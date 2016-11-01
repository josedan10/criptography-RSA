int prime(int num){
	int i;
	//num>1 siempre, DEBO ASEGURAR ESTO

	for (i==2;i<=floor(sqrt(num));i++){
		if (num%i==0)return 0;
	}
	return 1;
}