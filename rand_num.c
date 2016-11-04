#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rand_num(int par){

	/*par es para asegurar que el número sea mayor a par siempre*/

	int hora=time(NULL);
	srand(hora);
	int num=rand()%101+par;
	return num;
}
