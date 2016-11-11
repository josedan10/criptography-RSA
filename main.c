#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>
//#include <time.h>

/*--- DEFINICIÓN DE FUNCIONES ---*/

//Para calcular el mcd
int mcd(int, int);

//Algoritmo de Euclides
int* alg_euc_ext(int,int);

//Inverso modular
int Inverso_Zn(int,int);

//Para generar un número aleatorio
int rand_num(int);

//Para generar un número primo
int prime(int);

//Para generar un número primo aleatorio
int rand_prime(int (*)(int), int (*)(int));

//Función para generar las claves públicas y privadas
int func_claves_publica_privada(int (*)(int, int),/*MCD*/
	int (*)(int),/*rand_num*/
	int (*)(int),/*prime*/
	int (*)(int (*)(int), int (*) (int))/*rand_prime*/);

//Función generadora del vector esquema
void func_esquema(char *);

//Función r^s (mod n)
int func_r_elev_s_mod_n(int, int, int);

//Convierte el vector de números en texto
int func_numero2texto(int *, char *, char *, int, int, int,
	int (*)(int, int, int));

//Convierte el vector de caracteres en números
int func_texto2num(char *, char *, int *, int, int,
	int (*)(int, int, int));


int main(){
	char *esquema;//Vector esquema
	char *texto;//Vector con los párrafos
	char linea[80];//Variable para almacenar cada linea
	int *numeros;//Vector de números
	int opc;
	char espacio[3]={' ','\n'};
	//Llaves
	int e,n,d;
	//Contadores
	int i,j;
	int verdadero=1;

	FILE *archivo;
    //FILE *salida;
	char nombre[20];

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
				func_claves_publica_privada(mcd,prime,rand_num,rand_prime);
				//system("PAUSE");
				break;

			case 2:
				//Codificar mensaje

				//Reservamos espacio para almacenar los 99 caracteres.
				//esquema= (char *)calloc(99,sizeof(char));


                esquema=(char*)calloc(100,sizeof(char));
                if (esquema==NULL){
                    printf("Error al reservar memoria para el esquema");
                    exit(1);
                }else{
					func_esquema(esquema);
				}
				//printf("%s",esquema);

				/*Esta función devuelve en un ARCHIVO de nombre 'texto_codificado.txt' el texto codificado*/
				printf("Introduzca el nombre del archivo que desea codificar: ");
				scanf("%s",nombre);

				/*<<< ARCHIVO >>>*/
				archivo=fopen(nombre,"r");//Archivo de lectura
				if(archivo==NULL){
					printf("Error al abrir el archivo\n");
					return 1;
				}

				/*<<< LLAVES DE CODIFICACIÓN >>>*/
                printf("Introduzca las llaves de codificacion 'e' y 'n'");
				printf("\ne: ");scanf("%d",&e);printf("\nn: ");scanf("%d",&n);

				while(!feof(archivo)){
					fgets(linea,80,archivo);

                    int largo=strlen(linea);
                    //printf("%d\n", largo);
                    //system("pause");

                    //Si el texto tiene un número impar de caracteres, le agregamos un espacio al final
                    if(largo%2!=0){
						linea[largo-1]=espacio[0];
						strcat(linea,&espacio[1]);
					}

					largo=strlen(linea);
                    //printf("\nNuevo largo: %d",largo);
                    //system("pause");

                    //Reserva para el texto
                    texto=(char *)calloc(largo,sizeof(char));
                    strcpy(texto,linea);
                    free(linea);
                    func_texto2num(texto,esquema,numeros,e,n,func_r_elev_s_mod_n);
                    free(texto);

				}
				free(esquema);
				fclose(archivo);

				printf("\nSe ha almacenado el contenido en el archivo %s\n", nombre);
				break;

			case 3:
				//Descodificar mensaje

				//Reservamos espacio para almacenar los 99 caracteres.
				esquema= (char *)calloc(100,sizeof(char));

				if (esquema==NULL){
					puts("Error al reservar memoria para el esquema");
					exit(1);
				}else{
					func_esquema(esquema);
				}

				/*Esta función devuelve por PANTALLA el contenido del archivo descodificado*/

				printf("\nIntroduzca el nombre del archivo que desea descodificar: ");
				scanf("%s",nombre);

				archivo=fopen(nombre,"r");

				if (archivo==NULL){
					printf("\nError al abrir el archivo.\n");
					return 1;
				}

				/*<<< LLAVES DE DESCODIFICACIÓN >>>*/
            	printf("Introduzca las llaves de descodificacion 'd' y 'n'");
				printf("\nd: ");scanf("%d",&d);printf("\nn: ");scanf("%d",&n);

				while(!feof(archivo)){

					fgets(linea,160,archivo);
                    int largo=strlen(linea);
                    int nro_elem=1;
                    //printf("%d\n", largo);
                    //system("pause");
                    char *ptr;
					ptr=linea;

				    for (j=0;j<largo;j++){
				        if (isspace(linea[j]))
				            nro_elem++;
				    }
				    //printf("Cantidad de numeros en la linea: %d",nro_elem);
				    //system("pause");

				    //Reserva para los numeros
				    numeros=(int *)calloc(nro_elem,sizeof(int));
				    if(numeros==NULL){
				    	printf("Falla en la reserva de memoria");
				    	return 1;
				    }

				    int numerito;

				    i=0;
				    while(i<nro_elem){
				        sscanf(ptr,"%d",&numerito);
				        numeros[i]=numerito;
				        if(i==nro_elem-1) break;
				        while(!isspace(*ptr)) {
                            ptr++;
                        }
				        ptr++;
				        i++;
				    }
				    free(ptr);
                    texto=(char *)calloc((2*nro_elem)+1,sizeof(char));
                    if(texto==NULL){
                        printf("Error en la reserva de memoria\n");
                        exit(1);
                    }

                    func_numero2texto(numeros,esquema,texto,d,n,nro_elem,func_r_elev_s_mod_n);
                    free(numeros);
                    free(linea);
				}
				free(esquema);
				fclose(archivo);
				//fclose(salida);

				printf("\nSe ha almacenado el contenido en el archivo texto_descodificado.txt\n");
				break;

			case 4:
				free(esquema);
				return 0;

			default:
				printf("\nOpcion invalida\n");
		}
	}while(verdadero);
	return 0;
}
