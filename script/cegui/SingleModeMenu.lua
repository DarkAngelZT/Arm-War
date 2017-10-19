SingleMenu={}

-----------------------------------------
-- Handler to  key input
-----------------------------------------
function SingleMenu.keyInput( args )
	local keycode = CEGUI.toKeyEventArgs(args)
	if keycode.scancode == CEGUI.Key.Escape then
		--直接退出
		g_ui_table.switchto("main")
	end
end
-------------------------------------
-- button handler
------------------------------------
function SingleMenu.OnButtonClick(args)
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName=="StartBtn" then
		--test game here
		g_ui_table.switchto("loading")
		LoadingScreen.Init()
		players={}
		players[1]={
			name="Neo",
			tank_type="t34",
			id="a01",
			team=1
		}
		players[2]={
			name="Dummy",
			tank_type="t34",
			id="a02",
			team=2
		}
		Scene.Init("resources/maps/mini_manhattan.lua",players)
	elseif btnName=="ExitBtn" then
		g_ui_table.switchto("main")
	end
end
-------------------------------------
-- Initialize UI
------------------------------------
function SingleMenu.Init( ... )
	-- body
end

--load root ui
local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("SinglePlayerMenu.layout")
g_ui_table.single_menu=root

-- subscribe required events
root:subscribeEvent("KeyUp","SingleMenu.keyInput")
root:getChild("FrameWnd/StartBtn"):subscribeEvent("Clicked","SingleMenu.OnButtonClick")
root:getChild("FrameWnd/ExitBtn"):subscribeEvent("Clicked","SingleMenu.OnButtonClick")