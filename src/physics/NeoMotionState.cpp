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
	m_node = NULL;
}

NeoMotionState::NeoMotionState(irr::scene::ISceneNode* irrnode)
{
	setNode(irrnode);
}

NeoMotionState::NeoMotionState(irr::core::vector3df& pos,
		irr::core::vector3df& rot)
{
	m_node = NULL;
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
	quaternion rot(initialRot * DEGTORAD);
	trans.setRotation(btQuaternion(rot.X, rot.Y, rot.Z, rot.W));
	worldTrans = trans;
}

void NeoMotionState::setWorldTransform(const btTransform& worldTrans)
{
	if (m_node)
	{
		irr::core::matrix4 mat;
		NeoPhysics::btTransformToIrrlichtMatrix(worldTrans, mat);
		m_node->updateAbsolutePosition();
		matrix4 transform(m_node->getParent()->getAbsoluteTransformation(),
				irr::core::matrix4::EM4CONST_INVERSE);
		mat = transform * mat;

		m_node->setPosition(mat.getTranslation());
		m_node->setRotation(mat.getRotationDegrees());
	}
}

const irr::scene::ISceneNode* NeoMotionState::getNode() const
{
	return m_node;
}

void NeoMotionState::setNode(irr::scene::ISceneNode* node)
{
	this->m_node = node;
	if (node)
	{
		m_node->getParent()->updateAbsolutePosition();
		m_node->updateAbsolutePosition();
		matrix4 tranform = m_node->getAbsoluteTransformation();
		initialPos = tranform.getTranslation();
		initialRot = tranform.getRotationDegrees();
	}
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
