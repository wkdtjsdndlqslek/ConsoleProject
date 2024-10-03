#include "BattleScene.h"
#include "Poker.h"
#include "Player.h" 
#include "CursorControl.h"
#include "UIDesign.h"
#include "DungeonScene.h"

void BattleScene::runScene(Player* player, Monster* monster, int stage)
{
	CursorControl cursor;
	UIDesign ui;
	cursor.gotoxy(6, 23);
	std::cout << "�߻��� " << monster->GetName() << "�� ��Ÿ����!";
	PrintPlayer(player);
	PrintMonster(monster);
	ui.justNext();
	ui.onlyBottomDesign();
	cursor.gotoxy(6, 23);
	std::cout << "���!";
	ui.justNext();
	while (1)
	{
		Poker p;
		double monsterAttRatio = 0;
		double playerAttRatio = 0;
		p.playPoker(monsterAttRatio, playerAttRatio,player,monster,stage);
		ui.justNext();
		PrintScene(player,monster,stage);
		cursor.gotoxy(6, 23);
		if (monsterAttRatio < playerAttRatio)
		{
			std::cout << "���Ͱ� " << player->GetAtt() * playerAttRatio
				<< "�� �������� �Ծ����ϴ�." << std::endl;
			monster->SetHp(monster->GetHp() - player->GetAtt() * playerAttRatio);
		}
		if (monsterAttRatio > playerAttRatio)
		{
			std::cout << "�÷��̾ " << monster->GetAtt() * playerAttRatio
				<< "�� �������� �Ծ����ϴ�." << std::endl;
			player->SetHp(player->GetHp() - monster->GetAtt() * playerAttRatio);
		}
		cursor.gotoxy(6, 25);
		std::cout << "�÷��̾� ü�� : " << player->GetHp() << std::endl;
		cursor.gotoxy(6, 26);
		std::cout << "���� ü�� : " << monster->GetHp() << std::endl;
		std::cout << std::endl;
		ui.justNext();
		if (player->GetHp() <= 0)
		{
			ui.windowDesign();
			cursor.gotoxy(52,10);
			std::cout << "����Ͽ����ϴ�. ";
			cursor.gotoxy(50, 11); 
			std::cout<< monster->GetMoney() << "��带 �Ҿ����ϴ�." << std::endl;
			player->SetMoney(player->GetMoney() - monster->GetMoney());
			std::cout << "���� ��� : " << player->GetMoney() << std::endl;
			ui.checkDesign();
			break;
		}
		else if (monster->GetHp() <= 0)
		{
			ui.windowDesign();
			cursor.gotoxy(53, 10);
			std::cout << "�������� Ŭ����"; 
			cursor.gotoxy(53, 11);
			std::cout<< monster->GetMoney() << "��� ȹ��" << std::endl;
			player->SetMoney(player->GetMoney() + monster->GetMoney());
			cursor.gotoxy(53, 12);
			std::cout << "���� ��� : " << player->GetMoney() << std::endl;
			ui.checkDesign();
			break;
		}
	}
}

void BattleScene::PrintScene(Player* player, Monster* monster,int stage)
{
	DungeonScene dungeon;
	dungeon.PrintScene(stage);
	PrintMonster(monster);
	PrintPlayer(player);
}

void BattleScene::PrintMonster(Monster* monster)
{
	CursorControl cursor;
	cursor.gotoxy(89, 7);
	std::cout << monster->GetName();
	cursor.gotoxy(89, 8);
	std::cout << "_-��/��/";
	cursor.gotoxy(87, 9);
	std::cout << "�� /    )";
	cursor.gotoxy(87, 10);
	std::cout << "(��    )";
	cursor.gotoxy(88, 11);
	std::cout << "_| |_";
	cursor.gotoxy(86, 12);
	std::cout << "/       ��";
	cursor.gotoxy(87, 13);
	std::cout << "( /�� )";
	cursor.gotoxy(87, 14);
	std::cout << "(/  ��)";
}

void BattleScene::PrintPlayer(Player* player)
{
	{
		CursorControl cursor;
		cursor.gotoxy(52, 8);
		std::cout << player->GetName();
		cursor.gotoxy(51, 9);
		std::cout << "///////";
		cursor.gotoxy(50, 10);
		std::cout << "(   `��)";
		cursor.gotoxy(51, 11);
		std::cout << "_| |_";
		cursor.gotoxy(49, 12);
		std::cout << "/       ��";
		cursor.gotoxy(50, 13);
		std::cout << "( /�� )";
		cursor.gotoxy(50, 14);
		std::cout << "(/  ��)";
	}
}

