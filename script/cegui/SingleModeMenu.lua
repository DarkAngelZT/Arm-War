require(DIR_SCRIPT_CEGUI.."InGameUI/HUD")

SingleMenu={}
SingleMenu.map_root="resources/maps/"

-----------------------------------------
-- Handler to  key input
-----------------------------------------
function SingleMenu.keyInput( args )
	local keycode = CEGUI.toKeyEventArgs(args)
	if keycode.scancode == CEGUI.Key.Escape then
		--直接退出
		g_ui_table.switchto("main")
	end
end
-------------------------------------
-- button handler
------------------------------------
function SingleMenu.OnButtonClick(args)
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName=="StartBtn" then
		SingleMenu.LoadGame()
	elseif btnName=="ExitBtn" then
		g_ui_table.switchto("main")
	end
end
-------------------------------------
-- map list handler
------------------------------------
function SingleMenu.OnMapListSelect( args )
	local map_list = SingleMenu.ui.map_list
	local preview = SingleMenu.ui.map_preview
	local item = map_list:getFirstSelectedItem()
	if not item then
		return
	end

	SingleMenu.map_name = item:getText()
	SingleMenu.ui.map_name:setText(SingleMenu.map_name)
	SingleMenu.current_map_data=dofile(DIR_MAPS..SingleMenu.map_name )
	SingleMenu:InitPlayerList(SingleMenu.current_map_data)
	SingleMenu:LoadPreviewImage(SingleMenu.map_name)
end
-------------------------------------
-- handle player change
-------------------------------------
function SingleMenu.OnPlayerChange( args )
	local event = CEGUI.toWindowEventArgs(args)
	local row = event.window:getParent()
	local cbx_type = row:getChild("Type")
	local cbx_team = row:getChild("Team")
	local id = event.window:getID()
	if event.window:getText()=="Closed" then
		cbx_type:setVisible(false)
		cbx_team:setVisible(false)
		SingleMenu.players[id]=nil
	else
		cbx_type:setVisible(true)
		cbx_team:setVisible(true)
		SingleMenu.players[id]={}
		local player = SingleMenu.players[id]
		player.name="Bot"..id
		player.tank_type=cbx_type:getText()
		player.id="a"..id
		player.team=tonumber(string.match(cbx_team:getText(),"%d+"))
	end

end
-------------------------------------
-- handle player tank type change
-------------------------------------
function SingleMenu.OnPlayerTankChange( args )
	local event = CEGUI.toWindowEventArgs(args)
	local id = event.window:getID()
	local tank = event.window:getText()
	local player = SingleMenu.players[id]
	player.tank_type = tank
end
-------------------------------------
-- handle player team change
-------------------------------------
function SingleMenu.OnPlayerTeamChange( args )
	local event = CEGUI.toWindowEventArgs(args)
	local id = event.window:getID()
	local team = tonumber(string.match(event.window:getText(),"%d+"))
	local player = SingleMenu.players[id]
	player.team = team
end
-------------------------------------
-- Initialize UI
-------------------------------------
function SingleMenu:Init()
	self.players={}
	self.current_team_member_count={}
	self.map_name=""
	local file_list = NeoGame.io.getFileInfolder(self.map_root,"lua")
	self:InitMapList(file_list)
	self:getTankTypes()
	self.ui.map_name:setText("")
	self.ui.player_list:resetList()
	local ammo_config = readTableFile(DIR_DATA.."game/ammo/shellFeasibility.txt")
	Logic.ammo_config={
		shell_types=ammo_config.header,
		shell_feasibility=ammo_config.content	
	}
end
-------------------------------------
-- Initialize map list
-------------------------------------
function SingleMenu:InitMapList( files )
	self.ui.map_list:resetList()
	for i=0,files:size()-1 do
		local row=CEGUI.createListboxTextItem(files[i],i)
		row:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
		self.ui.map_list:addItem(row)
	end
end
-------------------------------------
-- Initialize player list
-------------------------------------
function SingleMenu:InitPlayerList(map_info)
	local config = eval("{"..map_info.setting.logic_data.."}")
	local max_player=config.max_player
	local team_count = config.max_team_allowed
	local list = self.ui.player_list
	local item_prototype = self.ui.player_list_item
	list:resetList()
	self.players={}
	for i=1,max_player do
		local item = CEGUI.toItemEntry(item_prototype:clone(true))

		local cbx_name = CEGUI.toCombobox(item:getChild("PlayerName"))
		local cbx_type = CEGUI.toCombobox(item:getChild("Type"))
		local cbx_team = CEGUI.toCombobox(item:getChild("Team"))

		self.players[i]={}
		local player = self.players[i]

		if i==1 then
			-- player self
			cbx_name:setText("Player")
			cbx_name:setDisabled(true)
			player.name="Player"
			player.id="a"..i
		else
			--ai player
			cbx_name:setText("Computer")
			local option_ai=CEGUI.createListboxTextItem("Computer")
			local option_closed = CEGUI.createListboxTextItem("Closed")
			option_ai:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
			option_closed:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
			cbx_name:addItem(option_ai)
			cbx_name:addItem(option_closed)
			cbx_name:setID(i)
			cbx_name:subscribeEvent("ListSelectionAccepted","SingleMenu.OnPlayerChange")

			player.name="Bot"..i
			player.id="a"..i
		end

		cbx_type:setText("t34")
		cbx_type:setID(i)
		for i,v in ipairs(self.tank_types) do
			local option = CEGUI.createListboxTextItem(v)
			option:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
			cbx_type:addItem(option)
		end
		cbx_type:subscribeEvent("ListSelectionAccepted","SingleMenu.OnPlayerTankChange")
		player.tank_type="t34"

		cbx_team:setText("Team 1")
		cbx_team:setID(i)
		for i=1,team_count do
			local option = CEGUI.createListboxTextItem("Team "..i)
			option:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
			cbx_team:addItem(option)
		end
		cbx_team:subscribeEvent("ListSelectionAccepted","SingleMenu.OnPlayerTeamChange")
		player.team=1

		item:setName("player"..i)
		item:setVisible(true)
		list:addItem(item)	
	end
	list:notifyScreenAreaChanged(true)
end
-------------------------------------
-- Load preview Image
-------------------------------------
function SingleMenu:LoadPreviewImage( map_file_name )
	local map_name = split(map_file_name,".")[1]
	--load image
	local image = DIR_MAP_PREVIEW..map_name..".png"
	if NeoGame.io.isFileExist(image) then
		CEGUI.ImageManager:getSingleton():addFromImageFile(
			"map_preview_image",map_name..".png","mapPreview")
		self.ui.map_preview:setProperty("Image","map_preview_image")
	else 
		self.ui.map_preview:setProperty("Image","map_preview_default")
	end
end
-------------------------------------
-- Get all tank typs
-------------------------------------
function SingleMenu:getTankTypes( )
	self.tank_types={}
	local type_list = NeoGame.io.getFileInfolder(DIR_TANKS,"lua")
	for i=0,type_list:size()-1 do
		local tank_file = type_list[i]
		local tank_type = split(tank_file,".")[1]
		table.insert(self.tank_types,tank_type)
	end
end
-------------------------------------
-- collect data and load game
------------------------------------
function SingleMenu.LoadGame()
	local self = SingleMenu
	if self.map_name == "" then
		return
	end

	g_ui_table.switchto("loading")
	LoadingScreen.Init()
	Scene.load=SceneLoaderGeneric
	Scene.Init(self.map_root..self.map_name,self.players)
end

--load root ui
local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("SinglePlayerMenu.layout")
g_ui_table.single_menu=root
CEGUI.ImageManager:getSingleton():addFromImageFile(
			"map_preview_default","preview_default.png","mapPreview")
SingleMenu.ui={
	map_list=CEGUI.toListbox(root:getChild("FrameWnd/MapList")),
	player_list=CEGUI.toItemListbox(root:getChild("FrameWnd/PlayerListRoot/PlayerList")),
	player_list_item=CEGUI.toItemEntry(root:getChild("FrameWnd/PlayerListRoot/PlayerItemPrefab")),
	map_preview=root:getChild("FrameWnd/mapOverView"),
	map_name=root:getChild("FrameWnd/MapName")
}

-- subscribe required events
root:subscribeEvent("KeyUp","SingleMenu.keyInput")
root:getChild("FrameWnd/StartBtn"):subscribeEvent("Clicked","SingleMenu.OnButtonClick")
root:getChild("FrameWnd/ExitBtn"):subscribeEvent("Clicked","SingleMenu.OnButtonClick")
SingleMenu.ui.map_list:subscribeEvent("SelectionChanged","SingleMenu.OnMapListSelect")