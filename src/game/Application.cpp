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

	NeoScript::GetInstance()->Init();
	if(NeoScript::GetInstance()->ExecuteScriptFile("./script/startup.lua")<0)
	{
		exit(-1);
	}
	NeoGraphics::GetInstance()->Init();
	NeoPhysics::getInstance()->Init();

	LuaScriptModule& scrptmod(
			LuaScriptModule::create(NeoScript::GetInstance()->getLuaState()));
	System::getSingleton().setScriptingModule(&scrptmod);

	NeoGameLogic::GetInstance()->Init();
	//test
	System::getSingleton().executeScriptFile("init.lua");
}

void Application::CleanUp()
{
	NeoGameLogic::Destroy();
	NeoGraphics::Drop();
}

Application::~Application()
{

}

void Application::MainLoop()
{
	while (running)
	{
		NeoGraphics::GetInstance()->Update();
		NeoPhysics::getInstance()->Update(1.0/NeoGraphics::GetInstance()->getFps());
		NeoGameLogic::GetInstance()->Update();
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
