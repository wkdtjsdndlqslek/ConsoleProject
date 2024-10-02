#pragma once
#include "Player.h"
#include "InventoryScene.h"

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

