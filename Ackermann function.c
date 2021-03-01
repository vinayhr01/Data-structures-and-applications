#include<stdio.h>
#include<stdlib.h>

int Ackermann(int m, int n)
{
    if(m==0)
    {
        return(n+1);       
    }
    if(n==0 && m>0)
    {
        return Ackermann(m-1,1);        
    }
    if(m>0 && n>0)
    {
        return Ackermann(m-1, Ackermann(m,n-1));
    }
}

void main()
{
    int m,n;
    
    printf("Enter m &n\n");
    scanf("%d%d",&m,&n);
    
   printf("The result is %d\n",Ackermann(m,n));  
}