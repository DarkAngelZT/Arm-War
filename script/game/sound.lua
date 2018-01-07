require(DIR_DATA.."game/sound_map")
Sound={
	sound_engine=NeoGame.Sound:getInstance(),
	bgm={},
	effects={},
}

function Sound:StopAllSounds()
	self.sound_engine:StopAllSounds()
end

function Sound:Clear()
	self.sound_engine:Clear()
end

function Sound:Play2D(sound_key, loop, sound_type)
	if sound_key and sound_map[sound_key] then
		sound_type =sound_type or "bgm"
		loop = loop or false
		local volume = 1
		if sound_type == "bgm" then
			volume = ApplicationSettings.SoundVolume.bgm/100
		elseif sound_type == "effect" then
			volume = ApplicationSettings.SoundVolume.effect/100
		end
		local s = self.sound_engine:Play2DSound(DIR_SOUND..sound_map[sound_key],loop)
		s:setVolume(volume)
		return s
	end
	return nil
end

function Sound:Play3D(sound_key, position,loop, sound_type)
	if sound_key and sound_map[sound_key] then
		sound_type =sound_type or "effect"
		loop=loop or false
		local volume = 1
		if sound_type == "bgm" then
			volume = ApplicationSettings.SoundVolume.bgm/100
		elseif sound_type == "effect" then
			volume = ApplicationSettings.SoundVolume.effect/100
		end
		position = position or irr.core.vector3df:new_local()
		local s = self.sound_engine:Play3DSound(DIR_SOUND..sound_map[sound_key],position,loop)
		s:setVolume(volume)
		return s
	end
	return nil
end

function Sound:CreateAudioSource( sound_type,sound_key, sound_name, stream )
	if sound_key and sound_map[sound_key] then
		sound_type =sound_type or "effect"
		sound_name = sound_name or ""
		if stream == nil then
			stream=true
		end
		local volume = 1
		if sound_type == "bgm" then
			volume = ApplicationSettings.SoundVolume.bgm/100
		elseif sound_type == "effect" then
			volume = ApplicationSettings.SoundVolume.effect/100
		end
		local s = self.sound_engine:CreateAudioSource(sound_name,DIR_SOUND..sound_map[sound_key],stream)
		s:setVolume(volume)
		return s
	end
	return nil
end

function Sound:ReleaseAudioSource( audio_source )
	self.sound_engine:ReleaseAudioSource(audio_source)
end

function Sound:setMasterVolume( volume )
	volume = volume or 1
	self.sound_engine:setMasterVolume(volume)
end

function Sound:getListener()
	return self.sound_engine:getListener()
end

function Sound:getDeviceList( )
	return self.sound_engine:getDeviceList()
end