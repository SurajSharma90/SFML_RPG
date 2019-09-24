#include "stdafx.h"
#include "Inventory.h"

//Private functions
void Inventory::initialize()
{
	this->capacity = 10;
	this->nrOfItems = 0;
	this->itemArray = new Item*[this->capacity];

	this->nullify();
}



void Inventory::expand()
{

}

void Inventory::nullify(const unsigned from)
{
	for (size_t i = from; i < this->capacity; i++)
	{
		this->itemArray = nullptr;
	}
}

void Inventory::freeMemory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArray[i];
	}

	delete[] this->itemArray;
}

//Constructors & Destructors
Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}
