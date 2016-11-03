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
int func_numero2texto(int **, char *, char **, int *, int *, int *,
	int (*)(int *, int *, int *, int *))

//Convierte el vector de caracteres en números
int func_texto2num(char **, char *, int **, int *, int *,
	int (*)(int *, int *, int *, int *))

//Eleva cada número r del vector a la s mod n
int vec_r_elev_s_n(int *, int *, int *);


int main(){
	char *esquema;//Vector esquema
	char **texto;//Vector con los párrafos
	char linea;//Variable para almacenar cada linea
	int *numeros;//Vector de números
	int opc;
	int *p, *q, *n, *d, *e;

	FILE *archivo, *salida;
	char nombre;
	
	//Reservamos espacio para almacenar los 99 caracteres.
	esquema= (char *)malloc(99*sizeof(char));


	if (esquema==NULL){
		puts("Error al reservar memoria para el esquema");
		exit(1);
	}else{
		gen_esquema(esquema);
	}

	do {
		/*--- MENÚ ---*/
		printf("1) Generar claves publicas y privadas\n");
		printf("2) Codificar mensaje\n");
		printf("3) Decodificar mensaje\n");
		printf("4) Salir\n");

		scanf("%d",&opc);

		switch (opc){
			case 1:
				//Generar las claves
				func_claves_publica_privada(p,q,d,e,n);
				printf("Numeros de la clave privada: p=%d, q=%d y d=%d\n", p,q,d);
				printf("Los numeros de la clave publica son: e=%d y n=%d", e,n);

			case 2:
				//Codificar mensaje

				/*Esta función devuelve en un ARCHIVO de nombre 'texto_codificado.txt' el texto codificado*/
				printf("Introduzca el nombre del archivo que desea codificar: ");
				scanf("%s",nombre);
				archivo=fopen(nombre,"r");

				if(archivo==NULL){
					printf("Error al abrir el archivo\n");
					return 1;
				}

				int verdadero=1;
				int parrafos=0;

				//Reserva para el texto
				texto= (char **)calloc(1,sizeof(char *));

				while(verdadero){
					
					//Variable para almacenar cada linea
					linea=fgets(texto[parrafos],80,archivo);
					if(linea==NULL){
						//Reasignamos memoria cuando se acaba el contenido
						texto= (char **)realloc(texto,(parrafos)*sizeof(char *));
						break;
					}else{
						texto[parrafos++]=linea;
						texto= (char **)realloc(texto,(parrafos+1)*sizeof(char *));
					}
				}

				//Reserva para los números
				numeros= (int **)malloc(parrafos*sizeof(int *));


				func_texto2numero(texto,esquema,numeros,e,n,parrafos,vec_r_elev_s_n);
				fclose(archivo);


				salida=fopen("texto_codificado.txt","w");
				free(numeros);
				free(texto);

				//Escribimos en el archivo cada párrrafo del texto
				for (i=0; i<parrafos; i++){
					//Escribimos cada número del párrafo
					for (j=0; j<strlen(numeros[i]); j++){
						caracter=(i==strlen(numeros[i])-1)?"\n":" ";
						fprintf(salida,"%d %c", numeros[i][j],caracter);
					}
				}
				printf("\nSe ha almacenado el contenido en el archivo %s\n", nombre);

				fclose(salida);

			case 3:
				//Decodificar mensaje

				/*Esta función devuelve por PANTALLA el contenido del archivo descodificado*/

				printf("Introduzca el nombre del archivo que desea descodificar: ");
				scanf("%s",nombre);

				archivo=fopen(nombre,"r");

				if (archivo==NULL){
					printf("\nError al abrir el archivo.\n");
					return 1;
				}

				int verdadero=1;
				int parrafos=0;

				//Reserva para los números
				numeros= (int **)calloc(1,sizeof(int*));

				while(verdadero){
					linea=fgets(numeros[parrafos],40,archivo);

					if(linea==NULL){
						//Reasignamos memoria cuando se acabe el contenido
						numeros= (char **)realloc(numeros,(parrafos)*sizeof(char *));
						break;
					}else{
						numeros[parrafos++]=linea;
						numeros= (char **)realloc(numeros,(parrafos+1)*sizeof(char *));
					}
				}
				fclose(archivo);

				//Reserva para el texto
				texto= (char **)calloc(1,sizeof(char *));

				func_numero2texto(numeros,esquema,texto,d,n,parrafos,vec_r_elev_s_n);

				free(numeros);

				//Imprimimos cada párrafo en pantalla
				for (i=0; i<=parrafos; i++){
					printf("%s\n",texto[i]);
				}

				free(texto);


			case 4:
				free(esquema);
				return 0;

			default:
				printf("\nOpcion invalida\n");
		}	
	}(while 1);
	return 0;
	
}