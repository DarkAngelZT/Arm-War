/*
 * CSceneNodeAnimatorCamera3rdPerson.cpp
 *
 *  Created on: 2017年9月24日
 *      Author: neo
 */

#include "CSceneNodeAnimatorCamera3rdPerson.h"
#include <math.h>
#include<iostream>
namespace irr
{
namespace scene
{

CSceneNodeAnimatorCamera3rdPerson::CSceneNodeAnimatorCamera3rdPerson(
		ISceneNode*targetNode, gui::ICursorControl* cursorControl,
		f32 rotaionSpeed, f32 zoomSpeed, f32 maxTilt/* = 89*/,
		f32 maxZoom/* = 20*/) :
		camTarget(targetNode), m_cursorControl(cursorControl), m_enabled(true), m_receiveInput(
				true), m_rotationSpeed(rotaionSpeed), m_zoomSpeed(zoomSpeed), m_maxTilt(
				maxTilt), m_maxZoom(maxZoom), m_firstUpdate(true), LastAnimationTime(
				0)
{
	camPan = 90;
	camTilt = -30;
	camZoom = 10;
	offset = core::vector3df(0, 3.0f, 0);
	if (m_cursorControl)
		m_cursorControl->grab();
}

f32 CSceneNodeAnimatorCamera3rdPerson::getCamPan() const
{
	return camPan;
}

void CSceneNodeAnimatorCamera3rdPerson::setCamPan(f32 camPan)
{
	this->camPan = camPan;
}

const ISceneNode* CSceneNodeAnimatorCamera3rdPerson::getCamTarget() const
{
	return camTarget;
}

void CSceneNodeAnimatorCamera3rdPerson::setCamTarget(
		const ISceneNode* camTarget)
{
	this->camTarget = camTarget;
}

f32 CSceneNodeAnimatorCamera3rdPerson::getCamTilt() const
{
	return camTilt;
}

void CSceneNodeAnimatorCamera3rdPerson::setCamTilt(f32 camTilt)
{
	this->camTilt = camTilt;
}

f32 CSceneNodeAnimatorCamera3rdPerson::getCamZoom() const
{
	return camZoom;
}

void CSceneNodeAnimatorCamera3rdPerson::setCamZoom(f32 camZoom)
{
	this->camZoom = camZoom;
}

f32 CSceneNodeAnimatorCamera3rdPerson::getMaxTilt() const
{
	return m_maxTilt;
}

void CSceneNodeAnimatorCamera3rdPerson::setMaxTilt(f32 maxTilt)
{
	this->m_maxTilt = maxTilt;
}

f32 CSceneNodeAnimatorCamera3rdPerson::getMaxZoom() const
{
	return m_maxZoom;
}

void CSceneNodeAnimatorCamera3rdPerson::setMaxZoom(f32 maxZoom)
{
	this->m_maxZoom = maxZoom;
}

const core::vector3df& CSceneNodeAnimatorCamera3rdPerson::getOffset() const
{
	return offset;
}

void CSceneNodeAnimatorCamera3rdPerson::setOffset(const core::vector3df& offset)
{
	this->offset = offset;
}

f32 CSceneNodeAnimatorCamera3rdPerson::getRotationSpeed() const
{
	return m_rotationSpeed;
}

void CSceneNodeAnimatorCamera3rdPerson::animateNode(ISceneNode* node,
		u32 timeMs)
{
	if (!m_enabled || !camTarget || !node || node->getType() != ESNT_CAMERA)
		return;

	ICameraSceneNode* camera = static_cast<ICameraSceneNode*>(node);

	if (m_firstUpdate)
	{
		camera->updateAbsolutePosition();
		if (m_cursorControl)
		{
			m_cursorControl->setPosition(0.5f, 0.5f);
			m_cursorPos = m_centerCursor =
					m_cursorControl->getRelativePosition();
		}

		LastAnimationTime = timeMs;

		m_firstUpdate = false;
	}
	scene::ISceneManager * smgr = camera->getSceneManager();
	if (smgr && smgr->getActiveCamera() != camera)
		return;
	LastAnimationTime = timeMs;
	core::vector3df relativeRotation;
	if (m_cursorControl && m_receiveInput)
	{
		if (m_cursorPos != m_centerCursor)
		{
			//鼠标获取偏移量
			relativeRotation.X = (.5f - m_cursorPos.X) * (m_rotationSpeed);
			relativeRotation.Y = (.5f - m_cursorPos.Y) * (m_rotationSpeed); //*mouseYDirection/10;

			//Y<最大垂直角，或者 X>360-最大垂直角
			if (relativeRotation.Y > 89.0f * 2.0f
					&& relativeRotation.Y < 360.0f - 89.0f)
				relativeRotation.Y = 360.0f - 89.0f;
			else if (relativeRotation.Y > 89.0f
					&& relativeRotation.Y < 360.0f - 89.0f)
				relativeRotation.Y = 89.0f;

			//重置鼠标
			m_cursorControl->setPosition(.5f, .5f);
			m_centerCursor = m_cursorControl->getRelativePosition();

			m_cursorPos = m_centerCursor;
		}
		//特殊情况：鼠标飞到窗口外去了
		video::IVideoDriver *driver = smgr->getVideoDriver();
		core::vector2d<u32> mousePos(u32(m_cursorControl->getPosition().X),
				u32(m_cursorControl->getPosition().Y));
		core::rect<u32> screenRect(0, 0, driver->getScreenSize().Width,
				driver->getScreenSize().Height);
		//如果鼠标在窗口外
		bool reset = !screenRect.isPointInside(mousePos) && m_receiveInput;

		if (reset)
		{
			//则重置鼠标
			m_cursorControl->setPosition(.5f, .5f);
			m_centerCursor = m_cursorControl->getRelativePosition();
			m_cursorPos = m_centerCursor;
		}

		ChangeOrientation(relativeRotation.X, relativeRotation.Y, 0);
	}
	UpdatePosition(camera);
}

bool CSceneNodeAnimatorCamera3rdPerson::OnEvent(const SEvent& event)
{
	if (!m_receiveInput)
		return false;
	switch (event.EventType)
	{
	case EET_MOUSE_INPUT_EVENT:
		switch (event.MouseInput.Event)
		{
		case EMIE_MOUSE_MOVED:
		{
			m_cursorPos = m_cursorControl->getRelativePosition();
			return true;
		}
		case EMIE_MOUSE_WHEEL:
		{
			f32 zoomtmp = camZoom + event.MouseInput.Wheel * m_zoomSpeed;
			camZoom = core::clamp(zoomtmp, 5.0f, m_maxZoom);
		}
		}
		break;

	default:
		break;
	}

	return false;
}

ISceneNodeAnimator* CSceneNodeAnimatorCamera3rdPerson::createClone(
		ISceneNode* node, ISceneManager* newManager)
{
	CSceneNodeAnimatorCamera3rdPerson * newAnimator =
			new CSceneNodeAnimatorCamera3rdPerson(camTarget, m_cursorControl,
					m_rotationSpeed, m_zoomSpeed, m_maxTilt, m_maxZoom);
	return newAnimator;
}

void CSceneNodeAnimatorCamera3rdPerson::setRotationSpeed(f32 rotationSpeed)
{
	this->m_rotationSpeed = rotationSpeed;
}

bool CSceneNodeAnimatorCamera3rdPerson::isEnabled() const
{
	return m_enabled;
}

void CSceneNodeAnimatorCamera3rdPerson::setEnabled(bool enabled)
{
	m_enabled = enabled;
}

f32 CSceneNodeAnimatorCamera3rdPerson::getZoomSpeed() const
{
	return m_zoomSpeed;
}

CSceneNodeAnimatorCamera3rdPerson::~CSceneNodeAnimatorCamera3rdPerson()
{
	if (m_cursorControl)
		m_cursorControl->drop();
}

void CSceneNodeAnimatorCamera3rdPerson::setZoomSpeed(f32 zoomSpeed)
{
	m_zoomSpeed = zoomSpeed;
}

void CSceneNodeAnimatorCamera3rdPerson::setOrientation(f32 pan, f32 titl,
		f32 zoom)
{
	camPan = fmod(pan, 360.0f);
	camTilt = core::clamp(titl, -89.0f, m_maxTilt);
	camZoom = core::clamp(zoom, 0.1f, m_maxZoom);
}

void CSceneNodeAnimatorCamera3rdPerson::ChangeOrientation(float pan, float tilt,
		float zoom)
{
	setOrientation(camPan + pan, camTilt + tilt, camZoom + zoom);
}

void CSceneNodeAnimatorCamera3rdPerson::UpdatePosition(ICameraSceneNode*cam)
{
	if (!cam)
	{
		return;
	}
	core::vector3df CamPosVector;
	core::vector3df NewCamLocation;
	core::vector3df Target;
	//camtilt一般限制在-89到89之间,-89：由上方射向地面
	//可通过maxtilt来改变camtilt的上限
	CamPosVector.X = cos(core::degToRad(camPan + 180))
			* sin(core::degToRad(camTilt + 90));
	CamPosVector.Y = cos(core::degToRad(camTilt + 90));
	CamPosVector.Z = sin(core::degToRad(camPan + 180))
			* sin(core::degToRad(camTilt + 90));

	core::matrix4 tmatrix;
	tmatrix.setRotationDegrees(
			camTarget->getAbsoluteTransformation().getRotationDegrees());
	//把euler角转换成球面坐标，再取水平旋转角
	core::vector3df unitVector(1, 0, 0);
	tmatrix.rotateVect(unitVector);
	core::vector3df rot = unitVector.getSphericalCoordinateAngles();
	float angle_y = rot.Y * -1 + 90;
	if (angle_y < 0)
	{
		angle_y += 360;
	}
	tmatrix.setRotationDegrees(core::vector3df(0, angle_y, 0));
	tmatrix.transformVect(CamPosVector);

	//把摄像机抬高一点，这样平视的时候就不会被挡住视线了
	Target = camTarget->getAbsolutePosition() + offset;
	NewCamLocation.X = Target.X + CamPosVector.X * camZoom;
	NewCamLocation.Y = Target.Y + CamPosVector.Y * camZoom;
	NewCamLocation.Z = Target.Z + CamPosVector.Z * camZoom;
	cam->setPosition(NewCamLocation);
	cam->setUpVector(core::vector3df(0, 1.f, 0));
	cam->setTarget(core::vector3df(Target));
	cam->updateAbsolutePosition();
}

bool CSceneNodeAnimatorCamera3rdPerson::isReceiveInput() const
{
	return m_receiveInput;
}

void CSceneNodeAnimatorCamera3rdPerson::setReceiveInput(bool receiveInput)
{
	m_receiveInput = receiveInput;
}

} /* namespace scene */
} /* namespace irr */
