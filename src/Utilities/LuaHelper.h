/*
 * LuaHelper.h
 *
 *  Created on: 2016年11月16日
 *      Author: neo
 */

#ifndef SRC_UTILITIES_LUAHELPER_H_
#define SRC_UTILITIES_LUAHELPER_H_

/*
 * lua helper for some basic operations in lua 5.1
 */
class LuaHelper
{
public:
	static int BitAnd(int a,int b);
	static int BitOr(int a,int b);
	static int BitXor(int a,int b);
	static int BitNot(int a);
	static int BitLshift(int a,int n);
	static int BitRshift(int a,int n);
};

#endif /* SRC_UTILITIES_LUAHELPER_H_ */
