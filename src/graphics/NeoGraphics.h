/*
 * NeoGraphic.h
 *
 *  Created on: 2016年1月12日
 *      Author: neo
 */

#ifndef SRC_GRAPHICS_NEOGRAPHICS_H_
#define SRC_GRAPHICS_NEOGRAPHICS_H_
#include"../game/GameObject.h"
#include "../game/stdafx.h"
#include <unordered_map>
class GameObject;
using namespace irr;
class NeoGraphics
{
public:
	void Init();
	static void Drop();
	void Update();
	static NeoGraphics* GetInstance();
	const IrrlichtDevice* getDevice();
	const video::IVideoDriver* getDriver();
	const gui::IGUIEnvironment* getGuiEnv();
	const scene::ISceneManager* getSmgr();
	CEGUI::IrrlichtRenderer*GetUIRenderer() const;
	void RenderUI();
	//---lua API---//
	std::string GetAvailableResolution();
	int GetMesh(std::string&file);
	int AddAnimatedMeshSceneNode(int meshidx, int parentIdx = -1, int id = -1,
			const core::vector3df& position = core::vector3df(0, 0, 0),
			const core::vector3df& rotation = core::vector3df(0, 0, 0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f),
			bool alsoAddIfMeshPointerZero = false);

	int AddMeshSceneNode(int meshIdx, int parentIdx = -1, int id = -1,
			const core::vector3df& position = core::vector3df(0, 0, 0),
			const core::vector3df& rotation = core::vector3df(0, 0, 0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f),
			bool alsoAddIfMeshPointerZero = false);

	int AddCameraSceneNode(int parentIdx = -1, const core::vector3df& position =
			core::vector3df(0, 0, 0), const core::vector3df& lookat =
			core::vector3df(0, 0, 100), int id = -1, bool makeActive = true);

	int AddCameraSceneNodeMaya(int parentIdx = -1, float rotateSpeed = -1500.f,
			float zoomSpeed = 200.f, float translationSpeed = 1500.f,
			signed int id = -1, float distance = 70.f, bool makeActive = true);

	int AddCameraSceneNodeFPS(int parentIdx = -1, float rotateSpeed = 100.0f,
			float moveSpeed = 0.5f, int id = -1, SKeyMap* keyMapArray = 0,
			int keyMapSize = 0, bool noVerticalMovement = false, int jumpSpeed =
					0.f, bool invertMouse = false, bool makeActive = true);

	int AddLightSceneNode(int parentIdx = -1, const core::vector3df& position =
			core::vector3df(0, 0, 0),
			video::SColorf color = video::SColorf(1.0f, 1.0f, 1.0f),
			float radius = 100.0f, int id = -1);

	int AddBillboardSceneNode(int parentIdx = -1,
			const core::dimension2d<float>& size = core::dimension2d<float>(
					10.0f, 10.0f), const core::vector3df& position =
					core::vector3df(0, 0, 0), int id = -1,
			video::SColor colorTop = 0xFFFFFFFF, video::SColor colorBottom =
					0xFFFFFFFF);

	int AddParticleSystemSceneNode(bool withDefaultEmitter = true,
			int parentIdx = -1, int id = -1, const core::vector3df& position =
					core::vector3df(0, 0, 0), const core::vector3df& rotation =
					core::vector3df(0, 0, 0), const core::vector3df& scale =
					core::vector3df(1.0f, 1.0f, 1.0f));

	int AddEmptySceneNode(int parentIdx = -1, s32 id = -1);

	int AddDummyTransformationSceneNode(int parentIdx = -1, s32 id = -1);

	int GetActiveCamera() ;
	void SetActiveCamera(int cameraIdx);

	bool loadScene(std::string file);

	//get a game object by attached scene node index(用scene node反向查找保存它的game object)
	GameObject*GetAttachedGameObject(int idx);
	//bind a scene node index to game object
	void BindSceneNodeToGameObject(int idx,GameObject*go);
	void RemoveSceneNode(int index);
	void ClearNodes();

	int getFps();
	//-------c++ API---------//
	scene::ISceneNode*GetSceneNode(int idx);
	scene::IMesh*GetMesh(int idx);
	int RegisterSceneNode(irr::scene::ISceneNode*node);

private:
	NeoGraphics();
	virtual ~NeoGraphics();
	void InitialiseResourceGroupDirectories();
	void InitialiseDefaultResourceGroups();
	static NeoGraphics* _instance;
	//-----irrlicht------//
	IrrlichtDevice* device;
	video::IVideoDriver* driver;
	scene::ISceneManager* smgr;
	gui::IGUIEnvironment* guiEnv;
	//---CEGUI--//
	CEGUI::IrrlichtRenderer* uiRenderer;
	irr::u32 d_lastTime;
	std::vector<irr::scene::IMesh*> list_mesh;
	std::vector<irr::scene::ISceneNode*> list_scene_node;
	std::unordered_map<int,GameObject*>list_go_bindings;
	std::unordered_map<int,int>sceneNode_IMesh_map;
};

#endif /* SRC_GRAPHICS_NEOGRAPHICS_H_ */
