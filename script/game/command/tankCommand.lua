---------------------------
-- move
---------------------------
TankMoveCommad=class(Command)

function TankMoveCommad:onCreate( reciever, dir, side )
	self.direction=dir
	self.side=side
end

function TankMoveCommad:Execute()
	self.reciever:Move(self.direction,self.side)
end
---------------------------
-- stop
---------------------------
TankStopCommad=class(Command)

function TankStopCommad:Execute()
	self.reciever:Stop()
end