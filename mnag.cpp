#include<stdio.h>
#include<math.h> 
#define MAX 100 
void nhap(int a[],int n){
	for (int i=0;i<n;i++)
	    scanf ("%d",&a[i]); 
} 
void xuat(int a[],int n){
	for(int i=0;i<n;i++)
	    printf("%d ",a[i]); 
} 
int main(){
	int n;
	scanf("%d ",&n);
	int a[n];
	nhap (a,n);
	xuat(a,n); 
	
} 

