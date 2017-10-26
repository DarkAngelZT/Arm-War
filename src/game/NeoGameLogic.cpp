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
NeoGameLogic::NeoGameLogic():m_gamePaused(false)
{
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

void NeoGameLogic::AddLuaUpdateFunction(std::string funcName)
{
	lua_update_functions.insert(funcName);
}

void NeoGameLogic::removeLuaUpdateFunction(std::string funcName)
{
	lua_update_functions.erase(funcName);
}

float NeoGameLogic::getDeltaTime()
{
	return NeoGraphics::getInstance()->getDeltaTime();
}

NeoGameLogic::~NeoGameLogic()
{
	NeoEventHandler* eventHandler =
			static_cast<NeoEventHandler*>(NeoGraphics::getInstance()->getDevice()->getEventReceiver());
	delete eventHandler;
	NeoGraphics::getInstance()->getDevice()->setEventReceiver(NULL);
}

NeoGameLogic* NeoGameLogic::getInstance()
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
	NeoGraphics::getInstance()->getDevice()->setEventReceiver(eventHandler);
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
	//-------------lua update---------------------//
	if (!lua_update_functions.empty())
	{
		std::vector<std::string> params;
		std::set<std::string>::iterator iter_func;
		for (iter_func = lua_update_functions.begin();
				iter_func != lua_update_functions.end(); ++iter_func)
		{
			NeoScript::getInstance()->ExecuteScriptedFunction((*iter_func),
					params);
		}
	}
	if (!lua_update_function_delete_queue.empty())
	{
		std::set<std::string>::iterator iter_queue;
		for (iter_queue = lua_update_function_delete_queue.begin();
				iter_queue != lua_update_function_delete_queue.end();
				iter_queue++)
		{
			removeLuaUpdateFunction(*iter_queue);
		}
		lua_update_function_delete_queue.clear();
	}
}

void NeoGameLogic::removeLuaUpdateFunctionExeSafe(std::string funcName)
{
	lua_update_function_delete_queue.insert(funcName);
}

bool NeoGameLogic::isGamePaused() const
{
	return m_gamePaused;
}

void NeoGameLogic::setGamePaused(bool gamePaused)
{
	m_gamePaused = gamePaused;
}
