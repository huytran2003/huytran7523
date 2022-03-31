#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int a[n];
    long long s[n];
    long long ans = 0;
    for(int i = 0; i<n; ++i)
        cin >> a[i];
    s[0] = a[0];
    for(int i = 1; i<n; ++i)
        s[i] = s[i-1]+a[i];
    for(int i = 0; i<n-1; ++i)
        ans+=a[i]*(s[n-1]-s[i]);
    cout << ans;
    return 0;
}
