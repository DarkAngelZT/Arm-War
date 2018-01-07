/*
 * AudioSource.cpp
 *
 *  Created on: 2018年1月6日
 *      Author: neo
 */

#include <sound/AudioSource.h>
#include "game/stdafx.h"
#include "sound/Sound.h"

namespace NeoGame
{

AudioSource::AudioSource(cAudio::IAudioSource* audio,
		const std::string& file_path) :
		m_audioSource(audio), path(file_path), initialized(true), id(-1)
{
}

AudioSource::~AudioSource()
{
	Sound::getInstance()->ReleaseAudioSource(this);
}

std::string& AudioSource::getFilePath()
{
	return path;
}

void AudioSource::Init(cAudio::IAudioSource* audio,
		const std::string& file_path)
{
	if (audio)
	{
		m_audioSource = audio;
		path = file_path;
		initialized = true;
	}
}

AudioSource::AudioSource() :
		m_audioSource(nullptr), path(""), initialized(false), id(-1)
{
}

bool AudioSource::play()
{
	if (active and m_audioSource)
	{
		return m_audioSource->play();
	}
	return false;
}

bool AudioSource::play2d(const bool& toLoop)
{
	if (active and m_audioSource)
	{
		return m_audioSource->play2d(toLoop);
	}
	return false;
}

bool AudioSource::play3d(const irr::core::vector3df& position,
		const float& soundstr, const bool& toLoop)
{
	if (active and m_audioSource)
	{
		return m_audioSource->play3d(
				cAudio::cVector3(const_cast<float*>(&position.X)), soundstr,
				toLoop);
	}
	return false;
}

void AudioSource::pause()
{
	if (active and m_audioSource)
	{
		m_audioSource->pause();
	}
}

void AudioSource::stop()
{
	if (active and m_audioSource)
	{
		m_audioSource->stop();
	}
}

void AudioSource::loop(const bool& toLoop)
{
	if (active and m_audioSource)
	{
		m_audioSource->loop(toLoop);
	}
}

bool AudioSource::seek(const float& seconds, bool relative)
{
	if (active and m_audioSource)
	{
		return m_audioSource->seek(seconds, relative);
	}
	return false;
}

float AudioSource::getTotalAudioTime()
{
	if (active and m_audioSource)
	{
		return m_audioSource->getTotalAudioTime();
	}
	return 0;
}

int AudioSource::getTotalAudioSize()
{
	if (active and m_audioSource)
	{
		return m_audioSource->getTotalAudioSize();
	}
	return 0;
}

int AudioSource::getCompressedAudioSize()
{
	if (active and m_audioSource)
	{
		return m_audioSource->getCompressedAudioSize();
	}
	return 0;
}

float AudioSource::getCurrentAudioTime()
{
	if (active and m_audioSource)
	{
		return m_audioSource->getCurrentAudioTime();
	}
	return 0;
}

int AudioSource::getCurrentAudioPosition()
{
	if (active and m_audioSource)
	{
		return m_audioSource->getCurrentAudioPosition();
	}
	return 0;
}

int AudioSource::getCurrentCompressedAudioPosition()
{
	if (active and m_audioSource)
	{
		return m_audioSource->getCurrentCompressedAudioPosition();
	}
	return 0;
}

bool AudioSource::isValid() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->isValid();
	}
	return false;
}

bool AudioSource::isPlaying() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->isPlaying();
	}
	return false;
}

bool AudioSource::isPaused() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->isPaused();
	}
	return false;
}

bool AudioSource::isStopped() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->isStopped();
	}
	return false;
}

bool AudioSource::isLooping() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->isLooping();
	}
	return false;
}

void AudioSource::setPosition(const irr::core::vector3df& position)
{
	if (active and m_audioSource)
	{
		m_audioSource->setPosition(
				cAudio::cVector3(const_cast<float*>(&position.X)));
	}
}

void AudioSource::setVelocity(const irr::core::vector3df& velocity)
{
	if (active and m_audioSource)
	{
		m_audioSource->setVelocity(
				cAudio::cVector3(const_cast<float*>(&velocity.X)));
	}
}

void AudioSource::setDirection(const irr::core::vector3df& direction)
{
	if (active and m_audioSource)
	{
		m_audioSource->setDirection(
				cAudio::cVector3(const_cast<float*>(&direction.X)));
	}
}

void AudioSource::setRolloffFactor(const float& rolloff)
{
	if (active and m_audioSource)
	{
		m_audioSource->setRolloffFactor(rolloff);
	}
}

void AudioSource::setStrength(const float& soundstrength)
{
	if (active and m_audioSource)
	{
		m_audioSource->setStrength(soundstrength);
	}
}

void AudioSource::setMinDistance(const float& minDistance)
{
	if (active and m_audioSource)
	{
		m_audioSource->setMinDistance(minDistance);
	}
}

void AudioSource::setMaxAttenuationDistance(const float& maxDistance)
{
	if (active and m_audioSource)
	{
		m_audioSource->setMaxAttenuationDistance(maxDistance);
	}
}

void AudioSource::setPitch(const float& pitch)
{
	if (active and m_audioSource)
	{
		m_audioSource->setPitch(pitch);
	}
}

void AudioSource::setVolume(const float& volume)
{
	if (active and m_audioSource)
	{
		m_audioSource->setVolume(volume);
	}
}

void AudioSource::setMinVolume(const float& minVolume)
{
	if (active and m_audioSource)
	{
		m_audioSource->setMinVolume(minVolume);
	}
}

void AudioSource::setMaxVolume(const float& maxVolume)
{
	if (active and m_audioSource)
	{
		m_audioSource->setMaxVolume(maxVolume);
	}
}

void AudioSource::setInnerConeAngle(const float& innerAngle)
{
	if (active and m_audioSource)
	{
		m_audioSource->setInnerConeAngle(innerAngle);
	}
}

void AudioSource::setOuterConeAngle(const float& outerAngle)
{
	if (active and m_audioSource)
	{
		m_audioSource->setOuterConeAngle(outerAngle);
	}
}

void AudioSource::setOuterConeVolume(const float& outerVolume)
{
	if (active and m_audioSource)
	{
		m_audioSource->setOuterConeVolume(outerVolume);
	}
}

void AudioSource::setDopplerStrength(const float& dstrength)
{
	if (active and m_audioSource)
	{
		m_audioSource->setDopplerStrength(dstrength);
	}
}

void AudioSource::setDopplerVelocity(const irr::core::vector3df& dvelocity)
{
	if (active and m_audioSource)
	{
		m_audioSource->setDopplerVelocity(
				cAudio::cVector3(const_cast<float*>(&dvelocity.X)));
	}
}

void AudioSource::move(const irr::core::vector3df& position)
{
	if (active and m_audioSource)
	{
		m_audioSource->move(cAudio::cVector3(const_cast<float*>(&position.X)));
	}
}

irr::core::vector3df AudioSource::getPosition()
{
	if (active and m_audioSource)
	{
		cAudio::cVector3 pos = m_audioSource->getPosition();
		return irr::core::vector3df(pos.x, pos.y, pos.z);
	}
	return irr::core::vector3df();
}

irr::core::vector3df AudioSource::getVelocity()
{
	if (active and m_audioSource)
	{
		cAudio::cVector3 v = m_audioSource->getVelocity();
		return irr::core::vector3df(v.x, v.y, v.z);
	}
	return irr::core::vector3df();
}

irr::core::vector3df AudioSource::getDirection()
{
	if (active and m_audioSource)
	{
		cAudio::cVector3 d = m_audioSource->getDirection();
		return irr::core::vector3df(d.x, d.y, d.z);
	}
	return irr::core::vector3df();
}

float AudioSource::getRolloffFactor() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getRolloffFactor();
	}
	return 1;
}

float AudioSource::getStrength() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getStrength();
	}
	return 0;
}

float AudioSource::getMinDistance() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getMinDistance();
	}
	return 0;
}

float AudioSource::getMaxDistance() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getMaxDistance();
	}
	return 0;
}

bool AudioSource::isRelative() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->isRelative();
	}
	return false;
}

float AudioSource::calculateGain() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->calculateGain();
	}
	return 0;
}

float AudioSource::getPitch() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getPitch();
	}
	return 0;
}

float AudioSource::getVolume() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getVolume();
	}
	return 0;
}

float AudioSource::getMinVolume() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getMinVolume();
	}
	return 0;
}

float AudioSource::getMaxVolume() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getMaxVolume();
	}
	return 0;
}

float AudioSource::getInnerConeAngle() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getInnerConeAngle();
	}
	return 0;
}

float AudioSource::getOuterConeAngle() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getOuterConeAngle();
	}
	return 0;
}

float AudioSource::getOuterConeVolume() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getOuterConeVolume();
	}
	return 0;
}

float AudioSource::getDopplerStrength() const
{
	if (active and m_audioSource)
	{
		return m_audioSource->getDopplerStrength();
	}
	return 0;
}

irr::core::vector3df AudioSource::getDopplerVelocity()
{
	if (active and m_audioSource)
	{
		cAudio::cVector3 dv = m_audioSource->getDopplerVelocity();
		return irr::core::vector3df(dv.x, dv.y, dv.z);
	}
	return irr::core::vector3df();
}

std::shared_ptr<AudioSource> AudioSource::Create()
{
	return std::shared_ptr<AudioSource>(new AudioSource);
}

void AudioSource::Update()
{
	if (gameObject)
	{
		move(gameObject->getPosition());
	}
}

cAudio::IAudioSource* AudioSource::getAudioSource()
{
	return m_audioSource;
}

void AudioSource::setAudioSource(cAudio::IAudioSource* audioSource)
{
	m_audioSource = audioSource;
}

void AudioSource::setPath(const std::string& path)
{
	this->path = path;
}

int AudioSource::getId()
{
	return id;
}

void AudioSource::setId(int id)
{
	this->id = id;
}

bool AudioSource::isInitialized()
{
	return initialized;
}

} /* namespace NeoGame */
