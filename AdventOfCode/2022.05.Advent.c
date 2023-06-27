#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// From a to b
void popo(char A[], char B[], int count, int a, int b)
{
	a--;
	for (int i = b; i < b + count; i++, a--)
	{
		if (a < 0)
		{
			break;
		}
		B[i] = A[a];
		A[a] = ' ';
	}	
}

void main()
{
	FILE* file;

	char line[36];
	int count, from, to;

	char K[50] = { 'Z', 'N'},
		L[50] = { 'M', 'C', 'D'},
		M[50] = { 'P'};

	int k = 2,
		l = 3,
		m = 1;

	char A[150] = {'B', 'V', 'S', 'N', 'T', 'C', 'H', 'Q' },
	   	B[150] = { 'W', 'D', 'B', 'G' },
		C[150] = { 'F', 'W', 'R', 'T', 'S', 'Q', 'B' },
		D[150] = { 'L', 'G', 'W', 'S', 'Z', 'J', 'D', 'N' },
		E[150] = { 'M', 'P', 'D', 'V', 'F' },
		F[200] = { 'F', 'W', 'J' },
		G[150] = { 'L', 'N', 'Q', 'B', 'J', 'V' },
		H[150] = { 'G', 'T', 'R', 'C', 'J', 'Q', 'S', 'N' },
		I[150] = { 'J', 'S', 'Q', 'C', 'W', 'D', 'M' };

	int a = 8,
		b = 4,
		c = 7,
		d = 8,
		e = 5,
		f = 3,
		g = 6,
		h = 8,
		i = 7;


	if ((fopen_s(&file, "input5.txt", "r")) == 0)
	{
		if (file == NULL)
		{
			printf("Error");
			exit(-1);
		}

		while (fgets(line, 36, file) != NULL)
		{

			sscanf_s(line, "move %d from %d to %d", &count, &from, &to);

			if (count < 0)
				continue;

			/*switch (from)
			{
			case 1:
				switch (to)
				{
				case 2: popo(K, L, count, k, l);
					k -= count;
					l += count;
					break;
				case 3: popo(K, M, count, k, m);
					k -= count;
					m += count;

					break;

				}
				break;
			case 2:
				switch (to)
				{
				case 1: popo(L, K, count, l, k);
					l -= count;
					k += count;
					break;
				case 3: popo(L, M, count, l, m);
					l -= count;
					m += count;

					break;

				}
				break;
			case 3:
				switch (to)
				{
				case 2: popo(M, L, count, m, l);
					m -= count;
					l += count;
					break;
				case 1: popo(M, K, count, m, k);
					m -= count;
					k += count;

					break;

				}
				break;
			}*/
			
			switch (from)
			{
			case 1:
				if (a < 0)
					continue;
				switch (to)
				{
				case 2: popo(A, B, count, a, b);
					a -= count;
					b += count;
					break;
				case 3: popo(A, C, count, a, c);
					a -= count;
					c += count;

					break;
				case 4:popo(A, D, count, a, d);
					a -= count;
					d += count;

					break;
				case 5:popo(A, E, count, a,e);
					a -= count;
					e += count;

					break;
				case 6:popo(A, F, count, a, f);
					a -= count;
					f += count;
					break;
				case 7:popo(A, G, count, a, g);
					a -= count;
					g += count;
					break;
				case 8:popo(A, H, count, a, h);
					a -= count;
					h += count;
					break;
				case 9:popo(A, I, count, a, i);
					a -= count;
					i += count;
					break;

				}
				break;
			case 2:
				if (b < 0)
					continue;
				switch (to)
				{
				case 1: popo(B, A, count, b, a);
					b -= count;
					a += count;
					break;
				case 3: popo(B, C, count, b, c);
					b -= count;
					c += count;

					break;
				case 4:popo(B, D, count, b, d);
					b -= count;
					d += count;

					break;
				case 5:popo(B, E, count, b, e);
					b -= count;
					e += count;

					break;
				case 6:popo(B, F, count, b, f);
					b -= count;
					f += count;
					break;
				case 7:popo(B, G, count, b, g);
					b -= count;
					g += count;
					break;
				case 8:popo(B, H, count, b, h);
					b -= count;
					h += count;
					break;
				case 9:popo(B, I, count, b, i);
					b -= count;
					i += count;
					break;

				}
				break;
			case 3:
				if (c < 0)
					continue;
				switch (to)
				{
				case 2: popo(C, B, count, c, b);
					c -= count;
					b += count;
					break;
				case 1: popo(C, A, count, c, a);
					c -= count;
					a += count;

					break;
				case 4:popo(C, D, count, c, d);
					c -= count;
					d += count;

					break;
				case 5:popo(C, E, count, c, e);
					c -= count;
					e += count;

					break;
				case 6:popo(C, F, count, c, f);
					c -= count;
					f += count;
					break;
				case 7:popo(C, G, count, c, g);
					c -= count;
					g += count;
					break;
				case 8:popo(C, H, count, c, h);
					c -= count;
					h += count;
					break;
				case 9:popo(C, I, count, c, i);
					c -= count;
					i += count;
					break;

				}
				break;
			case 4:
				if (d < 0)
					continue;
				switch (to)
				{
				case 2: popo(D, B, count, d, b);
					d -= count;
					b += count;
					break;
				case 3: popo(D, C, count, d, c);
					d -= count;
					c += count;

					break;
				case 1:popo(D, A, count, d, a);
					d -= count;
					a += count;

					break;
				case 5:popo(D, E, count, d, e);
					d -= count;
					e += count;

					break;
				case 6:popo(D, F, count, d, f);
					a -= count;
					f += count;
					break;
				case 7:popo(D, G, count, d, g);
					d -= count;
					g += count;
					break;
				case 8:popo(D, H, count, d, h);
					d -= count;
					h += count;
					break;
				case 9:popo(D, I, count, d, i);
					d -= count;
					i += count;
					break;

				}
				break;
			case 5:
				if (e < 0)
					continue;
				switch (to)
				{
				case 2: popo(E, B, count, e, b);
					a -= count;
					b += count;
					break;
				case 3: popo(E, C, count, e, c);
					e -= count;
					c += count;

					break;
				case 4:popo(E, D, count, e, d);
					e -= count;
					d += count;

					break;
				case 1:popo(E, A, count, e, a);
					e -= count;
					a += count;

					break;
				case 6:popo(E, F, count, e, f);
					e -= count;
					f += count;
					break;
				case 7:popo(E, G, count, e, g);
					e -= count;
					g += count;
					break;
				case 8:popo(E, H, count, e, h);
					e -= count;
					h += count;
					break;
				case 9:popo(E, I, count, e, i);
					e -= count;
					i += count;
					break;

				}
				break;
			case 6:
				if (f < 0)
					continue;
				switch (to)
			{
			case 2: popo(F, B, count, f, b);
				f -= count;
				b += count;
				break;
			case 3: popo(F, C, count, f, c);
				f -= count;
				c += count;

				break;
			case 4:popo(F, D, count, f, d);
				f -= count;
				d += count;

				break;
			case 5:popo(F, E, count, f, e);
				f -= count;
				e += count;

				break;
			case 1:popo(F, A, count, f, a);
				f -= count;
				a += count;
				break;
			case 7:popo(F, G, count, f, g);
				f -= count;
				g += count;
				break;
			case 8:popo(F, H, count, f, h);
				f -= count;
				h += count;
				break;
			case 9:popo(F, I, count, f, i);
				f -= count;
				i += count;
				break;

			}
				break;
			case 7:
				if (g < 0)
					continue;
				switch (to)
			{
			case 2: popo(G, B, count, g, b);
				g -= count;
				b += count;
				break;
			case 3: popo(G, C, count, g, c);
				g -= count;
				c += count;

				break;
			case 4:popo(G, D, count, g, d);
				g -= count;
				d += count;

				break;
			case 5:popo(G, E, count, g, e);
				g -= count;
				e += count;

				break;
			case 6:popo(G, F, count, g, f);
				g -= count;
				f += count;
				break;
			case 1:popo(G, A, count, g, a);
				g -= count;
				a += count;
				break;
			case 8:popo(G, H, count, g, h);
				g -= count;
				h += count;
				break;
			case 9:popo(G, I, count, g, i);
				g -= count;
				i += count;
				break;

			}
				break;
			case 8:
				if (h < 0)
					continue;
				switch (to)
			{
			case 2: popo(H, B, count, h, b);
				h -= count;
				b += count;
				break;
			case 3: popo(H, C, count, h, c);
				h -= count;
				c += count;

				break;
			case 4:popo(H, D, count, h, d);
				h -= count;
				d += count;

				break;
			case 5:popo(H, E, count, h, e);
				h -= count;
				e += count;

				break;
			case 6:popo(H, F, count, h, f);
				h -= count;
				f += count;
				break;
			case 7:popo(H, G, count, h, g);
				h -= count;
				g += count;
				break;
			case 1:popo(H, A, count, h, a);
				h -= count;
				a += count;
				break;
			case 9:popo(H, I, count, h, i);
				h -= count;
				i += count;
				break;

			}
				break;
			case 9:
				if (i < 0)
					continue;
				switch (to)
			{
			case 2: popo(I, B, count, i, b);
				i -= count;
				b += count;
				break;
			case 3: popo(I, C, count, i, c);
				i -= count;
				c += count;

				break;
			case 4:popo(I, D, count, i, d);
				i -= count;
				d += count;

				break;
			case 5:popo(I, E, count, i, e);
				i -= count;
				e += count;

				break;
			case 6:popo(I, F, count, i, f);
				i -= count;
				f += count;
				break;
			case 7:popo(I, G, count, i, g);
				i -= count;
				g += count;
				break;
			case 8:popo(I, H, count, i, h);
				i -= count;
				h += count;
				break;
			case 9:popo(I, A, count, i, a);
				i -= count;
				a += count;
				break;

			}
				break;

			}
		}


		
		printf("\n");
		for (int i = 0; i < a; i++)
		{
			printf("%c ", A[i]);
		}
		printf("\n");
		for (int i = 0; i < b; i++)
		{
			printf("%c ", B[i]);
		}
		printf("\n");
		for (int i = 0; i < c; i++)
		{
			printf("%c ", C[i]);
		}
		printf("\n");
		for (int i = 0; i < d; i++)
		{
			printf("%c ", D[i]);
		}
		printf("\n");
		for (int i = 0; i < e; i++)
		{
			printf("%c ", E[i]);
		}
		printf("\n");
		for (int i = 0; i < f; i++)
		{
			printf("%c ", F[i]);
		}
		printf("\n");
		for (int i = 0; i < g; i++)
		{
			printf("%c ", G[i]);
		}
		printf("\n");
		for (int i = 0; i < h; i++)
		{
			printf("%c ", H[i]);
		}
		printf("\n");
		for (int j = 0; j < i; j++)
		{
			printf("%c ", I[j]);
		}
		/*
		printf("\n\n\n");
		for (int i = 0; i < k; i++)
		{
			printf("%c ", K[i]);
		}
		printf("\n");
		for (int i = 0; i < l; i++)
		{
			printf("%c ", L[i]);
		}
		printf("\n");
		for (int j = 0; j < m; j++)
		{
			printf("%c ", M[j]);
		}*/

		fclose(file);
	}
}