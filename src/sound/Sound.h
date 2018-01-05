/*
 * Sound.h
 *
 *  Created on: 2018年1月1日
 *      Author: neo
 */

#ifndef SRC_SOUND_SOUND_H_
#define SRC_SOUND_SOUND_H_

#include "cAudio.h"
#include "game/SingletonMacro.h"
#include <vector>

namespace NeoGame
{

class Sound
{
SINGLETON_HEADER(Sound)
public:
	bool Init();
	bool setAudioDevice(std::string deviceName);
	std::vector<std::string>& getDeviceList();
	void setMasterVolume(float volume);
	float getMasterVolume();
	//TODO add listener and audio source
private:
	Sound();
	virtual ~Sound();

	cAudio::IAudioManager* m_audio_manager;
	std::vector<std::string> m_device_names;
	std::string m_default_device;
};

} /* namespace NeoGame */

#endif /* SRC_SOUND_SOUND_H_ */
