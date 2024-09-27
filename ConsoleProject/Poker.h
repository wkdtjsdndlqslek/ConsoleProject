#include<iostream>
#pragma once

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

	//ī�� �ʱ�ȭ �� ����
	void cardSetting(Poker c[]);

	//�ʱ� ī�� 4�� �̱�
	void draw(int n, Poker c[], int& u);

	//���� ī�� �����ֱ�
	void chooseCards(int u, Poker c[]);

	////���� ī�� �̱�
	void chooseTrashCards(int u, Poker c[]);
	
	//ī�� ���
	void PrintCard(Poker c[], int num);

	//���� ī�� ���
	void finalCards(Poker c[]);

	//��Ŀ ����
	void playPoker();

	//���� ��
	void evaluate(Poker c[]);
	
	void checkNumRanking(int n[]);
};

