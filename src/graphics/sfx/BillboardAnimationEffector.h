/*
 * BillboardAnimationEffector.h
 *
 *  Created on: 2017年9月22日
 *      Author: neo
 */

#ifndef SRC_GRAPHICS_SFX_BILLBOARDANIMATIONEFFECTOR_H_
#define SRC_GRAPHICS_SFX_BILLBOARDANIMATIONEFFECTOR_H_

#include "Effector.h"
#include "../../game/stdafx.h"
using namespace std;

class BillboardAnimationEffector: public Effector
{
public:
	static shared_ptr<Effector> Create(NeoData& params);
	virtual ~BillboardAnimationEffector();
	virtual void Play();
	virtual Effector* CreateClone();
	virtual void setParameters(NeoData&param);
	virtual NeoData& getParameters();
protected:
	BillboardAnimationEffector(BillboardAnimationEffectorParams&param);
	void Init();
	BillboardAnimationEffectorParams m_params;
	SfxManager::SpriteInfo* m_spriteData;
};

#endif /* SRC_GRAPHICS_SFX_BILLBOARDANIMATIONEFFECTOR_H_ */
