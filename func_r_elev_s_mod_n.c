int func_r_elev_s_mod_n(int r, int s, int n){

	//Esta función toma un número aplica la operación (r^s)(mod n) recursivamente para evitar que se llegue al oveflow

	int resultado=1;
	int j;

	for (j=1;j<=s;j++){
        resultado*=r;
        //printf("%d\n",resultado);
        if(resultado>n){
            resultado=resultado%n;
            //printf("resultado: %d\n",resultado);
        }
    }
	return resultado;
}
