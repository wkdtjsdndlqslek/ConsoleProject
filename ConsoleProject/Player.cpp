#include "Player.h"
#include "Unit.h"

Player::Player():Unit("플레이어", 1000, 20, 0)
{
	std::cout << "플레이어 이름을 입력하세요." << std::endl;
	string playerName;
	cin >> playerName;
	name = playerName;
}

Player::~Player()
{
}

void Player::EarnMoney(int money)
{
	Money += money;
}


void Player::EquippedItem(Item& item)
{
	equippedItems.push_back(item);
	Att+=item.GetItemAtt();
}

void Player::UnEquippedItem(Item& item)
{

}



