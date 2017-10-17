/*
 * CSceneNodeAnimatorCamera3rdPerson.h
 *
 *  Created on: 2017年9月24日
 *      Author: neo
 */

#ifndef SRC_GRAPHICS_CSCENENODEANIMATORCAMERA3RDPERSON_H_
#define SRC_GRAPHICS_CSCENENODEANIMATORCAMERA3RDPERSON_H_

#include <irrlicht.h>

namespace irr
{
namespace scene
{

class CSceneNodeAnimatorCamera3rdPerson: public ISceneNodeAnimator
{
public:
	CSceneNodeAnimatorCamera3rdPerson(ISceneNode*targetNode,
			gui::ICursorControl* cursorControl, f32 rotaionSpeed = 100,
			f32 zoomSpeed = 1, f32 maxTilt = 20, f32 maxZoom = 20);
	~CSceneNodeAnimatorCamera3rdPerson();

	virtual void animateNode(ISceneNode* node, u32 timeMs);
	//! Event receiver
	virtual bool OnEvent(const SEvent& event);
	//! This animator will receive events when attached to the active camera
	virtual bool isEventReceiverEnabled() const
	{
		return true;
	}

	//! Returns the type of this animator
	virtual ESCENE_NODE_ANIMATOR_TYPE getType() const
	{
		return ESNAT_CAMERA_FPS;
	}
	virtual ISceneNodeAnimator* createClone(ISceneNode* node,
			ISceneManager* newManager = 0);
	f32 getCamPan() const;
	void setCamPan(f32 camPan);
	const ISceneNode* getCamTarget() const;
	void setCamTarget(const ISceneNode* camTarget);
	f32 getCamTilt() const;
	void setCamTilt(f32 camTilt);
	f32 getCamZoom() const;
	void setCamZoom(f32 camZoom);
	f32 getMaxTilt() const;
	void setMaxTilt(f32 maxTilt);
	f32 getMaxZoom() const;
	void setMaxZoom(f32 maxZoom);
	const core::vector3df& getOffset() const;
	void setOffset(const core::vector3df& offset);
	f32 getRotationSpeed() const;
	void setRotationSpeed(f32 rotationSpeed);
	bool isEnabled() const;
	void setEnabled(bool enabled);
	f32 getZoomSpeed() const;
	void setZoomSpeed(f32 zoomSpeed);

	void setOrientation(f32 pan, f32 titl, f32 zoom);
	void ChangeOrientation(float pan,float tilt,float zoom);
	bool isReceiveInput() const;
	void setReceiveInput(bool receiveInput);

protected:
	void UpdatePosition(ICameraSceneNode*cam);
	f32 m_zoomSpeed; //鼠标滚轮卷动速度
	f32 camPan;
	f32 camTilt;
	f32 camZoom;
	f32 m_maxZoom;
	f32 m_maxTilt;
	ISceneNode* camTarget;
	core::vector3df offset;
	f32 m_rotationSpeed;
	bool m_enabled;
	bool m_receiveInput;
	gui::ICursorControl * m_cursorControl;
	core::position2d<f32> m_centerCursor, m_cursorPos;
	bool m_firstUpdate;
	s32 LastAnimationTime;
};

} /* namespace scene */
} /* namespace irr */

#endif /* SRC_GRAPHICS_CSCENENODEANIMATORCAMERA3RDPERSON_H_ */
