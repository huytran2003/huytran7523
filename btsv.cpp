#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
struct NgayThang{
    int Ngay;
    int Thang;
    int Nam;
};
struct SinhVien{
    string HoTen;
    NgayThang NS;
    int GT;
    float Diem;
};
void menu(){
    cout<<"\n===============SINH VIEN==============="<<endl;
    cout<<"Nhan 1: Nhap danh sach sinh vien"<<endl;
    cout<<"Nhan 2: Xuat danh sach sinh vien"<<endl;
    cout<<"Nhan 3: Sap xep theo ho tang"<<endl;
    cout<<"Nhan 4: Sap xep theo ho giam"<<endl;
	cout<<"Nhan 5: Sap xep theo diem tang"<<endl;
	cout<<"Nhan 6: Sap xep theo diem giam"<<endl;
    cout<<"Nhan 7: Tim kiem sinh vien co diem cao nhat"<<endl;
    cout<<"Nhan 8: Tim kiem sinh vien co diem thap nhat"<<endl;
    cout<<"Nhan 9: Tinh trung binh diem Nam"<<endl;
    cout<<"Nhan 10: Tinh trung binh diem Nu"<<endl;
	cout<<"Moi ban nhap lua chon : ";
}
int luachon(){
    int LC;
    menu();
    cin>>LC;
    return LC;
}
bool KiemTra(SinhVien DS[], int n,string Ten){
	bool kt=true;
	for(int i=0;i<n;i++)
	{
		if(DS[i].HoTen==Ten)
		{
			kt=false;
			break;
		}
	}
		return kt;
}

void Nhap(SinhVien DS[], int n){
    cout<<"Nhap vao danh sach sinh vien thu "<<n+1<<": "<<endl;
    bool kt=true;
    do{
        string Ten;
        fflush(stdin);
        cout<<"Nhap ho ten: ";
        getline(cin, Ten);
        kt=KiemTra(DS,n,Ten);
        if(kt==true){
            DS[n].HoTen=Ten;
        }else{
            cout<<"Sinh vien da co trong danh sach, nhap lai!\n";
        }
    }while(kt!=true);
    cout<<"Ngay sinh: ";cin>>DS[n].NS.Ngay>>DS[n].NS.Thang>>DS[n].NS.Nam;
    
	do{
		cout<<"Gioi tinh(1 la nam, 0 la nu): ";
		cin>>DS[n].GT;	
		if(DS[n].GT!=0 &&DS[n].GT!=1)
			cout<<"Nhap sai,Vui long nhap lai:"<<endl;
	}while(DS[n].GT!=0 &&DS[n].GT!=1);
	do{
		cout<<"Diem: ";cin>>DS[n].Diem;
		if(DS[n].Diem<0||DS[n].Diem>10)
			cout<<"Nhap lai: "<<endl;
	}while(DS[n].Diem<0||DS[n].Diem>10);
}
void Xuat(SinhVien DS[], int n){
    system("cls");
    cout<<setw(10)<<left<<"STT"<<setw(20)<<left<<"Ho va Ten"<<setw(20)<<right<<"Ngay sinh"<<setw(15)<<right<<"Gioi tinh"<<setw(20)<<right<<"Diem TB"<<endl;
    cout<<setfill('-');
    cout<<setw(80)<<"-"<<endl;
    cout<<setfill(' ');
    for (int i=0; i<n; i++){
    	string st=(DS[i].GT==1?"Nam":"Nu");
        cout<<setw(10)<<left<<i+1<<setw(20)<<left<<DS[i].HoTen<<setw(12)<<right<<DS[i].NS.Ngay<<"/"<<DS[i].NS.Thang<<"/"<<DS[i].NS.Nam<<setw(10)<<right<<st<<setw(20)<<right<<DS[i].Diem<<endl;
    }
}
void SapXepTang1(SinhVien DS[],int n)
{
	SinhVien temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(DS[i].HoTen>DS[j].HoTen)
			{
				temp=DS[i];
				DS[i]=DS[j];
				DS[j]=temp; 
			}
		}
	}
}
void SapXepGiam1(SinhVien DS[],int n)
{
	SinhVien temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(DS[i].HoTen<DS[j].HoTen)
			{
				temp=DS[i];
				DS[i]=DS[j];
				DS[j]=temp; 
			}
		}
	}
	
}
void SapXepGiam2(SinhVien DS[],int n)
{
	SinhVien temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(DS[i].Diem<DS[j].Diem)
			{
			temp=DS[i];
			DS[i]=DS[j];
			DS[j]=temp; 
			}
		}
	}
	
}

void SapXepTang2(SinhVien DS[],int n)
{
	SinhVien temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(DS[i].Diem>DS[j].Diem)
			{
			temp=DS[i];
			DS[i]=DS[j];
			DS[j]=temp; 
			}
		}
	}
	
}

int TimKiem1(SinhVien DS[], int n )
{
	float max=DS[0].Diem;
	for(int i=0;i<n;i++){
		if(max<DS[i].Diem)
		   max=DS[i].Diem;
	}
cout<<"Cac sinh vien co diem cao nhat la: "<<endl;
	for(int i =0;i<n;i++){
		if(DS[i].Diem==max)
			cout<<DS[i].HoTen<<" "<<DS[i].Diem <<" diem"<<endl;
		}
		cout<<"\n";
}
int TimKiem2(SinhVien DS[], int n )
{
	float min=DS[0].Diem;
	for(int i=0;i<n;i++){
		if(min>DS[i].Diem)
		   min=DS[i].Diem;
	}
cout<<"Cac sinh vien co diem thap nhat la: "<<endl;
	for(int i =0;i<n;i++){
		if(DS[i].Diem==min)
			cout<<DS[i].HoTen<<" "<<DS[i].Diem<<" diem"<<endl;
		}
		cout<<"\n";
}		
void TrungBinhNam(SinhVien DS[],int n)
{
	float tong=0;
	int dem=0;
	for(int i=0;i<n;i++){
		if(DS[i].GT==1){
			tong+=DS[i].Diem;
			dem++;
		}
	}
	cout<<"Diem trung binh cua nam la: "<<tong/dem;
}
void TrungBinhNu(SinhVien DS[],int n)
{
	{
	float s =0;
	int count=0;
	for(int i=0;i<n;i++){
		if(DS[i].GT==0){
			s+=DS[i].Diem;
			count++;
		}
	}
	cout<<"Diem trung binh cua nu la: "<<s/count;
}
}
int main(){
    int LC,n;
    SinhVien DS[100];
    do{
        LC=luachon();
        switch(LC){
            case 1: Nhap(DS,n);
            n++;
            break;
            case 2: Xuat(DS,n);
            break;
            case 3: SapXepTang1(DS,n);
            break;
            case 4: SapXepGiam1(DS,n);
            break;
            case 5: SapXepTang2(DS,n);
            break;
            case 6: SapXepGiam2(DS,n);
            break;
            case 7:TimKiem1(DS,n);
            break;
            case 8: TimKiem2(DS,n);
            break;
            case 9:TrungBinhNam(DS,n);
            break;
            case 10:TrungBinhNu(DS,n);
            break;
        }
    }while(LC!=0);
}
