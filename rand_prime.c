double (*rand_prime)(double *num, double (*rand_num)(double *), double (*prime)(double *)){
	do{
		*num=(*rand_num)(num);//Generamos un número aleatorio y lo guardamos en donde apunte *num

		*num=(*prime)(num);//Verificamos que *num sea primo;
	}while(*num==0);
	
	return *num;
}
