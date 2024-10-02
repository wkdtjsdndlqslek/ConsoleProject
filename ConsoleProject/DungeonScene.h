#pragma once
#include "Monster.h"
#include <iostream>
#include <vector>

class Player;

class DungeonScene
{
private:
public:
	DungeonScene();
public:
	void runScene(Player* player);
};

