map_editor.animation_wnd={
	list=CEGUI.toItemListbox(g_ui_table.editor:getChild("Property/TabControl/Tab_animation/ItemListbox")),
	list_item=CEGUI.toItemEntry(g_ui_table.editor:getChild("Property/AnimationListboxItem")),
	button_add=CEGUI.toPushButton(g_ui_table.editor:getChild("Property/TabControl/Tab_animation/add_btn")),
	button_apply=CEGUI.toPushButton(g_ui_table.editor:getChild("Property/TabControl/Tab_animation/apply_btn")),
	button_revert=CEGUI.toPushButton(g_ui_table.editor:getChild("Property/TabControl/Tab_animation/revert_btn")),
	item_info={},
	current_obj=nil
}

function map_editor.animation_wnd.Init()
	map_editor.animation_wnd.Clear()
	map_editor.animation_wnd.current_obj=nil
	map_editor.animation_wnd.button_apply:disable()
	map_editor.animation_wnd.button_add:disable()
	map_editor.animation_wnd.button_revert:disable()
end

function map_editor.animation_wnd.AddAnimation(data)
	local wnd = map_editor.animation_wnd
	local info = {}
	local id,alabel,afrom,ato
	if data then
		id = data.id
		alabel=data.label
		afrom=data.from
		ato=data.to
	else 
		id = #wnd.item_info+1
		alabel="animation"..id
		afrom=0
		ato=0
	end
	info.id = id
	wnd.item_info[info.id]=info
	info.data={ id = info.id, label = alabel, from = afrom, to = ato }
	local item,label,from,to = map_editor.animation_wnd.AddItem(info.data)
	info.item=item
	info.label=label
	info.from=from
	info.to=to
	return info
end

function map_editor.animation_wnd.AddItem( info )
	local wnd = map_editor.animation_wnd
	local item = CEGUI.toItemEntry(wnd.list_item:clone(true))
	local from = item:getChild("itemPanel/from/editbox")
	local to = item:getChild("itemPanel/to/editbox")
	local label = item:getChild("itemPanel/label")
	local delete_btn = item:getChild("itemPanel/delete_btn")
	item:setName("item"..info.id)
	item:setVisible(true)
	wnd.list:addItem(item)	
	label:setText(info.label)
	from:setText(info.from)
	to:setText(info.to)
	item:setID(info.id)
	delete_btn:subscribeEvent("Clicked","map_editor.animation_wnd.DeleteEvent")
	return item,label,from,to
end

function map_editor.animation_wnd.RemoveAnimation(item)
	map_editor.animation_wnd.item_info[item:getID()]=nil
	item:removeEvent("Clicked")
	map_editor.animation_wnd.list:removeItem(item)
end

function map_editor.animation_wnd.Clear()
	map_editor.animation_wnd.list:resetList()
	local info_table = map_editor.animation_wnd.item_info
	for k,_ in pairs(info_table) do
		info_table[k]=nil
	end
end

function map_editor.animation_wnd.UpdateObject( obj )
	local wnd = map_editor.animation_wnd
	if not obj.animation then
		wnd.current_obj = nil
		map_editor.animation_wnd.button_apply:disable()
		map_editor.animation_wnd.button_add:disable()
		map_editor.animation_wnd.button_revert:disable()
		map_editor.animation_wnd.Clear()
		return
	end
	map_editor.animation_wnd.button_apply:enable()
	map_editor.animation_wnd.button_add:enable()
	map_editor.animation_wnd.button_revert:enable()
	wnd.current_obj = obj
	map_editor.animation_wnd.Clear()
	for _,v in ipairs(obj.animation) do
		wnd.AddAnimation(v)
	end
	map_editor.animation_wnd.list:notifyScreenAreaChanged(true)
end

function map_editor.animation_wnd.ApplyChanges()
	local obj=map_editor.animation_wnd.current_obj
	local info = map_editor.animation_wnd.item_info
	-- gether changes from ui
	for _,v in pairs(info) do
		v.data.label=v.label:getText()
		v.data.from=tonumber(v.from:getText())
		v.data.to=tonumber(v.to:getText())
	end
	obj.animation={}
	for _,v in pairs(info) do
		obj.animation[#obj.animation+1]=v.data
	end
end
---------------------------------------
-- event handlers
---------------------------------------
function map_editor.animation_wnd.DeleteEvent( args )
	local event = CEGUI.toWindowEventArgs(args)
	local item=event.window:getParent():getParent()
	map_editor.animation_wnd.RemoveAnimation(item)
	map_editor.animation_wnd.list:notifyScreenAreaChanged(true)
end

function map_editor.animation_wnd.AddEvent( args )
	local info = map_editor.animation_wnd.AddAnimation()
	info.item:notifyScreenAreaChanged(true)
end

function map_editor.animation_wnd.ApplyEvent( args )
	if map_editor.animation_wnd.current_obj then
		map_editor.animation_wnd.ApplyChanges()
	end
end

function map_editor.animation_wnd.RevertEvent( args )
	if map_editor.animation_wnd.current_obj then
		map_editor.animation_wnd.Clear()
		map_editor.animation_wnd.UpdateObject( 
			map_editor.animation_wnd.current_obj )
	end
end
---------------------------------------
-- register event handlers
---------------------------------------
map_editor.animation_wnd.button_add:subscribeEvent("Clicked","map_editor.animation_wnd.AddEvent")
map_editor.animation_wnd.button_apply:subscribeEvent("Clicked","map_editor.animation_wnd.ApplyEvent")
map_editor.animation_wnd.button_revert:subscribeEvent("Clicked","map_editor.animation_wnd.RevertEvent")