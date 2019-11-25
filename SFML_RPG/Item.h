#ifndef ITEM_H
#define ITEM_H

enum ItemTypes {IT_DEFAULT = 0, IT_RANGEDWEAPON, IT_MELEEWEAPON};

class Item
{
private:
	void initVariables();

protected:
	//Variables
	short unsigned type;
	unsigned value;

public:
	Item(unsigned value);
	virtual ~Item();

	//Function
	virtual Item* clone() = 0;
};

#endif //Item.h