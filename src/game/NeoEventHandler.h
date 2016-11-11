/*
 * NeoEventHandler.h
 *
 *  Created on: 2016年1月21日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOEVENTHANDLER_H_
#define SRC_GAME_NEOEVENTHANDLER_H_

#include <IEventReceiver.h>
#include <list>
class NeoEventHandler: public irr::IEventReceiver
{
public:
	NeoEventHandler();
	virtual ~NeoEventHandler();
	bool OnEvent(const irr::SEvent& event);
	void AddAdditionalEventHandler(irr::IEventReceiver*handler);
	void RemoveAddtionalEventHandler(irr::IEventReceiver*handler);
	void ClearAddtionalEventHandler();
protected:
	std::list<irr::IEventReceiver*>additional_receivers;
};

#endif /* SRC_GAME_NEOEVENTHANDLER_H_ */
