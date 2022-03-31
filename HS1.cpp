#include<iostream>
#include<string>
using namespace std;
bool kiemtra(string DS[], int n, string ten) {
	bool kt=true;
	for (int i = 0; i < n; i++)
	{
		if (DS[i]==ten){
		kt=false;
		break;
	}
	}
	return kt;
}
int nhapds(string DS[], int n) {
	bool kt=true;
	do
	{
	string ten;
	cout << "Nhap ten hoc sinh " << n + 1 <<":";
	fflush(stdin);
	getline(cin, ten);
	kt=kiemtra(DS,n,ten);
	if ( kt==true)
		DS[n]=ten;
	else
			cout << "ten da co trong ds"<<endl;
    }
    while(kt==false);
}
void xapxepds(string DS[], int n) 
{
	
}
void timkiem(string DS[], int n) 
{
		
}
void innhieutu(string DS[], int n)
{
	
}
void chends(string DS[], int n) 
{

}
void xoa(string DS[], int n) 
{

}
void xuatds(string DS[], int n) {
	for (int i = 0; i <= n; i++) {
		cout << "hoc sinh thu " << i + 1 << " " << DS[i] << endl;
	}
}

int main() {
	int luachon;
	string DS[100];
	int n = 0;
	string ten;
	do {
		cout << "------CHUONG TRINH QUAN LY HOC SINH------" << endl;
		cout << "       -------------------------        " << endl;
		cout << "          LUA CHON THAO TAC: " << endl;
		cout << "Nhan 1: nhap ho ten hoc sinh." << endl;
		cout << "Nhan 2: sap xep hoc sinh tang dan." << endl;
		cout << "Nhan 3: tim kiem hoc sinh trong danh sach." << endl;
		cout << "Nhan 4: in ra hoc sinh nhieu tu." << endl;
		cout << "Nhan 5: them moi hoc sinh vao danh sach." << endl;
		cout << "Nhan 6: xoa mot hoc sinh ra khoi danh sach." << endl;
		cout << "Nhan 7: hien thi danh sach hoc sinh." << endl;
		cout << "Nhan 0: thoat khoi chuong trinh." << endl;
		cout << "Lua chon thao tac:";
		cin >> luachon;
		switch (luachon) {
		case 1: nhapds(DS, n);
			n++;
			break;
		case 2:
			cout << "nhap ten: ";
			fflush(stdin);
			getline(cin, ten);
			if (kiemtra(DS, n, ten))
				cout << "ten chua co trong ds";
			else
				cout << "ten da co trong ds";
			cout << endl;
			break;
		case 3: timkiem(DS, n);
			break;
		case 4: innhieutu(DS, n);
			break;
		case 5: chends(DS, n);
			break;
		case 6: xoa(DS, n);
			break;
		case 7: xuatds(DS, n);
			break;
		}
	} while (luachon);
}
