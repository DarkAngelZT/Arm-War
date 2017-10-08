/*
 * BasicExplosionPhysics.cpp
 *
 *  Created on: 2016年8月15日
 *      Author: neo
 */

#include "BasicExplosionPhysics.h"
#include <string>

BasicExplosionPhysics::BasicExplosionPhysics(BasicExplosionParams& param)
{
	params = param;
	active = true;
}

BasicExplosionPhysics::~BasicExplosionPhysics()
{
}

void BasicExplosionPhysics::Play()
{
	if (!active)
		return;
	NeoPhysics::getInstance()->GetObjectsInArea(params.fRange, params.origin,
			std::bind(&BasicExplosionPhysics::BasicExplosionCallback, this,
					std::placeholders::_1, std::placeholders::_2));
}

void BasicExplosionPhysics::BasicExplosionCallback(GhostObject*triggerObject,
		btAlignedObjectArray<btCollisionObject*>& objects)
{
	btVector3 origin = NeoPhysics::irrToBulletVector(params.origin);
	//如果有物体阻挡，则判定爆炸不会波及到;
	for (int i = 0; i < objects.size(); ++i)
	{
		btVector3 target = objects[i]->getWorldTransform().getOrigin();
		btVector3 impulseDir = target - origin;
		float range = impulseDir.norm();
		if (range > params.fRange)
			continue;
		//ray test for each object
		GameObject*go = static_cast<GameObject*>(objects[i]->getUserPointer());
		if (go == NULL)
		{
			continue;
		}
		btCollisionWorld::ClosestRayResultCallback RayCallback(origin, target);
		NeoPhysics::getInstance()->getDynamicsWorld()->rayTest(origin, target,
				RayCallback);
		if (RayCallback.hasHit())
		{
			GameObject*go_target =
					static_cast<GameObject*>(RayCallback.m_collisionObject->getUserPointer());
			if (!go)
				continue;
			if (go == go_target)
			{
				//apply event function here
				std::vector<std::string> luaValues;
				luaValues.push_back(go->getLuaIdentifier());
				luaValues.push_back(std::to_string(range));
				luaValues.insert(luaValues.begin() + 2,
						params.aScriptValus.begin(), params.aScriptValus.end());
				luaValues.push_back(std::to_string(params.bAttenuateByRange));
				NeoGameLogic::getInstance()->TriggerEvent(params.nEventID,
						luaValues);
				//apply physics force
				btRigidBody* rbody = btRigidBody::upcast(objects[i]);
				if (rbody)
				{
					btVector3 impulse = impulseDir.normalized();
					if (params.bAttenuateByRange)
					{
						impulse *= params.fImpulse
								* (1 - range / params.fRange);
					}
					else
					{
						impulse *= params.fImpulse;
					}
					rbody->applyCentralImpulse(impulse);
					rbody->activate(true);
				}
			}
		}
	}
	active = false;
	if (func_on_finish)
		func_on_finish();
}

std::shared_ptr<ExplosionPhysics> BasicExplosionPhysics::Create(NeoData& data)
{
	return std::shared_ptr<ExplosionPhysics>(
			new BasicExplosionPhysics(static_cast<BasicExplosionParams&>(data)));
}

void BasicExplosionPhysics::setParameters(NeoData& data)
{
	params = static_cast<BasicExplosionParams&>(data);
}

NeoData& BasicExplosionPhysics::getParameters()
{
	return params;
}

const std::function<void()>& BasicExplosionPhysics::getFuncOnFinish() const
{
	return func_on_finish;
}

void BasicExplosionPhysics::setFuncOnFinish(
		const std::function<void()>& funcOnFinish)
{
	func_on_finish = funcOnFinish;
}
