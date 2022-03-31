#include <stdio.h>

int main() {
 float a,b,c;
 scanf("%f", &a);
 scanf("%f", &b );
 scanf("%f", &c);
 if( a<b+c && b<a+c && c<a+b ){
     if(a==b && b==c)
      printf("Tam giac deu ");
    else if(a==b || a==c || b==c)
      printf("Tam giac can ");
    else 
    printf("Tam giac thuong ");
 }
  return 0;
}