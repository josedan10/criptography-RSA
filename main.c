#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int (*cmd)(int, int);//Función para calcular el mcd
double (*rand_num)(int *);//Función para generar un número aleatorio
int (*rand_prime)(double (*)(int *), double (*)(double));//Generamos un número primo usando la función de generar números
													   //Aleatoriamente y el teorema de Eratostenes para verificar si es primo
int (*prime)(int *)//Recibe un número y verifica si este es primo



int main(){
	int opc;//Opción del usuario
	double p, q, d, e, n;

	printf("1) Generar claves publica y privada\n
			2) Codificar el mensaje\n
			3) Decodificar el mensaje\n
			4) Salir");
	scanf("%d",&opc);

	switch (opc){
		case 1:
			/*func_claves_publica_privada(*p, *q, *d, *e,);*/
		case 2:
			//func_texto2numero();
		case 3:
			//func_numero2texto();
		default:
			return 0;
	}
}