#include "stdafx.h"
#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(unsigned level, unsigned value, std::string texture_file)
	: Weapon(level, value, texture_file)
{
	this->type = ItemTypes::IT_RANGEDWEAPON;
}

RangedWeapon::~RangedWeapon()
{

}

void RangedWeapon::generate(const unsigned levelMin, const unsigned levelMax)
{

}
