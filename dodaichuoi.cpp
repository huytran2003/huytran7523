#include <iostream>
#include<string.h>
using namespace std;
  
int main()
{
   string s1[100];
   cin>>s1;
   getline(cin,s1);
   int i = 0;
   while(s1[i] != '\0') 
   {
      i++;
   }    
   cout << "Do dai cua chuoi " << s1 << " la: " << i << endl;
}
  
