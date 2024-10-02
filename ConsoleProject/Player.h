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
	void EquippedItem(Item& item);//아이탬 장착 후 플레이어에게 적용
	void UnEquippedItem(Item& item);//아이탬 탈착 후 플레이어에게 적용
};

