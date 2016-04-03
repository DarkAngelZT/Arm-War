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
private:
	NeoScene();
	virtual ~NeoScene();
	static NeoScene*_instance;
	std::unordered_map<int,GameObject*>list_gameObjects;
	int go_id_counter;
};

#endif /* SRC_GAME_NEOSCENE_H_ */
