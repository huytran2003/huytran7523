#include<stdio.h>
#include<math.h>
int main(){
    int N, dem, a;
    scanf("%d",&N);
    dem=0;
    for (int i=1;i<=N;i++)
    {
        scanf( "%d",&a);
         if ((a%3==0)|| (a%7==0))
        dem=dem+1;
      }
    printf("%d",dem);
    return 0;
}

