#pragma once
#include "Player.h"
#include<iostream>
#include"Item.h"

class InventoryScene;

class LobbyScene
{
public:
	void runScene(Player* player, InventoryScene* inventory);
};

