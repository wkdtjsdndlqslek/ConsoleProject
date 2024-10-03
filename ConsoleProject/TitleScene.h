#pragma once
#include <iostream>
#include "CursorControl.h"

class LobbyScene;
class Player;
class InventoryScene;

class TitleScene
{

	Player* player;
	InventoryScene* inventory;
public:
	void PrintScene(int num);
	void runScene();
	void runScene(Player* player, InventoryScene* inventory);
	int PrintMenu();
};

