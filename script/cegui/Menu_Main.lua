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
		g_ui_table.switchto("single_menu")
		Sound:StopAllSounds()
		SingleMenu:Init()
	elseif btnName == "MultiPlayer" then
		g_ui_table.switchto("multi_menu")
		Sound:StopAllSounds()
		MultiMenu:Init()
	elseif btnName == "MapEditor" then
		g_ui_table.switchto("editor")
		Sound:StopAllSounds()
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

main_menu.background=root:getChild("bg")

CEGUI.ImageManager:getSingleton():addFromImageFile("main_menu_bg","main_menu_1.jpg","images")
main_menu.background:setProperty("Image","main_menu_bg")

-- subscribe required events
root:getChild("mainwindow/SinglePlayer"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/MultiPlayer"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/MapEditor"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/Settings"):subscribeEvent("Clicked","main_menu.btn_callback")
-- root:getChild("mainwindow/Factory"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/Exit"):subscribeEvent("Clicked","Application_Quit")
root:subscribeEvent("KeyUp","main_menu.keyInput")