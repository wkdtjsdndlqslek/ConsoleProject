#include "BattleScene.h"
#include "Poker.h"
#include <iostream>

void BattleScene::runScene()
{
	Poker* p = new Poker;
	p->playPoker();

}
