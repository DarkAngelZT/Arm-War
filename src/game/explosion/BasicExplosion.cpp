/*
 * BasicExplosion.cpp
 *
 *  Created on: 2016年10月7日
 *      Author: neo
 */

#include "BasicExplosion.h"
#include "../stdafx.h"

void BasicExplosion::setParams(NeoData& visual_p, NeoData& Physics_p)
{
	effector->setParameters(visual_p);
	physics_emulator->setParameters(Physics_p);
}

void BasicExplosion::setRecycleCallback(const std::function<void()>& funtor)
{
	if(physics_emulator)
	{
		physics_emulator->setFuncOnFinish(funtor);
	}
}

void BasicExplosion::Reset()
{
	physics_emulator->setActive(true);
}

BasicExplosion::BasicExplosion()
{
}

BasicExplosion::~BasicExplosion()
{
}

void BasicExplosion::Play()
{
	effector->Play();
	physics_emulator->Play();
}

std::shared_ptr<Explosion> BasicExplosion::Create(NeoData& visual_p,
		NeoData& physics_p)
{
	BasicExplosion* exp = new BasicExplosion();
	std::shared_ptr<Explosion> ptr(exp);
	exp->effector = NeoGraphics::getInstance()->getSfxManager()->AddEffector(
			"BasicExplosionEffector", visual_p);
	exp->physics_emulator = NeoPhysics::getInstance()->CreateExplosion(
			"BasicExplosionPhysics", physics_p);
	return ptr;
}

const std::shared_ptr<Effector>& BasicExplosion::getEffector() const
{
	return effector;
}

void BasicExplosion::setEffector(const std::shared_ptr<Effector>& effector)
{
	this->effector = effector;
}

const std::shared_ptr<ExplosionPhysics>& BasicExplosion::getPhysicsEmulator() const
{
	return physics_emulator;
}

void BasicExplosion::setPhysicsEmulator(
		const std::shared_ptr<ExplosionPhysics>& physicsEmulator)
{
	physics_emulator = physicsEmulator;
}
