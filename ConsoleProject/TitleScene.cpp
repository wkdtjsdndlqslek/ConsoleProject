#include "TitleScene.h"
#include "LobbyScene.h"
#include "InventoryScene.h"

void TitleScene::runScene(Player* player,InventoryScene* inventory)
{
	while (1)
	{
		std::cout << "1.게임하기 2. 종료" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "게임시작" << std::endl;
			LobbyScene lobby;
			lobby.runScene(player, inventory);
			break;
		}
		else if (choice == 2)
		{
			std::cout << "게임종료" << std::endl;
			break;
		}
		else
		{
			std::cout << "다시 입력 해주세요" << std::endl;
		}
	}
}
