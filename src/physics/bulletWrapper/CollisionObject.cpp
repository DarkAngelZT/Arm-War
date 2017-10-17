/*
 * CollisionObject.cpp
 *
 *  Created on: 2017年10月6日
 *      Author: neo
 */

#include "../../game/stdafx.h"
#include "CollisionObject.h"

CollisionObject::CollisionObject(
		std::shared_ptr<btCollisionObject> collisionObj) :
		m_collisionObject(collisionObj), m_internalIndex(-1)
{
}

CollisionObject::~CollisionObject()
{
}

void CollisionObject::setEnabled(bool bEnabled)
{
	if (bEnabled ^ enabled)
	{
		if (bEnabled && active)
		{
			NeoPhysics::getInstance()->AddCollisionObjectToWorld(this);
		}
		else
		{
			NeoPhysics::getInstance()->RemoveCollisionObjectFromWorld(this);
		}
	}
	this->enabled = bEnabled;
}

std::shared_ptr<btCollisionObject> CollisionObject::getBtCollisionObject()
{
	return m_collisionObject;
}

void CollisionObject::activate(bool forceActivation)
{
	m_collisionObject->activate(forceActivation);
}

void CollisionObject::setActive(bool bActive)
{
	if (bActive ^ active)
	{
		if (bActive && enabled)
		{
			NeoPhysics::getInstance()->AddCollisionObjectToWorld(this);
		}
		else
		{
			NeoPhysics::getInstance()->RemoveCollisionObjectFromWorld(this);
		}
	}
	this->active = bActive;
}

void CollisionObject::setPosition(irr::core::vector3df position)
{
	btVector3 pos = NeoPhysics::irrToBulletVector(position);
	m_collisionObject->getWorldTransform().setOrigin(pos);
}

void CollisionObject::setRotation(irr::core::vector3df rotation)
{
	quaternion rot(DEGTORAD * rotation);
	btQuaternion r = NeoPhysics::irrToBulletQuaternion(rot);
	m_collisionObject->getWorldTransform().setRotation(r);
}

void CollisionObject::EnableContinuousCollisionDetection(bool enabled)
{
	if (enabled)
	{
		m_collisionObject->setCcdMotionThreshold(1);
		btCollisionShape* shape = m_collisionObject->getCollisionShape();
		btVector3 center;
		float radius;
		shape->getBoundingSphere(center, radius);
		m_collisionObject->setCcdSweptSphereRadius(radius * 0.2f);
	}
	else
	{
		m_collisionObject->setCcdMotionThreshold(0);
		m_collisionObject->setCcdSweptSphereRadius(0);
	}
}

void CollisionObject::setFriction(float f)
{
	m_collisionObject->setFriction(f);
}

float CollisionObject::getFriction()
{
	return m_collisionObject->getFriction();
}
