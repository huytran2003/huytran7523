#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007
int main(){
    ll n,s=1;
    cin>>n;
    for(int i = 1; i <= n; i++){
    	s=(ll)(s*2)%(m);
    }
    cout<<s;
}
