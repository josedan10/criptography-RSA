int prime(int num){
	int i;
	//num>1 siempre, DEBO ASEGURAR ESTO
	if(num<2){
        return 0;
	}

	int mod,k=0;

    //printf("Numero: ");
    //scanf("%d",&num);

    for(i=2; i<=floor(sqrt(num));i++){
        mod=num%i;
        //printf("\nEl modulo es %d", mod);
        if(mod==0){
            k=1;
            //printf("\nEl numero %d no es primo\n",num);
            return 0;
            break;
        }
    }
    if(k==0){
        //printf("\nEl numero %d es primo",num);
        return 1;
    }

}
