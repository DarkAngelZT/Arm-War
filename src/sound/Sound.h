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
#include "game/objectPool/NeoObjectPool.h"
#include "InstantSoundEventHandler.h"
#include <vector>
#include <unordered_map>
#include <memory.h>
#include "AudioListener.h"
#include "AudioSource.h"

namespace NeoGame
{
class AudioListener;
class AudioSource;
class InstantSoundEventHandler;

typedef NeoObjectPool<AudioSource> AudioPool;

class Sound
{
SINGLETON_HEADER(Sound)
public:
	bool Init();
	void Clear();
	bool setAudioDevice(std::string deviceName);
	std::vector<std::string>& getDeviceList();
	void setMasterVolume(float volume);
	float getMasterVolume();

	AudioSource* Play2DSound(std::string path, bool loop = false);
	AudioSource* Play3DSound(std::string path, const irr::core::vector3df& pos =
			irr::core::vector3df(), bool loop = false);

	//audio source for instant use, will self-deactive when stopped
	AudioSource* CreateInstantAudioSource(const char* name,
			const char* filename, bool stream = false);
	//normal audio source
	AudioSource* CreateAudioSource(const char* name, const char* filename,
			bool stream = false);
	void ReleaseAudioSource(AudioSource*audio);
	void StopAllSounds();
	const std::string& getDefaultDevice();
	AudioListener& getListener();
	//--------c++ only------------//
	cAudio::IAudioManager* getAudioManager() const;
	void RecycleAudioSource(std::shared_ptr<AudioSource> audio);
private:
	Sound();
	virtual ~Sound();

	cAudio::IAudioManager* m_audio_manager;
	std::vector<std::string> m_device_names;
	std::string m_default_device;
	AudioListener m_listener;
	std::unordered_map<std::string, AudioPool> m_instant_audio_soureces;
	std::unordered_map<std::string, std::shared_ptr<InstantSoundEventHandler>> m_instant_audio_event_handlers;
	std::unordered_map<int, cAudio::IAudioSource*> m_audio_sources;
	int m_audio_id_counter;
};

} /* namespace NeoGame */

#endif /* SRC_SOUND_SOUND_H_ */
