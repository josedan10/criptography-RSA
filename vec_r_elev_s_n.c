int vec_r_elev_s_n(int *numeros, int *m, int *n){

	int func_r_elev_s_mod_n(int r, int s, int n){

		//Esta función toma un número aplica la operación (r^s)(mod n) recursivamente para evitar que se llegue al oveflow

		int resultado=1;
		int j;

		for (j=1;j<=s;j++)
			if(resultado<n){
				resultado*=r;
				continue;
			}
			resultado=(resultado*r)%n;
		return resultado;
	}

	int i, largo= sizeof(numeros)/sizeof(int);
	//Aplicamos la opreación (r^s)(mod n) a cada número del vector
	for (i=0;i<largo;i++)
		numeros[i]=func_r_elev_s_mod_n(numeros[i], *m, *n);

	return 0;
}
