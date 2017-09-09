map_editor={}

map_editor.isOnScene=true
map_editor.edit_mode=NeoEditor.EDITOR_MOVE
map_editor.root_directory=NeoEditor:getInstance():getWorkingDirectory()
map_editor.key_states=
{
	control=false,
	shift=true
}
-- scene node icons
map_editor.scene_node_icon=
{
	icon_root="editor/",
	mesh_static="sceneNode_mesh",
	mesh_animated="sceneNode_animated",
	billboard="sceneNode_billboard",
	light="sceneNode_light",
	octree="sceneNode_octree",
	event_point="event_point",
	spawn_point="event_point",
	cube="sceneNode_cube",
	sphere="sceneNode_sphere",
	particle_sys="sceneNode_particleSystem",
	camera="sceneNode_camera",
	unknown="sceneNode_unknown"
}
-- file list that needs to be copied to des folder
map_editor.copy_list={}
map_editor.saved=false
dofile(DIR_SCRIPT.."Editor/toolbar.lua")
dofile(DIR_SCRIPT.."Editor/animationPanel.lua")
dofile(DIR_SCRIPT.."Editor/physicsPanel.lua")
dofile(DIR_SCRIPT.."Editor/logicDataPanel.lua")
dofile(DIR_SCRIPT.."Editor/inputWindow.lua")
--------------------------------------------
-- initialize
--------------------------------------------
function map_editor.Init(resetEventHandler)
	if resetEventHandler == nil then
		resetEventHandler = true
	end
	-- c++ initialize
	NeoEditor:getInstance():Init(resetEventHandler)
	-- window caption
	NeoGraphics:getInstance():setWindowCaption("Map Editor -- untitled")
	--reset id generator
	IDGenerator:Reset()
	map_editor.mouse_states:reset()
	map_editor.isOnScene=true
	-- reset tool bar state
	map_editor.edit_mode=NeoEditor.EDITOR_MOVE
	map_editor.InitToolbar()
	--property window
	map_editor.InitPropertyWindow()
	--animation window
	map_editor.animation_wnd.Init()
	--physics panel
	map_editor.physics_wnd.Init()
	-- logic data panel
	map_editor.logic_data_wnd.Init()
	-- clear copy list (for save)
	map_editor.copy_list={}
	-- saved states
	map_editor.saved=false
	--map name
	map_editor.map_name="untitled"
	-- camera
	local graphicWrapper=NeoGraphics:getInstance()
	map_editor.camera=graphicWrapper:AddCameraSceneNode()
	map_editor.camera:setPosition(irr.core.vector3df:new_local(60,0,0))
	map_editor.camera:setTarget(irr.core.vector3df:new_local(0,0,0))
	map_editor.camera:setID(makeId())
	map_editor.camera_base_distance=irr.core.vector3df:new_local(60,0,0):getLength()
	--map info conrainer
	-- default skybox
	map_editor.skyboxTexture=graphicWrapper:LoadTexture(DIR_RESOURCES.."sfx/env/skydome/cloud_skydome.jpg")
	map_editor.skybox=graphicWrapper:AddSkyDomeSceneNode(map_editor.skyboxTexture,16,8,1.0)
	--default ambient colour
	graphicWrapper:SetAmbientLight(irr.video.SColor:new_local(255,255,253,242))
	--add root object
	map_editor.root_object=EditorRootObject.new()
	--scene window
	map_editor.InitSceneWindow()
	map_editor.UpdatePropertyWindow(map_editor.root_object)
end

--------------------------------------------
-- clean the editor objects
--------------------------------------------
function map_editor.CleanUp(resetEventHandler)
	if resetEventHandler == nil then
		resetEventHandler = true
	end
	--clear object information
	for k,_ in pairs(map_editor.objects) do
		map_editor.objects[k]=nil
	end
	map_editor.ClearObjectLookUpTable()
	map_editor:UnselectAllObjects()
	-- clear scene node from c++ side
	NeoEditor:getInstance():CleanUp(resetEventHandler)
	NeoGraphics:getInstance():UnloadTexture(map_editor.skyboxTexture)
	-- clear all loaded textures
	map_editor.RemoveAllTextures()
	--clear property window
	map_editor.ClearPropertyWindow()
	--clear scene window
	map_editor.ClearSceneWindow()
	--restore window caption
	NeoGraphics:getInstance():setWindowCaption(ApplicationSettings.caption)
end
------------------------------
-- property window control
------------------------------
map_editor.property_parser={
	["irr::core::vector3d<float>"] = function(text)
		local parse=loadstring("return "..text)
		if parse then
			local raw=parse(text)
			return irr.core.vector3df(raw[1],raw[2],raw[3])
		end
	end,
	["irr::video::SColor"] = function( text )
		local parse=loadstring("return "..text)
		if parse then
			local raw=parse(text)
			for _,v in ipairs({'a','r','g','b'}) do
				if not raw[v] or type(raw[v]) ~= "number" then
					return
				end
			end
			return irr.video.SColor:new_local(raw.a,raw.r,raw.g,raw.b)
		end
	end,
	StringList = function ( text )
		paths=split(text,":")
		return paths
	end,
	string = function (text)
		local parse=loadstring("return \""..text.."\"")
		if parse then
			local raw=parse(text)
			return raw
		end
	end,
	number = function ( text )
		local parse=loadstring("return "..text)
		if parse then
			local raw=parse(text)
			return raw
		end
	end,
	int = function ( text )
		local parse=loadstring("return "..text)
		if parse then
			local raw=parse(text)
			return raw
		end
	end,
	boolean=function ( text )
		local parse=loadstring("return "..text)
		if parse then
			local raw=parse(text)
			if type(raw) == "boolean" then
				return raw
			end
		end
	end
}
map_editor.property_converter={
	["irr::core::vector3d<float>"] = function(vector)
		return string.format("{%f, %f, %f}", vector.X, vector.Y, vector.Z)
	end,
	["irr::video::SColor"] = function( colour )
		return string.format("{a=%d, r=%d, g=%d, b=%d}", 
			colour:getAlpha(),colour:getRed(),colour:getGreen(),colour:getBlue())
	end,
	StringList = function ( list )
		paths=""
		if #list ==0 then
			return paths
		end
		paths=list[1]
		for i=2,#list do
			paths=paths..":"..list[i]
		end
		return paths
	end,
	string = function (text)
		return text
	end,
	number = function ( n )
		return string.format("%f",n)
	end,
	int = function ( n )
		return string.format("%d",n)
	end,
	boolean = function ( b )
		return tostring(b)
	end
}

function map_editor.InitPropertyWindow()
	local wnd=map_editor.property_wnd
	map_editor.property_editbox:setText("")
	map_editor.property_editbox:setReadOnly(true)
	map_editor.property_submitbtn:disable()
	wnd:invalidate(true)
end

function map_editor.UpdatePropertyWindow( object )
	local wnd=map_editor.property_wnd
	wnd:setSortDirection( CEGUI.ListHeaderSegment.None)
	map_editor.ClearPropertyWindow()
	if object == map_editor.root_object then
		--add a "name" row to root object
		local row=wnd:addRow()
		--key
		local keycol=CEGUI.createListboxTextItem("Node Type",0)
		--value
		local valuecol=CEGUI.createListboxTextItem("Root Object",0,nil,true)
		valuecol:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
		wnd:setItem(keycol,0,row)
		wnd:setItem(valuecol,1,row)
	end
	object:ClearItemKeyTable()
	for k,v in pairs(object.property) do
		-- add row
		local row=wnd:addRow()
		-- --key
		local display=v.display or k
		local keycol=CEGUI.createListboxTextItem(display,0)
		-- --value
		local datatype= v.type or tolua.type(object[k]):gsub("const ","")
		local value=map_editor.property_converter[datatype](object[k])
		local valuecol=CEGUI.createListboxTextItem(value)
		valuecol:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
		valuecol:setID(row)
		wnd:setItem(keycol,0,row)
		wnd:setItem(valuecol,1,row)
		object.property[k].list_item=valuecol
		object:setPropertyItemKey(valuecol, k)
	end
	wnd:autoSizeColumnHeader(1)
	map_editor.current_editted_object_property={obj=object}
	-- animation window
	map_editor.animation_wnd.UpdateObject( object )
	--physics data tab
	map_editor.physics_wnd.UpdateObject( object )
	-- logic data window
	map_editor.logic_data_wnd.UpdateObject( object )
end

function map_editor.UpdatePropertyWindowSingleRow( object, key )
	if not object then
		return
	end
	local wnd=map_editor.property_wnd
	local data = object.property[key]
	local datatype = data.type or tolua.type(object[key]):gsub("const ","")
	local value=map_editor.property_converter[datatype](object[key])
	local item = data.list_item
	item:setText(value)
	if item == map_editor.current_editted_object_property.item then
		map_editor.property_editbox:setText(value)
		if not object.property[key].readOnly then
			map_editor.property_submitbtn:enable()
		else
			map_editor.property_submitbtn:disable()
		end
	end
	wnd:invalidate(true)
end

function map_editor.ClearPropertyWindow()
	map_editor.property_wnd:resetList()
	map_editor.property_editbox:setText("")
	map_editor.current_editted_object_property={}
	map_editor.property_submitbtn:disable()
end
------------------------------
-- scene window control
------------------------------
map_editor.scene_wnd_info={}
function map_editor.InitSceneWindow()
	local tree=map_editor.tree
	local info=map_editor.scene_wnd_info
	local root_node = CEGUI.createTreeItem("root",0)
	root_node:setSelectionBrushImage("GlossySerpent/TextSelectionBrush")
	root_node:setIcon(CEGUI.ImageManager:getSingleton():get(
		map_editor.scene_node_icon.icon_root..map_editor.scene_node_icon.unknown))
	tree:addItem(root_node)
	info.root={
		object=map_editor.root_object,
		node=root_node
	}
	info[0]=info.root
end

function map_editor.ClearSceneWindow()
	map_editor.tree:resetList()
end

function map_editor.getObjectByItemId( id )
	return map_editor.scene_wnd_info[id].object
end

function map_editor.AddObjectToSceneWindow( obj, selected )
	local tree=map_editor.tree
	local info=map_editor.scene_wnd_info
	if selected == nil then
		selected=true
	else
		selected=selected
	end
	local new_node = CEGUI.createTreeItem(obj.name or obj.scene_type)
	local icon_path = map_editor.scene_node_icon[obj.scene_type] or 
		map_editor.scene_node_icon.unknown
	local icon = CEGUI.ImageManager:getSingleton():get(
		map_editor.scene_node_icon.icon_root..icon_path)
	new_node:setID(obj.id)
	new_node:setIcon(icon)
	new_node:setSelectionBrushImage("GlossySerpent/TextSelectionBrush")
	info[obj.id]={
		object=obj,
		node=new_node
	}
	info.root.node:addItem(new_node)
	new_node:setSelected(selected)
	if selected then
		map_editor.SelectObject(obj)
	end
	return new_node
end

function map_editor.RemoveObjectFromSceneWindow( object )
	if object == map_editor.root_object then
		--you can not delete root
		return
	end
	local tree=map_editor.tree
	local info=map_editor.scene_wnd_info
	info.root.node:removeItem(info[object.id].node)
	info[object.id]=nil
end

function map_editor.setSceneWindowSelectedObject( object )
	local tree=map_editor.tree
	local info=map_editor.scene_wnd_info
	--tree:clearAllSelections()
	if object == map_editor.root_object then
		info.root.node:setSelected(true)
	else
		local item=info[object.id].node
		if item then
			item:setSelected(true)
		end
	end
	tree:invalidate(true)
end

function map_editor.UpdateSceneWindowObject( object )
	local info=map_editor.scene_wnd_info
	local item=info[object.id].node
	if item then
		item:setText(object.name)
	end
	map_editor.tree:invalidate(true)
end
--------------------------------------------
-- Event Handler
--------------------------------------------
function map_editor.Menu_File_callback( args )
	-- body
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName == "New" then
		--create new scene
		map_editor.CleanUp(false)
		map_editor.Init(false)
	elseif btnName == "Open" then
		--open file dialog to load map
		map_editor.isOnScene=false
		NeoEditor:getInstance():CreateFileOpenDialog("map_editor.LoadCallback")
	elseif btnName == "Save" then
		if not map_editor.saved then
			map_editor.isOnScene=false
			map_editor.OpenInputWindow("Please input the map name:",
				map_editor.SaveCallback,map_editor.map_name)
		else
			map_editor:save()
		end
	elseif btnName == "SaveAs" then
		map_editor.isOnScene=false
			map_editor.OpenInputWindow("Please input the map name:",
				map_editor.SaveCallback,map_editor.map_name)
	elseif btnName == "Quit" then
		map_editor.Quit()
	end
	return false
end

function map_editor.Quit()
	g_ui_table.switchto("main")
	map_editor.CleanUp()
end

function map_editor.Menu_Insert_callback( args )
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName == "static_mesh" then
		--import a static mesh into scene
		map_editor.isOnScene=false
		NeoEditor:getInstance():CreateFileOpenDialog("map_editor.ImportStaticMesh")
	elseif btnName == "oct" then
		map_editor.isOnScene=false
		NeoEditor:getInstance():CreateFileOpenDialog("map_editor.ImportOctreeMesh")
	elseif btnName == "animated_mesh" then
		map_editor.isOnScene=false
		NeoEditor:getInstance():CreateFileOpenDialog("map_editor.ImportAnimatedMesh")
	elseif btnName == "billboard" then
		map_editor.isOnScene=false
		map_editor.ImportBillboard()
	elseif btnName == "cube" then
		map_editor.isOnScene=false
		map_editor.OpenInputWindow("Please input the size of cube",map_editor.AddCubeCallback,"10")
	elseif btnName == "sphere" then
		map_editor.isOnScene=false
		map_editor.OpenInputWindow("Please input the radius of sphere",map_editor.AddSphereCallback,"5")
	elseif btnName == "light" then
		map_editor.isOnScene=false
		map_editor.AddLightObject()
	elseif btnName == "event_point" then
		map_editor.isOnScene=false
		map_editor.AddEventPoint()
	elseif btnName == "spawn_point" then
		map_editor.isOnScene=false
		map_editor.AddSpawnPoint()
	end
end

function map_editor.PropertyChangeSubmitted( args )
	local text = map_editor.property_editbox:getText()
	-- apply changes to editor object
	local item=map_editor.current_editted_object_property.item
	local obj = map_editor.current_editted_object_property.obj
	if not obj then
		return
	end
	local key=obj:getPropertyKeyFromItem(item)
	local type=obj.property[key].type or tolua.type(obj[key]):gsub("const ","")
	local value=map_editor.property_parser[type](text)
	obj.property[key].set(obj,value)
	if key == "position" then
		-- synchronize cursor if edited property is position
		NeoEditor:getInstance():setSelectionCursorPosition(value)
	elseif key == "name" then
		-- synchronize scene window name
		map_editor.UpdateSceneWindowObject(obj)
	end
	map_editor.UpdatePropertyWindowSingleRow(obj, key)
end

function map_editor.PropertyItemSelected( args )
	local property_wnd = map_editor.property_wnd
	local item = property_wnd:getFirstSelectedItem()
	if not item then
		map_editor.property_editbox:setText("")
		map_editor.property_submitbtn:disable()
		return
	end
	local gridRef=property_wnd:getItemGridReference(item)
	if gridRef.column == 0 then
		return
	end
	local  key = map_editor.current_editted_object_property.obj:getPropertyKeyFromItem(
		item)
	map_editor.property_editbox:setText(item:getText())
	map_editor.current_editted_object_property.item=item
	map_editor.current_editted_object_property.key=key
	if not key or 
		not map_editor.current_editted_object_property.obj[key] or 
		map_editor.current_editted_object_property.obj.property[key].readOnly then
		map_editor.property_editbox:setReadOnly(true)
		map_editor.property_submitbtn:disable()
	else
		map_editor.property_editbox:setReadOnly(false)
		map_editor.property_submitbtn:enable()
	end
end

function map_editor.SceneTreeItemSelected( args )
	local item = map_editor.tree:getFirstSelectedItem()
	if not item then
		map_editor.CancelAllSelections()
		return
	end
	local obj = map_editor.getObjectByItemId(item:getID())
	if map_editor.isObjectSelected(obj) then
		return
	end
	map_editor.SelectObject(obj,not map_editor.key_states.control)
end
function map_editor.CopyCallback()
	if #map_editor.selected_objects == 0 then
		return
	end
	local objects = map_editor.CopyObjects(map_editor.selected_objects)
	map_editor.CancelAllSelections()
	for i=1,#objects do
		map_editor.SelectObject(objects[i],false)
	end	
end
--------------------------------------------
-- object handler
--------------------------------------------
map_editor.selected_objects={}
-- function allow multiple selection
function map_editor:UnselectAllObjects()
	for k,_ in ipairs(self.selected_objects) do
		self.selected_objects[k]=nil
	end
end

function map_editor:UnselectObject(obj)
	for k,v in ipairs(self.selected_objects) do
		if v == obj then
			table.remove(self.selected_objects,k)
			break
		end
	end
end

function map_editor:AddSelectedObject( obj )
	for _,v in ipairs(self.selected_objects) do
		if v == obj then
			return
		end
	end
	self.selected_objects[#self.selected_objects+1]=obj
end

function map_editor.isObjectSelected( obj )
	for _,v in ipairs(map_editor.selected_objects) do
		if v == obj then
			return true
		end
	end

	return false
end

function map_editor.SelectObject(obj, single)
	local node=obj.scene_node
	if single == nil then
		single=true
	else
		single=single
	end

	if not node then
		return
	end
	if single then
		map_editor.CancelAllSelections()
	end
	map_editor.ShowCursor(true, node:getAbsolutePosition())
	map_editor:AddSelectedObject(obj)
	map_editor.mouse_states.onSelectionCursor=false
	map_editor.mouse_states.onSelectionCursorIndex = -1
	map_editor.UpdatePropertyWindow(obj)
	map_editor.setSceneWindowSelectedObject(obj)
end

function map_editor.CancelAllSelections()
	map_editor.ShowCursor(false)
	map_editor:UnselectAllObjects()
	map_editor.UpdatePropertyWindow(map_editor.root_object)
	map_editor.tree:clearAllSelections()
end
--------------------------------------------
-- mouse event handler
--------------------------------------------
map_editor.mouse_states={
	lbutton=false,
	rbutton=false,
	mbutton=false,
	zoom_speed=15,
	onSelectionCursor=false,
	onSelectionCursorIndex=-1,
	reset=function (self)
		self.lbutton=false
		self.rbutton=false
		self.mbutton=false
		self.onSelectionCursor=false
		self.onSelectionCursorIndex=-1
	end
}

function map_editor.ShowCursor(visible,position)
	if visible then
		NeoEditor:getInstance():ShowSelectionCursor(visible, position)
		dist=(map_editor.camera:getPosition()-NeoEditor:getInstance():getSelectionCursorPosition()):getLength()
		scale=dist/map_editor.camera_base_distance
		NeoEditor:getInstance():setSelectionCursorScale(scale)
	else
		NeoEditor:getInstance():ShowSelectionCursor(visible)
		map_editor.mouse_states.onSelectionCursor=false
			map_editor.mouse_states.onSelectionCursorIndex = -1
	end
end

function map_editor.onSelectionCursorMove()
	dist=(map_editor.camera:getPosition()-NeoEditor:getInstance():getSelectionCursorPosition()):getLength()
	scale=dist/map_editor.camera_base_distance
	NeoEditor:getInstance():setSelectionCursorScale(scale)
end

function map_editor.OnMouseButtonDownEvent( args )
	if not map_editor.isOnScene then
		--skip when doing ui operations
		return
	end
	local event=CEGUI.toMouseEventArgs(args)
	if event.button == CEGUI.LeftButton then
		map_editor.OnLButtonDown(event)
	elseif event.button == CEGUI.RightButton then
		map_editor.OnRButtonDown(event)
	elseif event.button == CEGUI.MiddleButton then
		map_editor.OnMButtonDown(event)
	end
end

function map_editor.OnMouseButtonUpEvent( args )
	if not map_editor.isOnScene then
		--skip when doing ui operations
		return
	end
	local event=CEGUI.toMouseEventArgs(args)
	if event.button == CEGUI.LeftButton then
		map_editor.OnLButtonUp(event)
	elseif event.button == CEGUI.RightButton then
		map_editor.OnRButtonUp(event)
	elseif event.button == CEGUI.MiddleButton then
		map_editor.OnMButtonUp(event)
	end
end

function map_editor.OnMouseWheel( args )
	if not map_editor.isOnScene then
		--skip when doing ui operations
		return
	end
	local event=CEGUI.toMouseEventArgs(args)
	local camera=map_editor.camera
	local pos = camera:getPosition()
	local target=camera:getTarget()
	local verizon_vect=target-pos
	local len_sq=verizon_vect:getLengthSQ()
	local speed=map_editor.mouse_states.zoom_speed
	if len_sq < 900 then
		speed=2
	end
	verizon_vect:normalize()
	local delta=verizon_vect*(speed*event.wheelChange)
	local after_vect=target-(pos+delta)
	if after_vect:dotProduct(verizon_vect) >=0 then
		camera:setPosition(pos+delta)
		--scale cursor
		if #map_editor.selected_objects >0 then
			local dist=(camera:getPosition()-NeoEditor:getInstance():getSelectionCursorPosition()):getLength()
			local scale=dist/map_editor.camera_base_distance
			NeoEditor:getInstance():setSelectionCursorScale(scale)
		end
	end
end

function map_editor.rotateVectAxis(degree,vector,axis)
	--这是一个神奇的公式,可以把向量绕指定轴旋转β度
	--k是指定的轴向量，a是要旋转的向量
	--b是结果
	--b=cosβa+sinβ(k×a)+(k⋅a)(1−cosβ)k
	local cosd=math.cos(math.rad(degree))
	local b=vector*cosd+
		axis:crossProduct(vector)*math.sin(math.rad(degree))+
		axis*axis:dotProduct(vector)*(1-cosd)
	return b
end

function map_editor.OnMouseMove(args)
	if not map_editor.isOnScene then
		--skip when doing ui operations
		return
	end

	local event=CEGUI.toMouseEventArgs(args)
	if map_editor.mouse_states.mbutton then
		local camera=map_editor.camera
		local pos = camera:getPosition()
		local target=camera:getTarget()
		local verizon_vect=pos-target
		if map_editor.key_states.control then
			-- 平移相机
			verizon_vect:normalize()
			local upaxis = irr.core.vector3df:new_local(camera:getUpVector())
			local axis=upaxis:crossProduct(verizon_vect)
			upaxis=verizon_vect:crossProduct(axis)
			axis=axis*event.moveDelta.x
			upaxis=upaxis*event.moveDelta.y
			axis:normalize()
			upaxis:normalize()
			local delta = axis+upaxis
			camera:setPosition(pos+delta)
			camera:setTarget(target+delta)
		else 
			--旋转相机
			local rotation_y=irr.core.vector3df:new_local(0,event.moveDelta.x,0)
			local mat_y=irr.core.matrix4:new_local()
			local axis=verizon_vect:crossProduct(camera:getUpVector())
			axis:normalize()
			mat_y:setRotationAxisRadians(math.rad(event.moveDelta.y),axis)
			mat_y:setRotationDegrees(rotation_y)
			mat_y:rotateVect(verizon_vect)
			
			verizon_vect=map_editor.rotateVectAxis(event.moveDelta.y,verizon_vect, axis)

			pos=target+verizon_vect
			camera:setPosition(pos)
			--scale cursor
			if #map_editor.selected_objects >0 then
				local dist=(camera:getPosition()-NeoEditor:getInstance():getSelectionCursorPosition()):getLength()
				local scale=dist/map_editor.camera_base_distance
				NeoEditor:getInstance():setSelectionCursorScale(scale)
			end
		end
	end

	if map_editor.mouse_states.lbutton then
		if map_editor.mouse_states.onSelectionCursor then
			--move object align axis
			local delta = irr.core.vector3df()
			local camera=map_editor.camera
			local cursor=map_editor.mouse_states.onSelectionCursorIndex
			local lookVect=camera:getTarget()-camera:getPosition()
			local xdir = 1
			local zdir = 1
			if lookVect.Z < 0 then
				xdir=-1
			end
			if lookVect.X > 0 then
				zdir=-1
			end
			if cursor == 0 then
				delta.X=event.moveDelta.x*xdir
			elseif cursor == 1 then
				delta.Y = -event.moveDelta.y
			elseif cursor == 2 then
				delta.Z=event.moveDelta.x*zdir
			end
			
			if map_editor.edit_mode == NeoEditor.EDITOR_MOVE then
				local dist=(map_editor.camera:getPosition()-NeoEditor:getInstance():getSelectionCursorPosition()):getLength()
				delta=delta*dist*0.005
				-- update position
				for _,v in ipairs(map_editor.selected_objects) do
					v:setPosition(v.position+delta)
				end
				-- synchronize cursor position
				NeoEditor:getInstance():setSelectionCursorPosition(
					NeoEditor:getInstance():getSelectionCursorPosition()+delta)
				--update property panel
				map_editor.UpdatePropertyWindowSingleRow(
					map_editor.selected_objects[1]
					,"position")
			elseif map_editor.edit_mode == NeoEditor.EDITOR_SCALE then
				delta=delta*0.01
				-- update scale
				for _,v in ipairs(map_editor.selected_objects) do
					v:setScale(v.scale+delta)
				end
				--update property panel
				map_editor.UpdatePropertyWindowSingleRow(
					map_editor.selected_objects[1]
					,"scale")
			elseif map_editor.edit_mode == NeoEditor.EDITOR_ROTATE then
				delta = irr.core.vector3df()
				if cursor == 0 then
				delta.X = -event.moveDelta.y
				elseif cursor == 1 then
					delta.Y = event.moveDelta.x*zdir
				elseif cursor == 2 then
					delta.Z = -event.moveDelta.y
				end
				-- update rotation
				for _,v in ipairs(map_editor.selected_objects) do
					v:setRotation(v.rotation+delta)
				end
				--update property panel
				map_editor.UpdatePropertyWindowSingleRow(
					map_editor.selected_objects[1]
					,"rotation")
			end
		elseif #map_editor.selected_objects >0 and 
			map_editor.edit_mode == NeoEditor.EDITOR_MOVE then
			--move object according to screen
			local camera=map_editor.camera
			local lookVect=camera:getTarget()-camera:getPosition()
			lookVect:normalize()
			local upaxis = irr.core.vector3df:new_local(camera:getUpVector())
			local axis=upaxis:crossProduct(lookVect)
			upaxis=lookVect:crossProduct(axis)
			axis=axis*event.moveDelta.x
			upaxis=upaxis*event.moveDelta.y*-1
			axis:normalize()
			upaxis:normalize()
			local delta = axis+upaxis
			local dist=(map_editor.camera:getPosition()-NeoEditor:getInstance():getSelectionCursorPosition()):getLength()
			delta=delta*dist*0.005
			-- update position
			for _,v in ipairs(map_editor.selected_objects) do
				v:setPosition(v.position+delta)
			end
			-- synchronize cursor position
			NeoEditor:getInstance():setSelectionCursorPosition(
				NeoEditor:getInstance():getSelectionCursorPosition()+delta)
			--update property panel
			map_editor.UpdatePropertyWindowSingleRow(
				map_editor.selected_objects[1]
				,"position")
		end

	end
end

function map_editor.OnKeyDown( args )
	local event=CEGUI.toKeyEventArgs(args)

	if bit.band(event.sysKeys,CEGUI.SystemKeys.Control) ~= 0 then
		map_editor.key_states.control=true
	else
		map_editor.key_states.control=false
	end

	if bit.band(event.sysKeys,CEGUI.SystemKeys.Shift) ~= 0 then
		map_editor.key_states.shift=true
	else
		map_editor.key_states.shift=false
	end
	
	if map_editor.key_states.Control then
		--handle copy & paste event
		if event.scancode == CEGUI.Key.V then
			local graphicWrapper=NeoGraphics:getInstance()
			graphicWrapper:setAppClipboardString(graphicWrapper:getTextFromOSClipboard())
			CEGUI.System:getSingleton():getDefaultGUIContext():injectPasteRequest()
		elseif event.scancode == CEGUI.Key.C then
			local graphicWrapper=NeoGraphics:getInstance()
			CEGUI.System:getSingleton():getDefaultGUIContext():injectCopyRequest()
			graphicWrapper:setOSClipboardText(graphicWrapper:getAppClipboardString())
		elseif event.scancode == CEGUI.Key.X then
			local graphicWrapper=NeoGraphics:getInstance()
			CEGUI.System:getSingleton():getDefaultGUIContext():injectCutRequest()
			graphicWrapper:setOSClipboardText(graphicWrapper:getAppClipboardString())
		end
	end
	-- handle multi select event
	map_editor.tree:setMultiselectEnabled(map_editor.key_states.control)

end

function map_editor.OnKeyUp( args )
	local event=CEGUI.toKeyEventArgs(args)
	if bit.band(event.sysKeys,CEGUI.SystemKeys.Control) ~= 0 then
		map_editor.key_states.control=true
	else
		map_editor.key_states.control=false
	end

	if bit.band(event.sysKeys,CEGUI.SystemKeys.Shift) ~= 0 then
		map_editor.key_states.shift=true
	else
		map_editor.key_states.shift=false
	end

	if event.scancode == CEGUI.Key.Delete and
		g_ui_table.editor:getActiveChild():getType() ~= "GlossySerpent/Editbox" and
		g_ui_table.editor:getActiveChild():getType() ~= "GlossySerpent/MultiLineEditbox" then
		-- remove all selected objects
		for _,v in pairs(map_editor.selected_objects) do
			-- do not remove root object
			if v ~= map_editor.root_object then
				map_editor.RemoveObjectFromSceneWindow(v)
				map_editor.RemoveObject(v)
			end
		end
		map_editor.CancelAllSelections()
	end

	if event.scancode == CEGUI.Key.V and
		g_ui_table.editor:getActiveChild():getType() ~= "GlossySerpent/Editbox" and
		g_ui_table.editor:getActiveChild():getType() ~= "GlossySerpent/MultiLineEditbox" then
		-- remove all selected objects
		map_editor.CopyCallback()
	end
end

---------------
-- specific mouse handlers
---------------
function map_editor.OnLButtonDown(event)
	map_editor.mouse_states.lbutton=true
	local childWnd = g_ui_table.editor:getActiveChild()
	if childWnd:getType() == "GlossySerpent/Editbox" and 
		childWnd:getType() ~= "GlossySerpent/MultiLineEditbox"then
		childWnd:deactivate()
	end
	local editor_wrapper=NeoEditor:getInstance()
	local node=editor_wrapper:getSelectedSceneNode()
	if node and 
		node:getType()~=irr.scene.ESNT_SKY_DOME and
		node:getType()~=irr.scene.ESNT_SKY_BOX  and
		node:getID()~=map_editor.camera:getID() then
		if editor_wrapper:isSelectionCursor(node) then
			map_editor.mouse_states.onSelectionCursor=true
			map_editor.mouse_states.onSelectionCursorIndex =
				editor_wrapper:getSelectedCursorIndex(node)
			return
		end
		local singleMode = false
		if bit.band(event.sysKeys,CEGUI.SystemKeys.Control) ==0 then
			-- single select mode if control is not pressed
			singleMode=true
		end
		map_editor.SelectObject(map_editor.getObjectByNodeID(node:getID()),singleMode)
	else
		if not map_editor.key_states.control then
			map_editor.CancelAllSelections()
		end
	end
end

function map_editor.OnMButtonDown(event)
	map_editor.mouse_states.mbutton=true
end

function map_editor.OnRButtonDown(event)
	map_editor.mouse_states.rbutton=true
end

function map_editor.OnLButtonUp(event)
	map_editor.mouse_states.lbutton=false

	if #map_editor.selected_objects > 0 then
		return
	end

	local editor_wrapper=NeoEditor:getInstance()
	local node=editor_wrapper:getSelectedSceneNode()
	map_editor:UnselectAllObjects()
	if node and 
		node:getType()~=irr.scene.ESNT_SKY_DOME and
		node:getType()~=irr.scene.ESNT_SKY_BOX  and
		node:getID()~=map_editor.camera:getID() then

		if editor_wrapper:isSelectionCursor(node) then
			return
		end
		map_editor.SelectObject(map_editor.getObjectByNodeID(node:getID()))
	else
		if not map_editor.key_states.control then
			map_editor.CancelAllSelections()
		end
	end

end

function map_editor.OnMButtonUp(event)
	map_editor.mouse_states.mbutton=false
end

function map_editor.OnRButtonUp(event)
	map_editor.mouse_states.rbutton=false
end
---------------------------------------------------
-- get center position in screen, for inported mesh
---------------------------------------------------
function map_editor.getImportPosition()
	local camera = map_editor.camera
	local pos = camera:getPosition()
	local target = camera:getTarget()
	local lookVect = target-pos
	lookVect:normalize()
	lookVect=lookVect*50
	return pos+lookVect
end