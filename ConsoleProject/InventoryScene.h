#pragma once
#include<vector>
#include<iostream>
#include "Item.h"

class Player;
class LobbyScene;
class InventoryScene
{
protected:
	std::vector<Item> gotItems;
public:
	void runScene(Player* player, InventoryScene* inventory);
	void EquippingItem(Player* player, Item& item);
	void displayGotItems(const std::vector<Item>& gotItems)const;
	void UnEquippingItem(Player* player, InventoryScene* inventory, Item& item);
	void GotItem(Item& item);
	void EquipOrUnEquip(Player* player,InventoryScene* inventory);
	void UnEquippedDisplayItem(Player* player, Item& item);
	int PrintMenu(Player* player, InventoryScene* inventory);
	void PrintScene();
	int GetGotItemsSize();

};

