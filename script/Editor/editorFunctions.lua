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
EditorObject.logic_data={}
-- property table: properties to be available for property window
EditorObject.property={
	name={
		set = function( obj, text )
			obj.name=text
		end
	},
	id={
		readOnly=true,type="int",
		set = function( obj, id )
			obj.id=id
		end 
	},
	scene_type={
		display="Node Type",
		readOnly=true,
		set = function( obj, text )
			obj.scene_type=text
		end
	},
	physics_type={
		display="Physics Type",
		set = function( obj, text )
			obj.physics_type=text
		end
	},
	position={
		set = function( obj, pos )
			obj:setPosition(pos)
		end
	}, 
	rotation={
		set = function( obj, rot )
			obj:setRotation(rot)
		end
	},
	scale={
		set = function( obj, scale )
			obj:setScale(scale)
		end
	},
	mesh_path={
		readOnly=true,display="Mesh",
		set = function( obj, text )
			obj.mesh_path=text
		end
	},
	textures={
		type="StringList",
		set = function( obj, list )
			obj.textures=deepcopy(list)
		end
	}
}

EditorObject.propertyItemTable={}
-------------------
-- property handler
-------------------
function EditorObject:getPropertyKeyFromItem( item )
	return self.propertyItemTable[item:getID()]
end

function EditorObject:setPropertyItemKey( item, key )
	self.propertyItemTable[item:getID()]=key
end

function EditorObject:ClearItemKeyTable()
	self.propertyItemTable={}
end

-------------------
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
		self.scene_node:setRotation(rotation)
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
	local obj = deepcopy(self)
	if obj.scene_node then
		obj.scene_node=obj.scene_node:clone()
	end
	map_editor.AddObject(obj)
	return obj
end
--[[************************************
 define root object
**************************************]]
EditorRootObject=class(EditorObject)
EditorRootObject["ambient colour"]=irr.video.SColor:new_local(255,255,253,242)
EditorRootObject["skydome texure"]=DIR_RESOURCES.."sfx/env/skydome/cloud_skydome.jpg"
EditorRootObject.property={
	["ambient colour"]={
		set = function(obj, color)
			obj["ambient colour"]=color
			NeoGraphics:getInstance():SetAmbientLight(color)
		end
	},
	["skydome texure"]={
		set = function(obj, text)
			obj["skydome texure"]=text
			NeoGraphics:getInstance():UnloadTexture(map_editor.skyboxTexture)
			map_editor.skyboxTexture=NeoGraphics:getInstance():LoadTexture(text)
			map_editor.skybox:setMaterialTexture(0,map_editor.skyboxTexture)
		end
	}
}

--[[*****************************************
 define animated object based on basic object
*******************************************]]
EditorAnimatedMeshObject = class(EditorObject)
EditorAnimatedMeshObject.name = "animated mesh"
EditorAnimatedMeshObject.scene_type = "mesh_animated"
EditorAnimatedMeshObject.animation={
	-- { label = "animation1", from = 1, to = 10 }	 
}
EditorAnimatedMeshObject.autoplay=true
EditorAnimatedMeshObject.startLoop=""
--[[*****************************************
 define billboard object based on basic object
*******************************************]]
EditorBillboardObject = class(EditorObject)
EditorBillboardObject.name = "billboard"
EditorBillboardObject.scene_type = "billboard"
--[[*****************************************
 define cube object based on basic object
*******************************************]]
EditorCubeObject = class(EditorObject)
EditorCubeObject.name = "cube"
EditorCubeObject.scene_type = "cube"
EditorCubeObject.size=10.0
EditorCubeObject.property.mesh_path=nil -- we don't need path here
EditorCubeObject.property.size=
{
	readOnly=true,
	set = function( obj, n )
		obj.size=n
	end
}
--[[*****************************************
 define sphere object based on basic object
*******************************************]]
EditorSphereObject = class(EditorObject)
EditorSphereObject.name = "sphere"
EditorSphereObject.scene_type = "sphere"
EditorSphereObject.radius = 5.0

EditorSphereObject.property.mesh_path=nil -- we don't need path here
EditorSphereObject.property.radius=
{
	readOnly=true,
	set = function( obj, r )
		obj.radius=r
	end
}
--[[*****************************************
 define light object based on basic object
*******************************************]]
EditorLightObject = class(EditorObject)
EditorLightObject.name = "light"
EditorLightObject.scene_type = "light"
EditorLightObject.ambient_color = irr.video.SColorf:new_local()
EditorLightObject.diffuse_color = irr.video.SColorf:new_local(1,1,1,1)
EditorLightObject.specular_color = irr.video.SColorf:new_local(1,1,1,1)
EditorLightObject.attenuation = irr.video.SColorf:new_local(0,0.01,0)
EditorLightObject.direction = irr.core.vector3df(1,0,0)
EditorLightObject.falloff=2
EditorLightObject.outerCone = 45
EditorLightObject.innerCone = 0
EditorLightObject.radius=100
EditorLightObject.cast_shadow=true
EditorLightObject.light_type = "point"
EditorLightObject.type_list={
	point=irr.video.ELT_POINT,
	spot=irr.video.ELT_SPOT,
	directional=irr.video.ELT_DIRECTIONAL
}
-- set functions
function EditorLightObject:setAmbientColor(color)
	self.ambient_color=color
	if self.scene_node then
		self.scene_node:getLightData().AmbientColor=color
	end
end

function EditorLightObject.setDiffuseColor( color )
	self.diffuse_color=color
	if self.scene_node then
		self.scene_node:getLightData().DiffuseColor=color
	end
end

function EditorLightObject.setSpecularColor( color )
	self.specular_color=color
	if self.scene_node then
		self.scene_node:getLightData().SpecularColor=color
	end
end

function EditorLightObject.setAtenuation( attenuation )
	self.attenuation=color
	if self.scene_node then
		self.scene_node:getLightData().Attenuation=attenuation
	end
end

function EditorLightObject.setDirection( dir )
	self.Direction=color
	if self.scene_node then
		self.scene_node:getLightData().Direction=dir
	end
end

function EditorLightObject.setOuterCone( outerCone )
	self.outerCone=outerCone
	if self.scene_node then
		self.scene_node:getLightData().OuterCone=outerCone
	end
end

function EditorLightObject.setInnerCone( innerCone )
	self.InnerCone=innerCone
	if self.scene_node then
		self.scene_node:getLightData().InnerCone=innerCone
	end
end

function EditorLightObject.setFalloff( f )
	self.falloff=f
	if self.scene_node then
		self.scene_node:getLightData().Falloff=f
	end
end

function EditorLightObject.setRadius( r )
	self.radius=r
	if self.scene_node then
		self.scene_node:setRadius(r)
	end
end

function EditorLightObject.setCastShadow( castShadow )
	self.cast_shadow=castShadow
	if self.scene_node then
		self.scene_node:enableCastShadow(castShadow)
	end
end

function EditorLightObject.setLightType( type )
	self.light_type=type
	if self.scene_node and self.type_list[type] then
		self.scene_node:setLightType(self.type_list[type])
	end
end
-- delete unneccessary properties
EditorLightObject.property.mesh_path=nil
EditorLightObject.property.textures=nil
EditorLightObject.property.physics_type=nil
-- add new property
EditorLightObject.property.ambient_color={
	display="Ambient Colour",
	set=function( obj, color )
		obj:setAmbientColor(color)
	end
}
EditorLightObject.property.diffuse_color={
	display="Diffuse Color",
	set=function( obj, color )
		obj:setDiffuseColor(color)
	end
}
EditorLightObject.property.specular_color={
	display="Specular Color",
	set=function( obj, color )
		obj:setSpecularColor(color)
	end
}
EditorLightObject.property.direction={
	set=function( obj, dir )
		obj:setDirection(dir)
	end
}
EditorLightObject.property.falloff={
	set=function( obj, f )
		obj:setFalloff(f)
	end
}
EditorLightObject.property.innerCone={
	display="Inner Cone",
	set=function( obj, inner )
		obj:setInnerCone(inner)
	end
}
EditorLightObject.property.outerCone={
	display="Outer Cone",
	set=function( obj, outer )
		obj:setOuterCone(outer)
	end
}
EditorLightObject.property.radius={
	set=function( obj, r )
		obj:setRadius(r)
	end
}
EditorLightObject.property.cast_shadow={
	display="Cast Shadow",
	set=function( obj, s )
		obj:setCastShadow(s)
	end
}
EditorLightObject.property.light_type={
	display="Light Type",
	set=function( obj, t )
		obj:setLightType(t)
	end
}
--[[*****************************************
 define spawn point based on basic object
*******************************************]]
EditorEventPointObject=class(EditorObject)
EditorEventPointObject.name="event point"
EditorEventPointObject.scene_type="event_point"
EditorEventPointObject.property.physics_type=nil
EditorEventPointObject.property.mesh_path=nil
EditorEventPointObject.property.textures=nil
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
			table.remove(map_editor.objects,i)
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

function map_editor.getObjectByNodeID( nodeid )
	return map_editor.node_object_table[nodeid]
end

function map_editor.ClearObjectLookUpTable( ... )
	for k,_ in pairs(map_editor.node_object_table) do
		map_editor.node_object_table[k]=nil
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
function map_editor.ImportStaticMesh( path, id, selected, position, rotation, scale )
	if not path then
		-- cancel button is clicked
		map_editor.isOnScene=true
		return
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
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
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
	obj:setSceneNode(node)
	obj:setPosition(position)
	obj:setRotation(rotation)
	obj:setScale(scale)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.ImportAnimatedMesh( path, id,selected, position, rotation, scale )
	if not path then
		-- cancel button is clicked
		map_editor.isOnScene=true
		return
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	local obj=EditorAnimatedMeshObject.new()
	id=id or makeId()
	obj.id=id
	obj.name="animated mesh"
	obj.scene_type="mesh_animated"
	obj.mesh_path=path
	local mesh=NeoGraphics:getInstance():getMesh(path)
	local node=NeoGraphics:getInstance():AddAnimatedMeshSceneNode(mesh)
	local vector_std__string_ list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
	--It's a c++ list, so index starts from 0
	for i=0,list_path:size()-1 do
		obj.textures[#obj.textures+1]=list_path[i]
	end
	node:setID(id)
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
	obj:setSceneNode(node)
	obj:setPosition(position)
	obj:setRotation(rotation)
	obj:setScale(scale)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.ImportOctreeMesh( path, id, selected, position, rotation, scale )
	if not path then
		-- cancel button is clicked
		map_editor.isOnScene=true
		return
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
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
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"octree")
	obj:setSceneNode(node)
	obj:setPosition(position)
	obj:setRotation(rotation)
	obj:setScale(scale)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end