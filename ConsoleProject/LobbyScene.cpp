#include "LobbyScene.h"

void LobbyScene::runScene(Player* player)
{
	while(1)
	{
		std::cout << "1.상점 2.인벤토리 3.던전 4. 타이틀화면" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "상점으로 입장합니다." << std::endl;
			break;
		case 2:
			std::cout << "인벤토리를 확인합니다." << std::endl;
			break;
		case 3:
			std::cout << "던전으로 입장합니다." << std::endl;
			break;
		case 4:
			std::cout << "타이틀 화면으로 입장합니다." << std::endl;
			break;
		default:
			std::cout << "다시 입력해주세요." << std::endl;
			break;
		}
	}
}
