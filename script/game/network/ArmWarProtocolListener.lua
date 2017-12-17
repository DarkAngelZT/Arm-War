AWProtocolListener=
{
	Init=function( self )
		self.network=NeoGame.Network:getInstance()
		self.network:CleanUp()
		for k,v in pairs(self.protocol_mapping) do
			self.network:AddProtocolListener(k,v)
		end
	end,
	CustomProtocol={
		LOBBY_CHAT=ID_USER_PACKET_ENUM,
		LOBBY_START=ID_USER_PACKET_ENUM+1,
		LOBBY_QUERY_ROOM=ID_USER_PACKET_ENUM+2,
		LOBBY_ROOM_INFO=ID_USER_PACKET_ENUM+3,
		LOBBY_JOIN=ID_USER_PACKET_ENUM+4,
		LOBBY_LEAVE=ID_USER_PACKET_ENUM+5,
		LOBBY_PLAYER_UPDATE=ID_USER_PACKET_ENUM+6,
		LOBBY_PLAYER_SLOT_CHANGE=ID_USER_PACKET_ENUM+7,
		Lobby_PLAYER_READY=ID_USER_PACKET_ENUM+8,
	},
}

function skipProtocolID( packet )
	local bitstream = packet:getBitStream()
	--ignore protocol id byte
	bitstream:IgnoreBytes(1)
	return bitstream
end

function toPacket( packet, skip_protocol_id )
	if skip_protocol_id == nil then
		skip_protocol_id = true
	end
	local p = tolua.cast(packet,"NeoGame::network::Packet")
	if skip_protocol_id then
		return p, skipProtocolID(p)
	else
		return p, p:getBitStream()
	end
end

function AWProtocolListener.OnIncommingNewConnection( packet )
	-- packet=toPacket(packet)
	print("get incomming connect request")
end

function AWProtocolListener.OnConnectionAccept( packet )
	-- packet=toPacket(packet)
	print("Connect request accepted")
	Lobby:SendRoomRequest()
	Lobby.join_request_timer=2000
end

function AWProtocolListener.OnDisconnect( packet )
	packet=toPacket(packet)
	print("Disconneted")
	local guid = packet:getGUIDString()
	Lobby:OnDisconnect(guid)
	AWProtocolListener.network:ReadyEventRemoveFromRemoteList(0,packet:getGUID())
	--server广播
	if AWProtocolListener.network:isServer() then
		local stream = BitStreamHelper.CreateBitStream()
		BitStreamHelper.SerializeAsProtocolID(stream,AWProtocolListener.CustomProtocol.LOBBY_LEAVE)
		BitStreamHelper.SerializeString(stream,guid)
		AWProtocolListener.network:SendDataToGUID(stream,0,packet:getGUID(),true)
	end
end

function AWProtocolListener.OnConnectionFailed( packet )
	local packet,bitstream=toPacket(packet,false)
	local protocol = 0
	protocol = BitStreamHelper.DeserializeProtocolID(bitstream,protocol)
	local msg = AWProtocolListener.network:BaseProtocolIDToString(protocol)
	print(string.format("connection failed [%d]: %s",protocol,msg))
	Lobby:OnConnectionFailed()
end

function AWProtocolListener.OnRoomBroadcast( packet )
	local packet, bitstream=toPacket(packet)
	local guid = RakNet.RakNetGUID:new_local()
	local room_name = ""
	local map = ""
	local cap = ""
	local ip = packet:getSenderIPAddress()
	BitStreamHelper.DeserializeGUID(bitstream,guid)
	room_name=BitStreamHelper.DeserializeString(bitstream,room_name)
	map=BitStreamHelper.DeserializeString(bitstream,map)
	cap=BitStreamHelper.DeserializeString(bitstream,cap)
	local room_data={
		ip=ip,guid=guid:ToString(),room_name=room_name,
		map=map,capacity=cap
	}
	Lobby:AddRoom(room_data)
end

function AWProtocolListener.OnLobbyChat( packet)
	local packet,bitstream=toPacket(packet)
	local msg = ""
	msg=BitStreamHelper.DeserializeString(bitstream,msg)
	MultiMenu:PrepareWndChatLogAddLine(msg)
	--server转发
	if AWProtocolListener.network:isServer() then
		AWProtocolListener.network:SendDataToGUID(bitstream,0,packet:getGUID(),true,false)
	end
end

function AWProtocolListener.OnQueryRoomInfo( packet )
	local packet,bitstream=toPacket(packet)
	local name = ""
	name = BitStreamHelper.DeserializeString(bitstream,name)
	Lobby:OnPlayerConnected( {guid=packet:getGUID(),name=name,type="t34",team=1} )
	AWProtocolListener.network:ReadyEventAddToRemoteWaitingList(0,packet:getGUID())
end

function AWProtocolListener.OnReceiveRoomInfo( packet )
	local packet,bitstream=toPacket(packet)
	local data_str = ""
	data_str = BitStreamHelper.DeserializeString(bitstream,data_str)
	-- parse lua string
	local data = eval(data_str)
	-- update system
	Lobby:OnReceiveRoomInfo(data)
	Lobby.join_request_timer=-1
	AWProtocolListener.network:ReadyEventAddToRemoteWaitingList(0,packet:getGUID())
end

function AWProtocolListener.OnLobbyJoin( packet )
	local packet,bitstream=toPacket(packet)
	local data_str = ""
	data_str = BitStreamHelper.DeserializeString(bitstream,data_str)
	local data = eval(data_str)
	Lobby:OnPlayerJoined( data.id,data.guid,data.name,data.type,data.team )
end

function AWProtocolListener.OnLobbyLeave( packet )
	local packet,bitstream=toPacket(packet)
	local guid = ""
	guid = BitStreamHelper.DeserializeString(bitstream,guid)
	Lobby:OnPlayerLeave( guid )
end

function AWProtocolListener.OnLobbyPlayerUpdate( packet )
	local packet,bitstream=toPacket(packet)
	local data_str = ""
	data_str = BitStreamHelper.DeserializeString(bitstream,data_str)
	local data = eval(data_str)
	Lobby:OnPlayerInfoUpdate(data)
	--server转发
	if AWProtocolListener.network:isServer() then
		AWProtocolListener.network:SendDataToGUID(bitstream,0,packet:getGUID(),true,false)
	end
end
-- data_str="{id=xxx,open=true/false}"
function AWProtocolListener.OnLobbyPlayerSlotChange( packet )
	local packet,bitstream=toPacket(packet)
	local data_str = ""
	data_str = BitStreamHelper.DeserializeString(bitstream,data_str)
	local data = eval(data_str)
	Lobby:OnPlayerSlotChange(data.id,data.open)
end
----------------------------------------
-- ready event
----------------------------------------

function AWProtocolListener.OnPlayerAllReady( packet )
	local packet=toPacket(packet)
	if AWProtocolListener.network:isServer() then
		Lobby:OnPlayerReady( packet:getGUIDString() )
		local bitstream = BitStreamHelper.CreateBitStream()
		BitStreamHelper.SerializeAsProtocolID(bitstream,AWProtocolListener.CustomProtocol.Lobby_PLAYER_READY)
		BitStreamHelper.SerializeString(bitstream,packet:getGUIDString())
		AWProtocolListener.network:SendDataToAll(bitstream)
	end
end

function AWProtocolListener.OnPlayerReady( packet )
	local packet,bitstream = toPacket(packet)
	local guid_str = ""
	guid_str = BitStreamHelper.DeserializeString(bitstream,guid_str)
	print(guid_str)
	Lobby:OnPlayerReady(guid_str)
end
----------------------------------------
AWProtocolListener.protocol_mapping={
	[ID_NEW_INCOMING_CONNECTION]="AWProtocolListener.OnIncommingNewConnection",
	[ID_CONNECTION_REQUEST_ACCEPTED]="AWProtocolListener.OnConnectionAccept",
	[ID_CONNECTION_LOST]="AWProtocolListener.OnDisconnect",
	[ID_DISCONNECTION_NOTIFICATION]="AWProtocolListener.OnDisconnect",
	[ID_ADVERTISE_SYSTEM]="AWProtocolListener.OnRoomBroadcast",

	[ID_CONNECTION_ATTEMPT_FAILED]="AWProtocolListener.OnConnectionFailed",
	[ID_INVALID_PASSWORD]="AWProtocolListener.OnConnectionFailed",
	[ID_NO_FREE_INCOMING_CONNECTIONS]="AWProtocolListener.OnConnectionFailed",
	[ID_IP_RECENTLY_CONNECTED]="AWProtocolListener.OnConnectionFailed",
	[ID_INCOMPATIBLE_PROTOCOL_VERSION]="AWProtocolListener.OnConnectionFailed",

	[ID_READY_EVENT_ALL_SET]="AWProtocolListener.OnPlayerAllReady",

	[AWProtocolListener.CustomProtocol.LOBBY_CHAT]="AWProtocolListener.OnLobbyChat",
	[AWProtocolListener.CustomProtocol.LOBBY_QUERY_ROOM]="AWProtocolListener.OnQueryRoomInfo",
	[AWProtocolListener.CustomProtocol.LOBBY_ROOM_INFO]="AWProtocolListener.OnReceiveRoomInfo",
	[AWProtocolListener.CustomProtocol.LOBBY_JOIN]="AWProtocolListener.OnLobbyJoin",
	[AWProtocolListener.CustomProtocol.LOBBY_LEAVE]="AWProtocolListener.OnLobbyLeave",
	[AWProtocolListener.CustomProtocol.LOBBY_PLAYER_UPDATE]="AWProtocolListener.OnLobbyPlayerUpdate",
	[AWProtocolListener.CustomProtocol.LOBBY_PLAYER_SLOT_CHANGE]="AWProtocolListener.OnLobbyPlayerSlotChange",
	[AWProtocolListener.CustomProtocol.Lobby_PLAYER_READY]="AWProtocolListener.OnPlayerReady",
}