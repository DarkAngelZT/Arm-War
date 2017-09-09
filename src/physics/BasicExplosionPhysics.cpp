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
	// TODO 自动生成的析构函数存根
}

void BasicExplosionPhysics::Play()
{
	if (!active)
		return;
	NeoPhysics::getInstance()->GetObjectsInArea(params.fRange, params.origin,
			std::bind(&BasicExplosionPhysics::BasicExplosionCallback, this,
					std::placeholders::_1, std::placeholders::_2));
}

void BasicExplosionPhysics::BasicExplosionCallback(int triggerIndex,
		btAlignedObjectArray<btCollisionObject*>& objects)
{
	btVector3 origin = NeoPhysics::irrToBulletVector(params.origin);
	//如果有物体阻挡，则判定爆炸不会波及到;
	for (int i = 0; i < objects.size(); ++i)
	{
		//ray test for each object
		GameObject*go = static_cast<GameObject*>(objects[i]->getUserPointer());
		if (go == NULL)
		{
			continue;
		}
		irr::core::vector3df pos = go->GetPostion();
		btVector3 target = NeoPhysics::irrToBulletVector(pos);
		btCollisionWorld::ClosestRayResultCallback RayCallback(origin, target);
		NeoPhysics::getInstance()->getDynamicsWorld()->rayTest(origin, target,
				RayCallback);
		if (RayCallback.hasHit())
		{
			if (RayCallback.m_collisionObject == objects[i])
			{
				btVector3 impulseDir = target - origin;
				float range = impulseDir.norm();
				//apply event function here
				std::vector<std::string> luaValues;
				luaValues.push_back(go->getLuaIdentifier());
				luaValues.push_back(std::to_string(range));
				luaValues.insert(luaValues.begin() + 2,
						params.aScriptValus.begin(), params.aScriptValus.end());
				NeoGameLogic::GetInstance()->TriggerEvent(params.nEventID,
						luaValues);
				//apply physics force
				shared_ptr<btRigidBody> rbody = go->getRigidBody()->getBtRigidBody();
				if (rbody)
				{
					btVector3 impulse = impulseDir.normalized();
					if (params.bAttenuateByRange)
					{
						impulse *= params.fImpulse * (range / params.fRange);
					}
					else
					{
						impulse *= params.fImpulse;
					}
					rbody->applyCentralImpulse(impulse);
				}
			}
		}
	}
	active=false;
	if(func_on_finish)
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
