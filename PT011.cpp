#include<stdio.h>
#include<math.h> 
int main(){
    float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	printf("%.4f",0.5*a*b*sin(c*3.14159/180));
    return 0;

}

