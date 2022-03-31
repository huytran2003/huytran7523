#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
struct Diem{
	int x,y;
}s[100],f,db,tg;
FILE *h;
int opt,opt2,opt3,opt4,i,j,k,diem,l,m,p,z,cap,v,d1,ptr,dc[5];
char a[10][18],t;
bool stop,ps,reset_cfg[3];
void textbackground(char x){
	char t[13];
	strcpy(t,"\u001b[");
	switch(x){
		case '0':strcat(t,"40");break;
		case '1':strcat(t,"44");break;
		case '2':strcat(t,"42");break;
		case '3':strcat(t,"46");break;
		case '4':strcat(t,"41");break;
		case '5':strcat(t,"45");break;
		case '6':strcat(t,"43");break;
		case '7':strcat(t,"47");break;
		case '8':strcat(t,"100");break;
		case '9':strcat(t,"104");break;
		case 'A':strcat(t,"102");break;
		case 'B':strcat(t,"106");break;
		case 'C':strcat(t,"101");break;
		case 'D':strcat(t,"105");break;
		case 'E':strcat(t,"103");break;
		case 'F':strcat(t,"107");break;
	}
	strcat(t,"m");
	printf("%s",t);
}
void textcolor(char x){
	char t[13];
	strcpy(t,"\u001b[");
	switch(x){
		case '0':strcat(t,"30");break;
		case '1':strcat(t,"34");break;
		case '2':strcat(t,"32");break;
		case '3':strcat(t,"36");break;
		case '4':strcat(t,"31");break;
		case '5':strcat(t,"35");break;
		case '6':strcat(t,"33");break;
		case '7':strcat(t,"37");break;
		case '8':strcat(t,"90");break;
		case '9':strcat(t,"94");break;
		case 'A':strcat(t,"92");break;
		case 'B':strcat(t,"96");break;
		case 'C':strcat(t,"91");break;
		case 'D':strcat(t,"95");break;
		case 'E':strcat(t,"93");break;
		case 'F':strcat(t,"97");break;
	}
	strcat(t,"m");
	printf("%s",t);
}
void delay(int ms){
	clock_t start_time=clock();
	while (clock()<start_time+ms);
}
void hoan_doi(int &a,int &b){
	int tg;
	tg=a;
	a=b;
	b=tg;
}
int empty_file(const char *x){
	h=fopen(x,"r");
	if (h!=NULL){
		fseek(h,0,SEEK_END);
		if (ftell(h)==0) return 1;
		else return 0;
		fclose(h);
	}
	return 0;
}
bool kt(){
	for (i=0;i<l;i++)
		if ((f.x==s[i].x)&&(f.y==s[i].y)){
			a[f.x][f.y]='*';
			return false;
		}
	return true;
}
bool kt2(){
	for (i=0;i<l;i++)
		if ((s[i].x==db.x)&&(s[i].y==db.y)){
			a[db.x][db.y]='*';
			return false;
		}
	return true;
}
bool kt22(){
	for (i=0;i<7;i++)
		for (j=0;j<15;j++)
			if ((strncmp(&a[i+1][j+1],"  ",2)==0)&&(strncmp(&a[i+2][j+1],"  ",2)==0)) return true;
	return false;
}
bool kt2A(){
	for (i=0;i<l;i++)
		if ((s[i].x==db.x)&&(s[i].y==db.y)){
			a[db.x][db.y]='*';
			return false;
		}
		else if ((s[i].x==db.x+1)&&(s[i].y==db.y)){
			a[db.x+1][db.y]='*';
			return false;
		}
		else if ((s[i].x==db.x)&&(s[i].y==db.y+1)){
			a[db.x][db.y+1]='*';
			return false;
		}
		else if ((s[i].x==db.x+1)&&(s[i].y==db.y+1)){
			a[db.x+1][db.y+1]='*';
			return false;
		}
	if ((a[db.x][db.y]=='+')||(a[db.x+1][db.y]=='+')||(a[db.x][db.y+1]=='+')||(a[db.x+1][db.y+1]=='+')) return false;
	return true;
}
bool kt3(){
	if (((f.x==db.x)&&(f.y==db.y))||((f.x==db.x+1)&&(f.y==db.y))||((f.x==db.x)&&(f.y==db.y+1))||((f.x==db.x+1)&&(f.y==db.y+1))) return true;
	else return false;
}
void on_preload(){
	h=fopen("cfg.ini","r");
	if (h==NULL){
		h=fopen("cfg.ini","w");
		fprintf(h,"%d %d %d",1,1,0);
		fclose(h);
	}
	h=fopen("save.ini","r");
	if (h==NULL){
		h=fopen("save.ini","w");
		fclose(h);
	}
	system("attrib -r cfg.ini");
	system("attrib -r save.ini");
	h=fopen("hi0.txt","r");
	if (h==NULL){
		h=fopen("hi0.txt","w");
		fclose(h);
	}
	h=fopen("hi1.txt","r");
	if (h==NULL){
		h=fopen("hi1.txt","w");
		fclose(h);
	}
	h=fopen("hi2.txt","r");
	if (h==NULL){
		h=fopen("hi2.txt","w");
		fclose(h);
	}
	opt=1;
	for (i=0;i<3;i++) reset_cfg[i]=false;
}
void on_load(){
	h=fopen("cfg.ini","r");
	fscanf(h,"%d %d %d",&cap,&m,&z);
	fclose(h);
}
void doc_trang_thai(const char *x){
	h=fopen(x,"r");
	fscanf(h,"%d %d %d",&cap,&m,&z);
	fscanf(h,"%d %d",&diem,&l);
	fscanf(h,"%d",&k);
	fscanf(h,"%d %d %d %d %d %d",&f.x,&f.y,&db.x,&db.y,&v,&d1);
	for (i=0;i<l;i++) fscanf(h,"%d %d",&s[i].x,&s[i].y);
	fclose(h);
}
void ghi_trang_thai(const char *x){
	h=fopen(x,"w");
	fprintf(h,"%d %d %d\n",cap,m,z);
	fprintf(h,"%d %d\n",diem,l);
	fprintf(h,"%d\n",k);
	fprintf(h,"%d %d %d %d %d %d\n",f.x,f.y,db.x,db.y,v,d1);
	for (i=0;i<l;i++) fprintf(h,"%d %d\n",s[i].x,s[i].y);
	fclose(h);
}
void doc_diem_cao(const char *x){
    h=fopen(x,"r");
    for(i=0;i<5;i++) fscanf(h,"%d",&dc[i]);
    fclose(h);
}
void ghi_diem_cao(const char *x){
	h=fopen(x,"w");
	for(i=0;i<5;i++) fprintf(h,"%d\n",dc[i]);
	fclose(h);
}
void on_exit(){
	h=fopen("cfg.ini","w");
	fprintf(h,"%d %d %d",cap,m,z);
	fclose(h);
}
void khung(){
	printf("%04d\n",diem);
	for (i=0;i<10;i++){
		for (j=0;j<18;j++)
			if ((i==0)||(i==9)||(j==0)||(j==17)) a[i][j]='#';
			else a[i][j]=' ';
	}
}
void ve_me_cung(){
	switch(z){
		case 1:
			for (i=0;i<8;i++)
				for (j=0;j<16;j++)
					if ((i==0)||(i==7)||(j==0)||(j==15)) a[i+1][j+1]='+';
			break;
		case 2:{
			for (i=0;i<16;i++)
				if (((i>=0)&&(i<=2))||((i>=13)&&(i<=15))) a[1][i+1]='+';
			for (i=1;i<7;i++)
				if ((i==1)||(i==2)||(i==5)||(i==6)){
					a[i+1][1]='+';
					a[i+1][16]='+';
				}
			for (i=0;i<16;i++)
				if (((i>=0)&&(i<=2))||((i>=13)&&(i<=15))) a[8][i+1]='+';
			for (i=4;i<12;i++){
				a[3][i+1]='+';
				a[6][i+1]='+';
			}
			break;
		}
		case 3:{
			for (i=0;i<5;i++) a[i+1][5]='+';
			for (i=10;i<16;i++) a[2][i+1]='+';
			for (i=3;i<8;i++) a[i+1][11]='+';
			for (i=0;i<5;i++) a[7][i+1]='+';
			break;
		}
		case 4:{
			for (i=0;i<16;i++) a[1][i+1]='+';
			for (i=1;i<7;i++)
				if ((i==1)||(i==2)||(i==5)||(i==6)){
					a[i+1][1]='+';
					a[i+1][16]='+';
				}
			for (i=0;i<16;i++) a[8][i+1]='+';
			for (i=3;i<13;i++){
				a[3][i+1]='+';
				a[6][i+1]='+';
			}
			break;
		}
		case 5:{
			a[1][1]='+';
			a[1][2]='+';
			a[2][1]='+';
			for (i=4;i<13;i++) a[1][i+1]='+';
			a[2][7]='+';
			a[3][7]='+';
			for (i=0;i<16;i++){
				if ((i!=7)&&(i!=8)) a[4][i+1]='+';
				a[6][i+1]='+';
			}
			a[7][10]='+';
			a[8][10]='+';
			break;
		}
	}
	p=0;
	for (i=0;i<8;i++)
		for (j=0;j<16;j++)
			if (a[i+1][j+1]=='+') p++;
}
void in_mt(){
	for (i=0;i<10;i++){
		for (j=0;j<18;j++){
			if ((s[l-1].x==i)&&(s[l-1].y==j)) textcolor('F');
			printf("%c",a[i][j]);
			printf("\u001b[0m");
		}
		printf("\n");
	}
}
void tao(){
	do{
		f.x=rand()%8+1;
		f.y=rand()%16+1;
	}while ((kt()==false)||(a[f.x][f.y]=='+')||(a[f.x][f.y]=='1'));
	a[f.x][f.y]='0';
}
void tao_db(){
	do{
		db.x=rand()%8+1;
		db.y=rand()%16+1;
	}while ((kt2()==false)||(a[db.x][db.y]=='+')||(a[db.x][db.y]=='0'));
	a[db.x][db.y]='1';
}
void tao_db_2x2(){
	do{
		db.x=rand()%7+1;
		db.y=rand()%15+1;
	}while ((kt2A()==false)||(kt22()==false));
	if ((f.x==db.x)&&(f.y==db.y)) a[db.x][db.y]='2';
	else a[db.x][db.y]='1';
	if ((f.x==db.x+1)&&(f.y==db.y)) a[db.x+1][db.y]='2';
	else a[db.x+1][db.y]='1';
	if ((f.x==db.x)&&(f.y==db.y+1)) a[db.x][db.y+1]='2';
	else a[db.x][db.y+1]='1';
	if ((f.x==db.x+1)&&(f.y==db.y+1)) a[db.x+1][db.y+1]='2';
	else a[db.x+1][db.y+1]='1';
	v=1;
}
void xoa_db(){
	if ((v==1)&&((a[db.x][db.y]=='1')||(a[db.x+1][db.y]=='1')||(a[db.x][db.y+1]=='1')||(a[db.x+1][db.y+1]=='1'))){
		a[db.x][db.y]=' ';
		a[db.x+1][db.y]=' ';
		a[db.x][db.y+1]=' ';
		a[db.x+1][db.y+1]=' ';
		if ((s[l-1].x==db.x)&&(s[l-1].y==db.y)) a[db.x][db.y]='*';
		else if ((s[l-1].x==db.x+1)&&(s[l-1].y==db.y)) a[db.x+1][db.y]='*';
		else if ((s[l-1].x==db.x)&&(s[l-1].y==db.y+1)) a[db.x][db.y+1]='*';
		else if ((s[l-1].x==db.x+1)&&(s[l-1].y==db.y+1)) a[db.x+1][db.y+1]='*';
	}
	else if ((v==1)&&((a[db.x][db.y]=='2')||(a[db.x+1][db.y]=='2')||(a[db.x][db.y+1]=='2')||(a[db.x+1][db.y+1]=='2'))){
		a[db.x][db.y]=' ';
		a[db.x+1][db.y]=' ';
		a[db.x][db.y+1]=' ';
		a[db.x+1][db.y+1]=' ';
		if ((s[l-1].x==db.x)&&(s[l-1].y==db.y)) a[db.x][db.y]='*';
		else if ((s[l-1].x==db.x+1)&&(s[l-1].y==db.y)) a[db.x+1][db.y]='*';
		else if ((s[l-1].x==db.x)&&(s[l-1].y==db.y+1)) a[db.x][db.y+1]='*';
		else if ((s[l-1].x==db.x+1)&&(s[l-1].y==db.y+1)) a[db.x+1][db.y+1]='*';
	}
	else if ((a[db.x][db.y]=='1')||(a[db.x][db.y]=='2')) a[db.x][db.y]=' ';
	db.x=0;
	db.y=0;
	d1=0;
	v=0;
}
void cap_nhat(){
	system("cls");
	printf("%04d\n",diem);
	in_mt();
	for (i=0;i<13;i++) printf("\n");
	printf("%c/%c/%c/%c: Dieu khien \t ESC: Tam dung",30,31,17,16);
}
void luu_diem(){
	switch(m){
		case 1:doc_diem_cao("hi0.txt");break;
		case 2:doc_diem_cao("hi1.txt");break;
		case 3:doc_diem_cao("hi2.txt");break;
	}
	if (diem<=dc[4]) printf("Diem cua ban:%d",diem);
	else if ((diem>dc[4])&&(diem<=dc[0])) printf("Diem cao:%d",diem);
	else printf("Diem cao nhat:%d",diem);
	if (diem>dc[4]) dc[4]=diem;
	for (i=0;i<4;i++)
		for (j=i+1;j<5;j++)
			if (dc[i]<dc[j]) hoan_doi(dc[i],dc[j]);
	switch(m){
		case 1:ghi_diem_cao("hi0.txt");break;
		case 2:ghi_diem_cao("hi1.txt");break;
		case 3:ghi_diem_cao("hi2.txt");break;
	}
}
void khoi_tao(){
	l=2;
	if (m==1) z=0;
	else if ((m==3)&&(z!=1)) z=1;
	if (z==3) s[0].x=3;
	else s[0].x=5;
	s[0].y=8;
	if (z==3) s[1].x=3;
	else s[1].x=5;
	s[1].y=9;
	k=3;
	a[s[0].x][s[0].y]='*';
	a[s[1].x][s[1].y]='*';
	stop=false;
	ps=false;
}
void hoan_thanh(){
	delay(1000);
	for (i=0;i<6;i++){
		system("color 70");
		delay(100);
		system("color 07");
		delay(100);
	}
}
void tiep_theo(){
	hoan_thanh();
	system("cls");
	khung();
	l=2;
	z++;
	if (z==3) s[0].x=3;
	else s[0].x=5;
	s[0].y=8;
	if (z==3) s[1].x=3;
	else s[1].x=5;
	s[1].y=9;
	k=3;
	a[s[0].x][s[0].y]='*';
	a[s[l-1].x][s[l-1].y]='*';
	stop=false;
	ps=true;	
	ve_me_cung();
	tao();
	in_mt();
	for (i=0;i<13;i++) printf("\n");
	printf("%c/%c/%c/%c: Dieu khien \t ESC: Tam dung",30,31,17,16);
	ghi_trang_thai("save.ini");
	delay(720-65*cap);
	while (ps==true){
		t=getch();
		if (t==27) break;
		else if (t==-32){
			t=getch();
			if ((t==72)&&(k!=1)) k=0;
			else if ((t==80)&&(k!=0)) k=1;
			else if ((t==75)&&(k!=3)) k=2;
			else if ((t==77)&&(k!=2)) k=3;
			ps=false;
		}
		else ps=true;
	}
}
void di_chuyen(int k){
	if (d1>0) d1--;
	if (d1==0) xoa_db();
	tg=s[0];
	a[s[0].x][s[0].y]=' ';
	for (i=0;i<l-1;i++){
		s[i]=s[i+1];
		a[s[i].x][s[i].y]='*';
	}
	s[l-1].x=s[l-2].x+dx[k];
	s[l-1].y=s[l-2].y+dy[k];
	if (s[l-1].x==0) s[l-1].x=8;
	else if (s[l-1].x==9) s[l-1].x=1;
	if (s[l-1].y==0) s[l-1].y=16;
	else if (s[l-1].y==17) s[l-1].y=1;
	if (a[s[l-1].x][s[l-1].y]=='+') stop=true;
	a[s[l-1].x][s[l-1].y]='*';
	if ((s[l-1].x==f.x)&&(s[l-1].y)==f.y){
		if ((m!=3)||((m==3)&&(l<15))) diem+=cap;
		if (diem>9999) diem=9999;
		if ((((z==0)||(z==3))&&(l<100))||((z!=0)&&(z!=3)&&(l<126-p))){
			l++;
			for (i=l-1;i>=0;i--) s[i+1]=s[i];
			s[0]=tg;
			a[s[0].x][s[0].y]='*';
			if ((m!=3)||((m==3)&&(l<15))) tao();
			if (l%5==2){
				if (d1>0) xoa_db();
				if (kt22()==true) tao_db_2x2();
				else tao_db();
				d1=14;
			}
			if ((m==3)&&(l==15)) xoa_db();
		}
		else tao();
	}
	if (v==1)
		if (((s[l-1].x==db.x)&&(s[l-1].y==db.y))||((s[l-1].x==db.x+1)&&(s[l-1].y==db.y))||((s[l-1].x==db.x)&&(s[l-1].y==db.y+1))||((s[l-1].x==db.x+1)&&(s[l-1].y==db.y+1))){
			diem+=(d1*5-rand()%5)*cap;
			xoa_db();
		}
	else if ((s[l-1].x==db.x)&&(s[l-1].y==db.y)){
		diem+=(d1*5-rand()%5)*cap;
		xoa_db();
	}
	if ((f.x!=0)&&(f.y!=0)&&(a[f.x][f.y]==' ')) a[f.x][f.y]='0';
	for (i=0;i<l-1;i++)
		for (j=i+1;j<l;j++)
			if ((s[i].x==s[j].x)&&(s[i].y==s[j].y)){
				stop=true;
				break;
			}
	cap_nhat();
	if (stop==true) delay(3500);
}
void van_moi(){
	system("cls 2>save.ini");
	diem=0;
	khung();
	khoi_tao();
	ve_me_cung();
	tao();
	in_mt();
	for (i=0;i<13;i++) printf("\n");
	printf("%c/%c/%c/%c: Dieu khien \t ESC: Tam dung",30,31,17,16);
	delay(720-65*cap);
	while (ps==false){
		if (kbhit()==true){
			t=getch();
			if (t==-32){
				t=getch();
				if ((t==72)&&(k!=1)) k=0;
				else if ((t==80)&&(k!=0)) k=1;
				else if ((t==75)&&(k!=3)) k=2;
				else if ((t==77)&&(k!=2)) k=3;
			}
			else if (t==27){
				if (stop==false){
					ghi_trang_thai("save.ini");
					ps=true;
					opt--;
				}
				else{
					system("cls 2>save.ini");
					luu_diem();
				}
				opt=1;
				break;
			}
		}
		if (stop==false){
			if ((kbhit()==false)||!((t==-32)&&((t==72)||(t==80)||(t==75)||(t==77)))){
				di_chuyen(k);
				delay(720-65*cap);
			}
			if ((m==3)&&(l==15))
				if (z<5) tiep_theo();
				else{
					stop=true;
					delay(1000);
				}
		}
		else{
			system("cls 2>save.ini");
			if ((m==3)&&(z==5)&&(l==15)) printf("\t----CHIEN DICH DA HOAN THANH----\n");
			else printf("\t----GAME OVER----\n");
			luu_diem();
			printf("\nXin vui long doi de quay lai menu");
			delay(3500);
			opt=1;
			break;
		}
	}
}
void tiep_tuc(){
	system("cls");
	doc_trang_thai("save.ini");
	khung();
	ve_me_cung();
	for (i=0;i<l;i++) a[s[i].x][s[i].y]='*';
	if ((f.x!=0)&&(f.y!=0)) a[f.x][f.y]='0';
	if ((db.x!=0)&&(db.y!=0)){
		if (v==1){
			if ((f.x==db.x)&&(f.y==db.y)) a[db.x][db.y]='2';
			else a[db.x][db.y]='1';
			if ((f.x==db.x+1)&&(f.y==db.y)) a[db.x+1][db.y]='2';
			else a[db.x+1][db.y]='1';
			if ((f.x==db.x)&&(f.y==db.y+1)) a[db.x][db.y+1]='2';
			else a[db.x][db.y+1]='1';
			if ((f.x==db.x+1)&&(f.y==db.y+1)) a[db.x+1][db.y+1]='2';
			else a[db.x+1][db.y+1]='1';
		}
		else a[db.x][db.y]='1';
	}
	stop=false;
	ps=true;
	cap_nhat();
	delay(720-65*cap);
	while (ps==true){
		t=getch();
		if (t==27) break;
		else if (t==-32){
			t=getch();
			if ((t==72)&&(k!=1)) k=0;
			else if ((t==80)&&(k!=0)) k=1;
			else if ((t==75)&&(k!=3)) k=2;
			else if ((t==77)&&(k!=2)) k=3;
			ps=false;
		}
		else ps=true;
	}
	while (ps==false){
		if (kbhit()==true){
			t=getch();
			if (t==-32){
				t=getch();
				if ((t==72)&&(k!=1)) k=0;
				else if ((t==80)&&(k!=0)) k=1;
				else if ((t==75)&&(k!=3)) k=2;
				else if ((t==77)&&(k!=2)) k=3;
			}
			else if (t==27){
				if (stop==false){
					ghi_trang_thai("save.ini");
					ps=true;
				}
				else{
					system("cls 2>save.ini");
					luu_diem();
				}
				opt=1;
				break;
			}
		}
		if (stop==false){
			if ((kbhit()==false)||!((t==-32)&&((t==72)||(t==80)||(t==75)||(t==77)))){
				di_chuyen(k);
				delay(720-65*cap);
			}
			if ((m==3)&&(l==15))
				if (z<5) tiep_theo();
				else{
					stop=true;
					delay(1000);
				}
		}
		else{
			system("cls 2>save.ini");
			if ((m==3)&&(z==5)&&(l==15)) printf("\t----CHIEN DICH DA HOAN THANH----\n");
			else printf("\t----GAME OVER----\n");
			luu_diem();
			printf("\nXin vui long doi de quay lai menu");
			delay(3500);
			opt=1;
			break;
		}
	}
}
void cap_do(){
	ptr=cap;
	while (true){
		system("cls");
		printf("\t----SNAKE >> CAP DO----\n");
		for (i=0;i<4;i++) printf("\n");
		printf("\t  ");
		for (i=0;i<19;i++) printf("-");
		printf("\n");
		printf("\t%d | ",ptr);
		for (i=0;i<ptr;i++){
			textbackground('3');
			textcolor('0');
			printf(" \u001b[0m ");
		}
		for (i=0;i<8-ptr;i++){
			textbackground('0');
			textcolor('B');
			printf(" \u001b[0m ");
		}
		printf("|\n");
		printf("\t  ");
		for (i=0;i<19;i++) printf("-");
		for (i=0;i<17;i++) printf("\n");
		printf("%c/%c: Thay doi tuy chon \t Enter: Xac nhan \t ESC: Quay lai menu",17,16);
		t=getch();
		if (t==-32){
			t=getch();
			if ((t==75)&&(ptr>1)) ptr--;
			else if ((t==77)&&(ptr<8)) ptr++;
		}
		else if ((t==13)||(t==27)) break;
	}
	if (t==13){
		if ((cap!=ptr)&&(empty_file("save.ini")==0)){
			system("cls 2>save.ini");
			opt--;
		}
		cap=ptr;
		on_exit();
	}
}
void me_cung(){
	if (m==3) opt3=0;
	else opt3=z;
	while (true){
		system("cls");
		printf("\t----SNAKE >> CHE DO >> ME CUNG----\n");
		if (opt3==0){
			textbackground('3');
			textcolor('F');
		}
		printf("0. Khong co me cung%61s\u001b[0m\n","");
		if (opt3==1){
			textbackground('3');
			textcolor('F');
		}
		printf("1. Hop%74s\u001b[0m\n","");
		if (opt3==2){
			textbackground('3');
			textcolor('F');
		}
		printf("2. Duong ham%68s\u001b[0m\n","");
		if (opt3==3){
			textbackground('3');
			textcolor('F');
		}
		printf("3. Nha may%70s\u001b[0m\n","");
		if (opt3==4){
			textbackground('3');
			textcolor('F');
		}
		printf("4. Duong ray%68s\u001b[0m\n","");
		if (opt3==5){
			textbackground('3');
			textcolor('F');
		}
		printf("5. Can ho%71s\u001b[0m","");
		for (i=0;i<18;i++) printf("\n");
		printf("%c/%c: Chon muc \t Enter: Xac nhan \t ESC: Quay lai che do",30,31);
		t=getch();
		if ((t==13)||(t==27)) break;
		else if (t==-32){
			t=getch();
			if (t==72) opt3--;
			else if (t==80) opt3++;
		}
		if (opt3<0) opt3=5;
		else if (opt3>5) opt3=0;
	}
	if (t==13){
		if (((m==1)||(m==3)||((m==2)&&(z!=opt3)))&&(empty_file("save.ini")==0)){
			system("cls 2>save.ini");
			opt--;
		}
		m=2;
		z=opt3;
		on_exit();
	}
}
void che_do(){
	opt2=m;
	while (true){
		system("cls");
		printf("\t----SNAKE >> CHE DO----\n");
		if (opt2==1){
			textbackground('3');
			textcolor('F');
		}
		printf("1. Kinh dien%68s\u001b[0m\n","");
		if (opt2==2){
			textbackground('3');
			textcolor('F');
		}
		printf("2. Hien dai%69s\u001b[0m\n","");
		if (opt2==3){
			textbackground('3');
			textcolor('F');
		}
		printf("3. Chien dich%67s\u001b[0m","");
		for (i=0;i<21;i++) printf("\n");
		printf("%c/%c: Chon muc \t Enter: Xac nhan \t ESC: Quay lai menu",30,31);
		t=getch();
		if (t==13){
			if (opt2==2) me_cung();
			else break;
		}
		else if (t==27) break;
		else if (t==-32){
			t=getch();
			if (t==72) opt2--;
			else if (t==80) opt2++;
		}
		if (opt2<1) opt2=3;
		else if (opt2>3) opt2=1;
	}
	if (opt2==1) z=0;
	else if (opt2==3) z=1;
	if (t==13){
		if ((m!=opt2)&&(empty_file("save.ini")==0)){
			system("cls 2>save.ini");
			opt--;
		}
		m=opt2;
		on_exit();
	}
}
void huong_dan(){
	while (true){
		system("cls");
		printf("\t----SNAKE >> HUONG DAN----\n");
		printf("Su dung cac phim mui ten de dieu khien ran. An thuc an ma tranh cham cac chuong \n");
		printf("ngai vat va an thuc an dac biet nhanh chong de ghi them diem.");
		for (i=0;i<22;i++) printf("\n");
		printf("ESC: Quay lai menu");
		if (getch()==27) break;
	}
}
void diem_cao(){
	switch(m){
		case 1:doc_diem_cao("hi0.txt");break;
		case 2:doc_diem_cao("hi1.txt");break;
		case 3:doc_diem_cao("hi2.txt");break;
	}
	while (true){
		system("cls");
		printf("\t----SNAKE >> DIEM CAO----\n");
		for (i=0;i<5;i++) printf("%d:%d\n",i+1,dc[i]);
		for (i=0;i<18;i++) printf("\n");
		printf("ESC: Quay lai menu");
		if (getch()==27) break;
	}
}
void dat_lai(){
	opt4=1;
	while (true){
		system("cls");
		printf("\t----SNAKE >> DAT LAI----\n");
		if (opt4==1){
			textbackground('3');
			textcolor('F');
		}
		printf("1. Thiet lap du lieu%60s\u001b[0m\n","");
		if (opt4==2){
			textbackground('3');
			textcolor('F');
		}
		printf("2. Diem cao%69s\u001b[0m\n","");
		if (opt4==3){
			textbackground('3');
			textcolor('F');
		}
		printf("3. Khoi tao tat ca%62s\u001b[0m","");
		for (i=0;i<21;i++) printf("\n");
		printf("%c/%c: Chon muc \t Enter: Xac nhan \t ESC: Quay lai menu",30,31);
		t=getch();
		if (t==13){
			switch(opt4){
				case 1:{
					while (reset_cfg[0]==false){
						system("cls");
						printf("\t----SNAKE >> DAT LAI >> XAC NHAN----\n");
						printf("Dong y cai dat lai?\n");
						printf("Thiet lap du lieu\n");
						printf("[Enter]\t\t: Xac nhan\n");
						printf("[ESC]\t\t: Huy");
						t=getch();
						if (t==27) break;
						if (t==13){
							system("cls 2>cfg.ini");
							if (empty_file("save.ini")==0){
								system("cls 2>save.ini");
								opt--;
							}
							cap=1;
							m=1;
							z=0;
							on_exit();
							reset_cfg[0]=true;
						}
						if ((t!=13)&&(t!=27)) reset_cfg[0]=false;
					}
					break;
				}
				case 2:{
					while (reset_cfg[1]==false){
						system("cls");
						printf("\t----SNAKE >> DAT LAI >> XAC NHAN----\n");
						printf("Dong y cai dat lai?\n");
						printf("Diem cao\n");
						printf("[Enter]\t\t: Xac nhan\n");
						printf("[ESC]\t\t: Huy");
						t=getch();
						if (t==27) break;
						if (t==13){
							for (i=0;i<5;i++) dc[i]=0;
							ghi_diem_cao("hi0.txt");
							ghi_diem_cao("hi1.txt");
							ghi_diem_cao("hi2.txt");
							reset_cfg[1]=true;
						}
						if ((t!=13)&&(t!=27)) reset_cfg[1]=false;
					}
					break;
				}
				case 3:{
					while (reset_cfg[2]==false){
						system("cls");
						printf("\t----SNAKE >> DAT LAI >> XAC NHAN----\n");
						printf("Dong y cai dat lai?\n");
						printf("Khoi tao tat ca\n");
						printf("[Enter]\t\t: Xac nhan\n");
						printf("[ESC]\t\t: Huy");
						t=getch();
						if (t==27) break;
						if (t==13){
							system("cls 2>cfg.ini");
							if (empty_file("save.ini")==0){
								system("cls 2>save.ini");
								opt--;
							}
							cap=1;
							m=1;
							z=0;
							for (i=0;i<5;i++) dc[i]=0;
							ghi_diem_cao("hi0.txt");
							ghi_diem_cao("hi1.txt");
							ghi_diem_cao("hi2.txt");
							on_exit();
							reset_cfg[2]=true;
						}
						if ((t!=13)&&(t!=27)) reset_cfg[2]=false;
					}
					break;
				}
			}
			for (i=0;i<3;i++) reset_cfg[i]=false;
		}
		else if (t==27) break;
		else if (t==-32){
			t=getch();
			if (t==72) opt4--;
			else if (t==80) opt4++;
		}
		if (opt4<1) opt4=3;
		else if (opt4>3) opt4=1;
	}
}
void menu(){
	system("cls");
	printf("\t----SNAKE----\n");
	if (opt==1){
		textbackground('3');
		textcolor('F');
	}
	printf("1. Tro choi moi%65s\u001b[0m\n","");
	if (opt==2){
		textbackground('3');
		textcolor('F');
	}
	printf("2. Cap do%71s\u001b[0m\n","");
	if (opt==3){
		textbackground('3');
		textcolor('F');
	}
	printf("3. Che do%71s\u001b[0m\n","");
	if (opt==4){
		textbackground('3');
		textcolor('F');
	}
	printf("4. Huong dan%68s\u001b[0m\n","");
	if (opt==5){
		textbackground('3');
		textcolor('F');
	}
	printf("5. Diem cao%69s\u001b[0m\n","");
	if (opt==6){
		textbackground('3');
		textcolor('F');
	}
	printf("6. Dat lai%70s\u001b[0m\n","");
	if (opt==7){
		textbackground('3');
		textcolor('F');
	}
	printf("7. Thoat%72s\u001b[0m","");
	for (i=0;i<17;i++) printf("\n");
	printf("%c/%c: Chon muc \t Enter: Xac nhan",30,31);
	t=getch();
	if (t==13){
		switch(opt){
			case 1:van_moi();break;
			case 2:cap_do();break;
			case 3:che_do();break;
			case 4:huong_dan();break;
			case 5:diem_cao();break;
			case 6:dat_lai();break;
			case 7:{
				on_exit();
				system("cls");
				system("attrib +r cfg.ini");
				system("attrib +r save.ini");
				exit(0);
				break;
			}
		}
	}
	else if (t==-32){
		t=getch();
		if (t==72) opt--;
		else if (t==80) opt++;
	}
	if (opt<1) opt=7;
	else if (opt>7) opt=1;
}
void menu_tiep_tuc(){
	system("cls");
	printf("\t----SNAKE----\n");
	if (opt==1){
		textbackground('3');
		textcolor('F');
	}
	printf("1. Tiep tuc%69s\u001b[0m\n","");
	if (opt==2){
		textbackground('3');
		textcolor('F');
	}
	printf("2. Tro choi moi%65s\u001b[0m\n","");
	if (opt==3){
		textbackground('3');
		textcolor('F');
	}
	printf("3. Cap do%71s\u001b[0m\n","");
	if (opt==4){
		textbackground('3');
		textcolor('F');
	}
	printf("4. Che do%71s\u001b[0m\n","");
	if (opt==5){
		textbackground('3');
		textcolor('F');
	}
	printf("5. Huong dan%68s\u001b[0m\n","");
	if (opt==6){
		textbackground('3');
		textcolor('F');
	}
	printf("6. Diem cao%69s\u001b[0m\n","");
	if (opt==7){
		textbackground('3');
		textcolor('F');
	}
	printf("7. Dat lai%70s\u001b[0m\n","");
	if (opt==8){
		textbackground('3');
		textcolor('F');
	}
	printf("8. Thoat%72s\u001b[0m","");
	for (i=0;i<16;i++) printf("\n");
	printf("%c/%c: Chon muc \t Enter: Xac nhan",30,31);
	t=getch();
	if (t==13){
		switch(opt){
			case 1:tiep_tuc();break;
			case 2:van_moi();break;
			case 3:cap_do();break;
			case 4:che_do();break;
			case 5:huong_dan();break;
			case 6:diem_cao();break;
			case 7:dat_lai();break;
			case 8:{
				on_exit();
				system("cls");
				system("attrib +r cfg.ini");
				system("attrib +r save.ini");
				exit(0);
				break;
			}
		}
	}
	else if (t==-32){
		t=getch();
		if (t==72) opt--;
		else if (t==80) opt++;
	}
	if (opt<1) opt=8;
	else if (opt>8) opt=1;
}
int main(){
	srand(time(0));
	on_preload();
	on_load();
	while (true)
		if (empty_file("save.ini")==0) menu_tiep_tuc();
		else menu();
	on_exit();
	return 0;
}
