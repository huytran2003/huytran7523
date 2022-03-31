#include<stdio.h>

int main(){
    
    float D, Dx, Dy, x, y,a1, a2, b1, b2, c1, c2;
    int N;
    scanf("%d",&N); 
	
    for (int i=1;i<=N;i++)
    {
	    scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
	    D = a1 * b2 - a2 * b1;
        Dx = c1 * b2 - c2 * b1;
        Dy = a1 * c2 - a2 * c1;
        x =  Dx*1.0 / D;
        y = Dy*1.0 / D;
        if (D == 0) {
            if (Dx ==0 && Dy == 0)
                printf("Many solutions\n");
            else if( Dx !=0 && Dy != 0 )		
                printf("No solution\n");
            }
            else {
            	printf("%.6f %.6f\n", x ,y);
            }
    }
    return 0;
}  

    
