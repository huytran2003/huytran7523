#include <stdio.h>

void nhap(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
}
void check(int a[], int n)
{
	int max1,max2,max3;
	max1 = max2 = max3;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = a[i];
		}
		else if(a[i]>max2)
		{
			max3 = max2;
			max2 = a[i];
		}
		else if(a[i]>max3){
			max3 = a[i];
		}
	}printf("%d %d %d", max1, max2, max3);
	
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	if(n<2)
	{
		return 0;
	}
	nhap(a, n);
	
	check(a, n);
}

