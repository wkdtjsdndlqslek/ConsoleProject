#include "StoreScene.h"
#include"Player.h"

void StoreScene::runScene()
{
	std::cout <<"���� �ݾ�"<< GetMoney() << std::endl;
	std::cout << "������ �������� ������ �ּ���." << std::endl;
	

}

void StoreScene::displayItem()
{
	sellingItems.push_back(Item("���� ī��", 10, 100));
	sellingItems.push_back(Item("�ö�ƽ ī��", 20, 500));
	sellingItems.push_back(Item("���� ī��", 30, 1000));
	sellingItems.push_back(Item("�� ī��", 100, 5000));
	sellingItems.push_back(Item("û�� ī��", 200, 10000));
	sellingItems.push_back(Item("ö ī��", 1000, 100000));
	sellingItems.push_back(Item("�ݰ��� ī��", 10000, 1000000));


}


