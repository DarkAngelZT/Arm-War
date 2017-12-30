require(DIR_SCRIPT_CEGUI.."InGameUI/ScoreBoard")
require(DIR_SCRIPT_CEGUI.."InGameUI/PauseMenuSinglePlayer")
require(DIR_SCRIPT_CEGUI.."InGameUI/PauseMenuMultiPlayer")
require(DIR_SCRIPT_CEGUI.."InGameUI/DeathMenu")

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
		root=root:getChild("TopViewRoot"),
		base=root:getChild("TopViewRoot/Base"),
		top=root:getChild("TopViewRoot/Top")
	},
	message=root:getChild("Message")
}
gamehud.ammo_sprite_name={
	AP="gameHUD/AP_icon",
	HE="gameHUD/HE_icon",
	HESH="gameHUD/HESH_icon",
	HEAT="gameHUD/HEAT_icon"
}


function gamehud:Init( actor )
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
	if self.death_menu then
		Scene:addInternalObserver(self.death_menu)
		self.death_menu:Init()
	end
	-- add timer for message display
	Logic:AddTimer(self.message_fadeout_timer)
	self:Refresh(actor)
end

function gamehud:Refresh(actor)
	if actor then
		self.ui.ammo_slot.root:setVisible(true)
		--set shell icon
		for i=1,3 do
			local icon_type = self.ammo_sprite_name[actor.ammo[i].name]
			self.ui.ammo_slot[i]:getChild("icon"):setProperty("Image",icon_type)
			self.ui.ammo_slot[i]:getChild("amount"):setText(tostring(actor.ammo[i].amount))
		end
		local tank_type=actor.entity.property.tank_name
		CEGUI.ImageManager:getSingleton():loadImageset(tank_type..".imageset","tankTopview")
		self.ui.top_view.base:setProperty("Image","TankTopView/base")
		self.ui.top_view.top:setProperty("Image","TankTopView/top")
		--reset reloading bar
		self:setReloadingPercent( 100 )
		self.ui.ammo_slot.root:setVisible(true)
		self.ui.top_view.root:setVisible(true)
	else
		self.ui.ammo_slot.root:setVisible(false)
		self.ui.top_view.root:setVisible(false)
	end
	self.ui.message:setAlpha(0)
	if self.pause_menu then
		self.pause_menu:Hide()
	end
	self:setTopViewColor(255,255,255)
end

function gamehud:ShowMessage( message )
	self.ui.message:setText(message)
	if not self.message_fadeout_timer.running then
		gamehud.message_fadeout_animation:stop()
		gamehud.message_fadein_animation:start()
	end
	self.message_fadeout_timer:Reset()
	self.message_fadeout_timer:Start()
end

function gamehud:OnMessageTimeOut()
	gamehud.message_fadeout_animation:start()
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

function gamehud:UpdateTopView( base_angle,top_angle, health_ratio )
	health_ratio=health_ratio or 1
	self.ui.top_view.base:setProperty(
		"Rotation","x:0 y:0 z:"..base_angle)
	self.ui.top_view.top:setProperty(
		"Rotation","x:0 y:0 z:"..top_angle)
	local green = 255
	local blue = 255
	if health_ratio>0.5 then
		blue=math.floor(255*(2*health_ratio-1))
	elseif health_ratio <=0.5 then
		blue=0
		green=math.floor(255*(2*health_ratio))
	end
	self:setTopViewColor(255,green,blue)
end

function gamehud:setTopViewColor( red, green, blue )
	local color_str = string.format("FF%02X%02X%02X",red,green,blue)
	local color_attr = string.format("tl:%s tr:%s bl:%s br:%s",color_str,color_str,color_str,color_str)
	self.ui.top_view.base:setProperty(
		"ImageColours",color_attr)
	self.ui.top_view.top:setProperty(
		"ImageColours",color_attr)
end

function gamehud:notify( invoker, event )
	local event_id = event.event_id
	if event_id == Scene.EVENT.PLAYER_HIT then
		if event.attacker ~= Logic.actor_me then
			return
		end
		if event.pierce then
			self:ShowMessage("[colour='FFFF7F00']Hit - PIERCED")
		elseif event.ricochet then
			self:ShowMessage("Ricocheted")
		else
			self:ShowMessage("[colour='FFF4E242']Hit")
		end
	elseif event_id == Scene.EVENT.PLAYER_DESTROYED then
		if invoker==Logic.actor_me then
			if self.death_menu then
				self.death_menu:Show()
			end
			return
		end
		if event.attacker == Logic.actor_me then
			self:ShowMessage("[colour='FFFF0000']Target Destroyed")
		end
		
	end
end

function gamehud.OnKeyUp( args )
	local keycode = CEGUI.toKeyEventArgs(args)
	if keycode.scancode == CEGUI.Key.Escape then
		if not gamehud.pause_menu:isVisible() then
			gamehud.pause_menu:Show()
			if Logic.game_mode == Logic.GAME_MODE.SINGLE then
				Logic:PauseGame()
			elseif Logic.game_mode == Logic.GAME_MODE.MULTIPLE then
				Scene.cameras.third_person:setEnabled(false)
				Logic.in_game=false
			end
		end
	end
end

--------------------------
--init script entry
--------------------------
gamehud.message_fadeout_timer=Timer.new()
gamehud.message_fadeout_timer.duration=6
gamehud.message_fadeout_timer:AddTriggerFunction(gamehud.OnMessageTimeOut,gamehud)
local animation = CEGUI.AnimationManager:getSingleton()
animation:loadAnimationsFromXML("game_ui.anims")
gamehud.message_fadein_animation=animation:instantiateAnimation("FadeIn")
gamehud.message_fadein_animation:setTargetWindow(gamehud.ui.message)

gamehud.message_fadeout_animation=animation:instantiateAnimation("FadeOut")
gamehud.message_fadeout_animation:setTargetWindow(gamehud.ui.message)