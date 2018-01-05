/*
 * SingletonMacro.h
 *
 *  Created on: 2018年1月1日
 *      Author: neo
 */

#ifndef SRC_GAME_SINGLETONMACRO_H_
#define SRC_GAME_SINGLETONMACRO_H_

#define SINGLETON_HEADER(typeName) \
	private: \
	static typeName* _instance; \
	public: \
	static typeName*getInstance(); \
	static void Destroy(); \

#define SINGLETON_SOURCE(typeName) \
	typeName* typeName::_instance = NULL; \
	typeName* typeName::getInstance(){ if (_instance == NULL){	_instance = new typeName; } \
	return _instance; } \
	void typeName::Destroy(){ if (_instance != NULL){ delete _instance; } \
	_instance = NULL; } \

#endif /* SRC_GAME_SINGLETONMACRO_H_ */
