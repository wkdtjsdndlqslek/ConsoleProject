#pragma once
#include<iostream>
#include<vector>
#include"Item.h"
class StoreScene
{
protected:
	std::vector<Item> sellingItems;
	
public: 
	void runScene(Player* player);
	
	void SellingItems();

	void displaySellingItems(const std::vector<Item>& SellingItems) const;


};

