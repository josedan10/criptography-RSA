int func_claves_publica_privada(int (*mcd)(int, int),
	int (*prime)(int),
	int (*rand_num)(int),
	int (*rand_prime)(int (*rand_num)(int), int (*prime)(int))){
	/*Input de los números para armar la clave*/

    int var_p,var_q,var_n,var_d,var_e;

	int k;//Declaramos k de la relación k=(p-1)(q-1) que debe ser coprimo con e
	int i;

	//Generamos los números primos para la llave privada
	var_p=(*rand_prime)(rand_num,prime);
	var_q=(*rand_prime)(rand_num,prime);

	while(var_p==var_q){
		var_q=(*rand_prime)(rand_num,prime);
	}

	//Calculamos n
	var_n=(var_p)*(var_q);

	//Calculamos k
	k=((var_p)-1)*((var_q)-1);

	//Calculamos e=i tal que i<k cumpla con que k=1(mod i)
	for (i=2; i<k; i++){
        if (mcd(i,k)==1){
           var_e=i;
           break;
        }
	}
     //Aquí calculamos d

	var_d=(k+1)/(var_e);

	printf("Numeros de la clave privada: p=%d, q=%d y d=%d\n", var_p,var_q,var_d);
	printf("Los numeros de la clave publica son: e=%d y n=%d\n", var_e,var_n);

}
