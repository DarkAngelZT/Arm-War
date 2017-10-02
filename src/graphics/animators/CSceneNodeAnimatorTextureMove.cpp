/*
 * CSceneNodeAnimatorTextureMove.cpp
 *
 *  Created on: 2017年9月12日
 *      Author: neo
 */

#include "CSceneNodeAnimatorTextureMove.h"

namespace irr
{
namespace scene
{

CSceneNodeAnimatorTextureMove::CSceneNodeAnimatorTextureMove(float speed,
		core::vector2df direction) :
		m_speed(speed), m_direction(direction), lastUpdateTime(0)
{
}

CSceneNodeAnimatorTextureMove::~CSceneNodeAnimatorTextureMove()
{
}

void CSceneNodeAnimatorTextureMove::animateNode(ISceneNode* node, u32 timeMs)
{
	if (lastUpdateTime == 0)
	{
		lastUpdateTime = timeMs;
		return;
	}
	if (m_speed != 0)
	{
		float delta = static_cast<float>((timeMs - lastUpdateTime) % 1000);
		delta /= 1000.0f;
		core::matrix4 mat;
		//10 为1秒一圈的速度
		//speed 为米/秒
		float texture_movement = m_speed / 8.0f * delta;
		translation += texture_movement * m_direction;
		if (translation.getLengthSQ() > 1)
		{
			translation -= m_direction;
		}
		node->getMaterial(0).getTextureMatrix(0).setTextureTranslate(
				translation.X, translation.Y);
	}
	lastUpdateTime = timeMs;
}

void CSceneNodeAnimatorTextureMove::serializeAttributes(io::IAttributes* out,
		io::SAttributeReadWriteOptions* options) const
{
	out->addFloat("Speed", m_speed);
	out->addVector2d("Direction", m_direction);
}

void CSceneNodeAnimatorTextureMove::deserializeAttributes(io::IAttributes* in,
		io::SAttributeReadWriteOptions* options)
{
	m_speed = in->getAttributeAsFloat("Speed");
	m_direction = in->getAttributeAsVector2d("Direction");
}

ISceneNodeAnimator* CSceneNodeAnimatorTextureMove::createClone(ISceneNode* node,
		ISceneManager* newManager)
{
	return new CSceneNodeAnimatorTextureMove(m_speed, m_direction);
}

void CSceneNodeAnimatorTextureMove::setSpeed(float speed)
{
	this->m_speed = speed;
}

void CSceneNodeAnimatorTextureMove::setDirection(core::vector2df d)
{
	m_direction = d;
}

} /* namespace scene */
} /* namespace irr */
