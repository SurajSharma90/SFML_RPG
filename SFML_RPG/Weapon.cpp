#include "stdafx.h"
#include "Weapon.h"

void Weapon::initVariables()
{
	this->range = 20;
}

Weapon::Weapon(unsigned value, std::string texture_file)
	: Item(value)
{
	this->initVariables();

	if (!this->weapon_texture.loadFromFile(texture_file))
		std::cout << "ERROR::PLAYER::COULD NOT LOAD WEAPON TEXTURE::"<< texture_file << "\n";

	this->weapon_sprite.setTexture(this->weapon_texture);
}

Weapon::~Weapon()
{

}

//Accessors
const unsigned & Weapon::getRange() const
{
	return this->range;
}
