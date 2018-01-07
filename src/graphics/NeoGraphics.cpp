/*
 * NeoGraphic.cpp
 *
 *  Created on: 2016年1月12日
 *      Author: neo
 */

#include "NeoGraphics.h"
#include "CEGUI/RendererModules/Irrlicht/ResourceProvider.h"
#include "animators/CSceneNodeAnimatorAxisAlignedRotate.h"
#include "animators/CSceneNodeAnimatorTextureMove.h"
#include "animators/CSceneNodeAnimatorCamera3rdPerson.h"
#include <IrrlichtML/CGUITTFont.h>

NeoGraphics* NeoGraphics::_instance = NULL;
using namespace irr;
NeoGraphics::NeoGraphics() :
		m_delta_time(0)
{
	device = NULL;
}

NeoGraphics::~NeoGraphics()
{
	// TODO Auto-generated destructor stub
	using namespace CEGUI;

	LuaScriptModule* script_mod =
			static_cast<LuaScriptModule*>(System::getSingleton().getScriptingModule());

	// clear script module, since we're going to destroy it.
	System::getSingleton().setScriptingModule(0);

	LuaScriptModule::destroy(*script_mod);

	CEGUI::IrrlichtRenderer& renderer =
			*static_cast<CEGUI::IrrlichtRenderer*>(uiRenderer);

	CEGUI::IrrlichtRenderer::destroy(renderer);

	if (device != NULL)
		device->drop();
}

void NeoGraphics::Init()
{
	int w, h;
	bool fscr = false;
	std::string caption = "";
	w = NeoScript::getInstance()->GetScriptGlobalValue_int(
			"ApplicationSettings.resolution.width");
	h = NeoScript::getInstance()->GetScriptGlobalValue_int(
			"ApplicationSettings.resolution.height");
	fscr = NeoScript::getInstance()->GetScriptGlobalValue_bool(
			"ApplicationSettings.fullscreen");
	caption = NeoScript::getInstance()->GetScriptGlobalValue_string(
			"ApplicationSettings.caption");
	device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(w, h), 16,
			fscr, true, false, 0);
	device->setResizable(false);

	//convert to wstring
	std::wstring ws_caption;
	ws_caption.assign(caption.begin(), caption.end());
	device->setWindowCaption(ws_caption.c_str());
	device->getCursorControl()->setVisible(false);
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guiEnv = device->getGUIEnvironment();
	sfx_manager = std::make_shared<SfxManager>();
	//----CEGUI init----//
	uiRenderer = &(CEGUI::IrrlichtRenderer::bootstrapSystem(*device));
	InitialiseResourceGroupDirectories();
	InitialiseDefaultResourceGroups();
	d_lastTime = device->getTimer()->getRealTime();
}

void NeoGraphics::Drop()
{
	if (_instance != NULL)
		delete _instance;
	_instance = NULL;
}

NeoGraphics* NeoGraphics::getInstance()
{
	if (_instance == NULL)
		_instance = new NeoGraphics();
	return _instance;
}

void NeoGraphics::Update()
{
	if (device->run())
	{
		driver->beginScene(true, true, video::SColor(255, 100, 101, 140));
		smgr->drawAll();
		guiEnv->drawAll();
		RenderUI();
		driver->endScene();

	}
	else
	{
		Application::getInstance()->Quit();
	}
}

const IrrlichtDevice* NeoGraphics::getDevice()
{
	return device;
}

const video::IVideoDriver* NeoGraphics::getVideoDriver()
{
	return driver;
}

const gui::IGUIEnvironment* NeoGraphics::getGuiEnv()
{
	return guiEnv;
}

const scene::ISceneManager* NeoGraphics::getIrrSceneManger()
{
	return smgr;
}

void NeoGraphics::InitialiseResourceGroupDirectories()
{
	//以下代码搬运自cegui Sample
	CEGUI::IrrlichtResourceProvider* rp =
			static_cast<CEGUI::IrrlichtResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
	char* dataPathPrefix = "./resources/ui/cegui_data";
	char resourcePath[260];
	sprintf(resourcePath, "%s/%s", dataPathPrefix, "schemes/");
	rp->setResourceGroupDirectory("schemes", resourcePath);
	sprintf(resourcePath, "%s/%s", dataPathPrefix, "imagesets/");
	rp->setResourceGroupDirectory("imagesets", resourcePath);
	sprintf(resourcePath, "%s/%s", dataPathPrefix, "fonts/");
	rp->setResourceGroupDirectory("fonts", resourcePath);
	sprintf(resourcePath, "%s/%s", dataPathPrefix, "layouts/");
	rp->setResourceGroupDirectory("layouts", resourcePath);
	sprintf(resourcePath, "%s/%s", dataPathPrefix, "looknfeel/");
	rp->setResourceGroupDirectory("looknfeels", resourcePath);
	//sprintf(resourcePath, "%s/%s", dataPathPrefix, "Scripts/");
	rp->setResourceGroupDirectory("lua_scripts", "script/cegui/");
	sprintf(resourcePath, "%s/%s", dataPathPrefix, "xml_schemas/");
	rp->setResourceGroupDirectory("schemas", resourcePath);
	sprintf(resourcePath, "%s/%s", dataPathPrefix, "animations/");
	rp->setResourceGroupDirectory("animations", resourcePath);
	//以下代码是自己打的
	rp->setResourceGroupDirectory("tankTopview",
			"./resources/ui/images/tankTopView");
	rp->setResourceGroupDirectory("images", "./resources/ui/images/");
	rp->setResourceGroupDirectory("mapPreview",
			"./resources/ui/images/mapPreview");
}

void NeoGraphics::RenderUI()
{
	//checkWindowResize();
	// calculate time elapsed
	irr::u32 currTime = device->getTimer()->getRealTime();
	// inject time pulse
	m_delta_time = static_cast<float>(currTime - d_lastTime) * 0.001f;
	CEGUI::System::getSingleton().injectTimePulse(m_delta_time);
	CEGUI::System::getSingleton().getDefaultGUIContext().injectTimePulse(
			m_delta_time);
	d_lastTime = currTime;
	//render gui
	CEGUI::System::getSingleton().renderAllGUIContexts();
	//渲染geometry buffer（直接画屏）
//		std::list<AdvancedGeometryBuffer*>::iterator it=m_AdvancedGeometryBufferList.begin();
//		for(;it!=m_AdvancedGeometryBufferList.end();++it)
//		{
//			(*it)->draw();
//		}
}

CEGUI::IrrlichtRenderer* NeoGraphics::getUIRenderer() const
{
	return uiRenderer;
}

GameObject* NeoGraphics::GetAttachedGameObject(irr::scene::ISceneNode*node)
{
	return (GameObject*) node->getUserData();
}

std::string NeoGraphics::GetAvailableResolution()
{
	irr::video::IVideoModeList* rlist = device->getVideoModeList();
	std::string strlist;
	for (int i = 0; i < rlist->getVideoModeCount(); i++)
	{
		char buffer[48];
		sprintf(buffer, "%d,%d;", rlist->getVideoModeResolution(i).Width,
				rlist->getVideoModeResolution(i).Height);
		strlist.append(buffer);
	}
	return strlist;
}

shared_ptr<SfxManager> NeoGraphics::getSfxManager() const
{
	return sfx_manager;
}

irr::scene::IMeshSceneNode* NeoGraphics::AddOctreeSceneNode(
		scene::IAnimatedMesh* mesh, scene::ISceneNode* parent, int id,
		int minimalPolysPerNode, bool alsoAddIfMeshPointerZero)
{
	return smgr->addOctTreeSceneNode(mesh, parent, id, minimalPolysPerNode,
			alsoAddIfMeshPointerZero);
}

irr::scene::IMeshSceneNode* NeoGraphics::AddOctreeSceneNode(scene::IMesh* mesh,
		scene::ISceneNode* parent, int id, int minimalPolysPerNode,
		bool alsoAddIfMeshPointerZero)
{
	return smgr->addOctTreeSceneNode(mesh, parent, id, minimalPolysPerNode,
			alsoAddIfMeshPointerZero);
}

void NeoGraphics::RemoveSceneNode(irr::scene::ISceneNode* node)
{
	node->remove();
}

void NeoGraphics::CleanUp()
{
	smgr->clear();
	smgr->getMeshCache()->clearUnusedMeshes();
	sfx_manager->CleanUp();
}

irr::scene::ISceneNode* NeoGraphics::AddSkyDomeSceneNode(
		video::ITexture* texture, unsigned int horiRes, unsigned int vertRes,
		float texturePercentage, float spherePercentage, float radius,
		irr::scene::ISceneNode* parent, int id)
{
	return smgr->addSkyDomeSceneNode(texture, horiRes, vertRes,
			texturePercentage, spherePercentage, radius, parent, id);
}

void NeoGraphics::UnloadTexture(video::ITexture* texture)
{
	driver->removeTexture(texture);
}

video::ITexture* NeoGraphics::LoadTexture(std::string& path)
{
	return driver->getTexture(path.c_str());
}

void NeoGraphics::SetAmbientLight(const irr::video::SColor& colour)
{
	smgr->setAmbientLight(colour);
}

std::vector<std::string> NeoGraphics::getMeshTexturePath(
		irr::scene::IMesh* mesh)
{
	std::vector<std::string> result;
	std::set<std::string> path_unique;
	for (unsigned int i = 0; i < mesh->getMeshBufferCount(); i++)
	{
		irr::video::ITexture*texture =
				mesh->getMeshBuffer(i)->getMaterial().getTexture(0);
		if (!texture)
			continue;
		std::string path_str = texture->getName().getPath().c_str();
		path_unique.insert(path_str);
	}
	for (std::string p : path_unique)
	{
		result.push_back(p);
	}
	return result;
}

void NeoGraphics::setWindowCaption(const std::string& title)
{
	std::wstring caption(title.begin(), title.end());
	device->setWindowCaption(caption.c_str());
}

void NeoGraphics::setAppClipboardString(const std::string& text)
{
	CEGUI::System::getSingleton().getClipboard()->setText(text.c_str());
}

void NeoGraphics::setOSClipboardText(const std::string& text)
{
	device->getOSOperator()->copyToClipboard(text.c_str());
}

std::string NeoGraphics::getAppClipboardString()
{
	return std::string(
			CEGUI::System::getSingleton().getClipboard()->getText().c_str());
}

irr::scene::IMeshSceneNode* NeoGraphics::AddCubeSceneNode(float size,
		irr::scene::ISceneNode* parent, int id,
		const irr::core::vector3df& position,
		const irr::core::vector3df& rotation, const irr::core::vector3df& scale)
{
	return smgr->addCubeSceneNode(size, parent, id, position, rotation, scale);
}

irr::scene::IMeshSceneNode* NeoGraphics::AddSphereSceneNode(float radius,
		int polyCount, irr::scene::ISceneNode* parent, int id,
		const core::vector3df& position, const core::vector3df& rotation,
		const core::vector3df& scale)
{
	return smgr->addSphereSceneNode(radius, polyCount, parent, id, position,
			rotation, scale);
}

irr::scene::ISceneNodeAnimator* NeoGraphics::createTextureMoveAnimator(
		float speed, irr::core::vector2df direction)
{
	return new scene::CSceneNodeAnimatorTextureMove(speed, direction);
}

irr::scene::I3rdPersonCamera* NeoGraphics::AddCamera3rdPerson(
		ISceneNode* targetNode, irr::scene::ISceneNode* parent, int id,
		float rotationSpeed, float zoomSpeed, float maxVerticalAngel,
		float maxZoom, bool makeActive)
{
	ICameraSceneNode* node = smgr->addCameraSceneNode(parent, core::vector3df(),
			core::vector3df(0, 0, 100), id, makeActive);
	if (node)
	{
		CSceneNodeAnimatorCamera3rdPerson* animator =
				new CSceneNodeAnimatorCamera3rdPerson(targetNode,
						device->getCursorControl(), rotationSpeed, zoomSpeed,
						maxVerticalAngel, maxZoom);

		node->addAnimator(animator);
		I3rdPersonCamera* camera = new I3rdPersonCamera(node);
		camera->setCameraAnimator(animator);

		animator->drop();

		return camera;
	}
	return NULL;
}

irr::core::vector3df NeoGraphics::get3DPositionFromScreen(
		const irr::core::vector2di& screen_position)
{
	core::line3df line =
			smgr->getSceneCollisionManager()->getRayFromScreenCoordinates(
					screen_position);
	return line.end;
}

core::dimension2du NeoGraphics::getScreenSize()
{
	dimension2du size = driver->getScreenSize();
	return size;
}

irr::scene::ITextSceneNode* NeoGraphics::AddTextSceneNode(gui::IGUIFont* font,
		const std::string&text, video::SColor color, ISceneNode* parent,
		const core::vector3df& position, s32 id)
{
	std::wstring str;
	str.assign(text.begin(), text.end());
	return smgr->addTextSceneNode(font, str.c_str(), color, parent, position,
			id);
}

irr::scene::ISceneNode* NeoGraphics::AddWaterSurfaceNode(
		irr::scene::IMesh* mesh, float waveHight, float waveSpeed,
		float waveLength, scene::ISceneNode*parent, int id,
		const core::vector3df& position, const core::vector3df& rotation,
		const core::vector3df& scale)
{
	return smgr->addWaterSurfaceSceneNode(mesh, waveHight, waveSpeed,
			waveLength, parent, id, position, rotation, scale);
}

void NeoGraphics::ITextNodeSetText(irr::scene::ITextSceneNode* node,
		const std::string& text)
{
	if (!node)
		return;
	std::wstring str;
	str.assign(text.begin(), text.end());
	node->setText(str.c_str());
}

void NeoGraphics::MakePlanarTextureMapping(scene::IMesh* mesh,
		float resolution_herizon, float resolution_vertical, int project_axis,
		const core::vector3df& offset)
{
	if (mesh)
	{
		u8 axis = static_cast<u8>(project_axis);
		smgr->getMeshManipulator()->makePlanarTextureMapping(mesh,
				resolution_herizon, resolution_vertical, axis, offset);
	}
}

void NeoGraphics::MakePlanarTextureMapping(scene::IMesh* mesh, float resolution)
{
	if (mesh)
		smgr->getMeshManipulator()->makePlanarTextureMapping(mesh, resolution);
}

irr::scene::IMesh* NeoGraphics::CreateQuadMesh(const std::string&name,
		const core::dimension2d<f32>& tileSize,
		const core::dimension2d<u32>& tileCount /*= core::dimension2du(1, 1)*/,
		const core::dimension2df& textureRepeatCount /*= core::dimension2df(1.f,
		 1.f)*/)
{
	IMesh* mesh = smgr->getGeometryCreator()->createPlaneMesh(tileSize,
			tileCount, 0, textureRepeatCount);
	if (mesh)
	{
		SAnimatedMesh* animatedMesh = new SAnimatedMesh();
		if (!animatedMesh)
		{
			mesh->drop();
			return 0;
		}

		animatedMesh->addMesh(mesh);
		mesh->drop();
		animatedMesh->recalculateBoundingBox();

		smgr->getMeshCache()->addMesh(name.data(), animatedMesh);
		animatedMesh->drop();
		return animatedMesh;
	}
	return NULL;
}

irr::scene::IMesh* NeoGraphics::CreateCubeMesh(const std::string&name,
		const irr::core::vector3df& size)
{
	IMesh* mesh = smgr->getGeometryCreator()->createCubeMesh(size);
	if (mesh)
	{
		SAnimatedMesh* animatedMesh = new SAnimatedMesh();
		if (!animatedMesh)
		{
			mesh->drop();
			return 0;
		}

		animatedMesh->addMesh(mesh);
		mesh->drop();
		animatedMesh->recalculateBoundingBox();

		smgr->getMeshCache()->addMesh(name.data(), animatedMesh);
		animatedMesh->drop();
		return animatedMesh;
	}
	return NULL;
}

irr::scene::IMesh* NeoGraphics::CreateSphereMesh(const std::string&name,
		float radius)
{
	return smgr->addSphereMesh(name.data(), radius);
}

void NeoGraphics::setShadowColor(irr::video::SColor sColor)
{
	smgr->setShadowColor(sColor);
}

void NeoGraphics::InitialiseDefaultResourceGroups()
{
//以下代码搬运自cegui Sample
// set the default resource groups to be used
	CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
	CEGUI::Font::setDefaultResourceGroup("fonts");
	CEGUI::Scheme::setDefaultResourceGroup("schemes");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
	CEGUI::WindowManager::setDefaultResourceGroup("layouts");
	CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");
	CEGUI::AnimationManager::setDefaultResourceGroup("animations");

// setup default group for validation schemas
	CEGUI::XMLParser* parser = CEGUI::System::getSingleton().getXMLParser();
	if (parser->isPropertyPresent("SchemaDefaultResourceGroup"))
		parser->setProperty("SchemaDefaultResourceGroup", "schemas");
}

irr::scene::IAnimatedMesh* NeoGraphics::getMesh(std::string& file)
{
	return smgr->getMesh(core::stringc(file.c_str()));
}

irr::scene::IAnimatedMeshSceneNode* NeoGraphics::AddAnimatedMeshSceneNode(
		irr::scene::IAnimatedMesh* mesh, irr::scene::ISceneNode* parent, int id,
		const core::vector3df& position, const core::vector3df& rotation,
		const core::vector3df& scale, bool alsoAddIfMeshPointerZero)
{
	scene::IAnimatedMeshSceneNode*node = smgr->addAnimatedMeshSceneNode(mesh,
			parent, id, position, rotation, scale, alsoAddIfMeshPointerZero);
	return node;
}

irr::scene::IMeshSceneNode* NeoGraphics::AddMeshSceneNode(
		irr::scene::IMesh* mesh, irr::scene::ISceneNode* parent, int id,
		const core::vector3df& position, const core::vector3df& rotation,
		const core::vector3df& scale, bool alsoAddIfMeshPointerZero)
{
	return smgr->addMeshSceneNode(mesh, parent, id, position, rotation, scale,
			alsoAddIfMeshPointerZero);
}

irr::scene::ICameraSceneNode * NeoGraphics::AddCameraSceneNode(
		irr::scene::ISceneNode* parent, const core::vector3df& position,
		const core::vector3df& lookat, int id, bool makeActive)
{
	return smgr->addCameraSceneNode(parent, position, lookat, id, makeActive);
}

irr::scene::ICameraSceneNode * NeoGraphics::AddCameraSceneNodeMaya(
		irr::scene::ISceneNode* parent, float rotateSpeed, float zoomSpeed,
		float translationSpeed, signed int id, float distance, bool makeActive)
{
	return smgr->addCameraSceneNodeMaya(parent, rotateSpeed, zoomSpeed,
			translationSpeed, id, distance, makeActive);
}

irr::scene::ICameraSceneNode * NeoGraphics::AddCameraSceneNodeFPS(
		irr::scene::ISceneNode* parent, float rotateSpeed, float moveSpeed,
		int id, SKeyMap* keyMapArray, int keyMapSize, bool noVerticalMovement,
		int jumpSpeed, bool invertMouse, bool makeActive)
{
	return smgr->addCameraSceneNodeFPS(parent, rotateSpeed, moveSpeed, id,
			keyMapArray, keyMapSize, noVerticalMovement, jumpSpeed, invertMouse,
			makeActive);
}

irr::scene::ILightSceneNode * NeoGraphics::AddLightSceneNode(
		irr::scene::ISceneNode* parent, const core::vector3df& position,
		video::SColorf color, float radius, int id)
{
	return smgr->addLightSceneNode(parent, position, color, radius, id);
}

irr::scene::IBillboardSceneNode * NeoGraphics::AddBillboardSceneNode(
		irr::scene::ISceneNode* parent, const core::dimension2d<float>& size,
		const core::vector3df& position, int id, video::SColor colorTop,
		video::SColor colorBottom)
{
	return smgr->addBillboardSceneNode(parent, size, position, id, colorTop,
			colorBottom);
}

irr::scene::IParticleSystemSceneNode * NeoGraphics::AddParticleSystemSceneNode(
		bool withDefaultEmitter, irr::scene::ISceneNode* parent, int id,
		const core::vector3df& position, const core::vector3df& rotation,
		const core::vector3df& scale)
{
	return smgr->addParticleSystemSceneNode(withDefaultEmitter, parent, id,
			position, rotation, scale);
}

irr::scene::ISceneNode* NeoGraphics::AddEmptySceneNode(
		irr::scene::ISceneNode* parent, int id)
{
	return smgr->addEmptySceneNode(parent, id);
}

irr::scene::IDummyTransformationSceneNode* NeoGraphics::AddDummyTransformationSceneNode(
		irr::scene::ISceneNode* parent, int id)
{
	return smgr->addDummyTransformationSceneNode(parent, id);
}

irr::scene::ICameraSceneNode* NeoGraphics::GetActiveCamera()
{
	return smgr->getActiveCamera();
}

void NeoGraphics::SetActiveCamera(irr::scene::ICameraSceneNode*camera)
{
	smgr->setActiveCamera(camera);
}

bool NeoGraphics::loadScene(std::string file)
{
	return smgr->loadScene(file.c_str());
}

void NeoGraphics::ClearAllNodes()
{
	smgr->clear();
}

float NeoGraphics::getFps()
{
	return driver->getFPS();
}

std::string NeoGraphics::getTextFromOSClipboard()
{
	return std::string(device->getOSOperator()->getTextFromClipboard());
}

std::string NeoGraphics::getOperatingSystemVersion()
{
	return std::string(
			device->getOSOperator()->getOperatingSystemVersion().c_str());
}

irr::scene::ISceneNodeAnimator* NeoGraphics::createAxisAlignedRotateAnimator(
		u32 cycleTime, char align, int direction)
{
	scene::ISceneNodeAnimator* animator =
			new irr::scene::CSceneNodeAnimatorAxisAlignedRotate(cycleTime,
					align, direction);
	return animator;
}

irr::scene::IParticleAffector* NeoGraphics::CreateColourAffactorQ(
		const irr::video::SColor& targetColor0,
		const irr::video::SColor& targetColor1)
{
	return irr::scene::CreateColourAffactorQ(targetColor0, targetColor1);
}

irr::core::vector2di NeoGraphics::getPositionOnScreen(
		const irr::core::vector3df& position)
{
	return smgr->getSceneCollisionManager()->getScreenCoordinatesFrom3DPosition(
			position);
}

float NeoGraphics::getDeltaTime() const
{
	return m_delta_time;
}

gui::IGUIFont* NeoGraphics::LoadTTFFont(const std::string& filePath, int size)
{
	io::path p(filePath.data());
	return gui::CGUITTFont::createTTFont(guiEnv, p, size);
}

void NeoGraphics::ScaleTextureCoords(scene::IMesh* mesh,
		const core::vector2df& factor)
{
	smgr->getMeshManipulator()->scaleTCoords(mesh, factor);
}
