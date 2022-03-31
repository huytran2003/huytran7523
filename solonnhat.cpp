#include<stdio.h>

int main(){
	int a,b,c,d,e, max=0;
	scanf("%d%d",&a,&b);
	c = a + b;
	d = a - b;
	e = a * b;
	max = c;
    if(max < d) {
        max = d; 
    }
    if(max <  e){
        max=e; 
    }
    printf("%d", max); 

    return 0;

}

