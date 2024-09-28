#include "StoreScene.h"

void StoreScene::runScene()
{

}

void StoreScene::displayItem()
{
	sellingItems.push_back(Item("종이 카드", 10, 100));
	sellingItems.push_back(Item("플라스틱 카드", 20, 500));
	sellingItems.push_back(Item("나무 카드", 30, 1000));
	sellingItems.push_back(Item("돌 카드", 100, 5000));
	sellingItems.push_back(Item("청동 카드", 200, 10000));
	sellingItems.push_back(Item("철 카드", 1000, 100000));
	sellingItems.push_back(Item("금강석 카드", 10000, 1000000));


}


