Lobby={
	m_refresh_timer=0,
	m_broadcast_timer=0,
	join_request_timer=-1,
	host_list={},
	host_lookup={},
	network = NeoGame.Network:getInstance(),
	player_lookup={},
	players={},
	in_host_list=true,
	hosting=false,
	broadcast_port=7220,
	host_port=7201,
	in_game=false
}

function Lobby:Init( )
	self.network:Init()
	Network.protocolListener:Init()
	self.network:EnableUDPBroadcastListening(self.broadcast_port)
	self.network:setSynchronizeInterval(50);
	for k,_ in pairs(self.host_list) do
		self.host_list[k]=nil
	end
	self.host_lookup={}
	self.hosting=false
	Network:AddPostUpdateObj(self)
end

function Lobby:ShutDown( )
	self.network:ShutDown()
	self.network:EnableUDPBroadcastListening(self.broadcast_port)
	self.in_host_list=true
	self.hosting=false
end

function Lobby:Close()
	Network:RemovePostUpdateObj(self)
	MultiMenu:HostListClear()
end

function Lobby:OnGameEnd()
	Network:EnablePostUpdateFunction(self,true)
	if self.in_game then
		g_ui_table.switchto("multi_menu")
		CEGUI.System:getSingleton():getDefaultGUIContext():getMouseCursor():show()
		MultiMenu:ForceQuitToHostList()
		self.in_game=false
	end
end

function Lobby:ResetPlayers()
	self.players={}
	self.player_lookup={}
end

function Lobby:AddPlayer( id,guid,name,type,team )
	self.player_lookup[guid]=id
	self.players[id].data={
		id=id,guid=guid, name=name,is_me=false,type=type,
			team=team,status="Picking",connected=true,open=true,
	}
end

function Lobby:RemovePlayer( id )
	self.player_lookup[self.players[id].data.guid]=nil
	self.players[id].data.connected=false
end

function Lobby:KickPlayer( id )
	if self.players[id] then
		local player = self.players[id]
		if player.data.connected then
			local guid = RakNet.RakNetGUID:new_local()
			if guid:FromString(player.data.guid) then
				self.network:KickClient(guid)
				self:RemovePlayer( id )
				self.player_count=self.player_count-1
				self.capacity=string.format("%d/%d",self.player_count,self.max_player_count)
			end
		end

	end
end

function Lobby:setMaxPlayerCount( amount )
	if amount==nil then
		return
	end
	self.network:setMaxIncomingConnection(amount)
	self.capacity=string.format("%d/%d",self.player_count,self.max_player_count)
end
--open=bool
function Lobby:OnPlayerSlotChange( id, open )
	if open then
		MultiMenu:PrepareWndOpenPlayerSlot(id)
		if open ~= self.players[id].data.open then
			self.max_player_count=self.max_player_count+1
		end
	else 
		MultiMenu:PrepareWndClosePlayerSlot(id)
		if open ~= self.players[id].data.open then
			self.max_player_count=self.max_player_count-1
		end
	end
	self.players[id].data.open=open
	self.players[id].data.connected=false
	if self.network:isServer() then
		Lobby:setMaxPlayerCount( self.max_player_count-1 )
		-- broadcast
		local event_msg=string.format("{id=%d,open=%s}",id,tostring(open))
		local stream = BitStreamHelper.CreateBitStream()
		BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.LOBBY_PLAYER_SLOT_CHANGE)
		BitStreamHelper.SerializeString(stream,event_msg)
		self.network:SendDataToAll(stream)
	end
end

function Lobby:ConnectHost( host_id )
	self:ResetPlayers()
	if self.host_list[host_id] then
		return self:JoinGame(self.host_list[host_id].ip)
	else
		return false
	end
end

function Lobby:ConnectHostByIP( ip )
	self:ResetPlayers()
	if ip ~= "" then
		return self:JoinGame(ip)
	end
	return false
end

function Lobby:HostGame( room_name, map_name )
	self:ResetPlayers()
	self.network:DisableUDPBroadcastListening()
	self:ReadMapData(map_name)
	local max_player = self.current_map_config.max_player
	local startup_result = self.network:StartServer(self.host_port,max_player-1)
	if not startup_result then
		return false
	end
	for i=1,max_player do
		self.players[i]={}
		self.players[i].data={
			id=i, name="",is_me=false,type="--",
			team=1,status="--",connected=false,guid="",open=true
		}
	end
	--config host self
	self.players[1].data.guid=self.network:getMyGUID():ToString()
	self.players[1].data.name=self.player_name
	self.players[1].data.is_me=true
	self.players[1].data.status="Host"
	self.players[1].data.connected=true
	self.players[1].data.type="t34"

	self.player_lookup[self.players[1].data.guid]=1
	-- update ui
	local map_data = {
		map_name=self.current_map_data.setting.map_name,
		map_file_name=map_name
	}
	self.in_host_list=false
	self.hosting=true
	self.room_name=room_name
	self.map_name=map_name
	self.player_count=1
	self.max_player_count=self.current_map_config.max_player
	self.id_self=1
	self.capacity=string.format("%d/%d",1,self.max_player_count)
	local ui_data = {}
	for k,v in pairs(self.players) do
		local idx = #ui_data+1
		ui_data[idx]=v.data
	end
	self:UpdatePrepareWindow(room_name, map_data,ui_data)

	self.network:DeleteReadyEvent(0)
	self.network:setReadyEvent(0,true)
	return true
end

function Lobby:JoinGame( ip )
	if self.network:StartClient(ip,self.host_port) then
		self.network:setReadyEvent(0,false)
		self.network:DisableUDPBroadcastListening()
		self.in_host_list=false
		return true
	else
		return false
	end
end

function Lobby:ReadMapData( map_name )
	self.current_map_data=dofile(DIR_MAPS..map_name )
	self.current_map_config = eval("{"..self.current_map_data.setting.logic_data.."}")
end

function Lobby:SendRoomRequest()
	local stream = BitStreamHelper.CreateBitStream()
	BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.LOBBY_QUERY_ROOM)
	BitStreamHelper.SerializeString(stream,Lobby.player_name)
	self.network:SendDataToAll(stream)
end

-- map_data={
-- 		map_name,map_file_name
-- }
-- player_data={
-- 	{is_me,id,name,type,team,status}
-- }
function Lobby:UpdatePrepareWindow( room_name, map_data, player_data )
	local wnd = MultiMenu.ui.prepare_wnd
	wnd.st_room_name:setText(room_name)
	wnd.st_map_name:setText(map_data.map_name)
	MultiMenu:PrepareWndSetPreview(map_data.map_file_name)
	MultiMenu:PrepareWndInitPlayerList(player_data, self.current_map_config.max_team_allowed,self.network:isServer())
end

function Lobby:UpdatePlayerName()
	self.player_name=MultiMenu.ui.host_list.eb_name:getText()
	if self.player_name == "" then
		self.player_name="Player Unknown"
	end
end

function Lobby:Update( current_time,delta_time )
	if self.join_request_timer>0 then
		self.join_request_timer=self.join_request_timer-delta_time
		if self.join_request_timer<=0 then
			--超时没收到房间信息，则重发请求
			self:SendRoomRequest()
			Lobby.join_request_timer=2000
		end
	end
	if self.m_broadcast_timer <= current_time and self.hosting then
		--broadcast room info
		self:BroadcastRoomInfo()
		self.m_broadcast_timer=current_time+1000
	end
	if self.in_host_list then
		local expire_rooms = {}
		for _,r in pairs(self.host_list) do
			r.expire=r.expire - delta_time
			if r.expire<=0 then
				table.insert(expire_rooms,r.id)
			end
		end
		for _,id in ipairs(expire_rooms) do
			self:RemoveRoom(id)
		end
	end
end

function Lobby:BroadcastRoomInfo()
	local stream = BitStreamHelper.CreateBitStream()
	-- guid
	BitStreamHelper.SerializeGUID(stream,self.network:getMyGUID())
	-- host name
	BitStreamHelper.SerializeString(stream,self.room_name)
	-- map name
	BitStreamHelper.SerializeString(stream,self.map_name)
	-- capacity
	BitStreamHelper.SerializeString(stream,self.capacity)
	--send
	self.network:SendUDPLanBroadcast(stream,self.broadcast_port)
end

function Lobby:GenerateRoomId( guid_str )
	if nil == guid_str then
		print("Error: Null guid")
		return
	end
	local id = tonumber(guid_str:sub(guid_str:len()-3))
	while self.host_list[id] do
		id=id+1
	end
	return id
end
--data={ip,guid=str,room_name,map,capacity}
function Lobby:AddRoom( data )
	local room
	if data.guid then
		local id = self.host_lookup[data.guid]
		room=self.host_list[id]
	end
	if not room then
		room={
			id=self:GenerateRoomId(data.guid),ip=data.ip,guid=data.guid,
			name=data.room_name,map=data.map,
			capacity=data.capacity
		}
		self.host_lookup[data.guid]=room.id
		self.host_list[room.id]=room
		MultiMenu:HostListAddLine( room.id, room.name, room.map, room.capacity )
	else
		room.ip=data.ip
		room.name=data.room_name
		room.map=data.map
		room.capacity=data.capacity
		MultiMenu:HostListUpdate( room.id, room.name, room.map, room.capacity )
	end
	room.expire=2000
end

function Lobby:RemoveRoom( room_id )
	if self.host_list[room_id] then
		MultiMenu:HostListRemoveRow(room_id)
		local room = self.host_list[room_id]
		self.host_lookup[room.guid]=nil
		self.host_list[room_id]=nil
	end
end

function Lobby:RemoveAllRoom( )
	self.host_list={}
	self.host_lookup={}
end

function Lobby:SendChatMsg( msg )
	local stream = NeoGame.network.CreateBitStream()
	BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.LOBBY_CHAT)
	BitStreamHelper.SerializeString(stream,msg)
	self.network:SendDataToAll(stream)
end

function Lobby:SystemBroadcast( msg )
	MultiMenu:PrepareWndChatLogAddLine(msg)
	Lobby:SendChatMsg(msg)
end

function Lobby:OnDisconnect(guid_str)
	if self.network:isServer() then
		local id = self.player_lookup[guid_str]
		if not id then
			return
		end
		-- broadcast message
		local player = self.players[id].data
		local msg = string.format("%s has left the game.",player.name)
		self:SystemBroadcast( msg )
		if player.connected then
			self:OnPlayerLeave(guid_str)
		end
	else
		if self.in_game then
			game:ShutdownMultiPlayerGame()
			self:OnGameEnd()
		else
			MultiMenu:BackToPreviousUI()
		end
	end
end

function Lobby:OnPlayerLeave( guid_str )
	local id = self.player_lookup[guid_str]
	if not id then
		return
	end
	self.player_count=self.player_count-1
	self.capacity=string.format("%d/%d",self.player_count,self.max_player_count)
	-- update ui
	if self.players[id].data.connected then
		MultiMenu:PrepareWndUpdatePlayerList(id,MultiMenu.empty_player_data)
	end
	-- remove data
	self:RemovePlayer(id)
end

function Lobby:OnConnectionFailed()
	MultiMenu:BackToPreviousUI()
end
-- player_data={guid=RakNet::RakNetGUID,name,type,team}
function Lobby:OnPlayerConnected( player_data )
	-- assign id
	local id
	for k,v in pairs(self.players) do
		if not v.data.connected and v.data.open then
			id=k
			break
		end
	end
	-- register
	self:OnPlayerJoined(id, player_data.guid:ToString(),
		player_data.name, player_data.type, player_data.team)

	local msg = string.format("%s has joined the game.",player_data.name)
	local join_packet = string.format("{id=%d,guid='%s',name='%s',type='%s',team=%d}",
		id, player_data.guid:ToString(), player_data.name, player_data.type, player_data.team)
	-- chat message
	self:SystemBroadcast( msg )	
	-- return room info
	self:SendRoomInfo(player_data.guid)
	-- sychronize other clients
	self:BroadcastJoinInfo(join_packet,player_data.guid)
end
-- function for client synchronization
function Lobby:OnPlayerJoined( id,guid_str,name,type,team )
	self:AddPlayer( id, guid_str, name, type, team )
	MultiMenu:PrepareWndUpdatePlayerList( id, self.players[id].data )
	self.player_count=self.player_count+1
	self.capacity=string.format("%d/%d",self.player_count,self.max_player_count)
end

function Lobby:DumpRoomInfo(target_player_guid)
	local data
	local guid_str = target_player_guid:ToString()
	data=string.format("room_name='%s',server_guid='%s',map='%s',player_count=%d,max_player_count=%d,",
		self.room_name,self.network:getMyGUID():ToString(),self.map_name,self.player_count,self.current_map_config.max_player)
	local player_str = "players={"
	for _,v in pairs(self.players) do
		local info = v.data
		local is_me = (info.guid == guid_str)
		player_str=player_str..string.format("{id=%d,open=%s,guid='%s',name='%s',type='%s',team=%d,status='%s',is_me=%s,connected=%s},",
			info.id,tostring(info.open),info.guid,info.name,info.type,info.team,info.status,tostring(is_me),tostring(info.connected))
	end
	player_str=player_str.."},"
	data="{"..data..player_str.."}"
	return data
end

function Lobby:SendRoomInfo( target_guid )
	local stream = BitStreamHelper.CreateBitStream()
	local str = self:DumpRoomInfo(target_guid)
	BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.LOBBY_ROOM_INFO)
	BitStreamHelper.SerializeString(stream,str)
	-- unicast
	self.network:SendDataToGUID(stream,0,target_guid,false)
end

function Lobby:BroadcastJoinInfo( data, exclude_guid )
	local stream = BitStreamHelper.CreateBitStream()
	BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.LOBBY_JOIN)
	BitStreamHelper.SerializeString(stream,data)
	-- broadcast
	self.network:SendDataToGUID(stream,0,exclude_guid,true)
end

function Lobby:OnReceiveRoomInfo( room_data )
	self.room_name=room_data.room_name
	self.map_name=room_data.map
	self:ReadMapData(self.map_name)

	self.player_count=room_data.player_count
	self.max_player_count=room_data.max_player_count
	self.capacity=string.format("%d/%d",self.player_count,room_data.max_player_count)
	self.server_guid=room_data.server_guid
	--update player data
	for _,v in ipairs(room_data.players) do
		self.player_lookup[v.guid]=v.id
		self.players[v.id]={}
		self.players[v.id].data=v
		if v.is_me then
			self.id_self=v.id
		end
	end
	--ui update
	local map_data = {
		map_name=self.current_map_data.setting.map_name,
		map_file_name=self.map_name
	}
	self:UpdatePrepareWindow(self.room_name, map_data,room_data.players)
end

--data={guid=str,type,team}
function Lobby:BroadcastPlayerUpdate( data )
	local data_str = string.format("{guid='%s',type='%s',team=%d}",data.guid,data.type,data.team)
	local stream = BitStreamHelper.CreateBitStream()
	BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.LOBBY_PLAYER_UPDATE)
	BitStreamHelper.SerializeString(stream,data_str)
	-- broadcast
	self.network:SendDataToAll(stream,0)
end

--data={guid=str,type,team}
function Lobby:OnPlayerInfoUpdate( data )
	local id = self.player_lookup[data.guid]
	if nil == id then
		return
	end
	self.players[id].data.type=data.type
	self.players[id].data.team=data.team
	MultiMenu:PrepareWndUpdatePlayerList( id, self.players[id].data )
end

function Lobby:OnPlayerTeamChange( id, team )
	local guid = self.players[id].data.guid
	self:OnPlayerInfoUpdate({guid=guid,type=self.players[id].data.type,team=team})
	self:BroadcastPlayerUpdate({guid=guid,type=self.players[id].data.type,team=team})
end

function Lobby:OnPlayerTankChange( id, tank_type )
	local guid = self.players[id].data.guid
	self:OnPlayerInfoUpdate({guid=guid,type=tank_type,team=self.players[id].data.team})
	self:BroadcastPlayerUpdate({guid=guid,type=tank_type,team=self.players[id].data.team})
end

function Lobby:ReadyForGame()
	self.network:setReadyEvent(0,true)
end

function Lobby:OnPlayerReady( guid )
	if guid == self.server_guid then
		return
	end
	local id = self.player_lookup[guid]
	if id then
		self.players[id].data.status="Ready"
	end
	MultiMenu:PrepareWndUpdatePlayerList( id, self.players[id].data )
end

function Lobby:StartGame( )
	Network:EnablePostUpdateFunction(self,false)
	if self.hosting then
		-- broadcast cmd
		local stream = BitStreamHelper.CreateBitStream()
		BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.LOBBY_START)
		self.network:SendDataToAll(stream)
	end
	local player_data = {}
	for k,v in pairs(self.players) do
		if v.data.connected then
			local idx = #player_data+1
			player_data[idx]=v.data
		end
	end
	-- switch ui
	g_ui_table.switchto("loading")
	-- load game
	LoadingScreen.Init()
	Scene.load=MultiPlayerSceneLoader
	Scene.Init(MultiMenu.map_root..self.map_name,player_data)
	self.in_game=true
end
-- in multiplayer game, when a player finish loading game
function Lobby:OnPlayerLoaded()
	Synchronizer.loaded_player_count=Synchronizer.loaded_player_count+1
end