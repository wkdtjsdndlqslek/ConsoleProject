#include "TitleScene.h"

void TitleScene::runScene(Player* player)
{
	while (1)
	{
		std::cout << "1.�����ϱ� 2. ����" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "���ӽ���" << std::endl;
			break;
		case 2:std::cout << "��������" << std::endl;
			break;
		default:std::cout << "�ٽ� �Է� ���ּ���" << std::endl;
		}
	}
}
