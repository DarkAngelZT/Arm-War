/*
 * Effector.h
 *
 *  Created on: 2016年9月29日
 *      Author: neo
 */

#ifndef SRC_GRAPHICS_SFX_EFFECTOR_H_
#define SRC_GRAPHICS_SFX_EFFECTOR_H_
#include "../irrAddOn.h"
#include "../../Utilities/NeoData.h"
class NeoData;
//虚基类，特效器;
class Effector
{
public:
	Effector(){}
	virtual ~Effector(){}
	virtual void Play() = 0;
	virtual Effector* CreateClone() = 0;
	virtual void setParameters(NeoData&)=0;
	virtual NeoData& getParameters()=0;
};

#endif /* SRC_GRAPHICS_SFX_EFFECTOR_H_ */
