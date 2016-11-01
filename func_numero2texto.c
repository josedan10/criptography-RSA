(char*) func_numero2texto(char *numero, char *esquema, char* texto){
	char letra;//Apuntador a donde se van a almacenar los caracteres
	int tam, i, j, k, pos;

	//Necesitamos calcular el tamaño del numero y verificar que sea par
	tam=/*(strlen(*numero)%2!=0)?strlen(*numero)/2+1:*/strlen(*numero)/2;

	//Reservamos memoria para el texto
	//Debe ser la mitad de "numero" porque por cada 2 numeros hay un caracter.
	texto=(char *)calloc(tam,sizeof(char)); 

	for (i=0, j=0; i<=strlen(*numero); j++){
		for(k=0;k<2;k++){
			pos=((int)numero[i]-48)+((int)numero[++i]-48);
			letra=esquema[pos];
			texto[j]=letra;
			i++;
		}
	}

	return *texto;
}