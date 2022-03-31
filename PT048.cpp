#include <stdio.h>

int main(){
	int n, m;
	scanf("%d", &n);
       int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i]<=a[i+1]) 
		m = 1;  
		else {
			m = 0;
			break;
		} 
	}if(m==1) printf("Yes");
	else printf("No");
	return 0;
}
	
