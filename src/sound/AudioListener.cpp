/*
 * AudioListener.cpp
 *
 *  Created on: 2018年1月5日
 *      Author: neo
 */

#include <sound/AudioListener.h>
#include <irrlicht.h>

using namespace irr;
namespace NeoGame
{

AudioListener::AudioListener() :
		m_listener(0)
{
}

AudioListener::~AudioListener()
{
}

cAudio::IListener* AudioListener::getListener()
{
	return m_listener;
}

void AudioListener::setListener(cAudio::IListener* listener)
{
	m_listener = listener;
}

void AudioListener::setPosition(const irr::core::vector3df& position)
{
	if (m_listener)
	{
		m_listener->setPosition(
				cAudio::cVector3(const_cast<float*>(&position.X)));
	}
}

void AudioListener::setMasterVolume(float volume)
{
	if (m_listener)
	{
		m_listener->setMasterVolume(volume);
	}
}

void AudioListener::setDirection(const irr::core::vector3df& dir)
{
	if (m_listener)
	{
		m_listener->setDirection(cAudio::cVector3(const_cast<float*>(&dir.X)));
	}
}

void AudioListener::setUpVector(const irr::core::vector3df& up)
{
	if (m_listener)
	{
		m_listener->setUpVector(cAudio::cVector3(const_cast<float*>(&up.X)));
	}
}

float AudioListener::getMasterVolume(void)
{
	if (m_listener)
	{
		return m_listener->getMasterVolume();
	}
	return 0;
}

void AudioListener::Update()
{
	if (gameObject)
	{
		setPosition(gameObject->getPosition());
		switch (gameObject->GetSceneNode()->getType())
		{
		case irr::scene::ESNT_CAMERA:
		case irr::scene::ESNT_CAMERA_FPS:
		case irr::scene::ESNT_CAMERA_MAYA:
		{
			irr::scene::ICameraSceneNode* camera =
					static_cast<irr::scene::ICameraSceneNode*>(gameObject->GetSceneNode());
			setUpVector(camera->getUpVector());
			core::vector3df forward= camera->getTarget() - camera->getAbsolutePosition();
			setDirection(forward);
			break;
		}
		default:
			break;
		}
	}
}

} /* namespace NeoGame */

