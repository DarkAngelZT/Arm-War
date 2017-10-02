#include "I3rdPersonCamera.h"
namespace irr
{
namespace scene
{
void I3rdPersonCamera::ChangeOrientation(irr::f32 pan, irr::f32 titl,
		irr::f32 zoom)
{
	m_camera_animator->ChangeOrientation(pan, titl, zoom);
}

I3rdPersonCamera::I3rdPersonCamera(ICameraSceneNode*camera) :
		m_camera(camera), m_camera_animator(0)
{
}

f32 I3rdPersonCamera::getCamPan() const
{
	if (m_camera_animator)
	{
		return m_camera_animator->getCamPan();
	}
	return 0;
}

f32 I3rdPersonCamera::getCamTilt() const
{
	if (m_camera_animator)
	{
		return m_camera_animator->getCamTilt();
	}
	return 0;
}

f32 I3rdPersonCamera::getCamZoom() const
{
	if (m_camera_animator)
	{
		return m_camera_animator->getCamZoom();
	}
	return 0;
}

f32 I3rdPersonCamera::getRotationSpeed() const
{
	if (m_camera_animator)
	{
		return m_camera_animator->getRotationSpeed();
	}
	return 0;
}

bool I3rdPersonCamera::isEnabled() const
{
	if (m_camera_animator)
	{
		return m_camera_animator->isEnabled();
	}
	return false;
}

void I3rdPersonCamera::setEnabled(bool enabled)
{
	if (m_camera_animator)
	{
		m_camera_animator->setEnabled(enabled);
	}
}

f32 I3rdPersonCamera::getZoomSpeed() const
{
	if (m_camera_animator)
	{
		return m_camera_animator->getZoomSpeed();
	}
	return 0;
}

void I3rdPersonCamera::setZoomSpeed(f32 zoomSpeed)
{
	if (m_camera_animator)
	{
		m_camera_animator->setZoomSpeed(zoomSpeed);
	}
}

f32 I3rdPersonCamera::getMaxTilt() const
{
	if (m_camera_animator)
	{
		return m_camera_animator->getMaxTilt();
	}
	return 0;
}

void I3rdPersonCamera::setMaxTilt(f32 maxTilt)
{
	if (m_camera_animator)
	{
		m_camera_animator->setMaxTilt(maxTilt);
	}
}

f32 I3rdPersonCamera::getMaxZoom() const
{
	if (m_camera_animator)
	{
		return m_camera_animator->getMaxZoom();
	}
	return 0;
}

void I3rdPersonCamera::setOrientation(f32 pan, f32 titl, f32 zoom)
{
	m_camera_animator->setOrientation(pan, titl, zoom);
}

const ICameraSceneNode* irr::scene::I3rdPersonCamera::getCamera()
{
	return m_camera;
}

void irr::scene::I3rdPersonCamera::setCamera(const ICameraSceneNode* camera)
{
	m_camera = camera;
}

CSceneNodeAnimatorCamera3rdPerson* irr::scene::I3rdPersonCamera::getCameraAnimator() const
{
	return m_camera_animator;
}

void irr::scene::I3rdPersonCamera::setCameraAnimator(
		const CSceneNodeAnimatorCamera3rdPerson* cameraAnimator)
{
	m_camera_animator = cameraAnimator;
}
} /* namespace scene */
} /* namespace irr */
