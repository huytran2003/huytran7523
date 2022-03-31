#include<stdio.h>
int main()
{
   int n, a, b, tong=0, i, i2;
   scanf("%d", &n);
   scanf("%d%d", &a, &b);
   for(i=1;i<=n;i++)
   {
   	i2=i;
   	int c=0;
   	while(i2!=0) 
   	{
   	    c=c+i2%10;
		i2=i2/10;   	
   	}
   	if(c>=a && c<=b)
    {
   	    tong=tong+i;	
   	}
   }
   printf("%d", tong);	
}
