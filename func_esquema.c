void func_esquema(char *esquema){
		
	int i, j;

	//Agregamos las letras min√∫sculas
	for (i=97, j=0; i<=122; i++, j++){
		esquema[j]=(char)i;
	}

	//Agregamos las letras may√∫sculas
	for (i=65; i<=90; i++, j++){
		esquema[j]=(char)i;
	}

	//Agregamos los n√∫meros del 0 al 9

	for (i=48; i<=57; i++, j++){
		esquema[j]=(char)i;
	}

	//Agregamos el espacio, !, °, ?, ø

<<<<<<< HEAD
	esquema[++j]=' ';esquema[++j]='!';esquema[++j]='°';
	esquema[++j]='?';esquema[++j]='ø';
=======
	esquema[++j]=' ';esquema[++j]='!';esquema[++j]='¬°';
	esquema[++j]='?';esquema[++j]='¬ø';
>>>>>>> origin/master

	//Agregamos ·, Ì, Û, È
	for (i=160;i<=163;i++,j++){
		esquema[j]=(char)i;
	}

<<<<<<< HEAD
	/*Agregamos 'Ò', '—', ':', ';', '.', ',', '_', '-', '{', '}',
	'(',')', '%', '&', '@', '*', '+', '/', '\','|', '$', ''', ''', '#',
	'[', ']', '~'*/
	esquema[++j]='Ò';esquema[++j]='—';esquema[++j]=':';esquema[++j]=';';esquema[++j]='.';
=======
	/*Agregamos √©, √±, √ë, ':', ';', '.', ',', '_', '-', '{', '}',
	'(',')', '%', '&', '@', '*', '+', '/', '\','|', '$', ''', ''', '#',
	'[', ']', '~'*/
	esquema[++j]='√©';esquema[++j]='√±';esquema[++j]='√ë';
	esquema[++j]=':';esquema[++j]=';';esquema[++j]='.';
>>>>>>> origin/master
	esquema[++j]=',';esquema[++j]='_';esquema[++j]='-';
	esquema[++j]='{';esquema[++j]='}';esquema[++j]='(';
	esquema[++j]=')';esquema[++j]='%';//Este es el valor de '%', de la otra manera de error de sintaxis
	esquema[++j]='&';esquema[++j]='@';esquema[++j]='*';
	esquema[++j]='+';esquema[++j]='/';esquema[++j]='\\';//Revisar '\'
	esquema[++j]='|';esquema[++j]='$';esquema[++j]='"';
<<<<<<< HEAD
	esquema[++j]='\'';esquema[++j]='#';esquema[++j]='[';esquema[++j]=']';esquema[j]='~';
}
=======
	esquema[++j]='\'';esquema[++j]='#';esquema[++j]='[';
	esquema[++j]=']';esquema[++j]='~';
}
>>>>>>> origin/master
