/*
 * RigidBody.cpp
 *
 *  Created on: 2017年5月2日
 *      Author: neo
 */

#include "RigidBody.h"

RigidBody::RigidBody(std::shared_ptr<btRigidBody> body) :
		m_internalIndex(-1)
{
	// TODO 自动生成的构造函数存根
	rigidbody = body;
}

RigidBody::~RigidBody()
{
	// TODO 自动生成的析构函数存根
	if (m_internalIndex > 0)
		NeoPhysics::getInstance()->RemoveRigidBody(m_internalIndex);
}

void RigidBody::applyGravity()
{
	rigidbody->applyGravity();
}

void RigidBody::setGravity(irr::core::vector3df& acceleration)
{
	rigidbody->setGravity(NeoPhysics::irrToBulletVector(acceleration));
}

irr::core::vector3df RigidBody::getGravity() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getGravity()));
}

void RigidBody::setDamping(float lin_damping, float ang_damping)
{
	rigidbody->setDamping(lin_damping, ang_damping);
}

float RigidBody::getLinearDamping() const
{
	return rigidbody->getLinearDamping();
}

float RigidBody::getAngularDamping() const
{
	return rigidbody->getAngularDamping();
}

float RigidBody::getLinearSleepingThreshold() const
{
	return rigidbody->getLinearSleepingThreshold();
}

float RigidBody::getAngularSleepingThreshold() const
{
	return rigidbody->getAngularSleepingThreshold();
}

void RigidBody::applyDamping(float timeStep)
{
	rigidbody->applyDamping(timeStep);
}

void RigidBody::setMassProps(float mass, irr::core::vector3df& inertia)
{
	rigidbody->setMassProps(mass, NeoPhysics::irrToBulletVector(inertia));
}

const irr::core::vector3df RigidBody::getLinearFactor() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getLinearFactor()));
}

void RigidBody::setLinearFactor(irr::core::vector3df& linearFactor)
{
	rigidbody->setLinearFactor(NeoPhysics::irrToBulletVector(linearFactor));
}

float RigidBody::getInvMass() const
{
	return rigidbody->getInvMass();
}

void RigidBody::integrateVelocities(float step)
{
	rigidbody->integrateVelocities(step);
}

void RigidBody::setCenterOfMassTransform(irr::core::matrix4& xform)
{
	btTransform trans;
	NeoPhysics::IrrlichtMatrixTobtTransform(xform, trans);
	rigidbody->setCenterOfMassTransform(trans);
}

void RigidBody::applyCentralForce(irr::core::vector3df& force)
{
	rigidbody->applyCentralForce(NeoPhysics::irrToBulletVector(force));
}

const irr::core::vector3df RigidBody::getTotalForce() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getTotalForce()));
}

const irr::core::vector3df RigidBody::getTotalTorque() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getTotalTorque()));
}

const irr::core::vector3df RigidBody::getInvInertiaDiagLocal() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getInvInertiaDiagLocal()));
}

void RigidBody::setInvInertiaDiagLocal(irr::core::vector3df& diagInvInertia)
{
	rigidbody->setInvInertiaDiagLocal(
			NeoPhysics::irrToBulletVector(diagInvInertia));
}

void RigidBody::setSleepingThresholds(float linear, float angular)
{
	rigidbody->setSleepingThresholds(linear, angular);
}

void RigidBody::applyTorque(irr::core::vector3df& torque)
{
	rigidbody->applyTorque(NeoPhysics::irrToBulletVector(torque));
}

void RigidBody::applyForce(irr::core::vector3df& force,
		irr::core::vector3df& rel_pos)
{
	rigidbody->applyForce(NeoPhysics::irrToBulletVector(force),
			NeoPhysics::irrToBulletVector(rel_pos));
}

void RigidBody::applyCentralImpulse(irr::core::vector3df& impulse)
{
	rigidbody->applyCentralImpulse(NeoPhysics::irrToBulletVector(impulse));
}

void RigidBody::applyTorqueImpulse(irr::core::vector3df& torque)
{
	rigidbody->applyTorqueImpulse(NeoPhysics::irrToBulletVector(torque));
}

void RigidBody::applyImpulse(irr::core::vector3df& impulse,
		irr::core::vector3df& rel_pos)
{
	rigidbody->applyImpulse(NeoPhysics::irrToBulletVector(impulse),
			NeoPhysics::irrToBulletVector(rel_pos));
}

void RigidBody::clearForces()
{
	rigidbody->clearForces();
}

void RigidBody::updateInertiaTensor()
{
	rigidbody->updateInertiaTensor();
}

const irr::core::vector3df RigidBody::getCenterOfMassPosition() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getCenterOfMassPosition()));
}

irr::core::quaternion RigidBody::getOrientation() const
{
	return NeoPhysics::bulletToIrrQuaternion(rigidbody->getOrientation());
}

irr::core::matrix4 RigidBody::getCenterOfMassTransform() const
{
	matrix4 mat;
	NeoPhysics::btTransformToIrrlichtMatrix(
			rigidbody->getCenterOfMassTransform(), mat);
	return mat;
}

irr::core::vector3df RigidBody::getLinearVelocity() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getLinearVelocity()));
}

irr::core::vector3df RigidBody::getAngularVelocity() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getAngularVelocity()));
}

void RigidBody::setLinearVelocity(irr::core::vector3df& lin_vel)
{
	rigidbody->setLinearVelocity(NeoPhysics::irrToBulletVector(lin_vel));
}

void RigidBody::setAngularVelocity(irr::core::vector3df& ang_vel)
{
	rigidbody->setAngularVelocity(NeoPhysics::irrToBulletVector(ang_vel));
}

irr::core::vector3df RigidBody::getVelocityInLocalPoint(
		irr::core::vector3df& rel_pos) const
{
	return NeoPhysics::bulletToIrrVector(
			rigidbody->getVelocityInLocalPoint(
					NeoPhysics::irrToBulletVector(rel_pos)));
}

void RigidBody::translate(irr::core::vector3df& v)
{
	rigidbody->translate(NeoPhysics::irrToBulletVector(v));
}

void RigidBody::getAabb(irr::core::vector3df& aabbMin,
		irr::core::vector3df& aabbMax) const
{
	btVector3 btaabbmin;
	btVector3 btaabbMax;
	rigidbody->getAabb(btaabbmin, btaabbMax);
	aabbMin = NeoPhysics::bulletToIrrVector(btaabbmin);
	aabbMax = NeoPhysics::bulletToIrrVector(btaabbMax);
}

float RigidBody::computeImpulseDenominator(irr::core::vector3df& pos,
		irr::core::vector3df& normal) const
{
	return rigidbody->computeImpulseDenominator(
			NeoPhysics::irrToBulletVector(pos),
			NeoPhysics::irrToBulletVector(normal));
}

float RigidBody::computeAngularImpulseDenominator(
		irr::core::vector3df& axis) const
{
	return rigidbody->computeAngularImpulseDenominator(
			NeoPhysics::irrToBulletVector(axis));
}

void RigidBody::updateDeactivation(float timeStep)
{
	rigidbody->updateDeactivation(timeStep);
}

void RigidBody::setAngularFactor(irr::core::vector3df& angFac)
{
	rigidbody->setAngularFactor(NeoPhysics::irrToBulletVector(angFac));
}

void RigidBody::setAngularFactor(float angFac)
{
	rigidbody->setAngularFactor(angFac);
}

irr::core::vector3df RigidBody::getAngularFactor() const
{
	return NeoPhysics::bulletToIrrVector(
			const_cast<btVector3&>(rigidbody->getAngularFactor()));
}

void RigidBody::setPosition(irr::core::vector3df position)
{
	btVector3 pos = NeoPhysics::irrToBulletVector(position);
	rigidbody->getWorldTransform().setOrigin(pos);
}

void RigidBody::setRotation(irr::core::vector3df rotation)
{
	quaternion rot(DEGTORAD*rotation);
	btQuaternion r = NeoPhysics::irrToBulletQuaternion(rot);
	rigidbody->getWorldTransform().setRotation(r);
}

void RigidBody::setUserData(void* ptr)
{
	rigidbody->setUserPointer(ptr);
}

void* RigidBody::getUserData()
{
	return rigidbody->getUserPointer();
}

void RigidBody::setActivationState(int state)
{
	rigidbody->setActivationState(state);
}
