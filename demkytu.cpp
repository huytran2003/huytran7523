#include<iostream>
using namespace std;

int main(){
	 char s[100];
	int count =0;
	cin>>s;
    while (s[count] != '\0')
        count++;
    cout << "So luong ki tu: " << count << endl;
    
    return 0;
}

