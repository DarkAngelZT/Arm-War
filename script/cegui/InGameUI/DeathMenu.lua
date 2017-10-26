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
	end
}

--------------------------
--event handler
--------------------------
root:getChild("btn_respawn"):subscribeEvent("Clicked","SingleModeDeathMenu.OnRespawn")
root:getChild("btn_exit"):subscribeEvent("Clicked","SingleModeDeathMenu.OnExit")