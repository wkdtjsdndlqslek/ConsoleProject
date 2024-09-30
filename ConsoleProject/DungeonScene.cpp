#include "DungeonScene.h"
#include "BattleScene.h"


DungeonScene::DungeonScene()
{
	
}

void DungeonScene::runScene(Player* player)
{
	int stage=1;
	
	while (1)
	{
		std::cout << "stage" << stage << std::endl;
		Monster* monster;
		monster =new Monster("고블린", 90 + stage*10, 10 + stage, stage);
		BattleScene b;
		b.runScene(player,monster);
		delete monster;
		std::cout << std::endl;
		int choice;
		while (1)
		{
			std::cout << "로비로 나가시겠습니까?" << std::endl;
			std::cout << "1.네 0.아니오" << std::endl;
			
			std::cin >> choice;
			if (choice == 1)
			{
				break;
			}
			else if (choice == 0)
			{
				break;
			}
			else
			{
				std::cout << "다시 입력해주세요" << std::endl;
			}
		}
		if (choice == 1)break;
		stage++;
	}
	
}


