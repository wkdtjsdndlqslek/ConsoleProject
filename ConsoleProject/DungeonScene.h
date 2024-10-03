#pragma once
#include "Monster.h"
#include <iostream>
#include <vector>

class Player;

class DungeonScene
{
private:
public:
	void runScene(Player* player);
	void PrintScene(int stage);
};

