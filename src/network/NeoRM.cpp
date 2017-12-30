/*
 * NeoRM.cpp
 *
 *  Created on: 2017年11月9日
 *      Author: neo
 */

#include "NeoRM.h"
#include "Network.h"
#include "../script/NeoScript.h"
#include <vector>

namespace NeoGame
{
namespace network
{

NeoConnetionRM::NeoConnetionRM(const RakNet::SystemAddress &_systemAddress,
		RakNet::RakNetGUID _guid) :
		Connection_RM3(_systemAddress, _guid)
{
}

RakNet::Replica3* NeoConnetionRM::AllocReplica(
		RakNet::BitStream* allocationIdBitstream,
		RakNet::ReplicaManager3* replicaManager)
{
	RakNet::RakString id, obj_type;
	allocationIdBitstream->Read(id);
	allocationIdBitstream->Read(obj_type);
	NeoScript::getInstance()->ExecuteScriptedFunction("Network.OnRemoteConstruct",
			std::vector<std::string>
			{ id.C_String() , obj_type.C_String() });
	return Network::getInstance()->CreateNetworkedObject(id.C_String(), obj_type.C_String());
}

} /* namespace network */
} /* namespace NeoGame */
