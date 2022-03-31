#include<stdio.h>

int main(){
	long long a,b,S=0,i ;
	scanf("%lld%lld",&a,&b); 
	for( i=a;i<=b;i++){
	    if(i % 2 == 1)
	       S=S+i;
    }
	   printf("%lld",S);
}

