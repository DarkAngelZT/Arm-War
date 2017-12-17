/*
 * Package.h
 *
 *  Created on: 2017年11月7日
 *      Author: neo
 */

#ifndef SRC_NETWORK_PACKET_H_
#define SRC_NETWORK_PACKET_H_
#include <RakNet/RakNetTypes.h>
#include <RakNet/BitStream.h>
#include <string>
namespace NeoGame
{
namespace network
{

class Packet
{
public:
	Packet(RakNet::Packet*rakPacket);

	std::string getSenderIPAddress();
	int getSenderPort();
	std::string getGUIDString();
	RakNet::RakNetGUID getGUID();
	RakNet::BitStream& getBitStream()
	{
		return m_bitStream;
	}

//c++ only
	RakNet::Packet* getRawPacket();
private:
	RakNet::Packet* m_packet;
	RakNet::BitStream m_bitStream;
};

} /* namespace network */
} /* namespace NeoGame */

#endif /* SRC_NETWORK_PACKET_H_ */
