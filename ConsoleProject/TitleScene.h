#pragma once
#include <iostream>
#include"Scene.h"

class TitleScene:public Scene
{
public:
	int runScene()override;
	void PrintScene()override;
};

