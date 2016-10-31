double mcd(double y, double x){
	double temp, i;

	if (x<y){
		temp=x;
		y=x;
		x=temp;
	}
	int mod=(int)x%(int)y;

	if (mod==0){
		return y;
	}else{
		i=0;

		while (y!=0){
			y=x-y*(int)(x/y);

			if (x==y && i==0){
				return 1;
				break;
			}else if(y==0){
				return x;
				break;
			}else{
				x=y;
				i++;
			}
		}
	}
}
