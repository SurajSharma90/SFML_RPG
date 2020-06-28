#pragma once

#include "Player.h"
#include "Gui.h"

class Tab
{
protected:
	sf::VideoMode& vm;
	sf::Font& font;
	Player& player;
	bool hidden;

public:
	Tab(sf::VideoMode& vm, sf::Font& font, Player& player, bool hidden);
	virtual ~Tab();

	//Accessor
	const bool& getHidden() const;
	const bool& getOpen() const;
	void toggle();

	//Functions
	void hide();
	void show();

	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

