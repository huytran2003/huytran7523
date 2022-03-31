#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

//khai bao sinhvien structure
typedef struct sinhvien
{

string mssv;
char tensv[20];
char sex;
float diemkt1;
float diemkt2;
float diemcc;
float diemgk;
float diemck;
float tongdiem;
int soItem;
};
//cac nguyen mau ham (function prototype)
int search(struct sinhvien st[],string id, int biendem);
void clean(struct sinhvien st[],int deleteitem);

//ham de hien thi menu tuy chon
void displaymenu(){
cout<<"=========================================="<<"\n";
cout<<" MENU "<<"\n";
cout<<"=========================================="<<"\n";
cout<<" 1. Them ban ghi sinh vien"<<"\n";
cout<<" 2. Xoa ban ghi sinh vien"<<"\n";
cout<<" 3. Cap nhat ban ghi sinh vien"<<"\n";
cout<<" 4. Quan sat tat ca ban ghi sinh vien"<<"\n";
cout<<" 5. Tinh diem trung binh cua sinh vien da chon"<<"\n";
cout<<" 6. Hien thi sinh vien co tong diem cao nhat"<<"\n";
cout<<" 7. Hien thi sinh vien co tong diem thap nhat"<<"\n"; 
cout<<" 8. Tim sinh vien boi ID"<<"\n"; 
cout<<" 9. Sap xep cac ban ghi boi tong diem"<<"\n"; 
}
//ham de them cac ban ghi
void them_banghi(struct sinhvien st[],int& biendem){

again:
cout<<"\nNhap ID cua sinh vien: ";
cin>>st[biendem].mssv;
if(search(st,st[biendem].mssv,biendem)!=-1){
cout<<"ID nay da ton tai\n";goto again;
}

cout<<"Nhap ten sinh vien: "; 
cin>>st[biendem].tensv;
cout<<"Nhap gioi tinh cua sinh vien (F hoac M): ";cin>>st[biendem].sex;
cout<<"Nhap diem kiem tra 1: ";cin>>st[biendem].diemkt1;
cout<<"Nhap diem kiem tra 2: ";cin>>st[biendem].diemkt2;
cout<<"Nhap diem chuyen can: ";cin>>st[biendem].diemcc;
cout<<"Nhap diem giua ky: ";cin>>st[biendem].diemgk;
cout<<"Nhap diem cuoi ky: ";cin>>st[biendem].diemck;
st[biendem].tongdiem=st[biendem].diemkt1+st[biendem].diemkt2+st[biendem].diemcc+st[biendem].diemgk+st[biendem].diemck;

++biendem;


}

//ham de tim vi tri ban ghi
int search(struct sinhvien st[], string id,int biendem){
int found =-1;
for (int i = 0; i < biendem && found==-1; i++)
{

if (st[i].mssv == id) found=i;

else found=-1 ;
}

return found;
}



//ham de quan sat tat ca ban ghi
void viewall(struct sinhvien st[], int biendem){
int i=0;
cout<<left<<setw(5)<<"ID"<<setw(20)<<"TEN"<<setw(5)<<"GIOI TINH"
<<setw(5)<<"DKT1"
<<setw(5)<<"DKT2"<<setw(5)<<"DCC"<<setw(5)<<"DGK"<<setw(5)<<"DCK"
<<setw(5)<<"TONG"<<"\n";
cout<<"==============================================\n";
while(i<=biendem){
if(st[i].mssv!=""){
cout<<left<<setw(5)<<st[i].mssv<<setw(20)<<st[i].tensv<<setw(5)
<<st[i].sex;
cout<<setw(5)<<st[i].diemkt1<<setw(5)<<st[i].diemkt2<<setw(5)<<st[i].diemcc
<<setw(5)<<st[i].diemgk<<setw(5)<<st[i]. diemck<<setw(5)
<<st[i].tongdiem;

cout<<"\n";}
i=i+1;

}


}

//ham de xoa ban ghi 
void xoa_banghi(struct sinhvien st[], int& biendem){
string id;
int index;
if (biendem > 0)
{
cout<<"Nhap ID cua sinh vien: ";
cin>>id;
index = search(st, id,biendem); 

if ((index!=-1) && (biendem != 0))
{
if (index == (biendem-1)) //Xoa ban ghi cuoi cung
{

clean(st, index);
--biendem;

cout<<"Ban ghi da duoc xoa.\n";
}
else //xoa ban ghi dau tien hoac o giua
{
for (int i = index; i < biendem-1; i++)
{
st[i] = st[i + 1];
clean(st, biendem);
--biendem ;
}

}

}
else cout<<"Ban ghi khong ton tai. Kiem tra ID va thu lai.\n";


}
else cout<<"Khong co ban ghi nao duoc xoa\n";
}

//ham de xoa sach ban ghi da bi xoa
void clean(struct sinhvien st[],int index)
{
st[index].mssv ="";
strcpy(st[index].tensv,"");
st[index].sex =NULL;
st[index].diemkt1 = 0;
st[index].diemkt2 = 0;
st[index].diemcc = 0;
st[index].diemgk = 0;
st[index].diemck = 0;
st[index].tongdiem = 0;

}


//ham de cap nhat ban ghi
void capnhat_banghi(struct sinhvien st[],int biendem){
string id;
int column_index;
cout<<"Nhap ID cua sinh vien: ";
cin>>id;
cout<<"Ban muon cap nhat truong nao (1-7) ?: ";
cin>>column_index;

int index = search(st, id,biendem);

if (index != -1)
{
if (column_index == 1)
{
cout<<"Nhap ten sinh vien: ";

cin>>st[index].tensv;
}

else if (column_index == 2)
{
cout<<"Nhap gioi tinh sinh vien (F hoac M): ";
cin>>st[index].sex;
}
else if (column_index == 3)
{
cout<<"Nhap diem kiem tra 1: ";
cin>>st[index].diemkt1;
}
else if (column_index == 4)
{
cout<<"Nhap diem kiem tra 2: ";
cin>>st[index].diemkt2;
}
else if (column_index == 5)
{
cout<<"Nhap diem chuyen can: ";
cin>>st[index].diemcc;
}
else if (column_index == 6)
{
cout<<"Nhap diem thi giua ky: ";
cin>>st[index].diemgk;
}
else if (column_index == 7)
{
cout<<"Nhap diem thi cuoi ky: ";
cin>>st[index].diemck;
}
else cout<<"Gia tri chi muc khong hop le";

st[index].tongdiem = st[index].diemkt1 + st[index].diemkt2 + st[index].diemcc
+ st[index].diemgk + st[index].diemck;


}
else cout<<"Ban ghi khong ton tai. Kiem tra ID va thu lai.";


}

//Ham de hien thi tong diem lon nhat 
void showmax(struct sinhvien st[], int biendem)
{
float max = st[0].tongdiem;
int index=0;
if (biendem >= 2)
{

for (int j = 0; j < biendem-1; ++j)
if (max < st[j+1].tongdiem) {
max = st[j+1].tongdiem;
index = j+1;

}


}

else if (biendem == 1)
{
index = 0;
max = st[0].tongdiem;
}


else cout<<"Khong tim thay ban ghi nao!\n";

if (index != -1) cout<<"Sinh vien co ID la "<<st[index].mssv
<<" dat tong diem cao nhat la "<<max<<endl;


}

//ham de hien thi tong diem nho nhat
void showmin(struct sinhvien st[], int biendem)
{

float min = st[0].tongdiem;
int index = 0;
if (biendem >= 2)
{
for (int j = 0; j < biendem-1; ++j)
if (min > st[j+1].tongdiem)
{
min = st[j+1].tongdiem;
index = j+1;

}

}

else if (biendem == 1)
{
index = 0;
min = st[0].tongdiem;
}
else cout<<"Khong tim thay ban ghi nao!\n";

if (index != -1) cout<<"Sinh vien co ID la "<<st[index].mssv
<<" co tong diem thap nhat la "<<min<<endl;

}

//ham de tim ban ghi
void find(struct sinhvien st[], int biendem)
{
string id;
cout<<"Nhap ID cua sinh vien: ";
cin>>id;

int index=search(st,id,biendem);
if (index != -1) 
{ //hien thi ban ghi da tim thay
cout<<left<<setw(5)<<st[index].mssv<<setw(20)<<st[index].tensv<<setw(5)<<st[index].sex;
cout<<setw(5)<<st[index].diemkt1<<setw(5)<<st[index].diemkt2<<setw(5)
<<st[index].diemcc
<<setw(5)<<st[index].diemgk<<setw(5)<<st[index].diemck<<setw(5)
<<st[index].tongdiem;
cout<<"\n"; 

}
else cout<<"Ban ghi khong ton tai.";

}


//ham de sap xep cac ban ghi theo tong diem
void bubblesort(struct sinhvien dataset[], int n)
{
int i, j;
for (i = 0; i < n; i++)
for (j = n - 1; j > i; j--)
if (dataset[j].tongdiem < dataset[j - 1].tongdiem )
{
sinhvien temp = dataset[j];
dataset[j] = dataset[j - 1];
dataset[j - 1] = temp;
}

}

//ham de tinh diem trung binh cua mot sinh vien
void average(struct sinhvien st[], int biendem)
{
string id;
float avg=0;
cout<<"Nhap ID cua sinh vien: ";
cin>>id;
int index = search(st, id,biendem);
if (index != -1 && biendem>0)
{
st[index].tongdiem = st[index].diemkt1 + st[index].diemkt2 + st[index].diemcc
+ st[index].diemgk + st[index].diemck;
avg = st[index].tongdiem /5;
}

cout<<"Diem trung binh la "<<avg;
}

//ham main 

int main(int argc, char *argv[])
{


sinhvien st[80];
int biendem=0;

//hien thi menu
displaymenu();
int luachon;
char confirm;
do
{
cout<<"\nNhap lua chon cua ban (1-9): ";
cin>>luachon;

switch(luachon){
case 1:them_banghi(st, biendem);break;
case 2:xoa_banghi(st, biendem);break;
case 3:capnhat_banghi(st, biendem);break;
case 4:viewall(st, biendem);break;
case 5:average(st, biendem);break;
case 6:showmax(st, biendem);break;
case 7:showmin(st, biendem);break;
case 8:find(st, biendem);break;
case 9:bubblesort(st,biendem);break;
default:cout<<"Khong hop le";

}

cout<<"Nhan y hoac Y de tiep tuc: ";
cin>>confirm;
}while(confirm=='y'||confirm=='Y');

return 0;
}
