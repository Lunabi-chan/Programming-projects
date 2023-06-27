#include <stdio.h>
#include "ZPC109 U09.inc"


void Yax(int x, int y, char znak, int delka)
{
	for (int j = x; j <= delka; ++j)
	{
		K[y][j] = znak;
	}
}

void Yay(int x, int y, char znak, int delka)
{
	for (int j = y; j <= delka; ++j)
	{
		K[j][x] = znak;
	}
}

void main()
{
	char z = 'X'; //znak

	for (int y = 0; y < RADKY; ++y)
		for (int x = 0; x < SLOUPCE; ++x)
			K[y][x] = ' ';

	int x = 0, y = 0, d = 0, s = 0; //x-ova souradice, y-ova souradnice, delka, smer
	
	for (int i = 0; i < KRESBA; i++)
	{
		switch (kresba[i].kod)
		{
		case 1:  x = kresba[i].u.x; break;
		case 2:  y = kresba[i].u.y; break;
		case 3:  z = kresba[i].u.znak;  break;
		case 4:  d = kresba[i].u.delka; break;
		case 5: 
			switch (kresba[i].u.smer)
			{
			case 0:  Yax(x, y, z, x + d); x += d; break;
			case 1:  Yay(x, y, z, y + d); y += d; break;
			case 2:  Yax(x - d, y, z, x); x -= d; break;
			case 3:  Yay(x, y - d, z, y); y -= d; break;
			default: printf("Error"); break;
			}
			break;
		default: printf("Error"); break;
		}
	}

	for (int y = 0; y < RADKY; ++y)
	{
		for (int x = 0; x < SLOUPCE; ++x)
			printf("%c", K[y][x]);
		printf("\n");
	}
}