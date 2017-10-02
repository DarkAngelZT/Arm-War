/*
 * CSceneNodeRotate.cpp
 *
 *  Created on: 2017年9月10日
 *      Author: neo
 */

#include "CSceneNodeAnimatorAxisAlignedRotate.h"

namespace irr
{
namespace scene
{

CSceneNodeAnimatorAxisAlignedRotate::CSceneNodeAnimatorAxisAlignedRotate(
		u32 cycleTimeMs, char align/*='Y'*/, int direction/*=1*/) :
		cycleTime(cycleTimeMs), direction(direction)
{
	axis = getAxisType(align);
	lastUpdateTime = 0;
	lastUpdatedNode = NULL;
	lastDeltaAngle = 0;
}

CSceneNodeAnimatorAxisAlignedRotate::~CSceneNodeAnimatorAxisAlignedRotate()
{
}

void CSceneNodeAnimatorAxisAlignedRotate::animateNode(ISceneNode* node,
		u32 timeMs)
{
	if (cycleTime == 0)
	{
		return;
	}
	if (lastUpdateTime == 0)
	{
		lastUpdateTime = timeMs;
		return;
	}
	u32 delta = (timeMs - lastUpdateTime) % cycleTime;
	core::vector3df rotation(node->getRotation());
	if (delta > cycleTime)
	{
		delta %= cycleTime;
	}
	float deltaAngle;
	if (delta == 0 && node != lastUpdatedNode)
	{
		deltaAngle = lastDeltaAngle;
	}
	else
	{
		deltaAngle = (float) delta / (float) cycleTime * 360 * direction;
		lastDeltaAngle = deltaAngle;
	}
	switch (axis)
	{
	case X:
		rotation.X = rotation.X + deltaAngle;
		if (core::abs_(rotation.X) > 360)
		{
			rotation.X -= 360 * direction;
		}
		break;
	case Y:
		rotation.Y = rotation.Y + deltaAngle;
		if (core::abs_(rotation.Y) > 360)
		{
			rotation.Y -= 360 * direction;
		}
		break;
	case Z:
		rotation.Z = rotation.Z + deltaAngle;
		if (core::abs_(rotation.Z) > 360)
		{
			rotation.Z -= 360 * direction;
		}
		break;
	}
	node->setRotation(rotation);
	lastUpdatedNode = node;
	lastUpdateTime = timeMs;
}

void CSceneNodeAnimatorAxisAlignedRotate::serializeAttributes(
		io::IAttributes* out, io::SAttributeReadWriteOptions* options) const
{
	out->addFloat("CycleTime", cycleTime);
	out->addString("Align", core::stringc(getAxisTypeChar(axis)).c_str());
}

void CSceneNodeAnimatorAxisAlignedRotate::deserializeAttributes(
		io::IAttributes* in, io::SAttributeReadWriteOptions* options)
{
	cycleTime = in->getAttributeAsFloat("CycleTime");
	axis = getAxisType(in->getAttributeAsString("Align")[0]);
}

ISceneNodeAnimator* CSceneNodeAnimatorAxisAlignedRotate::createClone(
		ISceneNode* node, ISceneManager* newManager)
{
	return new CSceneNodeAnimatorAxisAlignedRotate(cycleTime,
			getAxisTypeChar(axis));
}

void CSceneNodeAnimatorAxisAlignedRotate::setCycleTime(float time_s)
{
	cycleTime = time_s * 1000;
}

char CSceneNodeAnimatorAxisAlignedRotate::getAxisTypeChar(AXIS_TYPE type)
{
	char result;
	switch (type)
	{
	case X:
	{
		result = 'x';
		break;
	}
	case Y:
	{
		result = 'y';
		break;
	}
	case Z:
	{
		result = 'z';
		break;
	}
	default:
	{
		result = X;
		break;
	}
	}
	return result;
}

CSceneNodeAnimatorAxisAlignedRotate::AXIS_TYPE CSceneNodeAnimatorAxisAlignedRotate::getAxisType(
		char t)
{
	AXIS_TYPE result;
	switch (t)
	{
	case 'x':
	case 'X':
	{
		result = X;
		break;
	}
	case 'y':
	case 'Y':
	{
		result = Y;
		break;
	}
	case 'z':
	case 'Z':
	{
		result = Z;
		break;
	}
	default:
	{
		result = X;
		break;
	}
	}
	return result;
}

int CSceneNodeAnimatorAxisAlignedRotate::getDirection() const
{
	return direction;
}

void CSceneNodeAnimatorAxisAlignedRotate::setDirection(int direction)
{
	this->direction = direction;
}

} /* namespace scene */
} /* namespace irr */
