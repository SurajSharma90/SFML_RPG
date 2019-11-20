#include "stdafx.h"
#include "Bow.h"

Bow::Bow()
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
