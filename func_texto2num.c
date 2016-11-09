#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func_texto2num(char *texto, char *esquema, int *numeros, int s, int n,
	int (*func_r_elev_s_mod_n)(int, int, int)){
	int nums[2],largo=strlen(texto), num;
	int i,j,z=0, k,val;
    char espacio[3]={' ','\n'};
    FILE *salida;

    salida=fopen("texto_codificado.txt","a");//Archivo de salida

    /*Esta función codifica el texto y lo devuelve en números*/


    //El índice de cada caracter corresponde a su código en el esquema
    //Buscamos el índice para obtener el código
    for (i=0, j=0; i<largo; i++){

        for (k=0;k<99;k++){

            val=(int)texto[i]-(int)esquema[k];
            if (val==0){
                nums[z++]=k;
                break;
            }

        }
        if (i%2==1){

            //Si los códigos son, por ejemplo, 9 y 34, entonces hará 900+34=934
            //Si los códigos son, por ejemplo, 23 y 18, entonces hará 2300+18=2318
            num=nums[0]*100+nums[1];
            numeros= (int *)calloc((largo/2),sizeof(int));
            if (numeros==NULL){
                printf("\nError en la reserva de memoria para los numeros\n");
                return 1;
            }

            //Ahora elevamos el código r a la potencia s, módulo n

            numeros[j]=(*func_r_elev_s_mod_n)(num, s, n);

            z=0;
            if (j==(largo/2)-1){
                fprintf(salida,"%d%c",numeros[j++],espacio[1]);
            }else{
                fprintf(salida,"%d%c",numeros[j++],espacio[0]);
            }
        }
    }
    free(numeros);
    free(nums);
    fclose(salida);
    return 0;
}







