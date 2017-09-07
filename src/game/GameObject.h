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
#include "Component.h"

using namespace irr::core;
using namespace std;

class Component;
class RigidBody;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	std::shared_ptr<Component> getComponent(const std::string&key);
	Component* getComponent(std::string&key);
	void AddComponent(std::string&key,Component*comp);
	void RemoveComponent(std::string&key);
	irr::scene::ISceneNode* GetSceneNode();
	void BindSceneNode(irr::scene::ISceneNode*node);

	void SetParent(GameObject*);
	GameObject*GetParent() const;
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
	vector3df GetPostion() const;
	vector3df GetRotation() const;
	int getId() const;
	void setId(int id);
	bool isActive() const;
	void setActive(bool active);
	bool isVisible() const;
	void setVisible(bool visible);
	//---physics callback
	virtual void OnCollisionEnter(GameObject*another);
	virtual void OnCollision(GameObject*another);
	virtual void OnCollisionExit(GameObject*another);
	virtual void OnContactCallback(btPersistentManifold*pm, GameObject*another);
	const RigidBody* getRigidBody() const;
	RigidBody* AddRigidBody(int collisionShape, float mass);
	RigidBody* AddRigidBody(int collisionShape, float mass,
			const vector3df& position, const vector3df& rotation);
	std::string getLuaIndentifier() const;
	void setLuaIndentifier(const std::string& luaIndentifier);

	//-----lua helper functions------------
	void setOnCollisionEnterLuaCallback(std::string&func);
	void setOnCollisionLuaCallback(std::string&func);
	void setOnCollisionExitLuaCallback(std::string&func);

private:
	std::map<std::string, std::shared_ptr<Component>> components;
	GameObject*parent;
	std::set<GameObject*> list_chidren;
	irr::scene::ISceneNode*m_sceneNode;
	RigidBody*m_rigidBody;
	int collisionShapeIndex;
	int id;
	std::string lua_indentifier;
	bool visible;
	bool active;

	std::string m_lua_OnCollisionEnter_callback;
	std::string m_lua_OnCollision_callback;
	std::string m_lua_OnCollisionExit_callback;
};

#endif /* SRC_GAME_GAMEOBJECT_H_ */
