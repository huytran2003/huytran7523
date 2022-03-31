#include<bits/stdc++.h>

int main()
{
	long a;
	scanf("%ld",&a);
	if(a >= 1 && a <= 1000000000)
	{
		int y = a/365;
		int m = (a%365)/30;
		int d = (a%365)%30;
		if(y > 0)
		{
			printf("%d years \n",y);
		}
		if(m > 0)
		{
			printf("%d months \n",m);
		}
		if(d > 0)
		{
			printf("%d days",d);
		}
	}
	return 0;
}
