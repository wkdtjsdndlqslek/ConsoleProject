#pragma once
#include<iostream>
class Item
{
protected:
	std::string itemName;
	int itemAtt;
	int price;
public:
	Item(std::string in, int ia, int p);
	~Item();
};

