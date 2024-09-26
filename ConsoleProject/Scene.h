#pragma once
#include <iostream>

class Scene
{
private:
	std::string sceneName;
	std::string sceneDesc;
public:
	Scene(std::string sn, std::string sd);
public:
	virtual void runScene()=0;
	virtual void PrintScene()=0;
};

