#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int r, s, n;
	int resultado = 1;
	int j;

	printf("Numero: "); scanf("%d", &r);
	printf("\nexp: "); scanf("%d", &s);
	printf("\nmod: "); scanf("%d", &n);

	for (j = 1; j <= s; j++) {
		resultado *= r;
		//printf("%d\n",resultado);
		if (resultado>n) {
			resultado = resultado%n;
			//printf("resultado: %d\n",resultado);
		}
	}
	printf("\n\nEl resultado es %d\n", resultado);
	system("pause");

	return 0;
}