/*
 * ExplosionObjectPool.h
 *
 *  Created on: 2016年10月27日
 *      Author: neo
 */

#ifndef SRC_GAME_EXPLOSIONOBJECTPOOL_H_
#define SRC_GAME_EXPLOSIONOBJECTPOOL_H_

#include "NeoObjectPool.h"
#include "../explosion/Explosion.h"
#include <map>
using namespace std;
/*
 *object pool for explosion
 */
class NeoData;
class Explosion;
class ExplosionObjectPool: public NeoObjectPool<Explosion>
{
public:
	ExplosionObjectPool();
	virtual ~ExplosionObjectPool();
	shared_ptr<Explosion> Create(std::string& type,NeoData&param_visual, NeoData&param_pyhsics);
	void RegisterCreator(std::string type_str,
			std::function<shared_ptr<Explosion>(NeoData&, NeoData&)> functor);
private:
	//creator
	std::map<std::string,
			std::function<shared_ptr<Explosion>(NeoData&, NeoData&)>> explosion_creator;
};

#endif /* SRC_GAME_EXPLOSIONOBJECTPOOL_H_ */
