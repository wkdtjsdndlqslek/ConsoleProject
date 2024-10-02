#pragma once
#include<iostream>
#include<vector>
#include"Item.h"
#include "Player.h"
#include "Choice.h"

class InventoryScene;
class LobbyScene;


class StoreScene
{
protected:
	std::vector<Item> sellingItems;
public:
	StoreScene();
public: 
	void runScene(Player* player, InventoryScene* inventory);

	void displaySellingItems(const std::vector<Item>& SellingItems) const;

	void storeInformation(Player* player, InventoryScene* inventory);

	void buyCheck(Player* player, InventoryScene* inventory, int selectItem);

	void buyItem(Player* player, InventoryScene* inventory);



};

