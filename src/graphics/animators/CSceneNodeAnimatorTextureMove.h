/*
 * CSceneNodeAnimatorTextureMove.h
 *
 *  Created on: 2017年9月12日
 *      Author: neo
 */

#ifndef SRC_GRAPHICS_ANIMATORS_CSCENENODEANIMATORTEXTUREMOVE_H_
#define SRC_GRAPHICS_ANIMATORS_CSCENENODEANIMATORTEXTUREMOVE_H_

#include <irrlicht.h>

namespace irr
{
namespace scene
{

class CSceneNodeAnimatorTextureMove: public ISceneNodeAnimator
{
public:
	CSceneNodeAnimatorTextureMove(float speed, core::vector2df direction);
	virtual ~CSceneNodeAnimatorTextureMove();
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

	void setSpeed(float speed);
	void setDirection(core::vector2df d);
private:
	core::vector2df m_direction;
	float m_speed;
	core::vector2df translation;
	u32 lastUpdateTime;
};

} /* namespace scene */
} /* namespace irr */

#endif /* SRC_GRAPHICS_ANIMATORS_CSCENENODEANIMATORTEXTUREMOVE_H_ */
