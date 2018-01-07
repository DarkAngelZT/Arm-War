/*
 * AudioSource.h
 *
 *  Created on: 2018年1月6日
 *      Author: neo
 */

#ifndef SRC_SOUND_AUDIOSOURCE_H_
#define SRC_SOUND_AUDIOSOURCE_H_

#include <cAudio.h>
#include <irrlicht.h>
#include <memory>
#include "game/NeoReusableObject.h"
#include "game/Component.h"

class Component;
class NeoReusableObject;

namespace NeoGame
{
class AudioSource: public Component, public NeoReusableObject
{
public:
	AudioSource(cAudio::IAudioSource*audio, const std::string& file_path);
	AudioSource();
	~AudioSource();
	//for object pool
	static std::shared_ptr<AudioSource> Create();

	void Init(cAudio::IAudioSource*audio, const std::string& file_path);
	std::string& getFilePath();
	void setAudioSource(cAudio::IAudioSource* audioSource);
	void setPath(const std::string& path);
	bool isInitialized();
	int getId();
	void setId(int id);

	virtual void Update();

	//! Plays the source with the last set parameters.
	/**
	 \return True if the source is playing, false if not. */
	virtual bool play();

	//! Plays the source in 2D mode.
	/** No automatic attenuation or panning will take place in this mode, but using setPosition will allow you to manually pan mono audio streams.
	 \param toLoop: Whether to loop (restart) the audio when the end is reached.
	 \return True if the source is playing, false if not. */
	virtual bool play2d(const bool& toLoop = false);

	//! Plays the source in 3D mode.
	/**
	 \param position: Position to start the sound off at.
	 \param soundstr: Affects how the source attenuates due to distance.  Higher values cause the source to stand out more over distance.
	 \param toLoop: Whether to loop (restart) the audio when the end is reached.
	 \return True if the source is playing, false if not. */
	virtual bool play3d(const irr::core::vector3df& position,
			const float& soundstr = 1.0, const bool& toLoop = false);

	//! Pauses playback of the sound source.
	virtual void pause();

	//! Stops playback of the sound source.
	virtual void stop();

	//! Controls whether the source should loop or not.
	/** \param toLoop: Whether to loop (restart) the audio when the end is reached. */
	virtual void loop(const bool& toLoop);

	//! Seeks through the audio stream to a specific spot.
	/** Note: May not be supported by all codecs.
	 \param seconds: Number of seconds to seek.
	 \param relative: Whether to seek from the current position or the start of the stream.
	 \return True on success, False if the codec does not support seeking. */
	virtual bool seek(const float& seconds, bool relative = false);
	//! Returns the total amount of time in the audio stream.  See IAudioDecoder for details.
	virtual float getTotalAudioTime();

	//! Returns the total decoded size of the audio stream.  See IAudioDecoder for details.
	virtual int getTotalAudioSize();

	//! Returns the original size of the audio stream.  See IAudioDecoder for details.
	virtual int getCompressedAudioSize();

	//! Returns the current position in the audio stream in seconds.  See IAudioDecoder for details.
	virtual float getCurrentAudioTime();

	//! Returns the current position in the decoded audio stream in bytes.  See IAudioDecoder for details.
	virtual int getCurrentAudioPosition();

	//! Returns the current position in the original audio stream in bytes.  See IAudioDecoder for details.
	virtual int getCurrentCompressedAudioPosition();
	//! Returns if the source is ready to be used.
	virtual bool isValid() const; //

	//! Returns if the source is playing.
	virtual bool isPlaying() const;

	//! Returns if the source is paused.
	virtual bool isPaused() const;

	//! Returns if the source is stopped.
	virtual bool isStopped() const;

	//! Returns if the source is looping.
	virtual bool isLooping() const;

	//! Sets the position of the source in 3D space.
	/**
	 \param position: A 3D vector giving the new location to put this source. */
	virtual void setPosition(const irr::core::vector3df& position);

	//! Sets the current velocity of the source for doppler effects.
	/**
	 \param velocity: A 3D vector giving the speed and direction that the source is moving. */
	virtual void setVelocity(const irr::core::vector3df& velocity);

	//! Sets the direction the source is facing.
	/**
	 \param direction: A 3D vector giving the direction that the source is aiming. */
	virtual void setDirection(const irr::core::vector3df& direction);

	//! Sets the factor used in attenuating the source over distance.
	/** Larger values make it attenuate faster, smaller values make the source carry better.
	 Range: 0.0f to +inf (Default: 1.0f).
	 \param rolloff: The rolloff factor to apply to the attenuation calculation. */
	virtual void setRolloffFactor(const float& rolloff);

	//! Sets how well the source carries over distance.
	/** Same as setRolloffFactor(1.0f/soundstrength).
	 Range: 0.0f to +inf (Default: 1.0f).
	 \param soundstrength: How well the sound carries over distance. */
	virtual void setStrength(const float& soundstrength);
	//! Sets the distance from the source where attenuation will begin.
	/** Range: 0.0f to +inf
	 \param minDistance: Distance from the source where attenuation begins. */
	virtual void setMinDistance(const float& minDistance);

	//! Sets the distance from the source where attenuation will stop.
	/** Range: 0.0f to +inf
	 \param maxDistance: Distance where attenuation will cease.  Normally the farthest range you can hear the source. */
	virtual void setMaxAttenuationDistance(const float& maxDistance);

	//! Sets the pitch of the source.
	/** Range: 0.0f to +inf (Default: 1.0f)
	 \param pitch: New pitch level.  Note that higher values will speed up the playback of the sound. */
	virtual void setPitch(const float& pitch);

	//! Sets the source volume before attenuation and other effects.
	/** Range: 0.0f to +inf (Default: 1.0f).
	 \param volume: New volume of the source. */
	virtual void setVolume(const float& volume);

	//! Sets the minimum volume that the source can be attenuated to.
	/** Range: 0.0f to +inf (Default: 0.0f).
	 \param minVolume: New minimum volume of the source. */
	virtual void setMinVolume(const float& minVolume);

	//! Sets the maximum volume that the source can achieve.
	/** Range: 0.0f to +inf (Default: 1.0f).
	 \param maxVolume: New maximum volume of the source. */
	virtual void setMaxVolume(const float& maxVolume);

	//! Sets the angle of the inner sound cone of the source.  The cone opens up in the direction of the source as set by setDirection().
	/** Note: This causes the sound to be loudest only if the listener is inside this cone.
	 Range: 0.0f to 360.0f (Default: 360.0f).
	 \param innerAngle: Inside angle of the cone. */
	virtual void setInnerConeAngle(const float& innerAngle);

	//! Sets the angle of the outer sound cone of the source. The cone opens up in the direction of the source as set by setDirection().
	/** Note: If the listener is outside of this cone, the sound cannot be heard.  Between the inner cone angle and this angle, the sound volume will fall off.
	 Range: 0.0f to 360.0f (Default: 360.0f).
	 \param outerAngle: Outside angle of the cone. */
	virtual void setOuterConeAngle(const float& outerAngle);

	//! Sets how much the volume of the source is scaled in the outer cone.
	/** Range: 0.0f to +inf (Default: 0.0f).
	 \param outerVolume: Volume of the source in the outside cone. */
	virtual void setOuterConeVolume(const float& outerVolume);

	//! Sets the doppler strength, which enhances or diminishes the doppler effect.  Can be used to exaggerate the doppler for a special effect.
	/** Range: 0.0f to +inf (Default: 1.0f).
	 \param dstrength: New strength for the doppler effect. */
	virtual void setDopplerStrength(const float& dstrength);
	//! Overrides the doppler velocity vector.  It is usually better to let the engine take care of it automatically.
	/** Note: must be set every time you set the position, velocity, or direction.
	 \param dvelocity: New doppler vector for the source. */
	virtual void setDopplerVelocity(const irr::core::vector3df& dvelocity);

	//! Convenience function to automatically set the velocity and position for you in a single call.
	/** Velocity will be set to new position - last position.
	 \param position: Position to move the source to. */
	virtual void move(const irr::core::vector3df& position);

	//! Returns the audio objects position
	virtual irr::core::vector3df getPosition();

	//! Returns the audio objects velocity
	virtual irr::core::vector3df getVelocity();

	//! Returns the audio objects direction
	virtual irr::core::vector3df getDirection();
	//! Returns the factor used in attenuating the source over distance
	virtual float getRolloffFactor() const;

	//! Returns the strength of the source
	virtual float getStrength() const;

	//! Returns the distance from the source where attenuation will begin
	virtual float getMinDistance() const;

	//! Returns the distance from the source where attenuation will stop
	virtual float getMaxDistance() const;

	//! Return true for 2d sounds, false for 3d sounds
	virtual bool isRelative() const;

	//! Return gain, taking into account volume as well as distance attenuation
	virtual float calculateGain() const;

	//! Returns the pitch of the source
	virtual float getPitch() const;

	//! Returns the source volume before attenuation and other effects
	virtual float getVolume() const;

	//! Returns the minimum volume that the source can be attenuated to
	virtual float getMinVolume() const;

	//! Returns the maximum volume that the source can achieve
	virtual float getMaxVolume() const;

	//! Returns the angle of the inner sound cone of the source
	virtual float getInnerConeAngle() const;

	//! Returns the angle of the outer sound cone of the source
	virtual float getOuterConeAngle() const;

	//! Returns how much the volume of the source is scaled in the outer cone
	virtual float getOuterConeVolume() const;

	//! Returns the doppler strength, which enhances or diminishes the doppler effect
	virtual float getDopplerStrength() const;

	//! Returns the override for the doppler velocity vector
	virtual irr::core::vector3df getDopplerVelocity();
	//----c++ only----
	cAudio::IAudioSource* getAudioSource();

private:
	cAudio::IAudioSource* m_audioSource;
	std::string path;
	bool initialized;
	int id;
};

} /* namespace NeoGame */

#endif /* SRC_SOUND_AUDIOSOURCE_H_ */
