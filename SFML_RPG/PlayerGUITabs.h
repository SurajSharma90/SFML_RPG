#pragma once

#include "CharacterTab.h"

enum PLAYER_TABS { CHARACTER_TAB = 0, INVENTORY_TAB };

class PlayerGUITabs
{
private:
	
	std::vector<Tab*> tabs;

	//Core
	sf::VideoMode& vm;
	sf::Font& font;
	Player& player;

	sf::Clock keyTimer;
	float keyTimeMax;

	//Tabs

	//Character Tab
	
	//Private functions
	void initTabs();
	void initKeyTime();

public:
	PlayerGUITabs(sf::VideoMode& vm, sf::Font& font, Player& player);
	virtual ~PlayerGUITabs();

	const bool getKeyTime();
	const bool tabsOpen();

	void toggleTab(const int tab_index);

	void update();
	void render(sf::RenderTarget& target);
};

