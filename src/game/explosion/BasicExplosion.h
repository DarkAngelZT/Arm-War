/*
 * BasicExplosion.h
 *
 *  Created on: 2016年10月7日
 *      Author: neo
 */

#ifndef SRC_GAME_EXPLOSION_BASICEXPLOSION_H_
#define SRC_GAME_EXPLOSION_BASICEXPLOSION_H_
#include "../../graphics/sfx/BasicExplosionEffector.h"
#include "../../physics/BasicExplosionPhysics.h"
#include "Explosion.h"
class Effector;
class ExplosionPhysics;

class BasicExplosion: public Explosion
{
public:
	virtual ~BasicExplosion();
	virtual void Play();
	virtual void Reset();
	virtual void setParams(NeoData&visual_p, NeoData&Physics_p);
	static std::shared_ptr<Explosion> Create(NeoData&visual_p,
			NeoData&Physics_p);
	const std::shared_ptr<Effector>& getEffector() const;
	void setEffector(const std::shared_ptr<Effector>& effector);
	const std::shared_ptr<ExplosionPhysics>& getPhysicsEmulator() const;
	void setPhysicsEmulator(
			const std::shared_ptr<ExplosionPhysics>& physicsEmulator);
	virtual void setRecycleCallback(const std::function<void()>&funtor);

private:
	BasicExplosion();
	std::shared_ptr<Effector> effector;
	std::shared_ptr<ExplosionPhysics> physics_emulator;
};

#endif /* SRC_GAME_EXPLOSION_BASICEXPLOSION_H_ */
