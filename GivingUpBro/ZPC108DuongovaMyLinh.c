#include <stdio.h>
#include "ZPC108 U08.inc"

void main()
{
	int k = sizeof nazev / sizeof nazev[0];
	
	for (Potravina p = 0; p < k; p++)
	{		
		printf("%s: ", nazev[p]);

		Jednotka m;
		Mnozstvi v; v.kus = 0; v.kg = 0;
		
		for (int i = 0; i < POHYB; i++)
		{
			if (p == pohyb[i].potr)
			{
				m = pohyb[i].jedn;
				if (m == 1)
				{
					v.kus += pohyb[i].mnoz.kus;
				}
				else	
					v.kg += pohyb[i].mnoz.kg;
			}
		}

		if (m == 2)
			printf("%g kg\n", v.kg);
		else
			printf("%d kusu\n", v.kus);
	}	
}