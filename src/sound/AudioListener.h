/*
 * AudioListener.h
 *
 *  Created on: 2018年1月5日
 *      Author: neo
 */

#ifndef SRC_SOUND_AUDIOLISTENER_H_
#define SRC_SOUND_AUDIOLISTENER_H_

#include <cAudio.h>
#include <irrlicht.h>
#include "game/Component.h"

class Component;
class NeoReusableObject;

namespace NeoGame
{

class AudioListener : Component
{
public:
	AudioListener();
	virtual ~AudioListener();
	cAudio::IListener* getListener();
	void setListener(cAudio::IListener* listener);
	void setPosition(const irr::core::vector3df& position);
	//! Sets the direction the listener is facing
	/**
	 \param dir: New direction vector for the listener. */
	void setDirection(const irr::core::vector3df& dir);

	//! Sets the up vector to use for the listener
	/** Default up vector is Y+, same as OpenGL.
	 \param up: New up vector for the listener. */
	void setUpVector(const irr::core::vector3df& up);
	//! Sets the global volume modifier (will effect all sources)
	/**
	 \param volume: Volume to scale all sources by. Range: 0.0 to +inf. */
	void setMasterVolume( float volume);
	float getMasterVolume(void);
	virtual void Update();
private:
	cAudio::IListener* m_listener;
};

} /* namespace NeoGame */

#endif /* SRC_SOUND_AUDIOLISTENER_H_ */
