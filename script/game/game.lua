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
end