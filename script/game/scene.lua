Scene={}
Scene.entities={}
Scene.load=SceneLoaderGeneric
Scene.loading_percent=0
Scene.entityMap={
	common=CommonObjectEntity
}

Scene.nodeLoader={
	mesh_static=function( info )
		local mesh=NeoGraphics:getInstance():getMesh(info.mesh_path)
		local node=NeoGraphics:getInstance():AddMeshSceneNode(mesh)
		node:setPosition(position)
		node:setRotation(rotation)
		node:setScale(scale)
		node:updateAbsolutePosition()
		return node
	end,
	mesh_animated=function( info )
		local mesh=NeoGraphics:getInstance():getMesh(info.mesh_path)
		local node=NeoGraphics:getInstance():AddOctreeSceneNode(mesh)
		node:setPosition(position)
		node:setRotation(rotation)
		node:setScale(scale)
		node:updateAbsolutePosition()
		return node
	end,
	billboard=function( info )
		
	end,
	light=function( info )
		local node=NeoGraphics:getInstance():AddLightSceneNode()
		node:setPosition(position)
		node:setRotation(rotation)
		node:setScale(scale)
		node:setRadius(obj.radius)
		node:getLightData().AmbientColor=irr.video.SColorf:new_local(info.ambient_color)
		node:getLightData().DiffuseColor=irr.video.SColorf:new_local(info.diffuse_color)
		node:getLightData().SpecularColor=irr.video.SColorf:new_local(obj.specular_color)
		node:getLightData().Falloff=info.falloff
		node:getLightData().Attenuation=info.attenuation
		node:enableCastShadow(obj.cast_shadow)
		node:getLightData().InnerCone=info.innerCone
		node:getLightData().OuterCone=info.outerCone
		node:setLightType(info.light_type)
		return node
	end,
	octree=function( info )
		local mesh=NeoGraphics:getInstance():getMesh(info.mesh_path)
		local node=NeoGraphics:getInstance():AddAnimatedMeshSceneNode(mesh)
		node:setPosition(position)
		node:setRotation(rotation)
		node:setScale(scale)
		node:updateAbsolutePosition()
		return node, info.animation
	end,
	event_point=function( info )
		
	end,
	spawn_point=function( info )
		
	end,
	cube=function( info )
		texture_path=info.textures[1] or DIR_RESOURCES.."model/default/default_cobe_texture.png"
		if texture_path=="" then
			texture_path = DIR_RESOURCES.."model/default/default_cobe_texture.png"
		end
		local texture=NeoGraphics:getInstance():LoadTexture(texture_path)
		local node=NeoGraphics:getInstance():AddCubeSceneNode(info.size)
		if texture then
			node:setMaterialTexture(0,texture)
		end
		node:setPosition(position)
		node:setRotation(rotation)
		node:setScale(scale)
		node:updateAbsolutePosition()
		return node
	end,
	sphere=function( info )
		texture_path=info.textures[1] or DIR_RESOURCES.."model/default/default_cobe_texture.png"
		if texture_path=="" then
			texture_path = DIR_RESOURCES.."model/default/default_cobe_texture.png"
		end
		local texture=NeoGraphics:getInstance():LoadTexture(texture_path)
		local node=NeoGraphics:getInstance():AddCubeSceneNode(info.radius)
		if texture then
			node:setMaterialTexture(0,texture)
		end
		node:setPosition(position)
		node:setRotation(rotation)
		node:setScale(scale)
		node:updateAbsolutePosition()
		return node
	end,
	--particle_sys=, -- not available yet
	-- camera=, -- not available yet
}

Scene.physicsLoader={
	convexHull=function( data )

	end,
	cube=function( data )
	end,
	sphere=function( data )
	end,
	cone=function( data )
	end,
	cylinder=function( data )
	end,
	static=function( data )
	--load bvh octree collision shape
	end,
	kinematic=function()
	end
}

function Scene.LoadEntity( data )
	local logic_data=nil
	if(data.logic_data ~= "")then
		data.logic_data = eval("return {"+data.logic_data+"}")
	end
	local entity_type = "common"
	if logic_data then
		entity_type = logic_data.entity_type
	end
	local entity=Scene.entityMap[entity_type].load(data,logic_data)
	Scene.entities[data.id]=entiry
end

function Scene.Clear()
	-- body
end

function Scene.Update()
	if(Scene.loading_controller) then
		if(Scene.loading_percent==100) then
			Scene.loading_controller=nil
		else
			Scene.loading_percent=coroutine.resume(Scene.loading_controller)
			--update ui progress bar
			return
		end
	end
end

function Scene.Init(map_path)
	NeoGameLogic:getInstance():AddLuaUpdateFunction("Scene.Update")
	Scene.loading_controller=coroutine.create(Scene.load)
	Scene.loading_percent=coroutine.resume(Scene.loading_controller,map_path)
end

function Scene.drop()
	Scene.Clear()
	NeoGameLogic:getInstance():removeLuaUpdateFunction("Scene.Update")
end