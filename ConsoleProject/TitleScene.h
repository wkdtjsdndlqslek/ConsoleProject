#pragma once
#include <iostream>
#include "Player.h"
class InventoryScene;
class LobbyScene;

class TitleScene
{
public:
	void runScene(Player* player, InventoryScene* inventory);
};