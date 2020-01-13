#include <stdio.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "winbgi2.h"

#define BOARD_EDGE 700
#define BOARD_MIDDLE 300
#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 1100
#define SNAKE_STEP 100
#define BASE_TIMEOUT 100

#define KB_UP 38 
#define KB_DOWN 40
#define KB_LEFT 37
#define KB_RIGHT 39

void rysuj();
void koloruj(int i, int j,int snakecolor);



int main()
{
	graphics(WINDOW_WIDTH, WINDOW_HEIGHT);

	int i, j;
	i = j = 0;

	rysuj();
		
	j = i = BOARD_MIDDLE;

	koloruj(i,j,60);

	char znak = 0, currentKey = 0;
	int  wynik;
	wynik = 0;
	int a, b;

	srand(time(NULL));

	a = (rand() % 7) * SNAKE_STEP;
	b = (rand() % 7) * SNAKE_STEP;

	int t = 0;
	while (-1 < i && i < BOARD_EDGE && -1 < j && j < BOARD_EDGE)
	{			
		clear();
		rysuj();
		koloruj(a,b,32);
		koloruj(i,j,60);
		
		if (kbhit() == 1)
			currentKey = getch();

		if (znak == currentKey)
		{
			Sleep(3 * BASE_TIMEOUT);
		}
		else
		{
			znak = currentKey;
		}
		if (kbhit() == 0)
		{
			switch (znak)
			{
			case KB_LEFT:
				i -= SNAKE_STEP;
				break;

			case KB_UP:
				j -= SNAKE_STEP;
				break;

			case KB_RIGHT:
				i += SNAKE_STEP;
				break;

			case KB_DOWN:
				j += SNAKE_STEP;
				break;
			}
		}
		if (a == i && b == j)
		{
			a = (rand() % 7) * SNAKE_STEP;
			b = (rand() % 7) * SNAKE_STEP;

			koloruj(a,b,32);
			wynik++;
			t++;
		}
		
		
	}
	printf("%d", wynik);
}

void koloruj(int i, int j, int snakecolor)
{
	int snakeGrid[] = { i,j,i + SNAKE_STEP,j,i + SNAKE_STEP,j + SNAKE_STEP,i,j + SNAKE_STEP };
	setfillstyle(1, snakecolor);
	fillpoly(4, snakeGrid);
}

void rysuj()
{
	int x, y;
	for (x = 0; x < 700; x += SNAKE_STEP)
		for (y = 0; y < 700; y += SNAKE_STEP)
		{
			line(x, y, x + SNAKE_STEP, y);
			line(x, y + SNAKE_STEP, x + SNAKE_STEP, y+SNAKE_STEP);
			line(x + SNAKE_STEP, y, x + SNAKE_STEP, y + SNAKE_STEP);
			line(x, y, x, y + SNAKE_STEP);			
		}
}

