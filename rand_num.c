int rand_num(int par){
	int num;

	/*par es para asegurar que el número sea mayor a par siempre*/

	srand((unsigned int)time(time_t *)NULL);
	return num=rand()%(100-par-1)+par;
}