#include<iostream>
#pragma once
#include "Monster.h"
#include "Player.h"
class Poker
{
private:

	std::string Shape;
	int shapeNumber;
	int Number;

public:
	//1~~52���� ī�� ����
	void SetshapeNumber(int sn);

	//���缳��
	void SetShape(int s);

	//���ڼ���
	void SetNumber(int n);

	std::string GetShape();

	int GetshapeNumber();

	int GetNumber();

	//ī�� ����ũ��� ����
	void CardSort(int n[],std::string s[]);

	//ī�� �ʱ�ȭ �� ����
	void cardSetting(Poker c[]);

	// ���� ī�� �̱�
	void MonsterDraw(int n, Poker c[], int& u);

	// ī�� n�� �̱�
	void draw(int n, Poker c[], int& u);

	//���� ī�� �����ֱ�
	void chooseCards(int u, Poker c[]);

	////���� ī�� �̱�
	void chooseTrashCards(int u, Poker c[]);
	
	//����� ���� ���ڰ� �ο��̶��
	std::string ifCardIsRoyal(int h);
	std::string ifCardIsRoyal(int n[]);

	//ī�� ��� (�Լ� �����ε�)
	void PrintCard(int n[],std::string s[],int i);
	void PrintCard(Poker c[], int num);

	//���� ī�� ���
	void finalCards(int n[], std::string s[]);

	//��� Ȯ��
	void CheckPair(int n[], std::string s[],int cphp[]);

	//ž, ��Ʈ����Ʈ, �÷��� Ȯ��
	int CheckTopStrateFlush(int n[], std::string s[]);

	//���� �Ǻ� �� ���ݷ� ��� ����
	double checkNumRanking(int n[],std::string s[]);

	//���� ��
	void evaluate(Poker c[],int u, double& MAR, double& PAR,Player* player, Monster* monster, int stage);
	
	//��Ŀ ����
	double playPoker(double& MAR, double& PAR, Player* player,Monster* moster, int stage);
	
	int  printMenu();
};

