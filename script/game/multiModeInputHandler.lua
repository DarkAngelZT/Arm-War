MultiModeInputHandler={}
MultiModeInputHandler.move_key_status={
	forward=0,back=0,left=0,right=0
}
MultiModeInputHandler.key_press_status={
	tab=0,
}
MultiModeInputHandler.key_turret_lock=false

function MultiModeInputHandler:Init()
	self.key_turret_lock=false
	for k,_ in pairs(self.move_key_status) do
	 	self.move_key_status[k]=0
	 end 
end

function MultiModeInputHandler.OnKeyEvent(event)
	local key = tonumber(event:getData(0))
	local press = tonumber(event:getData(1))
	if MultiModeInputHandler:DetectMoveOperation(key,press) then
		return
	end
	-- lock turret
	if MultiModeInputHandler:DetectLockTurretOp(key,press) then
		return
	end
	--select ammo
	if MultiModeInputHandler:DetectChangeAmmoOp(key,press) then
		return
	end
	--show score board
	if MultiModeInputHandler:DetectShowScoreBoard(key,press) then
		return
	end
end

function MultiModeInputHandler.OnMouseEvent( event )
	if Logic:isGamePaused() or not Logic.in_game then
		return
	end
	local button = event:getData(0)
	local status = tonumber(event:getData(1))
	if button == "L" then
		if status == 1 then
			local cmd = ActorAttackCommand.new(Logic.actor_me)
			Logic:addCommand(cmd)
			if Synchronizer.player_me then
				Synchronizer:OnPlayerOperation( 
					ID_PLAYER_OP_ATTACK, { playerId = Synchronizer.player_me.id } )
			end
		end
	elseif button == "R" then
	end
end

function MultiModeInputHandler:DetectMoveOperation( key, press )
	local result=false
	if key==irr.KEY_KEY_W then
		if self.move_key_status.forward == press then
			return false
		end
		self.move_key_status.forward=press
		result=true
	elseif key==irr.KEY_KEY_S then
		if self.move_key_status.back == press then
			return false
		end
		self.move_key_status.back=press
		result=true
	elseif key==irr.KEY_KEY_A then
		if self.move_key_status.left == press then
			return false
		end
		self.move_key_status.left=press
		result=true
	elseif key==irr.KEY_KEY_D then
		if self.move_key_status.right == press then
			return false
		end
		self.move_key_status.right=press
		result=true
	else
		return false
	end

	Synchronizer.player_me:setKeyboardStatus(
		self.move_key_status.forward,self.move_key_status.back,
		self.move_key_status.left,self.move_key_status.right
		)
	local straight_status = 
		self.move_key_status.forward-self.move_key_status.back
	local l_r_status = 
		self.move_key_status.right-self.move_key_status.left
	if straight_status == 0 and l_r_status == 0 then
		local cmd = ActorStopCommad.new(Logic.actor_me)
		Logic:addCommand(cmd)
	else
		Logic:addCommand(ActorMoveCommad.new(Logic.actor_me,straight_status,l_r_status))	
	end
	return result
end

function MultiModeInputHandler:DetectLockTurretOp( key,press )
	if key==irr.KEY_SPACE and press==0 then
		self.key_turret_lock = not self.key_turret_lock
		Logic.actor_me:LockTurret(self.key_turret_lock)
		return true
	end
	return false
end

function MultiModeInputHandler:DetectChangeAmmoOp( key,press )
	if key==irr.KEY_KEY_1 and press==0 then
		Logic:addCommand(ActorSetAmmoCommand.new(Logic.actor_me,1))
		return true
	elseif key==irr.KEY_KEY_2 and press==0 then
		Logic:addCommand(ActorSetAmmoCommand.new(Logic.actor_me,2))
		return true
	elseif key==irr.KEY_KEY_3 and press==0 then
		Logic:addCommand(ActorSetAmmoCommand.new(Logic.actor_me,3))
		return true
	end
	return false
end

function MultiModeInputHandler:DetectShowScoreBoard( key,press )
	if key==irr.KEY_TAB then
		if self.key_press_status.tab == press then
			return false
		end
		self.key_press_status.tab = press
		local p = true
		if press == 0 then
			p=false
		end
		ScoreBoard:setVisible(p)
		return true
	end
	return false
end