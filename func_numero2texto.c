#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int func_numero2texto(/*int *numeros,*/ char *esquema, char *texto, int s, int n, int elem,
	char *linea_numeros, int(*func_r_elev_s_mod_n)(int, int, int), char *fsalida){

	int i, numerito, j = 0, indice1, indice2;
	char *ptr;
	FILE * salida;

	texto = (char *)calloc((2 * elem) + 1, sizeof(char));
	if (texto == NULL) {
		printf("Error en la reserva de memoria\n");
		exit(1);
	}

	salida = fopen(fsalida, "a");

	if (salida == NULL) {
		printf("\nError en la reserva de memoria\n");
		exit(1);
	}

	if (strcmp(linea_numeros, "\n") == 0) {
		fprintf(salida, "\n");
		fclose(salida);
		return 0;
	}

	ptr = linea_numeros;

	i = 0;
	while (i<elem) {
		//if (strcmp(ptr,"\n")==0)break;
		sscanf(ptr, "%d", &numerito);
		numerito = func_r_elev_s_mod_n(numerito, s, n);
		indice1 = (int)(numerito / 100);
		indice2 = numerito-(indice1 * 100) ;
		texto[j++] = esquema[indice1];
		//if (i == elem - 1) {
			//i++; continue;
		//}
		texto[j++] = esquema[indice2];

		
		while (!isspace(*ptr)) {
			if (strcmp(ptr, "\n") == 0)break;
			ptr++;
		}
		ptr++;
		i++;
	}
	//ptr = NULL;
	//linea_numeros = NULL;
	fprintf(salida, "%s\n", texto);
	fclose(salida);
	
	free(texto);
	//texto = NULL;
	return 0;
}
//int func_numero2texto(int *numeros, char *esquema, char *texto, int s, int n, int elem,
//	int (*func_r_elev_s_mod_n)(int , int, int)){
//	int i, j=0,x,y;
//	int *nro_cod;
//
//    FILE *salida;
//
//	//Reserva para los numeros
//	/*numeros = (int *)calloc(elem, sizeof(int));
//	if (numeros == NULL) {
//		printf("Falla en la reserva de memoria");
//		return 1;
//	}
//
//	int numerito;
//
//	i = 0;
//	while (i<elem) {
//		sscanf(ptr, "%d", &numerito);
//		numeros[i] = numerito;
//		if (i == elem - 1) break;
//		while (!isspace(*ptr)) {
//			ptr++;
//		}
//		ptr++;
//		i++;
//	}*/
//
//	//Esta función descodifica el mensaje del archivo
//    salida=fopen("texto_descodificado.txt","a");//Archivo de salida
//    if (salida=="NULL"){
//        printf("Error en la apertura del archivo de salida");
//        exit(1);
//    }
//
//
//
//
//
//    //nro_cod=(int *)calloc(elem,sizeof(int));//vector para almacenar los codigos del esquema
//
//    //if(nro_cod==NULL){
//    //	printf("Error en la reserva de memoria");
//    //	exit(1);
//    //}
//
//    for (i=0;i<elem;i++){
//    	//Convertimos los números en sus códigos de esquema
//    	nro_cod[i]=func_r_elev_s_mod_n(numeros[i],s,n);
//    	printf("%d\n",nro_cod[i]);
//    }
//    free(numeros);
//    for (i=0;i<elem; i++){
//        x=(int)nro_cod[i]/100;
//        printf("x: %d",x);
//        y=nro_cod[i]-x*100;
//        printf("    y: %d\n",y);
//
//    	texto[j++]=esquema[x];
//        //j++;
//    	texto[j++]=esquema[y];
//    	//j++;
//    	printf("%s",texto);
//    	//free(x);
//    	//free(y);
//    }
//    fprintf(salida,"%s",texto);
//    fclose(salida);
//    free(texto);
//    //free(nro_cod);
//}


