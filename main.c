/*ALGORITM

a)Keys generation

(1) Alicia genera, aleatoriamente y del mismo tamaño, dos números primos
grandes y diferentes p y q, respectivamente.

(2) n = pq.

(3) k = (p − 1)(q − 1).

(4) Seleccionar, aleatoriamente, un número entero e tal que mcd(e, k) = 1,
con 1 < e < k.

(5) Usar el algoritmo de Euclides extendido para hallar el número entero d
tal que ed=1(mod k), donde 1 < d < Á.

(6) La clave pública de Alicia es (n,e) y la clave privada es d.

b)Encriptación

(1) Bob recibe la clave pública de Alicia (n, e).

(2) Representa el mensaje en texto plano m, como un número entero en el
intervalo [0, n − 1].

(3) Computar c = m^e(mod n).

(4) Remitir el texto cifrado c a Alicia.

c)Desencriptación

(1) Para recuperar m, Alicia usa la transformación m = c^d(mod n).*/




/*<<<<<<<<<<---------------- LIBRARIES ----------------->>>>>>>>>>>>>*/
//>'stdli.h'
//>'stdio.h'
//>'math.h' to can use the functions 'floor' y 'sqrt'.
//>'string.h' to can use the functions 'strcat', 'strcmp' and 'isspace'
/*<<<<<<<<<<<<-------------------------------------------->>>>>>>>>>>>>*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

/*<<<<<<<------------- FUNCTIONS ---------------->>>>>>>*/

//Euclides Algoritm Extendend
int *alg_eucl_ext(int, int);

//Máximo Común Divisor
int mcd(int,int);

//Función para verificar si un número es primo
int primo(int);

//Función para generar las claves
void func_claves_publica_privada(/*MCD*/int (*)(int,int),
	/*primo*/int (*)(int), /*alg_eucl*/int *(*)(int,int));

//Función para generar el esquema
void func_esquema(char *);

//Función para convertir de número a texto.







main(){
	

	/*>>>>>>>>>>>>>>>MENÚ<<<<<<<<<<<<<<<<<*/

	printf("Este programa genera claves, codifica y descodifica mensajes utilizando el metodo RSA.\n");

	

	do{
		printf("Elija la accion que desea realizar: \n\n");
		printf("1. Generar claves.\n");
		printf("2. Codificar un archivo o frase.\n");
		printf("3. Descodificar un archivo o frase.\n");
		printf("4. Salir.\n");

		int opc;

		scanf("%d",&opc);

		switch (opc){

			case 1:
				/*>>>>>>>>GENERAR LAS CLAVES<<<<<<<<*/

				func_claves_publica_privada(mcd,primo,alg_eucl_ext);


			case 2:

				/*>>>>>>>Codificar un mensaje o archivo<<<<<<<<<<*/
				do{
					printf("Desea codificar un mensaje corto o un archivo?")
					printf("\n\n1. Mensaje corto (max 80 carac.)");
					printf("\n2. Archivo '.txt'");
					

					int opc2;

					scanf("%d",&opc2);

					switch(opc2){
						case 1:
							//Mensaje corto
							break;

						case 2: 
							//Archivo
							break;

						case 3:
							char r;
							printf("Está seguro de que desea salir? (s/n)\n");
							scanf("%c",&r);

							if ((int)r==(int)"s"){
								
								exit(1);
								break;
							}else{
								break;
							}
					}
				}while(opc2>=1 || opc2<=3);				
		}

			case 3:

				/*>>>>>>>>>>>>>>> Decodificar un mensaje o archivo <<<<<<<<<<<<<*/
				printf("Desea descodificar un mensaje corto o un archivo?\n\n");
				printf("1. Descodificar un mensaje corto(max 40 num).\n");
				printf("2. Descodificar un archivo.\n");

				char opc2;

				scanf("%c",&opc2);


				switch (opc2){

					case 1:
					//Descodificar mensaje corto


					case 2:
					//Descodificar un archivo
				}

	}while(opc!=4);


}