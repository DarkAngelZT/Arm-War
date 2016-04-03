/*
 * stdafx.h
 *
 *  Created on: 2016年1月12日
 *      Author: neo
 */

#ifndef SRC_GAME_STDAFX_H_
#define SRC_GAME_STDAFX_H_

#include<memory>
#include<irrlicht.h>
#include <btBulletDynamicsCommon.h>
#include "CEGUI/CEGUI.h"
#include "CEGUI/RendererModules/Irrlicht/Renderer.h"
#include "CEGUI/ScriptModules/Lua/ScriptModule.h"
// include Lua libs and tolua++
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "tolua++.h"

#include "Application.h"
#include "../graphics/NeoGraphics.h"
#include "../script/NeoScript.h"
#include "../physics/NeoPhysics.h"

#ifdef DEBUG
#include <iostream>
#endif

#endif /* SRC_GAME_STDAFX_H_ */
