#include<stdio.h>
int main(){
	int n,max;
	int dem =0;
	scanf("%d ",&n);
	int a[n];
	for (int i =0;i <n;i++){
		scanf("%d",&a[i]);
	}
	max =a [0];
	for (int i =0;i <n;i++){
		if (a[i] > max )
		max = a[i];
		
    }
	for (int i =0;i <n;i++){
	    if (a[i] == max)
	        dem++;
    }
    printf("%d %d " ,max,dem );
}
