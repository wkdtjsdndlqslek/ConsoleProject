#include "BattleScene.h"
#include "Poker.h"
#include <iostream>

int BattleScene::runScene()
{
	Poker* p = new Poker;
	p->playPoker();
	int gameResult=0;
	return gameResult;
}
