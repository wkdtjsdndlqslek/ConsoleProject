#pragma once
#include<iostream>
#include"Monster.h"

class Player;
class BattleScene
{
public:
	int runScene(Player* player, Monster* monster,int stage);
	void PrintScene(Player* player, Monster* monster, int stage);
	void PrintMonster(Monster* monster);
	void PrintPlayer(Player* player);
	
};


