-----------------------------------------
-- Script Entry Point
-----------------------------------------
-- load our window layout
local winMgr = CEGUI.WindowManager:getSingleton()
CEGUI.ImageManager:getSingleton():loadImageset("editor_icon.imageset");
local root = winMgr:loadLayoutFromFile("MapEditor.layout")
g_ui_table.editor=root
--加载操作函数
dofile(DIR_SCRIPT.."Editor/editorUI.lua")
dofile(DIR_SCRIPT.."Editor/editorFunctions.lua")

--注册事件
menubar="Menubar"
fileOption=menubar.."/File/PopupMenu"
root:getChild(fileOption.."/Quit"):subscribeEvent("Clicked","map_editor.Menu_File_callback")