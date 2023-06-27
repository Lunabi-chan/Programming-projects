#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int y, x; // coordinates of H
int b, a; // coordinates of T

char checkerboard[1000][1000];

void CheckTea()
{
	int tEa = abs(y-b);
	int teA = abs(x-a);

	if (tEa > 1 || teA > 1)
	{
		if (y - b > 0)
			b += 1;
		if (y - b < 0)
			b -= 1;
		else
			b += 0;

		if (x - a > 0)
			a += 1;
		if (x - a < 0)
			a -= 1;
		else
			a += 0;
	}
	checkerboard[b][a] = '#';
}

void MoveH(char board[][1000], char where, int howmucho)
{
	// R is right, U is up, L is left, D is geddan
	switch (where)
	{
	case 'R':
		for (int i = x + howmucho; i > x; x++)
		{
			board[y][x] = 'x';
			CheckTea();
		}
		break;
	case 'U':
		for (int i = y - howmucho; i < y; y--)
		{
			board[y][x] = 'x';
			CheckTea();
		}
		break;
	case 'L':
		for (int i = x - howmucho; i < x; x--)
		{
			board[y][x] = 'x';
			CheckTea();
		}
		break;
	case 'D':
		for (int i = y + howmucho; i > y; y++)
		{
			board[y][x] = 'x';
			CheckTea();
		}
		break;
	}
	board[y][x] = 'H';
}

void main()
{
	char board[1000][1000];

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			//board[i][j] = '.';
			checkerboard[i][j] = '.';
		}
	}

	board[500][500] = 'H';

	FILE* file;

	char line[10], where;
	int howmucho, count = 0;

	if ((fopen_s(&file, "input09.txt", "r")) == 0)
	{
		fgets(line, 4, file);
	
		where = line[0];
		howmucho = line[2] - 48;

		y = 150, x = 100;
		b = 150, a = 100;


		MoveH(board, where, howmucho);

		while(fgets(line, 4, file) != NULL)
		{ 
			where = line[0];
			howmucho = line[2] - 48;
			MoveH(board, where, howmucho);
		}
	}

	board[500][700] = 's';
	checkerboard[150][100] = 'S';
	checkerboard[150][0] = '-';
	checkerboard[0][100] = '-';

	printf("\n\n");

	for (int i = 0; i < 250; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			printf("%c", checkerboard[i][j]);
			if (checkerboard[i][j] == '#')
				count++;
		}
		printf("\n");
	}

	printf("%d", count);
	fclose(file);
	return 0;
}