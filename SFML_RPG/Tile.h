#ifndef TILE_H
#define TILE_H

enum TileTypes {DEFAULT = 0, DAMAGING};

class Tile
{
private:

protected:
	sf::RectangleShape shape;
	bool collision;
	short type;

public:
	Tile();
	Tile(float x, float y, float gridSizeF, const sf::Texture& texture, const sf::IntRect& texture_rect,
		bool collision = false, short type = TileTypes::DEFAULT);
	virtual ~Tile();

	//Functions
	const std::string getAsString() const;

	void update();
	void render(sf::RenderTarget& target);
};

#endif