/*for (m=0; m<=parrafos; m++){
		//A cada n�mero del vector le aplicamos la operaci�n
		vec_r_elev_s_n(numeros[m], s, n);
	}

	for (i=0; i<=parrafos; i++){
		//Descodificamos cada l�nea
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

			//Concatenamos los caracteres y luego los unimos al resto del p�rrafo
			strcat(&letra1,&letra2);
			texto[i]=strcat(texto[i],&letra1);
			}
		}*/

