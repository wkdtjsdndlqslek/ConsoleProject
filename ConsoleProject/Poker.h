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
	//1~~52장의 카드 설정
	void SetshapeNumber(int sn);

	//문양설정
	void SetShape(int s);

	//숫자설정
	void SetNumber(int n);

	std::string GetShape();

	int GetshapeNumber();

	int GetNumber();

	//카드 숫자크기로 정렬
	void CardSort(int n[],std::string s[]);

	//카드 초기화 및 셔플
	void cardSetting(Poker c[]);

	// 몬스터 카드 뽑기
	void MonsterDraw(int n, Poker c[], int& u);

	// 카드 n장 뽑기
	void draw(int n, Poker c[], int& u);

	//버릴 카드 보여주기
	void chooseCards(int u, Poker c[]);

	////버릴 카드 뽑기
	void chooseTrashCards(int u, Poker c[]);
	
	//페어의 높은 숫자가 로열이라면
	std::string ifCardIsRoyal(int h);
	std::string ifCardIsRoyal(int n[]);

	//카드 출력 (함수 오버로딩)
	void PrintCard(int n[],std::string s[],int i);
	void PrintCard(Poker c[], int num);

	//최종 카드 출력
	void finalCards(int n[], std::string s[]);

	//페어 확인
	void CheckPair(int n[], std::string s[],int cphp[]);

	//탑, 스트레이트, 플러쉬 확인
	int CheckTopStrateFlush(int n[], std::string s[]);

	//족보 판별 후 공격력 계수 설정
	double checkNumRanking(int n[],std::string s[]);

	//족보 평가
	void evaluate(Poker c[],int u, double& MAR, double& PAR,Player* player, Monster* monster, int stage);
	
	//포커 시작
	double playPoker(double& MAR, double& PAR, Player* player,Monster* moster, int stage);
	
	int  printMenu();
};

