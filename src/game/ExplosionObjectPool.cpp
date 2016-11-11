/*
 * ExplosionObjectPool.cpp
 *
 *  Created on: 2016年10月27日
 *      Author: neo
 */

#include "ExplosionObjectPool.h"
#include "explosion/BasicExplosion.h"

ExplosionObjectPool::ExplosionObjectPool()
{
	// TODO 自动生成的构造函数存根
	//bind creator
	RegisterCreator("BasiceExplosion",BasicExplosion::Create);
}

ExplosionObjectPool::~ExplosionObjectPool()
{
	// TODO 自动生成的析构函数存根
	explosion_creator.clear();
}

shared_ptr<Explosion> ExplosionObjectPool::Create(std::string& type,
		NeoData& param_visual, NeoData& param_pyhsics)
{
	if (inactive_objects.empty())
	{
		if (explosion_creator.count(type) == 0)
			return std::shared_ptr<Explosion>();
		std::shared_ptr<Explosion> obj = explosion_creator[type](param_visual,
				param_pyhsics);
		obj->setActive(true);
		//bind return function
		//small trick: bind the pointer to std::function, so when call, it will just be func()
		obj->setRecycleCallback(
				std::bind(&ExplosionObjectPool::Recycle, this, obj));
		active_objects.push_back(obj);
		return obj;
	}
	else
	{
		std::shared_ptr<Explosion> obj = inactive_objects.front();
		inactive_objects.pop_front();
		obj->setActive(true);
		obj->Reset();
		obj->setParams(param_visual, param_pyhsics);
		active_objects.push_back(obj);
		return obj;
	}
}

void ExplosionObjectPool::RegisterCreator(std::string type_str,
		std::function<shared_ptr<Explosion>(NeoData&, NeoData&)> functor)
{
	explosion_creator[type_str] = functor;
}
