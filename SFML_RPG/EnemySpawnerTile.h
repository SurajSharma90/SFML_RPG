#ifndef ENEMYSPAWNERTILE_H
#define ENEMYSPAWNERTILE_H

#include "Tile.h"

class Tile;

class EnemySpawnerTile 
	: public Tile
{
private:
	int enemyType;
	int enemyAmount;
	int enemyTimeToSpawn;
	float enemyMaxDistance;

public:
	EnemySpawnerTile(int grid_x, int grid_y, float gridSizeF,
		const sf::Texture& texture, const sf::IntRect& texture_rect,
		int enemy_type, int enemy_amount, int enemy_time_to_spawn, float enemy_max_distance);
	virtual ~EnemySpawnerTile();

	virtual const std::string getAsString() const;

	void update();
	void render(sf::RenderTarget & target, sf::Shader* shader = NULL, const sf::Vector2f player_position = sf::Vector2f());
};

#endif //!ENEMYSPAWNERTTILE_H