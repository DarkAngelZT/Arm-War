/*
 * NeoScript.cpp
 *
 *  Created on: 2016年1月20日
 *      Author: neo
 */

#include "NeoScript.h"
#include<fstream>
#include "../game/NeoTrigger.h"
#include "../game/NeoGameLogic.h"

NeoScript* NeoScript::_instance = NULL;

//extra lua binding functions-//
int tolua_NeoGame_open(lua_State* tolua_S);

static int NeoTrigger_Trigger(lua_State* tolua_S);

static int NeoGameLogic_TriggerEvent(lua_State* tolua_S);
//---------------------------------------//

NeoScript::NeoScript()
{
	// TODO Auto-generated constructor stub

}

NeoScript* NeoScript::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new NeoScript();
	}
	return _instance;
}

void NeoScript::Destroy()
{
	if (_instance != NULL)
	{
		delete _instance;
		_instance = NULL;
	}
}

void NeoScript::Init(lua_State* lua_State)
{
	if (lua_State != 0)
		setLuaState(lua_State);
	else
	{
		//code copy from cegui, manually initialize, cause they have bug i can't fix
		static const luaL_Reg lualibs[] =
		{
		{ "", luaopen_base },
		{
		LUA_LOADLIBNAME, luaopen_package },
		{ LUA_TABLIBNAME, luaopen_table },
		{
		LUA_IOLIBNAME, luaopen_io },
		{ LUA_OSLIBNAME, luaopen_os },
		{
		LUA_STRLIBNAME, luaopen_string },
		{ LUA_MATHLIBNAME, luaopen_math },
		{ 0, 0 } };

		// create a lua state
		lua_S = luaL_newstate();

		// init all standard libraries
		const luaL_Reg *lib = lualibs;
		for (; lib->func; lib++)
		{
			lua_pushcfunction(lua_S, lib->func);
			lua_pushstring(lua_S, lib->name);
			lua_call(lua_S, 1, 0);
		}
		createExtraBindings();
	}
}
//fname:path of the file
int NeoScript::ExecuteScriptFile(std::string fname)
{
	//get whole file string
	std::ifstream fin(fname);
	std::istreambuf_iterator<char> beg(fin), end;
	std::string scriptStr(beg, end);
	fin.close();
	//get lua runtime
	int top = lua_gettop(lua_S);
	int loaderr = luaL_loadbuffer(lua_S, scriptStr.data(), scriptStr.length(),
			fname.c_str());

	if (loaderr)
	{
		std::string errMsg = lua_tostring(lua_S, -1);
		lua_settop(lua_S, top);
#ifdef DEBUG
		std::cout << "Unable to execute Lua script file: '" << fname << "'\n\n"
				<< errMsg << "\n";
#endif
		return -1;
	}

	// call it
	if (lua_pcall(lua_S, 0, 0, 0))
	{
		std::string errMsg = lua_tostring(lua_S, -1);
		lua_settop(lua_S, top);
#ifdef DEBUG
		std::cout << "Unable to execute Lua script file: '" << fname << "'\n\n"
				<< errMsg << "\n";
#endif
		return -1;
	}

	lua_settop(lua_S, top); // just in case :P
	return 0;
}

int NeoScript::ExecuteScriptGlobalFunc(std::string& func_name)
{
	int top = lua_gettop(lua_S);
	lua_getglobal(lua_S, func_name.c_str());

	// is it a function
	if (!lua_isfunction(lua_S, -1))
	{
		lua_settop(lua_S, top);
#ifdef DEBUG
		std::cout << "Unable to get Lua global: '" << func_name
				<< "' as name not represent a global Lua function\n";
#endif
		return -1;
	}

	// call it
	int error = lua_pcall(lua_S, 0, 1, 0);

	// handle errors
	if (error)
	{
		std::string errMsg = lua_tostring(lua_S, -1);
		lua_settop(lua_S, top);
#ifdef DEBUG
		std::cout << "Unable to evaluate Lua global: '" << func_name << "\n\n"
				<< errMsg << "\n";
#endif
		return -1;
	}

	// get return value
	if (!lua_isnumber(lua_S, -1))
	{
		// log that return value is invalid. return -1 and move on.
		lua_settop(lua_S, top);
#ifdef DEBUG
		std::cout << "Unable to get Lua global : '" << func_name
				<< "' return value as it's not a number\n";
#endif
		return -1;
	}

	int ret = static_cast<int>(lua_tonumber(lua_S, -1));
	lua_settop(lua_S, top);

	// return it
	return ret;
}

void NeoScript::ExecuteString(std::string& str)
{
	int top = lua_gettop(lua_S);
	int error = luaL_loadbuffer(lua_S, str.c_str(), str.length(),
			str.c_str()) || lua_pcall(lua_S, 0, 0, 0);

	// handle errors
	if (error)
	{
		std::string errMsg = lua_tostring(lua_S, -1);
		lua_settop(lua_S, top);
#ifdef DEBUG
		std::cout << "Unable to execute Lua script string: '" << str << "'\n\n"
				<< errMsg << "\n";
#endif
	}

	lua_settop(lua_S, top);
}

std::string NeoScript::GetScriptGlobalValue_string(std::string valname)
{
	int top = lua_gettop(lua_S);
	GetScriptField(valname);
	std::string result = lua_tostring(lua_S, -1);
	lua_settop(lua_S, top);
	return result;
}

int NeoScript::GetScriptGlobalValue_int(std::string valname)
{
	int top = lua_gettop(lua_S);
	GetScriptField(valname);
	int result = lua_tointeger(lua_S, -1);
	lua_settop(lua_S, top);
	return result;
}

bool NeoScript::GetScriptGlobalValue_bool(std::string valname)
{
	int top = lua_gettop(lua_S);
	GetScriptField(valname);
	bool result = lua_toboolean(lua_S, -1) ? true : false;
	lua_settop(lua_S, top);
	return result;
}

void NeoScript::GetScriptField(std::string valname)
{
	int top = lua_gettop(lua_S);
	std::string::size_type pos = valname.find_first_of('.');
	std::string::size_type posIdxStart = valname.find_first_of('[');
	std::string::size_type posIdxEnd = valname.find_first_of(']');
	std::string indexStr;
	if (pos != std::string::npos)
	{
		std::vector<std::string> parts;
		std::string::size_type start = 0;
		std::string tableName = valname.substr(start, pos - start);
		start = pos + 1;
		//检查是不是"[ ]"格式
		posIdxStart = tableName.find_first_of('[');
		posIdxEnd = tableName.find_first_of(']');
		if (posIdxStart != std::string::npos)
		{
			indexStr = tableName.substr(posIdxStart + 1,
					posIdxEnd - posIdxStart - 1);
			tableName = tableName.substr(0, posIdxStart);
			lua_getglobal(lua_S, tableName.c_str());
			lua_rawgeti(lua_S, -1, atoi(indexStr.c_str()));
		}
		else
		{
			lua_getglobal(lua_S, tableName.c_str());
		}
		if (!lua_istable(lua_S, -1))
		{
			lua_settop(lua_S, top);
#ifdef DEBUG
			std::cout << "Unable to get the Lua value: '"
					<< valname + "' as first part is not a table\n";
#endif
			return;
		}
		while (pos != std::string::npos)
		{
			pos = valname.find_first_of('.', start);

			std::string fieldName = valname.substr(start,
					pos == std::string::npos ? pos : pos - start);
			start = pos + 1;
			//检查是不是"[ ]"格式
			posIdxStart = fieldName.find_first_of('[');
			posIdxEnd = fieldName.find_first_of(']');
			if (posIdxStart != std::string::npos)
			{
				indexStr = fieldName.substr(posIdxStart + 1,
						posIdxEnd - posIdxStart - 1);
				fieldName = fieldName.substr(0, posIdxStart);
				lua_getfield(lua_S, -1, fieldName.c_str());
				lua_rawgeti(lua_S, -1, atoi(indexStr.c_str()));
			}
			else
			{
				lua_getfield(lua_S, -1, fieldName.c_str());
			}
		}
	}
	else
	{
		if (posIdxStart != std::string::npos)
		{
			indexStr = valname.substr(posIdxStart + 1,
					posIdxEnd - posIdxStart - 1);
			valname = valname.substr(0, posIdxStart);
			lua_getglobal(lua_S, valname.c_str());
			lua_rawgeti(lua_S, -1, atoi(indexStr.c_str()));
		}
		else
		{
			lua_getglobal(lua_S, valname.c_str());
		}
	}
}

void NeoScript::ExecuteScriptedFunction(std::string func_name,
		std::vector<std::string>& params)
{
	int top = lua_gettop(lua_S);
	GetScriptField(func_name.c_str());
	if (!lua_isfunction(lua_S, -1))
	{
#ifdef DEBUG
		std::cout << "Unable to get Lua global: '" << func_name
				<< "' as name not represent a global Lua function\n";
#endif
		lua_settop(lua_S, top);
		return;
	}
	int nParams = params.size();
	if (nParams > 0)
	{
		for (std::vector<std::string>::iterator iter = params.begin();
				iter != params.end(); iter++)
		{
			lua_pushstring(lua_S, iter->c_str());
		}
	}
	lua_pcall(lua_S, nParams, 0, 0);
	lua_settop(lua_S, top);
}

void NeoScript::ExecuteScriptedEventFunction(std::string& func_name,
		NeoEvent& e)
{
	int top = lua_gettop(lua_S);
	GetScriptField(func_name.c_str());
	if (!lua_isfunction(lua_S, -1))
	{
#ifdef DEBUG
		std::cout << "Unable to get Lua global: '" << func_name
				<< "' as name not represent a global Lua function\n";
#endif
		lua_settop(lua_S, top);
		return;
	}
	tolua_pushusertype(lua_S, (void*) &e, "const NeoEvent");
	lua_pcall(lua_S, 1, 0, 0);
	lua_settop(lua_S, top);
}

NeoScript::~NeoScript()
{
	// TODO Auto-generated destructor stub
}

lua_State* NeoScript::getLuaState() const
{
	return lua_S;
}

void NeoScript::setLuaState(lua_State* luaS)
{
	lua_S = luaS;
}

void NeoScript::createExtraBindings()
{
	tolua_NeoGame_open(lua_S);
	//custom bindings
	//---NeoTrigger---//
	luaL_Reg exlualibs_Neotrigger[] =
	{
	{ "Trigger", NeoTrigger_Trigger },
	{ 0, 0 } };
	luaL_register(lua_S, "NeoTrigger", exlualibs_Neotrigger);
	//------NeoGameLogic------//
	luaL_Reg exlualibs_GameLogic[] =
	{
	{ "TriggerEvent", NeoGameLogic_TriggerEvent },
	{ 0, 0 } };
	luaL_register(lua_S, "NeoGameLogic", exlualibs_GameLogic);
	//---------------------//
}

inline int NeoTrigger_Trigger(lua_State* tolua_S)
{
	NeoTrigger* self = (NeoTrigger*) tolua_tousertype(tolua_S, 1, 0);
	//返回栈中元素的个数
	int n = lua_gettop(tolua_S);
	int cid = ((int) tolua_tonumber(tolua_S, 2, 0));
	std::vector<std::string> params(0);
	int i;
	for (i = 3; i <= n; i++)
	{
		if (!lua_isstring(tolua_S, i))
		{
			lua_pushstring(tolua_S,
					"Incorrect argument to 'NeoTrigger:Trigger'");
			lua_error(tolua_S);
		}
		params.push_back(lua_tostring(tolua_S, i));
	}
	self->Trigger(cid, params);
	return 0;
}

inline int NeoGameLogic_TriggerEvent(lua_State* tolua_S)
{
	NeoGameLogic* self = (NeoGameLogic*) tolua_tousertype(tolua_S, 1, 0);
	//返回栈中元素的个数
	int n = lua_gettop(tolua_S);
	int cid = ((int) tolua_tonumber(tolua_S, 2, 0));
	std::vector<std::string> params(0);
	int i;
	for (i = 3; i <= n; i++)
	{
		if (!lua_isstring(tolua_S, i))
		{
			lua_pushstring(tolua_S,
					"Incorrect argument to 'GameLogic:TriggerEvent'");
			lua_error(tolua_S);
		}
		params.push_back(lua_tostring(tolua_S, i));
	}
	self->TriggerEvent(cid, params);
	return 0;
}
