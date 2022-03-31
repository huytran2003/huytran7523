#include<stdio.h>
#include<math.h>
void nhap(int n, int a[])
{
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
}
main(){
	long n;
	long dem=0;
	scanf("%ld",&n);
	int a[n];
	nhap(n, a);
		for(int i=0; i<n; i++)
		{
			if((a[i]%2==0) || ((a[i]<0) && (a[i]%3==0)))
				dem = dem+1;
		}
	printf("%ld",dem);
}

