#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	//Rock
	int A = 1, X = 1, Rock = 1;
	//Paper
	int B = 2, Y = 2, Paper = 2;
	//Scissors
	int C = 3, Z = 3, Scissors = 3;
	// Win, Loss, Draw
	int W = 6, L = 0, D = 3;
	int TOTAL = 0, TOTAL2= 0;

	FILE* fptr;

	char line[10];
	char opp, me;

	if ((fopen_s(&fptr, "MiscInput.txt", "r")) == 0)
	{
		if (fptr == NULL)
		{
			printf("Error!");
			return 1;
			exit(-1);
		}

		while (fgets(line, 3, fptr) != NULL)
		{
			sscanf_s(line, "%c", &opp);

			fgets(line, 3, fptr);
			sscanf_s(line, " %c", &me);

			// 1st task
			switch (opp)
			{
			case 'A':
				switch (me)
				{
				case 'X': TOTAL += D + X; break;
				case 'Y': TOTAL += W + Y; break;
				case 'Z': TOTAL += L + Z; break;
				}
				break;
			case 'B':
				switch (me)
				{
				case 'X': TOTAL += L + X; break;
				case 'Y': TOTAL += D + Y; break;
				case 'Z': TOTAL += W + Z; break;
				}
				break;
			case 'C':
				switch (me)
				{
				case 'X': TOTAL += W + X; break;
				case 'Y': TOTAL += L + Y; break;
				case 'Z': TOTAL += D + Z; break;
				}
				break;
			}

			// 2nd task - X = lose, Y = draw, Z = win
			switch (opp)
			{
			case 'A': //Rock
				switch (me)
				{
				case 'X': TOTAL2 += L + Scissors; break;
				case 'Y': TOTAL2 += D + Rock; break;
				case 'Z': TOTAL2 += W + Paper; break;
				}
				break;
			case 'B': //Paper
				switch (me)
				{
				case 'X': TOTAL2 += L + Rock; break;
				case 'Y': TOTAL2 += D + Paper; break;
				case 'Z': TOTAL2 += W + Scissors; break;
				}
				break;
			case 'C': //Scissors
				switch (me)
				{
				case 'X': TOTAL2 += L + Paper; break;
				case 'Y': TOTAL2 += D + Scissors; break;
				case 'Z': TOTAL2 += W + Rock; break;
				}
				break;
			}
		}
	}

	printf("\n%d \n%d", TOTAL, TOTAL2);

	fclose(fptr);
	return 0;
}