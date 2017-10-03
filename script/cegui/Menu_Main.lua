main_menu = {}
-----------------------------------------
-- Handler to key inputs
-----------------------------------------
function main_menu.keyInput( args )
	local keycode = CEGUI.toKeyEventArgs(args)
	if keycode.scancode == CEGUI.Key.Escape then
		Application_Quit()
	end
end
-----------------------------------------
-- Handler to buttons
-----------------------------------------
function main_menu.btn_callback( args )
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName == "SinglePlayer" then
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
		return
	elseif btnName == "MapEditor" then
		g_ui_table.switchto("editor")
		--编辑器界面初始化
		map_editor.Init()
	-- elseif btnName == "Factory" then
	-- 	g_ui_table.switchto("factory");
	elseif btnName == "Settings" then
		backupSettings = deepcopy(ApplicationSettings)
		g_ui_table.switchto("options")
		options_menu.refresh()
	end
end
-----------------------------------------
-- Script Entry Point
-----------------------------------------
-- load our window layout
local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("mainMenu.layout")
g_ui_table["main"]=root

-- subscribe required events
root:getChild("mainwindow/SinglePlayer"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/MapEditor"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/Settings"):subscribeEvent("Clicked","main_menu.btn_callback")
-- root:getChild("mainwindow/Factory"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/Exit"):subscribeEvent("Clicked","Application_Quit")
root:subscribeEvent("KeyUp","main_menu.keyInput")