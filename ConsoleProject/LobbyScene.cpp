#include "LobbyScene.h"
#include "TitleScene.h"
#include "StoreScene.h"
#include "InventoryScene.h"
#include "DungeonScene.h"
#include "UIDesign.h"

void LobbyScene::runScene(Player* player, InventoryScene* inventory)
{
	while(1)
	{
		CursorControl cursor;
		UIDesign ui;
		PrintScene();
		int choice=PrintMenu();
		if (choice == 0)//switch문 사용 불가
		{
			StoreScene store;
			store.runScene(player, inventory);
		}
		else if (choice == 1)
		{
			inventory->runScene(player,inventory);
		}
		else if (choice == 2)
		{
			ui.windowDesign();
			cursor.gotoxy(48, 10);
			std::cout << "던전에 입장하시겠습니까?";
			int choice=ui.yesOrNoDesign();
			if (choice == 0) 
			{
				DungeonScene dungeon;
				dungeon.runScene(player);
			}
		}
		else if (choice == 3)
		{
			TitleScene title;
			title.runScene(player,inventory);
		}
	}
}

int LobbyScene::PrintMenu()
{
	CursorControl cursor;
	int x = 6;
	int y = 3;
	int choice = 0;
	while (1)
	{
		cursor.gotoxy(x, y);
		int input;
		if (_kbhit())
		{
			input=_getch();
			switch (input)
			{
			case UP:
				if (choice > 0)
				{
					choice--;
				}
				cursor.gotoxy(x, y + 2*choice);
				std::cout << ">" << std::endl;
				cursor.gotoxy(x, y + 2*choice + 2);
				std::cout << "  " << std::endl;
				break;
			case DOWN:
				if (choice < 3)
				{
					choice++;
				}
				cursor.gotoxy(x, y + 2*choice - 2);
				std::cout << "  " << std::endl;
				cursor.gotoxy(x, y + 2*choice);
				std::cout << ">" << std::endl;
				break;
			case RIGHT:
				return choice;
			case SPACE:
				return choice;
			case ENTER:
				return choice;
			}
		}
	}
}

void LobbyScene::PrintScene()
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
}


