#include <stdio.h>
#include <math.h>
int somu(int k)
{
    int dem=0;
    while (k!=0)
    {
    k=k/10;
    dem++;
    }
    return dem;
}
int kiemtra(int k)
{
    int a,d,tong=0,j;
    d=somu(k);
    j=k;
    while (k!=0)
    {
        a=k%10;
        tong=tong+pow(a,d);
        k/=10;
    }
    if(tong==j)
        return 1;
    else return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int e=0,f=0;
    while (e<n)
    {
       if (kiemtra(f)==1)
       {
           printf("%d ",f);
        e++;
       }
        f++;
    }
}

