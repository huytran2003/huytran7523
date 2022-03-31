#include<stdio.h>
int main()
{
	int a1, b1, c1, d1, a2, b2, c2, d2;
	scanf("%d%d%d%d", &a1, &b1, &c1, &d1);
	scanf("%d%d%d%d", &a2, &b2, &c2, &d2);
	if(0<=a1<=127 && 0 <= a2 <= 127)
	{
		if (a1 == a2)
			printf("Yes");
		else
			printf("No");
	}
	 else if(128 <= a1 <= 191 && 128 <= b1 <= 191 && 128 <= a2 <= 191 && 128 <= b2 <= 191)
	{
		if(a1==a2&&b1==b2)
			printf("Yes");
		else
			printf("No");
	}
	 else if (192 <= a1 <= 223 && 192 <= b1 <= 223 && 192 <= c1 <= 223 && 192 <= a2 <= 223 && 192 <= b2 <= 223 && 192 <= c2 <= 223)
	{
		if(a1==a2&&b1==b1&&c1==c2)
			printf("Yes");
		else
			printf("No");
	}
	 else
		printf("No");
}
