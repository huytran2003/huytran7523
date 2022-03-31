#include <stdio.h>
int main(){
	int N, A, B, s=0, t;
	int so;
	scanf("%d%d%d",&N,&A,&B);
	for(int i=1; i<=N; i++){
		so = i;
		t=0;
		while(so>0){
			t=t+(so%10);
			so = so/10;
		}
		if(t>=A && t<=B)
			s = s+i;
	}
	printf("%d",s);
}
