#include <math.h>
int mcd(int y, int x){

	//Esta función retorna el mcd de dos números

   int max,min,r;

  // identificamos el mayor y menor de los numeros
  if(x>=y){
    max=x;min=y;}
  else{
    max=y;min=x;}

  while(min!=0){
    r=max%min;
    max=min;
    min=r;
  }
  return max;
}
