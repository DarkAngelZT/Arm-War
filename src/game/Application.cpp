/*
 * Application.cpp
 *
 *  Created on: 2016年1月12日
 *      Author: neo
 */
#include"stdafx.h"
#include "Application.h"
#include "NeoGameLogic.h"

Application* Application::_instance = NULL;
Application::Application()
{
	running = true;
	using namespace CEGUI;

	NeoScript::getInstance()->Init();
	if(NeoScript::getInstance()->ExecuteScriptFile("./script/startup.lua")<0)
	{
		exit(-1);
	}
	NeoGraphics::getInstance()->Init();
	NeoPhysics::getInstance()->Init();

	LuaScriptModule& scrptmod(
			LuaScriptModule::create(NeoScript::getInstance()->getLuaState()));
	System::getSingleton().setScriptingModule(&scrptmod);

	NeoGameLogic::getInstance()->Init();
	System::getSingleton().executeScriptFile("init.lua");

}

void Application::CleanUp()
{
	NeoGameLogic::Destroy();
	NeoPhysics::Destroy();
	NeoGraphics::Drop();
}

Application::~Application()
{

}

void Application::MainLoop()
{
	while (running)
	{
		NeoGraphics::getInstance()->Update();
		NeoPhysics::getInstance()->Update(NeoGraphics::getInstance()->getDeltaTime());
		NeoGameLogic::getInstance()->Update();
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
