#include <irrlicht.h>
#pragma  once
#include "animators/CSceneNodeAnimatorCamera3rdPerson.h"
using namespace irr;
using namespace irr::scene;
using namespace core;
/*
 使用方法：
 1.声明对象
 2.用 attachCamera()分配一个CamaraSceneNode
 3.用setTarget()设定camera要跟随的目标
 4.调用modOrietation(水平角度,垂直角度,缩放值)或者setOrientation(水平角度,垂直角度,缩放值)来改变camera
 5.调用updatePosition()使改变生效
 6.重复4和5
 */

namespace irr
{
namespace scene
{
class I3rdPersonCamera
{
public:
	I3rdPersonCamera(ICameraSceneNode*camera);

	void setRotationSpeed(f32 ns)
	{
		m_camera_animator->setRotationSpeed(ns);
	}
	void setMaxZoom(f32 NewMaxZoom)
	{
		m_camera_animator->setMaxZoom(NewMaxZoom);
	}
	void setMaxTitl(f32 NewMaxTitl)
	{
		m_camera_animator->setMaxTilt(clamp(NewMaxTitl, 0.0f, 89.0f));
	}
	void setTarget(ISceneNode*newTarget)
	{
		m_camera_animator->setCamTarget(newTarget);
	}

	void setOffset(vector3df newOffset)
	{
		m_camera_animator->setOffset(newOffset);
	}

	f32 getCamPan() const;
	f32 getCamTilt() const;
	f32 getCamZoom() const;
	f32 getRotationSpeed() const;
	bool isEnabled() const;
	void setEnabled(bool enabled);
	f32 getZoomSpeed() const;
	void setZoomSpeed(f32 zoomSpeed);
	f32 getMaxTilt() const;
	void setMaxTilt(f32 maxTilt);
	f32 getMaxZoom() const;

	void ChangeOrientation(f32 pan, f32 titl, f32 zoom);
	void setOrientation(f32 pan, f32 titl, f32 zoom);
	const ICameraSceneNode* getCamera();
	void setCamera(const ICameraSceneNode* camera);
	CSceneNodeAnimatorCamera3rdPerson* getCameraAnimator() const;
	void setCameraAnimator(
			const CSceneNodeAnimatorCamera3rdPerson* cameraAnimator);

	void setReceiveInput(bool receive);

protected:
	ICameraSceneNode* m_camera;
	CSceneNodeAnimatorCamera3rdPerson* m_camera_animator;
};
}
}
