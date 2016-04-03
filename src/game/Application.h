/*
 * Application.h
 *
 *  Created on: 2016年1月12日
 *      Author: neo
 */

#ifndef SRC_GAME_APPLICATION_H_
#define SRC_GAME_APPLICATION_H_

class Application
{
public:
	static Application* getInstance()
	{
		if (_instance == NULL)
			_instance = new Application();
		return _instance;
	}

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
	static Application* _instance;
};

#endif /* SRC_GAME_APPLICATION_H_ */
