#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
//#include <time.h>

/*--- DEFINICIÓN DE FUNCIONES ---*/

//Para calcular el mcd
int mcd(int, int);

//Para generar un número aleatorio
int rand_num(int);

//Para generar un número primo 
int prime(int);

//Para generar un número primo aleatorio
int rand_prime(int (*)(void), int (*)(void));

//Función para generar las claves públicas y privadas
int func_claves_publica_privada(int *, int *, int *, int *, int *,
	int (*)(int, int),/*MCD*/
	int (*)(void),/*rand_num*/
	int (*)(void), /*prime*/
	int (*)(int (*)(void), int (*) (void))/*rand_prime*/);

//Función generadora del vector esquema
void func_esquema(char *);

//Función r^s (mod n)
int func_r_elev_s_mod_n(int, int, int);

//Convierte el vector de números en texto
int func_numero2texto(char *, void (*)(char *));

//Convierte el vector de caracteres en números
int func_texto2numero(char *, void (*)(char *));


int main(){
	char *esquema;//Vector esquema
	int opc;
	
	//Reservamos espacio para almacenar los 99 caracteres.
	esquema= (char*)malloc(99*sizeof(char));

	if (esquema==NULL){
		puts("Error al reservar memoria para el esquema");
		exit(1);
	}else{
		gen_esquema(esquema);
	}

	do {
		/*--- MENÚ ---*/
		printf("1) Generar claves públicas y privadas\n");
		printf("2) Codificar mensaje\n");
		printf("3) Decodificar mensaje\n");
		printf("4) Salir\n");

		scanf("%d",&opc);

		switch (opc){
			case 1:
				//Generar las claves

			case 2:
				//Codificar mensaje

			case 3:
				//Decodificar mensaje

			default:
				return 0;
		}	
	}(while opc!=0);
	return 0;
	
}