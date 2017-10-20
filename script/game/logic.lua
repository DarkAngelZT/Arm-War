require(DIR_SCRIPT.."game/actor")
require(DIR_SCRIPT.."game/command/command")
require(DIR_SCRIPT.."game/singleModeInputHandler")

Logic={}
Logic.actors={}
Logic.input_handler=nil
Logic.in_game_trigger=nil
Logic.actor_me=nil
Logic.EVENT={
	KEY=0,
	MOUSE=1,
	EXPLOSION=2,
	SHELL_HIT=3
}
Logic.event_handlers=
{

}
Logic.command_queue=
{
	
}

function Logic:ClearTriggers()
	for k,_ in pairs(self.event_handlers) do
		self.event_handlers[k]=nil
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

function Logic:addActor( actor )
	if not actor.id then
		actor.id="a"..makeId()
	end
	self.actors[actor.id]=actor
end

function Logic.Update()
	for i,v in ipairs(Logic.command_queue) do
		if not v.executed then
			v:Execute()
		end
		
	end
	for _,v in pairs(Logic.actors) do
		v:Update()
	end

	--clear command queue
	for i,_ in ipairs(Logic.command_queue) do
		Logic.command_queue[i]=nil
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
	--set random seed
	math.randomseed( os.time() )
end

function Logic:Clear()
	NeoGameLogic:getInstance():removeLuaUpdateFunction("Logic.Update")
	self:ClearTriggers()
	if self.in_game_trigger then
		NeoGameLogic:getInstance():RemoveTrigger(self.in_game_trigger)
		self.in_game_trigger:drop()
		self.in_game_trigger=nil
	end
end

function Logic:addCommand( command )
	table.insert(self.command_queue,command)
end