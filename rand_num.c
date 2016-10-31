double rand_num(double *dir_num){
	srand((unsigned int)time(time_t)NULL));

	*dir_num=rand()%2000 + 100;//Generamos un número entre 100 y 2000

	return *dir_num;
}
