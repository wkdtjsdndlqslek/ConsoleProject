#pragma once
#include <iostream>
using namespace std;

class Unit
{
protected:
	string name;
	double Hp;
	int Att;
	int Money;
public:
	Unit(string n, double h, int a, int m);
	~Unit();
public:
	string GetName();
	void SetName(string n);
	int GetHp();
	void SetHp(double h);
	int GetAtt();
	void SetAtt(int a);
	int GetMoney();
	void SetMoney(int m);
	void Attack();
	void TakeDamage();

};

