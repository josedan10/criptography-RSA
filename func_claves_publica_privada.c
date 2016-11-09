int func_claves_publica_privada(int (*mcd)(int, int),
	int (*prime)(int),
	int (*rand_num)(int),
	int (*rand_prime)(int (*rand_num)(int), int (*prime)(int))){
	/*Input de los números para armar la clave*/

    int var_p,var_q,var_n,var_d=2,var_e=2;

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
	k=(var_p-1)*(var_q-1);

	//Calculamos e=i tal que i<k cumpla con que k=1(mod i)

	do{
       	var_e=rand()%(k-2)+2;
    }while(mcd(var_e,k)!=1);

	/*<<< ALGORITMO DE EUCLIDES EXTENDIDO>>>*/
	int* alg_euc_ext(int n1,int n2) // n1 es a y n2 es b
	{
	   int vector[3],x=0,y=0,d=0,x2 = 1,x1 = 0,y2 = 0,y1 = 1,q = 0, r = 0;
	  if(n2==0)
	  {
	  vector[0]=n1;
	  vector[1]=1;
	  vector[2]=0;
	  }
	  else
	  {
	   while(n2>0)
	      {
	     q = (n1/n2);
	      r = n1 - q*n2;
	      x = x2-q*x1;
	      y = y2 - q*y1;
	      n1 = n2;
	      n2 = r;
	      x2 = x1;
	      x1 = x;
	      y2 = y1;
	      y1 = y;
	      }
	      vector[0] = n1;   // mcd (n1,n2)
	      vector[1] = x2;   // x
	      vector[2] = y2;   // y
	    }
	    return vector;
	}




	/*<<< INVERSO MODULAR >>>*/
	int Inverso_Zn(int a,int n)
	{
	  int* ptr,vector[3];
	  ptr=alg_euc_ext(n,a);

	  vector[0]=*ptr;
	  vector[1]=*(ptr+1);
	  vector[2]=*(ptr+2);

	  if(vector[0]!=1)
	  return -1;
	  else
	  {
	  if(vector[2]<0)
	   vector[2]+=n;
	   return vector[2];
	  }
	}
	//Aquí calculamos d

	var_d=Inverso_Zn(var_e,k);

	printf("k: %d\n",k);
	printf("Numeros de la clave privada: p=%d, q=%d y d=%d\n", var_p,var_q,var_d);
	printf("Los numeros de la clave publica son: e=%d y n=%d\n", var_e,var_n);

}
