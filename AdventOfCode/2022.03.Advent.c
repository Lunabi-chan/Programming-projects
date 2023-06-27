#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numbah(char rucksack[], int i)
{
	for (int j = 0; j < i / 2; j++)
	{
		for (int k = i / 2; k < i; k++)
		{
			if (rucksack[j] == rucksack[k])
			{
				int l = rucksack[j];
				if (l > 96)
				{
					return l - 96;
				}
				else
				{
					return l - 38;
				}
			}
		}
	}
}

int numbah2(char rucksack[], int a, int b, int c)
{
	for (int j = 0; j < a; j++)
	{
		for (int k = a+1; k < b; k++)
		{
			if (rucksack[j] == rucksack[k])
			{
				for (int l = b+1; l < c; l++)
				{
					if (rucksack[j] == rucksack[l])
					{
						int m = rucksack[l];
						if (m > 96)
						{
							return m - 96;
						}
						else
						{
							return m - 38;
						}
					}
				}
			}
		}
	}
}

void main()
{
	// a-z = 1-26; A-Z = 27-52
	// 97-122 = a-z; 65-90 = A-Z; 

	FILE* file;
	char line[100], rucksack[50], group[300];
	int items = 0, priorities = 0;
	int i = 0, j = 0, m = 0, a = 0, b = 0, c = 0;

	if ((fopen_s(&file, "input3.txt", "r")) == 0)
	{
		if (file == NULL)
		{
			printf("Error!");
			return 1;
			exit(-1);
		}

		while (fgets(line, 2, file) != NULL)
		{
			sscanf_s(line, "%c", &rucksack[i]);

			i++;

			if (rucksack[i - 1] == '\n')
			{
				items += numbah(rucksack, i);
				char rucksack[50];
				i = 0;
			}
		}
	}
	fclose(file);


	// Task 2
	if ((fopen_s(&file, "input3.txt", "r")) == 0)
	{
		if (file == NULL)
		{
			printf("Error!");
			return 1;
			exit(-1);
		}

		while (fgets(line, 2, file) != NULL)
		{
			sscanf_s(line, "%c", &group[j]);

			if (group[j] == '\n')
			{
				m++;
				switch (m)
				{
				case 1:
					a = j; break;
				case 2:
					b = j; break;
				case 3:
					c = j;
					priorities += numbah2(group, a, b, c);
					char group[300];
					j = -1, m = 0; 
					break;

				default: printf("Error"); break;
				}
			}

			j++;
		}
	}

	items += numbah(rucksack, i);

	printf("\n1st task: %d\n", items);
	printf("2nd task: %d", priorities);

	fclose(file);
}