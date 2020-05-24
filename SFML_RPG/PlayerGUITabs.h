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

	sf::Clock keyTimer;
	float keyTimeMax;

	//Tabs

	//Character Tab
	
	//Private functions
	void initKeyTime();

public:
	PlayerGUITabs(sf::VideoMode& vm, sf::Font& font, Player& player);
	virtual ~PlayerGUITabs();

	const bool getKeyTime();
	const bool tabsOpen();

	void update();
	void render(sf::RenderTarget& target);
};

