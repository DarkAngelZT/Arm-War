-- tool buttons
map_editor.toolbar=
{
	duplicate=
		CEGUI.toPushButton(g_ui_table.editor:getChild("Toolbar/duplicate")),
	save=
		CEGUI.toPushButton(g_ui_table.editor:getChild("Toolbar/save")),
	open=
		CEGUI.toPushButton(g_ui_table.editor:getChild("Toolbar/open")),
	move=
		CEGUI.toPushButton(g_ui_table.editor:getChild("Toolbar/move")),
	rotate=
		CEGUI.toPushButton(g_ui_table.editor:getChild("Toolbar/rotate")),
	scale=
		CEGUI.toPushButton(g_ui_table.editor:getChild("Toolbar/scale"))
}
--------------------------------------------
-- initialize
--------------------------------------------
function map_editor.InitToolbar()
	map_editor.edit_mode=NeoEditor.EDITOR_MOVE
	map_editor.setCurrentTool(map_editor.edit_mode)
end
--------------------------------------------
-- exclusive set button select mode
--------------------------------------------
function map_editor.setCurrentTool( mode )
	for _,v in pairs(map_editor.toolbar) do
		v:enable()
	end
	local bar = map_editor.toolbar
	if mode == NeoEditor.EDITOR_MOVE then
		bar.move:disable()
	elseif mode == NeoEditor.EDITOR_SCALE then 
		bar.scale:disable()
	elseif mode == NeoEditor.EDITOR_ROTATE then 
		bar.rotate:disable()
	end
end
--------------------------------------------
-- event callback
--------------------------------------------
function map_editor.ToolbarCallback( args )
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName == "open" then
		--body
	elseif btnName == "duplicate" then
		--body
	elseif btnName == "save" then
		--body
	elseif btnName == "move" then
		map_editor.edit_mode=NeoEditor.EDITOR_MOVE
		map_editor.setCurrentTool(map_editor.edit_mode)
	elseif btnName == "rotate" then
		map_editor.edit_mode=NeoEditor.EDITOR_ROTATE
		map_editor.setCurrentTool(map_editor.edit_mode)
	elseif btnName == "scale" then
		map_editor.edit_mode=NeoEditor.EDITOR_SCALE
		map_editor.setCurrentTool(map_editor.edit_mode)
	end
end