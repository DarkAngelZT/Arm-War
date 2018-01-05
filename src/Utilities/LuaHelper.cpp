/*
 * LuaHelper.cpp
 *
 *  Created on: 2016年11月16日
 *      Author: neo
 */

#include "LuaHelper.h"
#include <irrlicht.h>
#include "../graphics/NeoGraphics.h"

int LuaHelper::BitAnd(int a, int b)
{
	return a & b;
}

int LuaHelper::BitOr(int a, int b)
{
	return a | b;
}

int LuaHelper::BitXor(int a, int b)
{
	return a ^ b;
}

int LuaHelper::BitLshift(int a, int n)
{
	return a << n;
}

int LuaHelper::BitNot(int a)
{
	return ~a;
}

int LuaHelper::BitRshift(int a, int n)
{
	return a >> n;
}

std::vector<std::string> NeoGame::io::getFileInfolder(
		const std::string& folder_name, const std::string& extensions)
{
	irr::io::IFileSystem* file_sys =
			NeoGraphics::getInstance()->getDevice()->getFileSystem();
	irr::io::path pwd = file_sys->getWorkingDirectory();
	file_sys->changeWorkingDirectoryTo(folder_name.c_str());
	std::vector<std::string> file_list_vector;
	irr::io::IFileList *file_list = file_sys->createFileList();

	int nFile = file_list->getFileCount();
	for (int i = 1; i < nFile; i++)
	{
		if (file_list->isDirectory(i))
			continue;
		irr::io::path fname = file_list->getFileName(i);
		irr::core::stringc ext;
		irr::core::getFileNameExtension(ext, fname);
		ext.make_lower();
		if (extensions.find(ext.subString(1, ext.size() - 1, true).c_str())
				!= std::string::npos)
		{
			file_list_vector.push_back(fname.c_str());
		}
	}
	file_sys->changeWorkingDirectoryTo(pwd);
	return file_list_vector;
}

std::string NeoGame::io::getCurrentWorkingDirectory()
{
	irr::io::IFileSystem* file_sys =
			NeoGraphics::getInstance()->getDevice()->getFileSystem();
	return std::string(file_sys->getWorkingDirectory().c_str());
}

bool NeoGame::io::isFileExist(const std::string& path)
{
	irr::io::IFileSystem* file_sys =
			NeoGraphics::getInstance()->getDevice()->getFileSystem();
	return file_sys->existFile(path.c_str());
}

irr::core::vector3df matrix4_getRotationZXY_rad(const irr::core::matrix4& mx)
{
	irr::core::vector3df r;
	r.X = asinf(-mx(2,1));
	const irr::f32 t = cosf(r.X);
	if (.001f < t) {
		r.Z = atan2f(mx(0,1), mx(1,1));
		r.Y = atan2f(mx(2,0), mx(2,2));
	}
	else {
		r.Z = atan2f(-mx (1,0), mx (0,0));
		r.Y = 0.f;
	}
	return r;
}

std::string NeoGame::io::getRelativePath(const std::string& file,
		const std::string& dir)
{
	irr::io::IFileSystem* file_sys =
				NeoGraphics::getInstance()->getDevice()->getFileSystem();
		return file_sys->getRelativeFilename(file.c_str(),dir.c_str()).c_str();
}

std::string NeoGame::io::getAbsolutePath(const std::string& file)
{
	irr::io::IFileSystem* file_sys =
				NeoGraphics::getInstance()->getDevice()->getFileSystem();
		return file_sys->getAbsolutePath(file.c_str()).c_str();
}
