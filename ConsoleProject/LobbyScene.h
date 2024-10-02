#pragma once
#include<iostream>
class Player;
class Item;
class TitleScene;
class DungeonScene;
class StoreScene;
class InventoryScene;


class LobbyScene
{
public:
	void runScene(Player* player, InventoryScene* inventory);
	void PrintScene();
	int PrintMenu();
};

