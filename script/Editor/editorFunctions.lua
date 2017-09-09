--[[************************************
 define basice object for map editor
**************************************]]
EditorObject=class()
EditorObject.name="mesh"
EditorObject.id=-1
EditorObject.scene_type="mesh_static"
EditorObject.position=irr.core.vector3df:new_local()
EditorObject.rotation=irr.core.vector3df:new_local()
EditorObject.scale=irr.core.vector3df:new_local(1,1,1)
EditorObject.scene_node=nil
EditorObject.mesh_path=nil
EditorObject.physics_data={
	physics_type="none"
}
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
		self.scale=scale
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
-- delete self
function EditorObject:Remove()
	if self.scene_node then
		self.scene_node:remove()
	end
end
------------------------------
-- loading and saving functions
------------------------------
function EditorObject:Deserialize( obj_info )
	local obj
	if obj_info.mesh_path then
		if obj_info.scene_type == "mesh_static" then
			obj = map_editor.ImportStaticMesh(
				obj_info.mesh_path, obj_info.id, false, 
				obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name)
		elseif obj_info.scene_type == "octree" then
			obj = map_editor.ImportOctreeMesh(
				obj_info.mesh_path, obj_info.id, false,
				obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name)
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

function EditorObject:SerializePhysicsData( fileWriter )
	--begin
	fileWriter:write("physics_data = {\n")
	--body
	for k,v in pairs(self.physics_data) do
		local datatype = tolua.type(v):gsub("const ","")
		map_editor.dataWriter[datatype](fileWriter,k,v)
	end
	--enclosure
	fileWriter:write("}, -- physics_data\n")
end

function EditorObject:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		map_editor.WriteString(fileWriter, "name", self.name)
		map_editor.WriteInt(fileWriter, "id", self.id)
		map_editor.WriteString(fileWriter, "scene_type", self.scene_type)
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		map_editor.WritePath(fileWriter, "mesh_path", self.mesh_path)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		--physics data
		self:SerializePhysicsData(fileWriter)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
	end
end
------------------------------
-- function for copy object
------------------------------
function EditorObject:Clone()
	local obj = deepcopy(self)
	--assign new id
	obj.id=makeId()
	if obj.scene_node then
		obj:setSceneNode(obj.scene_node:clone())
		if obj.scene_type == "octree" then
			NeoEditor:getInstance():setSceneNodeTriangleSelector(obj.scene_node,"octree")
		else
			NeoEditor:getInstance():setSceneNodeTriangleSelector(obj.scene_node,"normal")
		end
		obj.scene_node:setID(obj.id)
	end
	map_editor.AddObject(obj)
	map_editor.AddObjectToSceneWindow(obj,false)
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
			print("color set")
		end
	},
	["skydome texture"]={
		set = function(obj, text)						
			if obj["skydome texture"] ~= text then
				local new_texture=NeoGraphics:getInstance():LoadTexture(text)
				map_editor.skybox:setMaterialTexture(0,new_texture)
				NeoGraphics:getInstance():UnloadTexture(map_editor.skyboxTexture)
				map_editor.skyboxTexture=new_texture
			end	
			obj["skydome texture"]=text		
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
function EditorAnimatedMeshObject:Deserialize( obj_info )
	local obj
	if obj_info.mesh_path and obj_info.scene_type == "mesh_animated"  then
		obj = map_editor.ImportAnimatedMesh(
			obj_info.mesh_path,obj_info.id, false,
			obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name)
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
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		map_editor.WritePath(fileWriter, "mesh_path", self.mesh_path)
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
		fileWriter:write("},\n")
		--physics data
		self:SerializePhysicsData(fileWriter)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
	end
end
--[[*****************************************
 define billboard object based on basic object
*******************************************]]
EditorBillboardObject = class(EditorObject)
EditorBillboardObject.name = "billboard"
EditorBillboardObject.scene_type = "billboard"
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
function EditorBillboardObject:Deserialize( obj_info )
	local obj = map_editor.ImportBillboard(
		obj_info.textures[1], obj_info.id, false,
		obj_info.position, obj_info.width, obj_info.height,self,obj_info.name)
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
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		map_editor.WriteFloat(fileWriter, "width", self.width)
		map_editor.WriteFloat(fileWriter, "height", self.height)
		map_editor.WriteSColor(fileWriter,"color_top",self.color_top)
		map_editor.WriteSColor(fileWriter,"color_bottom",self.color_bottom)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		--physics data
		self:SerializePhysicsData(fileWriter)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
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
-- property functions
EditorCubeObject.property.textures={
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
function EditorCubeObject:Deserialize( obj_info )
	local obj = map_editor.AddCube(
		obj_info.textures[1], obj_info.id, false,obj_info.size,
		obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name)
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorCubeObject:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		map_editor.WriteString(fileWriter, "name", self.name)
		map_editor.WriteInt(fileWriter, "id", self.id)
		map_editor.WriteString(fileWriter, "scene_type", self.scene_type)
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		map_editor.WriteFloat(fileWriter, "size", self.size)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		--physics data
		self:SerializePhysicsData(fileWriter)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
	end
end
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
-- property functions
EditorSphereObject.property.textures={
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
function EditorSphereObject:Deserialize( obj_info )
	local obj = map_editor.AddSphere(
		obj_info.textures[1], obj_info.id, false,obj_info.radius,
		obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name)
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorSphereObject:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		map_editor.WriteString(fileWriter, "name", self.name)
		map_editor.WriteInt(fileWriter, "id", self.id)
		map_editor.WriteString(fileWriter, "scene_type", self.scene_type)
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		map_editor.WriteFloat(fileWriter, "radius", self.radius)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		--physics data
		self:SerializePhysicsData(fileWriter)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
	end
end
--[[*****************************************
 define light object based on basic object
*******************************************]]
EditorLightObject = class(EditorObject)
EditorLightObject.name = "light"
EditorLightObject.scene_type = "light"
EditorLightObject.ambient_color = irr.video.SColor:new_local(0,0,0,0)
EditorLightObject.diffuse_color = irr.video.SColor:new_local(255,255,255,255)
EditorLightObject.specular_color = irr.video.SColor:new_local(255,255,255,255)
EditorLightObject.attenuation = irr.core.vector3df:new_local(0,0.01,0)
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
EditorLightObject.icon=nil
EditorLightObject.physics_data=nil
-- set functions
function EditorLightObject:setPosition(position)
	-- body
	if(self.scene_node) then
		self.position=position
		self.scene_node:setPosition(position)
		self.icon:setPosition(position)
	end
end

function EditorLightObject:setAmbientColor(color)
	self.ambient_color=color
	if self.scene_node then
		self.scene_node:getLightData().AmbientColor=irr.video.SColorf:new_local(color)
	end
end

function EditorLightObject:setDiffuseColor( color )
	self.diffuse_color=color
	if self.scene_node then
		self.scene_node:getLightData().DiffuseColor=irr.video.SColorf:new_local(color)
	end
end

function EditorLightObject:setSpecularColor( color )
	self.specular_color=color
	if self.scene_node then
		self.scene_node:getLightData().SpecularColor=irr.video.SColorf:new_local(color)
	end
end

function EditorLightObject:setAtenuation( attenuation )
	self.attenuation=color
	if self.scene_node then
		self.scene_node:getLightData().Attenuation=attenuation
	end
end

function EditorLightObject:setOuterCone( outerCone )
	self.outerCone=outerCone
	if self.scene_node then
		self.scene_node:getLightData().OuterCone=outerCone
	end
end

function EditorLightObject:setInnerCone( innerCone )
	self.InnerCone=innerCone
	if self.scene_node then
		self.scene_node:getLightData().InnerCone=innerCone
	end
end

function EditorLightObject:setFalloff( f )
	self.falloff=f
	if self.scene_node then
		self.scene_node:getLightData().Falloff=f
	end
end

function EditorLightObject:setRadius( r )
	self.radius=r
	if self.scene_node then
		self.scene_node:setRadius(r)
	end
end

function EditorLightObject:setCastShadow( castShadow )
	self.cast_shadow=castShadow
	if self.scene_node then
		self.scene_node:enableCastShadow(castShadow)
	end
end

function EditorLightObject:setLightType( type )
	self.light_type=type
	if self.scene_node and self.type_list[type] then
		self.scene_node:setLightType(self.type_list[type])
	end
end

function EditorLightObject:Remove()
	if self.icon then
		self.icon:remove()
	end
	if self.scene_node then
		self.scene_node:remove()
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
EditorLightObject.property.attenuation={
	display="Attenuation",
	set=function( obj, att )
		obj:setAtenuation(att)
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
------------------------------
-- function for copy object
------------------------------
function EditorLightObject:Clone()
	local obj = deepcopy(self)
	--assign new id
	obj.id=makeId()
	if obj.scene_node then
		obj:setSceneNode(obj.scene_node:clone())
		obj.scene_node:setID(obj.id)
	end
	if obj.icon then
		obj.icon=obj.icon:clone()
		obj.icon.setID(obj.id)
		NeoEditor:getInstance():setSceneNodeTriangleSelector(obj.icon,"normal")
	end
	map_editor.AddObject(obj)
	map_editor.AddObjectToSceneWindow(obj,false)
	return obj
end
------------------------------
-- loading and saving functions
------------------------------
function EditorLightObject:Deserialize( obj_info )
	local obj = map_editor.AddLightObject(
		obj_info.id,false,obj_info.position, obj_info.rotation, 
		obj_info.scale,self,obj_info.name)
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		obj:setRadius(obj.radius)
		obj:setAmbientColor(obj.ambient_color)
		obj:setDiffuseColor(obj.diffuse_color)
		obj:setSpecularColor(obj.specular_color)
		obj:setFalloff(obj.falloff)
		obj:setAtenuation(obj.attenuation)
		obj:setCastShadow(obj.cast_shadow)
		obj:setInnerCone(obj.innerCone)
		obj:setOuterCone(obj.outerCone)
		obj:setLightType(obj.light_type)
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorLightObject:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		map_editor.WriteString(fileWriter, "name", self.name)
		map_editor.WriteInt(fileWriter, "id", self.id)
		map_editor.WriteString(fileWriter, "scene_type", self.scene_type)
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		map_editor.WriteSColor(fileWriter,"ambient_color",self.ambient_color)
		map_editor.WriteSColor(fileWriter,"diffuse_color",self.diffuse_color)
		map_editor.WriteSColor(fileWriter,"specular_color",self.specular_color)
		map_editor.WriteVector3df(fileWriter,"attenuation",self.attenuation)
		map_editor.WriteFloat(fileWriter,"falloff",self.falloff)
		map_editor.WriteFloat(fileWriter,"outerCone",self.outerCone)
		map_editor.WriteFloat(fileWriter,"innerCone",self.innerCone)
		map_editor.WriteFloat(fileWriter, "radius", self.radius)
		map_editor.WriteBool(fileWriter,"cast_shadow",self.cast_shadow)
		map_editor.WriteString(fileWriter,"light_type",self.light_type)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
	end
end
--[[*****************************************
 define event point based on basic object
*******************************************]]
EditorEventPointObject=class(EditorObject)
EditorEventPointObject.name="event point"
EditorEventPointObject.scene_type="event_point"
EditorEventPointObject.property.physics_data=nil
EditorEventPointObject.property.mesh_path=nil
EditorEventPointObject.property.textures=nil
------------------------------
-- loading and saving functions
------------------------------
function EditorEventPointObject:Deserialize( obj_info )
	local obj = map_editor.AddEventPoint(
		obj_info.id, false, obj_info.position, obj_info.rotation, 
		obj_info.scale,self,obj_info.name)
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorEventPointObject:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		map_editor.WriteString(fileWriter, "name", self.name)
		map_editor.WriteInt(fileWriter, "id", self.id)
		map_editor.WriteString(fileWriter, "scene_type", self.scene_type)
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
	end
end
--[[*****************************************
 define event point based on basic object
*******************************************]]
EditorSpawnPoint=class(EditorEventPointObject)
EditorSpawnPoint.name="spawn point"
EditorSpawnPoint.scene_type="spawn_point"
EditorSpawnPoint.team=1
map_editor.team_color={
	irr.video.SColor:new_local(255,66,134,244),-- blue
	irr.video.SColor:new_local(255,252,61,40),-- red
	irr.video.SColor:new_local(255,41,255,30),-- green
	irr.video.SColor:new_local(255,255,206,30),-- yellow
	irr.video.SColor:new_local(255,203,48,255) -- purple
}
-- set functions
function EditorSpawnPoint:setTeam( t )
	t=t or 1
	if t<=0 then
		t=1
	end
	local colour_index = t
	if colour_index > #map_editor.team_color then
		colour_index=#map_editor.team_color
	end
	self.team=t
	NeoEditor:getInstance():setMeshNodeColor(self.scene_node,map_editor.team_color[colour_index])
end
-- property functions
EditorSpawnPoint.property.team={
	type="int",
	set=function( obj, t )
		obj:setTeam(t)
	end
}
------------------------------
-- loading and saving functions
------------------------------
function EditorSpawnPoint:Deserialize( obj_info )
	local obj = map_editor.AddSpawnPoint(
		obj_info.team, obj_info.id, false, 
		obj_info.position, obj_info.rotation, 
		obj_info.scale,self,obj_info.name)
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorSpawnPoint:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		map_editor.WriteString(fileWriter, "name", self.name)
		map_editor.WriteInt(fileWriter, "id", self.id)
		map_editor.WriteString(fileWriter, "scene_type", self.scene_type)
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		map_editor.WriteInt(fileWriter, "team", self.team)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
	end
end
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
			end
			obj:Remove()
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
--copy functions
----------------
function map_editor.CopyObjects(objects)
	local ret = {}
	for i=1,#objects do
		if objects[i] ~= map_editor.root_object then
			ret[#ret+1]=objects[i]:Clone()
		end
	end
	return ret
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

function map_editor.WritePath( fileWriter, string_name, path, dim )
	dim=dim or ","
	--modifie the mesh file path
	local _,file=parsePath(path)
	local real_path = NeoEditor:getInstance():getRelativePath(path,map_editor.root_directory)
	local new_path=DIR_MAPS..map_editor.map_name.."/"..file
	if new_path ~= real_path then
		-- add to copy list
		map_editor.copy_list[real_path]=true
		local lpath = file:lower()
		if lpath:match("[.]obj$") then
			-- if file is obj, then copy mtl file
			local mtl=real_path:match(".*[.]").."mtl"
			if NeoEditor:getInstance():IsFileExists(mtl) then
				map_editor.copy_list[mtl]=true
			end
		end
	end
	fileWriter:write(string.format("%s = \"%s\""..dim.."\n", string_name, new_path))
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
	fileWriter:write(string.format("%s = {\n", array_name))
	for i=1,#texture_array do
		local _,path = parsePath(texture_array[i])
		local real_path = NeoEditor:getInstance():getRelativePath(texture_array[i],map_editor.root_directory)
		local new_path=DIR_MAPS..map_editor.map_name.."/"..path
		if new_path ~= real_path then
			-- add to copy list
			map_editor.copy_list[real_path]=true
		end
		fileWriter:write(string.format("\"%s\",\n", new_path))
	end
	fileWriter:write("}"..dim.." -- "..array_name.."\n")
end
--方便集成调用的函数表
map_editor.dataWriter={
	["irr::core::vector3d<float>"] = map_editor.WriteVector3df,
	["irr::video::SColor"] = map_editor.WriteSColor,
	string = map_editor.WriteString,
	number = map_editor.WriteFloat,
	boolean = map_editor.WriteBool
}
--------------
--import functions
--------------
function map_editor.ImportStaticMesh( path, id, selected, position, rotation, scale ,destObj, name )
	if not path then
		-- cancel button is clicked
		map_editor.isOnScene=true
		return
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	local obj= destObj or EditorObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "mesh"
	obj.scene_type="mesh_static"
	obj.mesh_path=path
	local mesh=NeoGraphics:getInstance():getMesh(path)
	local node=NeoGraphics:getInstance():AddMeshSceneNode(mesh)
	local vector_std__string_ list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
	--It's a c++ list, so index starts from 0
	obj.textures={}
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
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.ImportAnimatedMesh( path, id,selected, position, rotation, scale,destObj, name )
	if not path then
		-- cancel button is clicked
		map_editor.isOnScene=true
		return
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	local obj=destObj or EditorAnimatedMeshObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "animated mesh"
	obj.scene_type="mesh_animated"
	obj.mesh_path=path
	local mesh=NeoGraphics:getInstance():getMesh(path)
	local node=NeoGraphics:getInstance():AddAnimatedMeshSceneNode(mesh)
	local vector_std__string_ list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
	--It's a c++ list, so index starts from 0
	obj.textures={}
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
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.ImportOctreeMesh( path, id, selected, position, rotation, scale, destObj, name )
	if not path then
		-- cancel button is clicked
		map_editor.isOnScene=true
		return
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	local obj=destObj or EditorObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "octree"
	obj.scene_type="octree"
	obj.mesh_path=path
	local mesh=NeoGraphics:getInstance():getMesh(path)
	local node=NeoGraphics:getInstance():AddOctreeSceneNode(mesh)
	local vector_std__string_ list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
	--It's a c++ list, so index starts from 0
	obj.textures={}
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
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end


function map_editor.ImportBillboard( path, id, selected, position, width, height, destObj, name )
	path=path or DIR_RESOURCES.."Editor/default_billboard.png"
	if path=="" then
		path = DIR_RESOURCES.."Editor/default_billboard.png"
	end
	position=position or map_editor.getImportPosition()
	width=width or 10
	height=height or 10
	local obj=destObj or EditorBillboardObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "billboard"
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
	obj.textures={}
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
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.AddCube( texture_path, id, selected, size, position, rotation, scale, destObj, name )
	texture_path=texture_path or DIR_RESOURCES.."Editor/default_cobe_texture.png"
	if texture_path=="" then
		texture_path = DIR_RESOURCES.."Editor/default_cobe_texture.png"
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	size=size or 10
	local obj=destObj or EditorCubeObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "cube"
	obj.scene_type="cube"
	obj.size=size
	local texture=NeoGraphics:getInstance():LoadTexture(texture_path)
	local node=NeoGraphics:getInstance():AddCubeSceneNode(size)
	if texture then
		node:setMaterialTexture(0,texture)
	end
	obj.textures={}
	obj.textures[1]=texture_path
	map_editor.textures[texture_path]=true
	node:setID(id)
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
	obj:setSceneNode(node)
	obj:setPosition(position)
	obj:setRotation(rotation)
	obj:setScale(scale)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end
-- function for insert menu
function map_editor.AddCubeCallback(text)
	local size=tonumber(text)
	if size then
		map_editor.AddCube(nil,nil,true,size)
	end
end

function map_editor.AddSphere( texture_path, id, selected, radius, position, rotation, scale, destObj, name )
	texture_path=texture_path or DIR_RESOURCES.."Editor/CrackedGround_1-6.jpg"
	if texture_path=="" then
		texture_path = DIR_RESOURCES.."Editor/CrackedGround_1-6.jpg"
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	radius=radius or 5
	local obj=destObj or EditorSphereObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "sphere"
	obj.scene_type="sphere"
	obj.radius=radius
	local texture=NeoGraphics:getInstance():LoadTexture(texture_path)
	local node=NeoGraphics:getInstance():AddSphereSceneNode(radius)
	if texture then
		node:setMaterialTexture(0,texture)
	end
	obj.textures={}
	obj.textures[1]=texture_path
	map_editor.textures[texture_path]=true
	node:setID(id)
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
	obj:setSceneNode(node)
	obj:setPosition(position)
	obj:setRotation(rotation)
	obj:setScale(scale)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end
-- function for insert menu
function map_editor.AddSphereCallback(text)
	local radius=tonumber(text)
	if radius then
		map_editor.AddSphere(nil,nil,true,radius)
	end
end

function map_editor.AddLightObject( id, selected, position, rotation, scale, destObj, name )
	local texture_path=DIR_RESOURCES.."Editor/default_light.png"
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	local obj=destObj or EditorLightObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "light"
	obj.scene_type="light"
	-- add icon billboard
	local texture=NeoGraphics:getInstance():LoadTexture(texture_path)
	obj.icon=NeoGraphics:getInstance():AddBillboardSceneNode()
	obj.icon:setID(id)
	if texture then
		obj.icon:setMaterialTexture(0,texture)
	end
	obj.icon:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	obj.icon:setMaterialType(irr.video.EMT_TRANSPARENT_ALPHA_CHANNEL)
	map_editor.textures[texture_path]=true
	-- add node
	local node=NeoGraphics:getInstance():AddLightSceneNode()
	node:setID(id)
	NeoEditor:getInstance():setSceneNodeTriangleSelector(obj.icon,"normal")
	obj:setSceneNode(node)
	obj:setPosition(position)
	obj:setRotation(rotation)
	obj:setScale(scale)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.AddEventPoint( id, selected, position, rotation, scale, destObj, name )
	local texture_path=DIR_RESOURCES.."Editor/event_point.png"
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	local obj=destObj or EditorEventPointObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "event point"
	obj.scene_type="event_point"
	-- add icon billboard
	local texture=NeoGraphics:getInstance():LoadTexture(texture_path)
	local node=NeoGraphics:getInstance():AddBillboardSceneNode()
	if texture then
		node:setMaterialTexture(0,texture)
	end
	node:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	node:setMaterialType(irr.video.EMT_TRANSPARENT_ALPHA_CHANNEL)
	map_editor.textures[texture_path]=true
	local parent = NeoGraphics:getInstance():AddEmptySceneNode()
	node:setParent(parent)
	-- add node
	node:setID(id)
	parent:setID(id)
	local new_pos = irr.core.vector3df:new_local(0,5,0)
	node:setPosition(new_pos)
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
	obj:setSceneNode(parent)
	obj:setPosition(position)
	obj:setRotation(rotation)
	obj:setScale(scale)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	parent:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.AddSpawnPoint( team, id,selected, position, rotation, scale, destObj, name )
	team=team or 1
	if team <= 0 then
		team=1
	end
	local color_index = team
	if color_index > #map_editor.team_color then
		color_index = #map_editor.team_color
	end
	local mesh_path=DIR_RESOURCES.."Editor/spawnPoint_tank.obj"
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	local obj=destObj or EditorSpawnPoint.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "spawn point"
	obj.scene_type="spawn_point"
	obj.team=team
	-- add mesh as icon
	local mesh=NeoGraphics:getInstance():getMesh(mesh_path)
	local node=NeoGraphics:getInstance():AddMeshSceneNode(mesh)
	NeoEditor:getInstance():setMeshNodeColor(node,map_editor.team_color[color_index])
	node:setMaterialFlag(irr.video.EMF_LIGHTING, true)
	-- add node
	node:setID(id)
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
	obj:setSceneNode(node)
	obj:setPosition(position)
	obj:setRotation(rotation)
	obj:setScale(scale)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end
-------------------------------------------------
-- save and load
-------------------------------------------------
function map_editor:save(name)
	self.map_name=name or self.map_name
	print("Save map: "..self.map_name.." ...")
	-- create resource folder
	createDirectory(DIR_MAPS..self.map_name)
	mapfile=io.open(DIR_MAPS..self.map_name..".lua","w")
	if mapfile then
		-- clear copy list
		map_editor.copy_list={}
		-- save map settings
		mapfile:write("local map_info={}\nmap_info.setting={\n")
		map_editor.WriteString(mapfile,"map_name",self.map_name)
		map_editor.WriteSColor(mapfile,"[\"ambient colour\"]",self.root_object["ambient colour"])
		map_editor.WriteString(mapfile,"[\"skydome texture\"]",self.root_object["skydome texture"])
		map_editor.WriteString(mapfile,"logic_data",self.root_object.logic_data)
		mapfile:write("} -- settings\n")
		-- save objects
		mapfile:write("-- objects\nmap_info.objects={}\n")
		for i=1,#self.objects do
			local obj_name = "map_info.objects["..i.."]"
			self.objects[i]:Serialize(obj_name,mapfile)
		end
		-- return data to caller
		mapfile:write("return map_info")
		--close file
		io.close(mapfile)
		-- copy files
		local folder_path = DIR_MAPS..map_editor.map_name.."/"
		for fpath,_ in pairs(map_editor.copy_list) do
			local _,filename = parsePath(fpath)
			local new_path = folder_path..filename
			copyFile(fpath,new_path)
		end
	end
	print("Save done.")
	map_editor.saved=true
end
-- function for file menu
function map_editor.SaveCallback(text)
	text=text or ""
	if text == "" then
		return
	end
	map_editor:save(text)
	NeoGraphics:getInstance():setWindowCaption("Map Editor -- "..map_editor.map_name)
	map_editor.isOnScene=true
end
-- load map
map_editor.objectLoader={
	mesh_static=function( info )
		local obj = EditorObject.new()
		obj:Deserialize(info)
	end,
	mesh_animated=function( info )
		local obj = EditorAnimatedMeshObject.new()
		obj:Deserialize(info)
	end,
	billboard=function( info )
		local obj = EditorBillboardObject.new()
		obj:Deserialize(info)
	end,
	light=function( info )
		local obj = EditorLightObject.new()
		obj:Deserialize(info)
	end,
	octree=function( info )
		local obj = EditorObject.new()
		obj:Deserialize(info)
	end,
	event_point=function( info )
		local obj = EditorEventPointObject.new()
		obj:Deserialize(info)
	end,
	spawn_point=function( info )
		local obj = EditorSpawnPoint.new()
		obj:Deserialize(info)
	end,
	cube=function( info )
		local obj = EditorCubeObject.new()
		obj:Deserialize(info)
	end,
	sphere=function( info )
		local obj = EditorSphereObject.new()
		obj:Deserialize(info)
	end,
	--particle_sys=, -- not available yet
	-- camera=, -- not available yet
}
function map_editor:load( path )
	local info =  assert(dofile(path))
	NeoEditor:getInstance():ChangeWorkingDirectory(map_editor.root_directory);
	map_editor.CleanUp(false)
	map_editor.Init(false)
	-- map settings
	local mapSettings = info.setting
	self.map_name = mapSettings.map_name
	self.root_object.property["ambient colour"].set(
		self.root_object,mapSettings["ambient colour"])
	self.root_object.property["skydome texture"].set(
		self.root_object,mapSettings["skydome texture"])
	-- load objects
	for _,obj in ipairs(info.objects) do
		if self.objectLoader[obj.scene_type] then
			self.objectLoader[obj.scene_type](obj)
		end
	end
end

function map_editor.LoadCallback( text )
	text=text or ""
	if text == "" then
		return
	end
	map_editor:load(text)
	NeoGraphics:getInstance():setWindowCaption("Map Editor -- "..map_editor.map_name)
	map_editor.saved=true
	map_editor.isOnScene=true
	map_editor.UpdatePropertyWindow(map_editor.root_object)
end