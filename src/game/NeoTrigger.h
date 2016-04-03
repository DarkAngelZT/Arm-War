/*
 * NeoTrigger.h
 *
 *  Created on: 2016年1月22日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOTRIGGER_H_
#define SRC_GAME_NEOTRIGGER_H_

#include <set>
#include <vector>
#include <stdarg.h>
#include<string>

class NeoTrigger
{
public:
	static NeoTrigger* create(bool alive=true);
	void drop();
	/*
	 * 手动触发一个事件
	 * tid:事件id
	 * argc:参数个数
	 * 其余参数均为char*
	*/
	void Trigger(int tid,int argc=0,...);
	//gamelogic触发向下调用入口
	void Trigger(int tid,int argc,va_list args);
	/*
	 * 另一个触发函数，留给lua调用的
	 */
	void Trigger(int tid,std::vector<std::string>&params);

	//getter and setters
	bool isAlive()const;
	void setAlive(bool alive);

	void setTriggerFunction(std::string funcName);
	void addTriggerCondition(int cid);

	void setDisabled(bool dis);
	bool isDisabled()const;

	void Reset();

private:
	NeoTrigger(bool alive);
	virtual ~NeoTrigger();
	bool bAlive;
	bool bDisabled;
	std::set<int> tTriggerTable;
	std::string str_trigger_func_name;
};

#endif /* SRC_GAME_NEOTRIGGER_H_ */
