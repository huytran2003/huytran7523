#include<stdio.h>
void nhapmang(int* A, int k)
{
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &A[i]);
	}
}
int main()
{
	int N,i,hv;
	int	*X;
	scanf("N");
	X = new int [N];
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &X[i]);
		X[0] = hv;
		X[N] = X[0];
		hv = X[N];
		printf("%d", X[i]);
	}
}
