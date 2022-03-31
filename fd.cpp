#include <stdio.h>
int main (){
	int N,j;
	scanf ("%d",&N);
	int Sonut;
	int t = 0;
	for (int i = 1; i <= N; i++){
	j=i;
	Sonut=0;
	while (j>0){
		Sonut = Sonut + (j % 10);
		j = j / 10;
		}
		if (Sonut  % 10 == 9)
			t = t + 1 ;
			
			}
			printf("%d",t);
			return 0;
			}