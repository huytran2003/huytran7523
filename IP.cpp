#include<stdio.h>

int main(){
    int a1,a2,b1,b2,c1,c2,d1,d2;
	scanf("%d%d%d%d%d%d", &a1, &b1, &c1, &d1, &a2, &b2, &c2, &d2);
	if ((a1==a2 && (a1>=0 && a1<=127)) || (a1==a2 && b1==b2 && (a1>=128&& a1<=191)) || (a1==a2 && b1==b2 && c1==c2 && (a1>=192 && a1<=223)))
	    printf("YES");
	else
	    printf("NO");
    return 0;

}

