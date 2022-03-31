#include<stdio.h>
#include<math.h>
int main(){
    float x,a,b,c,d;
    a=1/(1+x*x);
    b=x-2*x*x*x;
    c=sqrt (x*x-1);
    d= 2*x*x*x-x;
    scanf("%f",&x);
    
    if(x>-1 && x<1) {
        printf("a");
    }
    if (x<=-1){
        printf("b");
    }
    if(x>=1){
       printf("c");
    }
    printf("d");
    if(a>d ||b>d || c>d){
       printf("YES");
    else printf("NO");
    }
}
