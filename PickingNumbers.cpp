#include<iostream>
using namespace std;
int main(){ 
    int b[100]={0}; 
	
	int n;
	cin >> n;
	 
	int x;
	for(int i = 0; i < n; ++i)
	{
		cin>> x;
		b[x]++;
	}
	
	int max=0; 
	for(int i = 1;i < 99; ++i){
	    if(b[i] + b[i+1] > max)
		max = b[i] + b[i+1]; 
	}
	cout << max; 
	 return 0; 
}  
