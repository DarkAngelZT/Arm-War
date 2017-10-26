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
function SceneLoaderGeneric(map_info,player_info)
	-- initialize sfx
	NeoGraphics:getInstance():getSfxManager():Init()
	Scene.DisablePhysicsSimulation()
	--load object
	local settings=map_info.setting
	--load map info
	local map_config = eval("{"..settings.logic_data.."}")
	Logic.max_player=map_config.max_player
	Logic.team_count = map_config.max_team_allowed
	--skybox
	local skybox_entity=SkydomeEntity.Load(settings)
	Scene.entities[skybox_entity.id]=skybox_entity
	--map object
	local object_number = #map_info.objects
	local percent=0
	local loaded_entity_type={}
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
				Scene.entities[tostring(game_entity.id)]=game_entity
				--event handler
				if not loaded_entity_type[entity_type] then
					loaded_entity_type[entity_type]=true
					Scene.entityMap[entity_type].RegisterSingleModeEventHandler()
				end
			end
			--return progress
			percent=i/object_number*50
			coroutine.yield(percent)
			-- print("object: "data.name.." load finish")
		until true
		
	end
	--shell object
	ShellFactory:init({"AP","HE","HESH","HEAT"})
	coroutine.yield(60)
	--tank object
	local tank_model_data = {}
	local spawn_points_index = {}
	local loaded_tank_type = {}
	if player_info then
		local player_number = #player_info
		--load tank according to player data
		for i,v in ipairs(player_info) do
			local tank_type = v.tank_type
			if not tank_model_data[tank_type] then
				local file_path = DIR_TANKS..tank_type..".lua"
				tank_model_data[tank_type]=assert(dofile(file_path))
			end
			local current_tank_data = tank_model_data[v.tank_type]
			if not spawn_points_index[v.team] then
				spawn_points_index[v.team]=1
			end
			local team_index = spawn_points_index[v.team]
			local point=Scene.spawn_points[v.team][team_index]
			spawn_points_index[v.team]=team_index+1
			local tank_data = {
				id=v.id,tank_name=current_tank_data.tank_name,
				position=point.position,rotation=point.rotation,
				data=current_tank_data
			}
			local tank=Scene.tankLoader[current_tank_data.property.tank_type].Load(tank_data)
			Scene.entities[tank.id]=tank
			local tank_enitity_type = current_tank_data.property.tank_type
			if not loaded_tank_type[tank_enitity_type] then
				loaded_tank_type[tank_enitity_type]=true
				Scene.tankLoader[tank_enitity_type].RegisterSingleModeEventHandler()
			end
			
			local current_actor = Actor.new(v.id)
			current_actor:Init()
			current_actor.name=v.name
			current_actor:setEntity(tank)
			current_actor.team=v.team
			current_actor.tank_type=tank_type
			if i==1 then
				Logic.actor_me=current_actor
			end
			Logic:addActor(current_actor,true)
			percent=60+i/player_number*30
			coroutine.yield(percent)
		end
	end
	--explosion
	Scene:addInternalObserver(SingleModeExplosionDispatcher)
	coroutine.yield(95)
	--camera
	local camera = NeoGraphics:getInstance():AddCamera3rdPerson(
		Logic.actor_me.entity.components.body.object:getTankBodyNode())
	Scene.cameras.third_person=camera
	-- set input handler
	Logic.input_handler=SingleModeInputHandler
	-- set game mode
	Logic:setGameMode(Logic.GAME_MODE.SINGLE)
	--resume physics
	Scene.EnablePhysicsSimulation()
	coroutine.yield(100)
end