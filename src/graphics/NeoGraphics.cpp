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
	w = NeoScript::GetInstance()->GetScriptGlobalValue_int(
			"ApplicationSettings.resolution.width");
	h = NeoScript::GetInstance()->GetScriptGlobalValue_int(
			"ApplicationSettings.resolution.height");
	fscr = NeoScript::GetInstance()->GetScriptGlobalValue_bool(
			"ApplicationSettings.fullscreen");
	caption = NeoScript::GetInstance()->GetScriptGlobalValue_string(
			"ApplicationSettings.caption");
	device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(w, h), 16,
			fscr, true, false, 0);
	//convert to wstring
	std::wstring ws_caption;
	ws_caption.assign(caption.begin(), caption.end());
	device->setWindowCaption(ws_caption.c_str());
	device->getCursorControl()->setVisible(false);
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guiEnv = device->getGUIEnvironment();
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

NeoGraphics* NeoGraphics::GetInstance()
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

const video::IVideoDriver* NeoGraphics::getDriver()
{
	return driver;
}

const gui::IGUIEnvironment* NeoGraphics::getGuiEnv()
{
	return guiEnv;
}

const scene::ISceneManager* NeoGraphics::getSmgr()
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
	const float elapsed = static_cast<float>(currTime - d_lastTime) / 1000.0f;
	CEGUI::System::getSingleton().injectTimePulse(elapsed);
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

CEGUI::IrrlichtRenderer* NeoGraphics::GetUIRenderer() const
{
	return uiRenderer;
}

GameObject* NeoGraphics::GetAttachedGameObject(int idx)
{
	std::unordered_map<int, GameObject*>::iterator iter = list_go_bindings.find(
			idx);
	if (iter != list_go_bindings.end())
	{
		return iter->second;
	}
	return NULL;
}

void NeoGraphics::BindSceneNodeToGameObject(int idx, GameObject* go)
{
	list_go_bindings[idx] = go;
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

int NeoGraphics::GetMesh(std::string& file)
{
	scene::IMesh* mesh = smgr->getMesh(core::stringc(file.c_str()));
	std::vector<scene::IMesh*>::iterator findit = std::find(list_mesh.begin(),
			list_mesh.end(), mesh);
	if (findit != list_mesh.end())
	{
		list_mesh.push_back(mesh);
		return list_mesh.size() - 1;
	}
	else
	{
		return findit - list_mesh.begin();
	}
}

int NeoGraphics::AddAnimatedMeshSceneNode(int meshidx, int parentIdx, int id,
		const core::vector3df& position, const core::vector3df& rotation,
		const core::vector3df& scale, bool alsoAddIfMeshPointerZero)
{
	scene::IMesh*mesh = GetMesh(meshidx);
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addAnimatedMeshSceneNode(
			static_cast<scene::IAnimatedMesh*>(mesh), parentNode, id, position,
			rotation, scale, alsoAddIfMeshPointerZero);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddMeshSceneNode(int meshIdx, int parentIdx, int id,
		const core::vector3df& position, const core::vector3df& rotation,
		const core::vector3df& scale, bool alsoAddIfMeshPointerZero)
{
	scene::IMesh*mesh = GetMesh(meshIdx);
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addMeshSceneNode(mesh, parentNode, id,
			position, rotation, scale, alsoAddIfMeshPointerZero);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddCameraSceneNode(int parentIdx,
		const core::vector3df& position, const core::vector3df& lookat, int id,
		bool makeActive)
{
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addCameraSceneNode(parentNode, position,
			lookat, id, makeActive);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddCameraSceneNodeMaya(int parentIdx, float rotateSpeed,
		float zoomSpeed, float translationSpeed, signed int id, float distance,
		bool makeActive)
{
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addCameraSceneNodeMaya(parentNode,
			rotateSpeed, zoomSpeed, translationSpeed, id, distance, makeActive);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddCameraSceneNodeFPS(int parentIdx, float rotateSpeed,
		float moveSpeed, int id, SKeyMap* keyMapArray, int keyMapSize,
		bool noVerticalMovement, int jumpSpeed, bool invertMouse,
		bool makeActive)
{
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addCameraSceneNodeFPS(parentNode,
			rotateSpeed, moveSpeed, id, keyMapArray, keyMapSize,
			noVerticalMovement, jumpSpeed, invertMouse, makeActive);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddLightSceneNode(int parentIdx,
		const core::vector3df& position, video::SColorf color, float radius,
		int id)
{
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addLightSceneNode(parentNode, position,
			color, radius, id);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddBillboardSceneNode(int parentIdx,
		const core::dimension2d<float>& size, const core::vector3df& position,
		int id, video::SColor colorTop, video::SColor colorBottom)
{
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addBillboardSceneNode(parentNode, size,
			position, id, colorTop, colorBottom);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddParticleSystemSceneNode(bool withDefaultEmitter,
		int parentIdx, int id, const core::vector3df& position,
		const core::vector3df& rotation, const core::vector3df& scale)
{
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addParticleSystemSceneNode(
			withDefaultEmitter, parentNode, id, position, rotation, scale);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddEmptySceneNode(int parentIdx, s32 id)
{
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addEmptySceneNode(parentNode, id);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::AddDummyTransformationSceneNode(int parentIdx, s32 id)
{
	scene::ISceneNode*parentNode = NULL;
	if (parentIdx > 0)
		parentNode = GetSceneNode(parentIdx);
	scene::ISceneNode*node = smgr->addDummyTransformationSceneNode(parentNode,
			id);
	if (node != NULL)
	{
//		std::vector<scene::ISceneNode*>::iterator findit = std::find(
//				list_scene_node.begin(), list_scene_node.end(), node);
//		if (findit == list_scene_node.end())
//		{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
//		}
//		else
//		{
//			return findit - list_scene_node.begin();
//		}
	}
	return -1;
}

int NeoGraphics::GetActiveCamera()
{
	scene::ISceneNode*node = smgr->getActiveCamera();
	if (node != NULL)
	{
		std::vector<scene::ISceneNode*>::iterator findit = std::find(
				list_scene_node.begin(), list_scene_node.end(), node);
		if (findit == list_scene_node.end())
		{
			list_scene_node.push_back(node);
			return list_scene_node.size() - 1;
		}
		else
		{
			return findit - list_scene_node.begin();
		}
	}
	return -1;
}

void NeoGraphics::SetActiveCamera(int cameraIdx)
{
	scene::ISceneNode* node = GetSceneNode(cameraIdx);
	if (node->getType() == scene::ESNT_CAMERA
			|| node->getType() == scene::ESNT_CAMERA_FPS
			|| node->getType() == scene::ESNT_CAMERA_MAYA)
	{
		smgr->setActiveCamera(static_cast<scene::ICameraSceneNode*>(node));
	}
}

bool NeoGraphics::loadScene(std::string file)
{
	return smgr->loadScene(file.c_str());
}

scene::ISceneNode* NeoGraphics::GetSceneNode(int idx)
{
	return list_scene_node[idx];
}

int NeoGraphics::RegisterSceneNode(irr::scene::ISceneNode* node)
{
	std::vector<scene::ISceneNode*>::iterator findit = std::find(
			list_scene_node.begin(), list_scene_node.end(), node);
	if (findit != list_scene_node.end())
	{
		return findit - list_scene_node.begin();
	}
	else
	{
		list_scene_node.push_back(node);
		return list_scene_node.size() - 1;
	}
}

void NeoGraphics::RemoveSceneNode(int index)
{
	if (index < list_scene_node.size())
	{
		scene::ISceneNode* node = list_scene_node[index];
		node->remove();
		list_scene_node[index] = NULL;
		list_go_bindings.erase(index);
	}
}

void NeoGraphics::ClearNodes()
{
	for (std::vector<scene::ISceneNode*>::iterator iter =
			list_scene_node.begin(); iter != list_scene_node.end(); iter++)
	{
		(*iter)->remove();
	}
	list_scene_node.clear();
}

scene::IMesh* NeoGraphics::GetMesh(int idx)
{
	if (idx > 0)
		return list_mesh[idx];
	else
		return NULL;
}

int NeoGraphics::getFps()
{
	return driver->getFPS();
}
