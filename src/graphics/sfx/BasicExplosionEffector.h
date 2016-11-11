/*
 * BasicExplosionEffector.h
 *
 *  Created on: 2016年10月4日
 *      Author: neo
 */

#ifndef SRC_GRAPHICS_SFX_BASICEXPLOSIONEFFECTOR_H_
#define SRC_GRAPHICS_SFX_BASICEXPLOSIONEFFECTOR_H_

#include "Effector.h"
#include "../../game/stdafx.h"
using namespace std;
class BasicExplosionEffectParams;
class BasicExplosionEffector: public Effector
{
public:
	static shared_ptr<Effector> Create(NeoData& params);
	virtual void Play();
	virtual BasicExplosionEffector* CreateClone();
	virtual ~BasicExplosionEffector();
	virtual void setParameters(NeoData&data);
	virtual NeoData& getParameters();
private:
	BasicExplosionEffector(BasicExplosionEffectParams& params);
	void Init();
	BasicExplosionEffectParams m_params;
	irr::video::ITexture* m_particle_texture_high;
	irr::video::ITexture* m_particle_texture_low;
	bool active;
};

#endif /* SRC_GRAPHICS_SFX_BASICEXPLOSIONEFFECTOR_H_ */
