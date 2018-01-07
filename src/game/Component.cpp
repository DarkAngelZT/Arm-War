/*
 * Component.cpp
 *
 *  Created on: 2017年5月6日
 *      Author: neo
 */

#include "Component.h"

Component::Component() :
		enabled(true),gameObject(nullptr)
{

}

Component::~Component()
{
}

void Component::setGameObject(GameObject* go)
{
	gameObject = go;
}

GameObject* Component::getGameObject()
{
	return gameObject;
}
