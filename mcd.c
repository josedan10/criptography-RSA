int (*mcd)(double x, double y){
	double temp, i;

	if (x<y){
		temp=x;
		y=x;
		x=temp;
	}

	if (x%y==0){
		return (int)y;
	}else{
		i=0;

		while (y!=0){
			y=x-y*(int)(x/y);

			if (x==y && i==0){
				return 1;
				break;
			}else if(y==0){
				return (int)x;
				break;
			}else{
				x=y;
				i++;
			}
		}
	}
}
