#include <stdio.h>

typedef unsigned char byte;

void LPar(byte Z[], unsigned d)
{	// fce LPar doplni do znaku lichou paritu. V nejvyssim bitu ponechá 0 nebo doneho ulozi 1
	//		tak, aby pocet 1 ve vsech bitech byl lichy 

	for (int i = 0; i < d; i++)
	{
		if (has_even_parity(Z[i]) == 1)
		{
			Z[i] = Z[i] ^ 10000000;
		}
	}

	print_bin(Z, d);
}

unsigned TLPar(const byte Z[], unsigned d)
{	// fce TLPar zkontroluje u vsech znaku lichou paritu. Vrati pocet znaku, ktere lichou paritu nemaji

	unsigned p = 0;

	for (int i = 0; i < d; i++)
	{
		if (has_even_parity(Z[i]) == 1)
		{
			p++;
		}
	}

	return p;
}

void OLPar(byte Z[], unsigned d)
{	// fce OLPar odstrani u vsech znaku lichou paritu - do nejvyssiho bitu znaku vrati 0

	char S[26];

	/*for (int i = 97, j = 0; i < 123; i++, j++)
	{
		S[j] = i;
		Z[j] = S[j] & Z[j];
	}*/

	

	print_bin(Z, d);
}

int print_bin(byte Z[], unsigned d)
{
	for (int i = 0; i < d; i++)
	{
		printf("%c ", Z[i]);
	}
}

int has_even_parity(unsigned int x) 
{
	unsigned int count = 0, i, b = 1;

	for (i = 0; i < 8; i++) {
		if (x & (b << i)) 
		{ 
			count++; 
		}
	}

	if ((count % 2)) 
	{ 
		return 0; 
	}
	
	return 1;
}

void main()
{
	char S[26];

	for (int i = 97, j = 0; i < 123; i++, j++)
	{
		S[j] = i;
		printf("%c ", S[j]);
	}

	printf("\n\n");

	LPar(S, sizeof S / sizeof S[0]);
	printf("\n%d\n", TLPar(S, sizeof S / sizeof S[0]));
	OLPar(S, sizeof S / sizeof S[0]);
}