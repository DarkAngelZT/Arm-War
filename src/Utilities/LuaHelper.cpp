/*
 * LuaHelper.cpp
 *
 *  Created on: 2016年11月16日
 *      Author: neo
 */

#include "LuaHelper.h"
int LuaHelper::BitAnd(int a, int b)
{
	return a&b;
}

int LuaHelper::BitOr(int a, int b)
{
	return a|b;
}

int LuaHelper::BitXor(int a, int b)
{
	return a^b;
}

int LuaHelper::BitLshift(int a, int n)
{
	return a<<n;
}

int LuaHelper::BitNot(int a)
{
	return ~a;
}

int LuaHelper::BitRshift(int a, int n)
{
	return a>>n;
}
