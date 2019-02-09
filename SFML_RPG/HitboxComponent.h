#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H

class HitboxComponent
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	float offsetX;
	float offsetY;

public:
	HitboxComponent(sf::Sprite& sprite, 
		float offset_x, float offset_y, 
		float width, float height);
	virtual ~HitboxComponent();

	//Functions
	bool checkIntersect(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget& target);
};

#endif