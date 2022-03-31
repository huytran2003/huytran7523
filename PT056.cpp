#include <iostream>

using namespace std;
long long A(long long x)
{
    if(x==1) return 1;
    if(x%2==0) return x+A(x-1);
    else return 2*x+A(x-1);
}
int main()
{
    long long n;
    cin >> n;
    cout << A(n);
    return 0;
}

