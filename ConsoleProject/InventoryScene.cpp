#include "InventoryScene.h"
#include"Item.h"
#include "Player.h"
#include "CursorControl.h"
#include "UIDesign.h"
#include"LobbyScene.h"

void InventoryScene::runScene(Player* player, InventoryScene* inventory)
{
	CursorControl cursor;
	UIDesign ui;
	while (1)
	{
		{
			PrintScene();
			if (gotItems.empty())
			{
				ui.windowDesign();
				cursor.gotoxy(52, 10);
				std::cout << "아이템이 없습니다.";
				ui.checkDesign();
				break;
			}
			else 
			{
				displayGotItems(gotItems);
				EquipOrUnEquip(player, inventory);
			}
		}
	}
	
}

void InventoryScene::EquippingItem(Player* player, Item& item)
{
	UIDesign ui;
	CursorControl cursor;
	player->EquippedItem(item);
	ui.windowDesign();
	cursor.gotoxy(53, 10);
	std::cout << "장착되었습니다." << std::endl;
	ui.checkDesign();
	item.SetEquipped(1);
	
}

void InventoryScene::UnEquippingItem(Player* player,InventoryScene* inventory,Item& item)
{
	player->checkEquippedItem(player,inventory,item);
}

void InventoryScene::GotItem(Item& item)
{
	gotItems.push_back(item);
}

void InventoryScene::displayGotItems(const std::vector<Item>& gotItems)const
{
	CursorControl cursor;
	cursor.gotoxy(33, 3);
	std::cout << ">";
	for (int i = 0; i < gotItems.size(); i++)
	{
		const Item& item = gotItems[i];
		if (item.isEquipped(item) == 1)
		{
			cursor.gotoxy(35, 3 + 2 * i);
			std::cout << "<장착중> " << item.GetItemName() << " 공격력 : " << item.GetItemAtt() << std::endl;
		}
		else
		{
			cursor.gotoxy(35, 3 + 2 * i);
			std::cout << item.GetItemName() << " 공격력 : " << item.GetItemAtt() << std::endl;
		}
	}
	
}

void InventoryScene::EquipOrUnEquip(Player * player,InventoryScene* inventory)
{
	int select = PrintMenu(player, inventory);
	Item& item= gotItems[select];
	if (item.isEquipped(item) == 0)
	{
		EquippingItem(player, item);
	}
	else
	{
		UnEquippingItem(player, inventory,item);
	}
	
}

void InventoryScene::UnEquippedDisplayItem(Player* player, Item& item)//private인 멤버변수 gotItems에 접근하기 위한 함수
{
	UIDesign ui;
	CursorControl cursor;
	player->UnEquippedItem(item);
	item.SetEquipped(0);
	ui.windowDesign();
	cursor.gotoxy(53, 10);
	std::cout << "탈착되었습니다." << std::endl;
	ui.checkDesign();	
}

int InventoryScene::PrintMenu(Player* player, InventoryScene* inventory)
{
	CursorControl cursor;
	int choice=0;
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
				if (choice < gotItems.size()-1)
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
				break;
			case SPACE:
				return choice;
			case ENTER:
				return choice;
			}
		}
	}
}

void InventoryScene::PrintScene()
{
	CursorControl cursor;
	UIDesign ui;
	cursor.gotoxy(0, 0);
	ui.wholeDesign();
	cursor.gotoxy(8, 3);
	std::cout << "상점" << std::endl;
	cursor.gotoxy(6, 5);
	std::cout << "> 인벤토리" << std::endl;
	cursor.gotoxy(8, 7);
	std::cout << "던전" << std::endl;
	cursor.gotoxy(8, 9);
	std::cout << "타이틀" << std::endl;
	displayGotItems(gotItems);
}

int InventoryScene::GetGotItemsSize()
{
	UIDesign ui;
	CursorControl cursor;
	return gotItems.size();
}