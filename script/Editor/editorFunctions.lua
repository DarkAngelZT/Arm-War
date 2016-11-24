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
EditorObject.logic_data=""
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
function EditorObject:setTexture( path )
	if self.scene_node then
		-- NeoGraphics:getInstance():UnloadTexture(map_editor.skyboxTexture)
		-- 	map_editor.skyboxTexture=NeoGraphics:getInstance():LoadTexture(text)
		-- 	map_editor.skybox:setMaterialTexture(0,map_editor.skyboxTexture)
		-- self.scene_node:
	end
end
------------------------------
-- loading and saving functions
------------------------------
function EditorObject.Deserialize( obj_info )
	local obj
	if obj_info.mesh_path then
		if obj_info.scene_type == "mesh_static" then
			obj = map_editor.ImportStaticMesh(
				obj_info.mesh_path, obj_info.id, false, 
				obj_info.position, obj_info.rotation, obj_info.scale)
		elseif obj_info.scene_type == "octree" then
			obj = map_editor.ImportOctreeMesh(
				obj_info.mesh_path, obj_info.id, false,
				obj_info.position, obj_info.rotation, obj_info.scale)
		end
	end
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		IDGenerator:Register(obj.id)
	end
	return obj
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
		file=DIR_MAPS..map_editor.map_name.."/"..file
		map_editor.WriteString(fileWriter, "mesh_path", file)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("\n} -- "..distObjName.."\n")
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
EditorRootObject["skydome texture"]=DIR_RESOURCES.."sfx/env/skydome/cloud_skydome.jpg"
EditorRootObject.property={
	["ambient colour"]={
		set = function(obj, color)
			obj["ambient colour"]=color
			NeoGraphics:getInstance():SetAmbientLight(color)
		end
	},
	["skydome texture"]={
		set = function(obj, text)
			obj["skydome texture"]=text
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
	-- {id = 1, label = "animation1", from = 1, to = 10 }	 
}
EditorAnimatedMeshObject.autoplay=true
EditorAnimatedMeshObject.startLoop=""
-- add new property
EditorAnimatedMeshObject.property.autoplay={
	display="autoplay animation",
	set=function( obj, p )
		obj.autoplay=p
		obj.scene_node:setLoopMode(p)
	end
}
EditorAnimatedMeshObject.property.startLoop={
	display="initial animation",
	set=function( obj, l )
		obj.startLoop=l
		for _,info in ipairs(obj.animation) do
		 	if info.label == obj.startLoop then
		 		obj.scene_node:setFrameLoop(info.from,info.to)
		 		break
		 	end
		end
	end
}
------------------------------
-- loading and saving functions
------------------------------
function EditorAnimatedMeshObject.Deserialize( obj_info )
	local obj
	if obj_info.mesh_path and obj_info.scene_type == "mesh_animated"  then
		obj = map_editor.ImportAnimatedMesh(
			obj_info.mesh_path,obj_info.id, false,
			obj_info.position, obj_info.rotation, obj_info.scale)
	end
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		obj.scene_node:setLoopMode(obj.autoplay)
		if obj.startLoop ~= "" then
			for _,info in ipairs(obj.animation) do
			 	if info.label == obj.startLoop then
			 		obj.scene_node:setFrameLoop(info.from,info.to)
			 		break
			 	end
			end
		end
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorAnimatedMeshObject:Serialize( distObjName, fileWriter )
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
		file=DIR_MAPS..map_editor.map_name.."/"..file
		map_editor.WriteString(fileWriter, "mesh_path", file)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		-- animation infomation
		map_editor.WriteBool(fileWriter,"autoplay",self.autoplay)
		map_editor.WriteString(fileWriter,"startLoop",self.startLoop)

		fileWriter:write("animation = {\n")
		if #self.animation > 0 then
			for i=1,#self.animation do
				local cinfo = self.animation[i]
				fileWriter:write(string.format("{ id = %d, label = \"%s\", from = %d, to = %d },\n",
					cinfo.id,cinfo.label,cinfo.from,cinfo.to))
			end
		end
		fileWriter:write("}\n")

		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("\n} -- "..distObjName.."\n")
	end
end
--[[*****************************************
 define billboard object based on basic object
*******************************************]]
EditorBillboardObject = class(EditorObject)
EditorBillboardObject.name = "billboard"
EditorBillboardObject.scene_type = "billboard"
EditorBillboardObject.physics_type = "none"
EditorBillboardObject.width=10
EditorBillboardObject.height=10
EditorBillboardObject.color_top=irr.video.SColor:new_local(255,255,255,255)
EditorBillboardObject.color_bottom=irr.video.SColor:new_local(255,255,255,255)
-- delete unneed property
EditorBillboardObject.property.mesh_path=nil
--set functions
function EditorBillboardObject:setWidth( w )
	self.width = w
	if self.scene_node then
		local s=irr.core.dimension2df:new_local(w,self.height)
		self.scene_node:setSize(s)
	end
end

function EditorBillboardObject:setHeight( h )
	self.height = h
	if self.scene_node then
		local s=irr.core.dimension2df:new_local(self.width,h)
		self.scene_node:setSize(s)
	end
end

function EditorBillboardObject:setColorTop( c )
	self.color_top=c
	if self.scene_node then
		self.scene_node:setColor(self.color_top,self.color_bottom)
	end
end

function EditorBillboardObject:setColorBottom( c )
	self.color_bottom=c
	if self.scene_node then
		self.scene_node:setColor(self.color_top,self.color_bottom)
	end
end
-- property functions
EditorBillboardObject.property.width={
	set=function( obj, w )
		obj:setWidth(w)
	end
}
EditorBillboardObject.property.height={
	set=function( obj, h )
		obj:setHeight(h)
	end
}
EditorBillboardObject.property.color_top={
	display="top color",
	set=function( obj, c )
		obj:setColorTop(c)
	end
}
EditorBillboardObject.property.color_bottom={
	display="bottom color",
	set=function( obj, c )
		obj:setColorBottom(c)
	end
}
EditorBillboardObject.property.textures={
	type="StringList",
	set = function( obj, list )
		obj.textures={}
		obj.textures[1]=list[1]
		local texture = NeoGraphics:getInstance():LoadTexture(obj.textures[1])
		obj.scene_node:setMaterialTexture(0,texture)
	end
}
------------------------------
-- loading and saving functions
------------------------------
function EditorBillboardObject.Deserialize( obj_info )
	local obj
	if obj_info.mesh_path then
		obj = map_editor.ImportBillboard(
			obj_info.textures[1], obj_info.id, false,
			obj_info.position, obj_info.width, obj_info.height)
	end
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		obj.scene_node:setColor(obj.color_top,obj.color_bottom)
		obj:setRotation(obj.rotation)
		obj:setScale(obj.scale)
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorBillboardObject:Serialize( distObjName, fileWriter )
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
		map_editor.WriteFloat(fileWriter, "width", self.width)
		map_editor.WriteFloat(fileWriter, "height", self.height)
		map_editor.WriteSColor(fileWriter,"color_top",self.color_top)
		map_editor.WriteSColor(fileWriter,"color_bottom",self.color_bottom)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("\n} -- "..distObjName.."\n")
	end
end

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
 define event point based on basic object
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
-- texture loaded during editing
map_editor.textures={}
function map_editor.RemoveAllTextures()
	for k,_ in pairs(map_editor.textures) do
		local texture = NeoGraphics:getInstance():LoadTexture(k)
		if texture then
			NeoGraphics:getInstance():UnloadTexture(texture)
		end
		map_editor.textures[k]=nil
	end
end
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
function map_editor.WriteVector3df( fileWriter, vector_name ,vector, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s = irr.core.vector3df:new_local(%f,%f,%f)"..dim.."\n",
			vector_name, vector.X, vector.Y,vector.Z))
end

function map_editor.WriteSColor( fileWriter, scolor_name, color, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s = irr.video.SColor:new_local(%d,%d,%d,%d)"..dim.."\n",
			scolor_name, color:getAlpha(), color:getRed(), color:getGreen(), color:getBlue()))
end

function map_editor.WriteString( fileWriter, string_name, value, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s = \"%s\""..dim.."\n", string_name, value))
end

function map_editor.WriteInt( fileWriter, string_name, value, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s = %d"..dim.."\n", string_name, value))
end

function map_editor.WriteFloat( fileWriter, string_name, value, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s = %f"..dim.."\n", string_name, value))
end

function map_editor.WriteBool( fileWriter, string_name, value, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s = %s"..dim.."\n", string_name, tostring(value)))
end

function map_editor.WriteTextureArray( fileWriter, array_name ,texture_array, dim )
	dim=dim or ","
	fileWriter:write(array_name.." = {}"..dim.."\n")
	for i=1,#texture_array do
		local _,path = parsePath(texture_array[i])
		path=DIR_MAPS..map_editor.map_name.."/"..path
		fileWriter.write(string.format("%s[%d] = \"%s\"\n", array_name, i, path))
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
		local p = list_path[i]
		obj.textures[#obj.textures+1]=p
		map_editor.textures[p]=true
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
		local p = list_path[i]
		obj.textures[#obj.textures+1]=p
		map_editor.textures[p]=true
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
		local p = list_path[i]
		obj.textures[#obj.textures+1]=p
		map_editor.textures[p]=true
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


function map_editor.ImportBillboard( path, id, selected, position, width, height )
	path=path or DIR_RESOURCES.."Editor/default_billboard.png"
	if path=="" then
		path = DIR_RESOURCES.."Editor/default_billboard.png"
	end
	position=position or map_editor.getImportPosition()
	width=width or 10
	height=height or 10
	local obj=EditorBillboardObject.new()
	id=id or makeId()
	obj.id=id
	obj.name="billboard"
	obj.scene_type="billboard"
	local texture=NeoGraphics:getInstance():LoadTexture(path)
	local size = irr.core.dimension2df:new_local(width,height)
	local node=NeoGraphics:getInstance():AddBillboardSceneNode()
	node:setSize(size)
	if texture then
		node:setMaterialTexture(0,texture)
	end
	node:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	node:setMaterialType(irr.video.EMT_TRANSPARENT_ALPHA_CHANNEL)
	obj.textures[1]=path
	map_editor.textures[path]=true
	node:setID(id)
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
	obj:setSceneNode(node)
	obj:setPosition(position)
	obj.width=width
	obj.height=height
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end