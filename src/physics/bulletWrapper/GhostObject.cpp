/*
 * GhostObject.cpp
 *
 *  Created on: 2017年10月7日
 *      Author: neo
 */

#include "../../game/stdafx.h"
#include "GhostObject.h"

GhostObject::GhostObject(std::shared_ptr<btGhostObject> p_ghostObj)
{
	m_collisionObject = m_ghostObject = p_ghostObj;
}

GhostObject::~GhostObject()
{
	if (m_internalIndex > 0)
	{
		NeoPhysics::getInstance()->RemoveGhostObject(m_internalIndex);
	}
}

std::shared_ptr<btGhostObject> GhostObject::getBtGhostObject()
{
	return m_ghostObject;
}

void GhostObject::setEnabled(bool bEnabled)
{
	CollisionObject::setEnabled(bEnabled);
	if (active && enabled)
	{
		NeoPhysics::getInstance()->AddActiveGhostObject(this);
	}
	else
	{
		NeoPhysics::getInstance()->RemoveActiveGhostObject(this);
	}
}

void GhostObject::setActive(bool bActive)
{
	CollisionObject::setActive(bActive);
	if (active && enabled)
	{
		NeoPhysics::getInstance()->AddActiveGhostObject(this);
	}
	else
	{
		NeoPhysics::getInstance()->RemoveActiveGhostObject(this);
	}
}
