#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int A[n], i;
	float sum = 0;
	
	for(i = 0; i < n; i++){
		scanf("%d", &A[i]);	
		sum += A[i];
}
	printf("%.4f", (float)sum/n);	
	
	r
