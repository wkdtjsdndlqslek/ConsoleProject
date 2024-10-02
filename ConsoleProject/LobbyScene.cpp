#include "LobbyScene.h"
#include "TitleScene.h"
#include "StoreScene.h"
#include "InventoryScene.h"
#include "DungeonScene.h"

void LobbyScene::runScene(Player* player, InventoryScene* inventory)
{
	while(1)
	{
		std::cout << "1.상점 2.인벤토리 3.던전 4. 타이틀화면" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "상점으로 입장합니다." << std::endl;
			StoreScene store;
			store.runScene(player, inventory);
		}
		else if (choice == 2)
		{
			std::cout << "인벤토리를 확인합니다." << std::endl;
			inventory->runScene(player,inventory);
		}
		else if (choice == 3)
		{
			std::cout << "던전으로 입장합니다." << std::endl;
			DungeonScene dungeon;
			dungeon.runScene(player);
		}
		else if (choice == 4)
		{
			std::cout << "타이틀 화면으로 입장합니다." << std::endl;
			return;
		}
		else
		{
			std::cout << "다시 입력해주세요." << std::endl;
		}
	}
}
