#include<stdio.h>
void nhapmang(int a[],int n){
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
}
}
int sochinhphuong(int n){
	for(int i=0; i<n;i++){
		if(i*i==n) return 0;
	}
	return 1;
}
void sapxeptang(int a[],int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n;j++){
			if(a[i]>a[j]){
				int dem=a[i];
				a[i]=a[j];
				a[j]=dem;
			}
		}
	}
}
void timmin(int a[],int n){
	for(int i=0; i<n;i++){
		if(sochinhphuong(a[i])==0){
			printf("%d",a[i]);
			break;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
}
