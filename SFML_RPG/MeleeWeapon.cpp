#include "stdafx.h"

#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(unsigned value)
	: Item(value)
{
	this->type = ItemTypes::IT_MELEEWEAPON;
}

MeleeWeapon::~MeleeWeapon()
{

}
