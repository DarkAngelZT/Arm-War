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
--初始化属性表（编辑器居然不提供编辑功能，靠）
local property_wnd=CEGUI.toMultiColumnList(
	CEGUI.WindowManager:getSingleton():createWindow("GlossySerpent/MultiColumnList", "list"))
property_wnd:setWidth(CEGUI.PropertyHelper:stringToUDim("{1,0}"))
property_wnd:setHeight(CEGUI.PropertyHelper:stringToUDim("{1,0}"))
property_wnd:addColumn("Property", 0, CEGUI.PropertyHelper:stringToUDim("{0.5,0}"))
property_wnd:addColumn("Value", 1, CEGUI.PropertyHelper:stringToUDim("{0.5,0}"))
root:getChild("Property"):addChild(property_wnd)
property_wnd:setProperty("ColumnsMovable",CEGUI.PropertyHelper:boolToString(false))
property_wnd:addRow()
--注册事件
local menubar="Menubar"
local fileOption=menubar.."/File/PopupMenu"

root:getChild(fileOption.."/New"):subscribeEvent("Clicked","map_editor.Menu_File_callback")
root:getChild(fileOption.."/Open"):subscribeEvent("Clicked","map_editor.Menu_File_callback")
root:getChild(fileOption.."/Save"):subscribeEvent("Clicked","map_editor.Menu_File_callback")
root:getChild(fileOption.."/Quit"):subscribeEvent("Clicked","map_editor.Menu_File_callback")

local insertOption=menubar.."/Insert/PopupMenu"
root:getChild(insertOption.."/static_mesh"):subscribeEvent("Clicked","map_editor.Menu_Insert_callback")
root:getChild(insertOption.."/animated_mesh"):subscribeEvent("Clicked","map_editor.Menu_Insert_callback")
root:getChild(insertOption.."/oct"):subscribeEvent("Clicked","map_editor.Menu_Insert_callback")
root:getChild(insertOption.."/billboard"):subscribeEvent("Clicked","map_editor.Menu_Insert_callback")
root:getChild(insertOption.."/light"):subscribeEvent("Clicked","map_editor.Menu_Insert_callback")
-- mouse and key event
root:subscribeEvent("MouseButtonDown","map_editor.OnMouseButtonDownEvent")
root:subscribeEvent("MouseButtonUp","map_editor.OnMouseButtonUpEvent")
root:subscribeEvent("MouseMove","map_editor.OnMouseMove")
root:subscribeEvent("MouseWheel","map_editor.OnMouseWheel")