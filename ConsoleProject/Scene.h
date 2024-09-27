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
	virtual int runScene()=0;
	virtual void PrintScene()=0;
};

