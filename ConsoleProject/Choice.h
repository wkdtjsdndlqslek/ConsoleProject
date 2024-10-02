#pragma once
#include <iostream>

class Choice
{
public:
	int choiceYesOrNo()
	{
		int choice;
		while (1)
		{
			std::cout << "1.네 0.아니오" << std::endl;
			std::cin >> choice;
			if (choice == 1 || choice == 0)break;
			std::cout << "다시 입력해주세요." << std::endl;
		}
		return choice;
	}
};

