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

void rysuj(int x, int y);
void koloruj(int i, int j);
void gora(int i, int j);
void dol(int i, int j);
void lewo(int i, int j);
void prawo(int i, int j);


int main()
{
	int x, y;
	x = y = 0;

	graphics(WINDOW_WIDTH, WINDOW_HEIGHT);

	int i, j;
	i = j = 0;

	rysuj(x,y);
		
	j = i = BOARD_MIDDLE;

	koloruj(i, j);

	char znak = 0;
	int c, d, wynik;
	c = d = wynik = 0;
	int a, b;

	srand(time(NULL));

	a = (rand() % 7) * 100;
	b = (rand() % 7) * 100;

	int t = 0;
	while (-1 < i && i < 700 && -1 < j && j < 700)
	{			
		clear();
		rysuj(x, y);
		koloruj(i, j);
		koloruj(a, b);
		
		Sleep(0);

		if (kbhit() == 1)
		{
			znak = getch();

			if (znak == 37)
			{
				lewo(i, j);
				
			}

			if (znak == 38)
			{

				gora(i, j);	
				
			}
			if (znak == 39)
			{
				prawo(i, j);

			}
			if (znak == 40)
			{
				dol(i, j);
				
			}
		}
		Sleep(200);
		 
		if (znak == 37)
		{
			i -= 100;
		}
		if (znak == 38)
		{
			j -= 100;
		}
		if (znak == 39)
		{
			i += 100;
		}
		if (znak == 40)
		{
			j += 100;
		}
		
		if (a == i && b == j)
		{
			a = (rand() % 7) * 100;
			b = (rand() % 7) * 100;

			koloruj(a, b);
			wynik++;
			t++;
		}
	}
	printf("%d", wynik);
}

void koloruj(int i, int j)
{
	int snakeGrid[] = { i,j,i + 100,j,i + 100,j + 100,i,j + 100 };
	setfillstyle(1, 60);
	fillpoly(4, snakeGrid);
}

void rysuj(int x, int y)
{
	for (x = 0; x < 700; x += 100)
		for (y = 0; y < 700; y += 100)
		{
			line(x, y, x + 100, y);
			line(x, y + 100, x + 100, y+100);
			line(x + 100, y, x + 100, y + 100);
			line(x, y, x, y + 100);			
		}
}

void gora(int i, int j)
{
	koloruj(i, j - 100);
}

void dol(int i, int j)
{
	koloruj(i, j + 100);
}

void lewo(int i, int j)
{
	koloruj(i - 100, j);
}

void prawo(int i, int j)
{
	koloruj(i + 100, j);
}
