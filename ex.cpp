#include<stdio.h>
int main()
{
  int i, n, temp;
  int max = 0;
  //s? d?ng v?ng l?p do..while �? y�u c?u ng�?i d�ng nh?p v�o s? nguyen d��ng n
  //n?u n < 0 th? y�u c?u nh?p l?i
  do
  {
    printf("\nNh?p v�o s? nguy�n d��ng n: ");
    scanf("%d", &n);
  }while(n < 0 && printf("\nS? n ph?i l?n h�n ho?c b?ng 0!!"));
  temp = n;
  //n?u n = 0 th? max = 0
  if(n == 0)
    max = 0;
  //s? d?ng v?ng l?p do..while �? t?m ch? s? l?n nh?t trong n
  do
  {
    i = n % 10;
    if(i > max)
    {
      max = i;
    }
  }while(n /= 10);
  printf("\nCh? s? l?n nh?t trong %d l�: %d",temp, max);
 
  printf("\n-----------------------------------\n");
  printf("Ch��ng tr?nh n�y ��?c ��ng t?i Freetuts.net");
}'
