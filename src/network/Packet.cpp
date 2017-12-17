/*
 * Package.cpp
 *
 *  Created on: 2017年11月7日
 *      Author: neo
 */

#include "Packet.h"

namespace NeoGame
{
namespace network
{

Packet::Packet(RakNet::Packet*rakPacket) :
		m_packet(rakPacket), m_bitStream(rakPacket->data, rakPacket->length,
				false)
{
}

std::string Packet::getGUIDString()
{
	return std::string(m_packet->guid.ToString());
}

RakNet::Packet* Packet::getRawPacket()
{
	return m_packet;
}

std::string Packet::getSenderIPAddress()
{
	return m_packet->systemAddress.ToString(false);
}

int Packet::getSenderPort()
{
	return m_packet->systemAddress.GetPort();
}

} /* namespace network */
} /* namespace NeoGame */

RakNet::RakNetGUID NeoGame::network::Packet::getGUID()
{
	return m_packet->guid;
}
