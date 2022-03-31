#include<stdio.h>
 
int main(){
    int a1, b1, c1, a2, b2, c2;
    float D, Dx, Dy, x, y;
    printf("a1*x + b1*y = c1\n");
    printf("a2*x + b2*y = cc\n");
    printf("\nNhap a1: "); scanf("%d", &a1);
    printf("\nNhap b1: "); scanf("%d", &b1);
    printf("\nNhap c1: "); scanf("%d", &c1);
    printf("\nNhap a2: "); scanf("%d", &a2);
    printf("\nNhap b2: "); scanf("%d", &b2);
    printf("\nNhap c2: "); scanf("%d", &c2);
    scanf("%d", &x);
    scanf("%d", &y);
    D = a1 * b2 - a2 * b1;
    Dx = c1 * b2 - c2 * b1;
    Dy = a1 * c2 - a2 * c1;
    if (D == 0) {
        if (Dx + Dy == 0)
            printf("He phuong trinh co vo so nghiem");
        else
            printf("He phuong trinh vo nghiem");
    }
    else {
        x = Dx / D;
        y = Dy / D;
        printf("He phuong trinh co nghiem (x, y) = (%d, %d)", x, y);
    }
    return 0;
}
