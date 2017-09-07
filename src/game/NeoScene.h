/*
 * NeoScene.h
 *
 *  Created on: 2016年2月3日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOSCENE_H_
#define SRC_GAME_NEOSCENE_H_
#include <unordered_map>
#include "GameObject.h"
#include "ExplosionObjectPool.h"

class ExplosionObjectPool;
class NeoData;

class NeoScene
{
public:
	static NeoScene*GetInstance();
	static void Destroy();
	void Clean();
	GameObject*CreateGameObject();
	GameObject*GetGameObject(int goId);
	void DestroyGameObject(GameObject*go,bool removeChild=false);
	void DestroyGameObject(int goId,bool removeChild=false);
	Explosion* CreateExplosion(std::string explosion_type,NeoData&visual_data,NeoData&physics_data);
	//--c++ interface--//
	std::shared_ptr<Explosion> CreateExplosion_cpp(std::string& explosion_type,NeoData&visual_data,NeoData&physics_data);
private:
	NeoScene();
	virtual ~NeoScene();
	static NeoScene*_instance;
	std::unordered_map<int,GameObject*>list_gameObjects;
	int go_id_counter;
	//object pools
	ExplosionObjectPool object_pool_explosion;
};

#endif /* SRC_GAME_NEOSCENE_H_ */
