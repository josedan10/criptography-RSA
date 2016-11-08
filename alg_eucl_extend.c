int* alg_euc_ext(int n,int a) // a mod n
{   
    int array[3],x=0,y=0,d=0,x2=1,x1=0,y2=0,y1=1,q=0,r=0;

    if(a==0){
        array[0]=n;
        array[1]=1; 
        array[2]=0;  
    }
    else{

        while(a>0) {
            q=(n/a); 
            r=n - q*a; 
            x=x2-q*x1; 
            y=y2 -q*y1; 
            n=a; 
            a=r; 
            x2=x1; 
            x1=x; 
            y2=y1;             
            y1=y; 
        }
        array[0]=n;   // mcd (n,a)
        array[1]=x2;   // x
        array[2]=y2;   // y
    }
    return array;
}