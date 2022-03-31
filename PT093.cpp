#include<string.h>
#include <stdlib.h>
#include<stdio.h>
int main() {
	char s[150];
	while(gets(s)) {
	int i,dem;
	dem=1;
	for (int i=0;i<strlen(s);i++) {
		if (s[i]>='A'&&s[i]<='Z')
			dem++;
		}
	printf("%d\n",dem);
}
	return 0;
}
