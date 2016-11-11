#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int s,n,r;
  	int resultado=1;
	int j;

    printf("Numero: ");scanf("%d",&r);
    printf("\ns: ");scanf("%d",&s);
    printf("\nn: ");scanf("%d",&n);
	for (j=1;j<=s;j++){
        resultado*=r;
        //printf("%d\n",resultado);
        if(resultado>n){
            resultado=resultado%n;
            //printf("resultado: %d\n",resultado);
        }
    }
    printf("\n\nEl resultado es: %d",resultado);
    return 0;
}
