#include<stdio.h>
#include<math.h> 
#define MAX 100 
//1.nhap mang 
void nhap(int a[],int  n){
	for (int i=0;i<n;i++){
	  printf("\nNhap a[%d]: ", i);
        scanf("%f", &a[i]);
    }
} 
//2. Xuat phan tu am 
void xuat(int a[],int n){
	for(int i=0;i<n;i++){
	    if(a[i]<0) 
	       printf("Cac phan tu am la %d ",a[i]); 
}
}

//3.vi tri phan tu lon nhat va nho nhat
void Min(int A[], int n)
{
	int vitri = 0;
	int min = A[0];
	for (int i = 0; i < n; i++)
	{
		if (min > A[i])
		{
			min = A[i];
			vitri = i;
		}
		
	}
	printf("Vi tri cua phan tu nho nhat la %d\n",min);
}
void Max(int A[], int n)
{
	int vitri = 0;
	int max = A[0];
	for (int i = 0; i < n; i++)
	{
		if (max < A[i])
		{
			max = A[i];
			vitri = i;
		}
	}
	printf("vi tri cua pha tu lon nhat la %d\n",vitri);
}
//4. phan tu am dau tien  
float amdautien(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
         if (a[i]<0)
         {
         	printf("Phan tu am dau tien trong mang la %d\n",a[i]); 
         }
    }
    return -1;
}
//5.tong cac so duong trong mang
float tongduong(int a[], int n)
{
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
        {
            s = s + a[i];
        }
    }
     printf("Tong cac so duong trong mang là %d\n",s);
} 

// Xoa cac phan tu o vi tri le trong mang

//Chen them mot so vao vi tri xac dinh trong mang 

int main(){
	int n;
	int a[100]; 
	scanf("%d",&n); 
	nhap (a,n);
	xuat (a,n);
	Min(a,n);
	Min(a,n);
    amdautien(a,n);
	tongduong(a,n);
	return 0 ;
} 

 
