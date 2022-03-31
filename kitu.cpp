#include<bits/stdc++.h>
using namespace std;

int main() 
{
	string s;
	while(getline(cin,s)){
		while(s[0]==' '){
			s.erase(s.begin()+0);
		}
		while(s[s.size()-1]==' '){
			s.erase(s.begin()+s.size()-1);
		}
		for(int i=0;i<s.size();i++){
			while(s[i]==' '&&s[i+1]==' '){
				s.erase(s.begin()+i+1);
			}
		}
		for(int i=0;i<s.size();i++){
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}

