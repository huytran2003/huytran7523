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
void hoanvi(int &x,int &y){
	int tam;
	tam =x;
	x=y;
	y=tam; 
} 
void sxgiam(int a[],int n){
	for(int i=0;i<n-1;i++)
	    for(int j=i+1;j<n;j++){
	 	   	if(fabs(a[i]) < fabs(a[j]) || (fabs(a[i]) == fabs(a[j]) && a[i]<a[j]))
			   hoanvi(a[i], a[j]) ;
		} 
		
		 
} 
int main(){
	int n;
	scanf("%d ",&n);
	int a[n];
	nhap (a,n);
	sxgiam(a,n);
	xuat(a,n); 
	
} 


   

