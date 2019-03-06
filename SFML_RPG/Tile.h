#ifndef TILE_H
#define TILE_H

class Tile
{
private:

protected:
	sf::RectangleShape shape;

public:
	Tile();
	Tile(float x, float y, float gridSizeF, sf::Texture& texture);
	virtual ~Tile();

	//Functions
	void update();
	void render(sf::RenderTarget& target);
};

#endif