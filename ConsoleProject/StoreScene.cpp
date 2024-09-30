#include "StoreScene.h"
#include"Player.h"
#include"Game.h"
#include"Item.h"

void StoreScene::runScene(Player* player)
{
	std::cout <<"�����ݾ�: "<< player->GetMoney() << endl;
	std::cout << "�����Ͻ� ������ ������" << std::endl;
	int choice;
	std::cin >> choice;
	

	

}

void StoreScene::SellingItems()
{
	sellingItems.push_back(Item("���� ī��", 10, 100));
	sellingItems.push_back(Item("�ö�ƽ ī��", 20, 500));
	sellingItems.push_back(Item("���� ī��", 30, 1000));
	sellingItems.push_back(Item("�� ī��", 100, 5000));
	sellingItems.push_back(Item("û�� ī��", 200, 10000));
	sellingItems.push_back(Item("ö ī��", 1000, 100000));
	sellingItems.push_back(Item("�ݰ��� ī��", 10000, 1000000));


}

void StoreScene::displaySellingItems(const std::vector<Item>& sellingItems) const
{
	for (size_t i=0;i<sellingItems.size();++i)
	{
		const Item& item = sellingItems[i];

		std::cout <<i+1<< item.GetItemName() << " ���ݷ� : " << item.GetItemAtt()<<" ���� : "<<item.GetPrice() << std::endl;
	}
}


