#include<iostream>
#pragma once

class Poker
{
private:

	std::string Shape;
	int shapeNumber;
	int Number;

public:
	void SetshapeNumber(int sn);

	//���缳��
	void SetShape(int s);

	//���ڼ���
	void SetNumber(int n);

	std::string GetShape();

	int GetshapeNumber();

	int GetNumber();
	//�ʱ� ī�� 4�� �̱�
	void draw(int n, Poker c[], int& u);

	//���� ī�� �����ֱ�
	void chooseCards(int u, Poker c[]);

	//ī�� �ʱ�ȭ �� ����
	void cardSetting(Poker c[]);

	////���� ī�� �̱�
	void chooseTrashCards(int u, Poker c[]);

	void playPoker();
};

