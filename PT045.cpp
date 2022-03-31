#include <bits/stdc++.h>
using namespace std;
int scp(long long k){
    long long m,check;
    m=sqrt(k);
    if (m*m==k)
        check=0;
    else
        check=1;
    return check;
}
int main(){
    long long n,i,a[100],s;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        if (scp(a[i])==0){
            s=a[i];
            break;
        }
    for(i=1;i<=n;i++)
        if (scp(a[i])==0)
            if (a[i]<s)
                s=a[i];
    cout<<s;
}
