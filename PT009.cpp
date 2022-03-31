#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    double p,s;
    scanf("%f%f%f",&a,&b,&c);
    if ((a+b<=c)||(a+c<=b)||(c+b<=a))
    printf("No Solution");
    else{
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.6f",s);
    }
}