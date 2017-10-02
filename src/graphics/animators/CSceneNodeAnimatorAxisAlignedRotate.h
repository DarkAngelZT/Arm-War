/*
 * CSceneNodeRotate.h
 *
 *  Created on: 2017年9月10日
 *      Author: neo
 */

#ifndef SRC_GRAPHICS_ANIMATORS_CSCENENODEANIMATORAXISALIGNEDROTATE_H_
#define SRC_GRAPHICS_ANIMATORS_CSCENENODEANIMATORAXISALIGNEDROTATE_H_

#include <irrlicht.h>

namespace irr
{
namespace scene
{

class CSceneNodeAnimatorAxisAlignedRotate: public ISceneNodeAnimator
{
public:
	enum AXIS_TYPE
	{
		X, Y, Z
	};
	CSceneNodeAnimatorAxisAlignedRotate(u32 cycleTimeMs, char align = 'Y',int direction=1);
	virtual ~CSceneNodeAnimatorAxisAlignedRotate();
	//! animates a scene node
	virtual void animateNode(ISceneNode* node, u32 timeMs);

	//! Writes attributes of the scene node animator.
	virtual void serializeAttributes(io::IAttributes* out,
			io::SAttributeReadWriteOptions* options = 0) const;

	//! Reads attributes of the scene node animator.
	virtual void deserializeAttributes(io::IAttributes* in,
			io::SAttributeReadWriteOptions* options = 0);

	//! Returns type of the scene node animator
	virtual ESCENE_NODE_ANIMATOR_TYPE getType() const
	{
		return ESNAT_UNKNOWN;
	}

	//! Creates a clone of this animator.
	/** Please note that you will have to drop
	 (IReferenceCounted::drop()) the returned pointer after calling
	 this. */
	virtual ISceneNodeAnimator* createClone(ISceneNode* node,
			ISceneManager* newManager = 0);

	void setCycleTime(float time_s);
	int getDirection() const;
	void setDirection(int direction);

private:
	char getAxisTypeChar(AXIS_TYPE type);
	AXIS_TYPE getAxisType(char t);
	u32 cycleTime;
	AXIS_TYPE axis;
	u32 lastUpdateTime;
	int direction;
	float lastDeltaAngle;
	ISceneNode*lastUpdatedNode;
};

} /* namespace scene */
} /* namespace irr */

#endif /* SRC_GRAPHICS_ANIMATORS_CSCENENODEANIMATORAXISALIGNEDROTATE_H_ */
