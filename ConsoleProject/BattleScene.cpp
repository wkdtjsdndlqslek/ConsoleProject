#include "BattleScene.h"
#include "Poker.h"
#include <iostream>

void BattleScene::runScene(Player* player, Monster* monster)
{
	while (1)
	{
		Poker p;
		double monsterAttRatio=0;
		double playerAttRatio=0;
		p.playPoker(monsterAttRatio, playerAttRatio);
		if (monsterAttRatio < playerAttRatio)
		{
			std::cout << "몬스터에게 " << player->GetAtt() * playerAttRatio
				<<"의 데미지를 입혔습니다." << std::endl;
			monster->SetHp(monster->GetHp() - player->GetAtt() * playerAttRatio);
		}
		if (monsterAttRatio > playerAttRatio)
		{
			std::cout << "몬스터에게 " << monster->GetAtt() * playerAttRatio
				<< "만큼의 데미지를 입었습니다." << std::endl;
			player->SetHp(player->GetHp() - monster->GetAtt() * playerAttRatio);
		}
		std::cout << "플레이어 체력 : " << player->GetHp() << std::endl;
		std::cout << "몬스터 체력 : " << monster->GetHp() << std::endl;
		std::cout << std::endl;
		if (player->GetHp() <= 0)
		{
			std::cout << "사망하였습니다. " << monster->GetMoney() << "만큼의 돈을 잃었습니다."<<std::endl;
			player->SetMoney(player->GetMoney() - monster->GetMoney());
			std::cout<<"보유 골드 : "<< player->GetMoney() <<std::endl;
			break;
		}
		else if (monster->GetHp() <= 0)
		{
			std::cout << "스테이지 클리어 " << monster->GetMoney() << "골드 획득" << std::endl;
			player->SetMoney(player->GetMoney() + monster->GetMoney());
			std::cout<<"보유 골드 : "<<player->GetMoney() << std::endl;
			break;
		}
		
	}
}
