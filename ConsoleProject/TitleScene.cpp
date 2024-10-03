#include "TitleScene.h"
#include "LobbyScene.h"
#include "InventoryScene.h"
#include"Player.h"
#include"InventoryScene.h"
#include"UIDesign.h"
#include <stdlib.h>

void TitleScene::runScene()
{
	CursorControl cursor;
	while (1)
	{
		PrintScene(1);
		int choice = PrintMenu();
		switch (choice)
		{
		case 0:
			cursor.gotoxy(0, 0);
			PrintScene(2);
			cursor.gotoxy(6, 23);
			std::cout << "게임시작" << std::endl;
			cursor.gotoxy(6, 25);
			player = new Player();
			inventory = new InventoryScene();
			LobbyScene lobby;
			lobby.runScene(player, inventory);
			break;
		case 1:std::cout << " 종료" << std::endl;
			exit(0);
			break;
		}
		if(choice == 1) break;
	}
}

void TitleScene::runScene(Player* player, InventoryScene* inventory)
{
	CursorControl cursor;
	while (1)
	{
		PrintScene(1);
		int choice = PrintMenu();
		switch (choice)
		{
		case 0:
			cursor.gotoxy(0, 0);
			PrintScene(2);
			cursor.gotoxy(6, 23);
			std::cout << "게임시작" << std::endl;
			LobbyScene lobby;
			lobby.runScene(player, inventory);
			break;
		case 1:
			std::cout << " 종료" << std::endl;
			exit(0);
			break;
		}
		if (choice == 1) break;
	}
}

int TitleScene::PrintMenu()
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
				cursor.gotoxy(54, 21);
				std::cout << " ";
				cursor.gotoxy(54, 20);
				std::cout << ">";
				if (choice > 0)
				{
					choice--;
				}
				break;
			case DOWN:
				cursor.gotoxy(54, 20);
				std::cout << " ";
				cursor.gotoxy(54, 21);
				std::cout << ">";
				if (choice <1)
				{
					choice++;
				}
				break;
			case SPACE:
				return choice;
			}
		}
	}
}

void TitleScene::PrintScene(int num)
{
	UIDesign ui;
	CursorControl cursor;
	if (num == 1)
	{
		ui.titleDesign();
		cursor.gotoxy(54, 20);
		std::cout << "> 게임하기" << std::endl;
		cursor.gotoxy(56, 21);
		std::cout << "종료" << std::endl;
	}
	else if (num == 2)
	{
		ui.bottomDesign();
	}
}
