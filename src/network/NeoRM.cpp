/*
 * NeoRM.cpp
 *
 *  Created on: 2017年11月9日
 *      Author: neo
 */

#include "NeoRM.h"
#include "Network.h"

namespace NeoGame
{
namespace network
{

NeoConnetionRM::NeoConnetionRM(const RakNet::SystemAddress &_systemAddress, RakNet::RakNetGUID _guid):Connection_RM3(_systemAddress,_guid)
{
}

RakNet::Replica3* NeoConnetionRM::AllocReplica(RakNet::BitStream* allocationIdBitstream,
		RakNet::ReplicaManager3* replicaManager)
{
	return Network::getInstance()->CreateNetworkedObject();
}

} /* namespace network */
} /* namespace NeoGame */
