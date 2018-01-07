--interface for overall game controll and game console commands
game={}

function game:Clear()
	--execute order matters
	Logic:Clear()
	print("logic module cleared")
	Scene:Clear()
	print("scene module cleared")
	NeoScene:getInstance():Clean()
	print("NeoScene cleared")
	NeoPhysics:getInstance():CleanUp()
	print("NeoPhysics cleared")
	NeoGraphics:getInstance():CleanUp()
	print("NeoGraphics cleared")
	Sound:Clear()
	print("Sound resource cleared")
	print("Game clear done")
end

function game:ShutdownMultiPlayerGame()
	-- shut down multiplayer synchronizer
	print("Shut down network")
	Lobby:ShutDown()
	print("Clear synchronizer")
	Synchronizer:Reset()
	print("Release game resources...")
	-- normal game clear
	self:Clear()
end