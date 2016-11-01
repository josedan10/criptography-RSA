#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/*--- DEFINICIÓN DE FUNCIONES ---*/

//Función para calcular el mcd
int mcd(double, double);

//Función para generar un número aleatorio
double rand_num(double *);

/*Generamos un número primo usando la función de generar números aleatoriamente y el teorema de Eratostenes 
para verificar si es primo*/
double rand_prime(double *, double (*)(double *), double (*)(double *));

//Recibe un número y verifica si este es primo													   
double prime(double *);

//Función para generar las claves públicas y privadas
void func_claves_publica_privada(double *, double *, double *, double *, double *,	
	double (*)(double, double ),	
	double (*)(double *),
	double (*)(double *),	
	double (*)(double *, double (*)(double *), double (*)(double *)));

//Función generadora del esquema
char *func_esquema(char *);

//Función r^s(mod n)
double func_r_elev_s_mod_n(double ,double, double);

//Convierte el vector de numeros en texto
char *func_numero2texto(char */*Apuntador del vector de números*/, char *(*)(char *));

//Convierte el texto en un vector de numeros
char *func_texto2numero(char */*Apuntador a la cadena*/, char *(*)(char *));


int main(){
	int opc;//Opción del usuario
	double p, q, d, e, n;
	char *esquema;//Esquema de referencia

	printf("1) Generar claves publica y privada\n2) Codificar el mensaje\n");
    printf("3) Decodificar el mensaje\n4) Salir");
	scanf("%d",&opc);

	switch (opc){
		case 1:
			/*func_claves_publica_privada(*p, *q, *d, *e, *n, *mcd, *prime, *rand_num, *rand_prime);*/
		case 2:
			//func_texto2numero();
		case 3:
			//func_numero2texto();
		default:
			return 0;
	}
}
