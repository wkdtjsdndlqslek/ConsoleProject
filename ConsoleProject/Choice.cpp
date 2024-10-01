#include "Choice.h"
#include<iostream>

int Choice::choiceYesOrNo()
{
    std::cout << "1.네 0.아니오" << std::endl;
    int choice;
    std::cin >> choice;
    return choice;
}
