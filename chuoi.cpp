#include<stdio.h>
#include<string.h>
int demc(char str[])
{
	int i = 0;
	while(str[i]!='\0')
	{
		i++;
	}
	return i;
}
char NhapChuoi(char str[])
{
	scanf("%[^\n]", str);
}
void XuatChuoi(char str[])
{
	int len = demc(str);
	for(int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
}
 
int demKhoangTrang(char str[])
{
	char k = ' ';
	int dem = 0;
	int len = demc(str);
	for(int i = 0; i < len; i++)
	{
		if(str[i] == k)
		{
			dem++;
		}
	}
	return dem;
}
 
void splitName(char str[])
{
	char k = ' ';
	int len = demc(str);
	for(int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
		if(str[i] == k)
		{
			break;
		}
	}
	int point = 0;
	for(int i = len; i > 0; i--)
	{
		if(str[i] == k)
		{
			point = i + 1;
			break;
		}
	}
	for(int i = point; i < len; i++)
	{
		printf("%c", str[i]);
	}
}
 
int main()
{
	char str[100];
	printf("Nhap vao ten day du cua ban: ");
	NhapChuoi(str);
	XuatChuoi(str);
	printf("\n");
	demKhoangTrang(str);
	printf("Chuoi co %d khoang trang", demKhoangTrang(str));
	printf("\n");
	splitName(str);
	return 0;
}
