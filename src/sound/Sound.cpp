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
		m_audio_manager(0)
{

}

bool Sound::Init()
{
	std::string deviceName = NeoScript::getInstance()->GetScriptGlobalValue_string(
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

Sound::~Sound()
{
	if (m_audio_manager)
	{
		cAudio::destroyAudioManager(m_audio_manager);
	}
}

} /* namespace NeoGame */
