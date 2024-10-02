#pragma once
#include"Unit.h"
#include"Item.h"
#include<iostream>
#include<vector>
using namespace std;

class Item;

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
};

