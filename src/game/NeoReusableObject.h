/*
 * NeoReusableObject.h
 *
 *  Created on: 2016年10月27日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOREUSABLEOBJECT_H_
#define SRC_GAME_NEOREUSABLEOBJECT_H_
#include <functional>
/*
 *base class for object pool element
 */
class NeoReusableObject
{
public:
	NeoReusableObject(){active=true;}
	virtual ~NeoReusableObject(){}
	virtual void Reset(){}
	bool isActive() const
	{
		return active;
	}

	void setActive(bool active)
	{
		this->active = active;
	}
	virtual void setRecycleCallback(std::function<void()>funtor){}
protected:
	bool active;
};

#endif /* SRC_GAME_NEOREUSABLEOBJECT_H_ */
