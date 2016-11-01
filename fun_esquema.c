(char*) fun_esquema(char *esquema){

	//Reservamos espacio para almacenar los 99 caracteres.
	int i, j;

	esquema= (char*)malloc(99*sizeof(char));

	if (esquema==NULL){
		puts("Error al reservar memoria para el esquema");
		exit(1);
	}else{

		//Agregamos las letras minúsculas
		for (i=97, j=0; i<=122; i++, j++){
			esquema[j]=(char)i;
		}

		//Agregamos las letras mayúsculas
		for (i=65; i<=90; i++, j++){
			esquema[j]=(char)i;
		}

		//Agregamos los números del 0 al 9

		for (i=48; i<=57; i++, j++){
			esquema[j]=(char)i;
		}

		//Agregamos el espacio, !, ¡, ?, ¿

		esquema[++j]=" ";esquema[++j]="!";esquema[++j]="¡";
		esquema[++j]="?";esquema[++j]="¿";

		//Agregamos á, í, ó, ú
		for (i=160;i<=163;i++,j++){
			esquema[j]=(char)i;
		}

		/*Agregamos é, ñ, Ñ, ":", ";", ".", ",", "_", "-", "{", "}",
		"(",")", "%", "&", "@", "*", "+", "/", "\","|", "$", '"', "'", "#",
		"[", "]", "~"*/
		esquema[++j]="é";esquema[++j]="ñ";esquema[++j]="Ñ";
		esquema[++j]=":";esquema[++j]=";";esquema[++j]=".";
		esquema[++j]=",";esquema[++j]="_";esquema[++j]="-";
		esquema[++j]="{";esquema[++j]="}";esquema[++j]="(";
		esquema[++j]=")";esquema[++j]=(char)37;//Este es el valor de "%", de la otra manera de error de sintaxis
		esquema[++j]="&";esquema[++j]="@";esquema[++j]="*";
		esquema[++j]="+";esquema[++j]="/";esquema[++j]="\\";//Revisar "\"
		esquema[++j]="|";esquema[++j]="$";esquema[++j]='"';
		esquema[++j]="'";esquema[++j]="#";esquema[++j]="[";
		esquema[++j]="]";esquema[++j]="~";
	}
	return esquema;

}