/*
 * ExplosionPhysics.h
 *
 *  Created on: 2016年10月25日
 *      Author: neo
 */

#ifndef SRC_PHYSICS_EXPLOSIONPHYSICS_H_
#define SRC_PHYSICS_EXPLOSIONPHYSICS_H_
#include "../Utilities/NeoData.h"
#include <memory>
class NeoData;
class ExplosionPhysics
{
public:
	ExplosionPhysics()
	{
		active=true;
	}
	virtual ~ExplosionPhysics()
	{
	}
	virtual void Play()=0;
	virtual void setParameters(NeoData&)=0;
	virtual NeoData& getParameters()=0;
	virtual bool isActive()
	{
		return active;
	}
	virtual void setActive(bool state)
	{
		active = state;
	}
	virtual void setFuncOnFinish(const std::function<void()>& funcOnFinish){}
protected:
	bool active;
};

#endif /* SRC_PHYSICS_EXPLOSIONPHYSICS_H_ */
