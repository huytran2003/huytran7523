#include<stdio.h>

int kt(int n){
	int i;
	for(i=2;i<=n/2;i++){
		if(n%i==0){
			return 1; 
		} 
	}
	return 0; 
} 
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		if(kt(i)==0){
			printf("%d ",i);
		} 
	}
	return 0; 
} 
