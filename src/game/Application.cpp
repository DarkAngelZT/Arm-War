/*
 * Application.cpp
 *
 *  Created on: 2016年1月12日
 *      Author: neo
 */
#include"stdafx.h"
#include "Application.h"
#include "NeoGameLogic.h"
#include "network/Network.h"
#include "game/NeoScene.h"
#include "sound/Sound.h"

SINGLETON_SOURCE(Application)

Application::Application()
{
	running = true;
	using namespace CEGUI;

	NeoScript::getInstance()->Init();
	if (NeoScript::getInstance()->ExecuteScriptFile("./script/startup.lua") < 0)
	{
		exit(-1);
	}
	NeoGraphics::getInstance()->Init();
	NeoPhysics::getInstance()->Init();
	NeoGame::Sound::getInstance()->Init();

	LuaScriptModule& scrptmod(
			LuaScriptModule::create(NeoScript::getInstance()->getLuaState()));
	System::getSingleton().setScriptingModule(&scrptmod);

	NeoGameLogic::getInstance()->Init();
	System::getSingleton().executeScriptFile("init.lua");

}

void Application::CleanUp()
{
	NeoGame::Network::Destroy();
	NeoGameLogic::Destroy();
	NeoPhysics::Destroy();
	NeoGraphics::Drop();
	NeoGame::Sound::Destroy();
}

Application::~Application()
{

}

void Application::MainLoop()
{
	while (running)
	{
		NeoGraphics::getInstance()->Update();
		NeoPhysics::getInstance()->Update(
				NeoGraphics::getInstance()->getDeltaTime());
		NeoScene::getInstance()->Update();
		NeoGameLogic::getInstance()->Update();
		NeoGame::Network::getInstance()->Update();
	}
}

void Application::Quit()
{
	running = false;
}
int main(int argc, char*argv[])
{
	Application* neoApp = Application::getInstance();
	neoApp->MainLoop();
	neoApp->CleanUp();
	return 0;
}
