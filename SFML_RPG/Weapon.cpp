#include "stdafx.h"
#include "Weapon.h"

void Weapon::initVariables()
{
	this->range = 20;
	this->damageMin = 1;
	this->damageMax = 2;
}

void Weapon::initCooldown()
{
	this->cooldown = 0.f;
	this->cooldownMax = 10.f;
	this->cooldownIteration = 1.f;
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

const unsigned & Weapon::getDamageMin() const
{
	return this->damageMin;
}

const unsigned & Weapon::getDamageMax() const
{
	return this->damageMax;
}

//Accessors
const unsigned & Weapon::getRange() const
{
	return this->range;
}
