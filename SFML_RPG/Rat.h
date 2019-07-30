#ifndef RAT_H
#define RAT_H

#include "Enemy.h"

class Rat :
	public Enemy
{
private:
	void initVariables();
	void initAnimations();

public:
	Rat(float x, float y, sf::Texture& texture_sheet);
	virtual ~Rat();

	//Functions
	void updateAnimation(const float & dt);
	void update(const float & dt, sf::Vector2f& mouse_pos_view);

	void render(sf::RenderTarget & target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox);
};

#endif //!RAT_H