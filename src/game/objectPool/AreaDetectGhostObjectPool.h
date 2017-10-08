/*
 * GhostObjectPool.h
 *
 *  Created on: 2017年10月7日
 *      Author: neo
 */

#ifndef SRC_GAME_OBJECTPOOL_AREADETECTGHOSTOBJECTPOOL_H_
#define SRC_GAME_OBJECTPOOL_AREADETECTGHOSTOBJECTPOOL_H_

#include "NeoObjectPool.h"
#include "../../physics/bulletWrapper/GhostObject.h"
#include <irrlicht.h>
/*
 *GhostObject pool for explosion (mainly use in NeoPhysics)
 */

class AreaDetectGhostObjectPool: public NeoObjectPool<GhostObject>
{
public:
	AreaDetectGhostObjectPool();
	virtual ~AreaDetectGhostObjectPool();
	std::shared_ptr<GhostObject> Create(float radius, irr::core::vector3df pos,
			std::function<
					void(GhostObject*,
							btAlignedObjectArray<btCollisionObject*>&)> overlapCallback);
	void AddToRecycleQueue(std::shared_ptr<GhostObject> object);
	void RecyleAll();
	void Clear();
protected:
	std::vector<std::shared_ptr<GhostObject>> m_recycleQueue;
};

#endif /* SRC_GAME_OBJECTPOOL_AREADETECTGHOSTOBJECTPOOL_H_ */
