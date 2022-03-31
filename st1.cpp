#include<iostream>
#include<string>
using namespace std;

//struct People1
//{
//	int old;
//	char *name;
//	int height;
//	char *sex;
//}PS1, PS2;
//struct NgayThang
//{
//	int Ngay;
//	int Thang;
//	int Nam;
//}QTLD={1,5,2022}
//struct PhanSo
//{
//	int TuSo;
//	int MauSo;
//};
//struct Lop
//{
//	char TenLop[20];
//	int SoLuong;
//	
//};
//LopDaiHoc={"K45CNTT",60}
//struct SinhVien
//{
//	char HoTen[30];
//	NgayThang NS;
//	int GT;
//	float Diem;
//};x,*p,K41T[60];

int main(){
	struct Lop
{
	char TenLop[20];
	int SiSo;
};
Lop DaiHoc ={"K41T","CaoDang"};
strcpy(CaoDang,DaiHoc);
CaoDang.SiSo++;
    return 0;
}

