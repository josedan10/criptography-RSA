void func_esquema(char *esquema){
	int i,j=0;

	/*>>>>> Reserva de memoria <<<<<*/
	esquema=(char *)calloc(100,sizeof(char));

	//Agregamos las letras minúsculas
	for (i=97; i<=122; i++,j++){
		esquema[j]=(char)i;
	}

	//Agregamos las letras mayúsculas
	for (i=65;i<=90;i++,j++){
		esquema[j]=(char)i;
	}

	//Agregamos los números
	for (i=48;i<=57;i++,j++){
		esquema[j]=(char)i;
	}

	//Agregamos el resto de los caracteres
	esquema[j++]=' ';esquema[j++]='!';esquema[j++]='¡';
	esquema[j++]='?';esquema[j++]='¿';esquema[j++]='á';
	esquema[j++]='í';esquema[j++]='ó';esquema[j++]='ú';
	esquema[j++]='é';esquema[j++]='ñ';esquema[j++]='Ñ';
	esquema[j++]=':';esquema[j++]=';';esquema[j++]='.';
	esquema[j++]=',';esquema[j++]='_';esquema[j++]='-';
	esquema[j++]='{';esquema[j++]='}';esquema[j++]='(';
	esquema[j++]=')';esquema[j++]='%';esquema[j++]='&';
	esquema[j++]='@';esquema[j++]='*';esquema[j++]='+';
	esquema[j++]='/';esquema[j++]='\\';esquema[j++]='|';
	esquema[j++]='$';esquema[j++]='"';esquema[j++]='\'';
	esquema[j++]='#';esquema[j++]='[';esquema[j++]=']';
	esquema[j]='~';

	printf("\n%s\n",esquema);

}
