/*
 * NeoTrigger.cpp
 *
 *  Created on: 2016年1月22日
 *      Author: neo
 */

#include "NeoTrigger.h"
#include "stdafx.h"
#include "NeoEvent.h"

NeoTrigger::NeoTrigger(bool alive = true)
{
	// TODO 自动生成的构造函数存根
	bAlive = alive;
	bDisabled = false;
}

NeoTrigger* NeoTrigger::create(bool alive)
{
	return new NeoTrigger(alive);
}

void NeoTrigger::drop()
{
	delete this;
}

void NeoTrigger::Reset()
{
	bAlive = true;
	bDisabled = false;
}

NeoTrigger::~NeoTrigger()
{
	// TODO 自动生成的析构函数存根
	tTriggerTable.clear();
}
/*
 * 触发一个条件
 */
void NeoTrigger::Trigger(int tid, int argc, ...)
{
	if (bDisabled)
		return;
	std::set<int>::iterator iter;
	iter = tTriggerTable.find(tid);
	if (iter != tTriggerTable.end())
	{
		std::vector<std::string> param(0);
		//向lua传递触发信息
		if (argc > 0)
		{
			va_list args;
			va_start(args, argc);
			for (int i = 0; i < argc; i++)
			{
				std::string str_param = va_arg(args, char*);
				param.push_back(str_param);
			}
			va_end(args);
		}
		if (!str_trigger_func_name.empty())
		{
			NeoEvent data2lua;
			data2lua.nEventId = tid;
			data2lua.data = param;
			NeoScript::getInstance()->ExecuteScriptedEventFunction(
					str_trigger_func_name, data2lua);
		}
	}
}

void NeoTrigger::Trigger(int tid, int argc, va_list args)
{
	if (bDisabled)
		return;
	std::set<int>::iterator iter;
	iter = tTriggerTable.find(tid);
	if (iter != tTriggerTable.end())
	{
		std::vector<std::string> param(0);
		for (int i = 0; i < argc; i++)
		{
			std::string str_param = va_arg(args, char*);
			param.push_back(str_param);
		}
		if (!str_trigger_func_name.empty())
		{
			NeoEvent data2lua;
			data2lua.nEventId = tid;
			data2lua.data = param;
			NeoScript::getInstance()->ExecuteScriptedEventFunction(
					str_trigger_func_name, data2lua);
		}
	}

}

void NeoTrigger::Trigger(int tid, std::vector<std::string>& params)
{
	if (bDisabled)
		return;
	std::set<int>::iterator iter;
	iter = tTriggerTable.find(tid);
	if (iter != tTriggerTable.end())
	{
		if (!str_trigger_func_name.empty())
		{
			NeoEvent data2lua;
			data2lua.nEventId = tid;
			data2lua.data = params;
			NeoScript::getInstance()->ExecuteScriptedEventFunction(
					str_trigger_func_name, data2lua);
		}
	}
}

bool NeoTrigger::isAlive() const
{
	return bAlive;
}

void NeoTrigger::setAlive(bool alive)
{
	bAlive = alive;
}
/*
 * 设置触发函数，
 * 参数：
 * 函数名，参数个数，以及具体的参数（全部字符串）
 */
void NeoTrigger::setTriggerFunction(std::string funcName)
{
	str_trigger_func_name = funcName;
}
/*
 * 设置触发条件，
 * 参数：
 * 条件cid，触发次数TTL(0表示无限次)，参数个数argc，以及具体的参数（全部字符串）
 * 同一个条件会覆盖之前的设定
 */
void NeoTrigger::addTriggerCondition(int cid)
{
	tTriggerTable.insert(cid);
}

void NeoTrigger::setDisabled(bool dis)
{
	bDisabled = dis;
}

bool NeoTrigger::isDisabled() const
{
	return bDisabled;
}
