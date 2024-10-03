#include "Player.h"
#include "Unit.h"
#include "Item.h"
#include "InventoryScene.h"
#include "UIDesign.h"

Player::Player():Unit("�÷��̾�", 1000, 20, 10000)
{
	std::cout << "�÷��̾� �̸��� �Է��ϼ���. : ";
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
	Att -= item.GetItemAtt();
}

void Player::displayEquippedItems(const std::vector<Item>& equippedItems)
	{
		for (auto& item : equippedItems)
		{
			int i = 1;
			std::cout << i++ << ". ";
			std::cout << item.GetItemName() << " ���ݷ� : " << item.GetItemAtt() << std::endl;
		}
	}

void Player::checkEquippedItem(Player* player, InventoryScene* inventory, Item& item)
{
	inventory->UnEquippedDisplayItem(player, item);
}


