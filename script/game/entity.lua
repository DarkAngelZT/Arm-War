Entity = class()
Entity.id=-1
Entity.name="entity"
Entity.active=true
Entity.logic_data={}
function Entity.RegisterSingleModeEventHandler( )
end
function Entity.RegisterMultiModeEventHandler( )
end
--[[*****************************************
 skybox
*******************************************]]
SkydomeEntity = class(Entity)
SkydomeEntity.sceneNode=nil
SkydomeEntity.texture=nil
function SkydomeEntity.Load(data,logic_data)
	local self = SkydomeEntity.new()
	local skyboxTexture=NeoGraphics:getInstance():LoadTexture(data["skydome texture"])
	local node=NeoGraphics:getInstance():AddSkyDomeSceneNode(skyboxTexture,16,8,1.0)
	self.sceneNode=node
	node:setMaterialTexture(0,skyboxTexture)
	texture=skyboxTexture
	self.id="sky"
	local colour = data["ambient colour"]
	NeoGraphics:getInstance():SetAmbientLight(colour)
	return self
end
function SkydomeEntity:Destroy()
	NeoGraphics:getInstance():RemoveSceneNode(self.sceneNode)
	NeoGraphics:getInstance():UnloadTexture(self.texture)
end
--[[*****************************************
 常规物件
*******************************************]]
CommonObjectEntity = class(Entity)
CommonObjectEntity.gameobject=nil

function CommonObjectEntity.Load(data,logic_data)
	local self=CommonObjectEntity.new()
	self.gameobject = NeoScene:getInstance():CreateGameObject()
	local node,mesh = Scene.nodeLoader[data.scene_type](data)
	self.gameobject:setSceneNode(node)
	if data.physics_data and data.physics_data.physics_type~="none" then
		--load physics object
		local attribute = data.physics_data
		attribute.scale = tolua.cast(node:getScale(),"irr::core::vector3d<float>")
		if mesh then
			attribute.mesh=mesh
		end
		local shape_index = 
			Scene.collisionShapeLoader[data.physics_data.physics_type](attribute)
		local mass = data.physics_data.mass or 0
		if shape_index then
			local rbody = self.gameobject:AddRigidBody(shape_index,mass)
			rbody:setFriction(0.8)
		else
			print("failed to create collision: "..data.name.."["..data.id.."]")
		end
	end
	self.gameobject:setLuaIdentifier(data.id)
	self.id=data.id
	return self
end

function CommonObjectEntity:Destroy()
	if self.gameobject then
		NeoScene:getInstance():DestroyGameObject(self.gameobject,true)
	end
end

-----------------
--event handler
-----------------
CommonObjectEntity.event_handlers={
}

function CommonObjectEntity.RegisterSingleModeEventHandler( )
	-- Logic:RegisterEventHandler(
	-- 	Logic.EVENT.EXPLOSION,"CommonObjectEntity",CommonObjectEntity.OnExplosion)
end

-- function CommonObjectEntity.OnExplosion( event )
-- 	local actor_id = event:getData(0)
-- 	local range = tonumber(event:getData(1))
-- 	local shell_id = event:getData(2)
-- 	local damage = tonumber(event:getData(3))
-- 	local attenuate = event:getData(4)

-- 	print(actor_id,range,shell_id,damage,attenuate)

-- end

require(DIR_SCRIPT.."game/tankEntity")
require(DIR_SCRIPT.."game/shellEntity")
require(DIR_SCRIPT.."game/PrismTankEntity")

TankEntityLoader={
	standard=StandardTankEntity,
	prism=PrismTankEntity
}