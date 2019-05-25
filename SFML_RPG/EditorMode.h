#ifndef EDITORMODE_H
#define EDITORMODE_H

#include "State.h"

class State;
class StateData;

class EditorMode
{
private:
	StateData* stateData;


public:
	EditorMode(StateData* state_data);
	virtual ~EditorMode();

	//Functions
	virtual void updateInput(const float& dt) = 0;
	virtual void updateGui(const float& dt) = 0;
	virtual void update(const float& dt) = 0;

	virtual void renderGui(sf::RenderTarget& target) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif //!EDITORMODE_H