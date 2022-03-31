#include <iostream>
#include <string>

using namespace std;

struct PhanSo {

	int TuSo;
	int MauSo;
};

void NhapPhanSo(PhanSo &ps) {

	cout << "\n Nhap tu so: ";
	cin >> ps.TuSo;
do{
	cout << " Nhap mau so: ";
	cin >> ps.MauSo;
	if(ps.MauSo==0)
		cout<<"\nMau phai khac o\nVui long nhap lai:";
}while(ps.MauSo==0);

//void HoanVi(int &so1, int &so2) {
//
//	int temp = so1;
//	so1 = so2;
//	so2 = temp;
//}
//
int TimUSCLN(int so1, int so2) {

	int res = 0;

	if (so1 == 0 || so2 == 0) {

		res = so1 + so2;
	}
	else {

		while (so1 != so2) {

			if (so1 > so2) {

				so1 -= so2;
			}
			else {

				so2 -= so1;
			}
		}

		res = so1;
	}

	return res;
}

//int TimBSCNN(int so1, int so2) {
//
//	return (so1 * so2) / TimUSCLN(so1, so2);
//}

void RutGonPhanSo(PhanSo &ps) {

	int UocSo = TimUSCLN(ps.TuSo, ps.MauSo);
	ps.TuSo /= UocSo;
	ps.MauSo /= UocSo;
}

PhanSo CongHaiPhanSo(PhanSo ps1, PhanSo ps2) {

	if (ps1.MauSo == 0 || ps2.MauSo == 0) {

		return{ -1, -1 };
	}

	if (ps1.MauSo < 0) {

		ps1.TuSo = -ps1.TuSo;
		ps1.MauSo = -ps1.MauSo;
	}

	if (ps2.MauSo < 0) {

		ps2.TuSo = -ps2.TuSo;
		ps2.MauSo = -ps2.MauSo;
	}

	int BoiSo = TimBSCNN(ps1.MauSo, ps2.MauSo);
	return{ ps1.TuSo * (BoiSo / ps1.MauSo) + ps2.TuSo * (BoiSo / ps2.MauSo), BoiSo };
}

PhanSo TruHaiPhanSo(PhanSo ps1, PhanSo ps2) {

	if (ps1.MauSo == 0 || ps2.MauSo == 0) {

		return{ -1, -1 };
	}

	if (ps1.MauSo < 0) {

		ps1.TuSo = -ps1.TuSo;
		ps1.MauSo = -ps1.MauSo;
	}

	if (ps2.MauSo < 0) {

		ps2.TuSo = -ps2.TuSo;
		ps2.MauSo = -ps2.MauSo;
	}

	int BoiSo = TimBSCNN(ps1.MauSo, ps2.MauSo);
	return{ ps1.TuSo * (BoiSo / ps1.MauSo) - ps2.TuSo * (BoiSo / ps2.MauSo), BoiSo };
}

PhanSo NhanHaiPhanSo(PhanSo ps1, PhanSo ps2) {

	if (ps1.MauSo == 0 || ps2.MauSo == 0) {

		return{ -1, -1 };
	}

	return{ ps1.TuSo * ps2.TuSo, ps1.MauSo * ps2.MauSo };
}

PhanSo ChiaHaiPhanSo(PhanSo ps1, PhanSo ps2) {

	if (ps1.MauSo == 0 || ps2.MauSo == 0) {

		return{ -1, -1 };
	}

	HoanVi(ps2.TuSo, ps2.MauSo);

	if (ps2.MauSo == 0) {

		return{ -1, -1 };
	}

	return{ ps1.TuSo * ps2.TuSo, ps1.MauSo * ps2.MauSo };
}

void InPhanSo(PhanSo ps) {

	cout << ps.TuSo << "/" << ps.MauSo << endl;
}

int main() {

	PhanSo ps1;
	PhanSo ps2;

	NhapPhanSo(ps1);
	NhapPhanSo(ps2);

	RutGonPhanSo(ps1);
	RutGonPhanSo(ps2);

	cout << "\n----------------------------------------" << endl;
	cout << "Chon ('+') thi cong hai phan so" << endl;
	cout << "Chon ('-') thi tru hai phan so" << endl;
	cout << "Chon ('*') thi nhan hai phan so" << endl;
	cout << "Chon ('/') thi chia hai phan so" << endl;
	cout << "----------------------------------------" << endl;

	char PhepToan;
	cout << "\n Nhap vao su lua chon (+, -, *, /): ";
	cin >> PhepToan;

	cout << " Ket qua phep " << PhepToan << " hai phan so la " << ": ";

	switch (PhepToan) {

	case '+':
	{
		RutGonPhanSo(CongHaiPhanSo(ps1, ps2));
		InPhanSo(CongHaiPhanSo(ps1, ps2));
		break;
	}

	case '-':
	{
		RutGonPhanSo(TruHaiPhanSo(ps1, ps2));
		InPhanSo(TruHaiPhanSo(ps1, ps2));
		break;
	}

	case '*':
	{
		RutGonPhanSo(NhanHaiPhanSo(ps1, ps2));
		InPhanSo(NhanHaiPhanSo(ps1, ps2));
		break;
	}

	case '/':
	{
		RutGonPhanSo(ChiaHaiPhanSo(ps1, ps2));
		InPhanSo(ChiaHaiPhanSo(ps1, ps2));
		break;
	}

	default:
	{
		cout << "\n Ban nhap sai phep toan, xin moi nhap lai !" << endl;
	}
	}

	system("pause");
	return 0;
}
