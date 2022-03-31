#include<iostream>
using namespace std;
double tong(double n){
	if(n==1) return n;
	else return (1/n+ tong(n-1)); 
} 

int main(){
    double n;
	cin>>n;
	cout<<tong(n); 
    return 0;

}

