require(DIR_SCRIPT_CEGUI.."InGameUI/ScoreBoard")
require(DIR_SCRIPT_CEGUI.."InGameUI/PauseMenuSinglePlayer")
require(DIR_SCRIPT_CEGUI.."InGameUI/PauseMenuMultiPlayer")

local winMgr = CEGUI.WindowManager:getSingleton()
CEGUI.ImageManager:getSingleton():loadImageset("gameHUD.imageset");
local root = winMgr:loadLayoutFromFile("inGameHud/HUD.layout")
g_ui_table.hud=root

root:addChild(ScoreBoard.ui.root)

----------------------
--event handler
----------------------
root:subscribeEvent("KeyUp","gamehud.OnKeyUp")
----------------------
gamehud={}
gamehud.ui={
	root=root,
	ammo_slot={
		root=root:getChild("AmmoRoot"),
		root:getChild("AmmoRoot/slot1"),
		root:getChild("AmmoRoot/slot2"),
		root:getChild("AmmoRoot/slot3")
	},
	cursor_mouse=root:getChild("Cursor_mouse"),
	cursor_canon=root:getChild("Cursor_canon"),
	current_ammo=root:getChild("AmmoRoot/AmmoText"),
	reload_progress_bar=CEGUI.toProgressBar(root:getChild("AmmoRoot/ReloadingBar")),
	reload_status=root:getChild("AmmoRoot/ReloadingBar/status"),
	active_ammo_frame=root:getChild("AmmoRoot/activeSlotFrame"),
	top_view={
		base=root:getChild("TopViewRoot/Base"),
		top=root:getChild("TopViewRoot/Top")
	},
}
gamehud.ammo_sprite_name={
	AP="gameHUD/AP_icon",
	HE="gameHUD/HE_icon",
	HESH="gameHUD/HESH_icon",
	HEAT="gameHUD/HEAT_icon"
}

function gamehud:Init( actor )
	if actor then
		self.ui.ammo_slot.root:setVisible(true)
		--set shell icon
		for i=1,3 do
			local icon_type = self.ammo_sprite_name[actor.ammo[i].name]
			self.ui.ammo_slot[i]:getChild("icon"):setProperty("Image",icon_type)
			self.ui.ammo_slot[i]:getChild("amount"):setText(tostring(actor.ammo[i].amount))
		end
	else
		self.ui.ammo_slot.root:setVisible(false)
	end
	local tank_type=actor.entity.property.tank_name
	CEGUI.ImageManager:getSingleton():loadImageset(tank_type..".imageset","tankTopview")
	self.ui.top_view.base:setProperty("Image","TankTopView/base")
	self.ui.top_view.top:setProperty("Image","TankTopView/top")
	-- hide cursor
	CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():hide()
	--evetn observer
	Scene:addInternalObserver(self)
	--add pause menu
	if self.ui.pause_menu_root then
		self.ui.root:removeChild(self.ui.pause_menu_root)
	end
	if self.pause_menu then
		self.ui.root:addChild(self.pause_menu.ui.root)
		self.ui.pause_menu_root=self.pause_menu.ui.root
		self.pause_menu:Hide()
	end
end

function gamehud:setCanonCursorPosition( pos_x, pos_y )
	local cursor = self.ui.cursor_canon
	--cusor size:61*34, center of coordinte is on upper left
	local pos_str_x = "{"..pos_x.X..","..(pos_x.Y-30.5).."}"
	local pos_str_y = "{"..pos_y.X..","..(pos_y.Y-17).."}"
	cursor:setXPosition(CEGUI.PropertyHelper:stringToUDim(pos_str_x))
	cursor:setYPosition(CEGUI.PropertyHelper:stringToUDim(pos_str_y))
end

function gamehud:setReloadingPercent( p )
	p=clamp(p,0,100)
	self.ui.reload_progress_bar:setProgress(p*0.01)
	if p==100 then
		self.ui.reload_status:setText("Ready")
	else
		self.ui.reload_status:setText("Reloading")
	end
end

function gamehud:setCanonCursorEnabled( enable )
	if self.ui.cursor_canon:isVisible() == not enable then
		self.ui.cursor_canon:setVisible(enable)
	end
end

function gamehud:setCurrentAmmoType( index, name)
	if index>0 and index <= #self.ui.ammo_slot then
		self.ui.active_ammo_frame:setPosition(
			self.ui.ammo_slot[index]:getPosition())
		self.ui.current_ammo:setText(name)
	end
end

function gamehud:ChangeAmmoAmount( index, amount)
	if index>0 and index <= #self.ui.ammo_slot then
		self.ui.ammo_slot[index]:getChild("amount"):setText(tostring(amount))
	end
end

function gamehud:UpdateTopView( base_angle,top_angle )

	self.ui.top_view.base:setProperty(
		"Rotation","x:0 y:0 z:"..base_angle)
	self.ui.top_view.top:setProperty(
		"Rotation","x:0 y:0 z:"..top_angle)
end

function gamehud:notify( invoker, event )
	local event_id = event.event_id
	if event_id == Scene.EVENT.PLAYER_HIT then
		--body
	elseif event_id == Scene.EVENT.PLAYER_DESTROYED then
	end
end

function gamehud.OnKeyUp( args )
	local keycode = CEGUI.toKeyEventArgs(args)
	if keycode.scancode == CEGUI.Key.Escape then
		if not gamehud.pause_menu:isVisible() then
			gamehud.pause_menu:Show()
			Logic:PauseGame()
		end
	end
end