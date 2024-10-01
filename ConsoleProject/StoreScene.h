#pragma once
#include<iostream>
#include<vector>
#include"Item.h"
#include "Player.h"
#include "InventoryScene.h"
#include "Choice.h"
class StoreScene
{
protected:
	std::vector<Item> sellingItems;
public:
	StoreScene();
public: 
	void runScene(Player* player, InventoryScene* inventory);

	void displaySellingItems(const std::vector<Item>& SellingItems) const;

	void storeInformation(Player* player, InventoryScene* inventory)
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
				lobby.runScene(player,inventory);
			}
			else
			{
				std::cout << "�ٽ� �Է����ּ���" << std::endl;
			}
		}
	}

	void buyItem(Player* player,InventoryScene* inventory)
	{
		while (1)
		{
			Choice choice;
			displaySellingItems(sellingItems);
			std::cout << "�����ݾ�: " << player->GetMoney() << endl;
			std::cout << "�����Ͻ� ������ ������" << std::endl;
			int selectItem;
			std::cin >> selectItem;
			if (1 <= selectItem && selectItem <= sellingItems.size())
			{
				if (player->GetMoney() >= sellingItems[selectItem - 1].GetPrice())
				{
					while (1)
					{
						std::cout << sellingItems[selectItem - 1].GetItemName() << "�� ���� �Ͻðڽ��ϱ�?" << std::endl;
						int select = choice.choiceYesOrNo();
						if (select == 1)
						{
							inventory->GotItem(sellingItems[selectItem - 1]);
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


};

