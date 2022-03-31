#include<stdio.h>
long long lucas2(int n){
long long  a,b, lu;;
	a=2;
	b=1;
	if (n == 0) lu = 2;
	else if (n == 1) lu = 1;
	else{
		for (int i = 2;i <= n;i++){
			lu = a + b ;
			a = b;
			b = lu ;
		} 
	} 
	return lu ; 
} 
int main(){
    int n;
	scanf("%d",&n);
	for (int i=0;i<=n;i++) 
	printf("%ld ",lucas2( i)); 
    return 0;

}



