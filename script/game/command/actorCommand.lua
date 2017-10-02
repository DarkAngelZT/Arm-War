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