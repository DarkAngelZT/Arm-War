/*
 * RigidBody.h
 *
 *  Created on: 2017年5月2日
 *      Author: neo
 */

#ifndef SRC_PHYSICS_BULLETWRAPPER_RIGIDBODY_H_
#define SRC_PHYSICS_BULLETWRAPPER_RIGIDBODY_H_
#include "../NeoPhysics.h"
#include "CollisionObject.h"

/*
 * Wrapper for rigidbody, used for unify the vector
 * variable and export interface for lua
 */
class RigidBody:public CollisionObject
{
public:
	RigidBody(std::shared_ptr<btRigidBody> body);
	virtual ~RigidBody();
	//general interface
	void applyGravity();

	void setGravity(irr::core::vector3df& acceleration);

	irr::core::vector3df getGravity() const;

	void setDamping(float lin_damping, float ang_damping);

	float getLinearDamping() const;

	float getAngularDamping() const;

	float getLinearSleepingThreshold() const;

	float getAngularSleepingThreshold() const;

	void applyDamping(float timeStep);

	void setMassProps(float mass, irr::core::vector3df& inertia);

	const irr::core::vector3df getLinearFactor() const;
	void setLinearFactor(irr::core::vector3df& linearFactor);
	float getInvMass() const;

	void integrateVelocities(float step);

	void setCenterOfMassTransform(irr::core::matrix4& xform);

	void applyCentralForce(irr::core::vector3df& force);

	const irr::core::vector3df getTotalForce() const;

	const irr::core::vector3df getTotalTorque() const;

	const irr::core::vector3df getInvInertiaDiagLocal() const;

	void setInvInertiaDiagLocal(irr::core::vector3df& diagInvInertia);

	void setSleepingThresholds(float linear, float angular);

	void applyTorque(irr::core::vector3df& torque);

	void applyForce(irr::core::vector3df& force,
			irr::core::vector3df& rel_pos);

	void applyCentralImpulse(irr::core::vector3df& impulse);

	void applyTorqueImpulse(irr::core::vector3df& torque);

	void applyImpulse(irr::core::vector3df& impulse,
			irr::core::vector3df& rel_pos);

	void clearForces();

	void updateInertiaTensor();

	const irr::core::vector3df getCenterOfMassPosition() const;
	irr::core::quaternion getOrientation() const;

	irr::core::matrix4 getCenterOfMassTransform() const;
	irr::core::vector3df getLinearVelocity() const;
	irr::core::vector3df getAngularVelocity() const;

	void setLinearVelocity(irr::core::vector3df& lin_vel);

	void setAngularVelocity(irr::core::vector3df& ang_vel);

	irr::core::vector3df getVelocityInLocalPoint(
			irr::core::vector3df& rel_pos) const;

	void translate(irr::core::vector3df& v);

	void getAabb(irr::core::vector3df& aabbMin,
			irr::core::vector3df& aabbMax) const;

	float computeImpulseDenominator(irr::core::vector3df& pos,
			irr::core::vector3df& normal) const;

	float computeAngularImpulseDenominator(irr::core::vector3df& axis) const;

	void updateDeactivation(float timeStep);

	void setAngularFactor(irr::core::vector3df& angFac);

	void setAngularFactor(float angFac);

	irr::core::vector3df getAngularFactor() const;

	//c++ interface
	std::shared_ptr<btRigidBody> getBtRigidBody()
	{
		return rigidbody;
	}

	void setUserData(void*ptr);
	void* getUserData();

	void setActivationState(int state);

private:
	std::shared_ptr<btRigidBody> rigidbody;
};

#endif /* SRC_PHYSICS_BULLETWRAPPER_RIGIDBODY_H_ */
