#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inv_4 = 250000002;
const ll m = 1e9+7;
ll mul_mod(ll a, ll b){
    return ((a%m)*(b%m))%m;
}
int main(){
    ll n;
    cin >> n;
    cout << mul_mod(mul_mod(n,n+1),mul_mod(mul_mod(n+2,n+3),inv_4));
}