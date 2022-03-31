#include<stdio.h>
#include<math.h> 
int main(){
	int n,max;
	scanf("%d ",&n);
	int a[n];
	for (int i =0;i <n;i++){
		scanf("%d",&a[i]);
	}
	max =a [0];
	for (int i =0;i <sqrt(n);i++){
		if (a[i] % n==0 ){
			max = a[i];
			if(max <a[i])
			 max=a[i]; 
		}
		
}
printf("%d",max);
}


