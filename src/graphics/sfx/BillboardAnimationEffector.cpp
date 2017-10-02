/*
 * BillboardAnimationEffector.cpp
 *
 *  Created on: 2017年9月22日
 *      Author: neo
 */

#include "BillboardAnimationEffector.h"

shared_ptr<Effector> BillboardAnimationEffector::Create(NeoData& params)
{
	return std::shared_ptr<Effector>(
			new BillboardAnimationEffector(
					static_cast<BillboardAnimationEffectorParams&>(params)));
}

void BillboardAnimationEffector::Play()
{
	irr::scene::ISceneManager* smgr =
			NeoGraphics::getInstance()->getIrrSceneManger();
	ITimer* sysTimer = NeoGraphics::getInstance()->getDevice()->getTimer();

	scene::ISceneNodeAnimator* spriteAnimator = scene::createSpriteAnimator(
			m_spriteData->texure, m_spriteData->spriteCoordinates,
			m_spriteData->scale, 40, false, sysTimer);
	u32 animateTime = m_spriteData->row * m_spriteData->column * 40;
	scene::ISceneNodeAnimator* deleteAnimator = smgr->createDeleteAnimator(
			animateTime);

	scene::IBillboardSceneNode* sprite = smgr->addBillboardSceneNode();
	sprite->addAnimator(spriteAnimator);
	sprite->addAnimator(deleteAnimator);
	sprite->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);
	sprite->setMaterialFlag(video::EMF_LIGHTING, false);
	sprite->setPosition(m_params.origin);
	sprite->setSize(m_params.size);

	spriteAnimator->drop();
	deleteAnimator->drop();
}

Effector* BillboardAnimationEffector::CreateClone()
{
	return new BillboardAnimationEffector(m_params);
}

void BillboardAnimationEffector::setParameters(NeoData&param)
{
	m_params = static_cast<BillboardAnimationEffectorParams&>(param);
	Init();
}

NeoData& BillboardAnimationEffector::getParameters()
{
	return m_params;
}

BillboardAnimationEffector::~BillboardAnimationEffector()
{
}

void BillboardAnimationEffector::Init()
{
	m_spriteData = NeoGraphics::getInstance()->getSfxManager()->getSpriteTexure(
			m_params.material_name);
}

BillboardAnimationEffector::BillboardAnimationEffector(
		BillboardAnimationEffectorParams& param)
{
	m_params = param;
	Init();
}
