local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("inGameHud/SingleGaming_menu.layout")

PauseMenuSinglePlayer={
	ui={
		root=root,
		main_menu=root:getChild("menuWnd"),
		quit_menu=root:getChild("QuitMenu")
	},
	OnQuit2Menu=function( args )
		PauseMenuSinglePlayer.ui.root:setVisible(false)
		g_ui_table.switchto("single_menu")
		game:Clear()
	end,
	OnCancelQuitMenu=function(args)
		PauseMenuSinglePlayer.ui.main_menu:setVisible(true)
		PauseMenuSinglePlayer.ui.quit_menu:setVisible(false)
	end,
	OnShowQuitMenu=function ( args )
		PauseMenuSinglePlayer.ui.main_menu:setVisible(false)
		PauseMenuSinglePlayer.ui.quit_menu:setVisible(true)
	end,
	OnResume=function( args )
		PauseMenuSinglePlayer:Hide()
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
		Logic:ResumeGame()
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
			PauseMenuSinglePlayer:OnPressEsc()
		end
	end,
}

-------------------------
--event handler
-------------------------
root:getChild("QuitMenu/btn_Cancel"):subscribeEvent("Clicked","PauseMenuSinglePlayer.OnCancelQuitMenu")
root:getChild("QuitMenu/btn_Quit2Menu"):subscribeEvent("Clicked","PauseMenuSinglePlayer.OnQuit2Menu")
root:getChild("QuitMenu/btn_Quit2System"):subscribeEvent("Clicked","Application_Quit")

root:getChild("menuWnd/btn_Quit"):subscribeEvent("Clicked","PauseMenuSinglePlayer.OnShowQuitMenu")
root:getChild("menuWnd/btn_resume"):subscribeEvent("Clicked","PauseMenuSinglePlayer.OnResume")

root:subscribeEvent("KeyUp","PauseMenuSinglePlayer.OnKeyUp")