#include "StoreScene.h"
#include"Player.h"
#include"Game.h"
#include"Item.h"
#include"InventoryScene.h"
#include"LobbyScene.h"
#include "Choice.h"


void StoreScene::runScene(Player* player, InventoryScene* inventory)
{
	while (1)
	{
		storeInformation(player,inventory);
		buyItem(player,inventory);
	}
}

StoreScene::StoreScene()
{
	sellingItems.push_back(Item("���� ī��", 10, 100));
	sellingItems.push_back(Item("�ö�ƽ ī��", 20, 500));
	sellingItems.push_back(Item("���� ī��", 30, 1000));
	sellingItems.push_back(Item("�� ī��", 100, 5000));
	sellingItems.push_back(Item("û�� ī��", 200, 10000));
	sellingItems.push_back(Item("ö ī��", 1000, 100000));
	sellingItems.push_back(Item("�ݰ��� ī��", 10000, 1000000));


}

void StoreScene::displaySellingItems(const std::vector<Item>& sellingItems) const
{
	for (size_t i=0;i<sellingItems.size();++i)
	{
		const Item& item = sellingItems[i];

		std::cout <<i+1<<". " << item.GetItemName() << " ���ݷ� : " << item.GetItemAtt() << " ���� : " << item.GetPrice() << std::endl;
	}
}

void StoreScene::storeInformation(Player* player, InventoryScene* inventory)
{
	Choice choice;
	while (1)
	{
		displaySellingItems(sellingItems);
		std::cout << " ������ �����Ͻðڽ��ϱ�?" << std::endl;
		int select = choice.choiceYesOrNo();
		if (select == 1)
		{
			break;
		}
		else if (select == 0)
		{
			LobbyScene lobby;
			lobby.runScene(player, inventory);
		}
		else
		{
			std::cout << "�ٽ� �Է����ּ���" << std::endl;
		}
	}
}


void StoreScene::buyCheck(Player* player, InventoryScene* inventory,int selectItem )
{
	while (1)
	{
		Choice choice;
		std::cout << sellingItems[selectItem - 1].GetItemName() << "�� ���� �Ͻðڽ��ϱ�?" << std::endl;
		int select = choice.choiceYesOrNo();
		if (select == 1)
		{
			inventory->GotItem(sellingItems[selectItem - 1]);
			player->SetMoney(player->GetMoney() - sellingItems[selectItem - 1].GetPrice());
			std::cout << "���ſϷ�" << std::endl;
			break;
		}
		else if (select == 0)
		{
			break;
		}
		else
		{
			std::cout << "�ٽ� �Է����ּ���" << std::endl;
		}
	}
}


void StoreScene::buyItem(Player* player, InventoryScene* inventory)
{
	while (1)
	{
		
		displaySellingItems(sellingItems);
		std::cout << "�����ݾ�: " << player->GetMoney() << endl;
		std::cout << "�����Ͻ� ������ ������" << std::endl;
		int selectItem;
		std::cin >> selectItem;
		if (1 <= selectItem && selectItem <= sellingItems.size())
		{
			if (player->GetMoney() >= sellingItems[selectItem - 1].GetPrice())
			{
				buyCheck(player, inventory, selectItem);
				break;
			}
			else if (player->GetMoney() < sellingItems[selectItem - 1].GetPrice())
			{
				std::cout << "�ݾ��� �����մϴ�." << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "�ٽ� �Է����ּ���" << std::endl;
		}
	}
}


