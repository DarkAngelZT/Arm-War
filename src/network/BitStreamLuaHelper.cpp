/*
 * BitStreamLuaHelper.cpp
 *
 *  Created on: 2017年11月8日
 *      Author: neo
 *  Function here are port for lua to serialize packet data,
 *  because tolua doesn't have good support on template functions
 *  So we only export bitstream type without any member functions.
 *  And provide extra function for lua script to use bitstream for common data types
 */
#include <RakNet/BitStream.h>
#include <irrlicht.h>
#include <string>
namespace NeoGame
{
namespace network
{
RakNet::BitStream* CreateBitStream(){
	return new RakNet::BitStream;
}
void DestroyBitStream(RakNet::BitStream* stream){
	delete stream;
}
//serilize
void SerializeVector3(RakNet::BitStream* bitStream,
		const irr::core::vector3df&vector3)
{
	bitStream->Write(vector3);
}
void SerializeFloat(RakNet::BitStream* bitStream, const float& f)
{
	bitStream->Write(f);
}
void SerializeInt(RakNet::BitStream* bitStream, const int&i)
{
	bitStream->Write(i);
}
void SerializeBool(RakNet::BitStream* bitStream, const bool&b)
{
	bitStream->Write(b);
}
void SerializeAsProtocolID(RakNet::BitStream* bitStream, const int&p)
{
	bitStream->Write((RakNet::MessageID) p);
}
void SerializeAsByte(RakNet::BitStream* bitStream, const int&i)
{
	SerializeAsProtocolID(bitStream, i);
}
void SerializeString(RakNet::BitStream* bitStream, const std::string&str)
{
	RakNet::RakString rakStr(str.data());
	bitStream->Write(rakStr);
}
void SerializeGUID(RakNet::BitStream* bitStream,const RakNet::RakNetGUID& guid)
{
	bitStream->Write(guid);
}
//deserilize
void DeserializeVector3(RakNet::BitStream* bitStream,
		irr::core::vector3df&out_vector3)
{
	bitStream->Read(out_vector3);
}
void DeserializeFloat(RakNet::BitStream* bitStream, float& f)
{
	bitStream->Read(f);
}
void DeserializeInt(RakNet::BitStream* bitStream, int&i)
{
	bitStream->Read(i);
}
void DeserializeBool(RakNet::BitStream* bitStream, bool&b)
{
	bitStream->Read(b);
}
void DeserializeProtocolID(RakNet::BitStream* bitStream, int&p)
{
	RakNet::MessageID protocolID;
	bitStream->Read(protocolID);
	p = protocolID;
}
void DeserializeByte(RakNet::BitStream* bitStream, int&i)
{
	DeserializeProtocolID(bitStream, i);
}
void DeserializeString(RakNet::BitStream* bitStream, std::string&str)
{
	RakNet::RakString rakStr;
	bitStream->Read(rakStr);
	str = rakStr.C_String();
}
void DeserializeGUID(RakNet::BitStream* bitStream,RakNet::RakNetGUID& guid)
{
	bitStream->Read(guid);
}
}/* namespace network */
}/* namespace NeoGame */
