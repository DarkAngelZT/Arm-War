map_editor.input_wnd={
	root = g_ui_table.editor:getChild("InputWindow"),
	title=g_ui_table.editor:getChild("InputWindow/info"),
	input=g_ui_table.editor:getChild("InputWindow/input"),
	confirm_callback=nil
}
function map_editor.OpenInputWindow( title, callback,default )
	default=default or ""
	map_editor.input_wnd.root:setModalState(true)
	map_editor.input_wnd.root:setVisible(true)
	map_editor.input_wnd.confirm_callback=callback
	map_editor.input_wnd.title:setText(title)
	map_editor.input_wnd.input:setText(default)
end
----------------------------
-- event handlers
----------------------------
function map_editor.InputWindowConfirmed( args )
	map_editor.input_wnd.root:setModalState(false)
	map_editor.input_wnd.root:setVisible(false)
	if map_editor.input_wnd.confirm_callback then
		map_editor.input_wnd.confirm_callback(map_editor.input_wnd.input:getText())
	end
	map_editor.isOnScene=true
end

function map_editor.InputWindowCanceled( args )
	map_editor.input_wnd.root:setModalState(false)
	map_editor.input_wnd.root:setVisible(false)
	confirm_callback=nil
	map_editor.isOnScene=true
end
------------------------------
-- register event handlers
------------------------------
map_editor.input_wnd.root:getChild("ok_btn"):subscribeEvent("Clicked","map_editor.InputWindowConfirmed")
map_editor.input_wnd.root:subscribeEvent("CloseClicked","map_editor.InputWindowCanceled")