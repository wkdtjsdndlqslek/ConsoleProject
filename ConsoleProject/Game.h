#pragma once
#include "Player.h"

class Inventory;

class Game
{
private:
	Player* player;
	InventoryScene* inventory;

public:
	Game();
	~Game();

public:
	void RunGame();


};

