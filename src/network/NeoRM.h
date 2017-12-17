/*
 * NeoRM.h
 *
 *  Created on: 2017年11月9日
 *      Author: neo
 */

#ifndef SRC_NETWORK_NEORM_H_
#define SRC_NETWORK_NEORM_H_

#include <RakNet/ReplicaManager3.h>

namespace NeoGame
{
namespace network
{

class NeoConnetionRM: public RakNet::Connection_RM3
{
public:
	NeoConnetionRM(const RakNet::SystemAddress &_systemAddress,
			RakNet::RakNetGUID _guid);
	virtual RakNet::Replica3* AllocReplica(
			RakNet::BitStream* allocationIdBitstream,
			RakNet::ReplicaManager3*replicaManager);
};

class NeoRM: public RakNet::ReplicaManager3
{
public:
	NeoRM()
	{
	}
	virtual RakNet::Connection_RM3* AllocConnection(
			const RakNet::SystemAddress &systemAddress,
			RakNet::RakNetGUID rakNetGUID) const
	{
		return new NeoConnetionRM(systemAddress, rakNetGUID);
	}
	virtual void DeallocConnection(RakNet::Connection_RM3 *connection) const
	{
		delete connection;
	}
};
} /* namespace network */
} /* namespace NeoGame */

#endif /* SRC_NETWORK_NEORM_H_ */
