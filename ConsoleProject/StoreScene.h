#pragma once
#include<iostream>
#include<vector>
#include "Item.h"

class Player;
class InventoryScene;

class StoreScene
{
protected:
	std::vector<Item> sellingItems;
	
public:
	StoreScene();

public: 
	void runScene(Player* player, InventoryScene* inventory);

	void displaySellingItems(const std::vector<Item>& sellingItems) const;

	void storeInformation(Player* player, InventoryScene* inventory);

	void buyCheck(Player* player, InventoryScene* inventory, int selectItem);

	void buyItem(Player* player, InventoryScene* inventory);

	void PrintScene();

};

