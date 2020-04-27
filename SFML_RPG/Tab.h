#pragma once

#include "Player.h"
#include "Gui.h"

class Tab
{
protected:
	sf::VideoMode& vm;
	sf::Font& font;
	Player& player;

public:
	Tab(sf::VideoMode& vm, sf::Font& font, Player& player);
	virtual ~Tab();

	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target) = 0;
};

