/*
 * NeoGameLogic.cpp
 *
 *  Created on: 2016年1月21日
 *      Author: neo
 */

#include "stdafx.h"
#include "NeoGameLogic.h"
#include "NeoEventHandler.h"

NeoGameLogic*NeoGameLogic::_instance = NULL;
NeoGameLogic::NeoGameLogic()
{
	// TODO 自动生成的构造函数存根

}

void NeoGameLogic::TriggerEvent(int eid, int argc, ...)
{
	for (std::set<NeoTrigger*>::iterator iter = list_triggers.begin();
			iter != list_triggers.end(); iter++)
	{
		if ((*iter)->isAlive() && !(*iter)->isDisabled())
		{
			va_list args;
			va_start(args, argc);
			(*iter)->Trigger(eid, argc, args);
			va_end(args);
		}
	}
}

void NeoGameLogic::TriggerEvent(int eid, std::vector<std::string>& params)
{
	for (std::set<NeoTrigger*>::iterator iter = list_triggers.begin();
			iter != list_triggers.end(); iter++)
	{
		if ((*iter)->isAlive() && !(*iter)->isDisabled())
		{
			(*iter)->Trigger(eid, params);
		}
	}
}

void NeoGameLogic::RegisterTrigger(NeoTrigger* newTrigger)
{
	list_triggers.insert(newTrigger);
	if (list_longterm_triggers.size() > 0)
	{
		for (std::map<int, std::string>::iterator iter =
				list_longterm_triggers.begin();
				iter != list_longterm_triggers.end(); iter++)
		{
			if ((*iter).second.empty())
				newTrigger->Trigger((*iter).first, 0);
			else
				newTrigger->Trigger((*iter).first, 1, (*iter).second.c_str());
		}
	}
}

void NeoGameLogic::ResetAllTriggers()
{
	for (std::set<NeoTrigger*>::iterator iter = list_triggers.begin();
			iter != list_triggers.end(); iter++)
	{
		(*iter)->Reset();
	}
}

void NeoGameLogic::RemoveTrigger(NeoTrigger* trigger)
{
	std::set<NeoTrigger*>::iterator iter;
	iter = list_triggers.find(trigger);
	if (iter != list_triggers.end())
	{
		list_triggers.erase(iter);
	}
}

void NeoGameLogic::RegisterLongTermEvent(int eid, std::string param)
{
	list_longterm_triggers[eid] = param;
}

void NeoGameLogic::RemoveLongTermEvent(int eid)
{
	list_longterm_triggers.erase(eid);
}

void NeoGameLogic::RemoveAllLongTermTriggers()
{
	list_longterm_triggers.clear();
}

NeoGameLogic::~NeoGameLogic()
{
	// TODO 自动生成的析构函数存根
	NeoEventHandler* eventHandler =
			static_cast<NeoEventHandler*>(NeoGraphics::GetInstance()->getDevice()->getEventReceiver());
	delete eventHandler;
	NeoGraphics::GetInstance()->getDevice()->setEventReceiver(NULL);
}

NeoGameLogic* NeoGameLogic::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new NeoGameLogic();
	}
	return _instance;
}

void NeoGameLogic::Destroy()
{
	if (_instance != NULL)
	{
		delete _instance;
	}
}

void NeoGameLogic::Init()
{
	NeoEventHandler* eventHandler = new NeoEventHandler();
	NeoGraphics::GetInstance()->getDevice()->setEventReceiver(eventHandler);
}

void NeoGameLogic::Update()
{
	//------------trigger-----------//
	std::set<NeoTrigger*>::iterator iter;
	for (iter = list_triggers.begin(); iter != list_triggers.end();)
	{
		if ((*iter)->isAlive())
		{
			iter++;
		}
		else
		{
			//清理废弃触发器
			NeoTrigger*obsoletTrigger = (*iter);
			list_triggers.erase(iter);
			obsoletTrigger->drop();
		}
	}
	//----------------------------------------//
}
