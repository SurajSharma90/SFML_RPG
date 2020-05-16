#pragma once

#include "CharacterTab.h"

class PlayerGUITabs
{
private:
	
	CharacterTab characterTab;

	//Core
	sf::VideoMode& vm;
	sf::Font& font;
	Player& player;

	//Tabs

	//Character Tab
	

public:
	PlayerGUITabs(sf::VideoMode& vm, sf::Font& font, Player& player);
	virtual ~PlayerGUITabs();

	void update();
	void render(sf::RenderTarget& target);
};

