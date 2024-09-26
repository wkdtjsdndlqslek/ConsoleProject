#include "Item.h"

Item::Item(std::string in, int ia, int p):itemName(in),itemAtt(ia),price(p)
{
}

Item::~Item()
{
}

std::string Item::GetItemName()
{
	return itemName;
}

int Item::GetItemAtt()
{
	return itemAtt;
}

int Item::GetPrice()
{
	return price;
}
