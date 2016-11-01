void func_claves_publica_privada(double *p,double *q,double *d,double *e,double *n,	
	double (*mcd)(double, double),	
	double (*prime)(double *),
	double (*rand_num)(double *),	
	double (*rand_prime)(double *, double (*rand_num)(double *), double (*prime)(double *)))
{
	/*Input de los números para armar la clave*/


	double k;//Declaramos k de la relación k=(p-1)(q-1) que debe ser coprimo con e
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
        int mod=(int)k%i;
        
		if(mod==1){
			*e=i;
			break;
		}
	}
     //Aquí calculamos d

	/*Utilizar la Criba de Eratóstenes para calcular un número coprimo con e que sea 
	menor que k*/



}
