#pragma once
#include<vector>
#include<iostream>
#include"Item.h"
#include"Player.h"

class InventoryScene
{
protected:
	std::vector<Item> gotItems;
public:
	void runScene(Player* player);
	void EquippingItem(Player* player);
	void GetItem(Item& item);
	void displayGotItems(const std::vector<Item>& gotItems)const;
	void UnEquippingItem();
};

