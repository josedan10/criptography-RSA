#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>

/*<<< ALGORITMO DE EUCLIDES EXTENDIDO>>>*/
int alg_euc_ext(int prod, int coPrimoProd) {
	int q=0, r=0, y1 = 1, y2=0, y=0;
	while (coPrimoProd > 0) {
		q = prod / coPrimoProd;
		r = prod - (q*coPrimoProd);
		y = y2 - (q*y1);
		prod = coPrimoProd;
		coPrimoProd = r;

		y2 = y1;
		y1 = y;
	}
	return y2;
}