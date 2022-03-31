#include<bits/stdc++.h>
using namespace std;

struct PhanSo {
    int TuSo;
    int MauSo;
} PS[100];

int UCLN(int a, int b){
	a=abs(a);
	b=abs(b);
	if(a==0||b==0)
		return a+b;
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
void RutGon(PhanSo &PS){
	int c=UCLN(PS.TuSo,PS.MauSo);
	PS.TuSo=PS.TuSo/c;
	PS.MauSo=PS.MauSo/c;
}

void NhapPhanSo(int n) {
    cout << "Nhap phan so thu "<< n+1 << ": " << endl;
    cout << "Nhap tu so: ";
    cin >> PS[n].TuSo;
    do{
    cout << "Nhap mau so: ";
    cin >> PS[n].MauSo;
    if(PS[n].MauSo==0)
		cout<<"\nMau phai khac 0"<<endl<<"Vui long nhap lai:";
    }while(PS[n].MauSo==0);
    if(PS[n].MauSo<0)
    {
    	PS[n].TuSo*=-1;
    	PS[n].MauSo*=-1;
	}
    
}
void XuatPhanSo(int n) {
    for (int i=0;i<n;i++)
    {
    	if(PS[i].MauSo==1)
    		cout << "Phan so thu "<< i+1<< " : " <<PS[i].TuSo<<endl;
    	else
        	cout << "Phan so thu "<< i+1 << ": " << PS[i].TuSo << "/" << PS[i].MauSo << endl;
    }
}

void ViTri(int &a, int &b) {
    cout << "Nhap vao 2 vi tri phan so can tinh: ";
    cin >> a >> b;
}

void TongPS(int n, int a, int b) {
    PhanSo PS1, PS2, PS3;
    for (int i=0;i<n;i++) {
        if (i==a-1) {
            PS1.TuSo=PS[i].TuSo;
            PS1.MauSo=PS[i].MauSo;
        }
        if (i==b-1) {
            PS2.TuSo=PS[i].TuSo;
            PS2.MauSo=PS[i].MauSo;
        }
    }
    PS3.TuSo=PS1.TuSo*PS2.MauSo+PS2.TuSo*PS1.MauSo;
    PS3.MauSo=PS1.MauSo*PS2.MauSo;
    RutGon(PS3);
    cout << "Tong 2 phan so: "<< " " << PS3.TuSo << "/" << PS3.MauSo << endl;
}

void HieuPS(int n, int a, int b) {
    PhanSo PS1, PS2, PS3;
    for (int i=0;i<n;i++) {
        if (i==a-1) {
            PS1.TuSo=PS[i].TuSo;
            PS1.MauSo=PS[i].MauSo;
        }
        if (i==b-1) {
            PS2.TuSo=PS[i].TuSo;
            PS2.MauSo=PS[i].MauSo;
        }
    }
    PS3.TuSo=PS1.TuSo*PS2.MauSo-PS2.TuSo*PS1.MauSo;
    PS3.MauSo=PS1.MauSo*PS2.MauSo;
    RutGon(PS3);
        cout << "Hieu 2 phan so do la: "<< PS3.TuSo << "/" << PS3.MauSo << endl;
    }

void TichPS(int n, int a, int b) {
    PhanSo PS1, PS2, PS3;
    for (int i=0;i<n;i++) {
        if (i == a - 1) {
            PS1.TuSo=PS[i].TuSo;
            PS1.MauSo=PS[i].MauSo;
        }
        if (i==b-1){
            PS2.TuSo=PS[i].TuSo;
            PS2.MauSo=PS[i].MauSo;
        }
    }
    PS3.TuSo=PS1.TuSo*PS2.TuSo;
    PS3.MauSo=PS1.MauSo*PS2.MauSo;
    RutGon(PS3);
    cout << "Tich 2 phan so do la: "<< PS3.TuSo << "/" << PS3.MauSo << endl;
}

void ThuongPS(int n, int a, int b) {
    PhanSo PS1, PS2, PS3;
    for (int i=0;i<n;i++) {
        if (i==a-1){
            PS1.TuSo=PS[i].TuSo;
            PS1.MauSo=PS[i].MauSo;
        }
        if (i == b - 1) {
            PS2.TuSo=PS[i].TuSo;
            PS2.MauSo=PS[i].MauSo;
        }
    }
    PS3.TuSo=PS1.TuSo*PS2.MauSo;
    PS3.MauSo=PS1.MauSo*PS2.TuSo;
    RutGon(PS3);
    cout << "Thuong 2 phan so:"<<PS3.TuSo<<"/"<<PS3.MauSo<<endl;
}

void Menu() {
    cout << "---------Chuong trinh thao tac voi phan so---------------" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "	Nhan 1: Nhap phan so." << endl;
    cout << "	Nhan 2: Xuat ra danh sach phan so da nhap." << endl;
    cout << "	Nhan 3: Tinh tong 2 phan so da nhap." << endl;
    cout << "	Nhan 4: Tinh hieu 2 phan so da nhap." << endl;
    cout << "	Nhan 5: Tinh tich 2 phan so da nhap." << endl;
    cout << "	Nhan 6: Tinh thuong 2 phan so da nhap." << endl;
    cout << "	Nhan 0: Thoat khoi chuong trinh." << endl;
    cout << "---------------------------------------------------------" << endl;
}

void LC() {
    Menu();
    int a, b;
    int n = 0;
    int LC;
    do {
        cout << "Lua chon thao tac: ";
        cin >> LC;
        switch (LC) {
	        case 1:
	            NhapPhanSo(n);
	            n++;
	            break;
	        case 2:
	            XuatPhanSo(n);
	            break;
	        case 3:
	            ViTri(a, b);
	            TongPS(n, a, b);
	            break;
	        case 4:
	            ViTri(a, b);
	            HieuPS(n, a, b);
	            break;
	        case 5:
	            ViTri(a, b);
	            TichPS(n, a, b);
	            break;
	        case 6:
	            ViTri(a, b);
	            ThuongPS(n, a, b);
	            break;
	        case 0: break;
	        default: cout << "Vui long nhap lai: "<<endl;
	    }
    } while (LC !=0);
}

int main(){
    LC();
    return 0;
}

