/*
 * NetworkedObject.h
 *
 *  Created on: 2017年11月10日
 *      Author: neo
 */

#ifndef SRC_NETWORK_NETWORKEDOBJECT_H_
#define SRC_NETWORK_NETWORKEDOBJECT_H_

#include <RakNet/ReplicaManager3.h>
#include <string>

namespace NeoGame
{
namespace network
{

class NetworkedObject: public RakNet::Replica3
{
public:
	NetworkedObject();
	NetworkedObject(const std::string&id,const std::string&type="common");
	virtual ~NetworkedObject();
	const std::string& getLuaIdentifier();
	void setLuaIdentifier(const std::string& luaIdentifier);
	void setInternalNetworkID(long id);
	//实现父类虚函数
	virtual void WriteAllocationID(RakNet::Connection_RM3*destConnection,
			RakNet::BitStream *allocationIdBitstream) const;
	virtual void DeallocReplica(RakNet::Connection_RM3 *sourceConnection);
	virtual RakNet::RM3ConstructionState QueryConstruction(
			RakNet::Connection_RM3 *destinationConnection,
			RakNet::ReplicaManager3 *replicaManager3);
	virtual bool QueryRemoteConstruction(
			RakNet::Connection_RM3 *sourceConnection);
	virtual void SerializeConstruction(RakNet::BitStream *constructionBitstream,
			RakNet::Connection_RM3 *destinationConnection);
	virtual bool DeserializeConstruction(
			RakNet::BitStream *constructionBitstream,
			RakNet::Connection_RM3 *sourceConnection);
	virtual RakNet::RM3QuerySerializationResult QuerySerialization(RakNet::Connection_RM3 *destinationConnection);
	virtual void SerializeDestruction(RakNet::BitStream *destructionBitstream,
			RakNet::Connection_RM3 *destinationConnection);
	virtual bool DeserializeDestruction(RakNet::BitStream *destructionBitstream,
			RakNet::Connection_RM3 *sourceConnection);
	virtual RakNet::RM3SerializationResult Serialize(
			RakNet::SerializeParameters *serializeParameters);
	virtual void Deserialize(
			RakNet::DeserializeParameters *deserializeParameters);
	virtual RakNet::RM3ActionOnPopConnection QueryActionOnPopConnection(
			RakNet::Connection_RM3 *droppedConnection) const;

	virtual void PostDeserializeConstruction(
			RakNet::BitStream *constructionBitstream,
			RakNet::Connection_RM3 *destinationConnection);
//---------
	bool isStatic() const;
	void setStatic(bool _static);
	std::string& getObjType();
	void setObjType(const std::string& objType);

private:
	std::string luaIdentifier;
	std::string obj_type;
	bool m_static;
};

} /* namespace network */
} /* namespace NeoGame */

#endif /* SRC_NETWORK_NETWORKEDOBJECT_H_ */
