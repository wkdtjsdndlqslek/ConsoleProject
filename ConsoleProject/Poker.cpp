#include<iostream>
#include "Poker.h"

void Poker::SetshapeNumber(int sn)
{
	shapeNumber = sn;
}

void Poker::SetShape(int s)
{
	if (s <= 13)
	{
		Shape = "♠";
	}
	else if (14 <= s && s <= 26)
	{
		Shape = "◆";
	}
	else if (27 <= s && s <= 39)
	{
		Shape = "♥";
	}
	else if (40 <= s && s <= 52)
	{
		Shape = "♣";
	}
}

void Poker::SetNumber(int n)
{
	if (n <= 13)
	{
		Number = n;
	}
	else if (14 <= n && n <= 26)
	{
		Number = n - 13;
	}
	else if (27 <= n && n <= 39)
	{
		Number = n - 26;
	}
	else if (40 <= n && n <= 52)
	{
		Number = n - 39;
	}
}

std::string Poker::GetShape()
{
	return Shape;
}

int Poker::GetshapeNumber()
{
	return shapeNumber;
}

int Poker::GetNumber()
{
	return Number;
}

void Poker::draw(int n, Poker c[], int& u)
{
	for (int i = 0; i < n; i++)
	{
		c[53 + i + u].SetNumber(c[i + u].GetNumber());
		c[53 + i + u].SetShape(c[i + u].GetshapeNumber());
		if (c[i + u].GetNumber() == 1)
		{
			std::cout << c[i + u].GetShape() << "A";
		}
		else if (c[i + u].GetNumber() == 11)
		{
			std::cout << c[i + u].GetShape() << "J";
		}
		else if (c[i + u].GetNumber() == 12)
		{
			std::cout << c[i + u].GetShape() << "Q";
		}
		else if (c[i + u].GetNumber() == 13)
		{
			std::cout << c[i + u].GetShape() << "K";
		}
		else
		{
			std::cout << c[i + u].GetShape() << c[i + u].GetNumber();
		}
		std::cout << "	";
	}
	std::cout << std::endl;
	u += n;
}

void Poker::chooseCards(int u, Poker c[])
{
	for (int i = 0; i < u; i++)
	{
		std::cout << i + 1 << ". ";

		if (c[53 + i].GetNumber() == 1)
		{
			std::cout << c[53 + i].GetShape() << "A";
		}
		else if (c[53 + i].GetNumber() == 11)
		{
			std::cout << c[53 + i].GetShape() << "J";
		}
		else if (c[53 + i].GetNumber() == 12)
		{
			std::cout << c[53 + i].GetShape() << "Q";
		}
		else if (c[53 + i].GetNumber() == 13)
		{
			std::cout << c[53 + i].GetShape() << "K";
		}
		else
		{
			std::cout << c[53 + i].GetShape() << c[53 + i].GetNumber();
		}
		std::cout << "		";
	}
}

void Poker::cardSetting(Poker c[])
{
	//52장 초기화

	for (int i = 0; i < 52; i++)
	{
		c[i].SetshapeNumber(i + 1);
	}

	//카드 셔플
	int temp, soar, dest;
	std::srand(time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		soar = rand() % 52;
		dest = rand() % 52;
		temp = c[soar].GetshapeNumber();
		c[soar].SetshapeNumber(c[dest].GetshapeNumber());
		c[dest].SetshapeNumber(temp);
	}

	//문양 숫자 넣기
	for (int i = 0; i < 52; i++)
	{
		c[i].SetShape(c[i].GetshapeNumber());
		c[i].SetNumber(c[i].GetshapeNumber());
	}
}

void PrintCard(Poker c[], int num)
{
	if (c[num].GetNumber() == 1)
	{
		std::cout << c[num].GetShape() << "A";
	}
	else if (c[num].GetNumber() == 11)
	{
		std::cout << c[num].GetShape() << "J";
	}
	else if (c[num].GetNumber() == 12)
	{
		std::cout << c[num].GetShape() << "Q";
	}
	else if (c[num].GetNumber() == 13)
	{
		std::cout << c[num].GetShape() << "K";
	}
	else
	{
		std::cout << c[num].GetShape() << c[num].GetNumber();
	}
}

void Poker::chooseTrashCards(int u, Poker c[])
{
	while (1)
	{
		std::cout << "버릴 카드를 선택해주세요." << std::endl;
		chooseCards(u, c);

		int throwCard;
		std::cin >> throwCard;

		if (throwCard == 1)
		{
			PrintCard(c, 53);
			std::cout << "를 버리셨습니다." << std::endl;
			c[53].SetNumber(0);
			break;
		}
		else if (throwCard == 2)
		{
			PrintCard(c, 54);
			std::cout << "를 버리셨습니다." << std::endl;
			c[54].SetNumber(0);
			break;
		}
		else if (throwCard == 3)
		{
			PrintCard(c, 55);
			std::cout << "를 버리셨습니다." << std::endl;
			c[55].SetNumber(0);
			break;
		}
		else if (throwCard == 4)
		{
			PrintCard(c, 56);
			std::cout << "를 버리셨습니다." << std::endl;
			c[56].SetNumber(0);
			break;
		}
		else
		{
			std::cout << "숫자를 다시 입력해주세요." << std::endl;
		}
	}
}

void Poker::playPoker()
{
	Poker cards[60];
	cardSetting(cards);

	//인게임, 카드 뽑기
	int usecard = 0;
	draw(4, cards, usecard);
	chooseTrashCards(usecard, cards);
	draw(2, cards, usecard);
}
