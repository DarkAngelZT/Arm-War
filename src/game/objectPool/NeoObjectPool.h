/*
 * NeoObjectPool.h
 *
 *  Created on: 2016年10月26日
 *      Author: neo
 */

#ifndef SRC_GAME_NEOOBJECTPOOL_H_
#define SRC_GAME_NEOOBJECTPOOL_H_
#include <memory>
#include <list>
#include <algorithm>
using namespace std;
/*
 *generic object pool,the object class should
 *have a static function Create()
 *non-static member functions: setActive(), isActive() and Reset() function,
 *also you need to call Recycle(object) to return your unused object
 */
template<typename T>
class NeoObjectPool
{
public:
	NeoObjectPool();
	virtual ~NeoObjectPool();
	void Clear();
	void Recycle(shared_ptr<T> object);
	std::shared_ptr<T> Create();
protected:
	std::list<shared_ptr<T>> active_objects;
	std::list<shared_ptr<T>> inactive_objects;
};
//---Implement---//
template<typename T>
NeoObjectPool<T>::NeoObjectPool()
{
}

template<typename T>
NeoObjectPool<T>::~NeoObjectPool()
{
	Clear();
}

template<typename T>
void NeoObjectPool<T>::Clear()
{
	active_objects.clear();
	inactive_objects.clear();
}

template<typename T>
void NeoObjectPool<T>::Recycle(shared_ptr<T> object)
{
	auto it = std::find(active_objects.begin(), active_objects.end(), object);
	object->setActive(false);
	inactive_objects.splice(inactive_objects.end(),active_objects,it);
}

template<typename T>
std::shared_ptr<T> NeoObjectPool<T>::Create()
{
	if(inactive_objects.empty())
	{
		std::shared_ptr<T> obj=T::Create();
		obj->setActive(true);
		active_objects.push_back(obj);
		return obj;
	}else{
		std::shared_ptr<T> obj=inactive_objects.front();
		inactive_objects.pop_front();
		obj->setActive(true);
		obj->Reset();
		active_objects.push_back(obj);
		return obj;
	}
}
#endif /* SRC_GAME_NEOOBJECTPOOL_H_ */
