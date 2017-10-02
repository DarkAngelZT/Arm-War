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
	-- body
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
function SkydomeEntity:Destory()
	-- body
	NeoGraphics:getInstance():RemoveSceneNode(self.node)
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
		if mesh then
			attribute.mesh=mesh
		end
		local shape_index = 
			Scene.collisionShapeLoader[data.physics_data.physics_type](attribute)
		local mass = data.physics_data.mass or 0
		self.gameobject:AddRigidBody(shape_index,mass)
	end
	self.gameobject:setLuaIdentifier(data.id)
	self.id=data.id
	return self
end

function CommonObjectEntity:Destory()
	if self.gameobject then
		NeoScene:getInstance():DestoryGameObject(self.gameobject,true)
	end
end

-----------------
--event handler
-----------------
CommonObjectEntity.event_handlers={
}

function CommonObjectEntity.RegisterSingleModeEventHandler( )
end

require(DIR_SCRIPT.."game/tankEntity")
require(DIR_SCRIPT.."game/shellEntity")