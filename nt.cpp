
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 100 // s?c ch?a t?i ða
 
void NhapMang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}
 
void XuatMang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\narr[%d] = %d", i, arr[i]);
    }
}
 
/*
    Ki?m tra s? nguyên t?
*/
bool IsPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
 
/*
    Ð?m s? lý?ng s? nguyên t?
*/
int PrimeCount(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (IsPrime(a[i]))
        {
            count++;
        }
    }
    return count;
}
 
/*
    Li?t kê các s? nguyên t?
*/
 
void PrintPrime(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (IsPrime(a[i]))
        {
            printf("%d\t", a[i]);
        }
    }
}
 
int main()
{
    int arr[MAX_SIZE];
 
    int n; // s? lý?ng ph?n t? c?a m?ng
    // Ki?m tra s? lý?ng ph?n t? là s? dýõng + nh? hõn MAX_SIZE
    do
    {
        printf("Nhap n = ");
        scanf("%d", &n);
    } while (n <= 0 || n > MAX_SIZE);
 
    // Nh?p m?ng
    NhapMang(arr, n);
 
    // Xu?t m?ng
    XuatMang(arr, n);
 
    // Gi?i bài toán
    int primeCount = PrimeCount(arr, n);
    printf("\nSo luong so nguyen to la %d", primeCount);
    if(primeCount > 0){
        printf("\nDanh sach so nguyen to: ");
        PrintPrime(arr, n);
    }
}
