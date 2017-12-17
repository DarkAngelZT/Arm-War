/*
 * NetworkedObject.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: neo
 */

#include "Network.h"
#include "NetworkedObject.h"
#include "../script/NeoScript.h"
#include <vector>

namespace NeoGame
{
namespace network
{

NetworkedObject::NetworkedObject() :
		m_static(false)
{

}

NeoGame::network::NetworkedObject::NetworkedObject(
		const RakNet::RakNetGUID& guid) :
		m_guid(guid), m_static(false)
{
}

NetworkedObject::~NetworkedObject()
{
	NeoScript::getInstance()->ExecuteScriptedFunction("Network.OnDestroy",
			std::vector<std::string>
			{ luaIdentifier });
}

const std::string& NetworkedObject::getLuaIdentifier()
{
	return luaIdentifier;
}

void NetworkedObject::setLuaIdentifier(const std::string& luaIdentifier)
{
	this->luaIdentifier = luaIdentifier;
}

bool NetworkedObject::isStatic() const
{
	return m_static;
}

void NetworkedObject::setStatic(bool _static)
{
	m_static = _static;
	if (m_static)
	{
		SetNetworkIDManager(Network::getInstance()->getNetworkIdManager());
	}
}

RakNet::RakNetGUID& NeoGame::network::NetworkedObject::getGuid()
{
	return m_guid;
}

void NeoGame::network::NetworkedObject::setGuid(const RakNet::RakNetGUID& guid)
{
	this->m_guid = guid;
}

void NeoGame::network::NetworkedObject::WriteAllocationID(
		RakNet::Connection_RM3* destConnection,
		RakNet::BitStream* allocationIdBitstream) const
{
}

void NeoGame::network::NetworkedObject::DeallocReplica(
		RakNet::Connection_RM3* sourceConnection)
{
	Network::getInstance()->DestroyNetworkedObject(this);
}

RakNet::RM3ConstructionState NeoGame::network::NetworkedObject::QueryConstruction(
		RakNet::Connection_RM3* destinationConnection,
		RakNet::ReplicaManager3* replicaManager3)
{
	//no need to send construct if this is a static object(already exist on both sides)
	if (m_static)
	{
		return RakNet::RM3CS_ALREADY_EXISTS_REMOTELY;
	}
	else
		return QueryConstruction_ClientConstruction(destinationConnection,
				Network::getInstance()->isServer());
}

bool NeoGame::network::NetworkedObject::QueryRemoteConstruction(
		RakNet::Connection_RM3* sourceConnection)
{
	return QueryRemoteConstruction_ClientConstruction(sourceConnection,
			Network::getInstance()->isServer());
}

void NeoGame::network::NetworkedObject::SerializeConstruction(
		RakNet::BitStream* constructionBitstream,
		RakNet::Connection_RM3* destinationConnection)
{
	NeoScript::getInstance()->ExecuteNetworkedObjectCallback(
			"Network.OnSerializeConstruct", luaIdentifier,
			constructionBitstream);
}

bool NeoGame::network::NetworkedObject::DeserializeConstruction(
		RakNet::BitStream* constructionBitstream,
		RakNet::Connection_RM3* sourceConnection)
{
	NeoScript::getInstance()->ExecuteNetworkedObjectCallback(
			"Network.OnDeserializeConstruction", luaIdentifier,
			constructionBitstream);
	return true;
}

RakNet::RM3QuerySerializationResult NeoGame::network::NetworkedObject::QuerySerialization(
		RakNet::Connection_RM3* destinationConnection)
{
	bool isServer = Network::getInstance()->isServer();
	if (m_static && !isServer)
	{
		return RakNet::RM3QSR_NEVER_CALL_SERIALIZE;
	}
	else
		return QuerySerialization_ClientSerializable(destinationConnection,
				isServer);
}

void NeoGame::network::NetworkedObject::SerializeDestruction(
		RakNet::BitStream* destructionBitstream,
		RakNet::Connection_RM3* destinationConnection)
{
}

bool NeoGame::network::NetworkedObject::DeserializeDestruction(
		RakNet::BitStream* destructionBitstream,
		RakNet::Connection_RM3* sourceConnection)
{
	return true;
}

RakNet::RM3SerializationResult NeoGame::network::NetworkedObject::Serialize(
		RakNet::SerializeParameters* serializeParameters)
{
	NeoScript::getInstance()->ExecuteNetworkedObjectCallback(
			"Network.OnSerialize", luaIdentifier,
			&serializeParameters->outputBitstream[0]);
	return RakNet::RM3SR_BROADCAST_IDENTICALLY;
}

void NeoGame::network::NetworkedObject::Deserialize(
		RakNet::DeserializeParameters* deserializeParameters)
{
	NeoScript::getInstance()->ExecuteNetworkedObjectCallback(
			"Network.OnDeserialize", luaIdentifier,
			&deserializeParameters->serializationBitstream[0]);
}

RakNet::RM3ActionOnPopConnection NeoGame::network::NetworkedObject::QueryActionOnPopConnection(
		RakNet::Connection_RM3* droppedConnection) const
{
	return QueryActionOnPopConnection_Server(droppedConnection);
}

void NeoGame::network::NetworkedObject::PostDeserializeConstruction(
		RakNet::BitStream* constructionBitstream,
		RakNet::Connection_RM3* destinationConnection)
{
	NeoScript::getInstance()->ExecuteNetworkedObjectCallback(
			"Network.OnPostDeserializeConstruct", luaIdentifier,
			constructionBitstream);
}

} /* namespace network */
} /* namespace NeoGame */
