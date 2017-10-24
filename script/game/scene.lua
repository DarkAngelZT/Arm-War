require(DIR_SCRIPT.."game/explosionDispatcher")
Scene={}
Scene.entities={}
Scene.load=SceneLoaderGeneric
Scene.loading_percent=0
Scene.light_type_list={
	point=irr.video.ELT_POINT,
	spot=irr.video.ELT_SPOT,
	directional=irr.video.ELT_DIRECTIONAL
}
Scene.entityMap={
	common=CommonObjectEntity
}
Scene.spawn_points={
	--[team number]={{points},...}
}
Scene.tankLoader={
	standard=StandardTankEntity
}
Scene.cameras={
	
}
Scene.internal_observers={
	
}
Scene.EVENT={
	EXPLOSION=1, PLAYER_DESTROYED=2, PLAYER_REVIVE=3, PLAYER_HIT=4,
}

Scene.nodeLoader={
	mesh_static=function( info )
		local mesh=NeoGraphics:getInstance():getMesh(info.mesh_path)
		local node=NeoGraphics:getInstance():AddMeshSceneNode(mesh)
		node:setPosition(info.position)
		node:setRotation(info.rotation)
		node:setScale(info.scale)
		node:updateAbsolutePosition()
		return node,mesh
	end,
	mesh_animated=function( info )
		local mesh=NeoGraphics:getInstance():getMesh(info.mesh_path)
		local node=NeoGraphics:getInstance():AddAnimatedMeshSceneNode(mesh)
		node:setPosition(info.position)
		node:setRotation(info.rotation)
		node:setScale(info.scale)
		node:updateAbsolutePosition()
		return node,mesh
	end,
	billboard=function( info )
		local texture=NeoGraphics:getInstance():LoadTexture(info.textures[1])
		local size = irr.core.dimension2df:new_local(info.width,info.height)
		local node=NeoGraphics:getInstance():AddBillboardSceneNode()
		node:setSize(size)
		if texture then
			node:setMaterialTexture(0,texture)
		end
		node:setMaterialFlag(irr.video.EMF_LIGHTING, false)
		node:setMaterialType(irr.video.EMT_TRANSPARENT_ALPHA_CHANNEL)
		node:setPosition(position)
		node:updateAbsolutePosition()
		return node
	end,
	light=function( info )
		local node=NeoGraphics:getInstance():AddLightSceneNode()
		node:setPosition(info.position)
		node:setRotation(info.rotation)
		node:setScale(info.scale)
		node:setRadius(info.radius)
		node:getLightData().AmbientColor=irr.video.SColorf:new_local(info.ambient_color)
		node:getLightData().DiffuseColor=irr.video.SColorf:new_local(info.diffuse_color)
		node:getLightData().SpecularColor=irr.video.SColorf:new_local(info.specular_color)
		node:getLightData().Falloff=info.falloff
		node:getLightData().Attenuation=info.attenuation
		node:enableCastShadow(info.cast_shadow)
		node:getLightData().InnerCone=info.innerCone
		node:getLightData().OuterCone=info.outerCone
		node:setLightType(Scene.light_type_list[info.light_type])
		node:updateAbsolutePosition()
		return node
	end,
	octree=function( info )
		local mesh=NeoGraphics:getInstance():getMesh(info.mesh_path)
		local node=NeoGraphics:getInstance():AddOctreeSceneNode(mesh)
		node:setPosition(info.position)
		node:setRotation(info.rotation)
		node:setScale(info.scale)
		node:updateAbsolutePosition()
		return node, mesh
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
		node:setPosition(info.position)
		node:setRotation(info.rotation)
		node:setScale(info.scale)
		node:updateAbsolutePosition()
		return node
	end,
	sphere=function( info )
		texture_path=info.textures[1] or DIR_RESOURCES.."model/default/default_cobe_texture.png"
		if texture_path=="" then
			texture_path = DIR_RESOURCES.."model/default/default_cobe_texture.png"
		end
		local texture=NeoGraphics:getInstance():LoadTexture(texture_path)
		local node=NeoGraphics:getInstance():AddSphereSceneNode(info.radius)
		if texture then
			node:setMaterialTexture(0,texture)
		end
		node:setPosition(info.position)
		node:setRotation(info.rotation)
		node:setScale(info.scale)
		node:updateAbsolutePosition()
		return node
	end,
	--particle_sys=, -- not available yet
	-- camera=, -- not available yet
}

Scene.collisionShapeLoader={
	convexHull=function( data )
		if data.mesh then
			local physics=NeoPhysics:getInstance()
			local scale = data.scale or irr.core.vector3df:new_local(1,1,1)
			local shape_index=physics:CreateConvexHullShape(data.mesh,scale)
			return shape_index
		end
		return nil
	end,
	cube=function( data )
		local physics=NeoPhysics:getInstance()
		local scale = data.scale or irr.core.vector3df:new_local(1,1,1)
		local shape_index=physics:CreateBoxShape(
			irr.core.vector3df:new_local(data.size_x,data.size_y,data.size_z),scale)
		return shape_index
	end,
	sphere=function( data )
		local physics=NeoPhysics:getInstance()
		local scale = data.scale or irr.core.vector3df:new_local(1,1,1)
		local shape_index=physics:CreateSphereShape(data.radius,scale)
		return shape_index
	end,
	cone=function( data )
		local physics=NeoPhysics:getInstance()
		local align = data.align or "Y"
		local scale = data.scale or irr.core.vector3df:new_local(1,1,1)
		local shape_index=physics:CreateConeShape(data.radius,data.height,align,scale)
		return shape_index
	end,
	cylinder=function( data )
		local physics=NeoPhysics:getInstance()
		local align = data.align or "Y"
		local scale = data.scale or irr.core.vector3df:new_local(1,1,1)
		local shape_index=physics:CreateCylinderShape(
			irr.core.vector3df:new_local(data.size_x,data.size_y,data.size_z),align,scale)
		return shape_index
	end,
	capsule=function( data )
		local physics=NeoPhysics:getInstance()
		local align = data.align or "Y"
		local scale = data.scale or irr.core.vector3df:new_local(1,1,1)
		local shape_index=physics:CreateCapsuleShape(data.radius,data.height,align,scale)
		return shape_index
	end,
	static=function( data )
	--load bvh octree collision shape
		if data.mesh then
			local physics=NeoPhysics:getInstance()
			local scale = data.scale or irr.core.vector3df:new_local(1,1,1)
			local shape_index=physics:CreateBvhTriangleShape(data.mesh,scale)
			return shape_index
		end
		return nil
	end,
	kinematic=function()
	end
}

Scene.shell_pool={}
Scene.shell_pool.AP=ObjectPool.new()
Scene.shell_pool.AP.type=ShellEntity

Scene.shell_pool.HE=ObjectPool.new()
Scene.shell_pool.HE.type=ShellEntity

Scene.shell_pool.HEAT=ObjectPool.new()
Scene.shell_pool.HEAT.type=ShellEntity

Scene.shell_pool.HESH=ObjectPool.new()
Scene.shell_pool.HESH.type=ShellEntity

Scene.ClearShellPool=function( self )
	for _,v in pairs(self.shell_pool) do
		v:clear()
	end
end

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
	Scene.entities[data.id]=entity
end

function Scene:ShootShell( property, impulse, data )
	if property.shell_type and self.shell_pool[property.shell_type] then
		local shell = self.shell_pool[property.shell_type]:create(property)
		local rbody = shell.gameobject:getRigidBody()
		--reset velocity
		shell.gameobject:ResetPhysicsStates()
		for k,v in pairs(data) do
			shell[k]=v
		end
		shell:setActive(true)
		rbody:applyCentralImpulse(impulse)
	end
end

function Scene:Clear()
	Scene.spawn_points={}
	ShellFactory:clear()
	self:ClearShellPool()
	self.internal_observers={}
	if self.cameras.third_person then
		self.cameras.third_person:drop()
		self.cameras.third_person=nil
	end
	for k,v in pairs(self.entities) do
		v:Destroy()
		self.entities[k]=nil
	end
end

function Scene.LoadUpdate()
	if(Scene.loading_controller) then
		if(Scene.loading_percent==100) then
			Scene.loading_controller=nil
			NeoGameLogic:getInstance():removeLuaUpdateFunctionExeSafe("Scene.LoadUpdate")
			NeoGameLogic:getInstance():AddLuaUpdateFunction("Scene.Update")
			Logic:Init()
			g_ui_table.switchto("hud")
		else
			local state
			if Scene.loading_percent<0 then
				--初始化加载
				state,Scene.loading_percent=
					coroutine.resume(Scene.loading_controller,Scene.map_info,Scene.player_info)
			else 
				state,Scene.loading_percent=coroutine.resume(Scene.loading_controller)
			end
			if(not state)then
				local error_str = "Error while loading map: "..Scene.loading_percent
				print(error_str)
				LoadingScreen.setMessage(error_str)
				--载入出错处理
				return
			end
			--update ui progress bar
			LoadingScreen.setProgressPercent(Scene.loading_percent)
			LoadingScreen.setMessage("loading..."..Scene.loading_percent.."%")
			return
		end
	end
end

function Scene.Update()
	-- body
end

function Scene.Init(map_path,player_info)
	NeoGameLogic:getInstance():AddLuaUpdateFunction("Scene.LoadUpdate")
	Scene.loading_controller=coroutine.create(Scene.load)
	Scene.loading_percent=-1
	Scene.map_info= assert(dofile(map_path))
	Scene.player_info=player_info
	Scene.internal_observers={}
	Scene.screen_size=NeoGraphics:getInstance():getScreenSize()
	-- Scene.load(Scene.map_info)
end

function Scene.drop()
	Scene.Clear()
	NeoGameLogic:getInstance():removeLuaUpdateFunction("Scene.Update")
end

Scene.DisablePhysicsSimulation=function( )
	NeoPhysics:getInstance():setTimescale(0)
end

function Scene.EnablePhysicsSimulation( )
	NeoPhysics:getInstance():setTimescale(1)
end

function Scene.addSpawnPoint( data )
	if not Scene.spawn_points[data.team] then
		 Scene.spawn_points[data.team]={}
	end
	local point = {}
	point.position=irr.core.vector3df:new_local(data.position)
	point.rotation=irr.core.vector3df:new_local(data.rotation)
	table.insert(Scene.spawn_points[data.team],point)
end

function Scene:TriggerExplosion(type, event_id, 
	invoker, damage, position, range, impulse, attenuate )
	local event={
		event_id = event_id, damage=damage,
		type=type, position=position,
		range=range, impulse=impulse, attenuate = attenuate
	}
	self:notify(invoker,event)
end
--------------------------
-- internal lua event
--------------------------
function Scene:notify( invoker, event )
	for _,v in ipairs(self.internal_observers) do
		v:notify(invoker,event)
	end
end

function Scene:addInternalObserver( observer )
	table.insert(self.internal_observers,observer)
end