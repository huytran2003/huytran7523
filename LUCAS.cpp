#include<stdio.h>
long long lucas (int n){
	if(n == 0) return 2 ;
	if(n ==1) return 1;
	return lucas (n-1) + lucas(n-2);
	 
} 
 
int main(){
    int n;
	scanf("%d",&n);
	for (int i=0;i<=n;i++) 
	printf("%ld ",lucas (i)); 
    return 0;

}

