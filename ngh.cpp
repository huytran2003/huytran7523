#include<stdio.h>

int main(){
    int n,a,N;
    int s=0; 
	scanf("%d",&n);
	a=n%1000;
	for(;n!=0;){
        N = n % 10;
        s += N;
        n /= 10;
    }    
    if(a % 8 == 0 && s % 9 == 0)
	printf("YES %d %d ", a ,s );
	else 
	printf("NO %d %d ", a ,s) ;
    return 0;

}

