#include<stdio.h>
#include<math.h> 
#define MAX 100 
//nhap mang 
void nhap(int a[],int n){
	for (int i=0;i<n;i++)
	    scanf ("%d",&a[i]); 
} 
//xuat mang 
void xuat(int a[],int n){
	for(int i=0;i<n;i++)
	    printf("%d",a[i]); 
} 
//liet ke so chan trong mang 
void lkchan(int a[], int n){
	for(int i=0;i<n;i++)
	    if (a[i]%2==0)
		    printf("%d",&a[i]); 
} 
//liet ke so nguyen to trong mang 
int ktnnt(int so){
	if(so <=1) return 1;
	for(int i=2;i<sqrt(so);i++)
	    if(so%i==0) return 0;
    return 1; 
} 
// 
void hoanvi(int &x,int &y){
	int tam;
	tam =x;
	x=y;
	y=tam; 
} 
