#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct { char Name; union { int a[]; } PC; } IDK;

int pomeranian = 0;

void main()
{
	FILE* file;
	char line[20];
	char Directories[500];
	int pAsInPain;
	char nAsInNameOfPain[20];

	int P1[10];
	int P2[10];
	int P3[10];

	P3[0] = 25;
	P3[1] = 32;
	P2[0] = P3;
	P1[0] = P2[0];


	printf("%d", );


	/*if (fopen_s(&file, "MiscInput.txt", "r") == 0)
	{
		while (fgets(&line, 20, file) != NULL)
		{
			//sscanf_s(line, "%c", &pAsInPain);

			switch (line[0])
			{
			case '$': 
				printf("\n Some kind of command that is: ");
				switch (line[3])
				{
				case 'd': printf("the command ");
					switch (line[5])
					{
					case '/': printf("Up up"); break;
					case '.': printf("Out out"); break;
					default: printf("Hop hop"); break;
					}
					break;
				case 's': printf("make a list"); break;
				}
					break;
			case 'd': printf("\nCreate a directory nghhh"); break;

			default: 
				sscanf_s(line, "%d   ", &pAsInPain);
				printf("\n %d", pAsInPain);

				Directories[pomeranian] = line;
				pomeranian++;

			}

			pAsInPain = -100;

		}
	}*/



}
