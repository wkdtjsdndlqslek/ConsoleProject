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
	void EquippedItem(Item& item);//������ ���� �� �÷��̾�� ����
	void UnEquippedItem(Item& item);//������ Ż�� �� �÷��̾�� ����
	void checkEquippedItem(Player* player, InventoryScene* inventory);
	void displayEquippedItems(const std::vector<Item>& equippedItems);
};

