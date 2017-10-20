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
	self.ammo={
	{name="AP",amount=20}
	}
end

function Actor:setEntity( e )
	self.entity=e
	e.actor=self
	self:ReadProperty()
end

function Actor:ReadProperty()
	if self.entity then
		for k,v in pairs(self.entity.property) do
			self[k]=v
		end
		self.max_health=self.health
		self.max_armor=self.armor
	end
end

function Actor:DealDamage( damage )
	self.health=self.health-damage
	self.health=clamp(self.health,0,self.max_health)
end

function Actor:OnShellHit( shell )
	print(self.id.." hitted by "..shell.shell_type.." from "..shell.owner.id)
	local damage = shell.property.damage
	if self.shield>0 then
		--先扣护盾
		if self.shield>=damage then
			self.shield=self.shield-damage
		else
			damage=damage-self.shield
			self.shield=0
		end
	end
	if math.random()<self.ricochet_possibility then
		--触发跳弹事件
		print("跳弹了")
	else 
		--处理伤害
		if math.random()<shell.property.piercePossibility then
			--穿甲伤害
			damage=shell.property.pierceDamage
			--触发穿甲事件
			print("穿甲")
		end
		damage = damage*(1-0.06*self.armor/(1+0.06*self.armor))
		self.armor=clamp(self.armor-shell.property.armorDamage)
		self:DealDamage(damage)
		print("health",self.health)
		if self.health ==0 then
			--发出死亡命令
			local cmd = ActorDestroyedCommand.new(self)
			Logic:addCommand(cmd)
		end
	end
	
	print("done")
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
				deg_turret = math.fmod( Scene.cameras.third_person:getCamPan()-90, 360)
				deg_canon = Scene.cameras.third_person:getCamTilt()
				deg_canon=-deg_canon-22
				if deg_turret<0 then
					deg_turret = deg_turret+360
				end
			end
			
			self.entity:setTurretAngle(deg_turret)
			self.entity:setCanonAngle(deg_canon)
		end
	end
end

function Actor:Attack()
	if self.state==ACTOR_STATE.LIVE and self.ammo[self.currentAmmoIdx].amount>0 then
		self.ammo[self.currentAmmoIdx].amount = self.ammo[self.currentAmmoIdx].amount-1
		self.entity:Attack(self.ammo[self.currentAmmoIdx].name)
	end
end

function Actor:Reset()
	self:ReadProperty()
	self.turret_locked=false
end

function Actor:Move( dir, side )
	if self.state==ACTOR_STATE.LIVE then
		self.entity:Move(dir,side)
	end
end

function Actor:Stop()
	if self.state==ACTOR_STATE.LIVE then
		self.entity:Stop()
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

function Actor:Die()
	if self.state==ACTOR_STATE.LIVE then
		self.state=ACTOR_STATE.DESTROYED
		self.entity:Die()
		--触发死亡事件
	end
end