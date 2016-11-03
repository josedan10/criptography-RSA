int vec_r_elev_s_n(int *numeros, int *m, int *n){

	int func_r_elev_s_mod_n(int r, int s, int n){
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

	int i;

	for (i=0;i<strlen(numeros);i++)
		numeros[i]=func_r_elev_s_mod_n(numeros[i], m, n);

	return 0;
}