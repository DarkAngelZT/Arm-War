/*
 * CollisionObject.h
 *
 *  Created on: 2017年10月6日
 *      Author: neo
 */

#ifndef SRC_PHYSICS_BULLETWRAPPER_COLLISIONOBJECT_H_
#define SRC_PHYSICS_BULLETWRAPPER_COLLISIONOBJECT_H_

#include<memory>
#include <btBulletDynamicsCommon.h>
#include "../../game/NeoReusableObject.h"
#include "../../game/Component.h"

class CollisionObject: public NeoReusableObject, public Component
{
public:
	CollisionObject(std::shared_ptr<btCollisionObject> collisionObj);
	virtual ~CollisionObject();
	virtual void setEnabled(bool bEnabled);
	virtual void setActive(bool bActive);
	void activate(bool forceActivation = false);
	//c++ interface
	std::shared_ptr<btCollisionObject> getBtCollisionObject();
	int getInternalIndex() const
	{
		return m_internalIndex;
	}

	void setInternalIndex(int internalIndex)
	{
		m_internalIndex = internalIndex;
	}
	virtual void setPosition(irr::core::vector3df position);
	virtual void setRotation(irr::core::vector3df rotation);
protected:
	CollisionObject()
	{
	}
	std::shared_ptr<btCollisionObject> m_collisionObject;
	int m_internalIndex;
};

#endif /* SRC_PHYSICS_BULLETWRAPPER_COLLISIONOBJECT_H_ */
