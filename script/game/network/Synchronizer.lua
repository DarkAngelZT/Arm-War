require(DIR_SCRIPT.."game/scene")
require(DIR_SCRIPT.."game/Network")

Synchronizer={
	network = NeoGame.Network:getInstance(),
	loaded_player_count=0,
	max_player_count=0,
	game_ready=false,
	m_enable_sync=false,
	players={},
	objects={},
	player_me=nil
}
------------------------------
-- game event ids
------------------------------
ID_GAME_EVENT_NONE = 0
ID_GAME_EVENT_SHOOT_BULLET=1
ID_GAME_EVENT_PLAYER_HIT=2
ID_GAME_EVENT_PLAYER_DIE=3
ID_GAME_EVENT_EXPLOSION=4
ID_GAME_EVENT_SHOOT_LASER=5
------------------------------
-- game event ids
------------------------------
ID_PLAYER_OP_NONE=0
ID_PLAYER_OP_ATTACK=1
ID_PLAYER_OP_RESPAWN=2
------------------------------
-- shell hit result ids
------------------------------
SHELL_HIT_RESULT_HIT=1
SHELL_HIT_RESULT_PIERCED=2
SHELL_HIT_RESULT_RICOCHET=3
------------------------------

Synchronizer.game_event_serialiser={
	[ID_GAME_EVENT_SHOOT_BULLET]=function( stream, data )
		-- data={shell_type, ownerId, impulse, position, rotation}
		--shell_type
		BitStreamHelper.SerializeString(stream,data.shell_type)
		--ownerId
		BitStreamHelper.SerializeString(stream,data.ownerId)
		--impulse
		BitStreamHelper.SerializeVector3(stream,data.impulse)
		--position
		BitStreamHelper.SerializeVector3(stream,data.position)
		--rotation
		BitStreamHelper.SerializeVector3(stream,data.rotation)
	end,
	[ID_GAME_EVENT_PLAYER_HIT]=function( stream, data )
		-- data = { victimId, attackerId, hit_result, damage2shield, damage2armor, damage2health }
		--victim id
		BitStreamHelper.SerializeString(stream,data.victimId)
		--attcker id
		BitStreamHelper.SerializeString(stream,data.attackerId)
		--hit result
		BitStreamHelper.SerializeAsByte(stream,data.hit_result)
		--damage to sheild
		BitStreamHelper.SerializeInt(stream,data.damage2shield)
		--damage to armor
		BitStreamHelper.SerializeFloat(stream,data.damage2armor)
		--damage to health
		BitStreamHelper.SerializeInt(stream,data.damage2health)
	end,
	[ID_GAME_EVENT_PLAYER_DIE]=function( stream, data )
		-- data = { victimId, killerId, corpseId }
		-- victim id
		BitStreamHelper.SerializeString(stream,data.victimId)
		-- killer id
		BitStreamHelper.SerializeString(stream,data.killerId)
		-- corpseId
		BitStreamHelper.SerializeString(stream,data.corpseId)
	end,
	[ID_GAME_EVENT_EXPLOSION]=function( stream, data )
		-- data = { explosion_type, invokerId, damage, position, range, impulse, attenuate }
		--explosion type
		BitStreamHelper.SerializeString(stream,data.explosion_type)
		--invoker id
		BitStreamHelper.SerializeString(stream,data.invokerId)
		--damage
		BitStreamHelper.SerializeInt(stream,data.damage)
		--position
		BitStreamHelper.SerializeVector3(stream,data.position)
		--range
		BitStreamHelper.SerializeFloat(stream,data.range)
		--impulse
		BitStreamHelper.SerializeFloat(stream,data.impulse)
		--is attenuated by distance
		BitStreamHelper.SerializeBool(stream,data.attenuate)
	end,
	[ID_GAME_EVENT_SHOOT_LASER]=function( stream, data )
		-- data={ ownerId, origin, direction, damage}
		--ownerId
		BitStreamHelper.SerializeString(stream,data.ownerId)
		--origin
		BitStreamHelper.SerializeVector3(stream,data.origin)
		--direction
		BitStreamHelper.SerializeVector3(stream,data.direction)
		--damage
		BitStreamHelper.SerializeFloat(stream,data.damage)
	end,
}

Synchronizer.game_event_deserializer={
	[ID_GAME_EVENT_SHOOT_BULLET]=function( stream )
		local data={shell_type="default", ownerId="", 
			impulse=irr.core.vector3df:new_local(), position=irr.core.vector3df:new_local(),
			rotation=irr.core.vector3df:new_local()}
		--shell_type
		data.shell_type = BitStreamHelper.DeserializeString(stream,data.shell_type)
		--ownerId
		data.ownerId = BitStreamHelper.DeserializeString(stream,data.ownerId)
		--impulse
		BitStreamHelper.DeserializeVector3(stream,data.impulse)
		--position
		BitStreamHelper.DeserializeVector3(stream,data.position)
		--rotation
		BitStreamHelper.DeserializeVector3(stream,data.rotation)
		Scene:AddShellToScene( { shell_type = data.shell_type, position=data.position,
			rotation=data.rotation }, data.impulse, { owner = Logic.actors[data.ownerId] } )
	end,
	[ID_GAME_EVENT_PLAYER_HIT]=function( stream )
		local data = { victimId="", attackerId="", hit_result=SHELL_HIT_RESULT_HIT, damage2shield=0, 
		damage2armor=0, damage2health=0 }
		--victim id
		data.victimId = BitStreamHelper.DeserializeString(stream,data.victimId)
		--attcker id
		data.attackerId = BitStreamHelper.DeserializeString(stream,data.attackerId)
		--hit result
		data.hit_result = BitStreamHelper.DeserializeByte(stream,data.hit_result)
		--damage to sheild
		data.damage2shield = BitStreamHelper.DeserializeInt(stream,data.damage2shield)
		--damage to armor
		data.damage2armor = BitStreamHelper.DeserializeFloat(stream,data.damage2armor)
		--damage to health
		data.damage2health = BitStreamHelper.DeserializeInt(stream,data.damage2health)

		local ricochet = (data.hit_result == SHELL_HIT_RESULT_RICOCHET)
		local pierce = (data.hit_result == SHELL_HIT_RESULT_PIERCED)
		local victim = Logic.actors[data.victimId]
		if not victim then
			print("Event sync error [ID_GAME_EVENT_PLAYER_HIT]: No such player "..data.victimId)
			return
		end

		if Synchronizer.players[data.victimId] then
			Synchronizer.players[data.victimId]:OnSynchronizeDamage(
			 data.damage2health, data.damage2armor, data.damage2shield )
		end

		local event = { 
			event_id=Scene.EVENT.PLAYER_HIT, attacker = Logic.actors[data.attackerId], 
			ricochet=ricochet, pierce=pierce }
		Scene:notify(victim,event)
	end,
	[ID_GAME_EVENT_PLAYER_DIE]=function( stream )
		local data = { victimId="", killerId="", corpseId="" }
		-- victim id
		data.victimId = BitStreamHelper.DeserializeString(stream,data.victimId)
		-- killer id
		data.killerId = BitStreamHelper.DeserializeString(stream,data.killerId)
		-- corpse id
		data.corpseId = BitStreamHelper.DeserializeString(stream,data.corpseId)

		local deathEvent = { 
			event_id=Scene.EVENT.PLAYER_DESTROYED, attacker = Logic.actors[data.killerId] }
		local cmd = ActorDestroyedCommand.new(Logic.actors[data.victimId],deathEvent, data.corpseId)
		Logic:addCommand(cmd)
	end,
	[ID_GAME_EVENT_EXPLOSION]=function( stream )
		local data = { explosion_type="default", 
			invokerId="", damage=0, position=irr.core.vector3df:new_local(), 
			range=0, impulse=0, attenuate=true }
		--explosion type
		data.explosion_type = BitStreamHelper.DeserializeString(stream,data.explosion_type)
		--invoker id
		data.invokerId = BitStreamHelper.DeserializeString(stream,data.invokerId)
		--damage
		data.damage = BitStreamHelper.DeserializeInt(stream,data.damage)
		--position
		BitStreamHelper.DeserializeVector3(stream,data.position)
		--range
		data.range = BitStreamHelper.DeserializeFloat(stream,data.range)
		--impulse
		data.impulse = BitStreamHelper.DeserializeFloat(stream,data.impulse)
		--is attenuated by distance
		data.attenuate = BitStreamHelper.DeserializeBool(stream,data.attenuate)
		MultiModeExplosionDispatcher:DoExplosion( data.explosion_type, data )
	end,
	[ID_GAME_EVENT_SHOOT_LASER]=function( stream )
		local data={ownerId="", origin=irr.core.vector3df:new_local(),
			direction=irr.core.vector3df:new_local(),damage=0}
		--ownerId
		data.ownerId = BitStreamHelper.DeserializeString(stream,data.ownerId)
		--origin
		BitStreamHelper.DeserializeVector3(stream,data.origin)
		--direction
		BitStreamHelper.DeserializeVector3(stream,data.direction)
		--damage
		BitStreamHelper.DeserializeFloat(stream,data.damage)
		Scene:ShootLaser( data.origin,data.direction,{damage=data.damage,owner=Logic.actors[data.ownerId]} )
	end,
}

Synchronizer.player_operation_serializer={
	[ID_PLAYER_OP_ATTACK]=function( stream, data )
		-- data = { playerId }
		BitStreamHelper.SerializeString(stream,data.playerId)
	end,
	[ID_PLAYER_OP_RESPAWN]=function( stream, data )
		-- data = { playerId,position,rotation }
		--player id
		BitStreamHelper.SerializeString(stream,data.playerId)
		--position
		BitStreamHelper.SerializeVector3(stream,data.position)
		--rotation
		BitStreamHelper.SerializeVector3(stream,data.rotation)
	end,
}

Synchronizer.player_operation_deserializer={
	[ID_PLAYER_OP_ATTACK]=function( stream )
		data = { playerId="" }
		data.playerId = BitStreamHelper.DeserializeString(stream,data.playerId)
		if Synchronizer.players[data.playerId] then
			local cmd = ActorAttackCommand.new(Synchronizer.players[data.playerId].actor)
			Logic:addCommand(cmd)
		end
	end,
	[ID_PLAYER_OP_RESPAWN]=function( stream )
		local data = { playerId="", position=irr.core.vector3df:new_local(), rotation=irr.core.vector3df:new_local() }
		--player id
		data.playerId = BitStreamHelper.DeserializeString(stream,data.playerId)
		--position
		BitStreamHelper.DeserializeVector3(stream,data.position)
		--rotation
		BitStreamHelper.DeserializeVector3(stream,data.rotation)

		if Logic.players[data.playerId] then
			Logic:RespawnActor( Logic.players[data.playerId], data.position, data.rotation )
		end
	end,
}

function Synchronizer:Init()
	self:Reset()
end

function Synchronizer:Reset()
	self.m_enable_sync=false
	self.max_player_count=0
	self.loaded_player_count=0
	self.game_ready=false
	for k,_ in pairs(self.players) do
		self.players[k]=nil
	end
	for k,_ in pairs(self.objects) do
		self.objects[k]=nil
	end
	self.player_me=nil
end

function Synchronizer:setEnabled( enable )
	self.m_enable_sync=enable
end

function Synchronizer:AddObject( obj )
	self.objects[obj.id]=obj
end

function Synchronizer:AddPlayer( p )
	self:AddObject(p)
	self.players[p.id]=p
end

function Synchronizer:CreateSynchronizedObject( ObjectClass, id, interanl_network_id,static )
	static = static or false
	ObjectClass = ObjectClass or SynchronizedObject
	local obj = NeoGame.Network:getInstance():CreateNetworkedObject(id)
	obj:setStatic(static)
	if interanl_network_id then
		obj:setInternalNetworkID(interanl_network_id)
	end
	
	local so = ObjectClass.new(id)
	obj:setObjType(so.obj_type)
	return so, obj
end

function Synchronizer:OnReceiveGameEvent( stream )
	local event_id = ID_GAME_EVENT_NONE
	event_id = BitStreamHelper.DeserializeByte(stream,event_id)
	if event_id == ID_GAME_EVENT_NONE then
		--prevent errors
		print("receive null game event, drop packet")
		return
	end
	self.game_event_deserializer[event_id](stream)
end

function Synchronizer:OnGameEvent( eventId, data )
	if self.network:isServer() then
		local stream = BitStreamHelper.CreateBitStream()
		BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.GAME_EVENT)
		BitStreamHelper.SerializeAsByte(stream,eventId)
		self.game_event_serialiser[eventId](stream,data)
		self.network:SendDataToAll(stream)
	end
end

function Synchronizer:OnPlayerOperation( op_type_id, data )
	local stream = BitStreamHelper.CreateBitStream()
	BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.GAME_PLAYER_OPERATION)
	BitStreamHelper.SerializeAsByte(stream,op_type_id)
	self.player_operation_serializer[op_type_id](stream,data)
	self.network:SendDataToAll(stream)
end

function Synchronizer:OnReceivePlayerOperation( stream )
	local op_id = ID_PLAYER_OP_NONE
	op_id = BitStreamHelper.DeserializeByte(stream,op_id)
	if op_id == ID_PLAYER_OP_NONE then
		--prevent errors
		print("receive null player input data, drop packet")
		return
	end
	self.player_operation_deserializer[op_id](stream)
end