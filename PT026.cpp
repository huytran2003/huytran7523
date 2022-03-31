#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d",&a,&b);
    if (a<0 && b>0)
        printf("Zero");
    if (a>0 && b>0)
        printf ("Positive");
    if (a==0 || b==0)
        printf("Zero");
    if (a<0 && b<0){
       c=(a-b)+1;
       if (c % 2 ==0)
       printf("Positive");
       else printf ("Negative");
    }
    return 0;
}