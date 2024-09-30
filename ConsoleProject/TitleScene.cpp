#include "TitleScene.h"

void TitleScene::runScene(Player* player)
{
	while (1)
	{
		std::cout << "1.게임하기 2. 종료" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "게임시작" << std::endl;
			break;
		case 2:std::cout << "게임종료" << std::endl;
			break;
		default:std::cout << "다시 입력 해주세요" << std::endl;
		}
	}
}
