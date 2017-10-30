/*
 * LuaHelper.h
 *
 *  Created on: 2016年11月16日
 *      Author: neo
 */

#ifndef SRC_UTILITIES_LUAHELPER_H_
#define SRC_UTILITIES_LUAHELPER_H_
#include <vector>
#include <string>
#include<irrlicht.h>
/*
 * lua helper for some basic operations in lua 5.1
 */
class LuaHelper
{
public:
	static int BitAnd(int a, int b);
	static int BitOr(int a, int b);
	static int BitXor(int a, int b);
	static int BitNot(int a);
	static int BitLshift(int a, int n);
	static int BitRshift(int a, int n);
};

namespace NeoGame
{
namespace io
{
std::vector<std::string> getFileInfolder(const std::string& folder_name,
		const std::string& extensions);
std::string getCurrentWorkingDirectory();
bool isFileExist(const std::string& path);
}
}

irr::core::vector3df matrix4_getRotationZXY_rad(const irr::core::matrix4& mx);

#endif /* SRC_UTILITIES_LUAHELPER_H_ */
