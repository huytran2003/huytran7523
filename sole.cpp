#include<stdio.h>
void sole(long long n){
	int dem=0;
	while(n!=0){
        int a= n%10 ;
            if(a%2==1){ 
             dem++;
            }
    n=n/10;
    } 
    printf("%d",dem); 
}
 int main(){
    long long n;
	scanf("%lld",&n);
	printf("%lld",sole(n)); 
    return 0;

}

