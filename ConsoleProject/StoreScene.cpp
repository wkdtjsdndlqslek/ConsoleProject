#include "StoreScene.h"
#include"Item.h"
#include"Player.h"
#include"Game.h"
#include "InventoryScene.h"
#include "LobbyScene.h"
#include "CursorControl.h"
#include "UIDesign.h"

void StoreScene::runScene(Player* player, InventoryScene* inventory)
{
	while (1)
	{
		CursorControl cursor;
		PrintScene();
		cursor.gotoxy(33, 3);
		std::cout << ">";
		storeInformation(player, inventory);
	}
}

StoreScene::StoreScene()
{
	sellingItems.push_back(Item("종이 카드", 10, 100));
	sellingItems.push_back(Item("유희왕 카드", 20, 500));
	sellingItems.push_back(Item("나무 카드", 30, 1000));
	sellingItems.push_back(Item("짱돌 카드", 100, 5000));
	sellingItems.push_back(Item("청동 카드", 200, 10000));
	sellingItems.push_back(Item("강철 카드", 1000, 100000));
	sellingItems.push_back(Item("금강석 카드", 10000, 1000000));
}

void StoreScene::displaySellingItems(const std::vector<Item>& sellingItems) const
{
	CursorControl cursor;
	for (int i=0;i<sellingItems.size();++i)
	{
		cursor.gotoxy(33, 3);
		std::cout << ">";
		cursor.gotoxy(35, 3+2*i);
		const Item& item = sellingItems[i];
		std::cout << item.GetItemName() << "		공격력 : " << item.GetItemAtt() << "		가격 : " << item.GetPrice() << std::endl;
		std::cout << std::endl;
	}
}

void StoreScene::storeInformation(Player* player, InventoryScene* inventory)
{
	CursorControl cursor;
	cursor.gotoxy(6, 23);
	std::cout << "보유 골드 " << player->GetMoney();
	buyItem(player, inventory);
}

void StoreScene::buyCheck(Player* player, InventoryScene* inventory,int item )
{
	CursorControl cursor;
	UIDesign ui;
	ui.windowDesign();
	cursor.gotoxy(49, 10);
	std::cout << "물건을 구매하시겠습니까?";
	int select = ui.yesOrNoDesign();
	if(inventory->GetGotItemsSize()==8)
	{
		ui.windowDesign();
		cursor.gotoxy(49, 10);
		std::cout << "인벤토리가 가득 찼습니다.";
		ui.checkDesign();
	}
	else
	{
		switch (select)
		{
		case 0:
			inventory->GotItem(sellingItems[item]);
			player->SetMoney(player->GetMoney() - sellingItems[item].GetPrice());
			ui.windowDesign();
			cursor.gotoxy(57, 10);
			std::cout << "구매완료 " << std::endl;
			ui.checkDesign();
			break;
		case 1:
			break;
		}
	}
}

void StoreScene::buyItem(Player* player, InventoryScene* inventory)
{
	
	CursorControl cursor;
	UIDesign ui;
	int select = PrintMenu(player, inventory);
	if (player->GetMoney() >= sellingItems[select].GetPrice())
	{
		buyCheck(player, inventory, select);
	}
	else if (player->GetMoney() < sellingItems[select].GetPrice())
	{
		ui.windowDesign();
		cursor.gotoxy(51, 10);
		std::cout << "금액이 부족합니다." << std::endl;
		ui.checkDesign();
	}
	
}

int StoreScene::PrintMenu(Player* player,InventoryScene* inventory)
{
	CursorControl cursor;
	int choice = 0;
	while (1)
	{
		int input;
		if (_kbhit())
		{
			input = _getch();
			switch (input)
			{
			case UP:
				if (choice > 0)
				{
					choice--;
				}
				cursor.gotoxy(33, 3 + 2 * choice + 2);
				std::cout << " ";
				cursor.gotoxy(33, 3 + 2 * choice);
				std::cout << ">";
				break;
			case DOWN:
				if (choice < 6)
				{
					choice++;
				}
				cursor.gotoxy(33, 3 + 2 * choice - 2);
				std::cout << " ";
				cursor.gotoxy(33, 3 + 2 * choice);
				std::cout << ">";
				break;
			case LEFT:
				LobbyScene lobby;
				lobby.runScene(player, inventory);
			case SPACE:
				return choice;
			}
		}
	}
}

void StoreScene::PrintScene()
{
	CursorControl cursor;
	UIDesign ui;
	ui.wholeDesign();
	cursor.gotoxy(6, 3);
	std::cout << "> 상점" << std::endl;
	cursor.gotoxy(8, 5);
	std::cout << "인벤토리" << std::endl;
	cursor.gotoxy(8, 7);
	std::cout << "던전" << std::endl;
	cursor.gotoxy(8, 9);
	std::cout << "타이틀" << std::endl;
	displaySellingItems(sellingItems);
	
}
