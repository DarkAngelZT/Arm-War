map_editor={}
--------------------------------------------
-- initialize
--------------------------------------------
function map_editor.Init()
	print("init")
	-- c++ initialize
	NeoEditor:getInstance():Init()
	-- window caption
	NeoGraphics:getInstance():setWindowCaption("Map Editor -- untitiled")
	--reset id generator
	IDGenerator:Reset()
	--map name
	map_editor.map_name="untitiled"
	-- camera
	local graphicWrapper=NeoGraphics:getInstance()
	map_editor.camera=graphicWrapper:AddCameraSceneNodeMaya()
	map_editor.camera:setPosition(irr.core.vector3df:new_local(35,35,35))
	map_editor.camera:setTarget(irr.core.vector3df:new_local(0,0,0))
	map_editor.camera:setID(makeId())
	--map info conrainer
	-- default skybox
	map_editor.skyboxTexture=graphicWrapper:LoadTexture(DIR_RESOURCES.."sfx/env/skydome/cloud_skydome.jpg")
	map_editor.skybox=graphicWrapper:AddSkyDomeSceneNode(map_editor.skyboxTexture,16,8,1.0)
	--default ambient colour
	graphicWrapper:SetAmbientLight(irr.video.SColor:new_local(255,255,253,242));
end

--------------------------------------------
-- clean the editor objects
--------------------------------------------
function map_editor.CleanUp()
	--clear object information
	for k,_ in pairs(map_editor.objects) do
		map_editor.objects[k]=nil
	end
	for k,_ in pairs(map_editor.node_object_table) do
		map_editor.node_object_table[k]=nil
	end
	-- clear scene node from c++ side
	NeoEditor:getInstance():CleanUp()
	NeoGraphics:getInstance():UnloadTexture(map_editor.skyboxTexture)
	--restore window caption
	NeoGraphics:getInstance():setWindowCaption(ApplicationSettings.caption)
end

--------------------------------------------
-- Event Handler
--------------------------------------------
function map_editor.Menu_File_callback( args )
	-- body
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName == "New" then
		--create new scene
		return
	elseif btnName == "Open" then
		--open file dialog to load map
		return
	elseif btnName == "Quit" then
		g_ui_table.switchto("main")
		map_editor.CleanUp()
	end
end

function map_editor.Menu_Insert_callback( args )
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName == "static_mesh" then
		--import a static mesh into scene
		NeoEditor:getInstance():CreateFileOpenDialog("map_editor.ImportStaticMesh")
	elseif btnName == "oct" then
		NeoEditor:getInstance():CreateFileOpenDialog("map_editor.ImportOctreeMesh")
	elseif btnName == "animated_mesh" then
		NeoEditor:getInstance():CreateFileOpenDialog("map_editor.ImportAnimatedMesh")
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
		if self.selected_objects[k] == obj then
			self.selected_objects[k]=nil
			break
		end
	end
end

function map_editor:AddSelectedObject( obj )
	for k,v in ipairs(self.selected_objects) do
		if self.selected_objects[k] == obj then
			return
		end
	end
	self.selected_objects[#self.selected_objects+1]=obj
end
--------------------------------------------
-- mouse event handler
--------------------------------------------
map_editor.mouse_states={
	lbutton=false;
	rbutton=false;
	mbutton=false;
	reset=function (self)
		self.lbutton=false
		self.rbutton=false
		self.mbutton=false
	end
}

function map_editor.OnLButtonDown()
	map_editor.mouse_states.lbutton=true
end

function map_editor.OnMButtonDown()
	map_editor.mouse_states.lbutton=true
end

function map_editor.OnRButtonDown()
	map_editor.mouse_states.rbutton=true
end

function map_editor.OnLButtonUp()
	map_editor.mouse_states.lbutton=false
	local editor_wrapper=NeoEditor:getInstance()
	local node=editor_wrapper:getSelectedSceneNode()
	map_editor:UnselectAllObjects()
	if node and 
		node:getType()~=irr.scene.ESNT_SKY_DOME and
		node:getType()~=irr.scene.ESNT_SKY_BOX  and
		node:getID()~=map_editor.camera:getID() then
		editor_wrapper:ShowSelectionCursor(true, node:getAbsolutePosition())
		map_editor:AddSelectedObject(node)
	else
		editor_wrapper:ShowSelectionCursor(false)
	end

end

function map_editor.OnMButtonUp()
	map_editor.mouse_states.mbutton=false
end

function map_editor.OnRButtonUp()
	map_editor.mouse_states.rbutton=false
end

function map_editor.OnMouseWheel( ... )
	local x=tonumber(arg[1])
	print(x)
end

function map_editor.OnMouseMove()
	local delta=NeoEditor:getInstance():getMouseMoveDelta()
end