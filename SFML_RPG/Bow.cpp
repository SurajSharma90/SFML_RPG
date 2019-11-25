#include "stdafx.h"
#include "Bow.h"

Bow::Bow(unsigned value)
	:RangedWeapon(value)
{
	std::cout << "Bow" << "\n";
}

Bow::~Bow()
{
}

Bow * Bow::clone()
{
	return new Bow(*this);
}
