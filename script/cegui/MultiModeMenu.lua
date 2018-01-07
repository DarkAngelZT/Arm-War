require(DIR_SCRIPT_CEGUI.."InGameUI/HUD")
require(DIR_SCRIPT.."game/network/Lobby")

MultiMenu={
	panel_stack={},
	current_ui=nil,
	empty_player_data={
		name="Open",type="--",team=1,status="--"
	},
}
MultiMenu.map_root="resources/maps/"

-----------------------------------------
-- Handler to  key input
-----------------------------------------
function MultiMenu.keyInput( args )
	local keycode = CEGUI.toKeyEventArgs(args)
	if keycode.scancode == CEGUI.Key.Escape then
		MultiMenu:BackToPreviousUI()
	end
	return true
end

function MultiMenu.PrepareWndOnChatKeyDown( args )
	local keycode = CEGUI.toKeyEventArgs(args)
	if keycode.scancode == CEGUI.Key.Return then
		MultiMenu:PrepareWndSendChatMsg()
	end
	return true
end
-------------------------------------
-- button handler
------------------------------------
function MultiMenu.OnHostListButtonClick(args)
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName=="Cancel_btn" then
		MultiMenu:BackToPreviousUI()
	elseif btnName=="JoinDes_btn" then
		local addr = MultiMenu.ui.host_list.eb_ip:getText()
		MultiMenu:PrepareWndReset()
		Lobby:UpdatePlayerName()
		if Lobby:ConnectHostByIP(addr) then
			MultiMenu:ShowUI(MultiMenu.ui.prepare_wnd)
			MultiMenu.ui.prepare_wnd.btn_start:setText("Ready")
		end
	elseif btnName=="Refresh_btn" then
		MultiMenu:HostListClear()
	elseif btnName=="Join_btn" then
		if MultiMenu.current_selected_host_id ~= -1 then
			MultiMenu:PrepareWndReset()
			Lobby:UpdatePlayerName()
			if Lobby:ConnectHost(MultiMenu.current_selected_host_id) then
				MultiMenu:ShowUI(MultiMenu.ui.prepare_wnd)
				MultiMenu.ui.prepare_wnd.btn_start:setText("Ready")
			end
		end
	elseif btnName=="Create_btn" then
		MultiMenu:ShowUI(MultiMenu.ui.map_select)
		Lobby:UpdatePlayerName()
	end
	return true
end

function MultiMenu.OnMapListButtonClick( args )
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName=="btn_cancel" then
		MultiMenu:BackToPreviousUI()
	elseif btnName=="btn_ok" then
		--load map data
		if MultiMenu.map_selection_selected == "" then
			return
		end
		if Lobby:HostGame(MultiMenu.ui.map_select.eb_room_name:getText(), MultiMenu.map_selection_selected)	then
			MultiMenu.ui.prepare_wnd.btn_start:setText("Start")
			MultiMenu:ShowUI(MultiMenu.ui.prepare_wnd)
			MultiMenu:PrepareWndClearChatLog()
		end
	end
end

function MultiMenu.OnTankSelectButtonClick( args )
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName=="btn_ok" then
		if MultiMenu.tank_selection_item == "" then
			return
		else
			Lobby:OnPlayerTankChange(Lobby.id_self,MultiMenu.tank_selection_item)
		end
	end
	MultiMenu:BackToPreviousUI()
end

function MultiMenu.OnPrepareWndButtonClick( args )
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName=="Cancel_btn" then
		MultiMenu:BackToPreviousUI()
	elseif btnName=="Start_btn" then
		if Lobby.hosting then
			if Lobby.network:isReadyEventCompleted(0) then
				Lobby:StartGame()
			end
		else
			MultiMenu.ui.prepare_wnd.btn_start:disable()
			Lobby:ReadyForGame()
		end
	elseif btnName=="Tank_btn" then
		MultiMenu:ShowUI(MultiMenu.ui.tank_select)
	elseif btnName=="chat_submit_btn" then
		MultiMenu:PrepareWndSendChatMsg()
	end
end
-------------------------------------
-- Initialize UI
-------------------------------------
function MultiMenu:Init( ... )
	self.ui.host_list:show()
	self.ui.map_select:show(false)
	self.ui.prepare_wnd:show(false)
	self.ui.tank_select:show(false)
	self.current_ui=self.ui.host_list
	self.panel_stack={}

	self.current_selected_host_id=-1
	MultiMenu.ui.host_list.eb_name:setText("")

	local map_file_list = NeoGame.io.getFileInfolder(self.map_root,"lua")
	self:InitMapSelection(map_file_list)
	self:TankSelectionWindowInit()

	Lobby:Init()
	self:PrepareWndReset()
end

function MultiMenu.Exit( )
	Lobby:Close()
	NeoGame.Network:getInstance():CleanUp()
	g_ui_table.switchto("main")
	Sound:Play2D("main_menu",true):setVolume(
			ApplicationSettings.SoundVolume.bgm/100)
end

function MultiMenu:PushUIToStack( ui )
	self.panel_stack[#self.panel_stack+1]=ui
end

function MultiMenu:ClearUIStack()
	for i,_ in ipairs(self.panel_stack) do
		self.panel_stack[i]=nil
	end
end

function MultiMenu:PopUIFromStack( )
	if #self.panel_stack>0 then
		local ui = self.panel_stack[#self.panel_stack]
		self.panel_stack[#self.panel_stack]=nil
		return ui
	else
		return
	end
end

function MultiMenu:ShowUI( ui )
	self.current_ui:show(false)
	self:PushUIToStack(self.current_ui)
	ui:show(true)
	self.current_ui=ui
end

function MultiMenu:BackToPreviousUI( )
	local ui = self:PopUIFromStack()
	if ui then
		self.current_ui:show(false)
		if self.current_ui == self.ui.prepare_wnd then
			Lobby:ShutDown()
		end
		self.current_ui=ui
		ui:show(true)
	else
		self:Exit()
	end
end

function MultiMenu:ForceQuitToHostList()
	self:ClearUIStack()
	self.ui.map_select:show(false)
	self.ui.prepare_wnd:show(false)
	self.ui.tank_select:show(false)
	self.current_ui = self.ui.host_list
	self.ui.host_list:show()
end
-------------------------------------
-- host list functions
-------------------------------------
function MultiMenu:HostListAddLine( room_id, host_name, map_name, cap )
	local row = self.ui.host_list.list:addRow()
	local name_col = CEGUI.createListboxTextItem(host_name)
	local map_col = CEGUI.createListboxTextItem(map_name)
	local cap_col = CEGUI.createListboxTextItem("  "..cap)

	name_col:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
	map_col:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
	cap_col:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")

	self.ui.host_list.list:setRowID(row,room_id)
	name_col:setID(room_id)
	map_col:setID(room_id)
	cap_col:setID(room_id)

	self.ui.host_list.list:setItem(name_col,0,row)
	self.ui.host_list.list:setItem(map_col,1,row)
	self.ui.host_list.list:setItem(cap_col,2,row)

	Lobby.host_list[room_id].ui_host_name=name_col
	Lobby.host_list[room_id].ui_map_name=map_col
	Lobby.host_list[room_id].ui_capacity=cap_col
end

function MultiMenu:HostListUpdate( room_id, host_name, map_name, cap )
	if not Lobby.host_list[room_id] then
		return
	end
	local room = Lobby.host_list[room_id]
	room.ui_host_name:setText(host_name)
	room.ui_map_name:setText(map_name)
	room.ui_capacity:setText("  "..cap)
	self.ui.host_list.list:invalidate(true)
end

function MultiMenu:HostListRemoveRow( room_id )
	if not Lobby.host_list[room_id] then
		return
	end
	local row_idx = self.ui.host_list.list:getRowWithID(room_id)
	self.ui.host_list.list:removeRow(row_idx)
end

function MultiMenu:HostListClear( )
	self.ui.host_list.list:resetList()
	self.ui.host_list.list:setSortDirection( CEGUI.ListHeaderSegment.None)
	self.current_selected_host_id=-1
	Lobby:RemoveAllRoom()
end

function MultiMenu.HostListOnSelect( args )
	local item = MultiMenu.ui.host_list.list:getFirstSelectedItem()
	local id = item:getID()
	MultiMenu.current_selected_host_id=id
end
-------------------------------------
-- map selection window functions
-------------------------------------
function MultiMenu:InitMapSelection( map_files )
	self:MapSelectionClear()
	for i=0,map_files:size()-1 do
		local row=CEGUI.createListboxTextItem(map_files[i],i)
		row:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
		self.ui.map_select.list:addItem(row)
	end
end

function MultiMenu:MapSelectionClear()
	self.ui.map_select.list:resetList()
	self.map_selection_selected=""
end

function MultiMenu.OnMapSelectionSelect( args )
	local map_list = MultiMenu.ui.map_select.list
	local item = map_list:getFirstSelectedItem()
	if not item then
		MultiMenu.map_selection_selected = ""
		return
	end

	MultiMenu.map_selection_selected = item:getText()
end
-------------------------------------
-- Prepare window functions
-------------------------------------
function MultiMenu:PrepareWndInitPlayerList( player_data, max_team_count , is_host )
	if is_host == nil then
		is_host=false
	end
	self.ui.prepare_wnd.player_list:resetList()
	for i,data in ipairs(player_data) do
		local item = CEGUI.toItemEntry(self.ui.prepare_wnd.player_list_item:clone(true))

		local cbx_name = CEGUI.toCombobox(item:getChild("player_name"))
		local cbx_team = CEGUI.toCombobox(item:getChild("team"))
		local st_type = item:getChild("type")
		local st_status = item:getChild("status")

		cbx_name:setID(data.id)
		cbx_team:setID(data.id)

		Lobby.players[data.id].ui={
			name=cbx_name,
			team=cbx_team,
			type=st_type,
			status=st_status
		}

		if is_host and not data.is_me then
			local option_kick=CEGUI.createListboxTextItem("Open")
			local option_close = CEGUI.createListboxTextItem("Closed")
			option_kick:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
			option_close:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
			cbx_name:addItem(option_kick)
			cbx_name:addItem(option_close)
			cbx_name:subscribeEvent("ListSelectionAccepted","MultiMenu.PrepareWndOnPlayerInfoChange")
		else
			cbx_name:disable()
		end
		if not data.connected then
			if data.open then
				cbx_name:setText("Open")
			else 
				cbx_name:setText("Closed")
			end
		else
			cbx_name:setText(data.name)
		end

		if data.is_me then
			for j=1,max_team_count do
				local option = CEGUI.createListboxTextItem("Team "..j)
				option:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
				cbx_team:addItem(option)
			end
			cbx_team:subscribeEvent("ListSelectionAccepted","MultiMenu.PrepareWndOnPlayerTeamChange")
		else
			cbx_team:disable()
		end
		cbx_team:setText("Team "..data.team)

		st_type:setText(data.type)
		st_status:setText(data.status)

		item:setName("player"..i)
		item:setVisible(true)
		self.ui.prepare_wnd.player_list:addItem(item)
	end
	self.ui.prepare_wnd.player_list:notifyScreenAreaChanged(true)
end

function MultiMenu:PrepareWndClosePlayerSlot(id)
	if not Lobby.players[id] then
		return
	end
	local ui = Lobby.players[id].ui
	ui.name:setText("Closed")
	ui.type:setText("--")
	ui.team:setText("--")
	ui.status:setText("--")

	ui.team:disable()
end

function MultiMenu:PrepareWndOpenPlayerSlot(id)
	if not Lobby.players[id] then
		return
	end
	local ui = Lobby.players[id].ui
	ui.name:setText("Open")
	ui.type:setText("--")
	ui.team:setText("Team 1")
	ui.status:setText("--")
end
--player_data={ name,type,team,status }
function MultiMenu:PrepareWndUpdatePlayerList( id, player_data )
	if Lobby.players[id] then
		local ui = Lobby.players[id].ui
		ui.name:setText(player_data.name)
		ui.type:setText(player_data.type)
		ui.team:setText("Team "..player_data.team)
		ui.status:setText(player_data.status)
	end
end

function MultiMenu:PrepareWndSetPreview( map_file_name )
	local map_name = split(map_file_name,".")[1]
	--load image
	local image = DIR_MAP_PREVIEW..map_name..".png"
	if NeoGame.io.isFileExist(image) then
		CEGUI.ImageManager:getSingleton():addFromImageFile(
			"map_preview_image",map_name..".png","mapPreview")
		self.ui.prepare_wnd.img_overview:setProperty("Image","map_preview_image")
	else 
		self.ui.prepare_wnd.img_overview:setProperty("Image","map_preview_default")
	end
end

function MultiMenu:PrepareWndReset()
	self.ui.prepare_wnd.st_room_name:setText("")
	self.ui.prepare_wnd.st_map_name:setText("Loading...")
	self.ui.prepare_wnd.player_list:resetList()
	self.ui.prepare_wnd.img_overview:setProperty("Image","map_preview_default")
	self:PrepareWndClearChatLog()
	self.ui.prepare_wnd.btn_start:enable()
end
-- kick client btn
function MultiMenu.PrepareWndOnPlayerInfoChange( args )
	local event = CEGUI.toWindowEventArgs(args)
	local id = event.window:getID()
	if Lobby.players[id].data.connected then
		Lobby:KickPlayer(id)
	end
	if event.window:getText() == "Closed" then
		Lobby:OnPlayerSlotChange(id,false)
	else
		Lobby:OnPlayerSlotChange(id,true)
	end
end

function MultiMenu.PrepareWndOnPlayerTeamChange( args )
	local event = CEGUI.toWindowEventArgs(args)
	local id = event.window:getID()
	local team = tonumber(string.match(event.window:getText(),"%d+"))
	Lobby:OnPlayerTeamChange(id,team)
end

function MultiMenu:PrepareWndChatLogAddLine( line )
	line = line..'\n'
	local log = self.ui.prepare_wnd.mleb_chat_content:getText()
	log = log..line
	self.ui.prepare_wnd.mleb_chat_content:setText(log)
	-- move cursor to the bottom
	self.ui.prepare_wnd.mleb_chat_content:setCaretIndex(-1)
end

function MultiMenu:PrepareWndClearChatInput()
	self.ui.prepare_wnd.eb_chat:setText("")
end

function MultiMenu:PrepareWndClearChatLog( )
	self.ui.prepare_wnd.mleb_chat_content:setText("")
	self.ui.prepare_wnd.eb_chat:setText("")
end

function MultiMenu:PrepareWndSendChatMsg()
	local msg = self.ui.prepare_wnd.eb_chat:getText()
	if msg == "" then
		return
	else
		--msg
		msg="[ "..Lobby.player_name.." ]: "..msg
		self:PrepareWndChatLogAddLine(msg)
		self.ui.prepare_wnd.eb_chat:setText("")
		Lobby:SendChatMsg(msg)
	end
end
-------------------------------------
-- Tank selection window functions
-------------------------------------
function MultiMenu:TankSelectionWindowInit()
	self.tank_selection_item=""
	local type_list = NeoGame.io.getFileInfolder(DIR_TANKS,"lua")
	for i=0,type_list:size()-1 do
		local tank_file = type_list[i]
		local tank_type = split(tank_file,".")[1]
		local row=CEGUI.createListboxTextItem(tank_type,i)
		row:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
		self.ui.tank_select.list:addItem(row)
	end
end

function MultiMenu.OnTankSelectionSelect( args )
	local tank_list = MultiMenu.ui.tank_select.list
	local item = tank_list:getFirstSelectedItem()
	if not item then
		MultiMenu.tank_selection_item=""
		return
	end
	MultiMenu.tank_selection_item=item:getText()
	return true
end
-------------------
--load root ui
local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("MultiPlayer.layout")
g_ui_table.multi_menu=root

MultiMenu.ui={
	host_list={
		wnd_root=root:getChild("HostSelectWnd"),
		btn_cancel=root:getChild("HostSelectWnd/Cancel_btn"),
		btn_refresh=root:getChild("HostSelectWnd/Refresh_btn"),
		btn_connect=root:getChild("HostSelectWnd/JoinDes_btn"),
		btn_create=root:getChild("HostSelectWnd/Create_btn"),
		btn_join==root:getChild("HostSelectWnd/Join_btn"),
		eb_ip=root:getChild("HostSelectWnd/IP_Text"),
		eb_name=root:getChild("HostSelectWnd/Eb_Online_ID"),
		show=function( self, visible )
			if visible == nil then
				visible=true
			end
			self.wnd_root:setVisible(visible)
		end,
	},
	map_select={
		wnd_root=root:getChild("MapSelection"),
		btn_ok=root:getChild("MapSelection/btn_ok"),
		btn_cancel=root:getChild("MapSelection/btn_cancel"),
		list=CEGUI.toListbox(root:getChild("MapSelection/map_list")),
		eb_room_name=root:getChild("MapSelection/eb_room_name"),
		show=function( self, visible )
			if visible == nil then
				visible=true
			end
			self.wnd_root:setVisible(visible)
		end,
	},
	prepare_wnd={
		wnd_root=root:getChild("Multi_PrepareWnd"),
		btn_start=root:getChild("Multi_PrepareWnd/Start_btn"),
		btn_cancel=root:getChild("Multi_PrepareWnd/Cancel_btn"),
		btn_tank=root:getChild("Multi_PrepareWnd/Tank_btn"),
		btn_chat=root:getChild("Multi_PrepareWnd/chat_submit_btn"),
		img_overview=root:getChild("Multi_PrepareWnd/mapOverview"),
		st_room_name=root:getChild("Multi_PrepareWnd/room_name_text"),
		st_map_name=root:getChild("Multi_PrepareWnd/MapName_text"),
		mleb_chat_content=CEGUI.toMultiLineEditbox(root:getChild("Multi_PrepareWnd/chatWnd")),
		eb_chat=root:getChild("Multi_PrepareWnd/chatEdit"),
		player_list=CEGUI.toItemListbox(root:getChild("Multi_PrepareWnd/PlayerList/list")),
		player_list_item=CEGUI.toItemEntry(root:getChild("Multi_PrepareWnd/PlayerList/playerItemPrefab")),
		show=function( self, visible )
			if visible == nil then
				visible=true
			end
			self.wnd_root:setVisible(visible)
			self.btn_start:enable()
		end,
		DiableAllButtons=function( self )
			self.btn_start:disable()
			self.btn_cancel:disable()
			self.btn_tank:disable()
		end,
		EnableAllButtons=function( self )
			self.btn_start:enable()
			self.btn_cancel:enable()
			self.btn_tank:enable()
		end,
	},
	tank_select={
		wnd_root=root:getChild("TankSelectWnd"),
		list=CEGUI.toListbox(root:getChild("TankSelectWnd/list_tank")),
		show=function( self, visible )
			if visible == nil then
				visible=true
			end
			self.wnd_root:setVisible(visible)
		end,
	}
}

--构建主机列表
local game_host_list=CEGUI.toMultiColumnList(
	CEGUI.WindowManager:getSingleton():createWindow("GlossySerpent/MultiColumnList", "list"))
game_host_list:setWidth(CEGUI.PropertyHelper:stringToUDim("{1,0}"))
game_host_list:setHeight(CEGUI.PropertyHelper:stringToUDim("{1,0}"))
game_host_list:addColumn("Host Name", 0, CEGUI.PropertyHelper:stringToUDim("{0.35,0}"))
game_host_list:addColumn("Map", 1, CEGUI.PropertyHelper:stringToUDim("{0.35,0}"))
game_host_list:addColumn("Capacity", 2, CEGUI.PropertyHelper:stringToUDim("{0.3,0}"))
root:getChild("HostSelectWnd/HostListPanel"):addChild(game_host_list)
game_host_list:setProperty("ColumnsMovable",CEGUI.PropertyHelper:boolToString(false))
MultiMenu.ui.host_list.list=game_host_list
game_host_list:setSelectionMode(CEGUI.MultiColumnList.RowSingle)

MultiMenu.ui.background=root:getChild("bg")

CEGUI.ImageManager:getSingleton():addFromImageFile("multi_menu_bg","game_menu.jpg","images")
MultiMenu.ui.background:setProperty("Image","multi_menu_bg")

-- subscribe required events
root:subscribeEvent("KeyUp","MultiMenu.keyInput")

root:getChild("HostSelectWnd/Cancel_btn"):subscribeEvent("Clicked","MultiMenu.OnHostListButtonClick")
root:getChild("HostSelectWnd/Create_btn"):subscribeEvent("Clicked","MultiMenu.OnHostListButtonClick")
root:getChild("HostSelectWnd/JoinDes_btn"):subscribeEvent("Clicked","MultiMenu.OnHostListButtonClick")
root:getChild("HostSelectWnd/Join_btn"):subscribeEvent("Clicked","MultiMenu.OnHostListButtonClick")
root:getChild("HostSelectWnd/Refresh_btn"):subscribeEvent("Clicked","MultiMenu.OnHostListButtonClick")
game_host_list:subscribeEvent("SelectionChanged","MultiMenu.HostListOnSelect")

root:getChild("MapSelection/btn_ok"):subscribeEvent("Clicked","MultiMenu.OnMapListButtonClick")
root:getChild("MapSelection/btn_cancel"):subscribeEvent("Clicked","MultiMenu.OnMapListButtonClick")
root:getChild("MapSelection/map_list"):subscribeEvent("SelectionChanged","MultiMenu.OnMapSelectionSelect")

root:getChild("TankSelectWnd/btn_ok"):subscribeEvent("Clicked","MultiMenu.OnTankSelectButtonClick")
root:getChild("TankSelectWnd/btn_cancel"):subscribeEvent("Clicked","MultiMenu.OnTankSelectButtonClick")
root:getChild("TankSelectWnd/list_tank"):subscribeEvent("SelectionChanged","MultiMenu.OnTankSelectionSelect")

root:getChild("Multi_PrepareWnd/Cancel_btn"):subscribeEvent("Clicked","MultiMenu.OnPrepareWndButtonClick")
root:getChild("Multi_PrepareWnd/Start_btn"):subscribeEvent("Clicked","MultiMenu.OnPrepareWndButtonClick")
root:getChild("Multi_PrepareWnd/Tank_btn"):subscribeEvent("Clicked","MultiMenu.OnPrepareWndButtonClick")
root:getChild("Multi_PrepareWnd/chat_submit_btn"):subscribeEvent("Clicked","MultiMenu.OnPrepareWndButtonClick")
root:getChild("Multi_PrepareWnd/chatEdit"):subscribeEvent("KeyDown","MultiMenu.PrepareWndOnChatKeyDown")