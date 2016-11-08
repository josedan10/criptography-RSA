//Esta función utiliza el teorema de Eratóstenes para verificar si un número es primo

/*<<<<<-----------TEOREMA DE ERATÖSTENES ----------->>>>>*/

/* Un número p no es primo <=> existe algún n<=sqrt(p)| p%n=0 , n>=2*/

#include <math.h>


int primo(int p){
	int n; 

	for (n=2; n<=sqrt(p); n++){
		if(p%n==0){
		//Si el número no es primo devuelve 0
			return 0;
		}
	}
	//Si no encuentra algún número, entonces p es primo
	return 1;
}