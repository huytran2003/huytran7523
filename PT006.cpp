#include<stdio.h>

int main(){
	int x,y;
	scanf("%d%d",&x, &y); 
	if(x==0 && y==0)
	   printf("The coordinate point (0, 0) lies at the origin.");
    if(x>0 && y>0 )
       printf("The coordinate point (%d, %d) lies in the I quandrant.",x,y);
	if(x>0 && y<0)
	   printf("The coordinate point (%d, %d) lies in the IV quandrant.",x,y);
	if(x<0 && y<0)    
       printf("The coordinate point (%d, %d) lies in the III quandrant.",x,y);
    if(x<0 && y>0)    
       printf("The coordinate point (%d, %d) lies in the II quandrant.",x,y);
    return 0;

}

