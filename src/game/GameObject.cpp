/*
 * GameObject.cpp
 *
 *  Created on: 2016年1月31日
 *      Author: neo
 */
#include "NeoScene.h"
#include "GameObject.h"

GameObject::GameObject()
{
	// TODO 自动生成的构造函数存根
	id = -1;
	parent = NULL;
	m_sceneNode = NULL;
	active = true;
	visible = true;
	enablePyhsics = true;
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
}

int GameObject::getId() const
{
	return id;
}

template<typename T>
shared_ptr<T> GameObject::GetComponent(std::string& key)
{
	std::map<std::string, std::shared_ptr<NeoData>>::iterator iter = components.find(key);
	if (iter != components.end())
	{
		shared_ptr<T> ptr = static_cast<NeoTypedData<T>>(*iter->second)->getData();
		return ptr;
	}
	return shared_ptr<T>(NULL);
}

template<typename T>
shared_ptr<T> GameObject::AddComponent(std::string&key)
{
	shared_ptr<T> ptr(new T());
	components[key] = NeoTypedData<T>(ptr);
	return ptr;
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
}

void GameObject::SetRotation(vector3df& rot)
{
	if (m_sceneNode != NULL)
	{
		m_sceneNode->setRotation(rot);
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

void GameObject::BindSceneNode(int nodeIndex)
{
	m_sceneNode = NeoGraphics::GetInstance()->GetSceneNode(nodeIndex);
	NeoGraphics::GetInstance()->BindSceneNodeToGameObject(nodeIndex, this);
}

bool GameObject::isVisible() const
{
	return visible;
}

void GameObject::setVisible(bool visible)
{
	this->visible = visible;
}

bool GameObject::isEnablePyhsics() const
{
	return enablePyhsics;
}

void GameObject::setEnablePyhsics(bool enablePyhsics)
{
	this->enablePyhsics = enablePyhsics;
}
