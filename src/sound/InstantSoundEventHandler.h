/*
 * SoundEventHandler.h
 *
 *  Created on: 2018年1月6日
 *      Author: neo
 */

#ifndef SRC_SOUND_INSTANTSOUNDEVENTHANDLER_H_
#define SRC_SOUND_INSTANTSOUNDEVENTHANDLER_H_

#include <ISourceEventHandler.h>
#include "AudioSource.h"
#include <memory>

namespace NeoGame
{
class AudioSource;
class InstantSoundEventHandler: public cAudio::ISourceEventHandler
{
public:
	InstantSoundEventHandler(std::shared_ptr<AudioSource> source);
	virtual void onStop();
private:
	std::shared_ptr<AudioSource> m_source;
};

} /* namespace NeoGame */

#endif /* SRC_SOUND_INSTANTSOUNDEVENTHANDLER_H_ */
