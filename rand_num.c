double rand_num(double *dir_num){
	int hora=time(NULL);

	srand(hora);

	*dir_num=rand()%2000 + 100;//Generamos un número entre 100 y 2000

	return *dir_num;
}
