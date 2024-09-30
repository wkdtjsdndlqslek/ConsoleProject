#include "Game.h"
#include "InventoryScene.h"
#include "BattleScene.h"
#include "LobbyScene.h"
#include "DungeonScene.h"

Game::Game()
{
	player = new Player();
}

Game::~Game()
{
	delete player;
}

void Game::RunGame()
{
	/*LobbyScene lobby;
	lobby.runScene(player);
	InventoryScene inventory;
	inventory.runScene(player);*/
	DungeonScene dungeon;
	dungeon.runScene(player);
	
}
