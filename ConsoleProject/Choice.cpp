#include "Choice.h"
#include<iostream>

int Choice::choiceYesOrNo()
{
    std::cout << "1.�� 0.�ƴϿ�" << std::endl;
    int choice;
    std::cin >> choice;
    return choice;
}
