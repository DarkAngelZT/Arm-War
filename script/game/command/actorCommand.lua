ActorSetAmmoCommand=class(Command)

function ActorSetAmmoCommand:onCreate( reciever, index )
	self.index=index
end

function ActorSetAmmoCommand:Execute()
	self.reciever.currentAmmoIdx=index
	if self.reciever == Logic.actor_me then
		--change ui
	end
end

---------------------------
-- move
---------------------------
ActorMoveCommad=class(Command)

function ActorMoveCommad:onCreate( reciever, dir, side )
	self.direction=dir
	self.side=side
end

function ActorMoveCommad:Execute()
	self.reciever:Move(self.direction,self.side)
end
---------------------------
-- stop
---------------------------
ActorStopCommad=class(Command)

function ActorStopCommad:Execute()
	self.reciever:Stop()
end
---------------------------
-- attack
---------------------------
ActorAttackCommand=class(Command)

function ActorAttackCommand:Execute()
	self.executed=true
	self.reciever:Attack()
end
---------------------------
-- dead
---------------------------
ActorDestroyedCommand=class(Command)
function ActorDestroyedCommand:onCreate(reciever,event, corpse_id)
	self.event=event
	self.corpse_id=corpse_id
end
function ActorDestroyedCommand:Execute()
	self.executed=true
	self.reciever:Die(self.corpse_id)
	if self.event then
		Scene:notify(self.reciever,self.event)
	end
end
---------------------------
-- set ammo
---------------------------
ActorSetAmmoCommand=class(Command)
function ActorSetAmmoCommand:onCreate( reciever, index )
	self.index=index
end

function ActorSetAmmoCommand:Execute()
	self.executed=true
	self.reciever:setAmmo(self.index)
end