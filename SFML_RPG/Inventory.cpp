#include "stdafx.h"
#include "Inventory.h"

//Private functions
void Inventory::initialize()
{
	this->nrOfItems = 0;
	this->itemArray = new Item*[this->capacity];

	this->nullify();
}

void Inventory::nullify(const unsigned from)
{
	for (size_t i = from; i < this->capacity; i++)
	{
		this->itemArray[i] = nullptr;
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
Inventory::Inventory(unsigned capacity)
{
	this->capacity = capacity;

	this->initialize();
}

Inventory::~Inventory()
{
	this->freeMemory();
}

//Accessors

const unsigned & Inventory::size() const
{
	return this->nrOfItems;
}

const unsigned & Inventory::maxSize() const
{
	return this->capacity;
}

//Modifiers

//Functions

void Inventory::clear()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArray[i];
	}

	this->nrOfItems = 0;

	this->nullify();
}

const bool Inventory::empty() const
{
	return this->nrOfItems == 0;
}

const bool Inventory::add(Item * item)
{
	if (this->nrOfItems < this->capacity)
	{
		this->itemArray[this->nrOfItems++] = item->clone();

		return true;
	}

	return false;
}

const bool Inventory::remove(const unsigned index)
{
	if (this->nrOfItems > 0)
	{
		if (index < 0 || index >= this->capacity)
			return false;

		delete this->itemArray[index];
		this->itemArray[index] = nullptr;
		--this->nrOfItems;

		return true;
	}

	return false;
}

const bool Inventory::saveToFile(const std::string fileName)
{
	return false;
}

const bool Inventory::loadFromFile(const std::string fileName)
{
	return false;
}
