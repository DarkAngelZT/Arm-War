Command=class()

function Command:onCreate( reciever )
	self.reciever=reciever
end

function Command:Execute( )
end

require(DIR_SCRIPT.."game/command/tankCommand")
require(DIR_SCRIPT.."game/command/actorCommand")