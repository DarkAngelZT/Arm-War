/*
 * NeoScene.h
 *
 *  Created on: 2016年2月3日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOSCENE_H_
#define SRC_GAME_NEOSCENE_H_
#include <unordered_map>
#include <list>
#include "GameObject.h"
#include "../graphics/sfx/Effector.h"
#include "objectPool/ExplosionObjectPool.h"
#include "object/StandardTankBodyObject.h"
#include "object/SimpleTankTrackObject.h"
#include "game/SingletonMacro.h"

class ExplosionObjectPool;
class NeoData;
class StandardTankBodyObject;
class SimpleTankTrackObject;
class Effector;

class NeoScene
{
SINGLETON_HEADER(NeoScene)
public:
	void Clean();
	GameObject*CreateGameObject();
	GameObject*GetGameObject(int goId);
	StandardTankBodyObject*CreateStandardTankBodyObject();
	SimpleTankTrackObject* CreateSimpleTankTrackObject();

	void DestroyGameObject(GameObject*go, bool removeChild = false);
	void DestroyGameObject(int goId, bool removeChild = false);
	Explosion* CreateExplosion(std::string explosion_type, NeoData&visual_data,
			NeoData&physics_data);
	Effector* addSpriteAnimationEffector(
			const irr::core::vector3d<float>& position,
			const std::string& spriteFile,
			const irr::core::dimension2d<float>& size);
	void RemoveEffector(Effector*effector);
	//--c++ interface--//
	std::shared_ptr<Explosion> CreateExplosion_cpp(std::string& explosion_type,
			NeoData&visual_data, NeoData&physics_data);
private:
	NeoScene();
	virtual ~NeoScene();
	std::unordered_map<int, GameObject*> list_gameObjects;
	int go_id_counter;
	//object pools
	ExplosionObjectPool object_pool_explosion;
	std::list<std::shared_ptr<Effector>> m_effectors;
};

#endif /* SRC_GAME_NEOSCENE_H_ */
