void func_claves_publica_privada(double *p,double *q,double *d,double *e,double *n,	
	double (*cmd)(double, double ),	
	double (*prime)(double *),
	double (*rand_num)(double *),	
	double (*rand_prime)(double *, double (*rand_num)(double *), double (*prime)(double *)))
{
		double k;//Declaramos k de la relación k=(p-1)(q-1) que debe ser coprimo con e
		int i;
		
		//Generamos los números primos para la llave privada
		*p=(*rand_prime)(p, rand_num, prime);
		*q=(*rand_prime)(q, rand_num, prime);
		
		//Calculamos n
		*n=(*p)*(*q);

		//Calculamos k
		k=((*p)-1)*((*q)-1);

		//Calculamos e=i tal que i<k cumpla con que (i,k)=1
		for (i=1; i<k; i++){
			if((int)(k%i)==1){
				*e=i;
				break;
			}
		}
	     //Aquí calculamos d


}
