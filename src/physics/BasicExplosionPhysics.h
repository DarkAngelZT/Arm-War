/*
 * BasicExplosionPhysics.h
 *
 *  Created on: 2016年8月15日
 *      Author: neo
 */

#ifndef SRC_GAME_EXPLOSION_BASICEXPLOSIONPHYSICS_H_
#define SRC_GAME_EXPLOSION_BASICEXPLOSIONPHYSICS_H_
#include "../game/stdafx.h"
#include "../game/NeoGameLogic.h"
#include "ExplosionPhysics.h"
using namespace std;
class ExplosionPhysics;
class BasicExplosionPhysics: public ExplosionPhysics
{
public:
	BasicExplosionPhysics(BasicExplosionParams& param);
	virtual ~BasicExplosionPhysics();
	static std::shared_ptr<ExplosionPhysics> Create(NeoData&data);

	virtual void Play();
	virtual void setParameters(NeoData&data);
	virtual NeoData& getParameters();
	void BasicExplosionCallback(int triggerIndex,
			btAlignedObjectArray<btCollisionObject*>&objects);
	const std::function<void()>& getFuncOnFinish() const;
	virtual void setFuncOnFinish(const std::function<void()>& funcOnFinish);

private:
	BasicExplosionParams params;
	std::function<void()>func_on_finish;
};

#endif /* SRC_GAME_EXPLOSION_BASICEXPLOSIONPHYSICS_H_ */
