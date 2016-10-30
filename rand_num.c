double (*rand_num)(*dir_num){
	srand(time(NULL));

	*dir_num=rand()%2000 + 100;

	return *dir_num;
}