#ifndef ITEM_H
#define ITEM_H

class Item
{
private:

public:
	Item();
	virtual ~Item();

	//Function
	virtual Item* clone() = 0;
};

#endif //Item.h