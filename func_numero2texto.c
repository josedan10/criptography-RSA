int func_numero2texto(int **numeros, char *esquema, char **texto, int *s, int *n, int parrafos,
	int (*vec_r_elev_s_n)(int *, int *, int *)){
	int m, i, j, x, y;
	int *vector, valor;
	char letra1, letra2;

	//Esta función descodifica el mensaje del archivo

	for (m=0; m<=parrafos; m++){
		//A cada número del vector le aplicamos la operación
		vec_r_elev_s_n(numeros[m], s, n);
	}

	for (i=0; i<=parrafos; i++){
		//Descodificamos cada línea
		vector=numeros[i];

		for (j=0; j<sizeof(numeros)/sizeof(int);j++){
			valor=vector[j];
			if(valor<1000){
				//Si el valor es, por ejemplo, 789, toma primero el 7 y luego el 89
				x=(int)(valor/10);
				letra1=esquema[x];
				y=x*100-valor;
				letra2=esquema[4];
			}else{
				//Si el valor es, por ejemplo, 1223, toma primero 12 y luedo 23
				x=(int)(valor/100);
				letra1=esquema[x];
				y=x*1000-valor;
				letra2=esquema[y];
			}

			//Concatenamos los caracteres y luego los unimos al resto del párrafo
			strcat(&letra1,&letra2);
			texto[i]=strcat(texto[i],&letra1);
			}
		}
	}
	

	
