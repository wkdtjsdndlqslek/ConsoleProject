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
			std::cout << " 물건을 구매하시겠습니까?" << std::endl;
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
				std::cout << "다시 입력해주세요" << std::endl;
			}
		}
	}

	void buyItem(Player* player,InventoryScene* inventory)
	{
		while (1)
		{
			Choice choice;
			displaySellingItems(sellingItems);
			std::cout << "소지금액: " << player->GetMoney() << endl;
			std::cout << "구매하실 물건을 고르세요" << std::endl;
			int selectItem;
			std::cin >> selectItem;
			if (1 <= selectItem && selectItem <= sellingItems.size())
			{
				if (player->GetMoney() >= sellingItems[selectItem - 1].GetPrice())
				{
					while (1)
					{
						std::cout << sellingItems[selectItem - 1].GetItemName() << "을 구매 하시겠습니까?" << std::endl;
						int select = choice.choiceYesOrNo();
						if (select == 1)
						{
							inventory->GotItem(sellingItems[selectItem - 1]);
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


};

