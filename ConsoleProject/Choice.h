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
			std::cout << "1.�� 0.�ƴϿ�" << std::endl;
			std::cin >> choice;
			if (choice == 1 || choice == 0)break;
			std::cout << "�ٽ� �Է����ּ���." << std::endl;
		}
		return choice;
	}
};

