#include <stdlib.h>
#include <stdio.h>
void func_esquema(char *esquema){

	int i, j;

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

	esquema[j++]=' ';esquema[j++]='!';esquema[j++]=(char)161;
	esquema[j++]='?';esquema[j++]=(char)191;

	//Agregamos á, í, ó, ú
	for (int voc = 12, i = 225; voc != -15; voc = voc + 1) {
		if (voc == 13) { voc = 6; }
		esquema[j++] = (char)i;
		if (voc == 8) { voc = -17; }
		i = i + voc;
	}
	

	/*Agregamos é, ñ, Ñ, ':', ';', '.', ',', '_', '-', '{', '}',
	'(',')', '%', '&', '@', '*', '+', '/', '\','|', '$', ''', ''', '#',
	'[', ']', '~'*/
	esquema[j++]=(char)233;esquema[j++]=(char)241;esquema[j++]=(char)209;
	esquema[j++]=(char)58;esquema[j++]=(char)59;esquema[j++]=(char)46;
	esquema[j++]=(char)44;esquema[j++]=(char)95;esquema[j++]=(char)45;
	esquema[j++]=(char)123;esquema[j++]=(char)125;esquema[j++]=(char)40;
	esquema[j++]=(char)41;esquema[j++]=(char)37;//Este es el valor de '%', de la otra manera de error de sintaxis
	esquema[j++]=(char)38;esquema[j++]=(char)64;esquema[j++]=(char)42;
	esquema[j++]=(char)43;esquema[j++]=(char)47;esquema[j++]=(char)92;//Revisar '\'
	esquema[j++]=(char)124;esquema[j++]=(char)36;esquema[j++]=(char)34;
	esquema[j++]=(char)39;esquema[j++]=(char)35;esquema[j++]=(char)91;
	esquema[j++]=(char)93;esquema[j]=(char)126;
}
