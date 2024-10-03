#include "Unit.h"

Unit::Unit(string n, double h, int a, int m):name(n),Hp(h),Att(a),Money(m)
{
}

Unit::~Unit()
{
}

string Unit::GetName()
{
	return name;
}

void Unit::SetName(string n)
{
	name = n;
}

int Unit::GetHp()
{
	return Hp;
}

void Unit::SetHp(double h)
{
	Hp = h;
}

int Unit::GetAtt()
{
	return Att;
}

void Unit::SetAtt(int a)
{
	Att = a;
}

int Unit::GetMoney()
{
	return Money;
}

void Unit::SetMoney(int m)
{
	Money = m;
}

void Unit::Attack()
{
	//GetAtt()* AttRatio();
}

void Unit::TakeDamage()
{
}
