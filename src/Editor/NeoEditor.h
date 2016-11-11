/*
 * NeoEditor.h
 *
 *  Created on: 2016年11月6日
 *      Author: neo
 */

#ifndef SRC_EDITOR_NEOEDITOR_H_
#define SRC_EDITOR_NEOEDITOR_H_
#include "../game/stdafx.h"
#include <IEventReceiver.h>
class NeoGraphics;

class NeoEditor: public irr::IEventReceiver
{
public:
	enum OBJECT_OPS
	{
		EDITOR_SELECT = 1,
		EDITOR_MOVE,
		EDITOR_SCALE,
		EDITOR_ROTATE
	};
	virtual bool OnEvent(const SEvent& event);
	//===lua API===//
	static NeoEditor* getInstance();

	void CreateFileOpenDialog(const std::string& lua_callback);
	void ShowSelectionCursor(irr::scene::ISceneNode* node,bool visible = true);
	void Init();
	void CleanUp();
private:
	NeoEditor();
	virtual ~NeoEditor();
	void CreateSelectionCursor();
	static NeoEditor* _instance;
	std::string file_open_callback_lua;
	bool select_mode;
	OBJECT_OPS current_op;
	irr::scene::IAnimatedMeshSceneNode*m_arrows[3];
	irr::scene::ISceneNode* m_selection_cursor;
};

#endif /* SRC_EDITOR_NEOEDITOR_H_ */