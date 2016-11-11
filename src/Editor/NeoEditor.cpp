/*
 * NeoEditor.cpp
 *
 *  Created on: 2016年11月6日
 *      Author: neo
 */

#include "NeoEditor.h"

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
}

void NeoEditor::ShowSelectionCursor(irr::scene::ISceneNode* node, bool visible)
{
	if(!node)return;
	m_selection_cursor->setParent(node);
	m_selection_cursor->setPosition(core::vector3df(0,0,0));
	m_selection_cursor->setVisible(visible);
}

void NeoEditor::Init()
{
	CreateSelectionCursor();
}

void NeoEditor::CleanUp()
{
	NeoGraphics::getInstance()->CleanUp();
}

NeoEditor::~NeoEditor()
{
	// TODO 自动生成的析构函数存根
}

bool NeoEditor::OnEvent(const SEvent& event)
{
	return false;
}

void NeoEditor::CreateSelectionCursor()
{
	float length = 15.0f;
	irr::scene::IAnimatedMesh* x_arrow_mesh =
			NeoGraphics::getInstance()->getIrrSceneManger()->addArrowMesh(
					"selectionCursorX", video::SColor(255, 255, 0, 0),
					video::SColor(255, 255, 0, 0), 4, 8, length, 12, 0.7f,
					1.2f); //red
	irr::scene::IAnimatedMesh* y_arrow_mesh =
			NeoGraphics::getInstance()->getIrrSceneManger()->addArrowMesh(
					"selectionCursorY", video::SColor(255, 0, 0, 255),
					video::SColor(255, 0, 0, 255), 4, 8, length, 12, 0.7f,
					1.2f); //blue
	irr::scene::IAnimatedMesh* z_arrow_mesh =
			NeoGraphics::getInstance()->getIrrSceneManger()->addArrowMesh(
					"selectionCursorZ", video::SColor(255, 0, 255, 0),
					video::SColor(255, 0, 255, 0), 4, 8, length, 12, 0.7f,
					1.2f); //green

	m_arrows[0] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addAnimatedMeshSceneNode(
					x_arrow_mesh); //x axis
	m_arrows[0]->setRotation(core::vector3df(0, 0, -90));

	m_arrows[1] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addAnimatedMeshSceneNode(
					y_arrow_mesh); //y axis(up)

	m_arrows[2] =
			NeoGraphics::getInstance()->getIrrSceneManger()->addAnimatedMeshSceneNode(
					z_arrow_mesh); //z axis*/
	m_arrows[2]->setRotation(core::vector3df(90, 0, 0));
	//cursor controller root
	m_selection_cursor=NeoGraphics::getInstance()->AddEmptySceneNode();
	for (int i = 0; i < 3; i++)
	{
		m_arrows[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		m_arrows[i]->setMaterialFlag(irr::video::EMF_ZBUFFER, false);
		m_selection_cursor->addChild(m_arrows[i]);
	}

	m_selection_cursor->setVisible(false);

}
