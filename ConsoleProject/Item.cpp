#include "Item.h"


Item::Item(const std::string& in, int ia, int p):itemName(in),itemAtt(ia),price(p),equipped(false)
{
}

Item::~Item()
{
}

std::string Item::GetItemName()const
{
	return itemName;
}

int Item::GetItemAtt()const
{
	return itemAtt;
}

int Item::GetPrice()const
{
	return price;
}

bool Item::isEquipped(const Item& item) const
{
	return equipped;
}

void Item::SetEquipped(bool value)
{
	equipped = value;
}
