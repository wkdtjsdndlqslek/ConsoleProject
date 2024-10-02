#pragma once
#include<vector>
#include<iostream>
#include"Item.h"
#include"Player.h"

class LobbyScene;

class InventoryScene
{
protected:
	std::vector<Item> gotItems;
public:
	void runScene(Player* player, InventoryScene* inventory);
	void EquippingItem(Player* player);
	void GotItem(Item& item);
	void displayGotItems(const std::vector<Item>& gotItems)const;
	void UnEquippingItem(Player* player);
	void EquipOrUnEquip(Player* player, InventoryScene* inventory)
	{
		std::cout << "1.��� ���� 2.��� Ż�� 3.�κ�" << std::endl;
		int choice;
		std::cin >> choice;
		switch(choice)
		{
		case 1:
			EquippingItem(player);
		case 2:
			UnEquippingItem(player);
		default:
			std::cout << "�ٽ� �Է����ּ���." << std::endl;
	}
};