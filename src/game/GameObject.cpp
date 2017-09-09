/*
 * GameObject.cpp
 *
 *  Created on: 2016年1月31日
 *      Author: neo
 */
#include "NeoScene.h"
#include "GameObject.h"

GameObject::GameObject() :
		m_rigidBody(NULL), collisionShapeIndex(-1)
{
	// TODO 自动生成的构造函数存根
	id = -1;
	parent = NULL;
	m_sceneNode = NULL;
	active = true;
	visible = true;
	lua_indentifier = "";
}

GameObject::~GameObject()
{
	// TODO 自动生成的析构函数存根
	//detach children
	for (std::set<GameObject*>::iterator iter = list_chidren.begin();
			iter != list_chidren.end(); iter++)
	{
		(*iter)->SetParent(NULL);
	}
	components.clear();
	list_chidren.clear();
	if (NULL != m_rigidBody)
	{
		delete m_rigidBody;
	}
}

int GameObject::getId() const
{
	return id;
}

shared_ptr<Component> GameObject::getComponent(const std::string&key)
{
	std::map<std::string, std::shared_ptr<Component>>::iterator iter =
			components.find(key);
	if (iter != components.end())
	{
		shared_ptr<Component> ptr = iter->second;
		return ptr;
	}
	return shared_ptr<Component>(NULL);
}

Component* GameObject::getComponent(std::string& key)
{
	shared_ptr<Component> component_ptr = getComponent(
			const_cast<const std::string&>(key));
	if (!component_ptr)
		return NULL;
	else
		return component_ptr.get();
}

void GameObject::AddComponent(std::string&key, Component* c)
{
	shared_ptr<Component> ptr(c);
	components[key] = ptr;
}

void GameObject::RemoveComponent(std::string& key)
{
	components.erase(key);
}

void GameObject::SetParent(GameObject*newParent)
{
	if (parent)
	{
		parent->RemoveChild(this);
	}
	parent = newParent;
	if (newParent)
		newParent->AddChild(this);
}

std::set<GameObject*>& GameObject::GetChidren()
{
	return list_chidren;
}

void GameObject::SetPostion(vector3df& pos)
{
	if (m_sceneNode != NULL)
	{
		m_sceneNode->setPosition(pos);
	}
	if (m_rigidBody)
	{
		m_rigidBody->setPosition(pos);
	}
}

void GameObject::SetRotation(vector3df& rot)
{
	if (m_sceneNode != NULL)
	{
		m_sceneNode->setRotation(rot);
	}

	if (m_rigidBody)
	{
		m_rigidBody->setRotation(rot);
	}
}

vector3df GameObject::GetPostion() const
{
	vector3df result;
	if (m_sceneNode != NULL)
		result = m_sceneNode->getPosition();
	return result;
}

vector3df GameObject::GetRotation() const
{
	vector3df result;
	if (m_sceneNode != NULL)
		result = m_sceneNode->getRotation();
	return result;
}

void GameObject::RemoveChild(GameObject* child)
{
	list_chidren.erase(child);
	if (child->GetParent() == this)
	{
		child->SetParent(NULL);
	}
}

void GameObject::DestoryChild(GameObject* child)
{
	NeoScene::GetInstance()->DestroyGameObject(child, true);
	RemoveChild(child);
}

GameObject* GameObject::GetParent() const
{
	return parent;
}

void GameObject::RemoveChildren()
{
	for (std::set<GameObject*>::iterator iter = list_chidren.begin();
			iter != list_chidren.end(); iter++)
	{
		if ((*iter)->GetParent() == this)
		{
			(*iter)->SetParent(NULL);
		}
	}
	list_chidren.clear();
}

void GameObject::setId(int id)
{
	this->id = id;
}

void GameObject::AddChild(GameObject*child)
{
	list_chidren.insert(child);
}

void GameObject::DestroyChidren()
{
	for (std::set<GameObject*>::iterator iter = list_chidren.begin();
			iter != list_chidren.end(); iter++)
	{
		NeoScene::GetInstance()->DestroyGameObject(*iter, true);
	}
}

bool GameObject::isActive() const
{
	return active;
}

void GameObject::setActive(bool active)
{
	if (active)
	{
		//set visual node
		if (m_sceneNode)
		{
			m_sceneNode->setVisible(visible);
		}
		//set physics object
	}
	else
	{
		//set visual node
		if (m_sceneNode)
		{
			m_sceneNode->setVisible(false);
		}
		//set physics object
	}
	this->active = active;
}

irr::scene::ISceneNode* GameObject::GetSceneNode()
{
	return m_sceneNode;
}

void GameObject::setSceneNode(irr::scene::ISceneNode*node)
{
	m_sceneNode = node;
	node->setUserData(this);
}

bool GameObject::isVisible() const
{
	return visible;
}

void GameObject::setVisible(bool visible)
{
	this->visible = visible;
}

const RigidBody* GameObject::getRigidBody() const
{
	return m_rigidBody;
}

RigidBody* GameObject::AddRigidBody(int collisionShape, float mass)
{
	if (collisionShape == -1 || m_sceneNode)
		return NULL;
	matrix4 mat = m_sceneNode->getAbsoluteTransformation();
	vector3df pos = mat.getTranslation();
	vector3df rot = mat.getRotationDegrees();
	return AddRigidBody(collisionShape, mass, pos, rot);
}

RigidBody* GameObject::AddRigidBody(int collisionShape, float mass,
		const vector3df& position, const vector3df& rotation)
{
	collisionShapeIndex = collisionShape;
	m_rigidBody = NeoPhysics::getInstance()->CreateRigidBody(
			collisionShapeIndex, m_sceneNode, mass, position, rotation);
	m_rigidBody->setUserData(this);
	return m_rigidBody;
}

void GameObject::OnCollisionEnter(GameObject* another)
{
	if (m_lua_OnCollisionEnter_callback.empty())
		return;
	std::vector<std::string> data;
	data.push_back(getLuaIdentifier());
	data.push_back(another->getLuaIdentifier());
	NeoScript::getInstance()->ExecuteScriptedFunction(
			m_lua_OnCollisionEnter_callback, data);
}

void GameObject::OnCollision(GameObject* another)
{
	if (m_lua_OnCollision_callback.empty())
		return;
	std::vector<std::string> data;
	data.push_back(getLuaIdentifier());
	data.push_back(another->getLuaIdentifier());
	NeoScript::getInstance()->ExecuteScriptedFunction(
			m_lua_OnCollision_callback, data);
}

void GameObject::OnCollisionExit(GameObject* another)
{
	if (m_lua_OnCollisionExit_callback.empty())
		return;
	std::vector<std::string> data;
	data.push_back(getLuaIdentifier());
	data.push_back(another->getLuaIdentifier());
	NeoScript::getInstance()->ExecuteScriptedFunction(
			m_lua_OnCollisionExit_callback, data);
}

void GameObject::OnContactCallback(btPersistentManifold* pm,
		GameObject* another)
{
}

std::string GameObject::getLuaIdentifier() const
{
	return lua_indentifier;
}

void GameObject::setLuaIdentifier(const std::string& luaIndentifier)
{
	lua_indentifier = luaIndentifier;
}

void GameObject::setOnCollisionEnterLuaCallback(std::string& func)
{
	m_lua_OnCollisionEnter_callback = func;
}

void GameObject::setOnCollisionLuaCallback(std::string& func)
{
	m_lua_OnCollision_callback = func;
}

void GameObject::setOnCollisionExitLuaCallback(std::string& func)
{
	m_lua_OnCollisionExit_callback = func;
}

