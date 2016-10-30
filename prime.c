double (*prime)(double num){
	int i, ver=0;

	for (i=0;i<=floor(sqrt(num); i++){
		if ((*num)%i==0){
			ver=1;
			break;
		}
	}
	if (ver==0){
		return 0;
	}else{
		return num;
	}
}