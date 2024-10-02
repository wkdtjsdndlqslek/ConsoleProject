#include "StoreScene.h"
#include"Item.h"
#include"Player.h"
#include"Game.h"
#include "InventoryScene.h"
#include "LobbyScene.h"
#include "Choice.h"
#include "CursorControl.h"

void StoreScene::runScene(Player* player, InventoryScene* inventory)
{
	while (1)
	{
		CursorControl cursor;
		PrintScene();
		cursor.gotoxy(30, 3);
		std::cout << ">";
		storeInformation(player,inventory);
		buyItem(player,inventory);
	}
}

StoreScene::StoreScene()
{
	sellingItems.push_back(Item("종이 카드", 10, 100));
	sellingItems.push_back(Item("골판지 카드", 20, 500));
	sellingItems.push_back(Item("나무 카드", 30, 1000));
	sellingItems.push_back(Item("돌 카드", 100, 5000));
	sellingItems.push_back(Item("청동 카드", 200, 10000));
	sellingItems.push_back(Item("철 카드", 1000, 100000));
	sellingItems.push_back(Item("금강석 카드", 10000, 1000000));
}

void StoreScene::displaySellingItems(const std::vector<Item>& sellingItems) const
{
	CursorControl cursor;
	for (size_t i=0;i<sellingItems.size();++i)
	{
		cursor.gotoxy(32, 3+2*i);
		const Item& item = sellingItems[i];
		std::cout <<i+1<<". " << item.GetItemName() << "		공격력 : " << item.GetItemAtt() << "		가격 : " << item.GetPrice() << std::endl;
		std::cout << std::endl;
	}
}

void StoreScene::storeInformation(Player* player, InventoryScene* inventory)
{
	Choice choice;
	while (1)
	{
		CursorControl cursor;
		displaySellingItems(sellingItems);
		std::cout <<"보유 골드 "<< player->GetMoney()<<"골드" << std::endl;
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
			std::cout << "구매완료 " <<player->GetMoney() << "골드 남았습니다." << std::endl;
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
		std::cout << "보유 골드 " << player->GetMoney() << endl;
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

void StoreScene::PrintScene()
{
	CursorControl cursor;
	cursor.gotoxy(0, 0);
	std::cout << "                                                                                                                      " << std::endl;
	std::cout << "  ■■■■■■■■■■■  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■                  ■  ■                                                                                        ■  " << std::endl;
	std::cout << "  ■■■■■■■■■■■  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  " << std::endl;
	std::cout << "                                                                                                                        " << std::endl;
	std::cout << "  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  " << std::endl;
	std::cout << "  ■                                                                                                                ■  " << std::endl;
	std::cout << "  ■                                                                                                                ■  " << std::endl;
	std::cout << "  ■                                                                                                                ■  " << std::endl;
	std::cout << "  ■                                                                                                                ■  " << std::endl;
	std::cout << "  ■                                                                                                                ■  " << std::endl;
	std::cout << "  ■                                                                                                                ■  " << std::endl;
	std::cout << "  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  " << std::endl;
	cursor.gotoxy(6, 3);
	std::cout << "> 상점" << std::endl;
	cursor.gotoxy(8, 5);
	std::cout << "인벤토리" << std::endl;
	cursor.gotoxy(8, 7);
	std::cout << "던전" << std::endl;
	cursor.gotoxy(8, 9);
	std::cout << "타이틀" << std::endl;
}
