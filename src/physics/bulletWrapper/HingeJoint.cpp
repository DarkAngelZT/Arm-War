/*
 * HingeConstraint.cpp
 *
 *  Created on: 2017年5月2日
 *      Author: neo
 */

#include "HingeJoint.h"

HingeJoint::HingeJoint(std::shared_ptr<btHingeConstraint> hinge, RigidBody*rbA,
		RigidBody*rbB) :
		m_hinge(hinge), rbodyA(rbA), rbodyB(rbB),m_internalIndex(-1)
{
}

HingeJoint::~HingeJoint()
{
	// TODO 自动生成的析构函数存根
	if(m_internalIndex>0)
		NeoPhysics::getInstance()->RemoveJoint(m_internalIndex);
}

void HingeJoint::setAngularOnly(bool angularOnly)
{
	m_hinge->setAngularOnly(angularOnly);
}

void HingeJoint::enableAngularMotor(bool enableMotor, float targetVelocity,
		float maxMotorImpulse)
{
	m_hinge->enableAngularMotor(enableMotor,targetVelocity,maxMotorImpulse);
}

void HingeJoint::enableMotor(bool enableMotor)
{
	m_hinge->enableMotor(enableMotor);
}

void HingeJoint::setMaxMotorImpulse(float maxMotorImpulse)
{
	m_hinge->setMaxMotorImpulse(maxMotorImpulse);
}

void HingeJoint::setMotorTarget(float targetAngle, float dt)
{
	m_hinge->setMotorTarget(targetAngle,dt);
}

void HingeJoint::setLimit(float low, float high, float _softness,
		float _biasFactor, float _relaxationFactor)
{
	m_hinge->setLimit(low,high,_softness,_biasFactor,_relaxationFactor);
}

void HingeJoint::setAxis(const irr::core::vector3df& axisInA)
{
	btVector3 axis=NeoPhysics::irrToBulletVector(axisInA);
	m_hinge->setAxis(axis);
}

bool HingeJoint::hasLimit()
{
	return m_hinge->hasLimit();
}

float HingeJoint::getHingeAngle()
{
	return m_hinge->getHingeAngle();
}

bool HingeJoint::getAngularOnly()
{
	return m_hinge->getAngularOnly();
}

bool HingeJoint::getEnableAngularMotor()
{
	return m_hinge->getEnableAngularMotor();
}

float HingeJoint::getMotorTargetVelosity()
{
	return m_hinge->getMotorTargetVelosity();
}

float HingeJoint::getMaxMotorImpulse()
{
	return m_hinge->getMaxMotorImpulse();
}
