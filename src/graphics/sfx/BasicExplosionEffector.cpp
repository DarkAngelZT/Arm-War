/*
 * BasicExplosionEffector.cpp
 *
 *  Created on: 2016年10月4日
 *      Author: neo
 */

#include "BasicExplosionEffector.h"
#include "../../game/stdafx.h"

void BasicExplosionEffector::setParameters(NeoData&data)
{
	m_params = static_cast<BasicExplosionEffectParams&>(data);
	Init();
}

NeoData& BasicExplosionEffector::getParameters()
{
	return m_params;
}

BasicExplosionEffector::BasicExplosionEffector(
		BasicExplosionEffectParams&params)
{
	m_params = params;
	Init();
}

shared_ptr<Effector> BasicExplosionEffector::Create(NeoData& params)
{
	return std::shared_ptr<Effector>(
			new BasicExplosionEffector(
					static_cast<BasicExplosionEffectParams&>(params)));
}

BasicExplosionEffector::~BasicExplosionEffector()
{
	// TODO 自动生成的析构函数存根
}

void BasicExplosionEffector::Play()
{
	irr::scene::ISceneManager *smgr =
			NeoGraphics::getInstance()->getIrrSceneManger();
	irr::IrrlichtDevice* device = NeoGraphics::getInstance()->getDevice();
	irr::scene::IParticleSystemSceneNode*ps_high =
			smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleSystemSceneNode*ps_low =
			smgr->addParticleSystemSceneNode(false);
	//粒子系统,爆炸中心
	irr::scene::IParticleSphereExplosionEmitter* emitter_high_speed =
			irr::scene::CreateExplosionSphereEmitter(m_params.origin, //中心位置
					m_params.fRadius, //emitter半径
					vector3df(0, m_params.fRadius / 800.f, 0), //初始方向
					200,
					500, //每秒最少、最多发射粒子数
					m_params.start_color_high_speed,
					m_params.start_color_high_speed, 500, 1200, //粒子生存周期
					360, //偏角
					dimension2df(40.f, 40.f), dimension2df(60.f, 60.f), //粒子最小尺寸、最大尺寸
					static_cast<u32>(m_params.fRadius * 100) //最多释放粒子数
					);
	emitter_high_speed->Configure(device);
	ps_high->setEmitter(emitter_high_speed);
	//粒子系统,爆炸烟雾
	irr::scene::IParticleSphereExplosionEmitter* emitter_low_speed =
			irr::scene::CreateExplosionSphereEmitter(m_params.origin, //中心位置
					m_params.fRadius, //emitter半径
					vector3df(0, m_params.fRadius / 900.f, 0), //初始方向
					200,
					500, //每秒最少、最多发射粒子数
					m_params.start_color_low_speed,
					m_params.start_color_low_speed, 600, 1500, //粒子生存周期
					360, //偏角
					dimension2df(40.f, 40.f), dimension2df(60.f, 60.f), //粒子最小尺寸、最大尺寸
					static_cast<u32>(m_params.fRadius * 100) //最多释放粒子数
					);
	emitter_low_speed->Configure(device);
	ps_low->setEmitter(emitter_low_speed);
	//粒子系统效果
	irr::scene::IParticleAffector* fade_out_affector_high =
			irr::scene::CreateColourAffactorQ(m_params.start_color_high_speed,
					m_params.end_color_high_speed);
	ps_high->addAffector(fade_out_affector_high);
	irr::scene::IParticleGravityAffector* gravity_affector_high =
			ps_high->createGravityAffector(vector3df(0, 0.8f, 0));
	ps_high->addAffector(gravity_affector_high);
	irr::scene::ISceneNodeAnimator* delete_animator_high =
			smgr->createDeleteAnimator(3000);
	ps_high->addAnimator(delete_animator_high);
	ps_high->setPosition(m_params.origin);
	ps_high->setRotation(m_params.rotation);
	ps_high->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps_high->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps_high->setMaterialTexture(0, m_particle_texture_high);
	//ps_high->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

	irr::scene::IParticleAffector* fade_out_affector_low =
			irr::scene::CreateColourAffactorQ(m_params.start_color_low_speed,
					m_params.end_color_low_speed);
	ps_low->addAffector(fade_out_affector_low);
	irr::scene::IParticleGravityAffector* gravity_affector_low =
			ps_low->createGravityAffector(vector3df(0, 1, 0));
	ps_low->addAffector(gravity_affector_low);
	irr::scene::ISceneNodeAnimator* delete_animator_low =
			smgr->createDeleteAnimator(4000);
	ps_low->addAnimator(delete_animator_low);
	ps_low->setPosition(m_params.origin);
	ps_low->setRotation(m_params.rotation);
	ps_low->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps_low->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps_low->setMaterialTexture(0, m_particle_texture_high);
	//ps_low->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	//火光效果
	irr::scene::ILightSceneNode* blast_light = smgr->addLightSceneNode(0,
			m_params.origin, video::SColorf(1.f, 1.f, 1.f), m_params.fRadius);
	irr::scene::ISceneNodeAnimator*blast_life = smgr->createDeleteAnimator(
			1000);
	//blast_light->enableCastShadow(false);
	blast_light->addAnimator(blast_life);
	//释放临时对象
	blast_life->drop();
	emitter_high_speed->drop();
	emitter_low_speed->drop();
	fade_out_affector_high->drop();
	fade_out_affector_low->drop();
	delete_animator_high->drop();
	delete_animator_low->drop();
	gravity_affector_high->drop();
	gravity_affector_low->drop();
}

BasicExplosionEffector* BasicExplosionEffector::CreateClone()
{
	BasicExplosionEffector* new_instance = new BasicExplosionEffector(m_params);
	return new_instance;
}

void BasicExplosionEffector::Init()
{
	m_particle_texture_high =
			NeoGraphics::getInstance()->getSfxManager()->getParticleTexure(
					m_params.material_name_high_speed);
	m_particle_texture_low =
			NeoGraphics::getInstance()->getSfxManager()->getParticleTexure(
					m_params.material_name_low_speed);
}
