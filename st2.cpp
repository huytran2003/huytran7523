#include<iostream>
#include<string.h>
using namespace std;

int main()
{

	struct NgayThang
	{
		int Ngay;
		int Thang;
		int Nam;
		
	}QTLD={1,5,2022};
//	struct SinhVien
//	{
//		char HoTen[30];
//		NgayThang NS;
//		int GT;
//		float Diem;
//		
//	}x,*p,K41T[60];
//	SinhVien y={"NVA",{1,1,1980},1};
//	y.Diem=5.5;
//	p=new SinhVien;
//	strcpy(p->HoTen,y.HoTen);
//	cout<<p->HoTen<<y.HoTen<<endl;
//	strcpy(K41T[1].HoTen,p->HoTen);
//	K41T[1].Diem=7.0;
//	cout<<K41T[1].Diem;
//	x.NS.Ngay=y.NS.Ngay;
//	x.NS.Thang=y.NS.Thang;
//	x.NS.Nam=y.NS.Nam;
	struct SinhVien
	{
		char HoTen[30];
		NgayThang NS;
		int GT;
		float Diem;	
	}x,y;
	cout<<"Nhap du lieu cho sinh vien x:"<<endl;
	cin.getline(x.HoTen,30);
	cin>>x.NS.Ngay>>x.NS.Thang>>x.NS.Nam;
	cin>>x.GT;
	cin>>x.Diem;
	cout<<"Thong tin SV x la: "<<endl;
	cout<<"Ho va ten: "<<x.HoTen<<endl;
	cout<<"Sinh ngay :"<<x.NS.Ngay<<"/"<<x.NS.Thang<<"/"<<x.NS.Nam<<endl;
	cout<<"Gioi tinh: "<<((x.GT==1)?"Nam":"Nu");
	cout<<"\nDiem: "<<x.Diem;
//	struct Lop
//	{
//		char TenLop
//		int SiSo;
//		
//	};
//	Lop DaiHoc={"K41T",CaoDang};
//	strcpy(CaoDang.TenLop=DaiHoc.TenLop);
//	CaoDang.SiSo++;
	
}
