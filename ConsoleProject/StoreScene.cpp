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
	sellingItems.push_back(Item("���� ī��", 10, 100));
	sellingItems.push_back(Item("����� ī��", 20, 500));
	sellingItems.push_back(Item("���� ī��", 30, 1000));
	sellingItems.push_back(Item("¯�� ī��", 100, 5000));
	sellingItems.push_back(Item("û�� ī��", 200, 10000));
	sellingItems.push_back(Item("��ö ī��", 1000, 100000));
	sellingItems.push_back(Item("�ݰ��� ī��", 10000, 1000000));
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
		std::cout << item.GetItemName() << "		���ݷ� : " << item.GetItemAtt() << "		���� : " << item.GetPrice() << std::endl;
		std::cout << std::endl;
	}
}

void StoreScene::storeInformation(Player* player, InventoryScene* inventory)
{
	CursorControl cursor;
	cursor.gotoxy(6, 23);
	std::cout << "���� ��� " << player->GetMoney();
	buyItem(player, inventory);
}

void StoreScene::buyCheck(Player* player, InventoryScene* inventory,int item )
{
	CursorControl cursor;
	UIDesign ui;
	ui.windowDesign();
	cursor.gotoxy(49, 10);
	std::cout << "������ �����Ͻðڽ��ϱ�?";
	int select = ui.yesOrNoDesign();
	if(inventory->GetGotItemsSize()==8)
	{
		ui.windowDesign();
		cursor.gotoxy(49, 10);
		std::cout << "�κ��丮�� ���� á���ϴ�.";
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
			std::cout << "���ſϷ� " << std::endl;
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
		std::cout << "�ݾ��� �����մϴ�." << std::endl;
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
	std::cout << "> ����" << std::endl;
	cursor.gotoxy(8, 5);
	std::cout << "�κ��丮" << std::endl;
	cursor.gotoxy(8, 7);
	std::cout << "����" << std::endl;
	cursor.gotoxy(8, 9);
	std::cout << "Ÿ��Ʋ" << std::endl;
	displaySellingItems(sellingItems);
	
}
