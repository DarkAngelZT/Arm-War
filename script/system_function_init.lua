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
			local sub_percent = i/object_number
			percent=sub_percent*50
			coroutine.yield(percent,string.format("Loading map objects...%.2f%%",sub_percent*100))
			-- print("object: "data.name.." load finish")
		until true
		
	end
	--shell object
	coroutine.yield(percent,"Loading bullets...")
	ShellFactory:init({"AP","HE","HESH","HEAT"})
	coroutine.yield(60,"Loading bullets...100%")
	--tank object
	local tank_model_data = {}
	local spawn_points_index = {}
	local loaded_tank_type = {}
	if player_info then
		local player_number = 0
		for k,_ in pairs(player_info) do
			player_number=player_number+1
		end
		--load tank according to player data
		local team = 1
		local i = 1
		for _,v in pairs(player_info) do
			local tank_type = v.tank_type
			if not tank_model_data[tank_type] then
				local file_path = DIR_TANKS..tank_type..".lua"
				local data_path = DIR_DATA.."game/tank/"..tank_type..".cfg"
				local attributes = assert(dofile(file_path))
				if not NeoGame.io.isFileExist(data_path) then
					data_path=DIR_DATA.."game/tank/default.cfg"
				end
				local attr = eval("{"..readAllText(data_path).."}")
				for k,v in pairs(attr) do
					attributes.property[k]=v
				end
				tank_model_data[tank_type]=attributes
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
			local ammo_config = current_tank_data.property.default_shell_config
			if ammo_config then
				current_actor.ammo_config=ammo_config
			end
			current_actor.team=v.team
			current_actor.tank_type=tank_type
			current_actor:setEntity(tank)
			--add player label
			local label_info = {
				font="OpenSans-Bold-12",text=v.name,position=irr.core.vector3df:new_local(0,5,0)}
			local label = Scene.nodeLoader.text(label_info)
			if label then
				label:setParent(tank.components.body.object:getTankBodyNode())
				label:updateAbsolutePosition()
				if v.team ~=team or i==1 then
					label:setVisible(false)
				else
					label:setTextColor(irr.video.SColor:new_local(100,0,255,0))
				end
			end
			if i==1 then
				Logic.actor_me=current_actor
				team = current_actor.team
			end
			Logic:addActor(current_actor,true)
				
			local sub_percent = i/player_number
			percent=60+sub_percent*30
			coroutine.yield(percent,string.format("Loading players...%.2f%%",sub_percent*100))
			i=i+1
		end
	end
	--explosion
	coroutine.yield(percent,"Adding explosions...")
	Scene:addInternalObserver(SingleModeExplosionDispatcher)
	coroutine.yield(95,"Intializing game...")
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
	coroutine.yield(100,"Loading complete")
end

--------------------------------------------
-- Scene Loader
-- @map_info: a table contain all data about how to load and place object
--------------------------------------------
function MultiPlayerSceneLoader(map_info,player_info)
	local network = NeoGame.Network:getInstance()
	network:setReadyEvent(EVENT_PLAYER_LOADED,false)
	Synchronizer:setEnabled( false )
	Synchronizer.game_ready=false
	local player_number = 0
	for k,_ in pairs(player_info) do
		player_number=player_number+1
	end	
	Synchronizer.loaded_player_count=0
	Synchronizer.max_player_count=player_number
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
				IDGenerator:Register(game_entity.id)
				Scene.entities[tostring(game_entity.id)]=game_entity
				--event handler
				if not loaded_entity_type[entity_type] then
					loaded_entity_type[entity_type]=true
					Scene.entityMap[entity_type].RegisterMultiModeEventHandler()
				end
				-- add synchroinze object
				if data.physics_data and 
					data.physics_data.physics_type ~= "static" and 
					data.physics_data.physics_type ~= "none" then
					local sync_agent,networked_object = 
					Synchronizer:CreateSynchronizedObject( SynchronizedObject, tostring(game_entity.id), game_entity.id,true )
					sync_agent:PostConstruct()
					network:StartSynchronizeObject(networked_object)
				end
			end
			--return progress
			local sub_percent = i/object_number
			percent=sub_percent*50
			coroutine.yield(percent,string.format("Loading map objects...%.2f%%",sub_percent*100))
			-- print("object: "data.name.." load finish")
		until true
		
	end
	--shell object
	coroutine.yield(percent,"Loading bullets...")
	ShellFactory:init({"AP","HE","HESH","HEAT"})
	coroutine.yield(60,"Loading players...")
	--tank object
	local tank_model_data = {}
	local spawn_points_index = {}
	local loaded_tank_type = {}
	if player_info then
		--load tank according to player data
		local team = 1
		local i = 1
		for _,v in pairs(player_info) do
			local tank_type = v.type
			local id = "p"..v.id
			if not tank_model_data[tank_type] then
				local file_path = DIR_TANKS..tank_type..".lua"
				local data_path = DIR_DATA.."game/tank/"..tank_type..".cfg"
				local attributes = assert(dofile(file_path))
				if not NeoGame.io.isFileExist(data_path) then
					data_path=DIR_DATA.."game/tank/default.cfg"
				end
				local attr = eval("{"..readAllText(data_path).."}")
				for k,v in pairs(attr) do
					attributes.property[k]=v
				end
				tank_model_data[tank_type]=attributes
			end
			local current_tank_data = tank_model_data[tank_type]
			if not spawn_points_index[v.team] then
				spawn_points_index[v.team]=1
			end
			local team_index = spawn_points_index[v.team]
			local point=Scene.spawn_points[v.team][team_index]
			spawn_points_index[v.team]=team_index+1
			local tank_data = {
				id=id,tank_name=current_tank_data.tank_name,
				position=point.position,rotation=point.rotation,
				data=current_tank_data
			}
			local tank=Scene.tankLoader[current_tank_data.property.tank_type].Load(tank_data)
			Scene.entities[tank.id]=tank
			local tank_enitity_type = current_tank_data.property.tank_type
			if not loaded_tank_type[tank_enitity_type] then
				loaded_tank_type[tank_enitity_type]=true
				Scene.tankLoader[tank_enitity_type].RegisterMultiModeEventHandler()
			end
			
			local current_actor = Actor.new(id)
			current_actor:Init()
			current_actor.name=v.name
			local ammo_config = current_tank_data.property.default_shell_config
			if ammo_config then
				current_actor.ammo_config=ammo_config
			end
			current_actor.team=v.team
			current_actor.tank_type=tank_type
			current_actor:setEntity(tank)
			--add player label
			local label_info = {
				font="OpenSans-Bold-12",text=v.name,position=irr.core.vector3df:new_local(0,5,0)}
			local label = Scene.nodeLoader.text(label_info)
			if label then
				label:setParent(tank.components.body.object:getTankBodyNode())
				label:updateAbsolutePosition()
				if v.team ~=team or v.is_me then
					label:setVisible(false)
				else
					label:setTextColor(irr.video.SColor:new_local(100,0,255,0))
				end
			end
			
			if v.is_me then
				Logic.actor_me=current_actor
				team = current_actor.team
				local player,networked_object = 
					Synchronizer:CreateSynchronizedObject(SynchronizedPlayer,id)
				Synchronizer.player_me=player
				network:StartSynchronizeObject(networked_object)
			end
			Logic:addActor(current_actor,true)
			local sub_percent = i/player_number
			percent=60+sub_percent*30
			coroutine.yield(percent,string.format("Loading players...%.2f%%",sub_percent*100))
			i=i+1
		end
	end
	--explosion
	coroutine.yield(percent,"Adding explosion...")
	Scene:addInternalObserver(MultiModeExplosionDispatcher)

	Synchronizer.loaded_player_count=Synchronizer.loaded_player_count+1
	network:setReadyEvent(EVENT_PLAYER_LOADED,true)

	coroutine.yield(95,string.format("Waiting for other players...%d/%d",
		Synchronizer.loaded_player_count,Synchronizer.max_player_count))
	while not Synchronizer.game_ready do
		coroutine.yield(95,string.format("Waiting for other players...%d/%d",
		Synchronizer.loaded_player_count,Synchronizer.max_player_count))
	end
	coroutine.yield(97,"Synchronizing..")
	for _,v in pairs(Synchronizer.players) do
		v:PostConstruct()
	end
	coroutine.yield(99,"Initializing game...")
	--camera
	local camera = NeoGraphics:getInstance():AddCamera3rdPerson(
		Logic.actor_me.entity.components.body.object:getTankBodyNode())
	Scene.cameras.third_person=camera
	-- set input handler
	Logic.input_handler=MultiModeInputHandler
	-- set game mode
	Logic:setGameMode(Logic.GAME_MODE.MULTIPLE)
	Synchronizer:setEnabled( true )
	coroutine.yield(100,"Loading complete")
end