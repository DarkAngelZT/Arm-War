/*
 * GameObject.h
 *
 *  Created on: 2016年1月31日
 *      Author: neo
 */

#ifndef SRC_GAME_GAMEOBJECT_H_
#define SRC_GAME_GAMEOBJECT_H_
#include"stdafx.h"
#include<map>
#include<set>
#include <functional>
#include "../Utilities/NeoTypedData.h"

 using namespace irr::core;
 using namespace std;
class GameObject
{
public:
	 GameObject();
	 virtual ~GameObject();
	template<typename T>
	shared_ptr<T>  GetComponent(std::string&key);
	template<typename T>
	shared_ptr<T>  AddComponent(std::string&key);
	void RemoveComponent(std::string&key);
	irr::scene::ISceneNode* GetSceneNode();
	void BindSceneNode(int nodeIndex);

	void SetParent(GameObject*);
	GameObject*GetParent()const;
	void AddChild(GameObject*);
	void RemoveChild(GameObject*child);
	//remove all child (just unregister them, won't delete)
	void RemoveChildren();
	std::set<GameObject*>& GetChidren();
	void DestoryChild(GameObject*child);
	void DestroyChidren();
	//transform functions
	void SetPostion(vector3df& pos);
	void SetRotation(vector3df& rot);
	vector3df GetPostion()const;
	vector3df GetRotation()const;
	int getId() const;
	void setId(int id);
	bool isActive() const;
	void setActive(bool active);
	bool isVisible() const;
	void setVisible(bool visible);
	bool isEnablePyhsics() const;
	void setEnablePyhsics(bool enablePyhsics);
	//---physics callback
	virtual void OnCollisionEnter(GameObject*another);
	virtual void OnCollision(GameObject*another);
	virtual void OnCollisionExit(GameObject*another);
	virtual void OnContactCallback(btPersistentManifold*pm,GameObject*another);
	//----------------------------

private:
	std::map<std::string,std::shared_ptr<NeoData>>components;
	GameObject*parent;
	std::set<GameObject*>list_chidren;
	irr::scene::ISceneNode*m_sceneNode;
	std::shared_ptr<btRigidBody>m_rigidBody;
	int id;
	bool visible;
	bool enablePyhsics;
	bool active;
//	std::set<std::function<void(GameObject*)>>m_on_collisionEnter_callbacks;
//	std::set<std::function<void(GameObject*)>>m_on_collision_callbacks;
//	std::set<std::function<void(GameObject*)>>m_on_collisionExit_callbacks;
//	std::set<std::function<void(btPersistentManifold*,GameObject*)>>m_on_contact_callbacks;
	std::vector<std::string>m_lua_OnCollisionEnter_callback;
	std::vector<std::string>m_lua_OnCollision_callback;
	std::vector<std::string>m_lua_OnCollisionExit_callback;
};


#endif /* SRC_GAME_GAMEOBJECT_H_ */
