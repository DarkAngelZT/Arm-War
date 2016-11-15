--[[************************************
 define basice object for map editor
**************************************]]
EditorObject=class()
EditorObject.name="mesh"
EditorObject.id=-1
EditorObject.scene_type="mesh_static"
EditorObject.physics_type="static"
EditorObject.position=irr.core.vector3df:new_local()
EditorObject.rotation=irr.core.vector3df:new_local()
EditorObject.scale=irr.core.vector3df:new_local(1,1,1)
EditorObject.scene_node=nil
EditorObject.mesh_path=nil
EditorObject.textures={}
--property table: property name --> property row id
EditorObject.property={
	name={},
	id={readOnly=true,type="int"},
	scene_type={display="Node Type"},
	physics_type={display="Physics Type"},
	position={}, rotation={},scale={},
	mesh_path={display="Mesh"},
	textures={type="StringList"}
}

function EditorObject:setID( id )
	self.id=id
	if self.scene_node then
		self.scene_node:setID(id)
	end
end

function EditorObject:setPosition(position)
	-- body
	if(self.scene_node) then
		self.position=position
		self.scene_node:setPosition(position)
	end
end

function EditorObject:setRotation( rotation )
	-- body
	if self.scene_node then
		self.rotation=rotation
		self.scene_node:setRotaion(rotation)
	end
end

function EditorObject:setScale( scale )
	-- body
	if self.scene_node then
		self.scene_node:setScale(scale)
		self.rotation=scale
	end
end

function EditorObject:setSceneNode( node )
	if node then
		self.scene_node=node
		self.position=node:getPosition()
		self.rotation=node:getRotation()
		self.scale=node:getScale()
		map_editor.node_object_table[self.id]=self
	end
end
------------------------------
-- loading and saving functions
------------------------------
function EditorObject:Deserialize( obj_info )
	-- loading node from map object info table
	for key,value in pairs(obj_info) do
		self[key]=value
	end
	IDGenerator:Register(self.id)
	if obj_info.mesh_path then
		if obj_info.scene_type == "mesh_static" then
			map_editor.ImportStaticMesh(self.mesh_path,self.id)
		elseif obj_info.scene_type == "octree" then
			map_editor.ImportOctreeMesh(self.mesh_path,self.id)
		end
	end
end

function EditorObject:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		map_editor.WriteString(fileWriter, "name", self.name)
		map_editor.WriteInt(fileWriter, "id", self.id)
		map_editor.WriteString(fileWriter, "scene_type", self.scene_type)
		map_editor.WriteString(fileWriter, "physics_type", self.physics_type)
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		--modifie the mesh file path
		_,file=parsePath(EditorObject.mesh_path)
		map_editor.WriteString(fileWriter, "mesh_path", file)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		--enclosure
		fileWriter:write("\n} -- "..distObjName)
	end
end
------------------------------
-- function for copy object
------------------------------
function EditorObject:Clone()
	local obj=EditorObject.new()
	obj.scene_type=self.scene_type
	obj.physics_type=self.physics_type
	obj.position=self.position
	obj.rotation=self.rotation
	obj.scale=self.scale
	obj.scene_node=self.scene_node
	obj.mesh_path=self.mesh_path
	obj.textures=self.textures
	return obj
end
--[[*****************************************
 define animated object based on basic object
*******************************************]]
--[[*****************************************
 define billboard object based on basic object
*******************************************]]
--[[*****************************************
 define light object based on basic object
*******************************************]]
--[[*****************************************
 define spawn point based on basic object
*******************************************]]
--[[**************************************
map editor functions
these are additional functions for map_editor
******************************************]]
--------------------------------
----- map editor functions -----
--------------------------------
--objects
map_editor.objects={}
--object look up table for reverse look up
map_editor.node_object_table={}
--objects manipulate
function map_editor.AddObject(obj)
	table.insert(map_editor.objects,obj)
end

function map_editor.RemoveObject(obj)
	for i=1,#map_editor.objects do
		if map_editor.objects[i]==obj then
			table.remove(map_editor.objects,obj)
			local node=obj.scene_node
			if node then
				map_editor.node_object_table[obj.id]=nil
				node:remove()
			end
			deleteId(obj.id)
			break
		end
	end
end
-----------------
--saver functions
----------------
function map_editor.WriteVector3df( fileWriter, vector_name ,vector )
	fileWriter:write(string.format("%s = irr.core.vector3df:new_local(%f,%f,%f)\n",
			vector_name, vector.X, vector.Y,vector.Z))
end

function map_editor.WriteSColor( fileWriter, scolor_name, color )
	fileWriter:write(string.format("%s = irr.video.SColor:new_local(%d,%d,%d)\n",
			scolor_name, color:getAlpha(), color:getRed(), color:getGreen(), color:getBlue()))
end

function map_editor.WriteString( fileWriter, string_name, value )
	fileWriter:write(string.format("%s = \"%s\"\n", string_name, value))
end

function map_editor.WriteInt( fileWriter, string_name, value )
	fileWriter:write(string.format("%s = %d\n", string_name, value))
end

function map_editor.WriteFloat( fileWriter, string_name, value )
	fileWriter:write(string.format("%s = %f\n", string_name, value))
end

function map_editor.WriteTextureArray( fileWriter, array_name ,texture_array )
	fileWriter:write(array_name.." = {}\n")
	for i=1,#texture_array do
		fileWriter.write(string.format("%s[%d] = \"%s\"\n", array_name, i, texture_array[i]))
	end
end
--------------
--import functions
--------------
function map_editor.ImportStaticMesh( path, id )
	local obj=EditorObject.new()
	id=id or makeId()
	obj.id=id
	obj.name="mesh"
	obj.scene_type="mesh_static"
	obj.mesh_path=path
	local mesh=NeoGraphics:getInstance():getMesh(path)
	local node=NeoGraphics:getInstance():AddMeshSceneNode(mesh)
	local vector_std__string_ list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
	--It's a c++ list, so index starts from 0
	for i=0,list_path:size()-1 do
		obj.textures[#obj.textures+1]=list_path[i]
	end
	node:setID(id)
	obj:setSceneNode(node)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
end

function map_editor.ImportAnimatedMesh( path, id )
	local obj=EditorObject.new()
	id=id or makeId()
	obj.id=id

	map_editor.AddObject(obj)
	map_editor.isOnScene=true
end

function map_editor.ImportOctreeMesh( path, id )
	local obj=EditorObject.new()
	id=id or makeId()
	obj.id=id
	obj.name="octree"
	obj.scene_type="octree"
	obj.mesh_path=path
	local mesh=NeoGraphics:getInstance():getMesh(path)
	local node=NeoGraphics:getInstance():AddOctreeSceneNode(mesh)
	local vector_std__string_ list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
	--It's a c++ list, so index starts from 0
	for i=0,list_path:size()-1 do
		obj.textures[#obj.textures+1]=list_path[i]
	end
	node:setID(id)
	obj:setSceneNode(node)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
end