#include "DungeonScene.h"
#include "BattleScene.h"
#include "UIDesign.h"
#include "CursorControl.h"



void DungeonScene::runScene(Player* player)
{
	CursorControl cursor;
	UIDesign ui;
	double stage=1.0;
	
	while (1)
	{
		PrintScene(stage);
		Monster* monster;
		monster =new Monster("���", stage*100.0, 10 + stage, stage*100);
		BattleScene b;
		b.runScene(player, monster,stage);
		delete monster;ui.windowDesign();
		cursor.gotoxy(53, 10);
		std::cout << "���� ����������";
		cursor.gotoxy(52, 11);
		std::cout<<"�̵��Ͻðڽ��ϱ�?";
		int select = ui.yesOrNoDesign();
		if (select == 1)break;
		stage++;
	}
	
}

void DungeonScene::PrintScene(int stage)
{
	UIDesign ui;
	CursorControl cursor;
	cursor.gotoxy(0, 0);
	ui.wholeDesign();
	cursor.gotoxy(35, 3);
	std::cout << "<stage " << stage << ">" << std::endl;
	{
		cursor.gotoxy(6, 3);
		std::cout << "ROYAL STRATE FLUSH";
		cursor.gotoxy(7, 4);
		std::cout << "10��";
		cursor.gotoxy(6, 5);
		std::cout << "STRATE FLUSH";
		cursor.gotoxy(7, 6);
		std::cout << "4��";
		cursor.gotoxy(6, 7);
		std::cout << "FOUR CARD";
		cursor.gotoxy(7, 8);
		std::cout << "2.5��";
		cursor.gotoxy(6, 9);
		std::cout << "FULL HOUSE";
		cursor.gotoxy(7, 10);
		std::cout << "2.0��";
		cursor.gotoxy(6, 11);
		std::cout << "FLUSH";
		cursor.gotoxy(7, 12);
		std::cout << "1.8��";
		cursor.gotoxy(6, 13);
		std::cout << "STRATE";
		cursor.gotoxy(7, 14);
		std::cout << "1.6��";
		cursor.gotoxy(6, 15);
		std::cout << "TRIPLE";
		cursor.gotoxy(7, 16);
		std::cout << "1.4��";
		cursor.gotoxy(16, 15);
		std::cout << "TWO PAIR";
		cursor.gotoxy(17, 16);
		std::cout << "1.2��";
		cursor.gotoxy(6, 17);
		std::cout << "ONE PAIR";
		cursor.gotoxy(7, 18);
		std::cout << "1.0��";
		cursor.gotoxy(16, 17);
		std::cout << "TOP";
		cursor.gotoxy(17, 18);
		std::cout << "0.8��";
	}
}



