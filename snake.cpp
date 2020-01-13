#include <stdio.h>
#include <iostream>
#include <math.h>
#include "winbgi2.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void rysuj(int x, int y);
void koloruj(int i, int j, int* tab);
void gora(int i, int j, int* tab);
void dol(int i, int j, int* tab);
void lewo(int i, int j, int* tab);
void prawo(int i, int j, int* tab);
void zamaluj(int a, int b, int i, int j, int* tab);
int main()
{
	int x, y;
	x = y = 0;
	graphics(1100, 900);
	int i, j;
	i = j = 0;
			rysuj(x,y);
		
	j = i = 300;
	int tab[] = { i,j,i + 100,j,i + 100,j + 100,i,j + 100 };
	koloruj(i, j, tab);
	char znak = 0;
	int c, d, wynik;
	c = d = wynik = 0;
	int a, b;
	srand(time(NULL));
	a = (rand() % 7) * 100;
	b = (rand() % 7) * 100;
	int t = 0;
	int tab1[] = { a,b,a + 100,b,a + 100,b + 100,a,b + 100 };
	while (-1 < i && i < 700 && -1 < j && j < 700)
	{
		int tab[] = { i,j,i + 100,j,i + 100,j + 100,i,j + 100 };
		int tab1[] = { a,b,a + 100,b,a + 100,b + 100,a,b + 100 };
		if (a != i || b != j)
		
			clear();
			rysuj(x, y);
			koloruj(i, j, tab);
			koloruj(a, b, tab1);
		
		Sleep(0);
		
		
		if (kbhit() == 1)
		{
			znak = getch();

			if (znak == 37)
			{
				lewo(i, j, tab);
				
				
			}

			if (znak == 38)
			{

				gora(i, j, tab);	
				
			}
			if (znak == 39)
			{
				prawo(i, j, tab);

				

			}
			if (znak == 40)
			{
				dol(i, j, tab);
				
			}
		}
		Sleep(200);
		if(kbhit()==0)
		{ 
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
		}
		if (a == i && b == j)
		{
			a = (rand() % 7) * 100;
			b = (rand() % 7) * 100;

			koloruj(a, b, tab1);
			wynik++;
			t++;
		}
	}
	printf("%d", wynik);
}
void koloruj(int i, int j, int* tab)
{
	setfillstyle(1, 60);
	fillpoly(4, tab);
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
void gora(int i, int j, int* tab)
{
	koloruj(i, j - 100, tab);
}
void dol(int i, int j, int* tab)
{
	koloruj(i, j + 100, tab);
}
void lewo(int i, int j, int* tab)
{
	koloruj(i - 100, j, tab);
}
void prawo(int i, int j, int* tab)
{
	koloruj(i + 100, j, tab);
}
void zamaluj(int a, int b, int i, int j, int* tab)
{
	if ((a != i) || (b != j))
	{
		setfillstyle(1, 0);
		fillpoly(4, tab);
	}
}