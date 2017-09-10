map_editor.physics_wnd={
	list=CEGUI.toItemListbox(g_ui_table.editor:getChild("Property/TabControl/Tab_physics/ItemListbox")),
	list_item=CEGUI.toItemEntry(g_ui_table.editor:getChild("Property/PhysicsAttrListboxItem")),
	cbx_type=CEGUI.toCombobox(g_ui_table.editor:getChild("Property/TabControl/Tab_physics/cbx_type")),
	button_apply=CEGUI.toPushButton(g_ui_table.editor:getChild("Property/TabControl/Tab_physics/btn_apply")),
	button_revert=CEGUI.toPushButton(g_ui_table.editor:getChild("Property/TabControl/Tab_physics/btn_revert")),
	current_obj=nil,
	attrKey_default={
		cube={size_x=1,size_y=1,size_z=1,mass=1},
		sphere={radius=1,mass=1},
		cone={radius=1,height=1,align="Y",mass=1},
		convexHull={mass=1},
		cylinder={size_x=1,size_y=1,size_z=1,align="Y",mass=1},
		capsule={radius=1,height=1,mass=1},
		static={},
		kinematic={},
		none={}
	},
	elements={}
}

function map_editor.physics_wnd.Init()
	map_editor.physics_wnd.current_obj=nil
	map_editor.physics_wnd.button_apply:disable()
	map_editor.physics_wnd.button_revert:disable()
	map_editor.physics_wnd.cbx_type:resetList()
	for k,_ in pairs(map_editor.physics_wnd.attrKey_default) do
		local option=CEGUI.createListboxTextItem(k)
		option:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
		map_editor.physics_wnd.cbx_type:addItem(option)
	end
	map_editor.physics_wnd.cbx_type:setText("none")
end

function map_editor.physics_wnd.clear()
	map_editor.physics_wnd.list:resetList()
	for k,_ in pairs(map_editor.physics_wnd.elements) do
		map_editor.physics_wnd.elements[k]=nil
	end
end

function map_editor.physics_wnd.AddAttributeRow( k, v )
	local wnd = map_editor.physics_wnd
	local item = CEGUI.toItemEntry(wnd.list_item:clone(true))
	local key = item:getChild("attrKey")
	local value = item:getChild("Editbox")
	item:setName(k)
	item:setVisible(true)
	wnd.list:addItem(item)	
	key:setText(k)
	value:setText(v)
	map_editor.physics_wnd.elements[k]=value
	return item
end

function map_editor.physics_wnd.UpdateObject( obj )
	local wnd = map_editor.physics_wnd
	map_editor.physics_wnd.button_apply:enable()
	map_editor.physics_wnd.button_revert:enable()
	wnd.current_obj = obj
	wnd.clear()
	--load attribute
	local type_str = obj.physics_data.physics_type
	map_editor.physics_wnd.cbx_type:setText(type_str)
	for k,v in pairs(map_editor.physics_wnd.attrKey_default[type_str]) do
		local datatype = tolua.type(v):gsub("const ","")
		local value = obj.physics_data[k] or v
		local value_str=map_editor.property_converter[datatype](value)
		map_editor.physics_wnd.AddAttributeRow(k,value_str)
	end
	map_editor.physics_wnd.list:notifyScreenAreaChanged(true)
end

function map_editor.physics_wnd.ApplyChanges()
	local obj=map_editor.physics_wnd.current_obj
	-- gether changes from ui
	if obj then
		local type_str = map_editor.physics_wnd.cbx_type:getText()
		local data={
			physics_type=type_str
		}
		for k,element in pairs(map_editor.physics_wnd.elements) do
			local attr_type=tolua.type(map_editor.physics_wnd.attrKey_default[type_str][k]):gsub("const ","")
			local text = element:getText()
			local value=map_editor.property_parser[attr_type](text)
			data[k]=value
		end
		obj.physics_data=data
	end
end

---------------------------------------
-- event handlers
---------------------------------------
function map_editor.physics_wnd.ApplyEvent( args )
	if map_editor.physics_wnd.current_obj then
		map_editor.physics_wnd.ApplyChanges()
	end
end

function map_editor.physics_wnd.RevertEvent( args )
	if map_editor.physics_wnd.current_obj then
		map_editor.physics_wnd.UpdateObject( 
			map_editor.physics_wnd.current_obj )
	end
end

function map_editor.physics_wnd.OnTypeChange( args )
	local type=map_editor.physics_wnd.cbx_type:getText()
	map_editor.physics_wnd.clear()
	for k,v in pairs(map_editor.physics_wnd.attrKey_default[type]) do
		local datatype = tolua.type(v):gsub("const ","")
		local value=map_editor.property_converter[datatype](v)
		map_editor.physics_wnd.AddAttributeRow(k,value)
	end
	map_editor.physics_wnd.list:notifyScreenAreaChanged(true)
end
---------------------------------------
-- register event handlers
---------------------------------------
map_editor.physics_wnd.button_apply:subscribeEvent("Clicked","map_editor.physics_wnd.ApplyEvent")
map_editor.physics_wnd.button_revert:subscribeEvent("Clicked","map_editor.physics_wnd.RevertEvent")
map_editor.physics_wnd.cbx_type:subscribeEvent("ListSelectionAccepted","map_editor.physics_wnd.OnTypeChange")