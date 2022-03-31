#include <stdio.h>
int main (){
	int T,n,t=0,sc;
	scanf ("%d",&T);
    for (int i = 1; i <= T; i++){
	     scanf("%d",&n);
         if(n<0) n*=(-1);
         t=0;
	     while (n!=0){
		        sc=n%10;
        		if (sc % 2== 0)
			        t = t + sc ;
                n=n/10;
		}
	    printf("%d\n",t);
    }
    return 0;
}