/*Esta función genera aleatoriamente las claves utilizando el método RSA*/



int func_claves_publica_privada(int (*mcd)(int,int), int (*primo)(int), 
	int *(*alg_eucl_ext)(int,int)){

	//Primos p y q
	int p,q,k,e,d,n;
	int hora=time(NULL);srand(hora);
	int *vector;


	do{
		p=rand%(101-1)+2;//Generamos un número entre 100 y 2
	}(while (*primo)(p));

	do{
		q=rand%(101-1)+2;//Generamos un número primo distinto a p
	}(while (*primo)(q)==0 && q=p);

	n=p*q;

	k=(p-1)*(q-1);

	do{
		e=rand%(k-1)+2;//Generamos un e coprimo con k
	}while(!mcd(e,k));

	vector=alg_eucl_ext(k,e);
	d=vector[2];//Hallamos el inverso multiplicativo de e mod k


	printf("\nClave publica: n= %d, y e= %d. \n",n,e);
	printf("Clave privada: p= %d, q= %d, y d=%d\n",p,q,d);

}