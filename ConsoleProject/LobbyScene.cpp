#include "LobbyScene.h"
#include "TitleScene.h"
#include "StoreScene.h"
#include "InventoryScene.h"
#include "DungeonScene.h"

void LobbyScene::runScene(Player* player, InventoryScene* inventory)
{
	while(1)
	{
		std::cout << "1.���� 2.�κ��丮 3.���� 4. Ÿ��Ʋȭ��" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "�������� �����մϴ�." << std::endl;
			StoreScene store;
			store.runScene(player, inventory);
		}
		else if (choice == 2)
		{
			std::cout << "�κ��丮�� Ȯ���մϴ�." << std::endl;
			inventory->runScene(player,inventory);
		}
		else if (choice == 3)
		{
			std::cout << "�������� �����մϴ�." << std::endl;
			DungeonScene dungeon;
			dungeon.runScene(player);
		}
		else if (choice == 4)
		{
			std::cout << "Ÿ��Ʋ ȭ������ �����մϴ�." << std::endl;
			return;
		}
		else
		{
			std::cout << "�ٽ� �Է����ּ���." << std::endl;
		}
	}
}
