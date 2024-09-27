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
		Shape = "��";
	}
	else if (14 <= s && s <= 26)
	{
		Shape = "��";
	}
	else if (27 <= s && s <= 39)
	{
		Shape = "��";
	}
	else if (40 <= s && s <= 52)
	{
		Shape = "��";
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

void Poker::CardSort(int n[],std::string s[])
{
	
	for (int i = 0; i < 5; i++)//���ϴ� ù��° ��
	{
		for (int k = 4; k > i; k--)//���ϴ� �ι�° ��
		{
			if (n[i] > n[k])
			{
				int temp;
				temp = n[i];
				n[i] = n[k];
				n[k] = temp;
				std::string shapeTemp;
				shapeTemp = s[i];
				s[i] = s[k];
				s[k] = shapeTemp; 
			}
		}
	}
}

void Poker::draw(int n, Poker c[], int& u)
{
	std::cout << n << "�� ��ο�" << std::endl;
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

void Poker::MonsterDraw(int n, Poker c[], int& u)
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
	//52�� �ʱ�ȭ

	for (int i = 0; i < 52; i++)
	{
		c[i].SetshapeNumber(i + 1);
	}

	//ī�� ����
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

	//���� ���� �ֱ�
	for (int i = 0; i < 52; i++)
	{
		c[i].SetShape(c[i].GetshapeNumber());
		c[i].SetNumber(c[i].GetshapeNumber());
	}
}

void Poker::PrintCard(int n[],std::string s[],int i)
{
	if (n[i] == 1)
	{
		std::cout << s[i] << "A";
	}
	else if (n[i] == 11)
	{
		std::cout << s[i] << "J";
	}
	else if (n[i] == 12)
	{
		std::cout << s[i] << "Q";
	}
	else if (n[i] == 13)
	{
		std::cout << s[i] << "K";
	}
	else
	{
		std::cout << s[i] << n[i];
	}
}

void Poker::PrintCard(Poker c[], int num)
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
		std::cout << "���� ī�带 �������ּ���." << std::endl;
		chooseCards(u, c);

		int throwCard;
		std::cin >> throwCard;

		if (throwCard == 1)
		{
			PrintCard(c, 53);
			std::cout << "�� �����̽��ϴ�." << std::endl;
			c[53].SetNumber(0);
			break;
		}
		else if (throwCard == 2)
		{
			PrintCard(c, 54);
			std::cout << "�� �����̽��ϴ�." << std::endl;
			c[54].SetNumber(0);
			break;
		}
		else if (throwCard == 3)
		{
			PrintCard(c, 55);
			std::cout << "�� �����̽��ϴ�." << std::endl;
			c[55].SetNumber(0);
			break;
		}
		else if (throwCard == 4)
		{
			PrintCard(c, 56);
			std::cout << "�� �����̽��ϴ�." << std::endl;
			c[56].SetNumber(0);
			break;
		}
		else
		{
			std::cout << "���ڸ� �ٽ� �Է����ּ���." << std::endl;
		}
	}
}

void Poker::CheckPair(int n[], std::string s[],int cphp[])
{
	int checkPair = 0;
	int highPair=0;
	int triple = 0;
	for (int i = 0; i < 5; i++)//���ϴ� ù��° ��
	{
		for (int k = 4; k > i; k--)//���ϴ� �ι�° ��
		{
			if (n[i] == n[k])
			{
				checkPair++;
				highPair = n[i];
			}
		}
		if (checkPair == 3)
		{
			triple = n[i];
		}
	}
	cphp[0] = checkPair;
	cphp[1] = highPair;
	cphp[2] = triple;
}

int Poker::CheckTopStrateFlush(int n[],std::string s[])
{
	int checkTopStrateFlush = 0;
	//�÷��� Ȯ��
	if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[3] == s[4])
	{
		checkTopStrateFlush++;
	}
	//��Ʈ����Ʈ Ȯ��
	if (n[4] == n[3] + 1 && n[3] == n[2] + 1 && n[2] == n[1] + 1 && n[1] == n[0] + 1)
	{
		checkTopStrateFlush += 2;
	}
	//�ο� ��Ʈ����Ʈ Ȯ��
	if (n[0] == 1 && n[1] == 10 && n[2] == 11 && n[3] == 12 && n[4] == 13)
	{
		checkTopStrateFlush += 10;
	}
	return checkTopStrateFlush;
}

void Poker::checkNumRanking(int n[], std::string s[])
{
	int checkPairHighPair[3];//CheckPair�� ���� ���� �� �� �޾ƿ��� ���� ���� �迭
	CheckPair(n,s,checkPairHighPair);
	int CP = checkPairHighPair[0];
	int HP = checkPairHighPair[1];//HP�� ��� �� ���� ���� 
	int triple = checkPairHighPair[2];//triple�� Ǯ�Ͽ콺�� ���� �� �� ���� ������ �� �ƴ� Ʈ������ ���ڸ� �������� ����.
	if (CP == 4)//�÷��� ���� �켱 ����
	{
		std::cout <<triple<< " FULL HOUSE�Դϴ�." << std::endl;
	}
	else if (CP == 6)//�÷��� ���� �켱 ����
	{
		std::cout << HP << " FOUR CARD�Դϴ�." << std::endl;
	}
	else if (CP ==0)
	{	int CTSF = CheckTopStrateFlush(n, s);
		if (CTSF == 1)
		{
			std::cout << n[4]<<" FLUSH�Դϴ�." << std::endl;
		}
		else if (CTSF == 2)
		{
			std::cout << n[4] <<" STRATE�Դϴ�." << std::endl;
		}
		else if (CTSF == 3)
		{
			std::cout << n[4] << " STRATE FLUSH�Դϴ�." << std::endl;
		}
		else if (CTSF == 11)
		{
			std::cout << " ROYAL STRATE FLUSH�Դϴ�." << std::endl;
		}
		else
		{
			std::cout << n[4] << " TOP�Դϴ�." << std::endl;
		}
	}
	else if (CP == 1)
	{
		std::cout << HP<< " ONE PAIR�Դϴ�." << std::endl;
	}
	else if (CP == 2)
	{
		std::cout << HP << " TWO PAIR�Դϴ�." << std::endl;
	}
	else if (CP == 3)
	{
		std::cout << HP << " TRIPLE�Դϴ�." << std::endl;
	}
	
	
	
}

void Poker::evaluate(Poker c[],int u)
{
	std::cout << "������ ī��" << std::endl;
	MonsterDraw(5, c, u);
	int playernum[5];
	std::string playershape[5];
	for (int i = 0; i < 5; i++)
	{
		if (c[53 + i].GetNumber()!=0)
		{
			playernum[i] = c[53 + i].GetNumber();
		}
		else if (c[53 + i].GetNumber() == 0)
		{
			playernum[i] = c[58].GetNumber();
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (c[53 + i].GetNumber() != 0)
		{
			playershape[i] = c[53 + i].GetShape();
		}
		else if (c[53 + i].GetNumber() == 0)
		{
			playershape[i] = c[58].GetShape();
		}
	}
	int Monsternum[5];
	std::string Monstershape[5];
	for (int i = 0; i < 5; i++)
	{
		if (c[59 + i].GetNumber() != 0)
		{
			Monsternum[i] = c[59 + i].GetNumber();
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (c[59 + i].GetNumber() != 0)
		{
			Monstershape[i] = c[59 + i].GetShape();
		}
	}

	CardSort(playernum, playershape);
	CardSort(Monsternum, Monstershape);
	std::cout << "���ʹ� ";
	checkNumRanking(Monsternum, Monstershape);
	finalCards(playernum, playershape);
	std::cout << "����� ";
	checkNumRanking(playernum, playershape);
	
}

void Poker::finalCards(int n[],std::string s[])
{
	std::cout << "���� ī��" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (n[i] == 0)
		{
		}
		else
		{
			PrintCard(n,s,i);
			std::cout << "	";
		}

	}
}


void Poker::playPoker()
{
	Poker cards[64];
	cardSetting(cards);

	//�ΰ���, ī�� �̱�
	int usecard = 0;
	draw(4, cards, usecard);
	std::cout<<std::endl;
	chooseTrashCards(usecard, cards);
	draw(2, cards, usecard);
	std::cout << std::endl;
	evaluate(cards, usecard);
}


