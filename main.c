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
int rand_prime(int (*)(int), int (*)(int));

//Función para generar las claves públicas y privadas
int func_claves_publica_privada(int *, int *, int *, int *, int *,
	int (*)(int, int),/*MCD*/
	int (*)(int),/*rand_num*/
	int (*)(int), /*prime*/
	int (*)(int (*)(int), int (*) (int))/*rand_prime*/);

//Función generadora del vector esquema
void func_esquema(char *);

//Función r^s (mod n)
int func_r_elev_s_mod_n(int, int, int);

//Convierte el vector de números en texto
int func_numero2texto(int **, char *, char **, int *, int *, int,
	int (*)(int *, int *, int *));

//Convierte el vector de caracteres en números
int func_texto2num(char **, char *, int **, int *, int *, int,
	int (*)(int *, int *, int *));

//Eleva cada número r del vector a la s mod n
int vec_r_elev_s_n(int *, int *, int *);


int main(){
	char *esquema;//Vector esquema
	char **texto;//Vector con los párrafos
	char linea[80];//Variable para almacenar cada linea
	int vector[40];//Variable para almacenar una linea de n?meros
	int **numeros;//Vector de números
	int opc;
	int *p, *q, *n, *d, *e;
	//Contadores
	int i,j,parrafos;
	int verdadero=1;

	FILE *archivo;
    FILE *salida;
	char nombre[20];
	
	//Reservamos espacio para almacenar los 99 caracteres.
	esquema= (char *)malloc(99*sizeof(char));


	if (esquema==NULL){
		puts("Error al reservar memoria para el esquema");
		exit(1);
	}else{
		func_esquema(esquema);
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
				func_claves_publica_privada(p,q,d,e,n,mcd,prime,rand_num,rand_prime);
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

				
				parrafos=0;

				//Reserva para el texto
				texto= (char **)calloc(1,sizeof(char *));

				while(verdadero){
					
					//Variable para almacenar cada linea
					fgets(linea,80,archivo);
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
				for (i=0;i<parrafos;i++){
                    numeros[i]=(int *)malloc(40*sizeof(int));
                }


				func_texto2num(texto,esquema,numeros,e,n,parrafos,vec_r_elev_s_n);
				fclose(archivo);


				salida=fopen("texto_codificado.txt","w");
				free(numeros);
				free(texto);

				//Escribimos en el archivo cada párrrafo del texto
				char espacio=' ', salto='\n';
				char caracter;
				for (i=0; i<parrafos; i++){
					//Escribimos cada número del párrafo
					j=0;
					for (j=0;j<(sizeof(numeros[i])/sizeof(int));j++){
					    if(j==(sizeof(numeros[i])/sizeof(int))-1){
                            caracter=salto;
                        }else{
                            caracter=espacio;
                        }
						fprintf(salida,"%d %c", numeros[i][j++],caracter);
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

				parrafos=0;

				//Reserva para los números
				numeros= (int **)malloc(parrafos*sizeof(int *));
				for (i=0;i<parrafos;i++){
                    numeros[i]=(int *)malloc(40*sizeof(int));
                }
                
				while(verdadero){
                                                        
					fgets(linea,40,archivo);
					i=0;
					while(linea[i]!='\0'){
						sscanf(linea,"%d",vector[i++]);
					}
					if(linea==NULL){
						//Reasignamos memoria cuando se acabe el contenido
						numeros= (int **)realloc(numeros,(parrafos)*sizeof(int *));
						break;
					}else{
						numeros[parrafos++]=vector;
						numeros= (int **)realloc(numeros,(parrafos+1)*sizeof(int *));
					}
				}
				fclose(archivo);

				//Reserva para el texto
				texto= (char **)calloc(parrafos,sizeof(char *));
				for (i=0; i<parrafos; i++){
					texto[i]=(char *)calloc(80,sizeof(char));
				}

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
	}while(verdadero);
	return 0;
}
