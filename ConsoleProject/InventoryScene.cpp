#include "InventoryScene.h"
#include <vector>
#include<iostream>

void InventoryScene::runScene(Player* player, InventoryScene* inventory)
{
	displayGotItems(gotItems);
	EquipOrUnEquip(player);
	
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
			std::cout << "장착되었습니다." << std::endl;
			selectItem.SetEquipped(1);
		}
		else std::cout << "다시 입력해주세요." << std::endl;
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
			int i = 1;
			std::cout << i++ << ". ";
			if (item.isEquipped(item))
			{
				std::cout << "<장착중> ";
			}
			std::cout << item.GetItemName() << " 공격력 : " << item.GetItemAtt() << std::endl;
		}
	}
}

void InventoryScene::UnEquippingItem(Player* player)
{
}

