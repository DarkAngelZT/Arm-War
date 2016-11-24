/*
 * NeoEditor.cpp
 *
 *  Created on: 2016年11月6日
 *      Author: neo
 */

#include "NeoEditor.h"
#include "../game/NeoEventHandler.h"
#include <vector>

using namespace irr;
using namespace irr::core;
NeoEditor* NeoEditor::_instance = NULL;

NeoEditor::NeoEditor()
{
	// TODO 自动生成的构造函数存根

}

NeoEditor* NeoEditor::getInstance()
{
	if (_instance == NULL)
		_instance = new NeoEditor();
	return _instance;
}

void NeoEditor::CreateFileOpenDialog(const std::string& lua_callback)
{
	NeoGraphics::getInstance()->getGuiEnv()->addFileOpenDialog(
			L"Please choose a file.", true, 0, -1, true);
	file_open_callback_lua = lua_callback;
}

void NeoEditor::ShowSelectionCursor(bool visible,
		const irr::core::vector3df& position)
{
	m_selection_cursor->setPosition(position);
	m_selection_cursor->setVisible(visible);
}

void NeoEditor::Init()
{
	static_cast<NeoEventHandler*>(NeoGraphics::getInstance()->getDevice()->getEventReceiver())->AddAdditionalEventHandler(
			this);
	CreateSelectionCursor();
}

void NeoEditor::CleanUp()
{
	m_selection_cursor->remove();
	for (int i = 0; i < 3; i++)
	{
		NeoGraphics::getInstance()->getIrrSceneManger()->getMeshCache()->removeMesh(
				m_arrow_mesh[i]);
	}
	NeoGraphics::getInstance()->CleanUp();
	static_cast<NeoEventHandler*>(NeoGraphics::getInstance()->getDevice()->getEventReceiver())->RemoveAddtionalEventHandler(
			this);
}

NeoEditor::~NeoEditor()
{
	// TODO 自动生成的析构函数存根
}

bool NeoEditor::OnEvent(const SEvent& event)
{
	switch (event.EventType)
	{
	case EET_GUI_EVENT:
	{
		switch (event.GUIEvent.EventType)
		{
		case irr::gui::EGET_FILE_SELECTED:
		{
			//file open dialog call back
			gui::IGUIFileOpenDialog* dialog =
					(gui::IGUIFileOpenDialog*) event.GUIEvent.Caller;
			std::wstring ws_path(dialog->getFileName());
			std::string path(ws_path.begin(), ws_path.end());
			std::vector<std::string> param;
			param.push_back(path);
			if (!file_open_callback_lua.empty())
				NeoScript::getInstance()->ExecuteScriptedFunction(
						file_open_callback_lua, param);
			break;
		}
		case irr::gui::EGET_FILE_CHOOSE_DIALOG_CANCELLED:
		{
			if (!file_open_callback_lua.empty())
				NeoScript::getInstance()->ExecuteScriptedFunction(
						file_open_callback_lua);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
	return false;
}

void NeoEditor::setSelectionCursorPosition(const irr::core::vector3df& position)
{
	m_selection_cursor->setPosition(position);
	NeoScript::getInstance()->ExecuteScriptedFunction(
			"map_editor.onSelectionCursorMove");
}

const irr::core::vector3df& NeoEditor::getSelectionCursorPosition()
{
	return m_selection_cursor->getPosition();
}

irr::scene::ISceneNode* NeoEditor::getSelectedSceneNode()
{
	irr::scene::ISceneCollisionManager* colmgr =
			NeoGraphics::getInstance()->getIrrSceneManger()->getSceneCollisionManager();
	line3d<f32> raytrace =
			colmgr->getRayFromScreenCoordinates(
					NeoGraphics::getInstance()->getDevice()->getCursorControl()->getPosition());
	core::vector3df outCollisionPoint;
	core::triangle3df outTriangle;
	scene::ISceneNode* outNode;
	//detect cursor first
	for (int i = 0; i < 3; i++)
	{
		if (colmgr->getCollisionPoint(raytrace,
				m_arrows[i]->getTriangleSelector(), outCollisionPoint,
				outTriangle, outNode))
		{
			return outNode;
		}
	}
	//if not the cursor, then comes normal scene node
	outNode = colmgr->getSceneNodeAndCollisionPointFromRay(raytrace,
			outCollisionPoint, outTriangle);
	return outNode;
}

bool NeoEditor::isSelectionCursor(irr::scene::ISceneNode* node)
{
	for (int i = 0; i < 3; i++)
	{
		if (m_arrows[i] == node)
		{
			return true;
		}
	}
	return false;
}

void NeoEditor::setSelectionCursorScale(float scale)
{
	m_selection_cursor->setScale(core::vector3df(scale));
}

int NeoEditor::getSelectedCursorIndex(irr::scene::ISceneNode* node)
{
	for (int i = 0; i < 3; i++)
	{
		if (m_arrows[i] == node)
		{
			return i;
		}
	}
	return -1;
}

void NeoEditor::setSceneNodeTriangleSelector(irr::scene::ISceneNode* node,
		const std::string& type)
{
	if (!node)
		return;
	scene::ITriangleSelector* selector;
	scene::ISceneManager* smgr =
			NeoGraphics::getInstance()->getIrrSceneManger();
	irr::scene::ESCENE_NODE_TYPE node_type = node->getType();
	if (type == "normal")
	{
		switch (node_type)
		{
		case irr::scene::ESNT_ANIMATED_MESH:
		{
			selector = smgr->createTriangleSelector(
					static_cast<scene::IAnimatedMeshSceneNode*>(node));
			break;
		}
		case scene::ESNT_MESH:
		case scene::ESNT_CUBE:
		case scene::ESNT_SPHERE:
		{
			selector = smgr->createTriangleSelector(
					static_cast<scene::IMeshSceneNode*>(node)->getMesh(), node);
			break;
		}
		default:
			selector = smgr->createTriangleSelectorFromBoundingBox(node);
			break;
		}
		node->setTriangleSelector(selector);
		selector->drop();
	}
	else if (type == "octree")
	{
		switch (node_type)
		{
		case scene::ESNT_ANIMATED_MESH:
			selector =
					smgr->createOctreeTriangleSelector(
							static_cast<scene::IAnimatedMeshSceneNode*>(node)->getMesh(),
							node, 128);
			break;
		case scene::ESNT_MESH:
		case scene::ESNT_CUBE:
		case scene::ESNT_SPHERE:
		case scene::ESNT_OCTREE:
			selector = smgr->createOctreeTriangleSelector(
					static_cast<scene::IMeshSceneNode*>(node)->getMesh(), node,
					128);
			break;
		default:
			return;
		}

		node->setTriangleSelector(selector);
		selector->drop();
	}
}

void NeoEditor::setMeshNodeColor(irr::scene::IMeshSceneNode* node, irr::video::SColor& color)
{
	for(unsigned i=0;i<node->getMesh()->getMeshBufferCount();i++)
	{
		int count=node->getMesh()->getMeshBuffer(i)->getVertexCount();
		scene::IMeshBuffer*buffer=node->getMesh()->getMeshBuffer(i);
		video::E_VERTEX_TYPE type=buffer->getVertexType();
		if(type==video::EVT_STANDARD)
		{
			video::S3DVertex*varray = static_cast<video::S3DVertex*>(buffer->getVertices());
			for(int j=0;j<count;j++)
			{
				varray[j].Color=color;
			}
		}
	}
}

void NeoEditor::CreateSelectionCursor()
{
	float length = 10.0f;
	m_arrow_mesh[0] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addArrowMesh(
					"selectionCursorX", video::SColor(255, 255, 0, 0),
					video::SColor(255, 255, 0, 0), 4, 8, length, 8, 0.4f, 1.0f); //red
	m_arrow_mesh[1] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addArrowMesh(
					"selectionCursorY", video::SColor(255, 0, 0, 255),
					video::SColor(255, 0, 0, 255), 4, 8, length, 8, 0.4f, 1.0f); //blue
	m_arrow_mesh[2] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addArrowMesh(
					"selectionCursorZ", video::SColor(255, 0, 255, 0),
					video::SColor(255, 0, 255, 0), 4, 8, length, 8, 0.4f, 1.0f); //green

	m_arrows[0] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addAnimatedMeshSceneNode(
					m_arrow_mesh[0]); //x axis
	m_arrows[0]->setRotation(core::vector3df(0, 0, -90));
	m_arrows[0]->setPosition(vector3df(1, 0, 0));
	scene::ITriangleSelector* selector_x =
			NeoGraphics::getInstance()->getIrrSceneManger()->createTriangleSelector(
					m_arrows[0]);
	m_arrows[0]->setTriangleSelector(selector_x);
	selector_x->drop();

	m_arrows[1] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addAnimatedMeshSceneNode(
					m_arrow_mesh[1]); //y axis(up)
	m_arrows[1]->setPosition(vector3df(0, 1, 0));
	scene::ITriangleSelector* selector_y =
			NeoGraphics::getInstance()->getIrrSceneManger()->createTriangleSelector(
					m_arrows[1]);
	m_arrows[1]->setTriangleSelector(selector_y);
	selector_y->drop();

	m_arrows[2] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addAnimatedMeshSceneNode(
					m_arrow_mesh[2]); //z axis*/
	m_arrows[2]->setRotation(core::vector3df(90, 0, 0));
	m_arrows[2]->setPosition(vector3df(0, 0, 1));
	scene::ITriangleSelector* selector_z =
			NeoGraphics::getInstance()->getIrrSceneManger()->createTriangleSelector(
					m_arrows[2]);
	m_arrows[2]->setTriangleSelector(selector_z);
	selector_z->drop();
	//cursor controller root
	m_selection_cursor = NeoGraphics::getInstance()->AddEmptySceneNode();
	for (int i = 0; i < 3; i++)
	{
		m_arrows[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		m_arrows[i]->setMaterialFlag(irr::video::EMF_ZBUFFER, false);
		m_arrows[i]->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
		m_selection_cursor->addChild(m_arrows[i]);
	}

	m_selection_cursor->setVisible(false);
}
