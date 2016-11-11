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
	if btnName == "Single Player" then
		--test game here
		return
	elseif btnName == "MapEditor" then
		g_ui_table.switchto("editor")
		--编辑器界面初始化
		map_editor.Init()
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
root:getChild("mainwindow/MapEditor"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/Settings"):subscribeEvent("Clicked","main_menu.btn_callback")
root:getChild("mainwindow/Exit"):subscribeEvent("Clicked","Application_Quit")
root:subscribeEvent("KeyUp","main_menu.keyInput")

-- v3=irr.core.vector3df:new_local(0,0,5)
-- v4=irr.core.vector3df:new_local(0,3,4)
-- vt=irr.core.vector3df:new_local(2,3,0)
-- m=irr.core.matrix4:new_local()
-- m:buildRotateFromTo(v3,v4)
-- m:rotateVect(vt)
-- print(string.format("%f,%f,%f",vt.X,vt.Y,vt.Z))
-- dot=vt:dotProduct(v4)
-- print(dot)