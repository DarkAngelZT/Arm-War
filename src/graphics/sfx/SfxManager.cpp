/*
 * SfxManager.cpp
 *
 *  Created on: 2016年9月29日
 *      Author: neo
 */

#include "SfxManager.h"
#include "BasicExplosionEffector.h"

SfxManager::SfxManager()
{
	// TODO 自动生成的构造函数存根
	//bind Effector creation functions
	RegisterEffector("BasicExplosionEffector", BasicExplosionEffector::Create);
}

SfxManager::~SfxManager()
{
	// TODO 自动生成的析构函数存根
}

void SfxManager::Init()
{
	CleanUp();
	//load particle images
	std::vector<irr::io::path> file_list = getFileInFolder(
			particle_parent_folder, "bmp,jpg,png,tga");
	std::vector<irr::io::path>::iterator it = file_list.begin();
	irr::video::IVideoDriver* video_driver =
			NeoGraphics::getInstance()->getVideoDriver();
	for (; it != file_list.end(); ++it)
	{
		irr::io::path file_path =
				(particle_parent_folder + (*it).c_str()).c_str();
		irr::video::ITexture* particle_texture = video_driver->getTexture(
				file_path);
		/*video_driver->makeColorKeyTexture(particle_texture,
				video::SColor(0, 0, 0, 0));*/
		m_dParticle_textures[(*it).c_str()] = particle_texture;
	}
	//load sprite images

	std::vector<irr::io::path> file_list_sprite = getFileInFolder(
			sprite_parent_folder, "bmp,jpg,png,tga");
	std::vector<irr::io::path>::iterator it_sprite = file_list_sprite.begin();
	for (; it_sprite != file_list_sprite.end(); ++it_sprite)
	{
		std::vector<std::string> lua_param;
		lua_param.push_back((*it_sprite).c_str());
		//load sprite information from lua script
		NeoScript::getInstance()->ExecuteScriptedFunction("SpriteLoader",
				lua_param);
	}
}

std::shared_ptr<Effector> SfxManager::AddEffector(std::string effector_name,
		NeoData& data)
{
	if (m_dEffectorType.count(effector_name) > 0)
	{
		return m_dEffectorType[effector_name](data);
	}
	//return empty pointer if failed to find type
	return std::shared_ptr<Effector>();
}

void SfxManager::CleanUp()
{
	std::map<std::string, irr::video::ITexture*>::iterator it;
	for (it = m_dParticle_textures.begin(); it != m_dParticle_textures.end();
			++it)
	{
		NeoGraphics::getInstance()->getVideoDriver()->removeTexture(it->second);
	}
	m_dParticle_textures.clear();

	std::map<std::string, SpriteInfo>::iterator it_sprite;
	for (it_sprite = m_dSprite_textures.begin();
			it_sprite != m_dSprite_textures.end(); ++it_sprite)
	{
		NeoGraphics::getInstance()->getVideoDriver()->removeTexture(
				it_sprite->second.texure);
	}
	m_dSprite_textures.clear();
}

void SfxManager::RegisterEffector(std::string effector_key,
		std::function<std::shared_ptr<Effector>(NeoData&)> functor)
{
	m_dEffectorType[effector_key] = functor;
}

irr::video::ITexture* SfxManager::getParticleTexure(std::string key)
{
	if (m_dParticle_textures.count(key) > 0)
	{
		return m_dParticle_textures[key];
	}
	return NULL;
}

auto SfxManager::getSpriteTexure(std::string key)->SpriteInfo*
{
	if (m_dSprite_textures.count(key) > 0)
	{
		return &m_dSprite_textures[key];
	}
	return NULL;
}

inline std::vector<irr::io::path> SfxManager::getFileInFolder(
		std::string folder_name, std::string extensions)
{
	irr::io::IFileSystem* file_sys =
			NeoGraphics::getInstance()->getDevice()->getFileSystem();
	file_sys->changeWorkingDirectoryTo(folder_name.c_str());
	std::vector<irr::io::path> file_list_vector;
	irr::io::IFileList *file_list = file_sys->createFileList();

	int nFile = file_list->getFileCount();
	for (u32 i = 1; i < nFile; i++)
	{
		irr::io::path fname = file_list->getFileName(i);
		stringc ext;
		irr::core::getFileNameExtension(ext, fname);
		ext.make_lower();
		if (extensions.find(ext.subString(1, ext.size() - 1, true).c_str())
				!= std::string::npos)
		{
			file_list_vector.push_back(fname);
		}
	}
	file_sys->changeWorkingDirectoryTo("../../..");
	return file_list_vector;
}

void SfxManager::AddSpriteTexture(std::string sprite_file, int row, int column)
{
	irr::io::path file_path = (sprite_parent_folder + sprite_file).c_str();
	irr::video::ITexture* sprite_texture =
			NeoGraphics::getInstance()->getVideoDriver()->getTexture(file_path);
	/*NeoGraphics::getInstance()->getVideoDriver()->makeColorKeyTexture(
			sprite_texture, video::SColor(0, 0, 0, 0));*/
	m_dSprite_textures[sprite_file] = SpriteInfo
	{ sprite_texture, row, column };
}
