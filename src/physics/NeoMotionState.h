/*
 * NeoMotionState.h
 *
 *  Created on: 2016年2月17日
 *      Author: neo
 */

#ifndef SRC_PHYSICS_NEOMOTIONSTATE_H_
#define SRC_PHYSICS_NEOMOTIONSTATE_H_

#include <LinearMath/btMotionState.h>
#include "../game/stdafx.h"

/*
 *绑定了gameobject的motionstate类
 */
class NeoMotionState: public btMotionState
{
public:
	NeoMotionState();
	NeoMotionState(irr::scene::ISceneNode*irrnode);
	NeoMotionState(irr::core::vector3df& pos,irr::core::vector3df& rot);
	virtual ~NeoMotionState();
	virtual void	getWorldTransform(btTransform& worldTrans )const;

	//Bullet only calls the update of worldtransform for active objects
	virtual void	setWorldTransform(const btTransform& worldTrans);
	const irr::scene::ISceneNode* getNode() const;
	void setNode( irr::scene::ISceneNode* node);
	const irr::core::vector3df& getInitialPos() const;
	void setInitialPos(const irr::core::vector3df& initialPos);
	const irr::core::vector3df& getInitialRot() const;
	void setInitialRot(const irr::core::vector3df& initialRot);

private:
	irr::scene::ISceneNode*m_node;
	irr::core::vector3df initialPos;
	irr::core::vector3df initialRot;
};

#endif /* SRC_PHYSICS_NEOMOTIONSTATE_H_ */
