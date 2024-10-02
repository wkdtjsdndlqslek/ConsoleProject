#include "Player.h"
#include "Unit.h"
#include "Item.h"
#include "InventoryScene.h"

Player::Player():Unit("플레이어", 1000, 20, 100)
{
	std::cout << "플레이어 이름을 입력하세요." << std::endl;
	string playerName;
	cin >> playerName;
	name = playerName;
}

Player::~Player()
{
}

void Player::EarnMoney(int money)
{
	Money += money;
}


void Player::EquippedItem(Item& item)
{
	equippedItems.push_back(item);
	Att+=item.GetItemAtt();
}

void Player::UnEquippedItem(Item& item)
{
	equippedItems.pop_back();
	Att += item.GetItemAtt();
}

void Player::displayEquippedItems(const std::vector<Item>& equippedItems)
	{
		for (auto& item : equippedItems)
		{
			int i = 1;
			std::cout << i++ << ". ";
			std::cout << item.GetItemName() << " 공격력 : " << item.GetItemAtt() << std::endl;
		}
	}

void Player::checkEquippedItem(Player* player, InventoryScene* inventory)
{
	if (equippedItems.empty())
	{
		std::cout << "장착한 아이템이 없습니다." << std::endl;
	}
	else
	{
		int choice;
		while (1)
		{
			std::cout << "<장착중> ";
			displayEquippedItems(equippedItems);
			std::cin >> choice;
			if (choice == 1)
			{
				inventory->UnEquippedDisplayItem(player, choice);
				break;
			}
			else
			{
				std::cout << "다시 입력해주세요." << std::endl;
			}
		}
	}
}

