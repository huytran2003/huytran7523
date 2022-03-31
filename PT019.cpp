#include<stdio.h>
int main(){
    long long int N;
    int dem =0;
    scanf("%lld",&N);
    while(N!=0){
        int a= N%10 ;
            if(a%2==1){ 
             dem++;
               }
    N=N/10;
    }
    printf("%d",dem);
   
}
