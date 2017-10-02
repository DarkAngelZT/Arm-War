/*
 * BasicTankObject.cpp
 *
 *  Created on: 2017年9月11日
 *      Author: neo
 */

#include "StandardTankBodyObject.h"

StandardTankBodyObject::StandardTankBodyObject() :
		m_body(NULL), m_left_track(NULL), m_right_track(NULL), m_left_track_animator(
		NULL), m_right_track_animator(NULL), m_left_wheel_animator(0), m_right_wheel_animator(
				0)
{
	m_sceneNode = NeoGraphics::getInstance()->AddEmptySceneNode();
}

StandardTankBodyObject::~StandardTankBodyObject()
{
	m_sceneNode->remove();
	m_left_wheels.clear();
	m_right_wheels.clear();
	m_right_wheel_animator->drop();
	m_right_wheel_animator->drop();
}

void StandardTankBodyObject::setBodyNode(irr::scene::IAnimatedMeshSceneNode*node,
		const irr::core::vector3df& position/* = irr::core::vector3df(0, 0,
		 0)*/)
{
	m_body = node;
	m_body->setPosition(position);
	node->setUserData(this);
	m_body->setParent(m_sceneNode);
}

void StandardTankBodyObject::OnCollisionEnter(GameObject* another)
{
}

void StandardTankBodyObject::OnCollision(GameObject* another)
{
}

void StandardTankBodyObject::OnCollisionExit(GameObject* another)
{
}

bool StandardTankBodyObject::isActive() const
{
	return GameObject::isActive();
}

void StandardTankBodyObject::setActive(bool active)
{
	GameObject::setActive(active);
}

bool StandardTankBodyObject::isVisible() const
{
	return GameObject::isVisible();
}

void StandardTankBodyObject::addWheelNode(irr::scene::IAnimatedMeshSceneNode* node,
		std::string side)
{
	if (NULL != m_body)
	{
		if (side == "left")
		{
			m_left_wheels.push_back(node);
			if (!m_left_wheel_animator)
			{
				m_left_wheel_animator =
						NeoGraphics::getInstance()->createAxisAlignedRotateAnimator(
								0.0f, 'Z', -1);
			}
			node->addAnimator(m_left_wheel_animator);
		}
		else
		{
			m_right_wheels.push_back(node);
			if (!m_right_wheel_animator)
			{
				m_right_wheel_animator =
						NeoGraphics::getInstance()->createAxisAlignedRotateAnimator(
								0.0f, 'Z', -1);
			}
			node->addAnimator(m_right_wheel_animator);
		}
		ConvertCoordinate(node, m_body);
		node->setParent(m_body);
		node->setUserData(this);
	}
}

void StandardTankBodyObject::addTrackNode(irr::scene::IAnimatedMeshSceneNode* node,
		std::string side)
{
	if (NULL != m_body)
	{
		if (side == "left")
		{
			m_left_track = node;
			if (!m_left_track_animator)
			{
				m_left_track_animator =
						NeoGraphics::getInstance()->createTextureMoveAnimator(
								0, vector2df(-1, 0));
			}
			node->addAnimator(m_left_track_animator);
		}
		else
		{
			m_right_track = node;
			if (!m_right_track_animator)
			{
				m_right_track_animator =
						NeoGraphics::getInstance()->createTextureMoveAnimator(
								0, vector2df(-1, 0));
			}
			node->addAnimator(m_right_track_animator);
		}
		ConvertCoordinate(node, m_body);
		node->setParent(m_body);
		node->setUserData(this);
	}
}

void StandardTankBodyObject::setWheelAnimationSpeed(float cycleTime_s,
		std::string side, int dir)
{
	if (side == "left")
	{
		m_left_wheel_animator->setCycleTime(cycleTime_s);
		m_left_wheel_animator->setDirection(dir);
	}
	else
	{
		m_right_wheel_animator->setCycleTime(cycleTime_s);
		m_right_wheel_animator->setDirection(dir);
	}
}

void StandardTankBodyObject::setTrackAnimationSpeed(float speed, std::string side =
		"left", const vector2df& dir)
{
	if (side == "left")
	{
		if (m_left_track_animator)
		{
			m_left_track_animator->setSpeed(speed);
			m_left_track_animator->setDirection(dir);
		}
	}
	else
	{
		if (m_right_track_animator)
		{
			m_right_track_animator->setSpeed(speed);
			m_right_track_animator->setDirection(dir);
		}
	}
}

void StandardTankBodyObject::setVisible(bool visible)
{
	GameObject::setVisible(visible);
	if (m_sceneNode)
	{
		m_sceneNode->setVisible(visible);
	}
}

RigidBody* StandardTankBodyObject::AddRigidBody(int collisionShape, float mass)
{
	if (collisionShape == -1 || !m_body)
		return NULL;
	matrix4 mat = m_body->getAbsoluteTransformation();
	vector3df pos = mat.getTranslation();
	vector3df rot = mat.getRotationDegrees();
	return AddRigidBody(collisionShape, mass, pos, rot);
}

RigidBody* StandardTankBodyObject::AddRigidBody(int collisionShape, float mass,
		const vector3df& position, const vector3df& rotation)
{
	collisionShapeIndex = collisionShape;
	m_rigidBody = NeoPhysics::getInstance()->CreateRigidBody(
			collisionShapeIndex, m_body, mass, position, rotation);
	m_rigidBody->setUserData(this);
	NeoPhysics::getInstance()->AddRigidiBodyToWorld(m_rigidBody);
	return m_rigidBody;
}

irr::scene::IAnimatedMeshSceneNode* StandardTankBodyObject::getTankBodyNode()
{
	return m_body;
}

void StandardTankBodyObject::ConvertCoordinate(scene::ISceneNode* node,
		scene::ISceneNode* parent)
{
	if (parent && node->getParent() != parent)
	{
		irr::core::matrix4 mat = node->getAbsoluteTransformation();
		matrix4 transform = parent->getAbsoluteTransformation();
		transform.makeInverse();
		mat = transform * mat;

		node->setPosition(mat.getTranslation());
		node->setRotation(mat.getRotationDegrees());
		node->setScale(mat.getScale());
	}
}
