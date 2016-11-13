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
		EDITOR_SELECT = 1, EDITOR_MOVE, EDITOR_SCALE, EDITOR_ROTATE
	};
	virtual bool OnEvent(const SEvent& event);
	//===lua API===//
	static NeoEditor* getInstance();

	void CreateFileOpenDialog(const std::string& lua_callback);
	void ShowSelectionCursor(bool visible = true,
			const irr::core::vector3df& position = irr::core::vector3df(0, 0,
					0));
	void setSelectionCursorPosition(const irr::core::vector3df& position);
	const irr::core::vector3df& getSelectionCursorPosition();
	irr::scene::ISceneNode* getSelectedSceneNode();
	const irr::core::position2di& getMouseMoveDelta();
	bool isSelectionCursor(irr::scene::ISceneNode*node);
	void Init();
	void CleanUp();
private:
	NeoEditor();
	virtual ~NeoEditor();
	void CreateSelectionCursor();
	inline void UpdateCursorPosInfo(const SEvent& event)
	{
		core::position2di pos(event.MouseInput.X, event.MouseInput.Y);
		cursor_move_delta = pos - old_cursor_position;
		old_cursor_position = pos;
	}
	static NeoEditor* _instance;
	std::string file_open_callback_lua;
	bool select_mode;
	OBJECT_OPS current_op;
	irr::scene::IAnimatedMeshSceneNode*m_arrows[3];
	irr::scene::ISceneNode* m_selection_cursor;
	core::position2di old_cursor_position;
	core::position2di cursor_move_delta;
};

#endif /* SRC_EDITOR_NEOEDITOR_H_ */
