require(DIR_SCRIPT.."game/network/ArmWarProtocolListener")
require(DIR_SCRIPT.."game/network/SynchronizedObject")
require(DIR_SCRIPT.."game/network/SynchronizedPlayer")

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
	if Synchronizer.m_enable_sync and Synchronizer.objects[id] then
		Synchronizer.objects[id]:OnDestroy()
	end
end

--接收远程主机信息，下载并创建对象
function Network.OnRemoteConstruct( id,obj_type )
	if obj_type == "common" then
		SynchronizedObject.new(id)
	elseif obj_type == "player" then
		SynchronizedPlayer.new(id)
	end
end

--同步数据上传回调
function Network.OnSerialize( id, bitstream )
	if Synchronizer.m_enable_sync and Synchronizer.objects[id] then
		Synchronizer.objects[id]:OnSerialize(bitstream)
	end
end

--同步数据处理回调
function Network.OnDeserialize( id, bitstream )
	if Synchronizer.m_enable_sync and Synchronizer.objects[id] then
		Synchronizer.objects[id]:OnDeserialize(bitstream)
	end
end

--同步对象创建回调
function Network.OnSerializeConstruct( id, bitstream )
	if Synchronizer.objects[id] then
		Synchronizer.objects[id]:OnSerializeConstruct(bitstream)
	end
end

--the callback after deserilizeConstruct
function Network.OnDeserializeConstruction( id, bitstream )
	if Synchronizer.objects[id] then
		Synchronizer.objects[id]:OnDeserializeConstruction(bitstream)
	end
end
--the callback after deserilizeConstruct
function Network.OnPostDeserializeConstruct( id, bitstream )
	if Synchronizer.objects[id] then
		Synchronizer.objects[id]:OnPostDeserializeConstruct(bitstream)
	end
end