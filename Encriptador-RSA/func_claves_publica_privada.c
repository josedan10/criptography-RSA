/*Esta función genera aleatoriamente las claves utilizando el método RSA*/
#include <stdlib.h>
//#include <time.h>
//#include <stdio.h>


void func_claves_publica_privada(int (*mcd)(int,int), int (*primo)(int)){

	//Primos p y q
	int p,q,k,e,d,n;
	int hora=time(NULL);srand(hora);
	int inverso;


	//Algoritmo de Euclides extendido

	int alg_eucl_ext(int n,int a)/*a mod n*/{
        int array[3],x=0,y=0,x2=1,x1=0,y2=0,y1=1,q=0,r=0;

        if(a==0){
            array[0]=n;
            array[1]=1;
            array[2]=0;
        }
        else{

            while(a>0) {
                q=(n/a);
                r=n - q*a;
                x=x2-q*x1;
                y=y2 -q*y1;
                n=a;
                a=r;
                x2=x1;
                x1=x;
                y2=y1;
                y1=y;
            }
            array[0]=n;   // mcd (n,a)
            array[1]=x2;   // x
            array[2]=y2;   // y
        }
        return array[2];
    }


	do{
		p=rand()%(101-1)+2;//Generamos un número entre 100 y 2
	}while(!(*primo)(p));

	do{
		q=rand()%(101-1)+2;//Generamos un número primo distinto a p
		if (q==p)q=2;
	}while(!(*primo)(q));

	n=p*q;

	k=(p-1)*(q-1);

	do{
		e=rand()%(k-1)+2;//Generamos un e coprimo con k
	}while(mcd(e,k)!=1);


    //Hallamos el inverso multiplicativo de e mod k
	inverso=alg_eucl_ext(k,e);


    if(inverso<=-1){
        inverso+=n;
    }
    d=inverso;


	printf("\nClave publica: n= %d, y e= %d. \n",n,e);
	printf("Clave privada: p= %d, q= %d, y d=%d\n",p,q,d);

}
