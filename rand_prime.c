int rand_prime(int (*rand_num)(int *), int (*prime)(int *)){
	int num;

	do{
		num=(*rand_num)(1);//Generamos un número aleatorio y lo guardamos en donde apunte *num

	}while((*prime)(num)==0);//Verificamos que num sea primo;
	
	return num;
}
