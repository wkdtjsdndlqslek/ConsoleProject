#include "InventoryScene.h"
#include"Item.h"
#include "Player.h"

void InventoryScene::runScene(Player* player, InventoryScene* inventory)
{
	displayGotItems(gotItems);
	EquipOrUnEquip(player,inventory);
	
}

void InventoryScene::EquippingItem(Player* player)
{
	std::cout << "장비할 아이템을 고르세요." << std::endl;
	displayGotItems(gotItems);
	if (gotItems.empty()){}
	else {
		int choice;
		while (1)
		{
			std::cin >> choice;
			if (choice >= 1 && choice <= gotItems.size())
			{
				Item& selectItem = gotItems[choice - 1];
				player->EquippedItem(selectItem);
				std::cout << "장착되었습니다." << std::endl;
				selectItem.SetEquipped(1);
				break;
			}
			else std::cout << "다시 입력해주세요." << std::endl;
		}
	}
}

void InventoryScene::UnEquippingItem(Player* player,InventoryScene* inventory)
{
	player->checkEquippedItem(player,inventory);
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
			if (item.isEquipped(item)==1)
			{
				std::cout << "<장착중> ";
			}
			std::cout << item.GetItemName() << " 공격력 : " << item.GetItemAtt() << std::endl;
		}
	}
}

void InventoryScene::EquipOrUnEquip(Player * player,InventoryScene* inventory)
{
	std::cout << "1.장비하기 2.탈착하기 3.로비" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		EquippingItem(player);
		break;
	case 2:
		UnEquippingItem(player, inventory);
		break;
	case 3:
		return;
	}
}

void InventoryScene::UnEquippedDisplayItem(Player* player, int choice)//private인 멤버변수 gotItems에 접근하기 위한 함수
{
	Item& selectItem = gotItems[choice - 1];
	player->UnEquippedItem(selectItem);
	std::cout << "탈착되었습니다." << std::endl;
	selectItem.SetEquipped(0);
}


