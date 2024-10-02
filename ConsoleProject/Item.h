#pragma once
#include<iostream>
#include "Player.h"
#include "Choice.h"
class Item
{
protected:
	std::string itemName;
	int itemAtt;
	int price;
	bool equipped;
public:
	Item(const std::string& in, int ia, int p);
	~Item();
public:
	std::string GetItemName()const;
	int GetItemAtt()const;
	int GetPrice()const;
	bool isEquipped(const Item& item)const;
	void SetEquipped(bool value);
	
};

