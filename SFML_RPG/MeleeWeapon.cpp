#include "stdafx.h"

#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(unsigned damageMin, unsigned damageMax, unsigned range, 
	unsigned value, 
	std::string texture_file)
	: Weapon(damageMin, damageMax, range, value, texture_file)
{
	this->type = ItemTypes::IT_MELEEWEAPON;
}

MeleeWeapon::~MeleeWeapon()
{

}
