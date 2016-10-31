double func_r_elev_s_mod_n(double r, double s, double n){
	double resultado;
	return resultado=(r*(pow(r,s-1)%n))%n;
}