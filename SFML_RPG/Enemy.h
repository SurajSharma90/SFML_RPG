#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy :
	public Entity
{
private:
	//Variables


	//Initializer functions
	void initVariables();
	void initAnimations();

public:
	Enemy(float x, float y, sf::Texture& texture_sheet);
	virtual ~Enemy();

	//Functions
	void updateAnimation(const float & dt);

	void update(const float & dt, sf::Vector2f& mouse_pos_view);
	void render(sf::RenderTarget & target, sf::Shader* shader, const bool show_hitbox);

};

#endif //!ENEMY_H
