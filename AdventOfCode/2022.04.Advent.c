#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	FILE* file;

	char line[15];
	int froma, toa, fromb, tob, count = 0, count2 = 0;


	if ((fopen_s(&file, "input4.txt", "r")) == 0)
	{
		if (file == NULL)
		{
			printf("Error");
			exit(-1);
		}

		while (fgets(line, 15, file) != NULL)
		{
			sscanf_s(line, "%d-%d,%d-%d", &froma, &toa, &fromb, &tob);

			if ((froma <= fromb && tob <= toa) || (fromb <= froma && toa <= tob))
			{
				count++;
			}

			if ((froma == tob) || (fromb == toa) || (froma >= fromb && froma <= tob) || (fromb >= froma && fromb <= toa) || (toa >= fromb && toa <= tob) || (tob >= froma && tob <= toa))
			{
				count2++;
			}
		}
	}

	printf("\n1st task: %d\n2nd task: %d", count, count2);

	fclose(file);
}