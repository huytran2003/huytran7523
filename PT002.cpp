#include<stdio.h>
#include<math.h>
#include<string.h> 
int main(){
	float x1,x2,y1,y2;
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	printf("%.4f\n",sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
	return 0; 
} 

