double (*rand_num)(double *dir_num){
	srand(time(NULL));

	*dir_num=rand()%2000 + 100;//Generamos un número entre 100 y 2000

	return *dir_num;
}