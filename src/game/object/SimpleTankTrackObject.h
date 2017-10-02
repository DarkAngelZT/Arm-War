/*
 * SimpleTankTrackObject.h
 *
 *  Created on: 2017年9月11日
 *      Author: neo
 */

#ifndef SRC_GAME_OBJECT_SIMPLETANKTRACKOBJECT_H_
#define SRC_GAME_OBJECT_SIMPLETANKTRACKOBJECT_H_

#include "../GameObject.h"

class SimpleTankTrackObject: public GameObject
{
public:
	SimpleTankTrackObject();
	virtual ~SimpleTankTrackObject();
	virtual void OnContactCallback(btPersistentManifold*pm, GameObject*another);
	virtual RigidBody* AddRigidBody(int collisionShape, float mass);
	float getSpeed() const;
	void setSpeed(float speed);
	virtual std::string getType()
	{
		return "SimpleTankTrackObject";
	}
private:
	float m_speed;
};

#endif /* SRC_GAME_OBJECT_SIMPLETANKTRACKOBJECT_H_ */
