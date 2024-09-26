#pragma once
#include <iostream>
#include"Scene.h"

class TitleScene:public Scene
{
public:
	void runScene()override;
	void PrintScene()override;
};

