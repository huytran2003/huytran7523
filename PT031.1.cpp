#include "stdio.h"
int main()
{
    int A[10][10];
    int h;
    int i, j;
    do
    {
         scanf("%d ", &h);
    }
    while(h > 10);
    for(i = 0;i < h;i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(i == j || j == 0)
            {
                A[i][j] = 1;
                printf("%d", A[i][j]);
            }
            else
            {
                A[i][j] = A[i-1][j-1] + A[i-1][j];
                printf("%d ", A[i][j]);
            }
        }
        printf("\n");
    }
}

