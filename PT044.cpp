#include<stdio.h>
#include<math.h>
void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
 
void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", i, a[i]);
    }
}
bool ktnt(int n)
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
void lknt(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ktnt(a[i]))
        {
            printf("%d\t", a[i]);
        }
    }
}
int main()
{
    int a[];
 
    int n; 
    do
    {
        printf("Nhap n = ");
        scanf("%d", &n);
    } while (n <= 0 || n > MAX_SIZE);
 
     NhapMang(a, n);
 
    XuatMang(a, n);
 
    int primeCount = PrimeCount(arr, n);
    printf("", primeCount);
    if(primeCount > 0){
        printf("\nDanh sach so nguyen to: ");
        PrintPrime(arr, n);
    }
}
