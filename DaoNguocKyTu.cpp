#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[100];
    cout<<"Nhap ky tu: ";
    cin>>s;
    strrev(s);
    cout<<"Ky tu dao nguoc la: "<<s;
    return 0;
}

