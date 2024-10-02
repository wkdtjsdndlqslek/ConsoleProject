#pragma once
#include<vector>
#include<iostream>
#include "Item.h"

class Player;

class InventoryScene
{
protected:
	std::vector<Item> gotItems;
public:
	void runScene(Player* player, InventoryScene* inventory);
	void EquippingItem(Player* player);
	void displayGotItems(const std::vector<Item>& gotItems)const;
	void UnEquippingItem(Player* player, InventoryScene* inventory);
	void GotItem(Item& item);
	void EquipOrUnEquip(Player* player,InventoryScene* inventory);
	void UnEquippedDisplayItem(Player* player, int choice);
};

