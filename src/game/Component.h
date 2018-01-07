/*
 * Component.h
 *
 *  Created on: 2017年5月6日
 *      Author: neo
 */

#ifndef SRC_GAME_COMPONENT_H_
#define SRC_GAME_COMPONENT_H_
#include "GameObject.h"
class GameObject;
class Component
{
public:
	Component();
	virtual ~Component();

	virtual bool isEnabled() const
	{
		return enabled;
	}

	virtual void setEnabled(bool enabled)
	{
		this->enabled = enabled;
	}

	virtual void Update(){}

	void setGameObject(GameObject* go);
	GameObject* getGameObject();
protected:
	bool enabled;
	GameObject* gameObject;
};

#endif /* SRC_GAME_COMPONENT_H_ */
