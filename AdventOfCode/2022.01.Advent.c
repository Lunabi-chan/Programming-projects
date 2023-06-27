#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int num, number = 0, Max = 0, pom;
	FILE* fptr;
	fopen_s(&fptr, "input.txt", "r");

	if (fptr == NULL)
	{
		printf("Error!");
		return 1;
		exit(-1);
	}

	char line[100];
	int Elves[3] = {0, 0, 0};


	if ((fopen_s(&fptr, "input.txt", "r")) == 0)
	{
		while (fgets(line, 100, fptr) != NULL)
		{
			sscanf_s(line, "%d", &num);
			number += num;

			if (strcmp(line, "\n") == 0)
			{
				number -= num;

				if (Max < number)
				{
					Max = number;
				}

				if (Elves[2] < number)
				{
					Elves[2] = number;
				}


				for (int i = 1, j = 2; i >= 0; i--)
				{
					if(Elves[i] < Elves[j])
					{
						pom = Elves[i];
						Elves[i] = Elves[j];
						Elves[j] = pom;
						j--;
					}
					
				}
				
				printf("\n");

				number = 0;
			}		
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", Elves[i]);
	}

	printf("\n %d", Elves[0] + Elves[2] + Elves[1]);

	fclose(fptr);
	return 0;


}