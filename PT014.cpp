#include "stdio.h"

long giaithua(int N);
 
void main(int N)
{
    int N;
    long ket_qua;
    do
    
    {
        scanf("%d", &N);
    }
    while(N < 0);
        ket_qua = giaithua(N);
        printf("%ld", ket_qua);
}
 
long giaithua(int N)
{
    if(N == 0 || N == 1)
    return 1;
    else
    return N * giaithua(N-2);
}
