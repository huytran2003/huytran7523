#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int Mang[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&Mang[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(Mang[i]>=5 && Mang[i]<=7 )
		{
	      printf("%d ", Mang[i]); 
		}
	}
	return 0;
}
