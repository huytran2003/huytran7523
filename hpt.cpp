#include<stdio.h>
int main(){
  
  int a1,a2,b1,b2,c1,c2,n,i;
  float D, Dx, Dy, x, y;
  scanf("%d%d%d%d%d%d",&a1,&a2,&b1,&b2,&c1,&c2);
  D = a1 * b2 - a2 * b1;
  Dx = c1 * b2 - c2 * b1;
  Dy = a1 * c2 - a2 * c1;
  if (D == 0) {
    if (Dx + Dy == 0)
      printf("Many solutions");
    else
      printf("No solution");
    }
    else {
    x = Dx / D;
    y = Dy / D;
    printf(" %.6f  %.6f", x, y);
    }
 }
