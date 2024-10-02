#pragma once
#include <iostream>
#include "Player.h"

class LobbyScene;
class InventoryScene;

class TitleScene
{
public:
	void runScene(Player* player, InventoryScene* inventory);
};

