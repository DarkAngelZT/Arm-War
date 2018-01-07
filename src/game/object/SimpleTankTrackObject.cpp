/*
 * SimpleTankTrackObject.cpp
 *
 *  Created on: 2017年9月11日
 *      Author: neo
 */

#include "SimpleTankTrackObject.h"
#include <limits>
#include "physics/bulletWrapper/RigidBody.h"
using namespace irr;

SimpleTankTrackObject::SimpleTankTrackObject() :
		m_speed(0)
{
}

SimpleTankTrackObject::~SimpleTankTrackObject()
{
}

void SimpleTankTrackObject::OnContactCallback(btPersistentManifold* pm,
		GameObject* another)
{
	RigidBody* rigidbody = getRigidBody();
	if (rigidbody)
	{
		core::vector3df dir(1, 0, 0);
		if (m_speed < 0)
		{
			dir.X = -1;
		}
		core::matrix4 mat = rigidbody->getCenterOfMassTransform();
		mat.rotateVect(dir);
		std::shared_ptr<btRigidBody> bt_rigidbody = rigidbody->getBtRigidBody();
		if (m_speed != 0)
			bt_rigidbody->activate(true);
		std::shared_ptr<btRigidBody> bt_another_rigidbody =
				another->getRigidBody()->getBtRigidBody();
//		float combinedFriction = btManifoldResult::calculateCombinedFriction(
//				bt_rigidbody.get(), bt_another_rigidbody.get());
		float combinedRestitution =
				btManifoldResult::calculateCombinedRestitution(
						bt_rigidbody.get(), bt_another_rigidbody.get());

		float min_distance = std::numeric_limits<int>::max();
		btVector3 minDir;
		float t_speed = core::abs_(m_speed);
		for (int j = 0; j < pm->getNumContacts(); j++)
		{
			btManifoldPoint& point = pm->getContactPoint(j);

			point.m_lateralFrictionInitialized = true;
			point.m_lateralFrictionDir1.setValue(dir.X, dir.Y, dir.Z);
			//point.m_lateralFrictionDir1.normalize();

			point.m_contactMotion1 = t_speed;
			point.m_combinedFriction = 9;
			point.m_combinedRestitution = combinedRestitution;
			if (abs_(point.m_distance1) < min_distance)
			{
				min_distance = abs_(point.m_distance1);
				btVector3 herizonLeft = point.m_lateralFrictionDir1.cross(
										point.m_normalWorldOnB);
				minDir = point.m_normalWorldOnB.cross(herizonLeft);
			}
		}
		//设置速度向量
		if (pm->getNumContacts() > 0)
		{
			btVector3 vel_new = t_speed * minDir;
			bt_rigidbody->setLinearVelocity(vel_new);
		}
	}
}

float SimpleTankTrackObject::getSpeed() const
{
	return m_speed;
}

RigidBody* SimpleTankTrackObject::AddRigidBody(int collisionShape, float mass)
{
	if (collisionShape == -1)
		return NULL;
	if (m_sceneNode)
	{
		matrix4 mat = m_sceneNode->getAbsoluteTransformation();
		vector3df pos = mat.getTranslation();
		vector3df rot = mat.getRotationDegrees();
		return GameObject::AddRigidBody(collisionShape, mass, pos, rot);
	}
	else
	{
		return GameObject::AddRigidBody(collisionShape, mass, core::vector3df(),
				core::vector3df());
	}
}

void SimpleTankTrackObject::setSpeed(float speed)
{
	m_speed = speed;
}
