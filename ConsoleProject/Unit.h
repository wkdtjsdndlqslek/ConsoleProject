#pragma once
#include <iostream>
using namespace std;

class Unit
{
protected:
	string name;
	int Hp;
	int Att;
	int Money;
public:
	Unit(string n, int h, int a, int m);
	~Unit();
public:
	string GetName();
	void SetName(string n);
	int GetHp();
	void SetHp(int h);
	int GetAtt();
	void SetAtt(int a);
	int GetMoney();
	void SetMoney(int m);
	void Attack();
	void TakeDamage();

};

