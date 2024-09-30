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
			std::cout << "���Ϳ��� " << player->GetAtt() * playerAttRatio
				<<"�� �������� �������ϴ�." << std::endl;
			monster->SetHp(monster->GetHp() - player->GetAtt() * playerAttRatio);
		}
		if (monsterAttRatio > playerAttRatio)
		{
			std::cout << "���Ϳ��� " << monster->GetAtt() * playerAttRatio
				<< "��ŭ�� �������� �Ծ����ϴ�." << std::endl;
			player->SetHp(player->GetHp() - monster->GetAtt() * playerAttRatio);
		}
		std::cout << "�÷��̾� ü�� : " << player->GetHp() << std::endl;
		std::cout << "���� ü�� : " << monster->GetHp() << std::endl;
		std::cout << std::endl;
		if (player->GetHp() <= 0)
		{
			std::cout << "����Ͽ����ϴ�. " << monster->GetMoney() << "��ŭ�� ���� �Ҿ����ϴ�."<<std::endl;
			player->SetMoney(player->GetMoney() - monster->GetMoney());
			std::cout<<"���� ��� : "<< player->GetMoney() <<std::endl;
			break;
		}
		else if (monster->GetHp() <= 0)
		{
			std::cout << "�������� Ŭ���� " << monster->GetMoney() << "��� ȹ��" << std::endl;
			player->SetMoney(player->GetMoney() + monster->GetMoney());
			std::cout<<"���� ��� : "<<player->GetMoney() << std::endl;
			break;
		}
		
	}
}
