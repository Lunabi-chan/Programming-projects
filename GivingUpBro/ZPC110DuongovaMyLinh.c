#include <stdio.h>

void TiskPomlcek(int kolik, int odsazeni)
{
	printf("\n");

	for (int i = 0; i < odsazeni; i++)
	{
		printf(" ");
	}

	for (int i = 0; i < kolik; i++)
	{
		printf("%c", '-');
	}
}

void Pole(int start, int finish, int ods, int jstart, int x)
{
	for (int i = start, j = jstart; i < finish; i++)
	{
		if ((i % ods) == 0 && (i != start))
		{
			printf("%2c", '|');
		}		

		if (i == finish - 1)
		{
			printf(" %c", '|');
			continue;
		}

		if ((i % ods) == 0)
		{
			if (x == 2)
			{printf("\n%2d0%c", j, '|');
			j++; }

			if (x==3)
			{
				printf("\n%3d0%c", j, '|');
				j++;
			}			
		}

		if (start == 30)
		{
			for (; i < start + 2; i++)
			{
				printf("%2c", ' ');
			}
		}

		if (i > 126)
		{
			for (; i < finish; i++)
			{
				printf("%2c", ' ');
			}
			break;
		}

		printf("%2c", i);
	}
}

void ToTamto()
{
	char wall = '|';

	printf("    ");

	// 48 - 57 65-70
	for (int i = 48; i <= 70; i++)
	{
		if (i == 58)
		{
			i = 65;
		}
		printf("%2c", i);

	}

	TiskPomlcek(35, 3);

	Pole(32, 8*16, 16, 2, 2);

	printf("%2c", wall);
	TiskPomlcek(35, 3);
}

void Toto()
{
	char wall = '|';

	printf("     ");

	for (int i = 48; i <= 57; i++)
	{
		printf("%2c", i);
	}

	TiskPomlcek(23, 4);

	Pole(30, 130, 10, 3, 3);

	printf("%2c", wall);
	TiskPomlcek(23, 4);
}

void main()
{
	ToTamto();
	printf("\n\n");

	Toto();
	printf("\n\n");
}