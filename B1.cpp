#include<stdio.h>

int main(){
    int a1,b1,c1,d1,a2,b2,c2,d2;
	scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2);
	if(0<a1,a2,b1,b2,c1,c2,d1,d2<225) {
	    if (a1 == a2 ){
		    if(0< a1,a2 <127) {
	            printf("YES");
            }
	        if(b1 == b2 ){ 
	            if(128 < a1,a2 <191){ 
	                printf("YES");
	            }
	            if (c1 == c2){
	      	        if(192< a1,a2 <223){
	           	        printf("Yes");
	                }
	            }
	       }
        }
	else
	    printf("No") ;
    return 0;
    }  
}

