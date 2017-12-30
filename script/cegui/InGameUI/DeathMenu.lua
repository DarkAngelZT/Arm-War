

local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("inGameHud/DeathMenu.layout")
g_ui_table.menu_dead_single=root

SingleModeDeathMenu={
	ui={
		root=root,
		btn_respawn=root:getChild("btn_respawn"),
		btn_exit=root:getChild("btn_exit")
	},
	OnExit=function( args )
		g_ui_table.switchto("single_menu")
		game:Clear()
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():show()
	end,
	OnRespawn=function( args )
		Logic:RespawnPlayer_SingleMode(Logic.actor_me)
		gamehud:Refresh(Logic.actor_me)
		g_ui_table.switchto("hud")
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():hide()
		Scene.cameras.third_person:setTarget(
			Logic.actor_me.entity.components.body.object:getTankBodyNode())
		Scene.cameras.third_person:setEnabled(true)
	end,
	notify=function( self, invoker, event )
		if invoker ~= Logic.actor_me then
			return
		end
		if event.event_id == Scene.EVENT.PLAYER_DESTROYED then
			g_ui_table.switchto("menu_dead_single")
		elseif event.event_id == Scene.EVENT.PLAYER_REVIVE then

		end
	end,
	Show=function( self )
		g_ui_table.switchto("menu_dead_single")
		Scene.cameras.third_person:setEnabled(false)
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():show()
	end,
	Init=function( self )
		
	end
}

--------------------------
--event handler
--------------------------
root:getChild("btn_respawn"):subscribeEvent("Clicked","SingleModeDeathMenu.OnRespawn")
root:getChild("btn_exit"):subscribeEvent("Clicked","SingleModeDeathMenu.OnExit")

-----------------------------------------------
-- multiplayer menu
-----------------------------------------------
local multi_root = winMgr:loadLayoutFromFile("inGameHud/DeathMenu_multiplayer.layout")
g_ui_table.menu_dead_multi=multi_root
MultiModeDeathMenu={
	ui={
		root=multi_root,
		btn_respawn=multi_root:getChild("btn_respawn"),
		btn_exit=multi_root:getChild("btn_exit")
	},
	OnExit=function( args )
		g_ui_table.switchto("multi_menu")
		game:ShutdownMultiPlayerGame()
		Lobby:OnGameEnd()
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():show()
	end,
	OnRespawn=function( args )
		Logic:RespawnPlayer_MultiMode(Logic.actor_me)
		gamehud:Refresh(Logic.actor_me)
		g_ui_table.switchto("hud")
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():hide()
		Scene.cameras.third_person:setTarget(
			Logic.actor_me.entity.components.body.object:getTankBodyNode())
		Scene.cameras.third_person:setEnabled(true)
	end,
	notify=function( self, invoker, event )
		if invoker ~= Logic.actor_me then
			return
		end
		if event.event_id == Scene.EVENT.PLAYER_DESTROYED then
			g_ui_table.switchto("menu_dead_multi")
		elseif event.event_id == Scene.EVENT.PLAYER_REVIVE then

		end
	end,
	Show=function( self )
		g_ui_table.switchto("menu_dead_multi")
		Scene.cameras.third_person:setEnabled(false)
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():show()
		self.ui.btn_respawn:disable()
		self.ui.btn_respawn:setText("Respawn (5)")
		self.respawn_timer:Start()
	end,
	Init=function( self )
		local timer = Timer.new()
		timer:AddTickFunction(self.OnRespawnTimerTick,self)
		timer:AddTriggerFunction(self.OnRespawnTimerFinish,self)
		self.respawn_timer = timer
		timer.duration=5
		Logic:AddTimer(self.respawn_timer)
	end
}

function MultiModeDeathMenu:OnRespawnTimerTick( delta_time )
	local second = math.ceil(self.respawn_timer.time_remain)
	if second >0 then
		self.ui.btn_respawn:setText(string.format("Respawn (%d)",second))
	end
end

function MultiModeDeathMenu:OnRespawnTimerFinish()
	self.ui.btn_respawn:setText("Respawn")
	self.ui.btn_respawn:enable()
end

--------------------------
--event handler
--------------------------
multi_root:getChild("btn_respawn"):subscribeEvent("Clicked","MultiModeDeathMenu.OnRespawn")
multi_root:getChild("btn_exit"):subscribeEvent("Clicked","MultiModeDeathMenu.OnExit")