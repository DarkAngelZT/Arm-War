/*
 * NetWork.h
 *
 *  Created on: 2017年10月30日
 *      Author: neo
 */

#ifndef SRC_NETWORK_NETWORK_H_
#define SRC_NETWORK_NETWORK_H_
#include "RakNet/ReplicaManager3.h"
#include "RakNet/NetworkIDManager.h"
#include "RakNet/RakPeerInterface.h"
#include "RakNet/ReadyEvent.h"
#include <unordered_map>
#include <list>
#include "NetworkedObject.h"
#include "game/SingletonMacro.h"

using namespace RakNet;

namespace NeoGame
{

class Network
{
SINGLETON_HEADER(Network)
public:
	void Init();
	void CleanUp();
	void Update();
	bool StartClient(const std::string& addr, int port);
	bool StartServer(int port, int max_connects = 10);
	void setMaxIncomingConnection(int max_count);
	//enable to receive udp broadcast msg from port
	//(only one port is allowed at a time, call this again will override elder one)
	void EnableUDPBroadcastListening(int port);
	void DisableUDPBroadcastListening();
	void KickClient(const RakNetGUID& guid);
	void ShutDown();
	void SendUDPLanBroadcast(RakNet::BitStream* bitstream, int port,
			bool autoDecallocatePacket = true);
	void SendDataToGUID(RakNet::BitStream* bitstream, int orderingChannel = 0,
			const RakNet::RakNetGUID&guid = UNASSIGNED_RAKNET_GUID,
			bool braodcast = true, bool autoDecallocatePacket = true);
	void SendDataToAddress(RakNet::BitStream* bitstream,
			int orderingChannel = 0, const RakNet::SystemAddress&addr =
					UNASSIGNED_SYSTEM_ADDRESS, bool braodcast = true,
			bool autoDecallocatePacket = true);
	void SendDataToAll(RakNet::BitStream* bitstream, int orderingChannel = 0);
	void Ping(const std::string&address, int port);
	network::NetworkedObject* CreateNetworkedObject(const std::string& id,
			const std::string& obj_type = "common");
	/*create a empty networked object, attention this object is not registered,
	 you have to register it with registerNetworkedObject() after set its lua id*/
	network::NetworkedObject* CreateNetworkedObject();
	network::NetworkedObject* getNetWorkedObject(const std::string& guid);
	void DestroyNetworkedObject(network::NetworkedObject*object);
	//return whether register succeed
	bool RegisterNetworkedObject(network::NetworkedObject*object);
	void AddProtocolListener(int protocol, const std::string& luaFunction);
	void RemoveProtocolListener(int protocol, const std::string& luaFunction);
	void StartSynchronizeObject(network::NetworkedObject* object);
	int getNetworkTimeMs();
	void setSynchronizeInterval(int timeMs);
	const RakNetGUID getMyGUID();

	bool setReadyEvent(int id, bool ready);
	void ForceCompleteReadyEvent(int id);
	bool isReadyEventSet(int id);
	bool isReadyEventCompleted(int eid);
	bool HasReadyEvent(int id);
	void setReadyEventSendChannel(int channel);
	bool DeleteReadyEvent(int eventId);
	bool ReadyEventAddToRemoteWaitingList(int eid, RakNet::RakNetGUID guid);
	bool ReadyEventRemoveFromRemoteList(int eid, RakNet::RakNetGUID guid);

	std::string BaseProtocolIDToString(int p);

	bool isServer() const
	{
		return m_server;
	}

	NetworkIDManager* getNetworkIdManager();
	ReplicaManager3* getReplicaManager();

protected:
	Network();
	virtual ~Network();
	struct GuidHasher
	{
		std::size_t operator()(const RakNet::RakNetGUID& g) const
		{
			return std::hash<uint64_t>()(g.g);
		}
	};
	bool ReceivePacket(RakNet::RakPeerInterface* peer);
	std::string StartupResultToString(RakNet::StartupResult);
	RakPeerInterface* m_rakPeer;
	RakPeerInterface* m_broadcast_listener;
	NetworkIDManager* m_networkIDManager;
	ReplicaManager3* m_replicaManager;
	std::unordered_map<int, std::list<std::string>> m_protocol_listeners;
	std::unordered_map<std::string, network::NetworkedObject*> m_networkedObjects;
	ReadyEvent* m_readyEvent;
	bool m_server;
};

} /* namespace NeoGame */

#endif /* SRC_NETWORK_NETWORK_H_ */
