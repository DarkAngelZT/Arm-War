SingleModeInputHandler={}
SingleModeInputHandler.move_key_status={
	forward=0,back=0,left=0,right=0
}
SingleModeInputHandler.key_turret_lock=false

function SingleModeInputHandler:Init()
	self.key_turret_lock=false
	for k,_ in pairs(self.move_key_status) do
	 	self.move_key_status[k]=0
	 end 
end

function SingleModeInputHandler.OnKeyEvent(event)
	local key = tonumber(event:getData(0))
	local press = tonumber(event:getData(1))
	if key==irr.KEY_KEY_W then
		if SingleModeInputHandler.move_key_status.forward == press then
			return
		end
		SingleModeInputHandler.move_key_status.forward=press
	elseif key==irr.KEY_KEY_S then
		if SingleModeInputHandler.move_key_status.back == press then
			return
		end
		SingleModeInputHandler.move_key_status.back=press
	elseif key==irr.KEY_KEY_A then
		if SingleModeInputHandler.move_key_status.left == press then
			return
		end
		SingleModeInputHandler.move_key_status.left=press
	elseif key==irr.KEY_KEY_D then
		if SingleModeInputHandler.move_key_status.right == press then
			return
		end
		SingleModeInputHandler.move_key_status.right=press
	end
	local straight_status = 
		SingleModeInputHandler.move_key_status.forward-SingleModeInputHandler.move_key_status.back
	local l_r_status = 
		SingleModeInputHandler.move_key_status.right-SingleModeInputHandler.move_key_status.left
	if straight_status == 0 and l_r_status == 0 then
		local cmd = ActorStopCommad.new(Logic.actor_me)
		Logic:addCommand(cmd)
	else
		Logic:addCommand(ActorMoveCommad.new(Logic.actor_me,straight_status,l_r_status))	
	end
	-- lock turret
	if key==irr.KEY_SPACE and press==0 then
		SingleModeInputHandler.key_turret_lock = not SingleModeInputHandler.key_turret_lock
		Logic.actor_me:LockTurret(SingleModeInputHandler.key_turret_lock)
	end
end

function SingleModeInputHandler.OnMouseEvent( event )
	local button = event:getData(0)
	local status = tonumber(event:getData(1))
	if button == "L" then
		if status == 1 then
			local cmd = ActorAttackCommand.new(Logic.actor_me)
			Logic:addCommand(cmd)
		end
	elseif button == "R" then
	end
end