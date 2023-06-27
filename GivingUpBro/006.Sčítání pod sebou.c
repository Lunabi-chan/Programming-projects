#include <stdio.h>
#include <math.h>


void main()
{

	int x = 1234;
	int y = 4321;


	printf("Zadej x, y: ");
	scanf("%d %d", &x, &y);

	int z = 1, g = 1;
	int ir = 1;

	if (x < y)
	{
		int pom = x;
		x = y;
		y = pom;
	}

	while (z == 1)
	{
		if ((x / ir) > 0)
		{
			ir *= 10;
		}
		else
			z = 0;
	}

	ir /= 10;

	int mm = round(log(ir));

	for(; ir >= 1 ;ir /= 10)
	{
		g = (x / ir) + (y / ir);

		printf("%d %d %d %d ", (x / ir), (y / ir), g, ir);

		if (g > 9)
		{
			/*z += (g / ir) * ir * ir;
			printf("%d ", (g / ir) * ir);
			z += (g % ir) * ir;
			printf("%d ", (g % ir) * ir);
			*/

			z += g * ir;
		}
		else
			z += g * ir;

		printf("%d\n", z);

		x %= ir;
		y %= ir;
	}

	printf("%d", z);
}


