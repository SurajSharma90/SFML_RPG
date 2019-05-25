#ifndef DEFAULTEDITORMODE_H
#define DEFAULTEDITORMODE_H

#include "EditorMode.h"

class State;
class StateData;
class EditorMode;

class DefaultEditorMode :
	public EditorMode
{
public:
	DefaultEditorMode(StateData* state_data);
	virtual ~DefaultEditorMode();
};

#endif //!DEFAULTEDITORMODE_H