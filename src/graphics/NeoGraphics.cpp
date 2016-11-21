/*
 * NeoGraphic.cpp
 *
 *  Created on: 2016年1月12日
 *      Author: neo
 */
#ifdef _WINDOWS
#pragma comment(lib, "Irrlicht.lib")
#endif

#include "NeoGraphics.h"
#include "CEGUI/RendererModules/Irrlicht/ResourceProvider.h"

NeoGraphics* NeoGraphics::_instance = NULL;
using namespace irr;
NeoGraphics::NeoGraphics()
{
	// TODO Auto-generated constructor stub
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
	//rp->setResourceGroupDirectory("topview","./sfx/UI/topViews/");
	//rp->setResourceGroupDirectory("commonUIElement","./sfx/UI/");
	//rp->setResourceGroupDirectory("overviewRoot","./maps/");
}

void NeoGraphics::RenderUI()
{
	//checkWindowResize();
	// calculate time elapsed
	irr::u32 currTime = device->getTimer()->getRealTime();
	// inject time pulse
	const float elapsed = static_cast<float>(currTime - d_lastTime) * 0.001f;
	CEGUI::System::getSingleton().injectTimePulse(elapsed);
	CEGUI::System::getSingleton().getDefaultGUIContext().injectTimePulse(
			elapsed);
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
	std::unordered_map<irr::scene::ISceneNode*, GameObject*>::iterator iter =
			list_go_bindings.find(node);
	if (iter != list_go_bindings.end())
	{
		return iter->second;
	}
	return NULL;
}

void NeoGraphics::BindSceneNodeToGameObject(irr::scene::ISceneNode*node,
		GameObject* go)
{
	list_go_bindings[node] = go;
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
	list_go_bindings.erase(node);
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
