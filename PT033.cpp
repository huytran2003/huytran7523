#include <stdio.h>
#include<math.h>
int main()
{
	double a, b, c;

	scanf("%lf%lf%lf", &a, &b, &c);

	double p1 = (b / 100) + 1;
	double p2 = c / a;

	printf("%.lf", ceil(log(p2) / log(p1)));

	return 0;
}
