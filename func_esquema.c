#include <stdlib.h>
#include <stdio.h>
void func_esquema(char *esquema){

	int i, j;

	//Agregamos las letras min�sculas
	for (i=97, j=0; i<=122; i++, j++){
		esquema[j]=(char)i;
	}

	//Agregamos las letras may�sculas
	for (i=65; i<=90; i++, j++){
		esquema[j]=(char)i;
	}

	//Agregamos los n�meros del 0 al 9

	for (i=48; i<=57; i++, j++){
		esquema[j]=(char)i;
	}

	//Agregamos el espacio, !, �, ?, �

	esquema[j++]=' ';esquema[j++]='!';esquema[j++]=(char)173;
	esquema[j++]='?';esquema[j++]=(char)168;

	//Agregamos �, �, �, �
	for (i=160;i<=163;i++,j++){
		esquema[j]=(char)i;
	}

	/*Agregamos �, �, �, ':', ';', '.', ',', '_', '-', '{', '}',
	'(',')', '%', '&', '@', '*', '+', '/', '\','|', '$', ''', ''', '#',
	'[', ']', '~'*/
	esquema[j++]=(char)130;esquema[j++]=(char)164;esquema[j++]=(char)165;
	esquema[j++]=':';esquema[j++]=';';esquema[j++]='.';
	esquema[j++]=',';esquema[j++]='_';esquema[j++]='-';
	esquema[j++]='{';esquema[j++]='}';esquema[j++]='(';
	esquema[j++]=')';esquema[j++]=(char)37;//Este es el valor de '%', de la otra manera de error de sintaxis
	esquema[j++]='&';esquema[j++]='@';esquema[j++]='*';
	esquema[j++]='+';esquema[j++]='/';esquema[j++]='\\';//Revisar '\'
	esquema[j++]='|';esquema[j++]='$';esquema[j++]='"';
	esquema[j++]='\'';esquema[j++]='#';esquema[j++]='[';
	esquema[j++]=']';esquema[j]='~';
}
