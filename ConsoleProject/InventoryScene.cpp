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
	std::cout << "����� �������� ������." << std::endl;
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
				std::cout << "�����Ǿ����ϴ�." << std::endl;
				selectItem.SetEquipped(1);
				break;
			}
			else std::cout << "�ٽ� �Է����ּ���." << std::endl;
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
		std::cout << "���� ������ ������ ����" << std::endl;
		return;
	}
	else {
		for (const auto& item : gotItems)
		{
			int i = 1;
			std::cout << i++ << ". ";
			if (item.isEquipped(item)==1)
			{
				std::cout << "<������> ";
			}
			std::cout << item.GetItemName() << " ���ݷ� : " << item.GetItemAtt() << std::endl;
		}
	}
}

void InventoryScene::EquipOrUnEquip(Player * player,InventoryScene* inventory)
{
	std::cout << "1.����ϱ� 2.Ż���ϱ� 3.�κ�" << std::endl;
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

void InventoryScene::UnEquippedDisplayItem(Player* player, int choice)//private�� ������� gotItems�� �����ϱ� ���� �Լ�
{
	Item& selectItem = gotItems[choice - 1];
	player->UnEquippedItem(selectItem);
	std::cout << "Ż���Ǿ����ϴ�." << std::endl;
	selectItem.SetEquipped(0);
}


