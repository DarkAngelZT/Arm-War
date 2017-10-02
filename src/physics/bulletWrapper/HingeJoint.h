/*
 * HingeConstraint.h
 *
 *  Created on: 2017年5月2日
 *      Author: neo
 */

#ifndef SRC_PHYSICS_BULLETWRAPPER_HINGEJOINT_H_
#define SRC_PHYSICS_BULLETWRAPPER_HINGEJOINT_H_
#include"RigidBody.h"
#include "../../game/Component.h"
class RigidBody;
class HingeJoint:public Component
{
public:
	HingeJoint(std::shared_ptr<btHingeConstraint>hinge,RigidBody*rbA,RigidBody*rbB);
	virtual ~HingeJoint();

	const std::shared_ptr<btHingeConstraint> getHinge() const
	{
		return m_hinge;
	}

	const RigidBody* getRbodyA() const
	{
		return rbodyA;
	}

	const RigidBody* getRbodyB() const
	{
		return rbodyB;
	}

	void setAngularOnly(bool angularOnly);
	void enableAngularMotor(bool enableMotor,float targetVelocity,float maxMotorImpulse);
	void enableMotor(bool enableMotor);
	void setMaxMotorImpulse(float maxMotorImpulse);
	void setMotorTarget(float targetAngle, float dt);
	void setLimit(float low,float high,float _softness = 0.9f, float _biasFactor = 0.3f, float _relaxationFactor = 1.0f);
	void setAxis(const irr::core::vector3df& axisInA);
	bool hasLimit();
	float getHingeAngle();
	bool getAngularOnly();
	bool getEnableAngularMotor();
	float getMotorTargetVelosity();
	float getMaxMotorImpulse();
//c++ interface
	int getInternalIndex() const
	{
		return m_internalIndex;
	}

	void setInternalIndex(int internalIndex)
	{
		m_internalIndex = internalIndex;
	}

private:
	std::shared_ptr<btHingeConstraint> m_hinge;
	RigidBody*rbodyA;
	RigidBody*rbodyB;
	int m_internalIndex;
};

#endif /* SRC_PHYSICS_BULLETWRAPPER_HINGEJOINT_H_ */
