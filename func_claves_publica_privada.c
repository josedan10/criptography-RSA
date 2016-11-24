#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int func_claves_publica_privada(int(*mcd)(int, int),
	int(*prime)(int),
	int(*rand_num)(int),
	int(*rand_prime)(int(*rand_num)(int), int(*prime)(int)),
	int(*alg_euc_ext)(int prod, int coPrimoProd),
	int(*Inverso_Zn)(int,int,int (*alg_euc_ext)(int,int))) {

	/*<<< INVERSO MODULAR >>>*/
	/*int Inverso_Zn(int prod, int coPrimoProd, int (*alg_euc_ext)(int,int)) {
		int inverso;

		inverso = (*alg_euc_ext)(prod, coPrimoProd);

		if (inverso<0)inverso += prod;
		return inverso;
	};*/


	/*Input de los números para armar la clave*/

    int var_p,var_q,var_n,var_d=2,var_e=2, MCD;

	int k;//Declaramos k de la relación k=(p-1)(q-1) que debe ser coprimo con e
	int i;

	//Generamos los números primos para la llave privada
	do {
		var_p = (*rand_prime)(rand_num, prime);
		var_q = (*rand_prime)(rand_num, prime);


		while (var_p == var_q) {
			var_q = (*rand_prime)(rand_num, prime);
		}
		//Calculamos n
		var_n = (var_p)*(var_q);

	} while (var_n < 7897);



	//Calculamos k
	k=(var_p-1)*(var_q-1);

	//Calculamos e=i tal que i<k cumpla con que k=1(mod i)

	do{
       	var_e=rand()%(k-2)+2;
		MCD = (*mcd)(var_e, k);
	} while (MCD!= 1);
	
	//Aquí calculamos d
	do {
		var_d = (*Inverso_Zn)(k, var_e, alg_euc_ext);
	} while (var_d == var_e);
	

	//printf("k: %d\n",k);
	printf("Numeros de la clave privada: p=%d, q=%d y d=%d\n", var_p,var_q,var_d);
	printf("Los numeros de la clave publica son: e=%d y n=%d\n", var_e, var_n);
}