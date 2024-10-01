#include "InventoryScene.h"
#include <vector>
#include<iostream>

void InventoryScene::runScene(Player* player)
{
	EquippingItem(player);
}

void InventoryScene::EquippingItem(Player* player)
{
	displayGotItems(gotItems);
	if (gotItems.empty()){}
	else {
		int choice;
		std::cin >> choice;
		if (choice >= 1 && choice <= gotItems.size())
		{
			Item& selectItem = gotItems[choice - 1];
			player->EquippedItem(selectItem);
		}
	}
}

void InventoryScene::GotItem(Item& item)
{
	gotItems.push_back(item);
}

void InventoryScene::displayGotItems(const std::vector<Item>& gotItems)const
{
	if (gotItems.empty())
	{
		std::cout << "장착 가능한 아이템 없음" << std::endl;
		return;
	}
	else {
		for (const auto& item : gotItems)
		{
			int i = 0;
			std::cout << i++ << ". ";
			if (item.isEquipped(item))
			{
				std::cout << "<장착중> ";
			}
			std::cout << item.GetItemName() << " 공격력 : " << item.GetItemAtt() << std::endl;
		}
	}
}

void InventoryScene::UnEquippingItem()
{
}

