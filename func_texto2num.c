int func_texto2num(char **texto, char *esquema, int **numeros, int *s, int *n, int parrafos,
	int (*vec_r_elev_s_n)(int *, int *, int *)){
	int nums[2],largo, num;
    char fila;
    char espacio=' ';
	int i,j,z=0, k, m;

	/*Esta función codifica el texto de la matriz texto y lo devuelve en números*/

	//Si el texto tiene un número impar de caracteres, le agregamos un espacio al final
	for (m=0; m<=parrafos; m++){
		fila=*texto[m];
        largo=strlen(&fila);
		if(largo%2!=0)
  
		strcat(&fila,&espacio);

		//El índice de cada caracter corresponde a su código en el esquema
		//Buscamos el índice para obtener el código
		for (i=0, j=0; i<strlen(&fila); i++){

			for (k=0;k<99;k++){
				if (strcmp(&texto[m][i],&esquema[k])==0)
					nums[z++]=k;
					break;
			}

			if (i%2==1){

				//Si los códigos son, por ejemplo, 9 y 34, entonces hará 900+34=934
				//Si los códigos son, por ejemplo, 23 y 18, entonces hará 2300+18=2318
				num=nums[0]*100+nums[1];
				int pot=pow(num,*s);
				for (j=1;j<=*s;j++){
					if(pot<*n){
						pot*=(*s);
						continue;
					}
					pot=(pot%*n)*(*s);
				}
				if(pot<*n){
					numeros[m][j++]=pot;
						
				}else{
					pot=(pot%(*n));
            	}
				k=0;
			}
		}
	}

	//Ahora elevamos cada código r a la potencia s, módulo n
	for (m=0; m<=parrafos; m++){
		vec_r_elev_s_n(numeros[m], s, n);
	}
}
