#include "LobbyScene.h"

int LobbyScene::runScene()
{
	while(1)
	{
		std::cout << "1.���� 2.�κ��丮 3.���� 4. Ÿ��Ʋȭ��" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "�������� �����մϴ�." << std::endl;
		case 2:
			std::cout << "�κ��丮�� Ȯ���մϴ�." << std::endl;
		case 3:
			std::cout << "�������� �����մϴ�." << std::endl;
		case 4:
			std::cout << "Ÿ��Ʋ ȭ������ �����մϴ�." << std::endl;
		default:
			std::cout << "�ٽ� �Է����ּ���." << std::endl;
		}
	}
}

void LobbyScene::PrintScene()
{
}
