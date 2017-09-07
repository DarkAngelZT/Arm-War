/*
 * Ragdoll.h
 *
 *  Created on: 2017年5月13日
 *      Author: neo
 */

#ifndef SRC_PHYSICS_BULLETWRAPPER_RAGDOLL_H_
#define SRC_PHYSICS_BULLETWRAPPER_RAGDOLL_H_
#include "../NeoPhysics.h"
#include "../../game/Component.h"

class Ragdoll: public Component
{
public:
	Ragdoll();
	virtual ~Ragdoll();
};

#endif /* SRC_PHYSICS_BULLETWRAPPER_RAGDOLL_H_ */
