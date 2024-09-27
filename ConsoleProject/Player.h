#pragma once
#include"Unit.h"
using namespace std;

class Player :public Unit
{
public:
	Player(string n, int a, int h, int m);
public:
	void EarnMoney();
};

