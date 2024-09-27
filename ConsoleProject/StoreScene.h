#pragma once
#include"Scene.h"
#include<iostream>
#include<vector>
#include"Item.h"
class StoreScene:public Scene
{
protected:
	std::vector<Item> sellingItems;
public: 
	void runScene()override;
	
	void displayItem();


};

