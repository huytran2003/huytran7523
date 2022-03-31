#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c = 10,d = 0;
    scanf("%d",&a);
    b = a % 10;
    a = a / 10;
    while(a / 10 != 0){
        d = d + (a%10)*c;
        c = c * 10;
        a = a /10;
    }
    b = b * c + d + a;
    printf("%d", b);
    return 0;
}
