/*
 * SfxManager.h
 *
 *  Created on: 2016年9月29日
 *      Author: neo
 */

#ifndef SRC_GRAPHICS_SFX_SFXMANAGER_H_
#define SRC_GRAPHICS_SFX_SFXMANAGER_H_
#include "../../game/stdafx.h"
#include "Effector.h"
/*
 *manager class for effect creation & invoke
 */
class Effector;
class SfxManager
{
public:
	struct SpriteInfo
	{
	public:
		irr::video::ITexture* texure;
		int row;
		int column;
		irr::core::array<irr::core::vector2df> spriteCoordinates;
		irr::core::vector2df scale;
	};
	SfxManager();
	virtual ~SfxManager();

	std::shared_ptr<Effector> AddEffector(std::string effector_name,
			NeoData& data);
	irr::video::ITexture* getParticleTexure(std::string key);
	auto getSpriteTexure(std::string key)->SpriteInfo*;
	inline std::vector<irr::io::path> getFileInFolder(std::string folder_name,
			std::string extentions = "");
	//lua API
	void Init();
	void AddSpriteTexture(std::string sprite_file, int row, int column);
	void CleanUp();
protected:
	void RegisterEffector(std::string effector_key,std::function<std::shared_ptr<Effector>(NeoData&)>functor);
private:
	std::map<std::string, std::function<std::shared_ptr<Effector>(NeoData&)>> m_dEffectorType;
	std::map<std::string, irr::video::ITexture*> m_dParticle_textures;
	std::map<std::string, SpriteInfo> m_dSprite_textures;
	const std::string particle_parent_folder = "resources/sfx/particles/";
	const std::string sprite_parent_folder = "resources/sfx/sprites/";
};

#endif /* SRC_GRAPHICS_SFX_SFXMANAGER_H_ */
