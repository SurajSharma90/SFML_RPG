#pragma once

#include"Item.h"

class Inventory
{
private:
	Item** itemArray;
	unsigned nrOfItems;
	unsigned capacity;

	//Private functions
	void initialize();
	void expand();
	void nullify(const unsigned from = 0);
	void freeMemory();

public:
	Inventory();
	virtual ~Inventory();
};

