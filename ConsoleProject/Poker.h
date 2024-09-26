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

	//문양설정
	void SetShape(int s);

	//숫자설정
	void SetNumber(int n);

	std::string GetShape();

	int GetshapeNumber();

	int GetNumber();
	//초기 카드 4장 뽑기
	void draw(int n, Poker c[], int& u);

	//버릴 카드 보여주기
	void chooseCards(int u, Poker c[]);

	//카드 초기화 및 셔플
	void cardSetting(Poker c[]);

	////버릴 카드 뽑기
	void chooseTrashCards(int u, Poker c[]);

	void playPoker();
};

