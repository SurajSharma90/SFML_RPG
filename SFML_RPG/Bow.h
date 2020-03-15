#ifndef BOW_H
#define BOW_H

#include "RangedWeapon.h"

class RangedWeapon;

class Bow :
	public RangedWeapon
{
private:

public:
	Bow(unsigned level, unsigned value, std::string texture_file);
	virtual ~Bow();

	virtual Bow* clone();

	virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f center);
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr);
};

#endif //!BOW_H
