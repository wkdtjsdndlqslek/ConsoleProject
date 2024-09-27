#include "StoreScene.h"

void StoreScene::runScene()
{
}

void StoreScene::displayItem()
{
	sellingItems.push_back(Item("종이 카드", 10, 100));
	sellingItems.push_back(Item("플라스틱 카드", 20, 300));
	sellingItems.push_back(Item("나무 카드", 30, 500));
	sellingItems.push_back(Item("돌 카드", 100, 1000));
	sellingItems.push_back(Item("철 카드", 200, 3000));

}


