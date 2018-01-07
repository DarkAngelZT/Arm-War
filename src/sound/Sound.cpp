/*
 * Sound.cpp
 *
 *  Created on: 2018年1月1日
 *      Author: neo
 */

#include "Sound.h"
#include "script/NeoScript.h"

namespace NeoGame
{
SINGLETON_SOURCE(Sound)

Sound::Sound() :
		m_audio_manager(0), m_audio_id_counter(0)
{

}

bool Sound::Init()
{
	std::string deviceName =
			NeoScript::getInstance()->GetScriptGlobalValue_string(
					"ApplicationSettings.SoundDevice");
	if (m_audio_manager)
	{
		m_audio_manager->shutDown();
		cAudio::destroyAudioManager(m_audio_manager);
	}
	m_device_names.clear();
	// get device list
	cAudio::IAudioDeviceList* device_list = cAudio::createAudioDeviceList();
	unsigned int count = device_list->getDeviceCount();
	m_default_device = std::string(device_list->getDefaultDeviceName().c_str());
	bool in_list = false;
	for (unsigned int i = 0; i < count; i++)
	{
		std::string d = device_list->getDeviceName(i);
		m_device_names.push_back(d);
		if (d == deviceName)
		{
			in_list = true;
		}
	}

	//init manager
	bool success = false;
	if (deviceName.empty() || !in_list)
	{
		m_audio_manager = cAudio::createAudioManager();
		success = true;
	}
	else
	{
		m_audio_manager = cAudio::createAudioManager(false);
		success = m_audio_manager->initialize(deviceName.c_str());
	}

	CAUDIO_DELETE device_list;
	if (success)
	{
		m_listener.setListener(m_audio_manager->getListener());
	}
	return success;
}

bool Sound::setAudioDevice(std::string deviceName)
{
	if (!deviceName.empty() && m_audio_manager)
	{
		m_audio_manager->shutDown();
		return m_audio_manager->initialize(deviceName.c_str());
	}
	return false;
}

std::vector<std::string>& Sound::getDeviceList()
{
	return m_device_names;
}

void Sound::setMasterVolume(float volume)
{
	if (m_audio_manager)
	{
		m_audio_manager->setMasterVolume(volume);
	}
}

float Sound::getMasterVolume()
{
	if (m_audio_manager)
	{
		return m_audio_manager->getMasterVolume();
	}
	return 0;
}

cAudio::IAudioManager* Sound::getAudioManager() const
{
	return m_audio_manager;
}

const std::string& Sound::getDefaultDevice()
{
	return m_default_device;
}

AudioListener& Sound::getListener()
{
	return m_listener;
}

AudioSource* Sound::Play2DSound(std::string path, bool loop)
{
	if (m_audio_manager)
	{
		AudioSource* audio = CreateInstantAudioSource("", path.data(), true);
		if (audio)
		{
			audio->play2d(loop);
			return audio;
		}
	}
	return nullptr;
}

AudioSource* Sound::Play3DSound(std::string path,
		const irr::core::vector3df& pos, bool loop)
{
	if (m_audio_manager)
	{
		AudioSource* audio = CreateInstantAudioSource("", path.data(), true);
		if (audio)
		{
			audio->play3d(pos, 1.0, loop);
			return audio;
		}
	}
	return nullptr;
}

AudioSource* Sound::CreateInstantAudioSource(const char* name,
		const char* filename, bool stream/* = false*/)
{
	if (m_audio_manager)
	{
		if (m_instant_audio_soureces.find(filename)
				== m_instant_audio_soureces.end())
		{
			m_instant_audio_soureces[filename] = AudioPool();
		}
		AudioPool& pool = m_instant_audio_soureces[filename];
		cAudio::IAudioSource* audio = m_audio_manager->create(name, filename,
				stream);
		if (audio)
		{
			std::shared_ptr<AudioSource> audio_source = pool.Create();
			if (!audio_source->isInitialized())
			{
				audio_source->Init(audio, filename);
				InstantSoundEventHandler* handler =
						new InstantSoundEventHandler(audio_source);
				m_instant_audio_event_handlers[filename] = std::shared_ptr<
						InstantSoundEventHandler>(handler);
				audio->registerEventHandler(handler);
			}
			return audio_source.get();
		}
	}
	return nullptr;
}

AudioSource* Sound::CreateAudioSource(const char* name, const char* filename,
		bool stream)
{
	cAudio::IAudioSource* audio = m_audio_manager->create(name, filename,
			stream);
	AudioSource* audio_source = new AudioSource(audio, filename);
	if (not audio_source)
	{
		return nullptr;
	}

	m_audio_sources[m_audio_id_counter] = audio;
	audio_source->setId(m_audio_id_counter);
	m_audio_id_counter++;
	return audio_source;
}

void Sound::ReleaseAudioSource(AudioSource* audio)
{
	auto iter = m_audio_sources.find(audio->getId());
	if (iter != m_audio_sources.end())
	{
		m_audio_manager->release(audio->getAudioSource());
		m_audio_sources.erase(iter);
	}
}

void Sound::Clear()
{
	m_instant_audio_soureces.clear();
	m_audio_sources.clear();
	m_audio_manager->releaseAllSources();
	m_instant_audio_event_handlers.clear();
	m_audio_id_counter = 0;
}

void Sound::RecycleAudioSource(std::shared_ptr<AudioSource> audio)
{
	if (m_instant_audio_soureces.find(audio->getFilePath())
			!= m_instant_audio_soureces.end())
	{
		m_instant_audio_soureces[audio->getFilePath()].Recycle(audio);
	}
}

void Sound::StopAllSounds()
{
	if (m_audio_manager)
	{
		m_audio_manager->stopAllSounds();
	}
}

Sound::~Sound()
{
	if (m_audio_manager)
	{
		m_audio_manager->stopAllSounds();
		Clear();
		cAudio::destroyAudioManager(m_audio_manager);
	}
}

} /* namespace NeoGame */
