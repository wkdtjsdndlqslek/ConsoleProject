#include "StoreScene.h"
#include"Player.h"

void StoreScene::runScene()
{
	std::cout <<"보유 금액"<< GetMoney() << std::endl;
	std::cout << "구매할 아이탬을 선택해 주세요." << std::endl;
	

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


