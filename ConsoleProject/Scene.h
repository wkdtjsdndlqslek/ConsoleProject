#pragma once
#include "Player.h"
#include <iostream>

class Scene
{
private:
	Player* player;
public:
	Scene() {
		player = new Player();
	}
public:
	virtual void runScene()=0;
	virtual void PrintScene()=0;
};

