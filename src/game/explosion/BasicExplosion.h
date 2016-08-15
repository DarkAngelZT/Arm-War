/*
 * BasicExplosion.h
 *
 *  Created on: 2016年8月15日
 *      Author: neo
 */

#ifndef SRC_GAME_EXPLOSION_BASICEXPLOSION_H_
#define SRC_GAME_EXPLOSION_BASICEXPLOSION_H_
#include "../stdafx.h"
/*
 *
 */
class BasicExplosion
{
public:
	BasicExplosion();
	virtual ~BasicExplosion();

	void ExplosionCallback(int triggerIndex, btAlignedObjectArray<btCollisionObject*>&objects);
};

#endif /* SRC_GAME_EXPLOSION_BASICEXPLOSION_H_ */
