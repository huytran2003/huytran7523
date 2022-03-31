#include <bits/stdc++.h>
#include <stdlib.h>
#include <math.h>
	using namespace std;
int main(int argc, char *argv[]) {
	int n, x, dem = 0;
	cin >> n;
	cin >> x;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i< n; i++) {
		if(x > a[i]){
			dem++;
		}
	}cout << dem;
	return 0;
}
