ACTOR_STATE={LIVE,DESTROYED,SPECTATE}
--游戏对象的逻辑封装类
Actor=class()
Actor.id="actor0"
Actor.name="player11"
Actor.entity=nil
Actor.health=100
Actor.max_health=100
Actor.armor=5
Actor.shield=0
Actor.ammo={
	{name="AP",amount=10}
}
Actor.currentAmmoIdx=1
Actor.state=ACTOR_STATE.LIVE

function Actor:onCreate( id )
	self.id=id
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
	-- body
end

function Actor:Update( ... )
	if self.health==0 and self.state==ACTOR_STATE.LIVE then
		-- go die
		self.state=ACTOR_STATE.DESTROYED
	elseif self == Logic.actor_me then
		if self.state==ACTOR_STATE.LIVE then
			local deg_turret = Scene.cameras.third_person:getCamPan()-90
			local deg_canon = Scene.cameras.third_person:getCamTilt()
			deg_canon=-deg_canon-26
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