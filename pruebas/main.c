#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int (*func_r_elev_s_mod_n)(int, int, int);
void func_esquema(char *);

int main()
{
    char texto[20], *esquema;
    int *numeros, s, n;
    printf("Cadena: ");
    gets(texto);
    int nums[2],largo=strlen(texto), num;
    int i,j,z=0, k;
    //printf("%d", largo);

    //Reservamos espacio para almacenar los 99 caracteres.
	esquema= (char *)calloc(99,sizeof(char));

	if (esquema==NULL){
		puts("Error al reservar memoria para el esquema");
		exit(1);
	}else{
		func_esquema(esquema);
	}

    func_esquema(esquema);
    //printf("\n%s\n",esquema);
    //system("pause");


    /*Esta función codifica el texto de la matriz texto y lo devuelve en números*/


    //El índice de cada caracter corresponde a su código en el esquema
    //Buscamos el índice para obtener el código
    for (i=0, j=0; i<largo; i++){

        for (k=0;k<99;k++){
            if (strcmp(&texto[i],&esquema[k])==0)
                nums[z++]=k;
                break;
        }

        if (i%2==1){

            //Si los códigos son, por ejemplo, 9 y 34, entonces hará 900+34=934
            //Si los códigos son, por ejemplo, 23 y 18, entonces hará 2300+18=2318
            num=nums[0]*100+nums[1];

            numeros= (int *)malloc((largo/2)*sizeof(int));
            if (numeros==NULL){
                printf("\nError en la reserva de memoria para los numeros\n");
                return 1;
            }

            //Ahora elevamos el código r a la potencia s, módulo n
            numeros[j++]=(*func_r_elev_s_mod_n)(num, s, n);

            z=0;
        }
    }
    return 0;
}
