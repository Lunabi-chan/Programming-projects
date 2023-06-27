#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
	float  n[3],
	      v1[3],
	      v2[3],
	      v3[3];
} trojuhelnik;

typedef struct {
	int pocet;
	trojuhelnik* trojuhelniky;
} objekt;

objekt nacti(char* path) {
	objekt out_with_you = { 0, NULL },
	       out_error = { 0, NULL };
	
	FILE* f = fopen(path, "rb");

	if (f == NULL || f == 0) {
		return out_error;
	}
	else {
		int poc = 0;
		
		fseek(f, 0, SEEK_SET);
		fseek(f, (80 * sizeof(uint8_t)), SEEK_CUR);
		fread(&poc, sizeof(uint32_t), 1, f);

		if (poc > 0) {
			out_with_you.pocet = poc;
			out_with_you.trojuhelniky = malloc((poc) * sizeof(trojuhelnik));
			
			if (out_with_you.trojuhelniky) {
				for (poc = 0; poc < out_with_you.pocet; poc++) {
					float *mop[4] = 
					{ out_with_you.trojuhelniky[poc].n , out_with_you.trojuhelniky[poc].v1, out_with_you.trojuhelniky[poc].v2, out_with_you.trojuhelniky[poc].v3 };

					for (int j = 0; j < 4; j++) {
						fread(mop[j], sizeof(float), 3, f);
					}

					fseek(f, sizeof(uint16_t), SEEK_CUR);
				}
			}
			else {
				return out_error;
			}

			if (fclose(f) == EOF) {
				printf("\nSoubor se dobre nezavrel.\n");
				return out_error;
			}
			else {
				return out_with_you;
			}
		}
		else {
			return out_error;
		}
	}
}

void vypis(objekt troy) {
	if (troy.pocet == 0) {
		printf("Prazdny objekt\n");
	}
	else {
		for (int i = 0; i < troy.pocet; i++) {
			trojuhelnik tray = troy.trojuhelniky[i];

			printf("Trojuhelnik %d\n", i + 1);
			printf("n  = [%4.6f, %4.6f, %4.6f]\n", tray.n[0], tray.n[1], tray.n[2]);
			printf("v1 = [%4.6f, %4.6f, %4.6f]\n", tray.v1[0], tray.v1[1], tray.v1[2]);
			printf("v2 = [%4.6f, %4.6f, %4.6f]\n", tray.v2[0], tray.v2[1], tray.v2[2]);
			printf("v3 = [%4.6f, %4.6f, %4.6f]\n\n", tray.v3[0], tray.v3[1], tray.v3[2]);
		}
	}
}

int uloz(char* path, objekt troj) {
	if (path && path != "\0") {
		FILE* f = fopen(path, "w");
		
		if (f) {
			fputs("solid\n\n", f);

			for (int i = 0; i < troj.pocet; i++) {
				fputs("facet normal ", f);

				for (int j = 0; j < 3; j++) {
					fprintf(f, "%f ", troj.trojuhelniky[i].n[j]);
				}
				fputs("\nouter loop\n", f);

				float *mop[3] = { troj.trojuhelniky[i].v1 , troj.trojuhelniky[i].v2, troj.trojuhelniky[i].v3};


				for (int j = 0; j < 3; j++) {
					fputs("vertex ", f);

					for (int k = 0; k < 3; k++) {
						fprintf(f ,"%f ", mop[j][k]);
					}

					fputs("\n", f);
				}

				fputs("endloop\nendfacet\n\n", f);
			}

			fputs("endsolid", f);

			if (fclose(f) == EOF) {
				printf("\nSoubor se dobre nezavrel.\n");
				return 0;
			}
			else {
				return 1;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

objekt sjednoceni(objekt a, objekt b) {
	objekt final = { a.pocet + b.pocet, malloc((a.pocet + b.pocet) * sizeof(trojuhelnik)) };

	if (final.trojuhelniky) {
		for (int i = 0; i < a.pocet; i++) {
			final.trojuhelniky[i] = a.trojuhelniky[i];

		} 
		for (int i = 0; i < b.pocet; i++) {
			final.trojuhelniky[i + a.pocet] = b.trojuhelniky[i];
		}

		return final;
	}
	else {
		objekt error = { 0, NULL };
		return error;
	}
	
}

void smaz(objekt *gon) {
	free(gon->trojuhelniky);

	gon->pocet = 0;
	gon->trojuhelniky = NULL;
}

void main() {
	objekt test = nacti("C:\\Users\\MlpLu\\Documents\\1 - University\\ZPC2\\binary.stl");
	objekt tset = nacti("C:\\Users\\MlpLu\\Documents\\1 - University\\ZPC2\\testbin.stl");
	
	objekt in = sjednoceni(test, tset);
	vypis(in);

	smaz(&in);
	vypis(in);

	printf("%d", uloz("C:\\Users\\MlpLu\\Documents\\1 - University\\ZPC2\\ASCII.txt", test));
}