#include <iostream> 
using namespace std;
void lucasnum(int n) 
{ 
  int a = 2, b = 1, c, i; 
  for (i = 0; i < n; i++) 
  { 
      if (i == 0) 
    cout<<2<<" ";
            else if (i==1) 
    cout<<1<<" ";
    else
    {
        c = a + b; 
        a = b; 
        b = c; 
            cout<<c<<" ";
    }
  } 
} 
int main() 
{ 
    int n ; 
    cin>>n;
    lucasnum(n);                 //calling Lucas function
  return 0; 
} 
