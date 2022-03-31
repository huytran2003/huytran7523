#include <stdio.h>
void SAPXEP(int a[], int n)
{
    for (int i=1; i<=n-1; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    int a[1000];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int A = (n*10)/100;
    SAPXEP(a, n);
    for(int i = 1; i <= A; i++){
        printf("%d ", a[i]);
    }
}
