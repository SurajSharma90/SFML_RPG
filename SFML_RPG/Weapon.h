#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon :
	public Item
{
private:
	void initVariables();

protected:
	sf::Texture weapon_texture;
	sf::Sprite weapon_sprite;

	int damageMin;
	int damageMax;
	unsigned range;

public:
	Weapon(unsigned value, std::string texture_file);
	virtual ~Weapon();

	//Accessors
	const unsigned& getRange() const;

	//Function
	virtual Item* clone() = 0;

	virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f center) = 0;
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr) = 0;
};

#endif
