/*
 * GhostObject.h
 *
 *  Created on: 2017年10月7日
 *      Author: neo
 */

#ifndef SRC_PHYSICS_BULLETWRAPPER_GHOSTOBJECT_H_
#define SRC_PHYSICS_BULLETWRAPPER_GHOSTOBJECT_H_

#include<memory>
#include <btBulletDynamicsCommon.h>
#include "BulletCollision/CollisionDispatch/btGhostObject.h"
#include "CollisionObject.h"

class GhostObject:public CollisionObject
{
public:
	GhostObject(std::shared_ptr<btGhostObject> p_ghostObj);
	virtual ~GhostObject();
	virtual void setEnabled(bool bEnabled);
	virtual void setActive(bool bActive);
	//----c++ interface
	std::shared_ptr<btGhostObject> getBtGhostObject();
private:
	std::shared_ptr<btGhostObject> m_ghostObject;
};

#endif /* SRC_PHYSICS_BULLETWRAPPER_GHOSTOBJECT_H_ */
