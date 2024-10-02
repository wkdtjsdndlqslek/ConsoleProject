#include "TitleScene.h"
#include "LobbyScene.h"
#include "InventoryScene.h"

void TitleScene::runScene(Player* player,InventoryScene* inventory)
{
	while (1)
	{
		std::cout << "1.�����ϱ� 2. ����" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "���ӽ���" << std::endl;
			LobbyScene lobby;
			lobby.runScene(player, inventory);
			break;
		}
		else if (choice == 2)
		{
			std::cout << "��������" << std::endl;
			break;
		}
		else
		{
			std::cout << "�ٽ� �Է� ���ּ���" << std::endl;
		}
	}
}
