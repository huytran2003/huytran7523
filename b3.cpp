#include<stdio.h>
int main(){
	int n,min;
	int dem =0;
	scanf("%d ",&n);
	int a[n];
	for (int i =0;i <n;i++){
		scanf("%d",&a[i]);
	}
	min =a [0];
	for (int i =0;i <n;i++){
		if (a[i] < min )
		min = a[i];
		
    }
	for (int i =0;i <n;i++){
	    if (a[i] == min)
	        dem++;
    }
    printf("%d %d " ,min,dem );
}
