#pragma once
#include <Windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define SPACE 32
#define ENTER 13

class CursorControl
{
public:
	void gotoxy(int x, int y)
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x,y };
		SetConsoleCursorPosition(consoleHandle, pos);
	}
};

