#include<stdio.h>
#include<math.h>
int main(){
    int a, b, c, dem=0;
    scanf("%d", &a);
    b=a%10;
    c=a;
    int x=a;
    while(a!=0){
        a/=10;
        dem++;
    }
    for(int i=1;i<dem;i++){
       c/=10;
    }
    int m;
    m=b*pow(10,(dem-1))+x-c*pow(10,(dem-1))-b+c;
    printf("%d",m);
}
