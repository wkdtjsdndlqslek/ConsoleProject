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
	sellingItems.push_back(Item("종이 카드", 10, 100));
	sellingItems.push_back(Item("플라스틱 카드", 20, 500));
	sellingItems.push_back(Item("나무 카드", 30, 1000));
	sellingItems.push_back(Item("돌 카드", 100, 5000));
	sellingItems.push_back(Item("청동 카드", 200, 10000));
	sellingItems.push_back(Item("철 카드", 1000, 100000));
	sellingItems.push_back(Item("금강석 카드", 10000, 1000000));


}

void StoreScene::displaySellingItems(const std::vector<Item>& sellingItems) const
{
	for (size_t i=0;i<sellingItems.size();++i)
	{
		const Item& item = sellingItems[i];

		std::cout <<i+1<<". " << item.GetItemName() << " 공격력 : " << item.GetItemAtt() << " 가격 : " << item.GetPrice() << std::endl;
	}
}

void StoreScene::storeInformation(Player* player, InventoryScene* inventory)
{
	Choice choice;
	while (1)
	{
		displaySellingItems(sellingItems);
		std::cout << " 물건을 구매하시겠습니까?" << std::endl;
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
			std::cout << "다시 입력해주세요" << std::endl;
		}
	}
}


void StoreScene::buyCheck(Player* player, InventoryScene* inventory,int selectItem )
{
	while (1)
	{
		Choice choice;
		std::cout << sellingItems[selectItem - 1].GetItemName() << "을 구매 하시겠습니까?" << std::endl;
		int select = choice.choiceYesOrNo();
		if (select == 1)
		{
			inventory->GotItem(sellingItems[selectItem - 1]);
			player->SetMoney(player->GetMoney() - sellingItems[selectItem - 1].GetPrice());
			std::cout << "구매완료" << std::endl;
			break;
		}
		else if (select == 0)
		{
			break;
		}
		else
		{
			std::cout << "다시 입력해주세요" << std::endl;
		}
	}
}


void StoreScene::buyItem(Player* player, InventoryScene* inventory)
{
	while (1)
	{
		
		displaySellingItems(sellingItems);
		std::cout << "소지금액: " << player->GetMoney() << endl;
		std::cout << "구매하실 물건을 고르세요" << std::endl;
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
				std::cout << "금액이 부족합니다." << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "다시 입력해주세요" << std::endl;
		}
	}
}


