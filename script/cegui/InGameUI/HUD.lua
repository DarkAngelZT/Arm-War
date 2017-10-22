require(DIR_SCRIPT_CEGUI.."InGameUI/ScoreBoard")

local winMgr = CEGUI.WindowManager:getSingleton()
CEGUI.ImageManager:getSingleton():loadImageset("gameHUD.imageset");
local root = winMgr:loadLayoutFromFile("inGameHud/HUD.layout")
g_ui_table.hud=root

gamehud={}
gamehud.ui={
	ammo_slot={
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
}

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