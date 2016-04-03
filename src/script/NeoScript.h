/*
 * NeoScript.h
 *
 *  Created on: 2016年1月20日
 *      Author: neo
 */

#ifndef SRC_SCRIPT_NEOSCRIPT_H_
#define SRC_SCRIPT_NEOSCRIPT_H_
#include"../game/stdafx.h"
#include <vector>
#include "../game/NeoEvent.h"
class NeoScript {
public:
	static NeoScript* GetInstance();
	static void Destroy();
	void Init(lua_State* lua_State=0);
	int ExecuteScriptFile(std::string fname);
	int ExecuteScriptGlobalFunc(std::string& func_name);
	void ExecuteString(std::string& str);
	void ExecuteScriptedFunction(std::string func_name,std::vector<std::string>&params);
	void ExecuteScriptedEventFunction(std::string& func_name,NeoEvent&e);

	std::string GetScriptGlobalValue_string(std::string valname);
	int GetScriptGlobalValue_int(std::string valname);
	bool GetScriptGlobalValue_bool(std::string valname);
	void GetScriptField(std::string valname);
	lua_State* getLuaState() const;
	void setLuaState(lua_State* luaS);

private:
	NeoScript();
	virtual ~NeoScript();
	void createExtraBindings();
	static NeoScript* _instance;
	lua_State*lua_S;
};

#endif /* SRC_SCRIPT_NEOSCRIPT_H_ */
