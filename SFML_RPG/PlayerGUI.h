#pragma once

#include "Player.h"

class Player;
class sf::RectangleShape;

class PlayerGUI
{
private:
	Player* player;

	sf::Font font;
	float hpBarMaxWidth;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;

	void initFont();
	void initHPBar();

public:
	PlayerGUI(Player* player);
	virtual ~PlayerGUI();

	//Functions
	void updateHPBar();
	void update(const float& dt);

	void renderHPBar(sf::RenderTarget & target);
	void render(sf::RenderTarget& target);
};

