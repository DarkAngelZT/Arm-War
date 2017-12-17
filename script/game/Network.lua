require(DIR_SCRIPT.."game/network/ArmWarProtocolListener")

Network={
	protocolListener=AWProtocolListener,
	post_update={},
	network=NeoGame.Network:getInstance(),
	m_current_time_ms=0,
	m_delta_time_ms=0,
}

BitStreamHelper=NeoGame.network

function Network.Update()
	local t = Network.network:getNetworkTimeMs()
	if Network.m_current_time_ms == 0 then
		Network.m_current_time_ms = t
		return
	end
	Network.m_delta_time_ms = t - Network.m_current_time_ms
	Network.m_current_time_ms = t
	for o,v in pairs(Network.post_update) do
		if v.enabled then
			o:Update(Network.m_current_time_ms,Network.m_delta_time_ms)
		end
	end
end

function Network:AddPostUpdateObj( obj )
	if self.post_update[func] then
		return
	end
	self.post_update[obj]={enabled=true}
end

function Network:RemovePostUpdateObj( obj )
	for k,v in pairs(self.post_update) do
		if k == obj then
			self.post_update[k]=nil
			break
		end
	end
end

function Network:EnablePostUpdateFunction( obj, enable )
	if enable == nil then
		enable=true
	end
	if self.post_update[obj] then
		self.post_update[obj].enabled=enable
	end
end

--销毁对象回调
function Network.OnDestroy( id )
	-- body
end

--同步数据上传回调
function Network.OnSerialize( id, bitstream )
	-- body
end

--同步数据处理回调
function Network.OnDeserialize( id, bitstream )
end

--同步对象创建回调
function Network.OnSerializeConstruct( id, bitstream )
	-- body
end

--the callback after deserilizeConstruct
function Network.DeserializeConstruction( id, bitstream )
	-- body
end
--the callback after deserilizeConstruct
function Network.OnPostDeserializeConstruct( id, bitstream )
	-- body
end

Network.protocolListener:Init()