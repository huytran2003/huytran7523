#include<stdio.h>
#include<math.h>
  
int scp(int n){
	int a=sqrt(n), b=n;
	if(a*a==b) return 1;
	else return 0;
	}

  int main(){
    int n;
    int sum =0;
    int a;
    scanf("%d",&n);
    while(n>0){
    a = n %10;
    sum += a;
    n = n /10;
	}
	if(scp(sum) == 1){
	  printf("%d Yes",sum);
	}else{
		printf("%d No", sum);
	}
  }
