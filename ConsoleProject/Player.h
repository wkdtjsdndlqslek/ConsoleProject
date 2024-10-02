#pragma once
#include"Unit.h"
#include<iostream>
#include<vector>
#include"Item.h"
using namespace std;

class InventoryScene;

class Player :public Unit
{
private:
	std::vector<Item> equippedItems;
public:
	Player();
	~Player();
public:
	void EarnMoney(int m);
	void EquippedItem(Item& item);//아이탬 장착 후 플레이어에게 적용
	void UnEquippedItem(Item& item);//아이탬 탈착 후 플레이어에게 적용
	void checkEquippedItem(Player* player, InventoryScene* inventory);
	void displayEquippedItems(const std::vector<Item>& equippedItems);
};

