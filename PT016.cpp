#include<stdio.h>
int main(){
    int N, dem, a;
    scanf("%d",&N);
    dem=0;
    for (int i=1;i<=N;i++)
    {
        scanf( "%d",&a);
         if ((a%19==0)|| (a%19==3)||(a%19==6)||(a%19==9)||(a%19==11)||(a%19==14)||(a%19==17))
        dem=dem+1;
    }
    printf("%d",dem);
    return 0;
}
