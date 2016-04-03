/*
 * NeoEvent.cpp
 *
 *  Created on: 2016年1月25日
 *      Author: neo
 */

#include "NeoEvent.h"
NeoEvent::NeoEvent()
{
	// TODO 自动生成的构造函数存根
}

NeoEvent::~NeoEvent()
{
	// TODO 自动生成的析构函数存根
	data.clear();
}

std::string NeoEvent::getData(int position)const
{
	return data[position];
}

int NeoEvent::getTriggerId() const
{
	return nEventId;
}
