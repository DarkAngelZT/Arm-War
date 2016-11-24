map_editor.logic_data_wnd = {
	editbox=CEGUI.toMultiLineEditbox(g_ui_table.editor:getChild("Property/TabControl/Tab_logicData/code")),
	button_apply=CEGUI.toPushButton(g_ui_table.editor:getChild("Property/TabControl/Tab_logicData/btn_apply")),
	button_revert=CEGUI.toPushButton(g_ui_table.editor:getChild("Property/TabControl/Tab_logicData/btn_revert")),
	current_obj=nil
}

function map_editor.logic_data_wnd.Init()
	map_editor.logic_data_wnd.Clear()
	map_editor.logic_data_wnd.current_obj=nil
end

function map_editor.logic_data_wnd.Clear()
	map_editor.logic_data_wnd.editbox:setText("")
end

function map_editor.logic_data_wnd.UpdateObject( obj )
	map_editor.logic_data_wnd.current_obj=obj
	if obj then
		map_editor.logic_data_wnd.editbox:setText(obj.logic_data)
	end
end

function map_editor.logic_data_wnd.ApplyChanges()
	local obj=map_editor.logic_data_wnd.current_obj
	if obj then
		obj.logic_data=trim(map_editor.logic_data_wnd.editbox:getText())
	end
end
---------------------------------------
-- event handlers
---------------------------------------
function map_editor.logic_data_wnd.ApplyEvent( args )
	if map_editor.logic_data_wnd.current_obj then
		map_editor.logic_data_wnd.ApplyChanges()
	end
end

function map_editor.logic_data_wnd.RevertEvent( args )
	if map_editor.logic_data_wnd.current_obj then
		map_editor.logic_data_wnd.UpdateObject( 
			map_editor.logic_data_wnd.current_obj )
	end
end
---------------------------------------
-- register event handlers
---------------------------------------
map_editor.logic_data_wnd.button_revert:subscribeEvent("Clicked","map_editor.logic_data_wnd.RevertEvent")
map_editor.logic_data_wnd.button_apply:subscribeEvent("Clicked","map_editor.logic_data_wnd.ApplyEvent")