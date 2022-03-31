#include<stdio.h>
int main(){
    long long int N;
    int dem =0;
    scanf("%lld",&N);
    if(N==0) dem=1;
    else 
    while(N!=0){
          int a= N%10 ;
          if(a%2==0){ 
             dem++;
               }
    N=N/10;
    }
    printf("%d",dem);
   
}