double (*rand_prime)(double (*rand_num)(*double num), double (*prime)(double num)){
	

	do{
		*num=(*rand_num)(num);//Generamos un número aleatorio y lo guardamos en donde apunte *num

		*num=(*prime(*num));//Verificamos que *num sea primo;
	}while(*num==0);
	
	return *num;
}