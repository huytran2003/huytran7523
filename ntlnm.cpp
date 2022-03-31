#include<iostream>
#include<math.h>
using namespace std;
const long MIN = -1000000000;
void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
bool checkNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if(n%i==0)
            return false;
    return true;
}
int Fun(int a[], int n) {
    long max = MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > max && checkNT(a[i]) )
            max = a[i];
    }
    if( max == MIN )
        return 0;
    else
        return max;
}
int main() {
    int a[100];
    int n;
    cin >> n;
    NhapMang(a, n);
    cout  << Fun(a, n);
    return 0;
}
 
