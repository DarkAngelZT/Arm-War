/*
** Lua binding: NeoGame
** Generated automatically by tolua++-1.0.93 on Fri Feb 12 19:22:47 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_NeoGame_open (lua_State* tolua_S);

#include "required.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_irr__SKeyMap (lua_State* tolua_S)
{
 irr::SKeyMap* self = (irr::SKeyMap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__video__SColor (lua_State* tolua_S)
{
 irr::video::SColor* self = (irr::video::SColor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__video__SColorHSL (lua_State* tolua_S)
{
 irr::video::SColorHSL* self = (irr::video::SColorHSL*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__core__vector2d_int_ (lua_State* tolua_S)
{
 irr::core::vector2d<int>* self = (irr::core::vector2d<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__core__vector3d_float_ (lua_State* tolua_S)
{
 irr::core::vector3d<float>* self = (irr::core::vector3d<float>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__core__vector3d_int_ (lua_State* tolua_S)
{
 irr::core::vector3d<int>* self = (irr::core::vector3d<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__core__vector3df (lua_State* tolua_S)
{
 irr::core::vector3df* self = (irr::core::vector3df*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__core__dimension2d_int_ (lua_State* tolua_S)
{
 irr::core::dimension2d<int>* self = (irr::core::dimension2d<int>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__core__dimension2d_float_ (lua_State* tolua_S)
{
 irr::core::dimension2d<float>* self = (irr::core::dimension2d<float>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__video__SColorf (lua_State* tolua_S)
{
 irr::video::SColorf* self = (irr::video::SColorf*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_irr__core__vector2d_float_ (lua_State* tolua_S)
{
 irr::core::vector2d<float>* self = (irr::core::vector2d<float>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NeoEvent");
 tolua_usertype(tolua_S,"irr::SKeyMap");
 tolua_usertype(tolua_S,"irr::video::SColor");
 tolua_usertype(tolua_S,"irr::core::vector2d<int>");
 tolua_usertype(tolua_S,"irr::core::vector3df");
 tolua_usertype(tolua_S,"irr::core::dimension2d<float>");
 tolua_usertype(tolua_S,"irr::video::SColorHSL");
 tolua_usertype(tolua_S,"irr::video::SColorf");
 tolua_usertype(tolua_S,"irr::core::vector2d<float>");
 tolua_usertype(tolua_S,"Application");
 tolua_usertype(tolua_S,"irr::core::dimension2d<int>");
 tolua_usertype(tolua_S,"NeoGraphics");
 tolua_usertype(tolua_S,"irr::core::vector3d<float>");
 tolua_usertype(tolua_S,"irr::core::vector3d<int>");
 tolua_usertype(tolua_S,"GameObject");
 tolua_usertype(tolua_S,"NeoTrigger");
 tolua_usertype(tolua_S,"NeoGameLogic");
}

/* method: getInstance of class  Application */
#ifndef TOLUA_DISABLE_tolua_NeoGame_Application_getInstance00
static int tolua_NeoGame_Application_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Application",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Application* tolua_ret = (Application*)  Application::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Application");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isRunning of class  Application */
#ifndef TOLUA_DISABLE_tolua_NeoGame_Application_isRunning00
static int tolua_NeoGame_Application_isRunning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Application",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Application* self = (const Application*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isRunning'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isRunning();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isRunning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Quit of class  Application */
#ifndef TOLUA_DISABLE_tolua_NeoGame_Application_Quit00
static int tolua_NeoGame_Application_Quit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Application",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Application* self = (Application*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Quit'", NULL);
#endif
  {
   self->Quit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Quit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_new00
static int tolua_NeoGame_irr_core_vector3di_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::vector3d<int>* tolua_ret = (irr::core::vector3d<int>*)  Mtolua_new((irr::core::vector3d<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_new00_local
static int tolua_NeoGame_irr_core_vector3di_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::vector3d<int>* tolua_ret = (irr::core::vector3d<int>*)  Mtolua_new((irr::core::vector3d<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_new01
static int tolua_NeoGame_irr_core_vector3di_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int nx = ((int)  tolua_tonumber(tolua_S,2,0));
  int ny = ((int)  tolua_tonumber(tolua_S,3,0));
  int nz = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   irr::core::vector3d<int>* tolua_ret = (irr::core::vector3d<int>*)  Mtolua_new((irr::core::vector3d<int>)(nx,ny,nz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_new01_local
static int tolua_NeoGame_irr_core_vector3di_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int nx = ((int)  tolua_tonumber(tolua_S,2,0));
  int ny = ((int)  tolua_tonumber(tolua_S,3,0));
  int nz = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   irr::core::vector3d<int>* tolua_ret = (irr::core::vector3d<int>*)  Mtolua_new((irr::core::vector3d<int>)(nx,ny,nz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_new02
static int tolua_NeoGame_irr_core_vector3di_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   irr::core::vector3d<int>* tolua_ret = (irr::core::vector3d<int>*)  Mtolua_new((irr::core::vector3d<int>)(n));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_new02_local
static int tolua_NeoGame_irr_core_vector3di_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   irr::core::vector3d<int>* tolua_ret = (irr::core::vector3d<int>*)  Mtolua_new((irr::core::vector3d<int>)(n));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_new03
static int tolua_NeoGame_irr_core_vector3di_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector3d<int>* tolua_ret = (irr::core::vector3d<int>*)  Mtolua_new((irr::core::vector3d<int>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_new03_local
static int tolua_NeoGame_irr_core_vector3di_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector3d<int>* tolua_ret = (irr::core::vector3d<int>*)  Mtolua_new((irr::core::vector3d<int>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__sub00
static int tolua_NeoGame_irr_core_vector3di__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__add00
static int tolua_NeoGame_irr_core_vector3di__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__add01
static int tolua_NeoGame_irr_core_vector3di__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int val = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator+(val);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__sub01
static int tolua_NeoGame_irr_core_vector3di__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator-(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__sub02
static int tolua_NeoGame_irr_core_vector3di__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int val = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator-(val);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__mul00
static int tolua_NeoGame_irr_core_vector3di__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator*(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__mul01
static int tolua_NeoGame_irr_core_vector3di__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int v = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator*(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__div00
static int tolua_NeoGame_irr_core_vector3di__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator/(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__div01
static int tolua_NeoGame_irr_core_vector3di__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int v = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->operator/(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator<= of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__le00
static int tolua_NeoGame_irr_core_vector3di__le00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<=(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.le'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator< of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__lt00
static int tolua_NeoGame_irr_core_vector3di__lt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.lt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di__eq00
static int tolua_NeoGame_irr_core_vector3di__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_equals00
static int tolua_NeoGame_irr_core_vector3di_equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_equals01
static int tolua_NeoGame_irr_core_vector3di_equals01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
  const int tolerance = ((const int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*other,tolerance);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_equals00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_set00
static int tolua_NeoGame_irr_core_vector3di_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int nx = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int ny = ((const int)  tolua_tonumber(tolua_S,3,0));
  const int nz = ((const int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::vector3d<int>& tolua_ret = (irr::core::vector3d<int>&)  self->set(nx,ny,nz);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_set01
static int tolua_NeoGame_irr_core_vector3di_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* p = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::vector3d<int>& tolua_ret = (irr::core::vector3d<int>&)  self->set(*p);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLength of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getLength00
static int tolua_NeoGame_irr_core_vector3di_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLengthSQ of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getLengthSQ00
static int tolua_NeoGame_irr_core_vector3di_getLengthSQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLengthSQ'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLengthSQ();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLengthSQ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dotProduct of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_dotProduct00
static int tolua_NeoGame_irr_core_vector3di_dotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dotProduct'", NULL);
#endif
  {
   int tolua_ret = (int)  self->dotProduct(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistanceFrom of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getDistanceFrom00
static int tolua_NeoGame_irr_core_vector3di_getDistanceFrom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistanceFrom'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDistanceFrom(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistanceFrom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistanceFromSQ of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getDistanceFromSQ00
static int tolua_NeoGame_irr_core_vector3di_getDistanceFromSQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistanceFromSQ'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDistanceFromSQ(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistanceFromSQ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: crossProduct of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_crossProduct00
static int tolua_NeoGame_irr_core_vector3di_crossProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* p = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'crossProduct'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->crossProduct(*p);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'crossProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isBetweenPoints of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_isBetweenPoints00
static int tolua_NeoGame_irr_core_vector3di_isBetweenPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* begin = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector3d<int>* end = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isBetweenPoints'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isBetweenPoints(*begin,*end);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isBetweenPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_normalize00
static int tolua_NeoGame_irr_core_vector3di_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   irr::core::vector3d<int>& tolua_ret = (irr::core::vector3d<int>&)  self->normalize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLength of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_setLength00
static int tolua_NeoGame_irr_core_vector3di_setLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  int newlength = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLength'", NULL);
#endif
  {
   irr::core::vector3d<int>& tolua_ret = (irr::core::vector3d<int>&)  self->setLength(newlength);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: invert of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_invert00
static int tolua_NeoGame_irr_core_vector3di_invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'invert'", NULL);
#endif
  {
   irr::core::vector3d<int>& tolua_ret = (irr::core::vector3d<int>&)  self->invert();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'invert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateXZBy of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_rotateXZBy00
static int tolua_NeoGame_irr_core_vector3di_rotateXZBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateXZBy'", NULL);
#endif
  {
   self->rotateXZBy(degrees);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateXZBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateXZBy of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_rotateXZBy01
static int tolua_NeoGame_irr_core_vector3di_rotateXZBy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3d<int>* center = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateXZBy'", NULL);
#endif
  {
   self->rotateXZBy(degrees,*center);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_rotateXZBy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateXYBy of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_rotateXYBy00
static int tolua_NeoGame_irr_core_vector3di_rotateXYBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateXYBy'", NULL);
#endif
  {
   self->rotateXYBy(degrees);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateXYBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateXYBy of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_rotateXYBy01
static int tolua_NeoGame_irr_core_vector3di_rotateXYBy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3d<int>* center = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateXYBy'", NULL);
#endif
  {
   self->rotateXYBy(degrees,*center);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_rotateXYBy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateYZBy of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_rotateYZBy00
static int tolua_NeoGame_irr_core_vector3di_rotateYZBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateYZBy'", NULL);
#endif
  {
   self->rotateYZBy(degrees);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateYZBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateYZBy of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_rotateYZBy01
static int tolua_NeoGame_irr_core_vector3di_rotateYZBy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3d<int>* center = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateYZBy'", NULL);
#endif
  {
   self->rotateYZBy(degrees,*center);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_rotateYZBy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getInterpolated00
static int tolua_NeoGame_irr_core_vector3di_getInterpolated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* other = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
  double d = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->getInterpolated(*other,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated_quadratic of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getInterpolated_quadratic00
static int tolua_NeoGame_irr_core_vector3di_getInterpolated_quadratic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* v2 = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector3d<int>* v3 = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,3,0));
  double d = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated_quadratic'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->getInterpolated_quadratic(*v2,*v3,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated_quadratic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: interpolate of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_interpolate00
static int tolua_NeoGame_irr_core_vector3di_interpolate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* a = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector3d<int>* b = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,3,0));
  double d = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'interpolate'", NULL);
#endif
  {
   irr::core::vector3d<int>& tolua_ret = (irr::core::vector3d<int>&)  self->interpolate(*a,*b,d);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'interpolate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHorizontalAngle of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getHorizontalAngle00
static int tolua_NeoGame_irr_core_vector3di_getHorizontalAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHorizontalAngle'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->getHorizontalAngle();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHorizontalAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSphericalCoordinateAngles of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getSphericalCoordinateAngles00
static int tolua_NeoGame_irr_core_vector3di_getSphericalCoordinateAngles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSphericalCoordinateAngles'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->getSphericalCoordinateAngles();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSphericalCoordinateAngles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotationToDirection of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_rotationToDirection00
static int tolua_NeoGame_irr_core_vector3di_rotationToDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotationToDirection'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->rotationToDirection();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotationToDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotationToDirection of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_rotationToDirection01
static int tolua_NeoGame_irr_core_vector3di_rotationToDirection01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<int>* forwards = ((const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotationToDirection'", NULL);
#endif
  {
   irr::core::vector3d<int> tolua_ret = (irr::core::vector3d<int>)  self->rotationToDirection(*forwards);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3di_rotationToDirection00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAs4Values of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getAs4Values00
static int tolua_NeoGame_irr_core_vector3di_getAs4Values00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  int array = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAs4Values'", NULL);
#endif
  {
   self->getAs4Values(&array);
   tolua_pushnumber(tolua_S,(lua_Number)array);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAs4Values'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAs3Values of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3di_getAs3Values00
static int tolua_NeoGame_irr_core_vector3di_getAs3Values00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<int>* self = (const irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
  int array = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAs3Values'", NULL);
#endif
  {
   self->getAs3Values(&array);
   tolua_pushnumber(tolua_S,(lua_Number)array);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAs3Values'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: X of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector3d_int__X
static int tolua_get_irr__core__vector3d_int__X(lua_State* tolua_S)
{
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: X of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector3d_int__X
static int tolua_set_irr__core__vector3d_int__X(lua_State* tolua_S)
{
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->X = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Y of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector3d_int__Y
static int tolua_get_irr__core__vector3d_int__Y(lua_State* tolua_S)
{
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Y of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector3d_int__Y
static int tolua_set_irr__core__vector3d_int__Y(lua_State* tolua_S)
{
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Z of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector3d_int__Z
static int tolua_get_irr__core__vector3d_int__Z(lua_State* tolua_S)
{
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Z of class  irr::core::vector3d<int> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector3d_int__Z
static int tolua_set_irr__core__vector3d_int__Z(lua_State* tolua_S)
{
  irr::core::vector3d<int>* self = (irr::core::vector3d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Z = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_new00
static int tolua_NeoGame_irr_core_vector3df_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::vector3d<float>* tolua_ret = (irr::core::vector3d<float>*)  Mtolua_new((irr::core::vector3d<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_new00_local
static int tolua_NeoGame_irr_core_vector3df_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::vector3d<float>* tolua_ret = (irr::core::vector3d<float>*)  Mtolua_new((irr::core::vector3d<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_new01
static int tolua_NeoGame_irr_core_vector3df_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float nx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ny = ((float)  tolua_tonumber(tolua_S,3,0));
  float nz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   irr::core::vector3d<float>* tolua_ret = (irr::core::vector3d<float>*)  Mtolua_new((irr::core::vector3d<float>)(nx,ny,nz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_new01_local
static int tolua_NeoGame_irr_core_vector3df_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float nx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ny = ((float)  tolua_tonumber(tolua_S,3,0));
  float nz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   irr::core::vector3d<float>* tolua_ret = (irr::core::vector3d<float>*)  Mtolua_new((irr::core::vector3d<float>)(nx,ny,nz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_new02
static int tolua_NeoGame_irr_core_vector3df_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float n = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   irr::core::vector3d<float>* tolua_ret = (irr::core::vector3d<float>*)  Mtolua_new((irr::core::vector3d<float>)(n));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_new02_local
static int tolua_NeoGame_irr_core_vector3df_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float n = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   irr::core::vector3d<float>* tolua_ret = (irr::core::vector3d<float>*)  Mtolua_new((irr::core::vector3d<float>)(n));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_new03
static int tolua_NeoGame_irr_core_vector3df_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector3d<float>* tolua_ret = (irr::core::vector3d<float>*)  Mtolua_new((irr::core::vector3d<float>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_new03_local
static int tolua_NeoGame_irr_core_vector3df_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector3d<float>* tolua_ret = (irr::core::vector3d<float>*)  Mtolua_new((irr::core::vector3d<float>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__sub00
static int tolua_NeoGame_irr_core_vector3df__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__add00
static int tolua_NeoGame_irr_core_vector3df__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__add01
static int tolua_NeoGame_irr_core_vector3df__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float val = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator+(val);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__sub01
static int tolua_NeoGame_irr_core_vector3df__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator-(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__sub02
static int tolua_NeoGame_irr_core_vector3df__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float val = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator-(val);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__mul00
static int tolua_NeoGame_irr_core_vector3df__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator*(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__mul01
static int tolua_NeoGame_irr_core_vector3df__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float v = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator*(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__div00
static int tolua_NeoGame_irr_core_vector3df__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator/(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__div01
static int tolua_NeoGame_irr_core_vector3df__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float v = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->operator/(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator<= of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__le00
static int tolua_NeoGame_irr_core_vector3df__le00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<=(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.le'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator< of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__lt00
static int tolua_NeoGame_irr_core_vector3df__lt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.lt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df__eq00
static int tolua_NeoGame_irr_core_vector3df__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_equals00
static int tolua_NeoGame_irr_core_vector3df_equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_equals01
static int tolua_NeoGame_irr_core_vector3df_equals01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
  const float tolerance = ((const float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*other,tolerance);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_equals00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_set00
static int tolua_NeoGame_irr_core_vector3df_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float nx = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float ny = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float nz = ((const float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::vector3d<float>& tolua_ret = (irr::core::vector3d<float>&)  self->set(nx,ny,nz);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_set01
static int tolua_NeoGame_irr_core_vector3df_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* p = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::vector3d<float>& tolua_ret = (irr::core::vector3d<float>&)  self->set(*p);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLength of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getLength00
static int tolua_NeoGame_irr_core_vector3df_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLengthSQ of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getLengthSQ00
static int tolua_NeoGame_irr_core_vector3df_getLengthSQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLengthSQ'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLengthSQ();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLengthSQ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dotProduct of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_dotProduct00
static int tolua_NeoGame_irr_core_vector3df_dotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dotProduct'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dotProduct(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistanceFrom of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getDistanceFrom00
static int tolua_NeoGame_irr_core_vector3df_getDistanceFrom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistanceFrom'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDistanceFrom(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistanceFrom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistanceFromSQ of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getDistanceFromSQ00
static int tolua_NeoGame_irr_core_vector3df_getDistanceFromSQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistanceFromSQ'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDistanceFromSQ(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistanceFromSQ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: crossProduct of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_crossProduct00
static int tolua_NeoGame_irr_core_vector3df_crossProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* p = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'crossProduct'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->crossProduct(*p);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'crossProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isBetweenPoints of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_isBetweenPoints00
static int tolua_NeoGame_irr_core_vector3df_isBetweenPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* begin = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector3d<float>* end = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isBetweenPoints'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isBetweenPoints(*begin,*end);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isBetweenPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_normalize00
static int tolua_NeoGame_irr_core_vector3df_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   irr::core::vector3d<float>& tolua_ret = (irr::core::vector3d<float>&)  self->normalize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLength of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_setLength00
static int tolua_NeoGame_irr_core_vector3df_setLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  float newlength = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLength'", NULL);
#endif
  {
   irr::core::vector3d<float>& tolua_ret = (irr::core::vector3d<float>&)  self->setLength(newlength);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: invert of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_invert00
static int tolua_NeoGame_irr_core_vector3df_invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'invert'", NULL);
#endif
  {
   irr::core::vector3d<float>& tolua_ret = (irr::core::vector3d<float>&)  self->invert();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'invert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateXZBy of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_rotateXZBy00
static int tolua_NeoGame_irr_core_vector3df_rotateXZBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateXZBy'", NULL);
#endif
  {
   self->rotateXZBy(degrees);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateXZBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateXZBy of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_rotateXZBy01
static int tolua_NeoGame_irr_core_vector3df_rotateXZBy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3d<float>* center = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateXZBy'", NULL);
#endif
  {
   self->rotateXZBy(degrees,*center);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_rotateXZBy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateXYBy of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_rotateXYBy00
static int tolua_NeoGame_irr_core_vector3df_rotateXYBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateXYBy'", NULL);
#endif
  {
   self->rotateXYBy(degrees);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateXYBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateXYBy of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_rotateXYBy01
static int tolua_NeoGame_irr_core_vector3df_rotateXYBy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3d<float>* center = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateXYBy'", NULL);
#endif
  {
   self->rotateXYBy(degrees,*center);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_rotateXYBy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateYZBy of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_rotateYZBy00
static int tolua_NeoGame_irr_core_vector3df_rotateYZBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateYZBy'", NULL);
#endif
  {
   self->rotateYZBy(degrees);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateYZBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateYZBy of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_rotateYZBy01
static int tolua_NeoGame_irr_core_vector3df_rotateYZBy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3d<float>* center = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateYZBy'", NULL);
#endif
  {
   self->rotateYZBy(degrees,*center);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_rotateYZBy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getInterpolated00
static int tolua_NeoGame_irr_core_vector3df_getInterpolated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* other = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
  double d = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->getInterpolated(*other,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated_quadratic of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getInterpolated_quadratic00
static int tolua_NeoGame_irr_core_vector3df_getInterpolated_quadratic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* v2 = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector3d<float>* v3 = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,3,0));
  double d = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated_quadratic'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->getInterpolated_quadratic(*v2,*v3,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated_quadratic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: interpolate of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_interpolate00
static int tolua_NeoGame_irr_core_vector3df_interpolate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* a = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector3d<float>* b = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,3,0));
  double d = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'interpolate'", NULL);
#endif
  {
   irr::core::vector3d<float>& tolua_ret = (irr::core::vector3d<float>&)  self->interpolate(*a,*b,d);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector3d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'interpolate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHorizontalAngle of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getHorizontalAngle00
static int tolua_NeoGame_irr_core_vector3df_getHorizontalAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHorizontalAngle'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->getHorizontalAngle();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHorizontalAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSphericalCoordinateAngles of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getSphericalCoordinateAngles00
static int tolua_NeoGame_irr_core_vector3df_getSphericalCoordinateAngles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSphericalCoordinateAngles'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->getSphericalCoordinateAngles();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSphericalCoordinateAngles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotationToDirection of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_rotationToDirection00
static int tolua_NeoGame_irr_core_vector3df_rotationToDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotationToDirection'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->rotationToDirection();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotationToDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotationToDirection of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_rotationToDirection01
static int tolua_NeoGame_irr_core_vector3df_rotationToDirection01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector3d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector3d<float>* forwards = ((const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotationToDirection'", NULL);
#endif
  {
   irr::core::vector3d<float> tolua_ret = (irr::core::vector3d<float>)  self->rotationToDirection(*forwards);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector3df_rotationToDirection00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAs4Values of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getAs4Values00
static int tolua_NeoGame_irr_core_vector3df_getAs4Values00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  float array = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAs4Values'", NULL);
#endif
  {
   self->getAs4Values(&array);
   tolua_pushnumber(tolua_S,(lua_Number)array);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAs4Values'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAs3Values of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector3df_getAs3Values00
static int tolua_NeoGame_irr_core_vector3df_getAs3Values00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector3d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector3d<float>* self = (const irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
  float array = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAs3Values'", NULL);
#endif
  {
   self->getAs3Values(&array);
   tolua_pushnumber(tolua_S,(lua_Number)array);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAs3Values'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: X of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector3d_float__X
static int tolua_get_irr__core__vector3d_float__X(lua_State* tolua_S)
{
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: X of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector3d_float__X
static int tolua_set_irr__core__vector3d_float__X(lua_State* tolua_S)
{
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->X = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Y of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector3d_float__Y
static int tolua_get_irr__core__vector3d_float__Y(lua_State* tolua_S)
{
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Y of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector3d_float__Y
static int tolua_set_irr__core__vector3d_float__Y(lua_State* tolua_S)
{
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Z of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector3d_float__Z
static int tolua_get_irr__core__vector3d_float__Z(lua_State* tolua_S)
{
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Z of class  irr::core::vector3d<float> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector3d_float__Z
static int tolua_set_irr__core__vector3d_float__Z(lua_State* tolua_S)
{
  irr::core::vector3d<float>* self = (irr::core::vector3d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new00
static int tolua_NeoGame_irr_core_vector2di_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new00_local
static int tolua_NeoGame_irr_core_vector2di_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new01
static int tolua_NeoGame_irr_core_vector2di_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int nx = ((int)  tolua_tonumber(tolua_S,2,0));
  int ny = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)(nx,ny));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new01_local
static int tolua_NeoGame_irr_core_vector2di_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int nx = ((int)  tolua_tonumber(tolua_S,2,0));
  int ny = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)(nx,ny));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new02
static int tolua_NeoGame_irr_core_vector2di_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)(n));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new02_local
static int tolua_NeoGame_irr_core_vector2di_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)(n));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new03
static int tolua_NeoGame_irr_core_vector2di_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new03_local
static int tolua_NeoGame_irr_core_vector2di_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new04
static int tolua_NeoGame_irr_core_vector2di_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::dimension2d<int>* other = ((const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_new04_local
static int tolua_NeoGame_irr_core_vector2di_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::dimension2d<int>* other = ((const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector2d<int>* tolua_ret = (irr::core::vector2d<int>*)  Mtolua_new((irr::core::vector2d<int>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__sub00
static int tolua_NeoGame_irr_core_vector2di__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__add00
static int tolua_NeoGame_irr_core_vector2di__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__add01
static int tolua_NeoGame_irr_core_vector2di__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<int>* other = ((const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__add02
static int tolua_NeoGame_irr_core_vector2di__add02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int v = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator+(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di__add01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__sub01
static int tolua_NeoGame_irr_core_vector2di__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator-(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__sub02
static int tolua_NeoGame_irr_core_vector2di__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<int>* other = ((const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator-(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__sub03
static int tolua_NeoGame_irr_core_vector2di__sub03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int v = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator-(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di__sub02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__mul00
static int tolua_NeoGame_irr_core_vector2di__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator*(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__mul01
static int tolua_NeoGame_irr_core_vector2di__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int v = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator*(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__div00
static int tolua_NeoGame_irr_core_vector2di__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator/(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__div01
static int tolua_NeoGame_irr_core_vector2di__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int v = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->operator/(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator<= of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__le00
static int tolua_NeoGame_irr_core_vector2di__le00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<=(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.le'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator< of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__lt00
static int tolua_NeoGame_irr_core_vector2di__lt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.lt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di__eq00
static int tolua_NeoGame_irr_core_vector2di__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_equals00
static int tolua_NeoGame_irr_core_vector2di_equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_set00
static int tolua_NeoGame_irr_core_vector2di_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  int nx = ((int)  tolua_tonumber(tolua_S,2,0));
  int ny = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::vector2d<int>& tolua_ret = (irr::core::vector2d<int>&)  self->set(nx,ny);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_set01
static int tolua_NeoGame_irr_core_vector2di_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* p = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::vector2d<int>& tolua_ret = (irr::core::vector2d<int>&)  self->set(*p);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLength of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getLength00
static int tolua_NeoGame_irr_core_vector2di_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLengthSQ of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getLengthSQ00
static int tolua_NeoGame_irr_core_vector2di_getLengthSQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLengthSQ'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLengthSQ();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLengthSQ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dotProduct of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_dotProduct00
static int tolua_NeoGame_irr_core_vector2di_dotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dotProduct'", NULL);
#endif
  {
   int tolua_ret = (int)  self->dotProduct(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistanceFrom of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getDistanceFrom00
static int tolua_NeoGame_irr_core_vector2di_getDistanceFrom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistanceFrom'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDistanceFrom(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistanceFrom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistanceFromSQ of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getDistanceFromSQ00
static int tolua_NeoGame_irr_core_vector2di_getDistanceFromSQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistanceFromSQ'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDistanceFromSQ(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistanceFromSQ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateBy of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_rotateBy00
static int tolua_NeoGame_irr_core_vector2di_rotateBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateBy'", NULL);
#endif
  {
   irr::core::vector2d<int>& tolua_ret = (irr::core::vector2d<int>&)  self->rotateBy(degrees);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateBy of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_rotateBy01
static int tolua_NeoGame_irr_core_vector2di_rotateBy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector2d<int>* center = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateBy'", NULL);
#endif
  {
   irr::core::vector2d<int>& tolua_ret = (irr::core::vector2d<int>&)  self->rotateBy(degrees,*center);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2di_rotateBy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_normalize00
static int tolua_NeoGame_irr_core_vector2di_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   irr::core::vector2d<int>& tolua_ret = (irr::core::vector2d<int>&)  self->normalize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAngleTrig of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getAngleTrig00
static int tolua_NeoGame_irr_core_vector2di_getAngleTrig00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAngleTrig'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getAngleTrig();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAngleTrig'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAngle of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getAngle00
static int tolua_NeoGame_irr_core_vector2di_getAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAngle'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getAngle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAngleWith of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getAngleWith00
static int tolua_NeoGame_irr_core_vector2di_getAngleWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* b = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAngleWith'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getAngleWith(*b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAngleWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isBetweenPoints of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_isBetweenPoints00
static int tolua_NeoGame_irr_core_vector2di_isBetweenPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* begin = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector2d<int>* end = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isBetweenPoints'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isBetweenPoints(*begin,*end);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isBetweenPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getInterpolated00
static int tolua_NeoGame_irr_core_vector2di_getInterpolated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
  double d = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->getInterpolated(*other,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated_quadratic of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_getInterpolated_quadratic00
static int tolua_NeoGame_irr_core_vector2di_getInterpolated_quadratic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<int>* self = (const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* v2 = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector2d<int>* v3 = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,3,0));
  double d = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated_quadratic'", NULL);
#endif
  {
   irr::core::vector2d<int> tolua_ret = (irr::core::vector2d<int>)  self->getInterpolated_quadratic(*v2,*v3,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated_quadratic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: interpolate of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2di_interpolate00
static int tolua_NeoGame_irr_core_vector2di_interpolate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* a = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector2d<int>* b = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,3,0));
  double d = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'interpolate'", NULL);
#endif
  {
   irr::core::vector2d<int>& tolua_ret = (irr::core::vector2d<int>&)  self->interpolate(*a,*b,d);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'interpolate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: X of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector2d_int__X
static int tolua_get_irr__core__vector2d_int__X(lua_State* tolua_S)
{
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: X of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector2d_int__X
static int tolua_set_irr__core__vector2d_int__X(lua_State* tolua_S)
{
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->X = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Y of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector2d_int__Y
static int tolua_get_irr__core__vector2d_int__Y(lua_State* tolua_S)
{
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Y of class  irr::core::vector2d<int> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector2d_int__Y
static int tolua_set_irr__core__vector2d_int__Y(lua_State* tolua_S)
{
  irr::core::vector2d<int>* self = (irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new00
static int tolua_NeoGame_irr_core_vector2df_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new00_local
static int tolua_NeoGame_irr_core_vector2df_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new01
static int tolua_NeoGame_irr_core_vector2df_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float nx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ny = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)(nx,ny));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new01_local
static int tolua_NeoGame_irr_core_vector2df_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float nx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ny = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)(nx,ny));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new02
static int tolua_NeoGame_irr_core_vector2df_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float n = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)(n));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new02_local
static int tolua_NeoGame_irr_core_vector2df_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float n = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)(n));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new03
static int tolua_NeoGame_irr_core_vector2df_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new03_local
static int tolua_NeoGame_irr_core_vector2df_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new04
static int tolua_NeoGame_irr_core_vector2df_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::dimension2d<float>* other = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_new04_local
static int tolua_NeoGame_irr_core_vector2df_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::dimension2d<float>* other = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::vector2d<float>* tolua_ret = (irr::core::vector2d<float>*)  Mtolua_new((irr::core::vector2d<float>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__sub00
static int tolua_NeoGame_irr_core_vector2df__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__add00
static int tolua_NeoGame_irr_core_vector2df__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__add01
static int tolua_NeoGame_irr_core_vector2df__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<float>* other = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__add02
static int tolua_NeoGame_irr_core_vector2df__add02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float v = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator+(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df__add01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__sub01
static int tolua_NeoGame_irr_core_vector2df__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator-(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__sub02
static int tolua_NeoGame_irr_core_vector2df__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<float>* other = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator-(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__sub03
static int tolua_NeoGame_irr_core_vector2df__sub03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float v = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator-(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df__sub02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__mul00
static int tolua_NeoGame_irr_core_vector2df__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator*(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__mul01
static int tolua_NeoGame_irr_core_vector2df__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float v = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator*(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__div00
static int tolua_NeoGame_irr_core_vector2df__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator/(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__div01
static int tolua_NeoGame_irr_core_vector2df__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float v = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->operator/(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator<= of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__le00
static int tolua_NeoGame_irr_core_vector2df__le00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<=(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.le'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator< of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__lt00
static int tolua_NeoGame_irr_core_vector2df__lt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.lt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df__eq00
static int tolua_NeoGame_irr_core_vector2df__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_equals00
static int tolua_NeoGame_irr_core_vector2df_equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_set00
static int tolua_NeoGame_irr_core_vector2df_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  float nx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ny = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::vector2d<float>& tolua_ret = (irr::core::vector2d<float>&)  self->set(nx,ny);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_set01
static int tolua_NeoGame_irr_core_vector2df_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* p = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::vector2d<float>& tolua_ret = (irr::core::vector2d<float>&)  self->set(*p);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLength of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getLength00
static int tolua_NeoGame_irr_core_vector2df_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLengthSQ of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getLengthSQ00
static int tolua_NeoGame_irr_core_vector2df_getLengthSQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLengthSQ'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLengthSQ();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLengthSQ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dotProduct of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_dotProduct00
static int tolua_NeoGame_irr_core_vector2df_dotProduct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dotProduct'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dotProduct(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dotProduct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistanceFrom of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getDistanceFrom00
static int tolua_NeoGame_irr_core_vector2df_getDistanceFrom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistanceFrom'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDistanceFrom(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistanceFrom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDistanceFromSQ of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getDistanceFromSQ00
static int tolua_NeoGame_irr_core_vector2df_getDistanceFromSQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDistanceFromSQ'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDistanceFromSQ(*other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDistanceFromSQ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateBy of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_rotateBy00
static int tolua_NeoGame_irr_core_vector2df_rotateBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateBy'", NULL);
#endif
  {
   irr::core::vector2d<float>& tolua_ret = (irr::core::vector2d<float>&)  self->rotateBy(degrees);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateBy of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_rotateBy01
static int tolua_NeoGame_irr_core_vector2df_rotateBy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  double degrees = ((double)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector2d<float>* center = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateBy'", NULL);
#endif
  {
   irr::core::vector2d<float>& tolua_ret = (irr::core::vector2d<float>&)  self->rotateBy(degrees,*center);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_vector2df_rotateBy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_normalize00
static int tolua_NeoGame_irr_core_vector2df_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   irr::core::vector2d<float>& tolua_ret = (irr::core::vector2d<float>&)  self->normalize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAngleTrig of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getAngleTrig00
static int tolua_NeoGame_irr_core_vector2df_getAngleTrig00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAngleTrig'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getAngleTrig();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAngleTrig'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAngle of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getAngle00
static int tolua_NeoGame_irr_core_vector2df_getAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAngle'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getAngle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAngleWith of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getAngleWith00
static int tolua_NeoGame_irr_core_vector2df_getAngleWith00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* b = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAngleWith'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getAngleWith(*b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAngleWith'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isBetweenPoints of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_isBetweenPoints00
static int tolua_NeoGame_irr_core_vector2df_isBetweenPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* begin = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector2d<float>* end = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isBetweenPoints'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isBetweenPoints(*begin,*end);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isBetweenPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getInterpolated00
static int tolua_NeoGame_irr_core_vector2df_getInterpolated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
  double d = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->getInterpolated(*other,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated_quadratic of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_getInterpolated_quadratic00
static int tolua_NeoGame_irr_core_vector2df_getInterpolated_quadratic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::vector2d<float>* self = (const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* v2 = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector2d<float>* v3 = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,3,0));
  double d = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated_quadratic'", NULL);
#endif
  {
   irr::core::vector2d<float> tolua_ret = (irr::core::vector2d<float>)  self->getInterpolated_quadratic(*v2,*v3,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated_quadratic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: interpolate of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_vector2df_interpolate00
static int tolua_NeoGame_irr_core_vector2df_interpolate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::vector2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* a = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
  const irr::core::vector2d<float>* b = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,3,0));
  double d = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'interpolate'", NULL);
#endif
  {
   irr::core::vector2d<float>& tolua_ret = (irr::core::vector2d<float>&)  self->interpolate(*a,*b,d);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::vector2d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'interpolate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: X of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector2d_float__X
static int tolua_get_irr__core__vector2d_float__X(lua_State* tolua_S)
{
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: X of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector2d_float__X
static int tolua_set_irr__core__vector2d_float__X(lua_State* tolua_S)
{
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->X = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Y of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__vector2d_float__Y
static int tolua_get_irr__core__vector2d_float__Y(lua_State* tolua_S)
{
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Y of class  irr::core::vector2d<float> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__vector2d_float__Y
static int tolua_set_irr__core__vector2d_float__Y(lua_State* tolua_S)
{
  irr::core::vector2d<float>* self = (irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_new00
static int tolua_NeoGame_irr_core_dimension2di_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::dimension2d<int>* tolua_ret = (irr::core::dimension2d<int>*)  Mtolua_new((irr::core::dimension2d<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_new00_local
static int tolua_NeoGame_irr_core_dimension2di_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::dimension2d<int>* tolua_ret = (irr::core::dimension2d<int>*)  Mtolua_new((irr::core::dimension2d<int>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_new01
static int tolua_NeoGame_irr_core_dimension2di_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const int width = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int height = ((const int)  tolua_tonumber(tolua_S,3,0));
  {
   irr::core::dimension2d<int>* tolua_ret = (irr::core::dimension2d<int>*)  Mtolua_new((irr::core::dimension2d<int>)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<int>");
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 3;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2di_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_new01_local
static int tolua_NeoGame_irr_core_dimension2di_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const int width = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int height = ((const int)  tolua_tonumber(tolua_S,3,0));
  {
   irr::core::dimension2d<int>* tolua_ret = (irr::core::dimension2d<int>*)  Mtolua_new((irr::core::dimension2d<int>)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 3;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2di_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_new02
static int tolua_NeoGame_irr_core_dimension2di_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::dimension2d<int>* tolua_ret = (irr::core::dimension2d<int>*)  Mtolua_new((irr::core::dimension2d<int>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<int>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2di_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_new02_local
static int tolua_NeoGame_irr_core_dimension2di_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::dimension2d<int>* tolua_ret = (irr::core::dimension2d<int>*)  Mtolua_new((irr::core::dimension2d<int>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2di_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di__eq00
static int tolua_NeoGame_irr_core_dimension2di__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<int>* other = ((const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di__eq01
static int tolua_NeoGame_irr_core_dimension2di__eq01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<int>* other = ((const irr::core::vector2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2di__eq00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_set00
static int tolua_NeoGame_irr_core_dimension2di_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::dimension2d<int>* self = (irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int width = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int height = ((const int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::dimension2d<int>& tolua_ret = (irr::core::dimension2d<int>&)  self->set(width,height);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::dimension2d<int>");
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di__div00
static int tolua_NeoGame_irr_core_dimension2di__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int scale = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::dimension2d<int> tolua_ret = (irr::core::dimension2d<int>)  self->operator/(scale);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
   tolua_pushnumber(tolua_S,(lua_Number)scale);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di__mul00
static int tolua_NeoGame_irr_core_dimension2di__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const int scale = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::dimension2d<int> tolua_ret = (irr::core::dimension2d<int>)  self->operator*(scale);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
   tolua_pushnumber(tolua_S,(lua_Number)scale);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di__add00
static int tolua_NeoGame_irr_core_dimension2di__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<int>* other = ((const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::dimension2d<int> tolua_ret = (irr::core::dimension2d<int>)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di__sub00
static int tolua_NeoGame_irr_core_dimension2di__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<int>* other = ((const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::dimension2d<int> tolua_ret = (irr::core::dimension2d<int>)  self->operator-(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArea of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_getArea00
static int tolua_NeoGame_irr_core_dimension2di_getArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArea'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getArea();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOptimalSize of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_getOptimalSize00
static int tolua_NeoGame_irr_core_dimension2di_getOptimalSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  bool requirePowerOfTwo = ((bool)  tolua_toboolean(tolua_S,2,true));
  bool requireSquare = ((bool)  tolua_toboolean(tolua_S,3,false));
  bool larger = ((bool)  tolua_toboolean(tolua_S,4,true));
  unsigned int maxValue = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOptimalSize'", NULL);
#endif
  {
   irr::core::dimension2d<int> tolua_ret = (irr::core::dimension2d<int>)  self->getOptimalSize(requirePowerOfTwo,requireSquare,larger,maxValue);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOptimalSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2di_getInterpolated00
static int tolua_NeoGame_irr_core_dimension2di_getInterpolated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<int>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<int>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<int>* self = (const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<int>* other = ((const irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,2,0));
  float d = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated'", NULL);
#endif
  {
   irr::core::dimension2d<int> tolua_ret = (irr::core::dimension2d<int>)  self->getInterpolated(*other,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<int>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<int>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<int>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Width of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__dimension2d_int__Width
static int tolua_get_irr__core__dimension2d_int__Width(lua_State* tolua_S)
{
  irr::core::dimension2d<int>* self = (irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Width of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__dimension2d_int__Width
static int tolua_set_irr__core__dimension2d_int__Width(lua_State* tolua_S)
{
  irr::core::dimension2d<int>* self = (irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Height of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__dimension2d_int__Height
static int tolua_get_irr__core__dimension2d_int__Height(lua_State* tolua_S)
{
  irr::core::dimension2d<int>* self = (irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Height of class  irr::core::dimension2d<int> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__dimension2d_int__Height
static int tolua_set_irr__core__dimension2d_int__Height(lua_State* tolua_S)
{
  irr::core::dimension2d<int>* self = (irr::core::dimension2d<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_new00
static int tolua_NeoGame_irr_core_dimension2df_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::dimension2d<float>* tolua_ret = (irr::core::dimension2d<float>*)  Mtolua_new((irr::core::dimension2d<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<float>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_new00_local
static int tolua_NeoGame_irr_core_dimension2df_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::core::dimension2d<float>* tolua_ret = (irr::core::dimension2d<float>*)  Mtolua_new((irr::core::dimension2d<float>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_new01
static int tolua_NeoGame_irr_core_dimension2df_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const float width = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float height = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   irr::core::dimension2d<float>* tolua_ret = (irr::core::dimension2d<float>*)  Mtolua_new((irr::core::dimension2d<float>)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<float>");
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 3;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2df_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_new01_local
static int tolua_NeoGame_irr_core_dimension2df_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const float width = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float height = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   irr::core::dimension2d<float>* tolua_ret = (irr::core::dimension2d<float>*)  Mtolua_new((irr::core::dimension2d<float>)(width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 3;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2df_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_new02
static int tolua_NeoGame_irr_core_dimension2df_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::dimension2d<float>* tolua_ret = (irr::core::dimension2d<float>*)  Mtolua_new((irr::core::dimension2d<float>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<float>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2df_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_new02_local
static int tolua_NeoGame_irr_core_dimension2df_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::core::dimension2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::core::dimension2d<float>* tolua_ret = (irr::core::dimension2d<float>*)  Mtolua_new((irr::core::dimension2d<float>)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2df_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df__eq00
static int tolua_NeoGame_irr_core_dimension2df__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<float>* other = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df__eq01
static int tolua_NeoGame_irr_core_dimension2df__eq01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::vector2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::vector2d<float>* other = ((const irr::core::vector2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_core_dimension2df__eq00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_set00
static int tolua_NeoGame_irr_core_dimension2df_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::core::dimension2d<float>* self = (irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float width = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float height = ((const float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   irr::core::dimension2d<float>& tolua_ret = (irr::core::dimension2d<float>&)  self->set(width,height);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::dimension2d<float>");
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df__div00
static int tolua_NeoGame_irr_core_dimension2df__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float scale = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   irr::core::dimension2d<float> tolua_ret = (irr::core::dimension2d<float>)  self->operator/(scale);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
   tolua_pushnumber(tolua_S,(lua_Number)scale);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df__mul00
static int tolua_NeoGame_irr_core_dimension2df__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const float scale = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   irr::core::dimension2d<float> tolua_ret = (irr::core::dimension2d<float>)  self->operator*(scale);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
   tolua_pushnumber(tolua_S,(lua_Number)scale);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df__add00
static int tolua_NeoGame_irr_core_dimension2df__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<float>* other = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::core::dimension2d<float> tolua_ret = (irr::core::dimension2d<float>)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df__sub00
static int tolua_NeoGame_irr_core_dimension2df__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<float>* other = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   irr::core::dimension2d<float> tolua_ret = (irr::core::dimension2d<float>)  self->operator-(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArea of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_getArea00
static int tolua_NeoGame_irr_core_dimension2df_getArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArea'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getArea();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOptimalSize of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_getOptimalSize00
static int tolua_NeoGame_irr_core_dimension2df_getOptimalSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  bool requirePowerOfTwo = ((bool)  tolua_toboolean(tolua_S,2,true));
  bool requireSquare = ((bool)  tolua_toboolean(tolua_S,3,false));
  bool larger = ((bool)  tolua_toboolean(tolua_S,4,true));
  unsigned int maxValue = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOptimalSize'", NULL);
#endif
  {
   irr::core::dimension2d<float> tolua_ret = (irr::core::dimension2d<float>)  self->getOptimalSize(requirePowerOfTwo,requireSquare,larger,maxValue);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOptimalSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_core_dimension2df_getInterpolated00
static int tolua_NeoGame_irr_core_dimension2df_getInterpolated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::core::dimension2d<float>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::core::dimension2d<float>* self = (const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
  const irr::core::dimension2d<float>* other = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,2,0));
  float d = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated'", NULL);
#endif
  {
   irr::core::dimension2d<float> tolua_ret = (irr::core::dimension2d<float>)  self->getInterpolated(*other,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::dimension2d<float>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::dimension2d<float>));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::dimension2d<float>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Width of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__dimension2d_float__Width
static int tolua_get_irr__core__dimension2d_float__Width(lua_State* tolua_S)
{
  irr::core::dimension2d<float>* self = (irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Width of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__dimension2d_float__Width
static int tolua_set_irr__core__dimension2d_float__Width(lua_State* tolua_S)
{
  irr::core::dimension2d<float>* self = (irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Height of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_get_irr__core__dimension2d_float__Height
static int tolua_get_irr__core__dimension2d_float__Height(lua_State* tolua_S)
{
  irr::core::dimension2d<float>* self = (irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Height of class  irr::core::dimension2d<float> */
#ifndef TOLUA_DISABLE_tolua_set_irr__core__dimension2d_float__Height
static int tolua_set_irr__core__dimension2d_float__Height(lua_State* tolua_S)
{
  irr::core::dimension2d<float>* self = (irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::RGBA16 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_RGBA1600
static int tolua_NeoGame_irr_video_RGBA1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int r = ((int)  tolua_tonumber(tolua_S,1,0));
  int g = ((int)  tolua_tonumber(tolua_S,2,0));
  int b = ((int)  tolua_tonumber(tolua_S,3,0));
  int a = ((int)  tolua_tonumber(tolua_S,4,0xFF));
  {
   unsigned short tolua_ret = (unsigned short)  irr::video::RGBA16(r,g,b,a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RGBA16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::RGB16 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_RGB1600
static int tolua_NeoGame_irr_video_RGB1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int r = ((int)  tolua_tonumber(tolua_S,1,0));
  int g = ((int)  tolua_tonumber(tolua_S,2,0));
  int b = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   unsigned short tolua_ret = (unsigned short)  irr::video::RGB16(r,g,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RGB16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::RGB16from16 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_RGB16from1600
static int tolua_NeoGame_irr_video_RGB16from1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short r = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  unsigned short g = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
  unsigned short b = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
  {
   unsigned short tolua_ret = (unsigned short)  irr::video::RGB16from16(r,g,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RGB16from16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::X8R8G8B8toA1R5G5B5 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_X8R8G8B8toA1R5G5B500
static int tolua_NeoGame_irr_video_X8R8G8B8toA1R5G5B500(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int color = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   unsigned short tolua_ret = (unsigned short)  irr::video::X8R8G8B8toA1R5G5B5(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'X8R8G8B8toA1R5G5B5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::A8R8G8B8toA1R5G5B5 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_A8R8G8B8toA1R5G5B500
static int tolua_NeoGame_irr_video_A8R8G8B8toA1R5G5B500(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int color = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   unsigned short tolua_ret = (unsigned short)  irr::video::A8R8G8B8toA1R5G5B5(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'A8R8G8B8toA1R5G5B5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::A8R8G8B8toR5G6B5 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_A8R8G8B8toR5G6B500
static int tolua_NeoGame_irr_video_A8R8G8B8toR5G6B500(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int color = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   unsigned short tolua_ret = (unsigned short)  irr::video::A8R8G8B8toR5G6B5(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'A8R8G8B8toR5G6B5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::A1R5G5B5toA8R8G8B8 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_A1R5G5B5toA8R8G8B800
static int tolua_NeoGame_irr_video_A1R5G5B5toA8R8G8B800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short color = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  irr::video::A1R5G5B5toA8R8G8B8(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'A1R5G5B5toA8R8G8B8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::R5G6B5toA8R8G8B8 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_R5G6B5toA8R8G8B800
static int tolua_NeoGame_irr_video_R5G6B5toA8R8G8B800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short color = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  irr::video::R5G6B5toA8R8G8B8(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'R5G6B5toA8R8G8B8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::R5G6B5toA1R5G5B5 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_R5G6B5toA1R5G5B500
static int tolua_NeoGame_irr_video_R5G6B5toA1R5G5B500(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short color = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  {
   unsigned short tolua_ret = (unsigned short)  irr::video::R5G6B5toA1R5G5B5(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'R5G6B5toA1R5G5B5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::A1R5G5B5toR5G6B5 */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_A1R5G5B5toR5G6B500
static int tolua_NeoGame_irr_video_A1R5G5B5toR5G6B500(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short color = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  {
   unsigned short tolua_ret = (unsigned short)  irr::video::A1R5G5B5toR5G6B5(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'A1R5G5B5toR5G6B5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::getAlpha */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_getAlpha00
static int tolua_NeoGame_irr_video_getAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short color = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  irr::video::getAlpha(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::getRed */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_getRed00
static int tolua_NeoGame_irr_video_getRed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short color = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  irr::video::getRed(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::getGreen */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_getGreen00
static int tolua_NeoGame_irr_video_getGreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short color = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  irr::video::getGreen(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::getBlue */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_getBlue00
static int tolua_NeoGame_irr_video_getBlue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned short color = ((unsigned short)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  irr::video::getBlue(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::video::getAverage */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_getAverage00
static int tolua_NeoGame_irr_video_getAverage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  signed short color = ((signed short)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  irr::video::getAverage(color);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAverage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_new00
static int tolua_NeoGame_irr_video_SColor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::video::SColor* tolua_ret = (irr::video::SColor*)  Mtolua_new((irr::video::SColor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_new00_local
static int tolua_NeoGame_irr_video_SColor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::video::SColor* tolua_ret = (irr::video::SColor*)  Mtolua_new((irr::video::SColor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_new01
static int tolua_NeoGame_irr_video_SColor_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
  int r = ((int)  tolua_tonumber(tolua_S,3,0));
  int g = ((int)  tolua_tonumber(tolua_S,4,0));
  int b = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   irr::video::SColor* tolua_ret = (irr::video::SColor*)  Mtolua_new((irr::video::SColor)(a,r,g,b));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColor");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColor_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_new01_local
static int tolua_NeoGame_irr_video_SColor_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
  int r = ((int)  tolua_tonumber(tolua_S,3,0));
  int g = ((int)  tolua_tonumber(tolua_S,4,0));
  int b = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   irr::video::SColor* tolua_ret = (irr::video::SColor*)  Mtolua_new((irr::video::SColor)(a,r,g,b));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColor_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_new02
static int tolua_NeoGame_irr_video_SColor_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int clr = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   irr::video::SColor* tolua_ret = (irr::video::SColor*)  Mtolua_new((irr::video::SColor)(clr));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColor");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColor_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_new02_local
static int tolua_NeoGame_irr_video_SColor_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int clr = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   irr::video::SColor* tolua_ret = (irr::video::SColor*)  Mtolua_new((irr::video::SColor)(clr));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColor_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlpha of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getAlpha00
static int tolua_NeoGame_irr_video_SColor_getAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlpha'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAlpha();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRed of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getRed00
static int tolua_NeoGame_irr_video_SColor_getRed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRed'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGreen of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getGreen00
static int tolua_NeoGame_irr_video_SColor_getGreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGreen'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getGreen();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlue of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getBlue00
static int tolua_NeoGame_irr_video_SColor_getBlue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlue'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getBlue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLightness of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getLightness00
static int tolua_NeoGame_irr_video_SColor_getLightness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLightness'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLightness();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLightness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLuminance of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getLuminance00
static int tolua_NeoGame_irr_video_SColor_getLuminance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLuminance'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLuminance();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLuminance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAverage of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getAverage00
static int tolua_NeoGame_irr_video_SColor_getAverage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAverage'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAverage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAverage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlpha of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_setAlpha00
static int tolua_NeoGame_irr_video_SColor_setAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlpha'", NULL);
#endif
  {
   self->setAlpha(a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRed of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_setRed00
static int tolua_NeoGame_irr_video_SColor_setRed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  int r = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRed'", NULL);
#endif
  {
   self->setRed(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGreen of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_setGreen00
static int tolua_NeoGame_irr_video_SColor_setGreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  int g = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGreen'", NULL);
#endif
  {
   self->setGreen(g);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlue of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_setBlue00
static int tolua_NeoGame_irr_video_SColor_setBlue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  int b = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlue'", NULL);
#endif
  {
   self->setBlue(b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toA1R5G5B5 of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_toA1R5G5B500
static int tolua_NeoGame_irr_video_SColor_toA1R5G5B500(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toA1R5G5B5'", NULL);
#endif
  {
   unsigned short tolua_ret = (unsigned short)  self->toA1R5G5B5();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toA1R5G5B5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toOpenGLColor of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_toOpenGLColor00
static int tolua_NeoGame_irr_video_SColor_toOpenGLColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  unsigned char* dest = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toOpenGLColor'", NULL);
#endif
  {
   self->toOpenGLColor(dest);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toOpenGLColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_set00
static int tolua_NeoGame_irr_video_SColor_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
  int r = ((int)  tolua_tonumber(tolua_S,3,0));
  int g = ((int)  tolua_tonumber(tolua_S,4,0));
  int b = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(a,r,g,b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_set01
static int tolua_NeoGame_irr_video_SColor_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  int col = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(col);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColor_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor__eq00
static int tolua_NeoGame_irr_video_SColor__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::video::SColor",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  const irr::video::SColor* other = ((const irr::video::SColor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator< of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor__lt00
static int tolua_NeoGame_irr_video_SColor__lt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::video::SColor",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  const irr::video::SColor* other = ((const irr::video::SColor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.lt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor__add00
static int tolua_NeoGame_irr_video_SColor__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::video::SColor",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  const irr::video::SColor* other = ((const irr::video::SColor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   irr::video::SColor tolua_ret = (irr::video::SColor)  self->operator+(*other);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::video::SColor)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::video::SColor));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getInterpolated00
static int tolua_NeoGame_irr_video_SColor_getInterpolated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::video::SColor",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  const irr::video::SColor* other = ((const irr::video::SColor*)  tolua_tousertype(tolua_S,2,0));
  float d = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated'", NULL);
#endif
  {
   irr::video::SColor tolua_ret = (irr::video::SColor)  self->getInterpolated(*other,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::video::SColor)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::video::SColor));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated_quadratic of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getInterpolated_quadratic00
static int tolua_NeoGame_irr_video_SColor_getInterpolated_quadratic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::video::SColor",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::video::SColor",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColor* self = (const irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  const irr::video::SColor* c1 = ((const irr::video::SColor*)  tolua_tousertype(tolua_S,2,0));
  const irr::video::SColor* c2 = ((const irr::video::SColor*)  tolua_tousertype(tolua_S,3,0));
  float d = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated_quadratic'", NULL);
#endif
  {
   irr::video::SColor tolua_ret = (irr::video::SColor)  self->getInterpolated_quadratic(*c1,*c2,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::video::SColor)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::video::SColor));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated_quadratic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setData of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_setData00
static int tolua_NeoGame_irr_video_SColor_setData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  const void* data = ((const void*)  tolua_touserdata(tolua_S,2,0));
  irr::video::ECOLOR_FORMAT format = ((irr::video::ECOLOR_FORMAT) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setData'", NULL);
#endif
  {
   self->setData(data,format);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getData of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColor_getData00
static int tolua_NeoGame_irr_video_SColor_getData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  irr::video::ECOLOR_FORMAT format = ((irr::video::ECOLOR_FORMAT) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getData'", NULL);
#endif
  {
   self->getData(data,format);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: color of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_get_irr__video__SColor_color
static int tolua_get_irr__video__SColor_color(lua_State* tolua_S)
{
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->color);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: color of class  irr::video::SColor */
#ifndef TOLUA_DISABLE_tolua_set_irr__video__SColor_color
static int tolua_set_irr__video__SColor_color(lua_State* tolua_S)
{
  irr::video::SColor* self = (irr::video::SColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->color = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_new00
static int tolua_NeoGame_irr_video_SColorf_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::video::SColorf* tolua_ret = (irr::video::SColorf*)  Mtolua_new((irr::video::SColorf)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColorf");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_new00_local
static int tolua_NeoGame_irr_video_SColorf_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::video::SColorf* tolua_ret = (irr::video::SColorf*)  Mtolua_new((irr::video::SColorf)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColorf");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_new01
static int tolua_NeoGame_irr_video_SColorf_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,1.0f));
  {
   irr::video::SColorf* tolua_ret = (irr::video::SColorf*)  Mtolua_new((irr::video::SColorf)(r,g,b,a));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColorf");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColorf_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_new01_local
static int tolua_NeoGame_irr_video_SColorf_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,1.0f));
  {
   irr::video::SColorf* tolua_ret = (irr::video::SColorf*)  Mtolua_new((irr::video::SColorf)(r,g,b,a));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColorf");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColorf_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_new02
static int tolua_NeoGame_irr_video_SColorf_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"irr::video::SColor",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::video::SColor c = *((irr::video::SColor*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::video::SColorf* tolua_ret = (irr::video::SColorf*)  Mtolua_new((irr::video::SColorf)(c));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColorf");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColorf_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_new02_local
static int tolua_NeoGame_irr_video_SColorf_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"irr::video::SColor",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::video::SColor c = *((irr::video::SColor*)  tolua_tousertype(tolua_S,2,0));
  {
   irr::video::SColorf* tolua_ret = (irr::video::SColorf*)  Mtolua_new((irr::video::SColorf)(c));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColorf");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColorf_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: toSColor of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_toSColor00
static int tolua_NeoGame_irr_video_SColorf_toSColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColorf* self = (const irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toSColor'", NULL);
#endif
  {
   irr::video::SColor tolua_ret = (irr::video::SColor)  self->toSColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::video::SColor)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::video::SColor));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toSColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_set00
static int tolua_NeoGame_irr_video_SColorf_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
  float rr = ((float)  tolua_tonumber(tolua_S,2,0));
  float gg = ((float)  tolua_tonumber(tolua_S,3,0));
  float bb = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(rr,gg,bb);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_set01
static int tolua_NeoGame_irr_video_SColorf_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
  float aa = ((float)  tolua_tonumber(tolua_S,2,0));
  float rr = ((float)  tolua_tonumber(tolua_S,3,0));
  float gg = ((float)  tolua_tonumber(tolua_S,4,0));
  float bb = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(aa,rr,gg,bb);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NeoGame_irr_video_SColorf_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_getInterpolated00
static int tolua_NeoGame_irr_video_SColorf_getInterpolated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColorf",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::video::SColorf",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColorf* self = (const irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
  const irr::video::SColorf* other = ((const irr::video::SColorf*)  tolua_tousertype(tolua_S,2,0));
  float d = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated'", NULL);
#endif
  {
   irr::video::SColorf tolua_ret = (irr::video::SColorf)  self->getInterpolated(*other,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::video::SColorf)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColorf");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::video::SColorf));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColorf");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInterpolated_quadratic of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_getInterpolated_quadratic00
static int tolua_NeoGame_irr_video_SColorf_getInterpolated_quadratic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColorf",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::video::SColorf",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::video::SColorf",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColorf* self = (const irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
  const irr::video::SColorf* c1 = ((const irr::video::SColorf*)  tolua_tousertype(tolua_S,2,0));
  const irr::video::SColorf* c2 = ((const irr::video::SColorf*)  tolua_tousertype(tolua_S,3,0));
  float d = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInterpolated_quadratic'", NULL);
#endif
  {
   irr::video::SColorf tolua_ret = (irr::video::SColorf)  self->getInterpolated_quadratic(*c1,*c2,d);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::video::SColorf)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColorf");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::video::SColorf));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::video::SColorf");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInterpolated_quadratic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColorComponentValue of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_setColorComponentValue00
static int tolua_NeoGame_irr_video_SColorf_setColorComponentValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  float value = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColorComponentValue'", NULL);
#endif
  {
   self->setColorComponentValue(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColorComponentValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlpha of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_getAlpha00
static int tolua_NeoGame_irr_video_SColorf_getAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColorf* self = (const irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlpha'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAlpha();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRed of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_getRed00
static int tolua_NeoGame_irr_video_SColorf_getRed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColorf* self = (const irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGreen of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_getGreen00
static int tolua_NeoGame_irr_video_SColorf_getGreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColorf* self = (const irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGreen'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getGreen();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlue of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorf_getBlue00
static int tolua_NeoGame_irr_video_SColorf_getBlue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColorf",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColorf* self = (const irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getBlue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_get_irr__video__SColorf_r
static int tolua_get_irr__video__SColorf_r(lua_State* tolua_S)
{
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_set_irr__video__SColorf_r
static int tolua_set_irr__video__SColorf_r(lua_State* tolua_S)
{
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_get_irr__video__SColorf_g
static int tolua_get_irr__video__SColorf_g(lua_State* tolua_S)
{
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_set_irr__video__SColorf_g
static int tolua_set_irr__video__SColorf_g(lua_State* tolua_S)
{
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_get_irr__video__SColorf_b
static int tolua_get_irr__video__SColorf_b(lua_State* tolua_S)
{
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_set_irr__video__SColorf_b
static int tolua_set_irr__video__SColorf_b(lua_State* tolua_S)
{
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_get_irr__video__SColorf_a
static int tolua_get_irr__video__SColorf_a(lua_State* tolua_S)
{
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a of class  irr::video::SColorf */
#ifndef TOLUA_DISABLE_tolua_set_irr__video__SColorf_a
static int tolua_set_irr__video__SColorf_a(lua_State* tolua_S)
{
  irr::video::SColorf* self = (irr::video::SColorf*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorHSL_new00
static int tolua_NeoGame_irr_video_SColorHSL_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColorHSL",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float h = ((float)  tolua_tonumber(tolua_S,2,0.f));
  float s = ((float)  tolua_tonumber(tolua_S,3,0.f));
  float l = ((float)  tolua_tonumber(tolua_S,4,0.f));
  {
   irr::video::SColorHSL* tolua_ret = (irr::video::SColorHSL*)  Mtolua_new((irr::video::SColorHSL)(h,s,l));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColorHSL");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorHSL_new00_local
static int tolua_NeoGame_irr_video_SColorHSL_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::video::SColorHSL",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float h = ((float)  tolua_tonumber(tolua_S,2,0.f));
  float s = ((float)  tolua_tonumber(tolua_S,3,0.f));
  float l = ((float)  tolua_tonumber(tolua_S,4,0.f));
  {
   irr::video::SColorHSL* tolua_ret = (irr::video::SColorHSL*)  Mtolua_new((irr::video::SColorHSL)(h,s,l));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::video::SColorHSL");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromRGB of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorHSL_fromRGB00
static int tolua_NeoGame_irr_video_SColorHSL_fromRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::SColorHSL",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const irr::video::SColorf",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::SColorHSL* self = (irr::video::SColorHSL*)  tolua_tousertype(tolua_S,1,0);
  const irr::video::SColorf* color = ((const irr::video::SColorf*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromRGB'", NULL);
#endif
  {
   self->fromRGB(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toRGB of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_video_SColorHSL_toRGB00
static int tolua_NeoGame_irr_video_SColorHSL_toRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const irr::video::SColorHSL",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"irr::video::SColorf",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const irr::video::SColorHSL* self = (const irr::video::SColorHSL*)  tolua_tousertype(tolua_S,1,0);
  irr::video::SColorf* color = ((irr::video::SColorf*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toRGB'", NULL);
#endif
  {
   self->toRGB(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Hue of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_get_irr__video__SColorHSL_Hue
static int tolua_get_irr__video__SColorHSL_Hue(lua_State* tolua_S)
{
  irr::video::SColorHSL* self = (irr::video::SColorHSL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Hue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Hue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Hue of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_set_irr__video__SColorHSL_Hue
static int tolua_set_irr__video__SColorHSL_Hue(lua_State* tolua_S)
{
  irr::video::SColorHSL* self = (irr::video::SColorHSL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Hue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Hue = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Saturation of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_get_irr__video__SColorHSL_Saturation
static int tolua_get_irr__video__SColorHSL_Saturation(lua_State* tolua_S)
{
  irr::video::SColorHSL* self = (irr::video::SColorHSL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Saturation'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Saturation);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Saturation of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_set_irr__video__SColorHSL_Saturation
static int tolua_set_irr__video__SColorHSL_Saturation(lua_State* tolua_S)
{
  irr::video::SColorHSL* self = (irr::video::SColorHSL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Saturation'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Saturation = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Luminance of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_get_irr__video__SColorHSL_Luminance
static int tolua_get_irr__video__SColorHSL_Luminance(lua_State* tolua_S)
{
  irr::video::SColorHSL* self = (irr::video::SColorHSL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Luminance'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Luminance);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Luminance of class  irr::video::SColorHSL */
#ifndef TOLUA_DISABLE_tolua_set_irr__video__SColorHSL_Luminance
static int tolua_set_irr__video__SColorHSL_Luminance(lua_State* tolua_S)
{
  irr::video::SColorHSL* self = (irr::video::SColorHSL*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Luminance'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Luminance = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::SKeyMap */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_SKeyMap_new00
static int tolua_NeoGame_irr_SKeyMap_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::SKeyMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::SKeyMap* tolua_ret = (irr::SKeyMap*)  Mtolua_new((irr::SKeyMap)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::SKeyMap");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::SKeyMap */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_SKeyMap_new00_local
static int tolua_NeoGame_irr_SKeyMap_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::SKeyMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   irr::SKeyMap* tolua_ret = (irr::SKeyMap*)  Mtolua_new((irr::SKeyMap)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::SKeyMap");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::SKeyMap */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_SKeyMap_new01
static int tolua_NeoGame_irr_SKeyMap_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::SKeyMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::EKEY_ACTION action = ((irr::EKEY_ACTION) (int)  tolua_tonumber(tolua_S,2,0));
  irr::EKEY_CODE keyCode = ((irr::EKEY_CODE) (int)  tolua_tonumber(tolua_S,3,0));
  {
   irr::SKeyMap* tolua_ret = (irr::SKeyMap*)  Mtolua_new((irr::SKeyMap)(action,keyCode));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::SKeyMap");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_SKeyMap_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::SKeyMap */
#ifndef TOLUA_DISABLE_tolua_NeoGame_irr_SKeyMap_new01_local
static int tolua_NeoGame_irr_SKeyMap_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::SKeyMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::EKEY_ACTION action = ((irr::EKEY_ACTION) (int)  tolua_tonumber(tolua_S,2,0));
  irr::EKEY_CODE keyCode = ((irr::EKEY_CODE) (int)  tolua_tonumber(tolua_S,3,0));
  {
   irr::SKeyMap* tolua_ret = (irr::SKeyMap*)  Mtolua_new((irr::SKeyMap)(action,keyCode));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::SKeyMap");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_irr_SKeyMap_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Action of class  irr::SKeyMap */
#ifndef TOLUA_DISABLE_tolua_get_irr__SKeyMap_Action
static int tolua_get_irr__SKeyMap_Action(lua_State* tolua_S)
{
  irr::SKeyMap* self = (irr::SKeyMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Action'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Action);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Action of class  irr::SKeyMap */
#ifndef TOLUA_DISABLE_tolua_set_irr__SKeyMap_Action
static int tolua_set_irr__SKeyMap_Action(lua_State* tolua_S)
{
  irr::SKeyMap* self = (irr::SKeyMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Action'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Action = ((irr::EKEY_ACTION) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeyCode of class  irr::SKeyMap */
#ifndef TOLUA_DISABLE_tolua_get_irr__SKeyMap_KeyCode
static int tolua_get_irr__SKeyMap_KeyCode(lua_State* tolua_S)
{
  irr::SKeyMap* self = (irr::SKeyMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyCode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->KeyCode);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeyCode of class  irr::SKeyMap */
#ifndef TOLUA_DISABLE_tolua_set_irr__SKeyMap_KeyCode
static int tolua_set_irr__SKeyMap_KeyCode(lua_State* tolua_S)
{
  irr::SKeyMap* self = (irr::SKeyMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyCode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->KeyCode = ((irr::EKEY_CODE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_create00
static int tolua_NeoGame_NeoTrigger_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NeoTrigger",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool alive = ((bool)  tolua_toboolean(tolua_S,2,true));
  {
   NeoTrigger* tolua_ret = (NeoTrigger*)  NeoTrigger::create(alive);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NeoTrigger");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: drop of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_drop00
static int tolua_NeoGame_NeoTrigger_drop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoTrigger* self = (NeoTrigger*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drop'", NULL);
#endif
  {
   self->drop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAlive of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_isAlive00
static int tolua_NeoGame_NeoTrigger_isAlive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const NeoTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const NeoTrigger* self = (const NeoTrigger*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAlive'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isAlive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAlive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlive of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_setAlive00
static int tolua_NeoGame_NeoTrigger_setAlive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoTrigger",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoTrigger* self = (NeoTrigger*)  tolua_tousertype(tolua_S,1,0);
  bool alive = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlive'", NULL);
#endif
  {
   self->setAlive(alive);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDisabled of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_setDisabled00
static int tolua_NeoGame_NeoTrigger_setDisabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoTrigger",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoTrigger* self = (NeoTrigger*)  tolua_tousertype(tolua_S,1,0);
  bool dis = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDisabled'", NULL);
#endif
  {
   self->setDisabled(dis);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDisabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDisabled of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_isDisabled00
static int tolua_NeoGame_NeoTrigger_isDisabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const NeoTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const NeoTrigger* self = (const NeoTrigger*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDisabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDisabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDisabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reset of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_Reset00
static int tolua_NeoGame_NeoTrigger_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoTrigger* self = (NeoTrigger*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Reset'", NULL);
#endif
  {
   self->Reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTriggerFunction of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_setTriggerFunction00
static int tolua_NeoGame_NeoTrigger_setTriggerFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoTrigger",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoTrigger* self = (NeoTrigger*)  tolua_tousertype(tolua_S,1,0);
  std::string funcName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTriggerFunction'", NULL);
#endif
  {
   self->setTriggerFunction(funcName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTriggerFunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTriggerCondition of class  NeoTrigger */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoTrigger_addTriggerCondition00
static int tolua_NeoGame_NeoTrigger_addTriggerCondition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoTrigger",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoTrigger* self = (NeoTrigger*)  tolua_tousertype(tolua_S,1,0);
  int cid = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTriggerCondition'", NULL);
#endif
  {
   self->addTriggerCondition(cid);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTriggerCondition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInstance of class  NeoGameLogic */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGameLogic_GetInstance00
static int tolua_NeoGame_NeoGameLogic_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NeoGameLogic",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NeoGameLogic* tolua_ret = (NeoGameLogic*)  NeoGameLogic::GetInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NeoGameLogic");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroy of class  NeoGameLogic */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGameLogic_Destroy00
static int tolua_NeoGame_NeoGameLogic_Destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NeoGameLogic",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NeoGameLogic::Destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  NeoGameLogic */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGameLogic_Update00
static int tolua_NeoGame_NeoGameLogic_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGameLogic",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGameLogic* self = (NeoGameLogic*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterTrigger of class  NeoGameLogic */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGameLogic_RegisterTrigger00
static int tolua_NeoGame_NeoGameLogic_RegisterTrigger00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGameLogic",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NeoTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGameLogic* self = (NeoGameLogic*)  tolua_tousertype(tolua_S,1,0);
  NeoTrigger* newTrigger = ((NeoTrigger*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterTrigger'", NULL);
#endif
  {
   self->RegisterTrigger(newTrigger);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterTrigger'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveTrigger of class  NeoGameLogic */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGameLogic_RemoveTrigger00
static int tolua_NeoGame_NeoGameLogic_RemoveTrigger00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGameLogic",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NeoTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGameLogic* self = (NeoGameLogic*)  tolua_tousertype(tolua_S,1,0);
  NeoTrigger* trigger = ((NeoTrigger*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveTrigger'", NULL);
#endif
  {
   self->RemoveTrigger(trigger);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveTrigger'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetAllTriggers of class  NeoGameLogic */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGameLogic_ResetAllTriggers00
static int tolua_NeoGame_NeoGameLogic_ResetAllTriggers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGameLogic",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGameLogic* self = (NeoGameLogic*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetAllTriggers'", NULL);
#endif
  {
   self->ResetAllTriggers();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetAllTriggers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getData of class  NeoEvent */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoEvent_getData00
static int tolua_NeoGame_NeoEvent_getData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const NeoEvent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const NeoEvent* self = (const NeoEvent*)  tolua_tousertype(tolua_S,1,0);
  int position = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getData'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getData(position);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTriggerId of class  NeoEvent */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoEvent_getTriggerId00
static int tolua_NeoGame_NeoEvent_getTriggerId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const NeoEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const NeoEvent* self = (const NeoEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTriggerId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTriggerId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTriggerId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetParent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_SetParent00
static int tolua_NeoGame_GameObject_SetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* tolua_var_1 = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetParent'", NULL);
#endif
  {
   self->SetParent(tolua_var_1);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetParent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_GetParent00
static int tolua_NeoGame_GameObject_GetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GameObject* self = (const GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParent'", NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->GetParent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddChild of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_AddChild00
static int tolua_NeoGame_GameObject_AddChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* tolua_var_2 = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddChild'", NULL);
#endif
  {
   self->AddChild(tolua_var_2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChild of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_RemoveChild00
static int tolua_NeoGame_GameObject_RemoveChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* child = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChild'", NULL);
#endif
  {
   self->RemoveChild(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChildren of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_RemoveChildren00
static int tolua_NeoGame_GameObject_RemoveChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChildren'", NULL);
#endif
  {
   self->RemoveChildren();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DestoryChild of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_DestoryChild00
static int tolua_NeoGame_GameObject_DestoryChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* child = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DestoryChild'", NULL);
#endif
  {
   self->DestoryChild(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DestoryChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DestroyChidren of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_DestroyChidren00
static int tolua_NeoGame_GameObject_DestroyChidren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DestroyChidren'", NULL);
#endif
  {
   self->DestroyChidren();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DestroyChidren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPostion of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_SetPostion00
static int tolua_NeoGame_GameObject_SetPostion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  irr::core::vector3df* pos = ((irr::core::vector3df*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPostion'", NULL);
#endif
  {
   self->SetPostion(*pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPostion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotation of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_SetRotation00
static int tolua_NeoGame_GameObject_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  irr::core::vector3df* rot = ((irr::core::vector3df*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotation'", NULL);
#endif
  {
   self->SetRotation(*rot);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPostion of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_GetPostion00
static int tolua_NeoGame_GameObject_GetPostion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GameObject* self = (const GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPostion'", NULL);
#endif
  {
   irr::core::vector3df tolua_ret = (irr::core::vector3df)  self->GetPostion();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3df)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3df");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3df));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3df");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPostion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotation of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_GetRotation00
static int tolua_NeoGame_GameObject_GetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GameObject* self = (const GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotation'", NULL);
#endif
  {
   irr::core::vector3df tolua_ret = (irr::core::vector3df)  self->GetRotation();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((irr::core::vector3df)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3df");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::vector3df));
     tolua_pushusertype(tolua_S,tolua_obj,"irr::core::vector3df");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getId of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_getId00
static int tolua_NeoGame_GameObject_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GameObject* self = (const GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setId of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_setId00
static int tolua_NeoGame_GameObject_setId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setId'", NULL);
#endif
  {
   self->setId(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isActive of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_isActive00
static int tolua_NeoGame_GameObject_isActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const GameObject* self = (const GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isActive'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setActive of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_NeoGame_GameObject_setActive00
static int tolua_NeoGame_GameObject_setActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  bool active = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActive'", NULL);
#endif
  {
   self->setActive(active);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_Update00
static int tolua_NeoGame_NeoGraphics_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInstance of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_GetInstance00
static int tolua_NeoGame_NeoGraphics_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NeoGraphics* tolua_ret = (NeoGraphics*)  NeoGraphics::GetInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NeoGraphics");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAvailableResolution of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_GetAvailableResolution00
static int tolua_NeoGame_NeoGraphics_GetAvailableResolution00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAvailableResolution'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetAvailableResolution();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAvailableResolution'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RenderUI of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_RenderUI00
static int tolua_NeoGame_NeoGraphics_RenderUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RenderUI'", NULL);
#endif
  {
   self->RenderUI();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RenderUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMesh of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_GetMesh00
static int tolua_NeoGame_NeoGraphics_GetMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  std::string file = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMesh'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetMesh(file);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)file);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddAnimatedMeshSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode00
static int tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int meshidx = ((int)  tolua_tonumber(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,-1));
  int id = ((int)  tolua_tonumber(tolua_S,4,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAnimatedMeshSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddAnimatedMeshSceneNode(meshidx,parentIdx,id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddAnimatedMeshSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddAnimatedMeshSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode01
static int tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int meshidx = ((int)  tolua_tonumber(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAnimatedMeshSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddAnimatedMeshSceneNode(meshidx,parentIdx,id,*position);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddAnimatedMeshSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode02
static int tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int meshidx = ((int)  tolua_tonumber(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
  const irr::core::vector3df* rotation = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAnimatedMeshSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddAnimatedMeshSceneNode(meshidx,parentIdx,id,*position,*rotation);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddAnimatedMeshSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode03
static int tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,8,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int meshidx = ((int)  tolua_tonumber(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
  const irr::core::vector3df* rotation = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,6,0));
  const irr::core::vector3df* scale = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,7,0));
  bool alsoAddIfMeshPointerZero = ((bool)  tolua_toboolean(tolua_S,8,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAnimatedMeshSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddAnimatedMeshSceneNode(meshidx,parentIdx,id,*position,*rotation,*scale,alsoAddIfMeshPointerZero);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMeshSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddMeshSceneNode00
static int tolua_NeoGame_NeoGraphics_AddMeshSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int meshIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,-1));
  int id = ((int)  tolua_tonumber(tolua_S,4,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMeshSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddMeshSceneNode(meshIdx,parentIdx,id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMeshSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMeshSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddMeshSceneNode01
static int tolua_NeoGame_NeoGraphics_AddMeshSceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int meshIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMeshSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddMeshSceneNode(meshIdx,parentIdx,id,*position);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddMeshSceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMeshSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddMeshSceneNode02
static int tolua_NeoGame_NeoGraphics_AddMeshSceneNode02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int meshIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
  const irr::core::vector3df* rotation = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMeshSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddMeshSceneNode(meshIdx,parentIdx,id,*position,*rotation);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddMeshSceneNode01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMeshSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddMeshSceneNode03
static int tolua_NeoGame_NeoGraphics_AddMeshSceneNode03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,8,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int meshIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
  const irr::core::vector3df* rotation = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,6,0));
  const irr::core::vector3df* scale = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,7,0));
  bool alsoAddIfMeshPointerZero = ((bool)  tolua_toboolean(tolua_S,8,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMeshSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddMeshSceneNode(meshIdx,parentIdx,id,*position,*rotation,*scale,alsoAddIfMeshPointerZero);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddMeshSceneNode02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCameraSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddCameraSceneNode00
static int tolua_NeoGame_NeoGraphics_AddCameraSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCameraSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCameraSceneNode(parentIdx);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCameraSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCameraSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddCameraSceneNode01
static int tolua_NeoGame_NeoGraphics_AddCameraSceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCameraSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCameraSceneNode(parentIdx,*position);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddCameraSceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCameraSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddCameraSceneNode02
static int tolua_NeoGame_NeoGraphics_AddCameraSceneNode02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,3,0));
  const irr::core::vector3df* lookat = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,4,0));
  int id = ((int)  tolua_tonumber(tolua_S,5,-1));
  bool makeActive = ((bool)  tolua_toboolean(tolua_S,6,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCameraSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCameraSceneNode(parentIdx,*position,*lookat,id,makeActive);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddCameraSceneNode01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCameraSceneNodeMaya of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddCameraSceneNodeMaya00
static int tolua_NeoGame_NeoGraphics_AddCameraSceneNodeMaya00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,-1));
  float rotateSpeed = ((float)  tolua_tonumber(tolua_S,3,-1500.f));
  float zoomSpeed = ((float)  tolua_tonumber(tolua_S,4,200.f));
  float translationSpeed = ((float)  tolua_tonumber(tolua_S,5,1500.f));
  signed int id = ((signed int)  tolua_tonumber(tolua_S,6,-1));
  float distance = ((float)  tolua_tonumber(tolua_S,7,70.f));
  bool makeActive = ((bool)  tolua_toboolean(tolua_S,8,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCameraSceneNodeMaya'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCameraSceneNodeMaya(parentIdx,rotateSpeed,zoomSpeed,translationSpeed,id,distance,makeActive);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCameraSceneNodeMaya'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCameraSceneNodeFPS of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddCameraSceneNodeFPS00
static int tolua_NeoGame_NeoGraphics_AddCameraSceneNodeFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"irr::SKeyMap",1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,10,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,11,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,-1));
  float rotateSpeed = ((float)  tolua_tonumber(tolua_S,3,100.0f));
  float moveSpeed = ((float)  tolua_tonumber(tolua_S,4,0.5f));
  int id = ((int)  tolua_tonumber(tolua_S,5,-1));
  irr::SKeyMap* keyMapArray = ((irr::SKeyMap*)  tolua_tousertype(tolua_S,6,0));
  int keyMapSize = ((int)  tolua_tonumber(tolua_S,7,0));
  bool noVerticalMovement = ((bool)  tolua_toboolean(tolua_S,8,false));
  int jumpSpeed = ((int)  tolua_tonumber(tolua_S,9,0.f));
  bool invertMouse = ((bool)  tolua_toboolean(tolua_S,10,false));
  bool makeActive = ((bool)  tolua_toboolean(tolua_S,11,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCameraSceneNodeFPS'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCameraSceneNodeFPS(parentIdx,rotateSpeed,moveSpeed,id,keyMapArray,keyMapSize,noVerticalMovement,jumpSpeed,invertMouse,makeActive);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCameraSceneNodeFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddLightSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddLightSceneNode00
static int tolua_NeoGame_NeoGraphics_AddLightSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddLightSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddLightSceneNode(parentIdx);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddLightSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddLightSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddLightSceneNode01
static int tolua_NeoGame_NeoGraphics_AddLightSceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddLightSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddLightSceneNode(parentIdx,*position);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddLightSceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddLightSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddLightSceneNode02
static int tolua_NeoGame_NeoGraphics_AddLightSceneNode02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"irr::video::SColorf",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,3,0));
  irr::video::SColorf color = *((irr::video::SColorf*)  tolua_tousertype(tolua_S,4,0));
  float radius = ((float)  tolua_tonumber(tolua_S,5,100.0f));
  int id = ((int)  tolua_tonumber(tolua_S,6,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddLightSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddLightSceneNode(parentIdx,*position,color,radius,id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddLightSceneNode01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddBillboardSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddBillboardSceneNode00
static int tolua_NeoGame_NeoGraphics_AddBillboardSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddBillboardSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddBillboardSceneNode(parentIdx);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddBillboardSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddBillboardSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddBillboardSceneNode01
static int tolua_NeoGame_NeoGraphics_AddBillboardSceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  const irr::core::dimension2d<float>* size = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddBillboardSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddBillboardSceneNode(parentIdx,*size);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddBillboardSceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddBillboardSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddBillboardSceneNode02
static int tolua_NeoGame_NeoGraphics_AddBillboardSceneNode02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const irr::core::dimension2d<float>",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"irr::video::SColor",1,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"irr::video::SColor",1,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,0));
  const irr::core::dimension2d<float>* size = ((const irr::core::dimension2d<float>*)  tolua_tousertype(tolua_S,3,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,4,0));
  int id = ((int)  tolua_tonumber(tolua_S,5,-1));
  irr::video::SColor colorTop = *((irr::video::SColor*)  tolua_tousertype(tolua_S,6,(void*)&(const irr::video::SColor)0xFFFFFFFF));
  irr::video::SColor colorBottom = *((irr::video::SColor*)  tolua_tousertype(tolua_S,7,(void*)&(const irr::video::SColor)0xFFFFFFFF));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddBillboardSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddBillboardSceneNode(parentIdx,*size,*position,id,colorTop,colorBottom);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddBillboardSceneNode01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddParticleSystemSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode00
static int tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  bool withDefaultEmitter = ((bool)  tolua_toboolean(tolua_S,2,true));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,-1));
  int id = ((int)  tolua_tonumber(tolua_S,4,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddParticleSystemSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddParticleSystemSceneNode(withDefaultEmitter,parentIdx,id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddParticleSystemSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddParticleSystemSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode01
static int tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  bool withDefaultEmitter = ((bool)  tolua_toboolean(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddParticleSystemSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddParticleSystemSceneNode(withDefaultEmitter,parentIdx,id,*position);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddParticleSystemSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode02
static int tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  bool withDefaultEmitter = ((bool)  tolua_toboolean(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
  const irr::core::vector3df* rotation = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddParticleSystemSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddParticleSystemSceneNode(withDefaultEmitter,parentIdx,id,*position,*rotation);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddParticleSystemSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode03
static int tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const irr::core::vector3df",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"const irr::core::vector3df",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  bool withDefaultEmitter = ((bool)  tolua_toboolean(tolua_S,2,0));
  int parentIdx = ((int)  tolua_tonumber(tolua_S,3,0));
  int id = ((int)  tolua_tonumber(tolua_S,4,0));
  const irr::core::vector3df* position = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,5,0));
  const irr::core::vector3df* rotation = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,6,0));
  const irr::core::vector3df* scale = ((const irr::core::vector3df*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddParticleSystemSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddParticleSystemSceneNode(withDefaultEmitter,parentIdx,id,*position,*rotation,*scale);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddEmptySceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddEmptySceneNode00
static int tolua_NeoGame_NeoGraphics_AddEmptySceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,-1));
  int id = ((int)  tolua_tonumber(tolua_S,3,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddEmptySceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddEmptySceneNode(parentIdx,id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddEmptySceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddDummyTransformationSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_AddDummyTransformationSceneNode00
static int tolua_NeoGame_NeoGraphics_AddDummyTransformationSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int parentIdx = ((int)  tolua_tonumber(tolua_S,2,-1));
  int id = ((int)  tolua_tonumber(tolua_S,3,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddDummyTransformationSceneNode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AddDummyTransformationSceneNode(parentIdx,id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddDummyTransformationSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActiveCamera of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_GetActiveCamera00
static int tolua_NeoGame_NeoGraphics_GetActiveCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActiveCamera'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetActiveCamera();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetActiveCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetActiveCamera of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_SetActiveCamera00
static int tolua_NeoGame_NeoGraphics_SetActiveCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int cameraIdx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetActiveCamera'", NULL);
#endif
  {
   self->SetActiveCamera(cameraIdx);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetActiveCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadScene of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_loadScene00
static int tolua_NeoGame_NeoGraphics_loadScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  std::string file = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadScene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadScene(file);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttachedGameObject of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_GetAttachedGameObject00
static int tolua_NeoGame_NeoGraphics_GetAttachedGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int idx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttachedGameObject'", NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->GetAttachedGameObject(idx);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttachedGameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindSceneNodeToGameObject of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_BindSceneNodeToGameObject00
static int tolua_NeoGame_NeoGraphics_BindSceneNodeToGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int idx = ((int)  tolua_tonumber(tolua_S,2,0));
  GameObject* go = ((GameObject*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BindSceneNodeToGameObject'", NULL);
#endif
  {
   self->BindSceneNodeToGameObject(idx,go);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindSceneNodeToGameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveSceneNode of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_RemoveSceneNode00
static int tolua_NeoGame_NeoGraphics_RemoveSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveSceneNode'", NULL);
#endif
  {
   self->RemoveSceneNode(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearNodes of class  NeoGraphics */
#ifndef TOLUA_DISABLE_tolua_NeoGame_NeoGraphics_ClearNodes00
static int tolua_NeoGame_NeoGraphics_ClearNodes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NeoGraphics",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NeoGraphics* self = (NeoGraphics*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearNodes'", NULL);
#endif
  {
   self->ClearNodes();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearNodes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_NeoGame_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Application","Application","",NULL);
  tolua_beginmodule(tolua_S,"Application");
   tolua_function(tolua_S,"getInstance",tolua_NeoGame_Application_getInstance00);
   tolua_function(tolua_S,"isRunning",tolua_NeoGame_Application_isRunning00);
   tolua_function(tolua_S,"Quit",tolua_NeoGame_Application_Quit00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_constant(tolua_S,"KEY_LBUTTON",irr::KEY_LBUTTON);
   tolua_constant(tolua_S,"KEY_RBUTTON",irr::KEY_RBUTTON);
   tolua_constant(tolua_S,"KEY_CANCEL",irr::KEY_CANCEL);
   tolua_constant(tolua_S,"KEY_MBUTTON",irr::KEY_MBUTTON);
   tolua_constant(tolua_S,"KEY_XBUTTON1",irr::KEY_XBUTTON1);
   tolua_constant(tolua_S,"KEY_XBUTTON2",irr::KEY_XBUTTON2);
   tolua_constant(tolua_S,"KEY_BACK",irr::KEY_BACK);
   tolua_constant(tolua_S,"KEY_TAB",irr::KEY_TAB);
   tolua_constant(tolua_S,"KEY_CLEAR",irr::KEY_CLEAR);
   tolua_constant(tolua_S,"KEY_RETURN",irr::KEY_RETURN);
   tolua_constant(tolua_S,"KEY_SHIFT",irr::KEY_SHIFT);
   tolua_constant(tolua_S,"KEY_CONTROL",irr::KEY_CONTROL);
   tolua_constant(tolua_S,"KEY_MENU",irr::KEY_MENU);
   tolua_constant(tolua_S,"KEY_PAUSE",irr::KEY_PAUSE);
   tolua_constant(tolua_S,"KEY_CAPITAL",irr::KEY_CAPITAL);
   tolua_constant(tolua_S,"KEY_KANA",irr::KEY_KANA);
   tolua_constant(tolua_S,"KEY_HANGUEL",irr::KEY_HANGUEL);
   tolua_constant(tolua_S,"KEY_HANGUL",irr::KEY_HANGUL);
   tolua_constant(tolua_S,"KEY_JUNJA",irr::KEY_JUNJA);
   tolua_constant(tolua_S,"KEY_FINAL",irr::KEY_FINAL);
   tolua_constant(tolua_S,"KEY_HANJA",irr::KEY_HANJA);
   tolua_constant(tolua_S,"KEY_KANJI",irr::KEY_KANJI);
   tolua_constant(tolua_S,"KEY_ESCAPE",irr::KEY_ESCAPE);
   tolua_constant(tolua_S,"KEY_CONVERT",irr::KEY_CONVERT);
   tolua_constant(tolua_S,"KEY_NONCONVERT",irr::KEY_NONCONVERT);
   tolua_constant(tolua_S,"KEY_ACCEPT",irr::KEY_ACCEPT);
   tolua_constant(tolua_S,"KEY_MODECHANGE",irr::KEY_MODECHANGE);
   tolua_constant(tolua_S,"KEY_SPACE",irr::KEY_SPACE);
   tolua_constant(tolua_S,"KEY_PRIOR",irr::KEY_PRIOR);
   tolua_constant(tolua_S,"KEY_NEXT",irr::KEY_NEXT);
   tolua_constant(tolua_S,"KEY_END",irr::KEY_END);
   tolua_constant(tolua_S,"KEY_HOME",irr::KEY_HOME);
   tolua_constant(tolua_S,"KEY_LEFT",irr::KEY_LEFT);
   tolua_constant(tolua_S,"KEY_UP",irr::KEY_UP);
   tolua_constant(tolua_S,"KEY_RIGHT",irr::KEY_RIGHT);
   tolua_constant(tolua_S,"KEY_DOWN",irr::KEY_DOWN);
   tolua_constant(tolua_S,"KEY_SELECT",irr::KEY_SELECT);
   tolua_constant(tolua_S,"KEY_PRINT",irr::KEY_PRINT);
   tolua_constant(tolua_S,"KEY_EXECUT",irr::KEY_EXECUT);
   tolua_constant(tolua_S,"KEY_SNAPSHOT",irr::KEY_SNAPSHOT);
   tolua_constant(tolua_S,"KEY_INSERT",irr::KEY_INSERT);
   tolua_constant(tolua_S,"KEY_DELETE",irr::KEY_DELETE);
   tolua_constant(tolua_S,"KEY_HELP",irr::KEY_HELP);
   tolua_constant(tolua_S,"KEY_KEY_0",irr::KEY_KEY_0);
   tolua_constant(tolua_S,"KEY_KEY_1",irr::KEY_KEY_1);
   tolua_constant(tolua_S,"KEY_KEY_2",irr::KEY_KEY_2);
   tolua_constant(tolua_S,"KEY_KEY_3",irr::KEY_KEY_3);
   tolua_constant(tolua_S,"KEY_KEY_4",irr::KEY_KEY_4);
   tolua_constant(tolua_S,"KEY_KEY_5",irr::KEY_KEY_5);
   tolua_constant(tolua_S,"KEY_KEY_6",irr::KEY_KEY_6);
   tolua_constant(tolua_S,"KEY_KEY_7",irr::KEY_KEY_7);
   tolua_constant(tolua_S,"KEY_KEY_8",irr::KEY_KEY_8);
   tolua_constant(tolua_S,"KEY_KEY_9",irr::KEY_KEY_9);
   tolua_constant(tolua_S,"KEY_KEY_A",irr::KEY_KEY_A);
   tolua_constant(tolua_S,"KEY_KEY_B",irr::KEY_KEY_B);
   tolua_constant(tolua_S,"KEY_KEY_C",irr::KEY_KEY_C);
   tolua_constant(tolua_S,"KEY_KEY_D",irr::KEY_KEY_D);
   tolua_constant(tolua_S,"KEY_KEY_E",irr::KEY_KEY_E);
   tolua_constant(tolua_S,"KEY_KEY_F",irr::KEY_KEY_F);
   tolua_constant(tolua_S,"KEY_KEY_G",irr::KEY_KEY_G);
   tolua_constant(tolua_S,"KEY_KEY_H",irr::KEY_KEY_H);
   tolua_constant(tolua_S,"KEY_KEY_I",irr::KEY_KEY_I);
   tolua_constant(tolua_S,"KEY_KEY_J",irr::KEY_KEY_J);
   tolua_constant(tolua_S,"KEY_KEY_K",irr::KEY_KEY_K);
   tolua_constant(tolua_S,"KEY_KEY_L",irr::KEY_KEY_L);
   tolua_constant(tolua_S,"KEY_KEY_M",irr::KEY_KEY_M);
   tolua_constant(tolua_S,"KEY_KEY_N",irr::KEY_KEY_N);
   tolua_constant(tolua_S,"KEY_KEY_O",irr::KEY_KEY_O);
   tolua_constant(tolua_S,"KEY_KEY_P",irr::KEY_KEY_P);
   tolua_constant(tolua_S,"KEY_KEY_Q",irr::KEY_KEY_Q);
   tolua_constant(tolua_S,"KEY_KEY_R",irr::KEY_KEY_R);
   tolua_constant(tolua_S,"KEY_KEY_S",irr::KEY_KEY_S);
   tolua_constant(tolua_S,"KEY_KEY_T",irr::KEY_KEY_T);
   tolua_constant(tolua_S,"KEY_KEY_U",irr::KEY_KEY_U);
   tolua_constant(tolua_S,"KEY_KEY_V",irr::KEY_KEY_V);
   tolua_constant(tolua_S,"KEY_KEY_W",irr::KEY_KEY_W);
   tolua_constant(tolua_S,"KEY_KEY_X",irr::KEY_KEY_X);
   tolua_constant(tolua_S,"KEY_KEY_Y",irr::KEY_KEY_Y);
   tolua_constant(tolua_S,"KEY_KEY_Z",irr::KEY_KEY_Z);
   tolua_constant(tolua_S,"KEY_LWIN",irr::KEY_LWIN);
   tolua_constant(tolua_S,"KEY_RWIN",irr::KEY_RWIN);
   tolua_constant(tolua_S,"KEY_APPS",irr::KEY_APPS);
   tolua_constant(tolua_S,"KEY_SLEEP",irr::KEY_SLEEP);
   tolua_constant(tolua_S,"KEY_NUMPAD0",irr::KEY_NUMPAD0);
   tolua_constant(tolua_S,"KEY_NUMPAD1",irr::KEY_NUMPAD1);
   tolua_constant(tolua_S,"KEY_NUMPAD2",irr::KEY_NUMPAD2);
   tolua_constant(tolua_S,"KEY_NUMPAD3",irr::KEY_NUMPAD3);
   tolua_constant(tolua_S,"KEY_NUMPAD4",irr::KEY_NUMPAD4);
   tolua_constant(tolua_S,"KEY_NUMPAD5",irr::KEY_NUMPAD5);
   tolua_constant(tolua_S,"KEY_NUMPAD6",irr::KEY_NUMPAD6);
   tolua_constant(tolua_S,"KEY_NUMPAD7",irr::KEY_NUMPAD7);
   tolua_constant(tolua_S,"KEY_NUMPAD8",irr::KEY_NUMPAD8);
   tolua_constant(tolua_S,"KEY_NUMPAD9",irr::KEY_NUMPAD9);
   tolua_constant(tolua_S,"KEY_MULTIPLY",irr::KEY_MULTIPLY);
   tolua_constant(tolua_S,"KEY_ADD",irr::KEY_ADD);
   tolua_constant(tolua_S,"KEY_SEPARATOR",irr::KEY_SEPARATOR);
   tolua_constant(tolua_S,"KEY_SUBTRACT",irr::KEY_SUBTRACT);
   tolua_constant(tolua_S,"KEY_DECIMAL",irr::KEY_DECIMAL);
   tolua_constant(tolua_S,"KEY_DIVIDE",irr::KEY_DIVIDE);
   tolua_constant(tolua_S,"KEY_F1",irr::KEY_F1);
   tolua_constant(tolua_S,"KEY_F2",irr::KEY_F2);
   tolua_constant(tolua_S,"KEY_F3",irr::KEY_F3);
   tolua_constant(tolua_S,"KEY_F4",irr::KEY_F4);
   tolua_constant(tolua_S,"KEY_F5",irr::KEY_F5);
   tolua_constant(tolua_S,"KEY_F6",irr::KEY_F6);
   tolua_constant(tolua_S,"KEY_F7",irr::KEY_F7);
   tolua_constant(tolua_S,"KEY_F8",irr::KEY_F8);
   tolua_constant(tolua_S,"KEY_F9",irr::KEY_F9);
   tolua_constant(tolua_S,"KEY_F10",irr::KEY_F10);
   tolua_constant(tolua_S,"KEY_F11",irr::KEY_F11);
   tolua_constant(tolua_S,"KEY_F12",irr::KEY_F12);
   tolua_constant(tolua_S,"KEY_F13",irr::KEY_F13);
   tolua_constant(tolua_S,"KEY_F14",irr::KEY_F14);
   tolua_constant(tolua_S,"KEY_F15",irr::KEY_F15);
   tolua_constant(tolua_S,"KEY_F16",irr::KEY_F16);
   tolua_constant(tolua_S,"KEY_F17",irr::KEY_F17);
   tolua_constant(tolua_S,"KEY_F18",irr::KEY_F18);
   tolua_constant(tolua_S,"KEY_F19",irr::KEY_F19);
   tolua_constant(tolua_S,"KEY_F20",irr::KEY_F20);
   tolua_constant(tolua_S,"KEY_F21",irr::KEY_F21);
   tolua_constant(tolua_S,"KEY_F22",irr::KEY_F22);
   tolua_constant(tolua_S,"KEY_F23",irr::KEY_F23);
   tolua_constant(tolua_S,"KEY_F24",irr::KEY_F24);
   tolua_constant(tolua_S,"KEY_NUMLOCK",irr::KEY_NUMLOCK);
   tolua_constant(tolua_S,"KEY_SCROLL",irr::KEY_SCROLL);
   tolua_constant(tolua_S,"KEY_LSHIFT",irr::KEY_LSHIFT);
   tolua_constant(tolua_S,"KEY_RSHIFT",irr::KEY_RSHIFT);
   tolua_constant(tolua_S,"KEY_LCONTROL",irr::KEY_LCONTROL);
   tolua_constant(tolua_S,"KEY_RCONTROL",irr::KEY_RCONTROL);
   tolua_constant(tolua_S,"KEY_LMENU",irr::KEY_LMENU);
   tolua_constant(tolua_S,"KEY_RMENU",irr::KEY_RMENU);
   tolua_constant(tolua_S,"KEY_OEM_1",irr::KEY_OEM_1);
   tolua_constant(tolua_S,"KEY_PLUS",irr::KEY_PLUS);
   tolua_constant(tolua_S,"KEY_COMMA",irr::KEY_COMMA);
   tolua_constant(tolua_S,"KEY_MINUS",irr::KEY_MINUS);
   tolua_constant(tolua_S,"KEY_PERIOD",irr::KEY_PERIOD);
   tolua_constant(tolua_S,"KEY_OEM_2",irr::KEY_OEM_2);
   tolua_constant(tolua_S,"KEY_OEM_3",irr::KEY_OEM_3);
   tolua_constant(tolua_S,"KEY_OEM_4",irr::KEY_OEM_4);
   tolua_constant(tolua_S,"KEY_OEM_5",irr::KEY_OEM_5);
   tolua_constant(tolua_S,"KEY_OEM_6",irr::KEY_OEM_6);
   tolua_constant(tolua_S,"KEY_OEM_7",irr::KEY_OEM_7);
   tolua_constant(tolua_S,"KEY_OEM_8",irr::KEY_OEM_8);
   tolua_constant(tolua_S,"KEY_OEM_AX",irr::KEY_OEM_AX);
   tolua_constant(tolua_S,"KEY_OEM_102",irr::KEY_OEM_102);
   tolua_constant(tolua_S,"KEY_ATTN",irr::KEY_ATTN);
   tolua_constant(tolua_S,"KEY_CRSEL",irr::KEY_CRSEL);
   tolua_constant(tolua_S,"KEY_EXSEL",irr::KEY_EXSEL);
   tolua_constant(tolua_S,"KEY_EREOF",irr::KEY_EREOF);
   tolua_constant(tolua_S,"KEY_PLAY",irr::KEY_PLAY);
   tolua_constant(tolua_S,"KEY_ZOOM",irr::KEY_ZOOM);
   tolua_constant(tolua_S,"KEY_PA1",irr::KEY_PA1);
   tolua_constant(tolua_S,"KEY_OEM_CLEAR",irr::KEY_OEM_CLEAR);
   tolua_constant(tolua_S,"KEY_KEY_CODES_COUNT",irr::KEY_KEY_CODES_COUNT);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_module(tolua_S,"core",0);
   tolua_beginmodule(tolua_S,"core");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"vector3di","irr::core::vector3d<int>","",tolua_collect_irr__core__vector3d_int_);
    #else
    tolua_cclass(tolua_S,"vector3di","irr::core::vector3d<int>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"vector3di");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector3di_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector3di_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector3di_new00_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector3di_new01);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector3di_new01_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector3di_new01_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector3di_new02);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector3di_new02_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector3di_new02_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector3di_new03);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector3di_new03_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector3di_new03_local);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector3di__sub00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector3di__add00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector3di__add01);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector3di__sub01);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector3di__sub02);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_vector3di__mul00);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_vector3di__mul01);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_vector3di__div00);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_vector3di__div01);
     tolua_function(tolua_S,".le",tolua_NeoGame_irr_core_vector3di__le00);
     tolua_function(tolua_S,".lt",tolua_NeoGame_irr_core_vector3di__lt00);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_core_vector3di__eq00);
     tolua_function(tolua_S,"equals",tolua_NeoGame_irr_core_vector3di_equals00);
     tolua_function(tolua_S,"equals",tolua_NeoGame_irr_core_vector3di_equals01);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_vector3di_set00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_vector3di_set01);
     tolua_function(tolua_S,"getLength",tolua_NeoGame_irr_core_vector3di_getLength00);
     tolua_function(tolua_S,"getLengthSQ",tolua_NeoGame_irr_core_vector3di_getLengthSQ00);
     tolua_function(tolua_S,"dotProduct",tolua_NeoGame_irr_core_vector3di_dotProduct00);
     tolua_function(tolua_S,"getDistanceFrom",tolua_NeoGame_irr_core_vector3di_getDistanceFrom00);
     tolua_function(tolua_S,"getDistanceFromSQ",tolua_NeoGame_irr_core_vector3di_getDistanceFromSQ00);
     tolua_function(tolua_S,"crossProduct",tolua_NeoGame_irr_core_vector3di_crossProduct00);
     tolua_function(tolua_S,"isBetweenPoints",tolua_NeoGame_irr_core_vector3di_isBetweenPoints00);
     tolua_function(tolua_S,"normalize",tolua_NeoGame_irr_core_vector3di_normalize00);
     tolua_function(tolua_S,"setLength",tolua_NeoGame_irr_core_vector3di_setLength00);
     tolua_function(tolua_S,"invert",tolua_NeoGame_irr_core_vector3di_invert00);
     tolua_function(tolua_S,"rotateXZBy",tolua_NeoGame_irr_core_vector3di_rotateXZBy00);
     tolua_function(tolua_S,"rotateXZBy",tolua_NeoGame_irr_core_vector3di_rotateXZBy01);
     tolua_function(tolua_S,"rotateXYBy",tolua_NeoGame_irr_core_vector3di_rotateXYBy00);
     tolua_function(tolua_S,"rotateXYBy",tolua_NeoGame_irr_core_vector3di_rotateXYBy01);
     tolua_function(tolua_S,"rotateYZBy",tolua_NeoGame_irr_core_vector3di_rotateYZBy00);
     tolua_function(tolua_S,"rotateYZBy",tolua_NeoGame_irr_core_vector3di_rotateYZBy01);
     tolua_function(tolua_S,"getInterpolated",tolua_NeoGame_irr_core_vector3di_getInterpolated00);
     tolua_function(tolua_S,"getInterpolated_quadratic",tolua_NeoGame_irr_core_vector3di_getInterpolated_quadratic00);
     tolua_function(tolua_S,"interpolate",tolua_NeoGame_irr_core_vector3di_interpolate00);
     tolua_function(tolua_S,"getHorizontalAngle",tolua_NeoGame_irr_core_vector3di_getHorizontalAngle00);
     tolua_function(tolua_S,"getSphericalCoordinateAngles",tolua_NeoGame_irr_core_vector3di_getSphericalCoordinateAngles00);
     tolua_function(tolua_S,"rotationToDirection",tolua_NeoGame_irr_core_vector3di_rotationToDirection00);
     tolua_function(tolua_S,"rotationToDirection",tolua_NeoGame_irr_core_vector3di_rotationToDirection01);
     tolua_function(tolua_S,"getAs4Values",tolua_NeoGame_irr_core_vector3di_getAs4Values00);
     tolua_function(tolua_S,"getAs3Values",tolua_NeoGame_irr_core_vector3di_getAs3Values00);
     tolua_variable(tolua_S,"X",tolua_get_irr__core__vector3d_int__X,tolua_set_irr__core__vector3d_int__X);
     tolua_variable(tolua_S,"Y",tolua_get_irr__core__vector3d_int__Y,tolua_set_irr__core__vector3d_int__Y);
     tolua_variable(tolua_S,"Z",tolua_get_irr__core__vector3d_int__Z,tolua_set_irr__core__vector3d_int__Z);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"vector3df","irr::core::vector3d<float>","",tolua_collect_irr__core__vector3d_float_);
    #else
    tolua_cclass(tolua_S,"vector3df","irr::core::vector3d<float>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"vector3df");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector3df_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector3df_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector3df_new00_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector3df_new01);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector3df_new01_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector3df_new01_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector3df_new02);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector3df_new02_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector3df_new02_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector3df_new03);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector3df_new03_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector3df_new03_local);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector3df__sub00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector3df__add00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector3df__add01);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector3df__sub01);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector3df__sub02);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_vector3df__mul00);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_vector3df__mul01);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_vector3df__div00);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_vector3df__div01);
     tolua_function(tolua_S,".le",tolua_NeoGame_irr_core_vector3df__le00);
     tolua_function(tolua_S,".lt",tolua_NeoGame_irr_core_vector3df__lt00);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_core_vector3df__eq00);
     tolua_function(tolua_S,"equals",tolua_NeoGame_irr_core_vector3df_equals00);
     tolua_function(tolua_S,"equals",tolua_NeoGame_irr_core_vector3df_equals01);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_vector3df_set00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_vector3df_set01);
     tolua_function(tolua_S,"getLength",tolua_NeoGame_irr_core_vector3df_getLength00);
     tolua_function(tolua_S,"getLengthSQ",tolua_NeoGame_irr_core_vector3df_getLengthSQ00);
     tolua_function(tolua_S,"dotProduct",tolua_NeoGame_irr_core_vector3df_dotProduct00);
     tolua_function(tolua_S,"getDistanceFrom",tolua_NeoGame_irr_core_vector3df_getDistanceFrom00);
     tolua_function(tolua_S,"getDistanceFromSQ",tolua_NeoGame_irr_core_vector3df_getDistanceFromSQ00);
     tolua_function(tolua_S,"crossProduct",tolua_NeoGame_irr_core_vector3df_crossProduct00);
     tolua_function(tolua_S,"isBetweenPoints",tolua_NeoGame_irr_core_vector3df_isBetweenPoints00);
     tolua_function(tolua_S,"normalize",tolua_NeoGame_irr_core_vector3df_normalize00);
     tolua_function(tolua_S,"setLength",tolua_NeoGame_irr_core_vector3df_setLength00);
     tolua_function(tolua_S,"invert",tolua_NeoGame_irr_core_vector3df_invert00);
     tolua_function(tolua_S,"rotateXZBy",tolua_NeoGame_irr_core_vector3df_rotateXZBy00);
     tolua_function(tolua_S,"rotateXZBy",tolua_NeoGame_irr_core_vector3df_rotateXZBy01);
     tolua_function(tolua_S,"rotateXYBy",tolua_NeoGame_irr_core_vector3df_rotateXYBy00);
     tolua_function(tolua_S,"rotateXYBy",tolua_NeoGame_irr_core_vector3df_rotateXYBy01);
     tolua_function(tolua_S,"rotateYZBy",tolua_NeoGame_irr_core_vector3df_rotateYZBy00);
     tolua_function(tolua_S,"rotateYZBy",tolua_NeoGame_irr_core_vector3df_rotateYZBy01);
     tolua_function(tolua_S,"getInterpolated",tolua_NeoGame_irr_core_vector3df_getInterpolated00);
     tolua_function(tolua_S,"getInterpolated_quadratic",tolua_NeoGame_irr_core_vector3df_getInterpolated_quadratic00);
     tolua_function(tolua_S,"interpolate",tolua_NeoGame_irr_core_vector3df_interpolate00);
     tolua_function(tolua_S,"getHorizontalAngle",tolua_NeoGame_irr_core_vector3df_getHorizontalAngle00);
     tolua_function(tolua_S,"getSphericalCoordinateAngles",tolua_NeoGame_irr_core_vector3df_getSphericalCoordinateAngles00);
     tolua_function(tolua_S,"rotationToDirection",tolua_NeoGame_irr_core_vector3df_rotationToDirection00);
     tolua_function(tolua_S,"rotationToDirection",tolua_NeoGame_irr_core_vector3df_rotationToDirection01);
     tolua_function(tolua_S,"getAs4Values",tolua_NeoGame_irr_core_vector3df_getAs4Values00);
     tolua_function(tolua_S,"getAs3Values",tolua_NeoGame_irr_core_vector3df_getAs3Values00);
     tolua_variable(tolua_S,"X",tolua_get_irr__core__vector3d_float__X,tolua_set_irr__core__vector3d_float__X);
     tolua_variable(tolua_S,"Y",tolua_get_irr__core__vector3d_float__Y,tolua_set_irr__core__vector3d_float__Y);
     tolua_variable(tolua_S,"Z",tolua_get_irr__core__vector3d_float__Z,tolua_set_irr__core__vector3d_float__Z);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_module(tolua_S,"core",0);
   tolua_beginmodule(tolua_S,"core");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"vector2di","irr::core::vector2d<int>","",tolua_collect_irr__core__vector2d_int_);
    #else
    tolua_cclass(tolua_S,"vector2di","irr::core::vector2d<int>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"vector2di");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2di_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2di_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2di_new00_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2di_new01);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2di_new01_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2di_new01_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2di_new02);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2di_new02_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2di_new02_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2di_new03);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2di_new03_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2di_new03_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2di_new04);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2di_new04_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2di_new04_local);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector2di__sub00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector2di__add00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector2di__add01);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector2di__add02);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector2di__sub01);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector2di__sub02);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector2di__sub03);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_vector2di__mul00);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_vector2di__mul01);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_vector2di__div00);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_vector2di__div01);
     tolua_function(tolua_S,".le",tolua_NeoGame_irr_core_vector2di__le00);
     tolua_function(tolua_S,".lt",tolua_NeoGame_irr_core_vector2di__lt00);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_core_vector2di__eq00);
     tolua_function(tolua_S,"equals",tolua_NeoGame_irr_core_vector2di_equals00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_vector2di_set00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_vector2di_set01);
     tolua_function(tolua_S,"getLength",tolua_NeoGame_irr_core_vector2di_getLength00);
     tolua_function(tolua_S,"getLengthSQ",tolua_NeoGame_irr_core_vector2di_getLengthSQ00);
     tolua_function(tolua_S,"dotProduct",tolua_NeoGame_irr_core_vector2di_dotProduct00);
     tolua_function(tolua_S,"getDistanceFrom",tolua_NeoGame_irr_core_vector2di_getDistanceFrom00);
     tolua_function(tolua_S,"getDistanceFromSQ",tolua_NeoGame_irr_core_vector2di_getDistanceFromSQ00);
     tolua_function(tolua_S,"rotateBy",tolua_NeoGame_irr_core_vector2di_rotateBy00);
     tolua_function(tolua_S,"rotateBy",tolua_NeoGame_irr_core_vector2di_rotateBy01);
     tolua_function(tolua_S,"normalize",tolua_NeoGame_irr_core_vector2di_normalize00);
     tolua_function(tolua_S,"getAngleTrig",tolua_NeoGame_irr_core_vector2di_getAngleTrig00);
     tolua_function(tolua_S,"getAngle",tolua_NeoGame_irr_core_vector2di_getAngle00);
     tolua_function(tolua_S,"getAngleWith",tolua_NeoGame_irr_core_vector2di_getAngleWith00);
     tolua_function(tolua_S,"isBetweenPoints",tolua_NeoGame_irr_core_vector2di_isBetweenPoints00);
     tolua_function(tolua_S,"getInterpolated",tolua_NeoGame_irr_core_vector2di_getInterpolated00);
     tolua_function(tolua_S,"getInterpolated_quadratic",tolua_NeoGame_irr_core_vector2di_getInterpolated_quadratic00);
     tolua_function(tolua_S,"interpolate",tolua_NeoGame_irr_core_vector2di_interpolate00);
     tolua_variable(tolua_S,"X",tolua_get_irr__core__vector2d_int__X,tolua_set_irr__core__vector2d_int__X);
     tolua_variable(tolua_S,"Y",tolua_get_irr__core__vector2d_int__Y,tolua_set_irr__core__vector2d_int__Y);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"vector2df","irr::core::vector2d<float>","",tolua_collect_irr__core__vector2d_float_);
    #else
    tolua_cclass(tolua_S,"vector2df","irr::core::vector2d<float>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"vector2df");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2df_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2df_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2df_new00_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2df_new01);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2df_new01_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2df_new01_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2df_new02);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2df_new02_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2df_new02_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2df_new03);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2df_new03_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2df_new03_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_vector2df_new04);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_vector2df_new04_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_vector2df_new04_local);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector2df__sub00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector2df__add00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector2df__add01);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_vector2df__add02);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector2df__sub01);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector2df__sub02);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_vector2df__sub03);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_vector2df__mul00);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_vector2df__mul01);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_vector2df__div00);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_vector2df__div01);
     tolua_function(tolua_S,".le",tolua_NeoGame_irr_core_vector2df__le00);
     tolua_function(tolua_S,".lt",tolua_NeoGame_irr_core_vector2df__lt00);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_core_vector2df__eq00);
     tolua_function(tolua_S,"equals",tolua_NeoGame_irr_core_vector2df_equals00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_vector2df_set00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_vector2df_set01);
     tolua_function(tolua_S,"getLength",tolua_NeoGame_irr_core_vector2df_getLength00);
     tolua_function(tolua_S,"getLengthSQ",tolua_NeoGame_irr_core_vector2df_getLengthSQ00);
     tolua_function(tolua_S,"dotProduct",tolua_NeoGame_irr_core_vector2df_dotProduct00);
     tolua_function(tolua_S,"getDistanceFrom",tolua_NeoGame_irr_core_vector2df_getDistanceFrom00);
     tolua_function(tolua_S,"getDistanceFromSQ",tolua_NeoGame_irr_core_vector2df_getDistanceFromSQ00);
     tolua_function(tolua_S,"rotateBy",tolua_NeoGame_irr_core_vector2df_rotateBy00);
     tolua_function(tolua_S,"rotateBy",tolua_NeoGame_irr_core_vector2df_rotateBy01);
     tolua_function(tolua_S,"normalize",tolua_NeoGame_irr_core_vector2df_normalize00);
     tolua_function(tolua_S,"getAngleTrig",tolua_NeoGame_irr_core_vector2df_getAngleTrig00);
     tolua_function(tolua_S,"getAngle",tolua_NeoGame_irr_core_vector2df_getAngle00);
     tolua_function(tolua_S,"getAngleWith",tolua_NeoGame_irr_core_vector2df_getAngleWith00);
     tolua_function(tolua_S,"isBetweenPoints",tolua_NeoGame_irr_core_vector2df_isBetweenPoints00);
     tolua_function(tolua_S,"getInterpolated",tolua_NeoGame_irr_core_vector2df_getInterpolated00);
     tolua_function(tolua_S,"getInterpolated_quadratic",tolua_NeoGame_irr_core_vector2df_getInterpolated_quadratic00);
     tolua_function(tolua_S,"interpolate",tolua_NeoGame_irr_core_vector2df_interpolate00);
     tolua_variable(tolua_S,"X",tolua_get_irr__core__vector2d_float__X,tolua_set_irr__core__vector2d_float__X);
     tolua_variable(tolua_S,"Y",tolua_get_irr__core__vector2d_float__Y,tolua_set_irr__core__vector2d_float__Y);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_module(tolua_S,"core",0);
   tolua_beginmodule(tolua_S,"core");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"dimension2di","irr::core::dimension2d<int>","",tolua_collect_irr__core__dimension2d_int_);
    #else
    tolua_cclass(tolua_S,"dimension2di","irr::core::dimension2d<int>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"dimension2di");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_dimension2di_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_dimension2di_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_dimension2di_new00_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_dimension2di_new01);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_dimension2di_new01_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_dimension2di_new01_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_dimension2di_new02);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_dimension2di_new02_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_dimension2di_new02_local);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_core_dimension2di__eq00);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_core_dimension2di__eq01);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_dimension2di_set00);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_dimension2di__div00);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_dimension2di__mul00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_dimension2di__add00);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_dimension2di__sub00);
     tolua_function(tolua_S,"getArea",tolua_NeoGame_irr_core_dimension2di_getArea00);
     tolua_function(tolua_S,"getOptimalSize",tolua_NeoGame_irr_core_dimension2di_getOptimalSize00);
     tolua_function(tolua_S,"getInterpolated",tolua_NeoGame_irr_core_dimension2di_getInterpolated00);
     tolua_variable(tolua_S,"Width",tolua_get_irr__core__dimension2d_int__Width,tolua_set_irr__core__dimension2d_int__Width);
     tolua_variable(tolua_S,"Height",tolua_get_irr__core__dimension2d_int__Height,tolua_set_irr__core__dimension2d_int__Height);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"dimension2df","irr::core::dimension2d<float>","",tolua_collect_irr__core__dimension2d_float_);
    #else
    tolua_cclass(tolua_S,"dimension2df","irr::core::dimension2d<float>","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"dimension2df");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_dimension2df_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_dimension2df_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_dimension2df_new00_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_dimension2df_new01);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_dimension2df_new01_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_dimension2df_new01_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_core_dimension2df_new02);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_core_dimension2df_new02_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_core_dimension2df_new02_local);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_core_dimension2df__eq00);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_core_dimension2df__eq01);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_core_dimension2df_set00);
     tolua_function(tolua_S,".div",tolua_NeoGame_irr_core_dimension2df__div00);
     tolua_function(tolua_S,".mul",tolua_NeoGame_irr_core_dimension2df__mul00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_core_dimension2df__add00);
     tolua_function(tolua_S,".sub",tolua_NeoGame_irr_core_dimension2df__sub00);
     tolua_function(tolua_S,"getArea",tolua_NeoGame_irr_core_dimension2df_getArea00);
     tolua_function(tolua_S,"getOptimalSize",tolua_NeoGame_irr_core_dimension2df_getOptimalSize00);
     tolua_function(tolua_S,"getInterpolated",tolua_NeoGame_irr_core_dimension2df_getInterpolated00);
     tolua_variable(tolua_S,"Width",tolua_get_irr__core__dimension2d_float__Width,tolua_set_irr__core__dimension2d_float__Width);
     tolua_variable(tolua_S,"Height",tolua_get_irr__core__dimension2d_float__Height,tolua_set_irr__core__dimension2d_float__Height);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_module(tolua_S,"video",0);
   tolua_beginmodule(tolua_S,"video");
    tolua_constant(tolua_S,"ECF_A1R5G5B5",irr::video::ECF_A1R5G5B5);
    tolua_constant(tolua_S,"ECF_R5G6B5",irr::video::ECF_R5G6B5);
    tolua_constant(tolua_S,"ECF_R8G8B8",irr::video::ECF_R8G8B8);
    tolua_constant(tolua_S,"ECF_A8R8G8B8",irr::video::ECF_A8R8G8B8);
    tolua_constant(tolua_S,"ECF_R16F",irr::video::ECF_R16F);
    tolua_constant(tolua_S,"ECF_G16R16F",irr::video::ECF_G16R16F);
    tolua_constant(tolua_S,"ECF_A16B16G16R16F",irr::video::ECF_A16B16G16R16F);
    tolua_constant(tolua_S,"ECF_R32F",irr::video::ECF_R32F);
    tolua_constant(tolua_S,"ECF_G32R32F",irr::video::ECF_G32R32F);
    tolua_constant(tolua_S,"ECF_A32B32G32R32F",irr::video::ECF_A32B32G32R32F);
    tolua_constant(tolua_S,"ECF_UNKNOWN",irr::video::ECF_UNKNOWN);
    tolua_function(tolua_S,"RGBA16",tolua_NeoGame_irr_video_RGBA1600);
    tolua_function(tolua_S,"RGB16",tolua_NeoGame_irr_video_RGB1600);
    tolua_function(tolua_S,"RGB16from16",tolua_NeoGame_irr_video_RGB16from1600);
    tolua_function(tolua_S,"X8R8G8B8toA1R5G5B5",tolua_NeoGame_irr_video_X8R8G8B8toA1R5G5B500);
    tolua_function(tolua_S,"A8R8G8B8toA1R5G5B5",tolua_NeoGame_irr_video_A8R8G8B8toA1R5G5B500);
    tolua_function(tolua_S,"A8R8G8B8toR5G6B5",tolua_NeoGame_irr_video_A8R8G8B8toR5G6B500);
    tolua_function(tolua_S,"A1R5G5B5toA8R8G8B8",tolua_NeoGame_irr_video_A1R5G5B5toA8R8G8B800);
    tolua_function(tolua_S,"R5G6B5toA8R8G8B8",tolua_NeoGame_irr_video_R5G6B5toA8R8G8B800);
    tolua_function(tolua_S,"R5G6B5toA1R5G5B5",tolua_NeoGame_irr_video_R5G6B5toA1R5G5B500);
    tolua_function(tolua_S,"A1R5G5B5toR5G6B5",tolua_NeoGame_irr_video_A1R5G5B5toR5G6B500);
    tolua_function(tolua_S,"getAlpha",tolua_NeoGame_irr_video_getAlpha00);
    tolua_function(tolua_S,"getRed",tolua_NeoGame_irr_video_getRed00);
    tolua_function(tolua_S,"getGreen",tolua_NeoGame_irr_video_getGreen00);
    tolua_function(tolua_S,"getBlue",tolua_NeoGame_irr_video_getBlue00);
    tolua_function(tolua_S,"getAverage",tolua_NeoGame_irr_video_getAverage00);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"SColor","irr::video::SColor","",tolua_collect_irr__video__SColor);
    #else
    tolua_cclass(tolua_S,"SColor","irr::video::SColor","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"SColor");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_video_SColor_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_video_SColor_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_video_SColor_new00_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_video_SColor_new01);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_video_SColor_new01_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_video_SColor_new01_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_video_SColor_new02);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_video_SColor_new02_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_video_SColor_new02_local);
     tolua_function(tolua_S,"getAlpha",tolua_NeoGame_irr_video_SColor_getAlpha00);
     tolua_function(tolua_S,"getRed",tolua_NeoGame_irr_video_SColor_getRed00);
     tolua_function(tolua_S,"getGreen",tolua_NeoGame_irr_video_SColor_getGreen00);
     tolua_function(tolua_S,"getBlue",tolua_NeoGame_irr_video_SColor_getBlue00);
     tolua_function(tolua_S,"getLightness",tolua_NeoGame_irr_video_SColor_getLightness00);
     tolua_function(tolua_S,"getLuminance",tolua_NeoGame_irr_video_SColor_getLuminance00);
     tolua_function(tolua_S,"getAverage",tolua_NeoGame_irr_video_SColor_getAverage00);
     tolua_function(tolua_S,"setAlpha",tolua_NeoGame_irr_video_SColor_setAlpha00);
     tolua_function(tolua_S,"setRed",tolua_NeoGame_irr_video_SColor_setRed00);
     tolua_function(tolua_S,"setGreen",tolua_NeoGame_irr_video_SColor_setGreen00);
     tolua_function(tolua_S,"setBlue",tolua_NeoGame_irr_video_SColor_setBlue00);
     tolua_function(tolua_S,"toA1R5G5B5",tolua_NeoGame_irr_video_SColor_toA1R5G5B500);
     tolua_function(tolua_S,"toOpenGLColor",tolua_NeoGame_irr_video_SColor_toOpenGLColor00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_video_SColor_set00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_video_SColor_set01);
     tolua_function(tolua_S,".eq",tolua_NeoGame_irr_video_SColor__eq00);
     tolua_function(tolua_S,".lt",tolua_NeoGame_irr_video_SColor__lt00);
     tolua_function(tolua_S,".add",tolua_NeoGame_irr_video_SColor__add00);
     tolua_function(tolua_S,"getInterpolated",tolua_NeoGame_irr_video_SColor_getInterpolated00);
     tolua_function(tolua_S,"getInterpolated_quadratic",tolua_NeoGame_irr_video_SColor_getInterpolated_quadratic00);
     tolua_function(tolua_S,"setData",tolua_NeoGame_irr_video_SColor_setData00);
     tolua_function(tolua_S,"getData",tolua_NeoGame_irr_video_SColor_getData00);
     tolua_variable(tolua_S,"color",tolua_get_irr__video__SColor_color,tolua_set_irr__video__SColor_color);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"SColorf","irr::video::SColorf","",tolua_collect_irr__video__SColorf);
    #else
    tolua_cclass(tolua_S,"SColorf","irr::video::SColorf","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"SColorf");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_video_SColorf_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_video_SColorf_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_video_SColorf_new00_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_video_SColorf_new01);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_video_SColorf_new01_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_video_SColorf_new01_local);
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_video_SColorf_new02);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_video_SColorf_new02_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_video_SColorf_new02_local);
     tolua_function(tolua_S,"toSColor",tolua_NeoGame_irr_video_SColorf_toSColor00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_video_SColorf_set00);
     tolua_function(tolua_S,"set",tolua_NeoGame_irr_video_SColorf_set01);
     tolua_function(tolua_S,"getInterpolated",tolua_NeoGame_irr_video_SColorf_getInterpolated00);
     tolua_function(tolua_S,"getInterpolated_quadratic",tolua_NeoGame_irr_video_SColorf_getInterpolated_quadratic00);
     tolua_function(tolua_S,"setColorComponentValue",tolua_NeoGame_irr_video_SColorf_setColorComponentValue00);
     tolua_function(tolua_S,"getAlpha",tolua_NeoGame_irr_video_SColorf_getAlpha00);
     tolua_function(tolua_S,"getRed",tolua_NeoGame_irr_video_SColorf_getRed00);
     tolua_function(tolua_S,"getGreen",tolua_NeoGame_irr_video_SColorf_getGreen00);
     tolua_function(tolua_S,"getBlue",tolua_NeoGame_irr_video_SColorf_getBlue00);
     tolua_variable(tolua_S,"r",tolua_get_irr__video__SColorf_r,tolua_set_irr__video__SColorf_r);
     tolua_variable(tolua_S,"g",tolua_get_irr__video__SColorf_g,tolua_set_irr__video__SColorf_g);
     tolua_variable(tolua_S,"b",tolua_get_irr__video__SColorf_b,tolua_set_irr__video__SColorf_b);
     tolua_variable(tolua_S,"a",tolua_get_irr__video__SColorf_a,tolua_set_irr__video__SColorf_a);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"SColorHSL","irr::video::SColorHSL","",tolua_collect_irr__video__SColorHSL);
    #else
    tolua_cclass(tolua_S,"SColorHSL","irr::video::SColorHSL","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"SColorHSL");
     tolua_function(tolua_S,"new",tolua_NeoGame_irr_video_SColorHSL_new00);
     tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_video_SColorHSL_new00_local);
     tolua_function(tolua_S,".call",tolua_NeoGame_irr_video_SColorHSL_new00_local);
     tolua_function(tolua_S,"fromRGB",tolua_NeoGame_irr_video_SColorHSL_fromRGB00);
     tolua_function(tolua_S,"toRGB",tolua_NeoGame_irr_video_SColorHSL_toRGB00);
     tolua_variable(tolua_S,"Hue",tolua_get_irr__video__SColorHSL_Hue,tolua_set_irr__video__SColorHSL_Hue);
     tolua_variable(tolua_S,"Saturation",tolua_get_irr__video__SColorHSL_Saturation,tolua_set_irr__video__SColorHSL_Saturation);
     tolua_variable(tolua_S,"Luminance",tolua_get_irr__video__SColorHSL_Luminance,tolua_set_irr__video__SColorHSL_Luminance);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_constant(tolua_S,"EKA_MOVE_FORWARD",irr::EKA_MOVE_FORWARD);
   tolua_constant(tolua_S,"EKA_MOVE_BACKWARD",irr::EKA_MOVE_BACKWARD);
   tolua_constant(tolua_S,"EKA_STRAFE_LEFT",irr::EKA_STRAFE_LEFT);
   tolua_constant(tolua_S,"EKA_STRAFE_RIGHT",irr::EKA_STRAFE_RIGHT);
   tolua_constant(tolua_S,"EKA_JUMP_UP",irr::EKA_JUMP_UP);
   tolua_constant(tolua_S,"EKA_CROUCH",irr::EKA_CROUCH);
   tolua_constant(tolua_S,"EKA_COUNT",irr::EKA_COUNT);
   tolua_constant(tolua_S,"EKA_FORCE_32BIT",irr::EKA_FORCE_32BIT);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"SKeyMap","irr::SKeyMap","",tolua_collect_irr__SKeyMap);
   #else
   tolua_cclass(tolua_S,"SKeyMap","irr::SKeyMap","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"SKeyMap");
    tolua_function(tolua_S,"new",tolua_NeoGame_irr_SKeyMap_new00);
    tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_SKeyMap_new00_local);
    tolua_function(tolua_S,".call",tolua_NeoGame_irr_SKeyMap_new00_local);
    tolua_function(tolua_S,"new",tolua_NeoGame_irr_SKeyMap_new01);
    tolua_function(tolua_S,"new_local",tolua_NeoGame_irr_SKeyMap_new01_local);
    tolua_function(tolua_S,".call",tolua_NeoGame_irr_SKeyMap_new01_local);
    tolua_variable(tolua_S,"Action",tolua_get_irr__SKeyMap_Action,tolua_set_irr__SKeyMap_Action);
    tolua_variable(tolua_S,"KeyCode",tolua_get_irr__SKeyMap_KeyCode,tolua_set_irr__SKeyMap_KeyCode);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NeoTrigger","NeoTrigger","",NULL);
  tolua_beginmodule(tolua_S,"NeoTrigger");
   tolua_function(tolua_S,"create",tolua_NeoGame_NeoTrigger_create00);
   tolua_function(tolua_S,"drop",tolua_NeoGame_NeoTrigger_drop00);
   tolua_function(tolua_S,"isAlive",tolua_NeoGame_NeoTrigger_isAlive00);
   tolua_function(tolua_S,"setAlive",tolua_NeoGame_NeoTrigger_setAlive00);
   tolua_function(tolua_S,"setDisabled",tolua_NeoGame_NeoTrigger_setDisabled00);
   tolua_function(tolua_S,"isDisabled",tolua_NeoGame_NeoTrigger_isDisabled00);
   tolua_function(tolua_S,"Reset",tolua_NeoGame_NeoTrigger_Reset00);
   tolua_function(tolua_S,"setTriggerFunction",tolua_NeoGame_NeoTrigger_setTriggerFunction00);
   tolua_function(tolua_S,"addTriggerCondition",tolua_NeoGame_NeoTrigger_addTriggerCondition00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NeoGameLogic","NeoGameLogic","",NULL);
  tolua_beginmodule(tolua_S,"NeoGameLogic");
   tolua_function(tolua_S,"GetInstance",tolua_NeoGame_NeoGameLogic_GetInstance00);
   tolua_function(tolua_S,"Destroy",tolua_NeoGame_NeoGameLogic_Destroy00);
   tolua_function(tolua_S,"Update",tolua_NeoGame_NeoGameLogic_Update00);
   tolua_function(tolua_S,"RegisterTrigger",tolua_NeoGame_NeoGameLogic_RegisterTrigger00);
   tolua_function(tolua_S,"RemoveTrigger",tolua_NeoGame_NeoGameLogic_RemoveTrigger00);
   tolua_function(tolua_S,"ResetAllTriggers",tolua_NeoGame_NeoGameLogic_ResetAllTriggers00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NeoEvent","NeoEvent","",NULL);
  tolua_beginmodule(tolua_S,"NeoEvent");
   tolua_function(tolua_S,"getData",tolua_NeoGame_NeoEvent_getData00);
   tolua_function(tolua_S,"getTriggerId",tolua_NeoGame_NeoEvent_getTriggerId00);
  tolua_endmodule(tolua_S);

  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static const unsigned char B[] = {
    10,102,117,110, 99,116,105,111,110, 32,116,111, 78,101,111,
     69,118,101,110,116, 40,101, 41, 10,114,101,116,117,114,110,
     32,116,111,108,117, 97, 46, 99, 97,115,116, 40,101, 44, 34,
     99,111,110,115,116, 32, 78,101,111, 69,118,101,110,116, 34,
     41, 10,101,110,100, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
     45, 45, 45, 45, 45,32
   };
   tolua_dobuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code 1");
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */

  tolua_cclass(tolua_S,"GameObject","GameObject","",NULL);
  tolua_beginmodule(tolua_S,"GameObject");
   tolua_function(tolua_S,"SetParent",tolua_NeoGame_GameObject_SetParent00);
   tolua_function(tolua_S,"GetParent",tolua_NeoGame_GameObject_GetParent00);
   tolua_function(tolua_S,"AddChild",tolua_NeoGame_GameObject_AddChild00);
   tolua_function(tolua_S,"RemoveChild",tolua_NeoGame_GameObject_RemoveChild00);
   tolua_function(tolua_S,"RemoveChildren",tolua_NeoGame_GameObject_RemoveChildren00);
   tolua_function(tolua_S,"DestoryChild",tolua_NeoGame_GameObject_DestoryChild00);
   tolua_function(tolua_S,"DestroyChidren",tolua_NeoGame_GameObject_DestroyChidren00);
   tolua_function(tolua_S,"SetPostion",tolua_NeoGame_GameObject_SetPostion00);
   tolua_function(tolua_S,"SetRotation",tolua_NeoGame_GameObject_SetRotation00);
   tolua_function(tolua_S,"GetPostion",tolua_NeoGame_GameObject_GetPostion00);
   tolua_function(tolua_S,"GetRotation",tolua_NeoGame_GameObject_GetRotation00);
   tolua_function(tolua_S,"getId",tolua_NeoGame_GameObject_getId00);
   tolua_function(tolua_S,"setId",tolua_NeoGame_GameObject_setId00);
   tolua_function(tolua_S,"isActive",tolua_NeoGame_GameObject_isActive00);
   tolua_function(tolua_S,"setActive",tolua_NeoGame_GameObject_setActive00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NeoGraphics","NeoGraphics","",NULL);
  tolua_beginmodule(tolua_S,"NeoGraphics");
   tolua_function(tolua_S,"Update",tolua_NeoGame_NeoGraphics_Update00);
   tolua_function(tolua_S,"GetInstance",tolua_NeoGame_NeoGraphics_GetInstance00);
   tolua_function(tolua_S,"GetAvailableResolution",tolua_NeoGame_NeoGraphics_GetAvailableResolution00);
   tolua_function(tolua_S,"RenderUI",tolua_NeoGame_NeoGraphics_RenderUI00);
   tolua_function(tolua_S,"GetMesh",tolua_NeoGame_NeoGraphics_GetMesh00);
   tolua_function(tolua_S,"AddAnimatedMeshSceneNode",tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode00);
   tolua_function(tolua_S,"AddAnimatedMeshSceneNode",tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode01);
   tolua_function(tolua_S,"AddAnimatedMeshSceneNode",tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode02);
   tolua_function(tolua_S,"AddAnimatedMeshSceneNode",tolua_NeoGame_NeoGraphics_AddAnimatedMeshSceneNode03);
   tolua_function(tolua_S,"AddMeshSceneNode",tolua_NeoGame_NeoGraphics_AddMeshSceneNode00);
   tolua_function(tolua_S,"AddMeshSceneNode",tolua_NeoGame_NeoGraphics_AddMeshSceneNode01);
   tolua_function(tolua_S,"AddMeshSceneNode",tolua_NeoGame_NeoGraphics_AddMeshSceneNode02);
   tolua_function(tolua_S,"AddMeshSceneNode",tolua_NeoGame_NeoGraphics_AddMeshSceneNode03);
   tolua_function(tolua_S,"AddCameraSceneNode",tolua_NeoGame_NeoGraphics_AddCameraSceneNode00);
   tolua_function(tolua_S,"AddCameraSceneNode",tolua_NeoGame_NeoGraphics_AddCameraSceneNode01);
   tolua_function(tolua_S,"AddCameraSceneNode",tolua_NeoGame_NeoGraphics_AddCameraSceneNode02);
   tolua_function(tolua_S,"AddCameraSceneNodeMaya",tolua_NeoGame_NeoGraphics_AddCameraSceneNodeMaya00);
   tolua_function(tolua_S,"AddCameraSceneNodeFPS",tolua_NeoGame_NeoGraphics_AddCameraSceneNodeFPS00);
   tolua_function(tolua_S,"AddLightSceneNode",tolua_NeoGame_NeoGraphics_AddLightSceneNode00);
   tolua_function(tolua_S,"AddLightSceneNode",tolua_NeoGame_NeoGraphics_AddLightSceneNode01);
   tolua_function(tolua_S,"AddLightSceneNode",tolua_NeoGame_NeoGraphics_AddLightSceneNode02);
   tolua_function(tolua_S,"AddBillboardSceneNode",tolua_NeoGame_NeoGraphics_AddBillboardSceneNode00);
   tolua_function(tolua_S,"AddBillboardSceneNode",tolua_NeoGame_NeoGraphics_AddBillboardSceneNode01);
   tolua_function(tolua_S,"AddBillboardSceneNode",tolua_NeoGame_NeoGraphics_AddBillboardSceneNode02);
   tolua_function(tolua_S,"AddParticleSystemSceneNode",tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode00);
   tolua_function(tolua_S,"AddParticleSystemSceneNode",tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode01);
   tolua_function(tolua_S,"AddParticleSystemSceneNode",tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode02);
   tolua_function(tolua_S,"AddParticleSystemSceneNode",tolua_NeoGame_NeoGraphics_AddParticleSystemSceneNode03);
   tolua_function(tolua_S,"AddEmptySceneNode",tolua_NeoGame_NeoGraphics_AddEmptySceneNode00);
   tolua_function(tolua_S,"AddDummyTransformationSceneNode",tolua_NeoGame_NeoGraphics_AddDummyTransformationSceneNode00);
   tolua_function(tolua_S,"GetActiveCamera",tolua_NeoGame_NeoGraphics_GetActiveCamera00);
   tolua_function(tolua_S,"SetActiveCamera",tolua_NeoGame_NeoGraphics_SetActiveCamera00);
   tolua_function(tolua_S,"loadScene",tolua_NeoGame_NeoGraphics_loadScene00);
   tolua_function(tolua_S,"GetAttachedGameObject",tolua_NeoGame_NeoGraphics_GetAttachedGameObject00);
   tolua_function(tolua_S,"BindSceneNodeToGameObject",tolua_NeoGame_NeoGraphics_BindSceneNodeToGameObject00);
   tolua_function(tolua_S,"RemoveSceneNode",tolua_NeoGame_NeoGraphics_RemoveSceneNode00);
   tolua_function(tolua_S,"ClearNodes",tolua_NeoGame_NeoGraphics_ClearNodes00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_NeoGame (lua_State* tolua_S) {
 return tolua_NeoGame_open(tolua_S);
};
#endif

