#include<iostream>


using namespace std;

int main(){
	int n;
	cin>>n;
	while(n%2 == 0){
		n=n/2;
	}
	while(n%3 == 0){
		n=n/3;
	}
	while(n%5 == 0){
		n=n/5;
	}
	
	if(n == 1)
		cout<<"YES";
	else	
		cout<<"NO";
	return 0;
}