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
EditorObject.cast_shadow=false
EditorObject.visible=true
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
			if #list == 1 then
				local texture = NeoGraphics:getInstance():LoadTexture(obj.textures[1])
				obj.scene_node:setMaterialTexture(0,texture)
			end
		end
	},
	
	texture_resolution={
		type="NumberArray",
		set = function ( obj, res )
			obj:setTextureResolution(res)
		end
	},
	cast_shadow = {
		display="cast shadow",
		set = function ( obj, c )		
			obj.cast_shadow=c
		end
	},
	visible={
		set=function ( obj, v )
			obj:setVisible(v)
		end
	}
	-- below feature doesn't work as expected
	-- texture_offset={
	-- 	set=function( obj, offset )
	-- 		obj:setTextureOffset(offset)
	-- 	end
	-- }
}

EditorObject.propertyItemTable={}
function EditorObject:onCreate()
	self.texture_resolution = {1,1}
	self.texture_offset = irr.core.vector3df:new_local(0,0,0)
end
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

function EditorObject:setVisible( v )
	-- body
	if self.scene_node then
		self.scene_node:setVisible(v)
		self.visible=v
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

function EditorObject:WriteTextureResoultion(file)
	if self.texture_resolution and (self.texture_resolution[1]~=1 or self.texture_resolution[2]~=1) then
		map_editor.WriteNumberArray(file,"texture_resolution",self.texture_resolution)
	end
	-- if self.texture_offset then
	-- 	map_editor.WriteVector3df(file,"texture_offset",self.texture_offset)
	-- end
end

function EditorObject:setTextureResolution(resolution)
	local prev_scale = self.texture_resolution
	self.texture_resolution=resolution or {1,1}
	if not resolution then
		return
	end
	local scale = deepcopy(resolution)
	scale[1]=self.texture_resolution[1]/prev_scale[1]
	scale[2]=self.texture_resolution[2]/prev_scale[2]
	if self.scene_type == "octree" then
		--octree needs to rebuild node
		if prev_scale == self.texture_resolution then
			return
		end
		local mesh = NeoGraphics:getInstance():getMesh(self.mesh_path)
		self.scene_node:remove()
		NeoGraphics:getInstance():ScaleTextureCoords(mesh,irr.core.vector2df:new_local(scale[1],scale[2]))
		local node = NeoGraphics:getInstance():AddOctreeSceneNode(mesh)

		if #self.textures == 1 then
			local texture = NeoGraphics:getInstance():LoadTexture(self.textures[1])
			node:setMaterialTexture(0,texture)
		end

		node:setID(self.id)
		NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"octree")
		node:setPosition(self.position)
		node:setRotation(self.rotation)
		node:setScale(self.scale)
		self:setSceneNode(node)
		node:updateAbsolutePosition()
	else
		NeoGraphics:getInstance():ScaleTextureCoords(self.scene_node:getMesh(),
		irr.core.vector2df:new_local(scale[1],scale[2]))
	end
end

-- function EditorObject:setTextureOffset( offset )
-- 	self.texture_offset=offset
-- 	NeoGraphics:getInstance():MakePlanarTextureMapping(self.scene_node:getMesh(),self.texture_resolution[1],self.texture_resolution[2],1,offset)
-- end
------------------------------
-- loading and saving functions
------------------------------
function EditorObject:Deserialize( obj_info )
	local obj
	if obj_info.mesh_path then
		if obj_info.scene_type == "mesh_static" then
			obj = map_editor.ImportStaticMesh(
				obj_info.mesh_path, obj_info.id, false, 
				obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name, obj_info.texture_resolution)
		elseif obj_info.scene_type == "octree" then
			obj = map_editor.ImportOctreeMesh(
				obj_info.mesh_path, obj_info.id, false,
				obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name, obj_info.texture_resolution)
		end
	end
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		-- apply (potential) external texture
		if #obj.textures == 1 then
			local texture = NeoGraphics:getInstance():LoadTexture(obj.textures[1])
			obj.scene_node:setMaterialTexture(0,texture)
		end
		if obj.visible == nil then
			obj.visible=true
		end
		obj:setVisible(obj.visible)
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
		map_editor.WriteBool(fileWriter,"visible",self.visible)
		map_editor.WriteBool(fileWriter,"cast_shadow",self.cast_shadow)
		map_editor.WritePath(fileWriter, "mesh_path", self.mesh_path)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		self:WriteTextureResoultion(fileWriter)
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
		local dup
		if obj.scene_type == "octree" then
			-- then clone function for octree isn't implemented in irrlicht, wtf
			local mesh = NeoGraphics:getInstance():getMesh(self.mesh_path)
			dup = NeoGraphics:getInstance():AddOctreeSceneNode(mesh)
			dup:setPosition(self.position)
			dup:setRotation(self.rotation)
			dup:setScale(self.scale)
			obj:setSceneNode(dup)
			NeoEditor:getInstance():setSceneNodeTriangleSelector(obj.scene_node,"octree")
		else
			dup = obj.scene_node:clone()
			dup=tolua.cast(dup,tolua.type(obj.scene_node))
			obj:setSceneNode(dup)			
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
EditorAnimatedMeshObject.property.texture_resolution=nil
EditorAnimatedMeshObject.property.texture_offset=nil
------------------------------
-- loading and saving functions
------------------------------
function EditorAnimatedMeshObject:Deserialize( obj_info )
	local obj
	if obj_info.mesh_path and obj_info.scene_type == "mesh_animated"  then
		obj = map_editor.ImportAnimatedMesh(
			obj_info.mesh_path,obj_info.id, false,
			obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name,obj_info.texture_resolution)
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
		if obj.visible == nil then
			obj.visible=true
		end
		obj:setVisible(obj.visible)
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
		map_editor.WriteBool(fileWriter,"visible",self.visible)
		map_editor.WritePath(fileWriter, "mesh_path", self.mesh_path)
		map_editor.WriteBool(fileWriter,"cast_shadow",self.cast_shadow)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		self:WriteTextureResoultion(fileWriter)
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
EditorBillboardObject.property.texture_resolution=nil
EditorBillboardObject.property.texture_offset=nil
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
		if obj.visible == nil then
			obj.visible=true
		end
		obj:setVisible(obj.visible)
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
		map_editor.WriteBool(fileWriter,"visible",self.visible)
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
-- EditorCubeObject.property.texture_resolution=nil
EditorCubeObject.property.texture_offset=nil
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
		obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name,obj_info.texture_resolution)
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		if obj.visible == nil then
			obj.visible=true
		end
		obj:setVisible(obj.visible)
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
		map_editor.WriteBool(fileWriter,"visible",self.visible)
		map_editor.WriteBool(fileWriter,"cast_shadow",self.cast_shadow)
		map_editor.WriteFloat(fileWriter, "size", self.size)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		self:WriteTextureResoultion(fileWriter)
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
EditorSphereObject.property.texture_resolution=nil
EditorSphereObject.property.texture_offset=nil
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
		obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name,obj_info.texture_resolution)
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		if obj.visible == nil then
			obj.visible=true
		end
		obj:setVisible(obj.visible)
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
		map_editor.WriteBool(fileWriter,"visible",self.visible)
		map_editor.WriteBool(fileWriter,"cast_shadow",self.cast_shadow)
		map_editor.WriteFloat(fileWriter, "radius", self.radius)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)
		self:WriteTextureResoultion(fileWriter)
		--physics data
		self:SerializePhysicsData(fileWriter)
		-- logic data
		map_editor.WriteString(fileWriter,"logic_data",self.logic_data)
		--enclosure
		fileWriter:write("} -- "..distObjName.."\n")
	end
end
--[[*****************************************
 define quad object based on basic object
*******************************************]]
EditorQuadObject = class(EditorObject)

function EditorQuadObject:onCreate()
	self.name = "quad"
	self.scene_type = "quad"
	self.size = irr.core.dimension2df:new_local()
	self.tile_count = irr.core.dimension2du:new_local()
	self.texture_repeat_count = irr.core.dimension2df:new_local()
end

EditorQuadObject.property.mesh_path=nil -- we don't need path here
EditorQuadObject.property.texture_resolution=nil
EditorQuadObject.property.size=
{
	readOnly=true,
	set = function( obj, s )
		obj.size=s
	end
}
EditorQuadObject.property.tile_count={
	readOnly=true,
	set = function( obj, tc )
		obj.tile_count=tc
	end
}
EditorQuadObject.property.texture_repeat_count={
	set = function( obj, trc )
		local mesh = obj.scene_node:getMesh()
		local s = trc.Width/(obj.size.Width*obj.tile_count.Height)
		local t = trc.Height/(obj.size.Height*obj.tile_count.Height)
		NeoGraphics:getInstance():MakePlanarTextureMapping(mesh,s,t,1)
		obj.texture_repeat_count = trc
	end
}
-- property functions
EditorQuadObject.property.textures={
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
function EditorQuadObject:Deserialize( obj_info )
	local obj = map_editor.AddQuad(
		obj_info.textures[1], obj_info.id, false,{obj_info.size.Width,obj_info.size.Height},
		{obj_info.tile_count.Width,obj_info.tile_count.Height},
		{obj_info.texture_repeat_count.Width,obj_info.texture_repeat_count.Height},
		obj_info.position, obj_info.rotation, obj_info.scale,self,obj_info.name)
	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		if obj.visible == nil then
			obj.visible=true
		end
		obj:setVisible(obj.visible)
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorQuadObject:Serialize( distObjName, fileWriter )
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
		map_editor.WriteDimesion2d(fileWriter, "size", self.size)
		map_editor.WriteBool(fileWriter,"visible",self.visible)
		map_editor.WriteBool(fileWriter,"cast_shadow",self.cast_shadow)
		map_editor.WriteDimesion2d(fileWriter, "tile_count", self.tile_count)
		map_editor.WriteDimesion2d(fileWriter, "texture_repeat_count", self.texture_repeat_count)
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
	self.attenuation=attenuation
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
EditorLightObject.property.texture_resolution=nil
EditorLightObject.property.texture_offset=nil
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

		if obj.visible == nil then
			obj.visible=true
		end
		obj:setVisible(obj.visible)

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
		map_editor.WriteBool(fileWriter,"visible",self.visible)
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
EditorEventPointObject.property.texture_resolution=nil
EditorEventPointObject.property.texture_offset=nil
EditorEventPointObject.property.visible=nil
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

--[[*****************************************
 define watersuface object based on basic object
*******************************************]]
EditorWaterSurfaceObject = class(EditorObject)
EditorWaterSurfaceObject.name = "watersurface"
EditorWaterSurfaceObject.scene_type = "water_surface"
EditorWaterSurfaceObject.wave_height = 2
EditorWaterSurfaceObject.wave_speed = 300
EditorWaterSurfaceObject.wave_length = 10
EditorWaterSurfaceObject.override_texture = false
EditorWaterSurfaceObject.build_type="quad"

EditorWaterSurfaceObject.property.mesh_path=nil
EditorWaterSurfaceObject.property.texture_offset=nil

EditorWaterSurfaceObject.property.build_type=
{
	readOnly=true,
	set = function( obj, t )
		obj.build_type=t
	end
}
EditorWaterSurfaceObject.property.texture_resolution=
{
	type="NumberArray",
	set=function( obj, res )
		obj:setTextureResolution(res)
	end
}
EditorWaterSurfaceObject.property.override_texture=
{
	set = function( obj, o )
		obj.override_texture=o
	end
}
EditorWaterSurfaceObject.property.wave_height=
{
	readOnly=true,
	set = function( obj, h )
		obj.wave_height=h
	end
}
EditorWaterSurfaceObject.property.wave_speed=
{
	readOnly=true,
	set = function( obj, s )
		obj.wave_speed=s
	end
}
EditorWaterSurfaceObject.property.wave_length=
{
	readOnly=true,
	set = function( obj, l )
		obj.wave_length=l
	end
}
-- property functions
EditorWaterSurfaceObject.property.textures={
	type="StringList",
	set = function( obj, list )
		obj.textures={}
		obj.textures[1]=list[1]
		local texture = NeoGraphics:getInstance():LoadTexture(obj.textures[1])
		obj.scene_node:setMaterialTexture(0,texture)
	end
}
function EditorWaterSurfaceObject:onCreate()
	self.texture_offset = nil
	self.property = deepcopy(EditorWaterSurfaceObject.property)
end
function EditorWaterSurfaceObject:UpdateProperty( build_type )
	if build_type == "quad" then
		for k,v in pairs(self.property_quad) do
			self.property[k]=v
		end
	elseif build_type == "cube" then 
		for k,v in pairs(self.property_cube) do
			self.property[k]=v
		end
	elseif build_type == "sphere" then
		for k,v in pairs(self.propery_sphere) do
			self.property[k]=v
		end
	elseif build_type == "mesh" then 
		for k,v in pairs(self.property_mesh) do
			self.property[k]=v
		end
	end
end
EditorWaterSurfaceObject.property_cube={
	size={
		readOnly=true,
		set=function( obj, s )
			obj.size=s
		end
	}
}
EditorWaterSurfaceObject.propery_sphere={
	radius={
		readOnly=true,
		set=function(obj, r)
			obj.radius=r
		end
	}
}
EditorWaterSurfaceObject.property_quad={
	size={
		readOnly=true,
		set=function( obj, s )
			obj.size=s
		end
	},
	tile_count={
		readOnly=true,
		set=function( obj, tc )
			obj.tile_count=tc
		end
	},
	texture_repeat_count={
		readOnly=true,
		set=function( obj, trc )
			obj.texture_resolution=trc
		end
	}
}
EditorWaterSurfaceObject.property_mesh={
	mesh_path={
		readOnly=true,
		set=function( obj, p )
			obj.mesh_path=p
		end
	}
}
function EditorWaterSurfaceObject:Clone()
	local obj = deepcopy(self)
	--assign new id
	obj.id=makeId()
	if obj.scene_node then
		local dup
		dup = NeoGraphics:getInstance():AddWaterSurfaceNode(obj.mesh,obj.wave_height,obj.wave_speed,obj.wave_length)
		if obj.override_texture then
			local texture = NeoGraphics:getInstance():LoadTexture(obj.textures[0])
			dup.setMaterialTexture(0,texture)
		end
		dup:setPosition(self.position)
		dup:setRotation(self.rotation)
		dup:setScale(self.scale)
		obj:setSceneNode(dup)			
		NeoEditor:getInstance():setSceneNodeTriangleSelector(obj.scene_node,"normal")
		obj.scene_node:setID(obj.id)
	end
	map_editor.AddObject(obj)
	map_editor.AddObjectToSceneWindow(obj,false)
	return obj 
end
function EditorWaterSurfaceObject:setTextureResolution(resolution)
	local prev_scale = self.texture_resolution
	self.texture_resolution=resolution or {1,1}
	if not resolution then
		return
	end
	local scale = deepcopy(resolution)
	scale[1]=self.texture_resolution[1]/prev_scale[1]
	scale[2]=self.texture_resolution[1]/prev_scale[2]
	
	--octree needs to rebuild node
	if prev_scale == self.texture_resolution then
		return
	end

	self.scene_node:remove()
	NeoGraphics:getInstance():ScaleTextureCoords(self.mesh,irr.core.vector2df:new_local(scale[1],scale[2]))
	local node = NeoGraphics:getInstance():AddWaterSurfaceNode(self.mesh,self.wave_height,self.wave_speed,self.wave_length)
	if self.override_texture then
		local texture = NeoGraphics:getInstance():LoadTexture(self.textures[1])
		node:setMaterialTexture(0,texture)
	end

	if self.texture_repeat_count then
		self.texture_repeat_count=irr.core.dimension2df:new_local(self.texture_resolution[1],self.texture_resolution[2])
	end

	node:setID(self.id)
	NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
	node:setPosition(self.position)
	node:setRotation(self.rotation)
	node:setScale(self.scale)
	self:setSceneNode(node)
	node:updateAbsolutePosition()
end
------------------------------
-- loading and saving functions
------------------------------
function EditorWaterSurfaceObject:SerializeBuildData(fileWriter)
	if self.build_type == "quad" then
		map_editor.WriteDimesion2d(fileWriter, "size", self.size)
		map_editor.WriteDimesion2d(fileWriter, "tile_count", self.tile_count)
		map_editor.WriteDimesion2d(fileWriter, "texture_repeat_count", self.texture_repeat_count)
	elseif self.build_type == "sphere" then
		map_editor.WriteFloat(fileWriter,"radius",self.radius)
	elseif self.build_type == "cube" then
		map_editor.WriteFloat(fileWriter,"size",self.size)
	elseif self.build_type == "mesh" then
		if self.mesh_path then
			map_editor.WritePath(fileWriter,"mesh_path",self.mesh_path)
		end
	end
end
function EditorWaterSurfaceObject:DeserializeBuildData( obj_info )
	if obj_info.build_type == "quad" then
		return {size={obj_info.size.Width,obj_info.size.Height},
		tile_count={obj_info.tile_count.Width,obj_info.tile_count.Height},
		texture_repeat_count={obj_info.texture_repeat_count.Width,obj_info.texture_repeat_count.Height}}
	elseif obj_info.build_type == "sphere" then
		return {radius=obj_info.radius}
	elseif obj_info.build_type == "cube" then
		return {size=obj_info.size}
	elseif obj_info.build_type == "mesh" then
		return {path=obj_info.mesh_path}
	end
end
function EditorWaterSurfaceObject:Deserialize( obj_info )
	local build_data = self:DeserializeBuildData(obj_info)
	local obj = map_editor.AddWaterSurface( 
		obj_info.build_type, build_data,{texture_path=obj_info.textures[1],resolution=obj_info.texture_resolution}, obj_info.override_texture, 
		obj_info.id, false, obj_info.wave_height, obj_info.wave_speed, obj_info.wave_length, 
		obj_info.position, obj_info.rotation, obj_info.scale, self, obj_info.name )

	if obj then
		-- loading node from map object info table
		for key,value in pairs(obj_info) do
			obj[key]=value
		end
		if obj.visible == nil then
			obj.visible=true
		end
		obj:setVisible(obj.visible)
		IDGenerator:Register(obj.id)
	end
	return obj
end

function EditorWaterSurfaceObject:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		map_editor.WriteString(fileWriter, "name", self.name)
		map_editor.WriteInt(fileWriter, "id", self.id)
		map_editor.WriteString(fileWriter, "scene_type", self.scene_type)
		map_editor.WriteString(fileWriter,"build_type",self.build_type)
		map_editor.WriteVector3df(fileWriter, "position", self.position)
		map_editor.WriteVector3df(fileWriter, "rotation", self.rotation)
		map_editor.WriteVector3df(fileWriter, "scale", self.scale)
		map_editor.WriteBool(fileWriter,"visible",self.visible)
		map_editor.WriteTextureArray(fileWriter, "textures", self.textures)

		map_editor.WriteBool(fileWriter,"override_texture",self.override_texture)
		self:SerializeBuildData(fileWriter)
		map_editor.WriteFloat(fileWriter,"wave_height",self.wave_height)
		map_editor.WriteFloat(fileWriter,"wave_speed",self.wave_speed)
		map_editor.WriteFloat(fileWriter,"wave_length",self.wave_length)

		self:WriteTextureResoultion(fileWriter)
		--physics data
		self:SerializePhysicsData(fileWriter)
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

function map_editor.WriteDimesion2d( fileWriter, dimension_name ,dimension, dim )
	dim=dim or ","
	local t = tolua.type(dimension):gsub("const ",""):gsub("::","."):gsub("<float>","f"):gsub("<unsigned>","u")
	fileWriter:write(string.format("%s = %s:new_local(%f,%f)"..dim.."\n",
			dimension_name, t, dimension.Width, dimension.Height))
end

function map_editor.WriteString( fileWriter, string_name, value, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s = \"%s\""..dim.."\n", string_name, value))
end

function map_editor.ConvertModelPath( path )
	local _,file=parsePath(path)
	local real_path = NeoEditor:getInstance():getRelativePath(path,map_editor.root_directory)
	local new_path=DIR_MAPS..map_editor.map_name.."/"..file
	local built_in_path_tex = map_editor.built_in_texture_directory..file
	local built_in_path_model = map_editor.built_in_model_directory..file

	if real_path == built_in_path_tex then
		new_path = built_in_path_tex
	elseif real_path == built_in_path_model then
		new_path = built_in_path_model
	end
	local is_built_in = (new_path == real_path or new_path == built_in_path_tex or new_path == built_in_path_model)
	return new_path,real_path,is_built_in
end

function map_editor.WritePath( fileWriter, string_name, path, dim )
	dim=dim or ","
	--modifie the mesh file path
	local new_path,real_path,is_built_in = map_editor.ConvertModelPath(path)	
	
	if not is_built_in then
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

function map_editor.WriteNumberArray( fileWriter, array_name, array, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s={ ",array_name))
	for _,v in ipairs(array) do
		fileWriter:write(tostring(v)..",")
	end
	fileWriter:write("}"..dim.."\n");
end

function map_editor.WriteTextureArray( fileWriter, array_name ,texture_array, dim )
	dim=dim or ","
	fileWriter:write(string.format("%s = {\n", array_name))
	for i=1,#texture_array do
		local new_path,real_path,is_built_in = map_editor.ConvertModelPath(texture_array[i])
		if not is_built_in then
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
	["irr::core::dimension2d<float>"] = map_editor.WriteDimesion2d,
	["irr::core::dimension2d<unsigned>"] = map_editor.WriteDimesion2d,
	string = map_editor.WriteString,
	number = map_editor.WriteFloat,
	boolean = map_editor.WriteBool
}
--------------
--import functions
--------------
function map_editor.ImportStaticMesh( path, id, selected, position, rotation, scale ,destObj, name, texture_res )
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
	local list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
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
	obj:setTextureResolution(texture_res)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.ImportAnimatedMesh( path, id,selected, position, rotation, scale,destObj, name, texture_res )
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
	local list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
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
	obj:setTextureResolution(texture_res)
	map_editor.AddObject(obj)
	map_editor.isOnScene=true
	node:updateAbsolutePosition()
	map_editor.AddObjectToSceneWindow(obj,selected)
	return obj
end

function map_editor.ImportOctreeMesh( path, id, selected, position, rotation, scale, destObj, name, texture_res )
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
	if texture_res then
		NeoGraphics:getInstance():ScaleTextureCoords(mesh,irr.core.vector2df:new_local(texture_res[1],texture_res[2]))
	end
	
	local node=NeoGraphics:getInstance():AddOctreeSceneNode(mesh)
	local list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
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
	obj.texture_resolution=texture_res or {1,1}
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

function map_editor.AddCube( texture_path, id, selected, size, position, rotation, scale, destObj, name, texture_res )
	texture_path=texture_path or map_editor.default_cube_texture_path
	if texture_path=="" then
		texture_path = map_editor.default_cube_texture_path
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	size=size or 10
	texture_res=texture_res or {1,1}
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
	obj:setTextureResolution(texture_res)
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
	else
		map_editor.isOnScene=true
	end
end

function map_editor.AddSphere( texture_path, id, selected, radius, position, rotation, scale, destObj, name, texture_res )
	texture_path=texture_path or map_editor.built_in_texture_directory.."CrackedGround_1-6.jpg"
	if texture_path=="" then
		texture_path = map_editor.built_in_texture_directory.."CrackedGround_1-6.jpg"
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	radius=radius or 5
	texture_res=texture_res or {1,1}
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
	obj:setTextureResolution(texture_res)
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
	else
		map_editor.isOnScene=true
	end
end

--@size={width,height}
--@tile_count={w,h}
--@texture_repeat_count={herizon,vertical}
function map_editor.AddQuad( texture_path, id, selected, size, tile_count, texture_repeat_count, position, rotation, scale, destObj, name )
	texture_path=texture_path or map_editor.built_in_texture_directory.."CrackedGround_1-6.jpg"
	if texture_path=="" then
		texture_path = map_editor.built_in_texture_directory.."CrackedGround_1-6.jpg"
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	size=size or {1,1}
	tile_count=tile_count or {1,1}
	texture_repeat_count=texture_repeat_count or {1,1}
	local obj=destObj or EditorQuadObject.new()
	id=id or makeId()
	obj.id=id
	obj.name=name or "quad"
	obj.scene_type="quad"
	obj.size=irr.core.dimension2df:new_local(size[1],size[2])
	obj.tile_count=irr.core.dimension2du:new_local(tile_count[1],tile_count[2])
	obj.texture_repeat_count=irr.core.dimension2df:new_local(texture_repeat_count[1],texture_repeat_count[2])
	local texture=NeoGraphics:getInstance():LoadTexture(texture_path)
	local quad_mesh = NeoGraphics:getInstance():CreateQuadMesh(obj.size,obj.tile_count,obj.texture_repeat_count)
	local node=NeoGraphics:getInstance():AddMeshSceneNode(quad_mesh)
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
function map_editor.AddQuadCallback(text)
	local data=assert(eval("{"..text.."}"))
	if data and #data==6 then
		--data={width,height,tile_x,tile_y,texture_repeat_x,texture_repeat_y}
		local size = {data[1],data[2]}
		local tile_count = {data[3],data[4]}
		local texture_repeat_count = {data[5],data[6]}
		map_editor.AddQuad(nil,nil,true,size,tile_count,texture_repeat_count)
	else
		map_editor.isOnScene=true
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

function map_editor.AddWaterSurfaceNode( mesh,texture_path, override_texture, wave_height, wave_speed, wave_length)
	override_texture=override_texture or false
	texture_path = texture_path or map_editor.built_in_texture_directory.."water.jpg"
	if texture_path=="" then
		texture_path = map_editor.built_in_texture_directory.."water.jpg"
	end
	local texture
	if not mesh then
		-- if no mesh, then create a quad as default
		override_texture=true
		local size=irr.core.dimension2df:new_local(10,10)
		local tile_count=irr.core.dimension2du:new_local(32,32)
		local texture_repeat_count=irr.core.dimension2df:new_local(1,1)
		texture=NeoGraphics:getInstance():LoadTexture(texture_path)
		mesh = NeoGraphics:getInstance():CreateQuadMesh(size,tile_count,texture_repeat_count)
	end
	wave_height = wave_height or 2
	wave_speed = wave_speed or 300
	wave_length = wave_length or 10
	local node = NeoGraphics:getInstance():AddWaterSurfaceNode(mesh,wave_height,wave_speed,wave_length)
	if override_texture then
		if not texture then
			texture = NeoGraphics:getInstance():LoadTexture(texture_path)
		end
		node:setMaterialTexture(0,texture)
	end

	return node, override_texture
end
--@texture_data={texture_path,resolution}
function map_editor.AddWaterSurface( build_type, build_data,texture_data, override_texture, id, selected, wave_height, wave_speed, wave_length, position, rotation, scale, destObj, name )
	local mesh
	local node
	local mesh_path
	texture_path = texture_data.texture_path or map_editor.built_in_texture_directory.."water.jpg"
	if texture_path=="" then
		texture_path = map_editor.built_in_texture_directory.."water.jpg"
	end
	position=position or map_editor.getImportPosition()
	rotation=rotation or irr.core.vector3df:new_local(0,0,0)
	scale=scale or irr.core.vector3df:new_local(1,1,1)
	wave_height = wave_height or 2
	wave_speed = wave_speed or 300
	wave_length = wave_length or 10
	local texture_res = texture_data.resolution or {1,1}
	if build_type == "quad" then
		build_data = build_data or { size={10,10},tile_count={32,32},texture_repeat_count={1,1} }
		local size=irr.core.dimension2df:new_local(build_data.size[1],build_data.size[2])
		local tile_count=irr.core.dimension2du:new_local(build_data.tile_count[1],build_data.tile_count[2])
		local texture_repeat_count=irr.core.dimension2df:new_local(build_data.texture_repeat_count[1],build_data.texture_repeat_count[2])
		mesh = NeoGraphics:getInstance():CreateQuadMesh(size,tile_count,texture_repeat_count)
		-- texture_repeat_count and resolution conflict
		--NeoGraphics:getInstance():ScaleTextureCoords(mesh,irr.core.vector2df:new_local(texture_res[1],texture_res[2]))
	elseif build_type == "cube" then
		build_data = build_data or {size=50}
		mesh = NeoGraphics:getInstance():CreateCubeMesh(irr.core.vector3df:new_local(build_data.size))
		NeoGraphics:getInstance():ScaleTextureCoords(mesh,irr.core.vector2df:new_local(texture_res[1],texture_res[2]))
	elseif build_type == "sphere" then
		build_data = build_data or {radius=25}
		mesh = NeoGraphics:getInstance():CreateSphereMesh(build_data.radius)
		NeoGraphics:getInstance():ScaleTextureCoords(mesh,irr.core.vector2df:new_local(texture_res[1],texture_res[2]))
	elseif build_type == "mesh" then
		if not build_data or not build_data.path then
			map_editor.isOnScene=true
			return
		end
		mesh_path = build_data.path
		mesh = NeoGraphics:getInstance():getMesh(build_data.path)
		if not mesh then
			map_editor.isOnScene=true
			return
		end
		NeoGraphics:getInstance():ScaleTextureCoords(mesh,irr.core.vector2df:new_local(texture_res[1],texture_res[2]))
	else
		map_editor.isOnScene=true
		return
	end
	if not mesh then
		return
	end
	node, override_texture = map_editor.AddWaterSurfaceNode(mesh,texture_path,override_texture,wave_height,wave_speed,wave_length)
	if node then
		local obj=destObj or EditorWaterSurfaceObject.new()
		id=id or makeId()
		obj.id=id
		obj.name=name or "watersurface"
		obj.scene_type="water_surface"
		obj.mesh = mesh
		if build_type == "quad" then
			obj.size=irr.core.dimension2df:new_local(build_data.size[1],build_data.size[2])
			obj.tile_count=irr.core.dimension2du:new_local(build_data.tile_count[1],build_data.tile_count[2])
			obj.texture_repeat_count=irr.core.dimension2df:new_local(build_data.texture_repeat_count[1],build_data.texture_repeat_count[2])
			obj.texture_resolution={build_data.texture_repeat_count[1],build_data.texture_repeat_count[2]}
		elseif build_type == "cube" then
			obj.size=build_data.size
		elseif build_type == "sphere" then
			obj.radius=build_data.radius
		elseif build_type == "mesh" then
			obj.mesh_path=build_data.path
		end
		local list_path = NeoGraphics:getInstance():getMeshTexturePath(mesh)
		--It's a c++ list, so index starts from 0
		obj.textures={}
		if override_texture then
			obj.textures[1]=texture_path
		else
			for i=0,list_path:size()-1 do
				local p = list_path[i]
				obj.textures[#obj.textures+1]=p
				map_editor.textures[p]=true
			end
		end
		node:setID(id)
		NeoEditor:getInstance():setSceneNodeTriangleSelector(node,"normal")
		obj:setSceneNode(node)
		obj:setPosition(position)
		obj:setRotation(rotation)
		obj:setScale(scale)
		
		obj.override_texture=override_texture
		-- quad built already set the resolution, so skip quad
		if build_type ~= "quad" then
			obj.texture_resolution=texture_res
		end
		obj.mesh_path=mesh_path
		obj.wave_length=wave_length
		obj.wave_speed=wave_speed
		obj.wave_height=wave_height
		obj.build_type=build_type

		map_editor.AddObject(obj)
		map_editor.isOnScene=true
		node:updateAbsolutePosition()
		map_editor.AddObjectToSceneWindow(obj,selected)

		obj:UpdateProperty(build_type)
		return obj
	end
end

function map_editor.AddQuadWaterSurfaceCallback( text )
	local data = assert(eval("{"..text.."}"))
	if data and #data==4 then
		local build_data = { size=data[1], tile_count=data[2], texture_repeat_count=data[3] }
		local texture_data = { resolution=data[3] }
		map_editor.AddWaterSurface("quad", build_data,texture_data, true, nil, true,
			data[4][1], data[4][2], data[4][3])
	else 
		map_editor.isOnScene=true
	end
end

function map_editor.AddCubeWaterSurfaceCallback( text )
	local data = assert(eval("{"..text.."}"))
	if data and #data==3 then
		local build_data = { size=data[1][1] }
		local texture_data = { resolution=data[2] }
		map_editor.AddWaterSurface("cube", build_data,texture_data, true, nil, true,
			data[3][1], data[3][2], data[3][3])
	else 
		map_editor.isOnScene=true
	end
end

function map_editor.AddSphereWaterSurfaceCallback( text )
	local data = assert(eval("{"..text.."}"))
	if data and #data==3 then
		local build_data = { radius=data[1][1] }
		local texture_data = { resolution=data[2] }
		map_editor.AddWaterSurface("sphere", build_data,texture_data, true, nil, true,
			data[3][1], data[3][2], data[3][3])
	else 
		map_editor.isOnScene=true
	end
end

function map_editor.AddMeshWaterSurfaceCallback( text )
	local data = assert(eval("{"..text.."}"))
	if data and #data==3 then
		local build_data = { path=data[3][1] }
		local texture_data = { resolution=data[1] }
		map_editor.AddWaterSurface("mesh", build_data,texture_data, false, nil, true,
			data[2][1], data[2][2], data[2][3])
	else 
		map_editor.isOnScene=true
	end
end
-------------------------------------------------
-- save and load
-------------------------------------------------
function map_editor:save(name)
	self.map_name=name or self.map_name
	print("Save map: "..self.map_name.." ...")
	-- create resource folder
	NeoEditor:getInstance():ChangeWorkingDirectory(map_editor.root_directory);
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
			local dir,filename = parsePath(fpath)
			local dir_full = NeoGame.io.getAbsolutePath(dir)
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
	quad=function( info )
		local obj = EditorQuadObject.new()
		obj:Deserialize(info)
	end,
	water_surface=function( info )
		local obj = EditorWaterSurfaceObject.new()
		obj:Deserialize(info)
	end,
	--particle_sys=, -- not available yet
	-- camera=, -- not available yet
}
function map_editor:load( path )
	NeoEditor:getInstance():ChangeWorkingDirectory(map_editor.root_directory);
	print("Loading map: ",path)
	local info =  assert(dofile(path))
	if not info then
		print("map open failed")
	end
	map_editor.CleanUp(false)
	map_editor.Init(false)
	-- map settings
	local mapSettings = info.setting
	self.map_name = mapSettings.map_name
	self.root_object.property["ambient colour"].set(
		self.root_object,mapSettings["ambient colour"])
	self.root_object.property["skydome texture"].set(
		self.root_object,mapSettings["skydome texture"])
	self.root_object.logic_data=mapSettings.logic_data
	-- load objects
	for _,obj in ipairs(info.objects) do
		if self.objectLoader[obj.scene_type] then
			self.objectLoader[obj.scene_type](obj)
		end
	end
	print("Loading done")
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