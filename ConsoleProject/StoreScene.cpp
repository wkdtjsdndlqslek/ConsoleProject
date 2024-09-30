#include "StoreScene.h"
#include"Player.h"
#include"Game.h"
#include"Item.h"

void StoreScene::runScene(Player* player)
{
	std::cout <<"소지금액: "<< player->GetMoney() << endl;
	std::cout << "구매하실 물건을 고르세요" << std::endl;
	int choice;
	std::cin >> choice;
	

	

}

void StoreScene::SellingItems()
{
	sellingItems.push_back(Item("종이 카드", 10, 100));
	sellingItems.push_back(Item("플라스틱 카드", 20, 500));
	sellingItems.push_back(Item("나무 카드", 30, 1000));
	sellingItems.push_back(Item("돌 카드", 100, 5000));
	sellingItems.push_back(Item("청동 카드", 200, 10000));
	sellingItems.push_back(Item("철 카드", 1000, 100000));
	sellingItems.push_back(Item("금강석 카드", 10000, 1000000));


}

void StoreScene::displaySellingItems(const std::vector<Item>& sellingItems) const
{
	for (size_t i=0;i<sellingItems.size();++i)
	{
		const Item& item = sellingItems[i];

		std::cout <<i+1<< item.GetItemName() << " 공격력 : " << item.GetItemAtt()<<" 가격 : "<<item.GetPrice() << std::endl;
	}
}


