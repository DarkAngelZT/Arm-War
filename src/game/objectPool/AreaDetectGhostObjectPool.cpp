/*
 * GhostObjectPool.cpp
 *
 *  Created on: 2017年10月7日
 *      Author: neo
 */
#include "../../physics/NeoPhysics.h"
#include "AreaDetectGhostObjectPool.h"

AreaDetectGhostObjectPool::AreaDetectGhostObjectPool()
{
}

AreaDetectGhostObjectPool::~AreaDetectGhostObjectPool()
{
}

std::shared_ptr<GhostObject> AreaDetectGhostObjectPool::Create(float radius,
		irr::core::vector3df pos,
		std::function<
				void(GhostObject*, btAlignedObjectArray<btCollisionObject*> &)> overlapCallback)
{
	NeoPhysics* physics = NeoPhysics::getInstance();
	if (inactive_objects.empty())
	{
		int collisionIndex = physics->CreateSphereShape(1);
		GhostObject* object = physics->CreateGhostObject(collisionIndex,
				overlapCallback, pos, irr::core::vector3df(0, 0, 0));
		btSphereShape* shape =
				static_cast<btSphereShape*>(object->getBtGhostObject()->getCollisionShape());
		shape->setLocalScaling(btVector3(radius, 0, 0));
		physics->AddCollisionObjectToWorld(object);
		physics->AddActiveGhostObject(object);
		std::shared_ptr<GhostObject> object_ptr(object);
		active_objects.push_back(object_ptr);
		return object_ptr;
	}
	else
	{
		std::shared_ptr<GhostObject> obj = inactive_objects.front();
		inactive_objects.pop_front();
		active_objects.push_back(obj);
		btSphereShape* sphere =
				static_cast<btSphereShape*>(obj->getBtGhostObject()->getCollisionShape());
		sphere->setLocalScaling(btVector3(radius, 0, 0));
		obj->setPosition(pos);
		obj->setActive(true);
		physics->GhostObjectSetOverLapCallback(obj.get(),overlapCallback);
		return obj;
	}
}

void AreaDetectGhostObjectPool::AddToRecycleQueue(
		std::shared_ptr<GhostObject> object)
{
	m_recycleQueue.push_back(object);
}

void AreaDetectGhostObjectPool::RecyleAll()
{
	if (!m_recycleQueue.empty())
	{
		for (std::shared_ptr<GhostObject> ptr : m_recycleQueue)
		{
			Recycle(ptr);
		}
		m_recycleQueue.clear();
	}
}

void AreaDetectGhostObjectPool::Clear()
{
	m_recycleQueue.clear();
	NeoObjectPool::Clear();
}
