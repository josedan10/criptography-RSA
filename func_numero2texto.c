int func_numero2texto(int **numeros, int *esquema, char **texto, int *s, int *n, int parrafos,
	int (*vec_r_elev_s_n)(int *, int *, int *, int *)){
	int m;

	for (m=0; m<=parrafos; m++){
		vec_r_elev_s_n(numeros[m], s, n);
	}

	for (i=0; i<=parrafos; i++){
		linea=numeros[i];
		for (j=0; j<strlen(numeros[i]);j++){
			valor=linea[j];
			if(valor<1000){
				x=(int)(valor/10);
				letra1=esquema[x];
				y=x*100-valor;
				letra2=esquema[4];
			}else{
				x=(int)(valor/100);
				letra1=esquema[x];
				y=x*1000-valor;
				letra2=esquema[y];
			}


			concat=strcat(letra1,letra2);
			texto[i]=strcat(texto[i],concat);
			}
		}
	}
	

	
