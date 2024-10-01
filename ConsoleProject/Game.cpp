#include "Game.h"
#include "InventoryScene.h"
#include "BattleScene.h"
#include "LobbyScene.h"
#include "DungeonScene.h"
#include "TitleScene.h"
#include"InventoryScene.h"

Game::Game()
{
	player = new Player();
	inventory = new InventoryScene();
}

Game::~Game()
{
	delete player;
}

void Game::RunGame()
{
	TitleScene title;
	title.runScene(player,inventory);

	
}
