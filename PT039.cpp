#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 100
void nhapmang(int a[], int &n);
void xuatmang(int a[], int n);
int SNT(int n);
int VtriSNTLonNhat(int a[], int n);
int  main()
{
	int a[MAX],n;
	nhapmang(a,n);
	printf("\nNoi dung cua mang");
	xuatmang(a,n);
	if(VtriSNTLonNhat(a,n)==-1)
		printf("\nTrong mang khong co SNT ");
	else
		printf("\nVi tri SNT lon nhat trong mang la: %d",VtriSNTLonNhat(a,n));
	printf("\nChuc cac ban hoc tot");
	getch();
}
void nhapmang(int a[], int &n)
{
	do
	{
		printf("\nSo phan tu trong mang ");
		scanf("%d",&n);
	}while(n<=0 && n>100);
	for(int i=0 ; i<n ; i++ )
	{
		printf("\nSo phan tu a[%d] la: ",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[], int n)
{
	for(int i=0 ; i<n ; i++ )
		printf("%4d",a[i]);
}
int SNT(int n)
{
	int dem=0;

	for(int i=1;i<=n;i++)
		if(n%i==0)
			dem++;
	if(dem==2)
		return 1;
	else
		return 0;
}
int VtriSNTLonNhat(int a[], int n)
{
	int vt,d,i;
	for( i=0 ; i<n ; i++ )
		if(SNT(a[i])==1)
		{
			d=i;
			break;
		}
	if(i==n)
		return -1;
	vt=d;
	for(i=vt+1;i<n;i++ )
		if(SNT(a[i])==1 && a[i]>a[vt])
			vt=i;
	return vt;
}
