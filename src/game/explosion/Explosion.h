/*
 * Explosion.h
 *
 *  Created on: 2016年10月25日
 *      Author: neo
 */

#ifndef SRC_GAME_EXPLOSION_EXPLOSION_H_
#define SRC_GAME_EXPLOSION_EXPLOSION_H_
#include "../stdafx.h"
#include "../NeoReusableObject.h"
class NeoData;
class NeoReusableObject;
class Explosion : public NeoReusableObject
{
public:
	Explosion(){}
	virtual ~Explosion(){}
	virtual void Play()=0;
	virtual void setParams(NeoData&visual_p,NeoData&physics_p)=0;
	static std::shared_ptr<Explosion> Create(NeoData&visual_p,NeoData&physics_p){}
};

#endif /* SRC_GAME_EXPLOSION_EXPLOSION_H_ */
