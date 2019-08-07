#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "EnemySpawnerTile.h"

class Entity;
class EnemySpawnerTile;

class Enemy :
	public Entity
{
private:
	//Variables
	//EnemySpawner& enemySpawner;

	//Initializer functions
	virtual void initVariables() = 0;
	virtual void initAnimations() = 0;

public:
	Enemy();
	virtual ~Enemy();

	//Functions
	virtual void updateAnimation(const float & dt) = 0;

	virtual void update(const float & dt, sf::Vector2f& mouse_pos_view) = 0;
	virtual void render(sf::RenderTarget & target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f(), const bool show_hitbox = false) = 0;
};

#endif //!ENEMY_H
