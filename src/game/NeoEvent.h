/*
 * NeoEvent.h
 *
 *  Created on: 2016年1月25日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOEVENT_H_
#define SRC_GAME_NEOEVENT_H_
#include<vector>
#include <string>
/*
 *
 */
class NeoEvent
{
public:
	NeoEvent();
	virtual ~NeoEvent();
	std::string getData(int position)const;
	int getTriggerId()const;
	int nEventId;
	std::vector<std::string>data;
};

#endif /* SRC_GAME_NEOEVENT_H_ */
