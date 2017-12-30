require(DIR_SCRIPT.."game/network/SynchronizedObject")
require(DIR_SCRIPT.."game/network/TankSerializer")
require(DIR_SCRIPT.."game/network/TankDeserializer")

SynchronizedPlayer=class(SynchronizedObject)

function SynchronizedPlayer:onCreate( id )
	self.id=id
	self.obj_type="player"
	self.keyboard=0x0 --up,down,left,right key status, in binary number 0000
	Synchronizer:AddPlayer(self)
end

function SynchronizedPlayer:PostConstruct()
	self.actor=Logic.actors[self.id]
end

function SynchronizedPlayer:OnDestroy()
	Synchronizer.objects[self.id]=nil
	Synchronizer.players[self.id]=nil
end

function SynchronizedPlayer:setKeyboardStatus( up,down,left,right )
	up=bit.lshift(up,3)
	down=bit.lshift(down,2)
	left=bit.lshift(left,1)
	self.keyboard=bit.bor(up,down,left,right)
end

function SynchronizedPlayer:UpdateKeyboardStatus( status )
	if status ~= self.keyboard then
		--up
		local up = bit.rshift(bit.band(status,0x8),3)
		--down
		local down = bit.rshift(bit.band(status,0x4),2)
		--left
		local left = bit.rshift(bit.band(status,0x2),1)
		--right
		local right = bit.band(status,1)
		--copy from input handler
		local straight_status = up-down
		local l_r_status = right-left
		if straight_status == 0 and l_r_status == 0 then
			local cmd = ActorStopCommad.new(self.actor)
			Logic:addCommand(cmd)
		else
			Logic:addCommand(ActorMoveCommad.new(self.actor,straight_status,l_r_status))	
		end
		--update
		self.keyboard=status
	end
end

function SynchronizedPlayer:UpdatePlayerLiveStatus( status )
	if status ~= self.actor:isAlive() then
		if status then
			self.actor.state=ACTOR_STATE.LIVE
		else
			self.actor.state=ACTOR_STATE.DESTROYED
		end
	end
end

function SynchronizedPlayer:OnSerialize( stream )
	if self.actor then
		local alive = self.actor:isAlive()
		--is alive
		BitStreamHelper.SerializeBool(stream,alive)
		if not alive then
			return
		end
		--keyboard status
		BitStreamHelper.SerializeAsByte(stream,self.keyboard)
		--current ammon index
		BitStreamHelper.SerializeAsByte(stream,self.actor.currentAmmoIdx)
		--turret lock status
		BitStreamHelper.SerializeBool(stream,self.actor.turret_locked)
		--fire ready status
		BitStreamHelper.SerializeBool(stream,self.actor.fire_ready)
		--tank entity status
		TankSerializer:Serialize(self.actor.entity,stream)
	end
end

function SynchronizedPlayer:OnDeserialize( stream )
	if self.actor then
		local alive = false
		--is alive
		alive = BitStreamHelper.DeserializeBool(stream,alive)
		self:UpdatePlayerLiveStatus(alive)
		if alive then
			--keyboard status
			local keyboard = 0
			keyboard=BitStreamHelper.DeserializeByte(stream,keyboard)
			self:UpdateKeyboardStatus(keyboard)
			--current ammon index
			self.actor.currentAmmoIdx=BitStreamHelper.DeserializeByte(stream,self.actor.currentAmmoIdx)
			--turret lock status
			self.actor.turret_locked=BitStreamHelper.DeserializeBool(stream,self.actor.turret_locked)
			--fire ready status
			self.actor.fire_ready=BitStreamHelper.DeserializeBool(stream,self.actor.fire_ready)
			--tank entity status
			TankDeserializer:Deserialize(self.actor.entity,stream)
		end
	end
end

function SynchronizedPlayer:OnSerializeConstruct( stream )
	if self.actor then
		local gameobject = self.actor.entity.components.body.object
		local rigid_body = gameobject:getRigidBody()
		-- position
		BitStreamHelper.SerializeVector3(stream,gameobject:getPosition())
		-- rotation
		BitStreamHelper.SerializeVector3(stream,gameobject:getRotation())

	end
end

function SynchronizedPlayer:OnDeserializeConstruction( stream )
	if self.actor then
		local entity = self.actor.entity
		local position = irr.core.vector3df:new_local()
		local rotation = irr.core.vector3df:new_local()
		-- position
		BitStreamHelper.DeserializeVector3(stream,position)
		-- rotation
		BitStreamHelper.DeserializeVector3(stream,rotation)
		local transform = irr.core.matrix4:new_local()
		transform:setTranslation(position)
		transform:setRotationDegrees(rotation)
		entity:setTransform(transform)
	end
end

function SynchronizedPlayer:OnSynchronizeDamage( delta_health, delta_armor, delta_shield )
	self.actor.health=self.actor.health-delta_health
	self.actor.health=clamp(self.actor.health,0,self.actor.max_health)

	self.actor.shield=self.actor.shield-delta_shield
	self.actor.shield=clamp(self.actor.shield,0,math.huge)

	self.actor.armor=self.actor.armor-delta_armor
	self.actor.armor=clamp(self.actor.armor,0,math.huge)
end