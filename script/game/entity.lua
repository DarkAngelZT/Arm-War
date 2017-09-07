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
function SkydomeEntity:Load(data,logic_data)
	-- body
	local skyboxTexture=NeoGraphics:getInstance():LoadTexture(data["skydome texture"])
	local node=NeoGraphics:getInstance():AddSkyDomeSceneNode(skyboxTexture,16,8,1.0)
	self.sceneNode=node
	map_editor.skybox:setMaterialTexture(0,skyboxTexture)
	texture=skyboxTexture
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

function CommonObjectEntity:Load(data,logic_data)
	self.gameobject = NeoScene:getInstance():CreateGameObject()
	if data.scene_type == "mesh" then
		local mesh=NeoGraphics:getInstance():getMesh(data.mesh_path)
		local node=NeoGraphics:getInstance():AddMeshSceneNode(mesh)
	end
	
end

dofile(DIR_SCRIPT.."game/tankEntity.lua")