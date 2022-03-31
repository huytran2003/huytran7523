#include<stdio.h>
#define nmax 1000001
void nhap(int a[],int n)
{
	for (int i = 1;i <=n;i++)
	{
		scanf("%d",&a[i]);
	}
}
int max(int a[],int n)
{
	int max = a[1];
	for (int i =1; i<= n;i++)
		if (max < a[i]) max = a[i];
	return max;
}
int min(int a[],int n)
{
	int min = a[1];
	for (int i = 1; i < n;i++)
		if (min > a[i]) min = a[i];
	return min;
}
int a[nmax];
int main()
{
	int n;
	scanf("%d",&n);
	nhap(a,n);
	int kq = 0;
	kq = max(a,n) - min(a,n);
	printf("%d",kq);

}
