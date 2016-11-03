int mcd(int y, int x){

	//Esta función retorna el mcd de dos números

	int temp, i;

	if (x<y){
		temp=x;
		y=x;
		x=temp;
	}
	//Si y divide a x, entonces mcd(x,y)=y
	int mod=x%y;

	if (mod==0){
		return y;
	}else{
		i=0;

		while (y!=0){
			y=x-y*(int)(x/y);

			if (x==y && i==0){
				//Si esto ocurre significa que son coprimos, mcd(x,y)=1
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
