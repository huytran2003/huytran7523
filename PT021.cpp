#include<stdio.h>
int main(){
    long long int N;
    int s =0,a ;
    scanf("%lld",&N);
    for (int i=1;i<=N;i++)
    {
        scanf( "%d",&a);
    while(N!=0){
        int a= N%10 ;
        if(a%2==0){ 
            s=s+a;
        }
    N=N/10;
    }
    printf("%d",s );
   
}
}
