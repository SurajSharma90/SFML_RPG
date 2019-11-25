#ifndef SWORD_H
#define SWORD_H

#include "MeleeWeapon.h"

class MeleeWeapon;

class Sword :
	public MeleeWeapon
{
private:

public:
	Sword(unsigned value);
	virtual ~Sword();

	virtual Sword* clone();

	virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f center);
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr);
};

#endif //!SWORD_H