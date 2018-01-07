ACTOR_STATE={LIVE=1,DESTROYED=2,SPECTATE=3}
--游戏对象的逻辑封装类
Actor=class()
Actor.id="actor0"
Actor.name="player11"
Actor.entity=nil
Actor.health=100
Actor.max_health=100
Actor.armor=5
Actor.shield=0

Actor.currentAmmoIdx=1
Actor.state=ACTOR_STATE.LIVE

function Actor:onCreate( id )
	self.id=id
	self.turret_locked=false
	self.ammo={}
	self.ammo_config={
		{name="AP",amount=3},
		{name="HE",amount=3},
		{name="HEAT",amount=3}
	}
	self.fire_ready=true
end

function Actor:OnDestroy()
	if self.reload_timer then
		Logic:RemoveTimer(self.reload_timer)
	end
end

function Actor:isAlive()
	return (self.state == ACTOR_STATE.LIVE)
end

function Actor:setEntity( e )
	self.entity=e
	e.actor=self
	self:ReadProperty()
end

function Actor:Init( )
	local timer = Timer.new()
	timer:AddTickFunction(self.UpdateReloadBar,self)
	timer:AddTriggerFunction(self.OnReloadFinish,self)
	self.reload_timer = timer
	Logic:AddTimer(self.reload_timer)
end

function Actor:ReadProperty()
	if self.entity then
		for k,v in pairs(self.entity.property) do
			self[k]=v
		end
		self.max_health=self.health
		self.max_armor=self.armor
		self.reload_timer.duration=self.reload_time
	end
	self.ammo=deepcopy(self.ammo_config)
end

function Actor:DealDamage( damage, invoker, event_to_trigger, still_trigger_event_on_death )
	self.health=self.health-damage
	self.health=clamp(self.health,0,self.max_health)
	still_trigger_event_on_death=still_trigger_event_on_death or false
	if self.health == 0 then
			--发出死亡命令
		local deathEvent = { event_id=Scene.EVENT.PLAYER_DESTROYED, attacker = invoker }
		local corpseId = "co"..self.id..os.time()
		local cmd = ActorDestroyedCommand.new(self,deathEvent, corpseId)
		Logic:addCommand(cmd)
		if still_trigger_event_on_death and event_to_trigger then
			Scene:notify(self,event_to_trigger)
		end
		return corpseId
	else
		if event_to_trigger then
			Scene:notify(self,event_to_trigger)
		end
	end
end

function Actor:OnShellHit( shell )
	local event = { 
		event_id=Scene.EVENT.PLAYER_HIT, attacker = shell.owner, ricochet=false, pierce=false }
	local damage = shell.property.damage
	local corpse_id
	if self.shield>0 then
		--先扣护盾
		if self.shield>=damage then
			self.shield=self.shield-damage
		else
			damage=damage-self.shield
			self.shield=0
		end
	end
	if shell.property.ricochetEnabled and math.random()<self.ricochet_possibility then
		--触发跳弹事件
		event.ricochet=true
		Scene:notify(self,event)
	else 
		--处理伤害
		if math.random()<shell.property.piercePossibility then
			--穿甲伤害
			damage=shell.property.pierceDamage
			--触发穿甲事件
			event.pierce=true
		end
		damage = damage*(1-0.06*self.armor/(1+0.06*self.armor))
		damage=math.floor(damage)
		if math.random()<shell.property.squashPossibility then
			self.armor=clamp(self.armor-shell.property.armorDamage,0,math.huge)
		end
		
		corpse_id = self:DealDamage(damage,shell.owner,event)
	end
	return event.ricochet, event.pierce, corpse_id
end

function Actor:MultiModeOnShellHit( shell )
	if NeoGame.Network:getInstance():isServer() then
		local dmg_health = self.health
		local dmg_shield = self.shield
		local dmg_armor = self.armor
		local ricochet, pierce, corpse_id = self:OnShellHit(shell)
		dmg_health=dmg_health-self.health
		dmg_shield=dmg_shield-self.shield
		dmg_armor=dmg_armor-self.armor
		local hit_result = SHELL_HIT_RESULT_HIT
		if ricochet then
			hit_result = SHELL_HIT_RESULT_RICOCHET
		elseif pierce then
			hit_result = SHELL_HIT_RESULT_PIERCED
		end
		Synchronizer:OnGameEvent( ID_GAME_EVENT_PLAYER_HIT, {
			victimId=self.id, attackerId=shell.owner.id, 
			hit_result=hit_result, damage2shield=dmg_shield, 
			damage2armor=dmg_armor, damage2health=dmg_health
			} )
		if self.health == 0 and corpse_id then
			Synchronizer:OnGameEvent( ID_GAME_EVENT_PLAYER_DIE, {
				victimId = self.id, killerId = shell.owner.id, corpseId=corpse_id } )
		end
	end
end

function Actor:Update( ... )
	if self.health==0 and self.state==ACTOR_STATE.LIVE then
		-- go die
		self.state=ACTOR_STATE.DESTROYED
	elseif self == Logic.actor_me then
		if self.state==ACTOR_STATE.LIVE then
			local deg_turret = 0
			local deg_canon = 0
			if self.turret_locked then
				deg_turret = self.angle_cache.turret
				deg_canon = self.angle_cache.canon
			else 
				deg_turret, deg_canon= self:getTurretTargetAngle()
				deg_canon = deg_canon - 90
				deg_canon=deg_canon*0.5
				if deg_turret<0 then
					deg_turret = deg_turret+360
				end
			end
			
			self.entity:setTurretAngle(deg_turret)
			self.entity:setCanonAngle(deg_canon)
			
			self:UpdateUI()
		end
	end
end

function Actor:getTurretTargetAngle()
	local screen_size = Scene.screen_size
	local pos = irr.core.vector2di:new_local(screen_size.Width*0.5,screen_size.Height*0.25)
	local target = NeoGraphics:getInstance():get3DPositionFromScreen(pos)
	local from = Scene.cameras.third_person:getPosition()
	local to = target --from+dir*distance
	local raycastResult = NeoPhysics:getInstance():RayCast(from,to)
	if raycastResult.hasHit then
		target = raycastResult.m_hitPointWorld
	end

	return self.entity:getTargetAngle(target)
end

function Actor:UpdateUI()
	--update aim position
	local aim_pos = self.entity:getCanonAimPosition()
	local screen_pos_int = NeoGraphics:getInstance():getPositionOnScreen(aim_pos)
	if screen_pos_int.X== -1000 and screen_pos_int.Y == -1000 then
		gamehud:setCanonCursorEnabled(false)
	else
		gamehud:setCanonCursorEnabled(true)
	end
	local screen_pos_dim_x = irr.core.vector2df(0,clamp(screen_pos_int.X,0,math.huge))
	local screen_pos_dim_y = irr.core.vector2df(0,clamp(screen_pos_int.Y,0,math.huge))
	gamehud:setCanonCursorPosition(screen_pos_dim_x,screen_pos_dim_y)

	

	local body_angle = self.entity:getTankComponentWorldAngles("body")
	local turret_angle = self.entity:getTankComponentWorldAngles("turret")
	gamehud:UpdateTopView(body_angle.Y,turret_angle.Y,self.health/self.max_health)
end

function Actor:UpdateReloadBar( delta_time )
	local percent = 1-self.reload_timer.time_remain/self.reload_timer.duration
	percent=percent*100
	if self == Logic.actor_me then
		gamehud:setReloadingPercent(percent)
	end
end

function Actor:OnReloadFinish( )
	self.fire_ready=true
	if self == Logic.actor_me then
		gamehud:setReloadingPercent(100)
	end
end

function Actor:Attack()
	if self.state==ACTOR_STATE.LIVE and self.fire_ready and self.ammo[self.currentAmmoIdx].amount>0 then
		local amount = self.ammo[self.currentAmmoIdx].amount-1
		self.ammo[self.currentAmmoIdx].amount = amount
		if self==Logic.actor_me then
			gamehud:ChangeAmmoAmount(self.currentAmmoIdx,amount)
		end
		self.entity:Attack(self.ammo[self.currentAmmoIdx].name)
		self.reload_timer:Start()
		self.fire_ready=false
	end
end

function Actor:Reset()
	self:ReadProperty()
	self.turret_locked=false
	self.fire_ready=true
	self.reload_timer:Stop()
end

function Actor:Respawn( position,rotation )
	if self.state==ACTOR_STATE.LIVE then
		return
	end
	self:Reset()
	self.entity:Respawn(position,rotation)
	self.state=ACTOR_STATE.LIVE
end

function Actor:Move( dir, side )
	if self.state==ACTOR_STATE.LIVE then
		self.entity:Move(dir,side)
		self.entity:PlayEngineSound()
	end
end

function Actor:Stop()
	if self.state==ACTOR_STATE.LIVE then
		self.entity:Stop()
		self.entity:StopEngineSound()
	end
end


function Actor:LockTurret( state )
	self.turret_locked=state
	if state then
		self.angle_cache={
			turret=self.entity:getTurretAngle(),
			canon=self.entity:getCanonAngle()
		}
	end
end

function Actor:Die(corpse_id)
	if self.state==ACTOR_STATE.LIVE then
		self.state=ACTOR_STATE.DESTROYED
		self.entity:Die(corpse_id)
		self.entity:StopEngineSound()
	end
end

function Actor:setAmmo( index )
	if index>0 and index<= #self.ammo then
		self.currentAmmoIdx=index
		if self==Logic.actor_me then
			gamehud:setCurrentAmmoType(index,self.ammo[index].name)
		end
	end
end
