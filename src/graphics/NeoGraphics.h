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
#include "I3rdPersonCamera.h"
#include "sfx/SfxManager.h"
#include <unordered_map>
#include <functional>
class GameObject;
class SfxManager;
using namespace irr;

class NeoGraphics
{
public:
	void Init();
	static void Drop();
	void Update();
	static NeoGraphics* getInstance();
	const IrrlichtDevice* getDevice();
	const video::IVideoDriver* getVideoDriver();
	const gui::IGUIEnvironment* getGuiEnv();
	const scene::ISceneManager* getIrrSceneManger();
	CEGUI::IrrlichtRenderer*getUIRenderer() const;
	std::shared_ptr<SfxManager> getSfxManager() const;
	void RenderUI();
	//---lua API---//
	SfxManager*getSfxManager()
	{
		return sfx_manager.get();
	}
	std::string GetAvailableResolution();
	void setWindowCaption(const std::string& title);
	irr::scene::IAnimatedMesh* getMesh(std::string&file);
	irr::scene::IAnimatedMeshSceneNode* AddAnimatedMeshSceneNode(
			irr::scene::IAnimatedMesh* mesh, irr::scene::ISceneNode* parent = 0,
			int id = -1,
			const core::vector3df& position = core::vector3df(0, 0, 0),
			const core::vector3df& rotation = core::vector3df(0, 0, 0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f),
			bool alsoAddIfMeshPointerZero = false);

	irr::scene::IMeshSceneNode* AddMeshSceneNode(irr::scene::IMesh* mesh,
			irr::scene::ISceneNode* parent = 0, int id = -1,
			const core::vector3df& position = core::vector3df(0, 0, 0),
			const core::vector3df& rotation = core::vector3df(0, 0, 0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f),
			bool alsoAddIfMeshPointerZero = false);

	irr::scene::ICameraSceneNode * AddCameraSceneNode(
			irr::scene::ISceneNode* parent = 0,
			const core::vector3df& position = core::vector3df(0, 0, 0),
			const core::vector3df& lookat = core::vector3df(0, 0, 100), int id =
					-1, bool makeActive = true);

	irr::scene::ICameraSceneNode * AddCameraSceneNodeMaya(
			irr::scene::ISceneNode* parent = 0, float rotateSpeed = -1500.f,
			float zoomSpeed = 200.f, float translationSpeed = 1500.f,
			signed int id = -1, float distance = 70.f, bool makeActive = true);

	irr::scene::ICameraSceneNode * AddCameraSceneNodeFPS(
			irr::scene::ISceneNode* parent = 0, float rotateSpeed = 100.0f,
			float moveSpeed = 0.5f, int id = -1, SKeyMap* keyMapArray = 0,
			int keyMapSize = 0, bool noVerticalMovement = false, int jumpSpeed =
					0.f, bool invertMouse = false, bool makeActive = true);

	irr::scene::I3rdPersonCamera* AddCamera3rdPerson(
			irr::scene::ISceneNode*targetNode, irr::scene::ISceneNode* parent =
					0, int id = -1, float rotationSpeed = 100, float zoomSpeed =
					1, float maxVerticalAngel = 20, float maxZoom = 20,
			bool makeActive = true);

	irr::scene::IMeshSceneNode* AddCubeSceneNode(float size = 10.0f,
			irr::scene::ISceneNode* parent = 0, int id = -1,
			const irr::core::vector3df& position = irr::core::vector3df(0, 0,
					0), const irr::core::vector3df& rotation =
					irr::core::vector3df(0, 0, 0),
			const irr::core::vector3df& scale = irr::core::vector3df(1.0f, 1.0f,
					1.0f));

	irr::scene::IMeshSceneNode* AddSphereSceneNode(float radius = 5.0f,
			int polyCount = 16, irr::scene::ISceneNode* parent = 0, int id = -1,
			const core::vector3df& position = core::vector3df(0, 0, 0),
			const core::vector3df& rotation = core::vector3df(0, 0, 0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f));

	irr::scene::ILightSceneNode * AddLightSceneNode(
			irr::scene::ISceneNode* parent = 0,
			const core::vector3df& position = core::vector3df(0, 0, 0),
			video::SColorf color = video::SColorf(1.0f, 1.0f, 1.0f),
			float radius = 100.0f, int id = -1);

	irr::scene::IBillboardSceneNode * AddBillboardSceneNode(
			irr::scene::ISceneNode* parent = 0,
			const core::dimension2d<float>& size = core::dimension2d<float>(
					10.0f, 10.0f), const core::vector3df& position =
					core::vector3df(0, 0, 0), int id = -1,
			video::SColor colorTop = 0xFFFFFFFF, video::SColor colorBottom =
					0xFFFFFFFF);

	irr::scene::IMeshSceneNode* AddOctreeSceneNode(scene::IAnimatedMesh* mesh,
			scene::ISceneNode* parent = 0, int id = -1,
			int minimalPolysPerNode = 512,
			bool alsoAddIfMeshPointerZero = false);

	irr::scene::IMeshSceneNode* AddOctreeSceneNode(scene::IMesh* mesh,
			scene::ISceneNode* parent = 0, int id = -1,
			int minimalPolysPerNode = 256,
			bool alsoAddIfMeshPointerZero = false);

	irr::scene::ISceneNode* AddSkyDomeSceneNode(video::ITexture* texture,
			unsigned int horiRes = 16, unsigned int vertRes = 8,
			float texturePercentage = 0.9, float spherePercentage = 2.0,
			float radius = 1000.f, irr::scene::ISceneNode* parent = 0, int id =
					-1);

	irr::scene::IParticleSystemSceneNode * AddParticleSystemSceneNode(
			bool withDefaultEmitter = true, irr::scene::ISceneNode* parent = 0,
			int id = -1,
			const core::vector3df& position = core::vector3df(0, 0, 0),
			const core::vector3df& rotation = core::vector3df(0, 0, 0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f));

	irr::scene::ISceneNode* AddEmptySceneNode(
			irr::scene::ISceneNode* parent = 0, int id = -1);

	irr::scene::IDummyTransformationSceneNode* AddDummyTransformationSceneNode(
			irr::scene::ISceneNode* parent = 0, int id = -1);

	irr::scene::IParticleAffector* CreateColourAffactorQ(
			const irr::video::SColor& targetColor0,
			const irr::video::SColor& targetColor1);

	irr::scene::ICameraSceneNode* GetActiveCamera();
	void SetActiveCamera(irr::scene::ICameraSceneNode*camera);
	void SetAmbientLight(const irr::video::SColor& colour);

	bool loadScene(std::string file);

	//get a game object by attached scene node index(用scene node反向查找保存它的game object)
	GameObject*GetAttachedGameObject(irr::scene::ISceneNode*node);
	//bind a scene node index to game object
	void RemoveSceneNode(irr::scene::ISceneNode*node);
	void ClearAllNodes();
	void CleanUp();
	video::ITexture* LoadTexture(std::string&path);
	void UnloadTexture(video::ITexture*texture);

	irr::core::vector2di getPositionOnScreen(
			const irr::core::vector3df& position);
	irr::core::vector3df get3DPositionFromScreen(
			const irr::core::vector2di& screen_position);

	float getFps();
	core::dimension2du getScreenSize();
	std::string getTextFromOSClipboard();
	void setAppClipboardString(const std::string& text);
	std::string getAppClipboardString();
	void setOSClipboardText(const std::string& text);
	std::string getOperatingSystemVersion();
	std::vector<std::string> getMeshTexturePath(irr::scene::IMesh*mesh);
	//-------c++ API---------//
	irr::scene::ISceneNodeAnimator* createAxisAlignedRotateAnimator(
			u32 cycleTime, char align, int direction);
	irr::scene::ISceneNodeAnimator* createTextureMoveAnimator(float speed,
			irr::core::vector2df direction);
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
	std::shared_ptr<SfxManager> sfx_manager;
	//---CEGUI--//
	CEGUI::IrrlichtRenderer* uiRenderer;
	irr::u32 d_lastTime;
};

#endif /* SRC_GRAPHICS_NEOGRAPHICS_H_ */
