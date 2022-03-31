#include <stdio.h>
int main () {
int  m;
float tbc=0;
scanf ("%d",&m);
float a[m];
for (int i=0;i<m;i++)
 {
  scanf ("%f",&a[i]);
 }
 for (int i=0;i<m;i++)
 {
  tbc=tbc+a[i];
  }
  printf ("%0.4f",tbc/m);
return 0;
}
