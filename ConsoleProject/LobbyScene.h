#pragma once
#include"Scene.h"
#include<iostream>
class LobbyScene: public Scene
{
public:
	int runScene()override;
	void PrintScene()override;
};

