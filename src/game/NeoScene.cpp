/*
 * NeoScene.cpp
 *
 *  Created on: 2016年2月3日
 *      Author: neo
 */

#include "NeoScene.h"

SINGLETON_SOURCE(NeoScene)

NeoScene::NeoScene()
{
	go_id_counter = 0;
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
	m_effectors.clear();
	object_pool_explosion.Clear();
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
		DestroyGameObject(go, removeChild);
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
			DestroyGameObject(*iter, removeChild);
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

Effector* NeoScene::addSpriteAnimationEffector(
		const irr::core::vector3d<float>& position,
		const std::string& spriteFile,
		const irr::core::dimension2d<float>& size)
{
	BillboardAnimationEffectorParams param;
	param.origin = position;
	param.material_name = spriteFile;
	param.size = size;
	std::shared_ptr<Effector> ptr =
			NeoGraphics::getInstance()->getSfxManager()->AddEffector(
					"BillboardAnimation", param);
	m_effectors.push_back(ptr);
	return ptr.get();
}

void NeoScene::RemoveEffector(Effector* effector)
{
	auto it = m_effectors.begin();
	for (; it != m_effectors.end(); ++it)
	{
		if ((*it).get() == effector)
		{
			m_effectors.erase(it);
			break;
		}
	}

}

NeoScene::~NeoScene()
{
	Clean();
}

Explosion* NeoScene::CreateExplosion(std::string explosion_type,
		NeoData& visual_data, NeoData& physics_data)
{
	return object_pool_explosion.Create(explosion_type, visual_data,
			physics_data).get();
}

std::shared_ptr<Explosion> NeoScene::CreateExplosion_cpp(
		std::string& explosion_type, NeoData& visual_data,
		NeoData& physics_data)
{
	return object_pool_explosion.Create(explosion_type, visual_data,
			physics_data);
}

StandardTankBodyObject* NeoScene::CreateStandardTankBodyObject()
{
	StandardTankBodyObject* newgo = new StandardTankBodyObject();
	list_gameObjects.insert(std::pair<int, GameObject*>(go_id_counter, newgo));
	newgo->setId(go_id_counter);
	go_id_counter++;
	return newgo;
}

SimpleTankTrackObject* NeoScene::CreateSimpleTankTrackObject()
{
	SimpleTankTrackObject* newgo = new SimpleTankTrackObject();
	list_gameObjects.insert(std::pair<int, GameObject*>(go_id_counter, newgo));
	newgo->setId(go_id_counter);
	go_id_counter++;
	return newgo;
}
