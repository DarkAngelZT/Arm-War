/*
 * NeoEventHandler.h
 *
 *  Created on: 2016年1月21日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOEVENTHANDLER_H_
#define SRC_GAME_NEOEVENTHANDLER_H_

#include <IEventReceiver.h>

class NeoEventHandler: public irr::IEventReceiver
{
public:
	NeoEventHandler();
	virtual ~NeoEventHandler();
	bool OnEvent(const irr::SEvent& event);
};

#endif /* SRC_GAME_NEOEVENTHANDLER_H_ */
