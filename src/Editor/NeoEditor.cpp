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
	NeoScript::getInstance()->ExecuteScriptedFunction("map_editor.onSelectionCursorMove");
}

const irr::core::vector3df& NeoEditor::getSelectionCursorPosition()
{
	return m_selection_cursor->getPosition();
}

irr::scene::ISceneNode* NeoEditor::getSelectedSceneNode()
{
	core::position2di cursor_position =
			NeoGraphics::getInstance()->getDevice()->getCursorControl()->getPosition();
	scene::ISceneNode *node =
			NeoGraphics::getInstance()->getIrrSceneManger()->getSceneCollisionManager()->getSceneNodeFromScreenCoordinatesBB(
					cursor_position, 0, true);
	return node;
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

	m_arrows[1] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addAnimatedMeshSceneNode(
					m_arrow_mesh[1]); //y axis(up)

	m_arrows[2] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addAnimatedMeshSceneNode(
					m_arrow_mesh[2]); //z axis*/
	m_arrows[2]->setRotation(core::vector3df(90, 0, 0));
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
