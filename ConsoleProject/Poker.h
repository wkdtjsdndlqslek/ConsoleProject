#include<iostream>
#pragma once

class Poker
{
private:

	std::string Shape;
	int shapeNumber;
	int Number;

public:
	//1~~52장의 카드 설정
	void SetshapeNumber(int sn);

	//문양설정
	void SetShape(int s);

	//숫자설정
	void SetNumber(int n);

	std::string GetShape();

	int GetshapeNumber();

	int GetNumber();

	//카드 초기화 및 셔플
	void cardSetting(Poker c[]);

	//초기 카드 4장 뽑기
	void draw(int n, Poker c[], int& u);

	//버릴 카드 보여주기
	void chooseCards(int u, Poker c[]);

	////버릴 카드 뽑기
	void chooseTrashCards(int u, Poker c[]);
	
	//카드 출력
	void PrintCard(Poker c[], int num);

	//최종 카드 출력
	void finalCards(Poker c[]);

	//포커 시작
	void playPoker();

	//족보 평가
	void evaluate(Poker c[]);
	
	void checkNumRanking(int n[]);
};

