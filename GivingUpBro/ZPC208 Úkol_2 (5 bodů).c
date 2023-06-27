#include <stdio.h>
#include <stdarg.h>

#define X 0.0
#define Y 0.0
#define KONEC -1.025478

typedef struct {
	double x, y, polomer;
} kruznice;

kruznice vytvor(double polomer, ...) { // bere 1 povinny parametr - polomer 
	va_list parametry;
	kruznice kruz;
	kruz.polomer = polomer;
	
	double x_in, y_in;

	va_start(parametry, polomer); 

	if ((x_in = va_arg(parametry, double)) == KONEC) {
		kruz.x = X;
		kruz.y = Y;
	}
	else {
		if ((y_in = va_arg(parametry, double)) == KONEC) {
			kruz.x = x_in;
			kruz.y = x_in; // jestli jsem to pochopila spravne, tak jestli je zadan jen 1 nepovinny parametr, tak se stava x-ovou i y-ovou souradnici kruznice
		}                                   // jinak kruz.y = Y; -> kde x_in bylo nahrazeno makrem Y
		else {
			kruz.x = x_in;
			kruz.y = y_in;
		}
	}	

	va_end(parametry);

	return kruz;
}

double myPow_2(double n) {
	return ((n) * (n));
}

double sqrt(double x);

int poloha_bodu(kruznice objekt, double x, double y) {
	double hodnota = sqrt(myPow_2(x - objekt.x) + myPow_2(y - objekt.y));
	return hodnota == objekt.polomer ? 0 : hodnota > objekt.polomer ? -1 : 1;  
} // Vraci 0 jestli bod lezi na kruznici, 1 jestli je uvnitr kruznice a -1 jestlu vne

void main() {
	/*
	kruznice a = vytvor(5, KONEC);
	kruznice b = vytvor(5, 1.0, KONEC);
	kruznice c = vytvor(5, 1.0, 2.0, KONEC);

	printf("a: %.2f %.2f %.2f\n", a.polomer, a.x, a.y);
	printf("b: %.2f %.2f %.2f\n", b.polomer, b.x, b.y);
	printf("c: %.2f %.2f %.2f\n\n", c.polomer, c.x, c.y);

	printf("Bod K[4, 3]: %d\n", poloha_bodu(a, 4, 3));
	printf("Bod K[1, 1]: %d\n", poloha_bodu(a, 1, 1));
	printf("Bod K[9, 9]: %d\n", poloha_bodu(a, 9, 9));
	*/
}