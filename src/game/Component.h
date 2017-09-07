/*
 * Component.h
 *
 *  Created on: 2017年5月6日
 *      Author: neo
 */

#ifndef SRC_GAME_COMPONENT_H_
#define SRC_GAME_COMPONENT_H_

class Component
{
public:
	Component();
	virtual ~Component();

	virtual bool isEnabled() const
	{
		return enabled;
	}

	virtual void setEnabled(bool enabled)
	{
		this->enabled = enabled;
	}

private:
	bool enabled;
};

#endif /* SRC_GAME_COMPONENT_H_ */
