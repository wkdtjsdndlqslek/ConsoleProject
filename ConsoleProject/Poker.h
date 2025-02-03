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
    //1~52까지 카드 설정
    void SetshapeNumber(int sn);

    //모양설정
    void SetShape(int s);

    //숫자설정
    void SetNumber(int n);

    std::string GetShape();

    int GetshapeNumber();

    int GetNumber();

    //카드 크기순으로 정렬
    void CardSort(int n[], std::string s[]);

    //카드 초기화 및 섞기
    void cardSetting(Poker c[]);

    // 몬스터 카드 뽑기
    void MonsterDraw(int n, Poker c[], int& u);

    // 카드 n장 뽑기
    void draw(int n, Poker c[], int& u);

    //가진 카드 보여주기
    void chooseCards(int u, Poker c[]);

    //버릴 카드 뽑기
    void chooseTrashCards(int u, Poker c[]);

    //가지고 있는 숫자가 로얄이라면
    std::string ifCardIsRoyal(int h);
    std::string ifCardIsRoyal(int n[]);

    //카드 출력 (함수 오버로딩)
    void PrintCard(int n[], std::string s[], int i);
    void PrintCard(Poker c[], int num);

    //최종 카드 출력
    void finalCards(int n[], std::string s[]);

    //페어 확인
    void CheckPair(int n[], std::string s[], int cphp[]);

    //탑, 스트레이트, 플러시 확인
    int CheckTopStrateFlush(int n[], std::string s[]);

    //족보 판별 및 공격력 배율 설정
    double checkNumRanking(int n[], std::string s[]);

    //결과 값
    void evaluate(Poker c[], int u, double& MAR, double& PAR, Player* player, Monster* monster, int stage);

    //포커 실행
    double playPoker(double& MAR, double& PAR, Player* player, Monster* moster, int stage);

    int  printMenu();
};