int func_vec_elev_s_mod_n(int *vec, int s, int n, int num_elem){
	
	/*Esta funcion hace la operacion r^s(mod n)*/
	int func_r_elev_s_mod_n(int,int,int){
		int resultado=1, i;

		for (i=1; i<=s; j++){
			resultado*=r;

			if (resultado>n){
				resultado=resultado%n;
			}
		}
		return resultado;
	}
	
	for (i=0; i<num_elem; i++){
		vec[i]=func_r_elev_s_mod_n(vec[i],s,n);
	}

	return 0;
}