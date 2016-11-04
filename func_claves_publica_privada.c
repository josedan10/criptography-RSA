int func_claves_publica_privada(int *p,int *q,int *d,int *e,int *n,	
	int (*mcd)(int, int),	
	int (*prime)(int *),
	int (*rand_num)(int *),	
	int (*rand_prime)(int *, int (*rand_num)(int *), int (*prime)(int *)))
{
	/*Input de los números para armar la clave*/


	int k;//Declaramos k de la relación k=(p-1)(q-1) que debe ser coprimo con e
	int i;
	
	//Generamos los números primos para la llave privada
	*p=(*rand_prime)(p, rand_num, prime);
	*q=(*rand_prime)(q, rand_num, prime);
	
	//Calculamos n
	*n=(*p)*(*q);

	//Calculamos k
	k=((*p)-1)*((*q)-1);

	//Calculamos e=i tal que i<k cumpla con que k=1(mod i)
	for (i=1; i<k; i++){
        if (mcd(i,k)==1){
           *e=i;
           break;
        }
	}
     //Aquí calculamos d

	*d=(k+1)/(*e);

}
