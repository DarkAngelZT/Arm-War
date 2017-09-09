/*
 * NeoGameLogic.h
 *
 *  Created on: 2016年1月21日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOGAMELOGIC_H_
#define SRC_GAME_NEOGAMELOGIC_H_
#include <vector>
#include <map>
#include "NeoTrigger.h"
#include <set>
using namespace std;
class NeoGameLogic
{
public:
	static NeoGameLogic*GetInstance();
	static void Destroy();
	void Init();
	void Update();

	//-------triggers-----//
	void TriggerEvent(int eid,int argc=0,...);
	/*
	 * reserve for lua
	 */
	void TriggerEvent(int eid,std::vector<std::string>&params);
	void RegisterTrigger(NeoTrigger* newTrigger);
	void RegisterLongTermEvent(int eid,std::string param="");
	void RemoveLongTermEvent(int eid);
	void RemoveAllLongTermTriggers();
	void RemoveTrigger(NeoTrigger* trigger);
	void ResetAllTriggers();

	void AddLuaUpdateFunction(std::string funcName);
	void removeLuaUpdateFunction(std::string funcName);
	//--------------//
private:
	NeoGameLogic();
	virtual ~NeoGameLogic();
	static NeoGameLogic*_instance;
	std::set<NeoTrigger*>list_triggers;
	std::map<int,std::string>list_longterm_triggers;
	std::set<std::string>lua_update_functions;
};

#endif /* SRC_GAME_NEOGAMELOGIC_H_ */
