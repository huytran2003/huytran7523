#include<stdio.h>
int main()
{
  int i, n, temp;
  int max = 0;
  //s? d?ng v?ng l?p do..while ð? yêu c?u ngý?i dùng nh?p vào s? nguyen dýõng n
  //n?u n < 0 th? yêu c?u nh?p l?i
  do
  {
    printf("\nNh?p vào s? nguyên dýõng n: ");
    scanf("%d", &n);
  }while(n < 0 && printf("\nS? n ph?i l?n hõn ho?c b?ng 0!!"));
  temp = n;
  //n?u n = 0 th? max = 0
  if(n == 0)
    max = 0;
  //s? d?ng v?ng l?p do..while ð? t?m ch? s? l?n nh?t trong n
  do
  {
    i = n % 10;
    if(i > max)
    {
      max = i;
    }
  }while(n /= 10);
  printf("\nCh? s? l?n nh?t trong %d là: %d",temp, max);
 
  printf("\n-----------------------------------\n");
  printf("Chýõng tr?nh này ðý?c ðãng t?i Freetuts.net");
}'
