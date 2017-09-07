/*
 * NeoScene.cpp
 *
 *  Created on: 2016年2月3日
 *      Author: neo
 */

#include "NeoScene.h"

NeoScene* NeoScene::_instance = NULL;
NeoScene::NeoScene()
{
	// TODO 自动生成的构造函数存根
	go_id_counter = 0;
}

NeoScene* NeoScene::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new NeoScene();
	}
	return _instance;
}

void NeoScene::Destroy()
{
	if (_instance != NULL)
	{
		delete _instance;
	}
	_instance = NULL;
}

void NeoScene::Clean()
{
	std::unordered_map<int, GameObject*>::iterator goIter;
	for (goIter = list_gameObjects.begin(); goIter != list_gameObjects.end();
			goIter++)
	{
		delete goIter->second;
	}
	list_gameObjects.clear();
	go_id_counter = 0;
}

GameObject* NeoScene::CreateGameObject()
{
	GameObject* newgo = new GameObject();
	list_gameObjects.insert(std::pair<int, GameObject*>(go_id_counter, newgo));
	newgo->setId(go_id_counter);
	go_id_counter++;
	return newgo;
}

void NeoScene::DestroyGameObject(int goId, bool removeChild)
{
	std::unordered_map<int, GameObject*>::iterator goIter =
			list_gameObjects.find(goId);
	if (goIter != list_gameObjects.end())
	{
		GameObject*go = goIter->second;
		DestroyGameObject(go,removeChild);
	}
}

void NeoScene::DestroyGameObject(GameObject* go, bool removeChild)
{
	if (removeChild)
	{
		std::set<GameObject*> childList = go->GetChidren();
		for (std::set<GameObject*>::iterator iter = childList.begin();
				iter != childList.end(); iter++)
		{
			DestroyGameObject(*iter , removeChild);
		}
	}
	list_gameObjects.erase(go->getId());
	delete go;
}

GameObject* NeoScene::GetGameObject(int goId)
{
	std::unordered_map<int, GameObject*>::iterator iter = list_gameObjects.find(
			goId);
		if (iter != list_gameObjects.end())
		{
			return iter->second;
		}
		return NULL;
}

NeoScene::~NeoScene()
{
	// TODO 自动生成的析构函数存根
	Clean();
}

Explosion* NeoScene::CreateExplosion(std::string explosion_type,
		NeoData& visual_data, NeoData& physics_data)
{
	return object_pool_explosion.Create(explosion_type,visual_data,physics_data).get();
}

std::shared_ptr<Explosion> NeoScene::CreateExplosion_cpp(std::string& explosion_type,
		NeoData& visual_data, NeoData& physics_data)
{
	return object_pool_explosion.Create(explosion_type,visual_data,physics_data);
}
