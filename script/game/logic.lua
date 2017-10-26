require(DIR_SCRIPT.."game/actor")
require(DIR_SCRIPT.."game/command/command")
require(DIR_SCRIPT.."game/singleModeInputHandler")

Logic={}
Logic.actors={}
Logic.players={}
Logic.input_handler=nil
Logic.in_game_trigger=nil
Logic.actor_me=nil
Logic.game_mode=1
Logic.EVENT={
	KEY=0,
	MOUSE=1,
	EXPLOSION=2,
	SHELL_HIT=3
}
Logic.GAME_MODE={
	SINGLE=1,
	MULTIPLE=2
}
Logic.event_handlers={}
Logic.command_queue={}
Logic.timers={}
Logic.game_judge=nil

function Logic:setGameMode( mode )
	self.game_mode=mode
	if mode == Logic.GAME_MODE.SINGLE then
		-- set pause menu
		gamehud.pause_menu=PauseMenuSinglePlayer
		gamehud.death_menu=SingleModeDeathMenu
	else
		gamehud.pause_menu=PauseMenuMultiPlayer
	end
end

function Logic:ClearTriggers()
	for k,_ in pairs(self.event_handlers) do
		self.event_handlers[k]=nil
	end
end

function Logic:ClearTimers()
	for i,_ in ipairs(self.timers) do
		self.timers[i]=nil
	end
end

function Logic.TriggerEvent( args )
	local event=toNeoEvent(args)
	local event_id = event:getTriggerId()
	if Logic.event_handlers[event_id] then
		for _,v in pairs(Logic.event_handlers[event_id]) do
			v(event)
		end
	end
end

function Logic:RegisterEventHandler( eventId,key,func )
	if not self.event_handlers[eventId] then
		self.event_handlers[eventId]={}
	end
	self.event_handlers[eventId][key]=func
end

function Logic:RemoveEventHandler(eventId,key)
	if self.event_handlers[eventId] then
		self.event_handlers[eventId][key]=nil;
	end
end

function Logic:addActor( actor, isPlayer )
	if not actor.id then
		actor.id="a"..makeId()
	end
	self.actors[actor.id]=actor
	if isPlayer then
		self.players[actor.id]=actor
	end
end

function Logic:RemoveActor( actor, isPlayer )
	actor:OnDestroy()
	self.actors[actor.id]=nil
	if isPlayer then
		self.players[actor.id]=nil
	end
end

function Logic:RespawnActor( actor, position, rotation )
	--respawn
	actor:Respawn(position,rotation)
	--trigger respawn event
	Scene:notify(actor,{event_id=Scene.EVENT.PLAYER_REVIVE})
	--reset hud ui
	if actor == self.actor_me then
		gamehud:Refresh(actor)
	end
end

function Logic:RespawnPlayer_SingleMode( player )
	-- pick respawn position
	local pos,rot=self:PickPlayerRespawnPosition(player)
	--resawn
	if pos and rot then
		self:RespawnActor(player,pos,rot)
	end
end

function Logic:AddTimer( t )
	table.insert(self.timers,t)
end

function Logic:RemoveTimer( t )
	for i,v in ipairs(self.timers) do
		if v==t then
			self.timers[i]=nil
		end
	end
end

function Logic.Update()
	if Logic:isGamePaused() then
		return
	end
	local delta_time = NeoGameLogic:getInstance():getDeltaTime()
	--update timers
	for _,v in ipairs(Logic.timers) do
		v:Update(delta_time)
	end
	--execute commands
	for i,v in ipairs(Logic.command_queue) do
		if not v.executed then
			v:Execute()
		end
	end
	--clear command queue
	for i,_ in ipairs(Logic.command_queue) do
		Logic.command_queue[i]=nil
	end
	--update actor status
	for _,v in pairs(Logic.actors) do
		v:Update()
	end
	--determine if game meet end condition
	if Logic.game_judge then
		Logic.game_judge:Update()
	end
end

function Logic:Init()
	NeoGameLogic:getInstance():AddLuaUpdateFunction("Logic.Update")
	if self.input_handler then
		self.input_handler:Init()
		self.event_handlers[0]={self.input_handler.OnKeyEvent}
		self.event_handlers[1]={self.input_handler.OnMouseEvent}
	end
	local trigger = NeoTrigger:create()
	self.in_game_trigger=trigger
	trigger:setTriggerFunction("Logic.TriggerEvent")
	for _,v in pairs(self.EVENT) do
		trigger:addTriggerCondition(v)
	end
	NeoGameLogic:getInstance():RegisterTrigger(trigger)

	if self.actor_me then
		gamehud:Init(self.actor_me)
		gamehud:setCanonCursorEnabled(true)
	end
	--score board
	ScoreBoard:Init(self.players)
	ScoreBoard:setVisible(false)
	--set random seed
	math.randomseed( os.time() )
	self:ResumeGame()
end

function Logic:Clear()
	NeoGameLogic:getInstance():removeLuaUpdateFunction("Logic.Update")
	self:ClearTriggers()
	self:ClearTimers()
	if self.in_game_trigger then
		NeoGameLogic:getInstance():RemoveTrigger(self.in_game_trigger)
		self.in_game_trigger:drop()
		self.in_game_trigger=nil
	end
	self.actor_me=nil
	for k,v in pairs(self.actors) do
		self.actors[k]=nil
	end
	for k,_ in pairs(self.players) do
		self.players[k]=nil
	end
	--clear command queue
	for i,_ in ipairs(Logic.command_queue) do
		Logic.command_queue[i]=nil
	end
end

function Logic:addCommand( command )
	table.insert(self.command_queue,command)
end

function Logic:PauseGame()
	NeoGameLogic:getInstance():setGamePaused(true)
	Scene.DisablePhysicsSimulation()
	Scene.cameras.third_person:setEnabled(false)
end

function Logic:ResumeGame()
	NeoGameLogic:getInstance():setGamePaused(false)
	Scene.EnablePhysicsSimulation()
	Scene.cameras.third_person:setEnabled(true)
end

function Logic:isGamePaused( )
	return NeoGameLogic:getInstance():isGamePaused()
end

function Logic:PickPlayerRespawnPosition(actor)
	local isPlayer = false
	for _,v in pairs(self.players) do
		if v == actor then
			isPlayer=true
			break
		end
	end
	if not isPlayer then
		return
	end
	local team = actor.team
	local point = Scene.spawn_points[team][math.random(self.max_player)]
	return point.position,point.rotation
end