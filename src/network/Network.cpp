/*
 * NetWork.cpp
 *
 *  Created on: 2017年10月30日
 *      Author: neo
 */

#include "Network.h"
#include "RakNet/GetTime.h"
#include "../script/NeoScript.h"
#include "NeoRM.h"
#include "RakNet/PacketLogger.h"

namespace NeoGame
{

Network* Network::_instance = NULL;
Network::Network() :
		m_rakPeer(0), m_broadcast_listener(0), m_networkIDManager(0), m_replicaManager(
				0), m_readyEvent(0), m_server(false)
{
}

Network* Network::getInstance()
{
	if (!_instance)
	{
		_instance = new Network;
	}
	return _instance;
}

void Network::Destroy()
{
	if (_instance)
	{
		delete _instance;
		_instance = NULL;
	}
}

void Network::Init()
{
	CleanUp();
	m_rakPeer = RakNet::RakPeerInterface::GetInstance();
	m_networkIDManager = RakNet::NetworkIDManager::GetInstance();
	m_replicaManager = new network::NeoRM;
	m_readyEvent = RakNet::ReadyEvent::GetInstance();
	m_replicaManager->SetNetworkIDManager(m_networkIDManager);

	m_rakPeer->AttachPlugin(m_readyEvent);
	m_rakPeer->AttachPlugin(m_replicaManager);
}

void Network::CleanUp()
{
	if (m_rakPeer)
	{
		ShutDown();
		RakNet::RakPeerInterface::DestroyInstance(m_rakPeer);
		RakNet::NetworkIDManager::DestroyInstance(m_networkIDManager);
		RakNet::ReadyEvent::DestroyInstance(m_readyEvent);
		delete m_replicaManager;
		m_rakPeer = NULL;
		m_networkIDManager = NULL;
		m_replicaManager = NULL;
		for (auto& functions : m_protocol_listeners)
		{
			functions.second.clear();
		}
		m_protocol_listeners.clear();
	}
	m_server = false;
	if (m_broadcast_listener)
	{
		m_broadcast_listener->Shutdown(0, 0);
		RakNet::RakPeerInterface::DestroyInstance(m_broadcast_listener);
		m_broadcast_listener = NULL;
	}
}

std::string Network::BaseProtocolIDToString(int p)
{
	return std::string(PacketLogger::BaseIDTOString(p));
}

void Network::setMaxIncomingConnection(int max_count)
{
	if (m_rakPeer && m_server)
	{
		m_rakPeer->SetMaximumIncomingConnections(
				static_cast<unsigned short>(max_count));
	}
}

bool Network::setReadyEvent(int id, bool ready)
{
	if (m_readyEvent)
	{
		return m_readyEvent->SetEvent(id, ready);
	}
	return false;
}

void Network::ForceCompleteReadyEvent(int id)
{
	if (m_readyEvent)
	{
		m_readyEvent->ForceCompletion(id);
	}
}

bool Network::isReadyEventSet(int id)
{
	if (m_readyEvent)
	{
		return m_readyEvent->IsEventSet(id);
	}
	return false;
}

bool Network::HasReadyEvent(int id)
{
	if (m_readyEvent)
	{
		return m_readyEvent->HasEvent(id);
	}
	return false;
}

void Network::setReadyEventSendChannel(int channel)
{
	if (m_readyEvent)
	{
		m_readyEvent->SetSendChannel(static_cast<unsigned char>(channel));
	}
}

bool Network::DeleteReadyEvent(int eventId)
{
	if (m_readyEvent)
	{
		return m_readyEvent->DeleteEvent(eventId);
	}
	return false;
}

bool Network::isReadyEventCompleted(int eid)
{
	if (m_readyEvent)
	{
		return m_readyEvent->IsEventCompleted(eid);
	}
	return false;
}

bool Network::ReadyEventAddToRemoteWaitingList(int eid, RakNet::RakNetGUID guid)
{
	if (m_readyEvent)
	{
		return m_readyEvent->AddToWaitList(eid, guid);
	}
	return false;
}

bool Network::ReadyEventRemoveFromRemoteList(int eid, RakNet::RakNetGUID guid)
{
	if (m_readyEvent)
	{
		return m_readyEvent->RemoveFromWaitList(eid, guid);
	}
	return false;
}

bool Network::ReceivePacket(RakNet::RakPeerInterface* peer)
{
	if (peer && peer->IsActive())
	{
		RakNet::Packet* packet;
		NeoScript* script = NeoScript::getInstance();
		for (packet = peer->Receive(); packet;
				peer->DeallocatePacket(packet), packet = peer->Receive())
		{
			if (m_protocol_listeners.count(packet->data[0]) > 0)
			{
				NeoGame::network::Packet p(packet);
				int protocol = packet->data[0];
				for (auto const &func : m_protocol_listeners[protocol])
					script->ExecuteNetworkProtocolListenerFunction(func, p);
			}
			if (!peer->IsActive())
			{
				//如果peer在处理完所有packet之前就被shutdown了，那么会引起段错误
				//所以必须加上这个判断
				break;
			}
		}
		return true;
	}
	return false;
}

void Network::Update()
{
	bool r1 = ReceivePacket(m_rakPeer);
	bool r2 = ReceivePacket(m_broadcast_listener);
	//运行lua脚本中的post_update
	NeoScript* script = NeoScript::getInstance();
	if (r1 || r2)
	{
		script->ExecuteScriptedFunction("Network.Update");
	}
}

void Network::AddProtocolListener(int protocol, const std::string& luaFunction)
{
	if (m_protocol_listeners.count(protocol) == 0)
	{
		m_protocol_listeners[protocol] = std::list<std::string>();
	}
	m_protocol_listeners[protocol].push_back(luaFunction);
}

void Network::RemoveProtocolListener(int protocol,
		const std::string& luaFunction)
{
	if (m_protocol_listeners.count(protocol) > 0)
	{
		m_protocol_listeners[protocol].remove(luaFunction);
	}
}

int Network::getNetworkTimeMs()
{
	RakNet::TimeMS t = RakNet::GetTimeMS();
	int time = static_cast<int>(t);
	return time;
}

void Network::Ping(const std::string& address, int port)
{
	if (m_rakPeer)
	{
		m_rakPeer->Ping(address.data(), static_cast<unsigned short>(port),
				true);
	}
}

void Network::SendUDPLanBroadcast(RakNet::BitStream* bitstream, int port,
		bool autoDecallocatePacket)
{
	if (m_rakPeer)
	{
		m_rakPeer->AdvertiseSystem("255.255.255.255",
				static_cast<unsigned short>(port), bitstream->GetData(),
				static_cast<int>(bitstream->GetNumberOfBytesUsed()));
	}
	if (autoDecallocatePacket)
	{
		delete bitstream;
	}
}

void Network::SendDataToGUID(RakNet::BitStream* bitstream, int orderingChannel,
		const RakNet::RakNetGUID& guid, bool broadcast,
		bool autoDecallocatePacket)
{
	if (m_rakPeer)
	{
		m_rakPeer->Send(bitstream, MEDIUM_PRIORITY, RELIABLE_ORDERED,
				static_cast<char>(orderingChannel), guid, broadcast);
	}
	if (autoDecallocatePacket)
	{
		delete bitstream;
	}
}

void Network::SendDataToAddress(RakNet::BitStream* bitstream,
		int orderingChannel, const RakNet::SystemAddress& addr, bool broadcast,
		bool autoDecallocatePacket)
{
	if (m_rakPeer)
	{
		m_rakPeer->Send(bitstream, MEDIUM_PRIORITY, RELIABLE_ORDERED,
				static_cast<char>(orderingChannel), addr, broadcast);
	}
	if (autoDecallocatePacket)
	{
		delete bitstream;
	}
}

void Network::SendDataToAll(RakNet::BitStream* bitstream, int orderingChannel)
{
	SendDataToGUID(bitstream, orderingChannel);
}

bool Network::RegisterNetworkedObject(network::NetworkedObject* object)
{
	if (m_networkedObjects.count(object->getGuid()) > 0)
		return false;
	else
	{
		m_networkedObjects[object->getGuid()] = object;
		return true;
	}
}

void Network::DestroyNetworkedObject(network::NetworkedObject* object)
{
	if (!object)
		return;
	if (m_networkedObjects.count(object->getGuid()) > 0)
	{
		m_networkedObjects.erase(object->getGuid());
	}
	delete object;
}

void Network::StartClient(const std::string& addr, int port)
{
	m_server = false;
	RakNet::SocketDescriptor sd;
	sd.socketFamily = AF_INET;
	m_rakPeer->Startup(1, &sd, 1);
	m_rakPeer->Connect(addr.data(), static_cast<unsigned short>(port), 0, 0);
}

void Network::StartServer(int port, int max_connects)
{
	m_server = true;

	RakNet::SocketDescriptor sd(static_cast<unsigned short>(port), 0);
	sd.socketFamily = AF_INET;
	m_rakPeer->Startup(static_cast<unsigned int>(max_connects), &sd, 1);
	m_rakPeer->SetMaximumIncomingConnections(
			static_cast<unsigned int>(max_connects));
}

void Network::ShutDown()
{
	if (m_rakPeer)
	{
		m_rakPeer->Shutdown(100);
		m_replicaManager->Clear();
		m_networkIDManager->Clear();
	}
}

void Network::StartSynchronizeObject(network::NetworkedObject* object)
{
	if (m_replicaManager)
	{
		m_replicaManager->Reference(object);
	}
}

NetworkIDManager* Network::getNetworkIdManager()
{
	return m_networkIDManager;
}

ReplicaManager3* Network::getReplicaManager()
{
	return m_replicaManager;
}

void Network::KickClient(const RakNetGUID& guid)
{
	if (m_rakPeer)
	{
		m_rakPeer->CloseConnection(guid, true);
	}
}

const RakNetGUID Network::getMyGUID()
{
	if (m_rakPeer)
	{
		return m_rakPeer->GetMyGUID();
	}
	else
		return RakNet::UNASSIGNED_RAKNET_GUID;
}

void Network::EnableUDPBroadcastListening(int port)
{
	if (!m_broadcast_listener)
	{
		m_broadcast_listener = RakNet::RakPeerInterface::GetInstance();
	}
	m_broadcast_listener->Shutdown(0, 0);
	RakNet::SocketDescriptor sd(static_cast<unsigned short>(port), 0);
	sd.socketFamily = AF_INET;
	m_broadcast_listener->Startup(static_cast<unsigned int>(1), &sd, 1);
}

void Network::DisableUDPBroadcastListening()
{
	if (m_broadcast_listener)
	{
		m_broadcast_listener->Shutdown(0, 0);
	}
}

Network::~Network()
{
	CleanUp();
}
network::NetworkedObject* Network::CreateNetworkedObject(
		const RakNet::RakNetGUID& guid)
{
	if (m_networkedObjects.count(guid) == 0)
	{
		network::NetworkedObject* object = new network::NetworkedObject(guid);
		m_networkedObjects[guid] = object;
		return object;
	}
	return NULL;
}

network::NetworkedObject* Network::CreateNetworkedObject(
		const std::string& guid_str)
{
	RakNet::RakNetGUID guid;
	guid.FromString(guid_str.data());
	return CreateNetworkedObject(guid);
}

network::NetworkedObject* Network::CreateNetworkedObject()
{
	return new network::NetworkedObject();
}

network::NetworkedObject* Network::getNetWorkedObject(
		const RakNet::RakNetGUID& guid)
{
	if (m_networkedObjects.count(guid) > 0)
	{
		return m_networkedObjects[guid];
	}
	else
		return NULL;
}

network::NetworkedObject* Network::getNetWorkedObject(
		const std::string& guid_str)
{
	RakNet::RakNetGUID guid;
	guid.FromString(guid_str.data());
	return getNetWorkedObject(guid);
}

} /* namespace NeoGame */

