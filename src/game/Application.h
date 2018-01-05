/*
 * Application.h
 *
 *  Created on: 2016年1月12日
 *      Author: neo
 */

#ifndef SRC_GAME_APPLICATION_H_
#define SRC_GAME_APPLICATION_H_

#include "SingletonMacro.h"

class Application
{
SINGLETON_HEADER(Application)
public:

	bool isRunning() const
	{
		return running;
	}
	void MainLoop();
	void CleanUp();
	void Quit();
private:
	Application();
	~Application();
private:
	bool running = false;
};

#endif /* SRC_GAME_APPLICATION_H_ */
