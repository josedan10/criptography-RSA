int func_texto2num(/*esquema*/void (*func_esquema)(char *),
	/*vec^s(mod n)*/(*func_vec_elev_s_mod_n)(int,int,int),
	/*msg*/char *msg, /*msgCod*/ int *msgCod, 
	/*codificadores exp=s y mod=n*/int s, int n){
	
	/*Debemos buscar cada caracter en el esquema y pasar su posicion
	al vector de numeros para codificarlos*/
	int i, j, k, z, largo=strlen(msg), val, nums[2], num;

	/*>>>>> Variables <<<<<*/
	/*'i' es el contador para el msg,
	  'j' es el contador para el msgCod,
	  'k' es el contador para buscar la posicion en el esquema,
	  'z' es el contador para indicar el indice en el vector 'nums',
	  'val' es la variable que verifica que los ascii de el caracter del
	  msg y el del esquema coinciden*/


	for (i=0,j=0;i<largo,i++){
		
		for (k=0;k<99;k++){
			val=(int)msg[i]-(int)esquema[k];

			if(val==0){
			/*En el vector nums almacenamos los indices de dos caracteres*/
				nums[z++]=k;
				break;
			}
		}

		if(i%2==1){

			/*Si los codigos son, por ejemplo, 2 y 34, num debe ser igual a
			num=(2*100)+34 --> num=200+34=234*/

			/*Si los codigos son, por ejemplo, 32 y 53, num debe ser igual a
			num= (32*100)+53 --> num=3200+53=3253*/

			num=(nums[0]*100)+nums[1];
			free (nums);

			msgCod= (int *)calloc((largo/2),sizeof(int));

			if(msgCod==NULL){
				printf("\nError en la reserva de memoria para los numeros\n");
				return 1;
			}

			//Elevamos cada numero del vector de numeros r^s (mod n)

			func_vec_elev_s_mod_n(msgCod, s, n);
			z=0;
		}
	}
	free (msgCod);
	return 0;
}