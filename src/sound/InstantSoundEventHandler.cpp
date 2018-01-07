/*
 * SoundEventHandler.cpp
 *
 *  Created on: 2018年1月6日
 *      Author: neo
 */

#include <sound/InstantSoundEventHandler.h>
#include "Sound.h"

namespace NeoGame
{
InstantSoundEventHandler::InstantSoundEventHandler(std::shared_ptr<AudioSource> source) :
		m_source(source)
{
}

void NeoGame::InstantSoundEventHandler::onStop()
{
	if (m_source)
	{
		Sound::getInstance()->RecycleAudioSource(m_source);
	}
}
} /* namespace NeoGame */
