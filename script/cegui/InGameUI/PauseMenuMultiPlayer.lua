local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("inGameHud/MultiGame.layout")

PauseMenuMultiPlayer={
	ui={
		root=root,
		main_menu=root:getChild("MenuRoot/MainMenu"),
		quit_menu=root:getChild("MenuRoot/QuitMenu")
	},
	OnQuit2Menu=function( args )
		PauseMenuMultiPlayer.ui.root:setVisible(false)
		g_ui_table.switchto("multi_menu")
		game:ShutdownMultiPlayerGame()
		Lobby:OnGameEnd()
	end,
	OnCancelQuitMenu=function(args)
		PauseMenuMultiPlayer.ui.main_menu:setVisible(true)
		PauseMenuMultiPlayer.ui.quit_menu:setVisible(false)
	end,
	OnShowQuitMenu=function ( args )
		PauseMenuMultiPlayer.ui.main_menu:setVisible(false)
		PauseMenuMultiPlayer.ui.quit_menu:setVisible(true)
	end,
	OnResume=function( args )
		PauseMenuMultiPlayer:Hide()
	end,
	Show=function( self )
		self.ui.root:setVisible(true)
		self.ui.main_menu:setVisible(true)
		self.ui.quit_menu:setVisible(false)
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():show()
		self.ui.root:activate()
	end,
	Hide=function( self )
		self.ui.root:setVisible(false)
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():hide()
		Scene.cameras.third_person:setEnabled(true)
		Logic.in_game=true
	end,
	setVisible=function( self, visible )
		if visible then
			self:Show()
		else 
			self:Hide()
		end
	end,
	isVisible=function( self )
		return self.ui.root:isVisible()
	end,
	OnPressEsc=function( self )
		if self.ui.quit_menu:isVisible() then
			self.OnCancelQuitMenu()
		else
			self:Hide()
		end
	end,
	OnKeyUp=function( args )
		local keycode = CEGUI.toKeyEventArgs(args)
		if keycode.scancode == CEGUI.Key.Escape then
			PauseMenuMultiPlayer:OnPressEsc()
		end
	end,
}

-------------------------
--event handler
-------------------------
root:getChild("MenuRoot/QuitMenu/CancelBtn"):subscribeEvent("Clicked","PauseMenuMultiPlayer.OnCancelQuitMenu")
root:getChild("MenuRoot/QuitMenu/Quit2MenuBtn"):subscribeEvent("Clicked","PauseMenuMultiPlayer.OnQuit2Menu")
root:getChild("MenuRoot/QuitMenu/Quit2SysBtn"):subscribeEvent("Clicked","Application_Quit")

root:getChild("MenuRoot/MainMenu/QuitBtn"):subscribeEvent("Clicked","PauseMenuMultiPlayer.OnShowQuitMenu")
root:getChild("MenuRoot/MainMenu/ReturnBtn"):subscribeEvent("Clicked","PauseMenuMultiPlayer.OnResume")

root:subscribeEvent("KeyUp","PauseMenuMultiPlayer.OnKeyUp")