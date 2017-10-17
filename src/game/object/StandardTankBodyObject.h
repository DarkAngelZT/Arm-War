/*
 * BasicTankObject.h
 *
 *  Created on: 2017年9月11日
 *      Author: neo
 */

#ifndef SRC_GAME_OBJECT_STANDARDTANKBODYOBJECT_H_
#define SRC_GAME_OBJECT_STANDARDTANKBODYOBJECT_H_
#include "../GameObject.h"
#include "../../graphics/animators/CSceneNodeAnimatorAxisAlignedRotate.h"
#include "../../graphics/animators/CSceneNodeAnimatorTextureMove.h"
class StandardTankBodyObject: public GameObject
{
public:
	StandardTankBodyObject();
	virtual ~StandardTankBodyObject();
	//position is relative
	void setBodyNode(irr::scene::IAnimatedMeshSceneNode*node,
			const irr::core::vector3df& position = irr::core::vector3df(0, 0,
					0));
	irr::scene::IAnimatedMeshSceneNode* getTankBodyNode();
	//position is relative
	void addWheelNode(irr::scene::IAnimatedMeshSceneNode*node,
			std::string side = "left");
	void addTrackNode(irr::scene::IAnimatedMeshSceneNode*node,
			std::string side = "left");
	void setWheelAnimationSpeed(float cycleTime_s, std::string side = "left",
			int direction = 1);
	void setTrackAnimationSpeed(float speed, std::string side = "left",
			const irr::core::vector2df& dir = irr::core::vector2df(1, 0));
	virtual void OnCollisionEnter(GameObject*another);
	virtual void OnCollision(GameObject*another);
	virtual void OnCollisionExit(GameObject*another);

	virtual void setPosition(vector3df& pos);
	virtual void setRotation(vector3df& rot);
	virtual vector3df getPosition() const;
	virtual vector3df getRotation() const;
	virtual bool isActive() const;
	virtual void setActive(bool active);
	virtual bool isVisible() const;
	virtual void setVisible(bool visible);

	virtual RigidBody* AddRigidBody(int collisionShape, float mass);
	virtual RigidBody* AddRigidBody(int collisionShape, float mass,
			const vector3df& position, const vector3df& rotation);

	virtual std::string getObjectType()
	{
		return "StandardTankObject";
	}
protected:
	void ConvertCoordinate(scene::ISceneNode*node, scene::ISceneNode*parent =
	NULL);
	std::vector<scene::IAnimatedMeshSceneNode*> m_left_wheels;
	std::vector<scene::IAnimatedMeshSceneNode*> m_right_wheels;
	scene::CSceneNodeAnimatorAxisAlignedRotate* m_left_wheel_animator;
	scene::CSceneNodeAnimatorAxisAlignedRotate* m_right_wheel_animator;
	scene::IAnimatedMeshSceneNode* m_body;
	scene::IAnimatedMeshSceneNode* m_left_track;
	scene::IAnimatedMeshSceneNode* m_right_track;
	scene::CSceneNodeAnimatorTextureMove*m_left_track_animator;
	scene::CSceneNodeAnimatorTextureMove*m_right_track_animator;
	//父对象的m_sceneNode将作为根对象使用
};

#endif /* SRC_GAME_OBJECT_STANDARDTANKBODYOBJECT_H_ */
