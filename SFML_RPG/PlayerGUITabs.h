#pragma once

#include "Player.h"
#include "Gui.h"

class PlayerGUITabs
{
private:

	//Core
	sf::VideoMode& vm;
	sf::Font& font;
	Player& player;

	//Tabs

	//Character Tab
	sf::RectangleShape CharacterTabBack;
	sf::Text CharacterInfoText;

public:
	PlayerGUITabs(sf::VideoMode& vm, sf::Font& font, Player& player);
	virtual ~PlayerGUITabs();

	//Functions
	void initTabMenu();
	void initCharacterTab();
};

