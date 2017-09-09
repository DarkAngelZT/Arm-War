Entity = class()
Entity.id=-1
Entity.name="entity"
Entity.active=true
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
	map_editor.skybox:setMaterialTexture(0,skyboxTexture)
	texture=skyboxTexture
	self.id="sky"
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
	local node = Scene.nodeLoader[data.scene_type](data)
	self.gameobject:setSceneNode(node)
	self.gameobject:setLuaIdentifier(data.id)
	self.id=data.id
	return self
end

dofile(DIR_SCRIPT.."game/tankEntity.lua")