int mcd(int a,int b) { 
    int max,min,r;
         
    // identificamos el mayor y menor de los numeros
    if(a>=b){
        max=a;min=b;
    }
    else{
        max=b;min=a;
    }
        
    while(min!=0){
        r=max%min;
        max=min;
        min=r;
    }
    return max;
}