/*
 * NeoMotionState.cpp
 *
 *  Created on: 2016年2月17日
 *      Author: neo
 */

#include "NeoMotionState.h"

NeoMotionState::NeoMotionState()
{
	// TODO 自动生成的构造函数存根
	node = NULL;
}

NeoMotionState::NeoMotionState(irr::scene::ISceneNode* irrnode)
{
	node = irrnode;
}

NeoMotionState::NeoMotionState(irr::core::vector3df& pos,
		irr::core::vector3df& rot)
{
	node = NULL;
	initialPos = pos;
	initialRot = rot;
}

NeoMotionState::~NeoMotionState()
{
	// TODO 自动生成的析构函数存根
}

void NeoMotionState::getWorldTransform(btTransform& worldTrans) const
{
	btTransform trans;
	trans.setIdentity();
	trans.setOrigin(btVector3(initialPos.X, initialPos.Y, initialPos.Z));
	quaternion rot(initialRot*DEGTORAD);
	trans.setRotation(btQuaternion(rot.X, rot.Y, rot.Z, rot.W));
	worldTrans = trans;
}

void NeoMotionState::setWorldTransform(const btTransform& worldTrans)
{
	if (node)
	{
		irr::core::matrix4 mat;
		NeoPhysics::btTransformToIrrlichtMatrix(worldTrans, mat);
//		btQuaternion rot = worldTrans.getRotation();
//		quaternion qrot(rot.x(), rot.y(), rot.z(), rot.w());
//		vector3df rotation;
//		qrot.toEuler(rotation);
//		node->setRotation(rotation * RADTODEG);
//		btVector3 pos = worldTrans.getOrigin();
//		node->setPosition(vector3df(pos.x(), pos.y(), pos.z()));
		node->setPosition(mat.getTranslation());
		node->setRotation(mat.getRotationDegrees());
	}
}

const irr::scene::ISceneNode* NeoMotionState::getNode() const
{
	return node;
}

void NeoMotionState::setNode(irr::scene::ISceneNode* node)
{
	this->node = node;
	initialPos = node->getPosition();
	initialRot = node->getRotation();
}

const irr::core::vector3df& NeoMotionState::getInitialPos() const
{
	return initialPos;
}

void NeoMotionState::setInitialPos(const irr::core::vector3df& initialPos)
{
	this->initialPos = initialPos;
}

const irr::core::vector3df& NeoMotionState::getInitialRot() const
{
	return initialRot;
}

void NeoMotionState::setInitialRot(const irr::core::vector3df& initialRot)
{
	this->initialRot = initialRot;
}
