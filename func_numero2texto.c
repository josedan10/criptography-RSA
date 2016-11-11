#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int func_numero2texto(int *numeros, char *esquema, char *texto, int s, int n, int elem,
	int (*func_r_elev_s_mod_n)(int , int, int)){
	int i, j=0,x,y;
	int *nro_cod;

    FILE *salida;

	//Esta función descodifica el mensaje del archivo
    salida=fopen("texto_descodificado.txt","a");//Archivo de salida
    if (salida=="NULL"){
        printf("Error en la apertura del archivo de salida");
        exit(1);
    }

    nro_cod=(int *)calloc(elem,sizeof(int));//vector para almacenar los codigos del esquema

    if(nro_cod==NULL){
    	printf("Error en la reserva de memoria");
    	exit(1);
    }

    for (i=0;i<elem;i++){
    	//Convertimos los números en sus códigos de esquema
    	nro_cod[i]=func_r_elev_s_mod_n(numeros[i],s,n);
    	printf("%d\n",nro_cod[i]);
    }
    free(numeros);
    for (i=0;i<elem; i++){
        x=(int)nro_cod[i]/100;
        printf("x: %d",x);
        y=nro_cod[i]-x*100;
        printf("    y: %d\n",y);

    	texto[j]=esquema[x];
        j++;
    	texto[j]=esquema[y];
    	j++;
    	printf("%s",texto);
    	free(x);
    	free(y);
    }
    fprintf(salida,"%s",texto);
    fclose(salida);
    free(texto);
    free(nro_cod);
}


