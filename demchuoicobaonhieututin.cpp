#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
int main()
{
 	char s[256];
 	char t;
 	printf("vui long nhap chuoi: ");
 	gets(s);
 	puts(s);
 	printf("vui long 1 ky tu: ");
 	scanf("%c",&t);
 	printf("%c ",t);
 	int dem=0;
 	for(int i=0;i<=strlen(s);i++)
     {
	 if(s[i]==t) dem=dem+1;  
	 }
 	printf(" so lan xuat hien ky tu %c la: %d ",t,dem);
    return 0;
}

