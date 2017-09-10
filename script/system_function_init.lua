--Loaders
--------------------------------------------
-- Sprite Loader
--------------------------------------------
function SpriteLoader( file_name )
	-- body
	--generate sprite name
	strs=split(file_name,'.')
	path=''
	for i=1,#strs-1,1 do
		path=path..strs[i]
	end
	path=path..'.sprite'
	parent_path='resources/sfx/sprites/'
	--get sprite config
	data=dofile(parent_path..path)
	NeoGraphics:getInstance():getSfxManager():AddSpriteTexture(file_name,data.row, data.column)
end
--------------------------------------------
-- Scene Loader
-- @map_info: a table contain all data about how to load and place object
--------------------------------------------
function SceneLoaderGeneric(map_info)
	-- initialize sfx
	NeoGraphics:getInstance():getSfxManager():Init()
	Scene.DisablePhysicsSimulation()
	--load object
	local settings=map_info.setting
	--skybox
	local skybox_entity=SkydomeEntity.Load(settings)
	Scene.entities[skybox_entity.id]=skybox_entity
	--map object
	local object_number = #map_info.objects
	local percent=0
	for i=1,object_number do
		--因为lua没有continue这种东西，所以之有用内嵌repeat+break实现
		repeat
			local data = map_info.objects[i]
			local logic_data = eval("{"..data.logic_data.."}")
			-- print("start load object: "..data.name)
			if data.scene_type=="spawn_point" then
				--记录出生点
				Scene.addSpawnPoint( data )
				break
			end
			if data.scene_type == "event_point" then
				--读取logic_data记录事件点
				break
			end

			local entity_type = "common"
			if logic_data then
				entity_type = logic_data.entity_type or "common"
			end
			if Scene.entityMap[entity_type] then
				local game_entity = Scene.entityMap[entity_type].Load(data)
				Scene.entities[game_entity.id]=game_entity
			end
			--return progress
			percent=i/object_number*50
			print(percent)
			coroutine.yield(percent)
			-- print("object: "data.name.." load finish")
		until true
		
	end
	--tank object
	--camera
	Scene.EnablePhysicsSimulation()
	--test
	NeoGraphics:getInstance():AddCameraSceneNodeFPS()
	coroutine.yield(100)
end