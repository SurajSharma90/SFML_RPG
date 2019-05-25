#include "stdafx.h"
#include "EditorMode.h"

EditorMode::EditorMode(StateData* state_data, TileMap* tile_map, sf::Font* font)
	: stateData(state_data), tileMap(tile_map), font(font)
{

}

EditorMode::~EditorMode()
{

}
