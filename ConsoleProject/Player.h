#pragma once
#include "Unit.h"
#include <iostream>
#include <vector>
#include "Item.h"
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
    void EquippedItem(Item& item);    //아이템 장착 시 플레이어의 변화
    void UnEquippedItem(Item& item);  //아이템 탈착 시 플레이어의 변화
    void checkEquippedItem(Player* player, InventoryScene* inventory, Item& item);
    void displayEquippedItems(const std::vector<Item>& equippedItem);
};