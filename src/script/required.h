/*
 * required.h
 *
 *  Created on: 2016年1月24日
 *      Author: neo
 */
#include <irrlicht.h>
#include "../game/Application.h"
#include "../game/NeoGameLogic.h"
#include "../game/NeoTrigger.h"
#include "../game/NeoEvent.h"
#include "../game/GameObject.h"
#include "../game/object/SimpleTankTrackObject.h"
#include "../game/NeoScene.h"
#include "../Editor/NeoEditor.h"
#include "../game/object/StandardTankBodyObject.h"
#include "../Utilities/LuaHelper.h"
#include "../network/Network.h"
#include "../network/Packet.h"
#include "../ThirdParty/RakNet/MessageIdentifiers.h"

namespace NeoGame
{
namespace network
{
RakNet::BitStream* CreateBitStream();
void DestroyBitStream(RakNet::BitStream* stream);
//serialize
void SerializeVector3(RakNet::BitStream* bitStream,
		const irr::core::vector3d<float>&vector3);
void SerializeFloat(RakNet::BitStream* bitStream, const float& f);
void SerializeInt(RakNet::BitStream* bitStream, const int&i);
void SerializeBool(RakNet::BitStream* bitStream, const bool&b);
void SerializeAsProtocolID(RakNet::BitStream* bitStream, const int&p);
void SerializeAsByte(RakNet::BitStream* bitStream, const int&i);
void SerializeString(RakNet::BitStream* bitStream, const std::string&str);
void SerializeGUID(RakNet::BitStream* bitStream,
		const RakNet::RakNetGUID& guid);
//deserialize
void DeserializeVector3(RakNet::BitStream* bitStream,
		irr::core::vector3d<float>&out_vector3);
void DeserializeFloat(RakNet::BitStream* bitStream, float& f);
void DeserializeInt(RakNet::BitStream* bitStream, int&i);
void DeserializeBool(RakNet::BitStream* bitStream, bool&b);
void DeserializeProtocolID(RakNet::BitStream* bitStream, int&p);
void DeserializeByte(RakNet::BitStream* bitStream, int&i);
void DeserializeString(RakNet::BitStream* bitStream, std::string&str);
void DeserializeGUID(RakNet::BitStream* bitStream, RakNet::RakNetGUID& guid);
}/* namespace network */
}/* namespace NeoGame */
