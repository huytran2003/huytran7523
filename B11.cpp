#include<stdio.h>

int main(){
int a1,b1,c1,d1,a2,b2,c2,d2;
	scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2);
	if(a1=a2 && 0<=a1<=127  && 0<= a2 <=127){
		   printf("YES");
	   }
		if(a1=a2 && b1==b2 && 128 <=a1 <=191 && 128<=a2 <= 191 ){ 
		   printf("YES");
	   }
	   if(a1=a2 && b1==b2 && c1==c2 && 192 <= a1 <=223 && 192<=a2<=223 ){
	   	   printf("YES");
	   }
	else 
	    printf("NO");
    return 0;
}


