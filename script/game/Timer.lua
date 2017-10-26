Timer=class()
function Timer:onCreate( duration )
	self.duration=duration or 0
	self.running=false
	self.time_remain=0
	self.once=true
	self.trigger_functions={}
	self.tick_functions={}
end

function Timer:Update( delta_time )
	if self.running then
		self.time_remain=self.time_remain-delta_time
		if self.time_remain<=0 then
			for _,v in ipairs(self.trigger_functions) do
				v.trigger(v.object,v.param)
			end
			if self.once then
				self.running=false
			else
				self:Reset()
			end
		end
		for _,v in ipairs(self.tick_functions) do
			v.trigger(v.object,delta_time)
		end
	end
end
--function to call when time out
function Timer:AddTriggerFunction( f, obj, param )
	table.insert(self.trigger_functions,{trigger=f,object=obj,param=param})
end
--function to call in every update
function Timer:AddTickFunction( f, obj )
	table.insert(self.tick_functions,{trigger=f,object=obj})
end
--remove trigger function
function Timer:RemoveTriggerFunction( f )
	for i,v in ipairs(self.trigger_functions) do
		if v.trigger == f then
			self.trigger_functions[i]=nil
			break
		end
	end
end
--remove tick update function
function Timer:RemoveTickFunction( f )
	for i,v in ipairs(self.tick_functions) do
		if v.trigger == f then
			self.tick_functions[i]=nil
			break
		end
	end
end
--clear trigger function
function Timer:ClearTriggerFunction( )
	for i,_ in ipairs(self.trigger_functions) do
		self.trigger_functions[i]=nil
	end
end
--clear tick update function
function Timer:ClearTickFunction( )
	for i,_ in ipairs(self.tick_functions) do
		self.tick_functions[i]=nil
	end
end
function Timer:Reset( )
	self.time_remain=self.duration
end

function Timer:Pause( )
	self.running=false
end

function Timer:Resume( )
	self.running=true
end

function Timer:Start( )
	self:Reset()
	self.running=true
end

function Timer:Stop()
	self:Reset()
	self:Pause()
end