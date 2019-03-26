#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "Entity.h"

class Tile;
class Entity;

class TileMap
{
private:
	void clear();

	float gridSizeF;
	unsigned gridSizeU;
	sf::Vector2u maxSizeWorldGrid;
	sf::Vector2f maxSizeWorldF;
	unsigned layers;
	std::vector< std::vector< std::vector< Tile* > > > map;
	std::string textureFile;
	sf::Texture tileSheet;
	sf::RectangleShape collisionBox;

public:
	TileMap(float gridSize, unsigned width, unsigned height, std::string texture_file);
	virtual ~TileMap();

	//Accessors
	const sf::Texture* getTileSheet() const;

	//Functions
	void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect, const bool& collision, const short& type);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);
	void saveToFile(const std::string file_name);
	void loadFromFile(const std::string file_name);

	void updateCollision(Entity* entity);

	void update();
	void render(sf::RenderTarget& target, Entity* entity = NULL);


};

#endif