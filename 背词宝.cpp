#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#pragma comment(lib, ��winmm.lib��)
using namespace std;
const int WK=4000;
int wk=27,ck=54,fc=1;
int color,M,V,vol=600;
LONG l_WinStyle=-1792344064;
class Recite{
	fstream file;
	fstream file1;
public:
	Recite();
	void insert_word();
	void query_all();
	void query_by_time();
	void query_history();
	void query_exact();
	void delete_word();
	int get_num();
	void recite_word();
	void update_log();
	void run();
};
Recite::Recite() {
	file.open("���ʱ�.txt");
	file.close();
	file.open("������ʷ.log");
	file.close();
	file.open("��ʷ��¼.txt");
	file.close();
}
void full_screen()
{   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void windowed()
{   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */
    SetWindowLong(hwnd,GWL_STYLE,l_WinStyle);
    SetWindowPos(hwnd, HWND_TOP, cx/4, cy/4, cx/2, cy/2, 0);
}
void save() {
	FILE *fp2;
	fp2=fopen("beicibao.ini","w");
	fprintf(fp2,"%d %d %d %d %d %d",color,wk,ck,M,vol,fc);
	fclose(fp2);
}
void read() {
	FILE *fp1;
	fp1=fopen("beicibao.ini","r");
	fscanf(fp1,"%d %d %d %d %d %d",&color,&wk,&ck,&M,&vol,&fc);
	fclose(fp1);
}
void CE()
{
	printf(" ");
	for(int i=1;i<=wk;i++)
	   printf("-");
	printf("+");
	for(int i=1;i<=ck;i++)
	   printf("-");
	cout<<endl;
	return;
}
void setaudio()
{
	    if(vol==0)mciSendString("setaudio mymusic volume to 0",NULL,0,NULL);		//����������С
        if(vol==100)mciSendString("setaudio mymusic volume to 100",NULL,0,NULL);		//����������С
        if(vol==200)mciSendString("setaudio mymusic volume to 200",NULL,0,NULL);		//����������С
        if(vol==300)mciSendString("setaudio mymusic volume to 300",NULL,0,NULL);		//����������С
        if(vol==400)mciSendString("setaudio mymusic volume to 400",NULL,0,NULL);		//����������С
        if(vol==500)mciSendString("setaudio mymusic volume to 500",NULL,0,NULL);		//����������С
        if(vol==600)mciSendString("setaudio mymusic volume to 600",NULL,0,NULL);		//����������С
        if(vol==700)mciSendString("setaudio mymusic volume to 700",NULL,0,NULL);		//����������С
        if(vol==800)mciSendString("setaudio mymusic volume to 800",NULL,0,NULL);		//����������С
        if(vol==900)mciSendString("setaudio mymusic volume to 900",NULL,0,NULL);		//����������С
        if(vol==1000)mciSendString("setaudio mymusic volume to 1000",NULL,0,NULL);		//����������С
        if(vol==1100)mciSendString("setaudio mymusic volume to 1100",NULL,0,NULL);		//����������С
        if(vol==1200)mciSendString("setaudio mymusic volume to 1200",NULL,0,NULL);		//����������С
        if(vol==1300)mciSendString("setaudio mymusic volume to 1300",NULL,0,NULL);		//����������С
        if(vol==1400)mciSendString("setaudio mymusic volume to 1400",NULL,0,NULL);		//����������С
        if(vol==1500)mciSendString("setaudio mymusic volume to 1500",NULL,0,NULL);		//����������С
        if(vol<0) vol=0;
        if(vol>1500) vol=1500;
        if(wk<=0) wk=1;
        if(ck<=0) ck=1;
        if(M<=0) M=25;
        if(fc==1) full_screen(); 
        if(fc==0) windowed();
}
void set()
{
	system("cls");
	setaudio();
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n\n\n\n"); 
	cout << "                              ______________________________  " << endl;
	cout << "                             |                              | " << endl;
	cout << "                             |     ���á�����W,A,S,D�ٿ�    | " << endl;
	cout << "                             |         ���������           | " << endl;
	cout << "                             ";
	if(V==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	printf("|             %3d              | \n",wk);
	SetConsoleTextAttribute(h,color);
	cout << "                             |         ���������           | " << endl;
	cout << "                             ";
	if(V==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	printf("|             %3d              | \n",ck);
	SetConsoleTextAttribute(h,color);
	cout << "                             |       ������󱳴���         | " << endl;
	cout << "                             ";
	if(V==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	printf("|             %3d              | \n",M);
	SetConsoleTextAttribute(h,color);
	cout << "                             |            ����              | " << endl;
	cout << "                             ";
	if(V==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	printf("|");
	for(int i=1;i<=15;i++){
		if(vol>=i*100) printf("�� ");
		else printf("  ");
	}
	printf("| \n");
	SetConsoleTextAttribute(h,color);
	cout << "                             |            ��ʾģʽ          |" << endl;
	cout << "                             ";
	if(V==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	if(fc==1) printf("|          Full screen         | \n");
	else printf("|           Windowed           | \n");
	SetConsoleTextAttribute(h,color);
	cout << "                             |        ��0���ز���������     | " << endl;
	cout << "                             |      ��������Ҫ��������    | " << endl;
	cout << "                              ------------------------------  " << endl;
	int o=0;
	while(o==0)
	{
		o=0;
	    char D=getch();
	    if(D=='0') return;
	    if(D=='W') {V=(V+4)%5;set();o=1;}
	    if(D=='S') {V=(V+1)%5;set();o=1;}
	    if(D=='D') {if(V==0) wk+=1;if(V==1) ck+=1;if(V==2) M+=25;if(V==3) vol+=100;if(V==4) fc^=1;set();o=1;}
	    if(D=='A') {if(V==0) wk-=1;if(V==1) ck-=1;if(V==2) M-=25;if(V==3) vol-=100;if(V==4) fc^=1;set();o=1;}
	}
	save();
	return;
}
void Recite::insert_word() {
	clock_t startTime, endTime;
	file.open("���ʱ�.txt", ios::out | ios::app);
	if (file.is_open() == 1) {
		startTime = clock();
		char word[wk+1], trans[ck+1];
		cout << "������Ҫд����Ȿ�ĵ��ʣ�";
		char c;
		cin>>word;
		cout << "�����뵥�ʵĽ��ͣ�";
		cin >> trans;
		file << word << " " <<trans<<endl;
		file.close();
		endTime = clock();
		cout << "д��ɹ����ܹ���ʱ" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
	else {
		cout << "���ļ�ʧ��" << endl;
		system("pause");
	}
	
}
void Recite::query_all() {
	clock_t startTime, endTime;
	startTime = clock();
	char buffer[WK];
	int number = 0; 
	CE();
	cout << "|" << setw(wk) << "����";
	cout << "|" << setw(ck) << "����";
	cout << "|" << endl;
	CE();
	file.open("���ʱ�.txt", ios::in | ios::app);
	while (!file.eof()) {
		file.getline(buffer,WK,'\n');
		istringstream is(buffer);
		string s1, s3,s4;
		is >> s1 >> s3>>s4;
		if (s1 != ""&&s3 != "") {
			number++;
			cout << "|" << setw(wk) << s1;
			cout << "|" << setw(ck) << s3;
			cout << "|" << endl;
			CE();
		}
	}
	endTime = clock();
	cout << "�ܹ���" << number << "����¼���ܹ���ʱ"<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
	file.close();
}
void Recite::query_by_time() {
	file.open("������ʷ.log", ios::in | ios::out | ios::app);
	if (file.is_open()) {
		string time;
		cout << "������Ҫ��ѯ����ʷ��¼�������գ���ʽΪĳ��-ĳ��-ĳ�գ�";
		cin >> time;
		string word[WK], trans[WK];
		int i = 0;
		char buffer[WK];
		while (!file.eof()) {
			file.getline(buffer, WK);
			istringstream is(buffer);
			string t1, t2;
			is >> t1 >> t2;
			if (t1 == time) {
				while (!file.eof()) {
					file.getline(buffer, WK);
					istringstream input(buffer);
					string s1, s3;
					input >> s1 >> s3;
					if (s1 != ""&&s3 != "") {
						word[i] = s1;
						trans[i] = s3;
						i++;
					}
					else {
						if (s1 == time)
							continue;
						else
							break;
					}
				}
			}
		}
		file.close();
		file.open("��ʷ��¼.txt", ios::in | ios::out | ios::trunc);
		for (int j = 0; j < i; j++)
			file << word[j] << " " <<trans[j] << endl;
		file.close();
		query_history();
	}
	else {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
}
void Recite::query_history() {
	clock_t startTime, endTime;
	startTime = clock();
	char buffer[WK];
	int number = 0;
	CE();
	cout << "|" << setw(wk) << "����";
	cout << "|" << setw(ck) << "����";
	cout << "|" << endl;
	CE();
	file.open("��ʷ��¼.txt", ios::in | ios::app);
	while (!file.eof()) {
		file.getline(buffer, WK);
		istringstream is(buffer);
		string s1,  s3;
		is >> s1 >> s3 ;
		if (s1 != ""&&s3 != "") {
			number++;
			cout << "|" << setw(wk) << s1;
			cout << "|" << setw(ck) << s3;
			cout << "|" << endl;
			CE();
		}
	}
	endTime = clock();
	cout << "�ܹ���" << number << "����¼���ܹ���ʱ" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	file.close();
}
void Recite::query_exact() {
	clock_t startTime, endTime;
	char buffer[WK];
	int i,number=0;
	startTime = clock();
	string word;
	cout << "������Ҫ��ĵ��ʣ�";
	cin >> word;
	CE();
	cout << "|" << setw(wk) << "����";
	cout << "|" << setw(ck) << "����";
	cout << "|" << endl;
	CE();
	file.open("���ʱ�.txt", ios::in);
		while (!file.eof()) {
			file.getline(buffer,WK,'\n');
			istringstream is(buffer);
			string s1, s3;
			is >> s1 >> s3;
			if (s1 == word) {
				number++;
				cout << "|" << setw(wk) << s1;
				cout << "|" << setw(ck) << s3;
				cout << "|" << endl;
				CE();
			}
		}
		endTime = clock();
		cout << "��ѯ�ɹ���һ����" << number << "����¼����ʱ��" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		file.close();
}
void Recite::delete_word() {
	query_all();
	string str;
	clock_t startTime, endTime;
	cout << "��������Ҫɾ���ĵ��ʣ�";
	cin >> str;
	startTime = clock();
	file.open("���ʱ�.txt",ios::in);
	char buffer[WK];
	string str1[WK],str2[WK],str3[WK];
	int i = 0;
	while (!file.eof()) {
		file.getline(buffer, WK);
		istringstream is(buffer);
		string s1, s3;
		is >> s1 >>  s3;
		if (s1 != str && s1 != ""&& s3!="" ) {
			str1[i] = s1;
			str3[i] = s3;
			i++;
		}
	}
	file.close();
	file.open("���ʱ�.txt", ios::out|ios::trunc);
	for (int j = 0; j < i; j++) {
		file << str1[j] << " " << str2[j] << " " << str3[j] << " " << endl;
	}
	file.close();
	endTime = clock();
	cout << "ɾ���ɹ�����ʱ��" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}
void Recite::recite_word() {
	file.open("���ʱ�.txt", ios::in|ios::out);  
	if (file.is_open() == 1) {
		clock_t startTime, endTime;
		string word[WK], trans[WK], str;
		char buffer[WK];
		int i = 0;
		while (!file.eof()&&i<M) {
			file.getline(buffer, WK);
			istringstream is(buffer);
			string s1, s3;
			is >> s1 >> s3;
			if (s1 != ""&&s3 != "") {
				word[i] = s1;
				trans[i] = s3;
				i++;
			}
		}
		int number=i;
		if(number==0){
		cout << "���ʱ�Ϊ�գ��ȼ��������ٱ��а�" << endl;
		return;}
		cout <<"������Ҫ��ϰ�ĵ��������ǣ�"<<number;
		cout<<endl;system("pause");system("cls");
		int num_of_recite[WK];
		for (int k = 0;k<number; k++)
			num_of_recite[k] = 1;
		int sucessful = 0;
		int num=0;
		startTime=clock();
		while (sucessful == 0) {
			for (int j = 0; j < i; j++) {
				if (num_of_recite[j] != 0) {
					cout<<" --------------------------------------------------"<<endl<<"|";
		for(int i=1; i<=25; i++)
		{
			if(i<=num*25/M) cout<<"�� ";
			else cout<<"  ";
		}			
		cout<<"|"<<endl<<" --------------------------------------------------"<<endl;
				cout << "Ӣ�ĵ��ʣ�" << word[j]<< endl;
				cout << "��ѡ����˼��"<<endl;
				srand((unsigned)time(NULL));
				int cr=rand()%4;
				int r1,r2,r3,r4;
				if(number<4)
				{ 
					word[number]="SJJ";trans[number]="n.ʱ�ѿ�";
					word[number+1]="ZYT";trans[number+1]="n.����͢";
					word[number+2]="CBS";trans[number+2]="n.�ܲ���";
					word[number+3]="Astral Plane";trans[number+3]="n.�����"; 
				}
				int cbg=0;
				if(number<4) cbg=4;
					do {r1=rand()%(number+cbg); }while(r1==j);
					do {r2=rand()%(number+cbg); }while(r2==r1||r2==j);
					do {r3=rand()%(number+cbg); }while(r3==r2||r3==r1||r3==j);
					do {r4=rand()%(number+cbg); }while(r4==r3||r4==r2||r4==r1||r4==j);
					if(cr==1) cout << "A."<<trans[j] <<endl;
					else cout << "A."<<trans[r1] <<endl;
					if(cr==2) cout << "B."<<trans[j]<<endl;
					else cout << "B."<<trans[r2] <<endl;
					if(cr==3) cout << "C."<<trans[j] <<endl;
					else cout << "C."<<trans[r3]  <<endl;
					if(cr==0) cout << "D."<<trans[j] <<endl;
					else cout << "D."<<trans[r4] <<endl;
					cin >> str;
					if (str == "A"&&cr==1 || str == "B"&&cr==2||str == "C"&&cr==3||str == "D"&&cr==0) {
						cout << "��ȷ��";
						num_of_recite[j]--;
						system("pause");
						system("cls");
						num++;
						if (num == number)
							sucessful = 1;
					}
					else {
						if(cr==0) cr=4;
						printf("������ȷ���ǣ�%c\n",cr+64);
						num_of_recite[j]++;
						system("pause");
						system("cls");
					}
				}
			}
		}
		endTime=clock();
		cout<<" --------------------------------------------------"<<endl<<"|";
		for(int i=1; i<=25; i++) cout<<"��";
		cout<<"|"<<endl<<" --------------------------------------------------"<<endl;
		cout << "��ϲ�㱳����~~����ʱ��" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		file.close();
		file.open("������ʷ.log", ios::out|ios::app);
		SYSTEMTIME st = { 0 };
		GetLocalTime(&st);
		file << st.wYear << "-" << st.wMonth << "-" << st.wDay << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
		for (int j = 0; j < i; j++) {
			file << word[j] <<" " << trans[j] << endl;
		}
		file.close();
		file.open("���ʱ�.txt", ios::in|ios::out);
		i = 0;
 		while (!file.eof()) {
			file.getline(buffer, WK);
			istringstream is(buffer);
			string s1, s3;
			is >> s1 >> s3;
			if (s1 != ""&&s3 != "") {
				if(i>=M) 
				{word[i] = s1;
				trans[i] = s3;}
				i++;
			}
		}
		file.close();
		file.open("���ʱ�.txt", ios::out | ios::trunc);
		for (int j = M; j < i; j++) {
			file << word[j] <<" " << trans[j] << endl;
		}
		file.close();
	}
	else {
		cout << "���ʱ�Ϊ�գ��ȼ��������ٱ��а�" << endl;
		return;
	}
}
void print()
{
	system("cls");printf("\n\n\n\n\n"); 
	cout << "                              ______________________________  " << endl;
	cout << "                             |                              | " << endl;
	cout << "                             |      ��ӭʹ�ñ��ʱ�6.0       | " << endl;
	cout << "                             |          1.�������          | " << endl;
	cout << "                             |        2.��ʾ��������        | " << endl;
	cout << "                             |          3.��ȷ���          | " << endl;
	cout << "                             |       4.ɾ�����ʱ��еĴ�     | " << endl;
	cout << "                             |           5.������           | " << endl;
	cout << "                             |        6.��ѯ������ʷ        | " << endl;
	cout << "                             |          7.������־          | " << endl;
	cout << "                             |         8.������ģʽ         | " << endl;
	cout << "                             |            9.����            | " << endl;
	cout << "                             |            0.�˳�            | " << endl;
	cout << "                             |      ��������Ҫ��������    | " << endl;
	cout << "                              ------------------------------  " << endl;
}
void Recite::update_log() {
	cout << "2018-9-4 ���ʱ�1.0 ����" << endl;
	cout << "2020-2-15 ���ʱ�2.0 ���� �����˽��� �ع��˴���" << endl;
	cout << "2021-1-19 ���ʱ�3.0���� �޸����ش�bug ������ͼ��"<<endl;
	cout << "2021-1-21 ���ʱ�3.5���� �޸��˴ʿ��Сbug"<<endl;
	cout << "2021-1-22 ���ʱ�4.0���� �����˿�����ģʽ"<<endl;
	cout << "2021-1-23 ���ʱ�4.5���� ����������"<<endl;
	cout << "2021-1-24 ���ʱ�5.0���� �����˽�����"<<endl;
	cout << "2021-1-25 ���ʱ�5.1���� �޸����ļ�����bug"<<endl;
	cout << "2021-1-26 ���ʱ�5.2���� ������BGM"<<endl;
	cout << "2021-1-27 ���ʱ�5.3���� �Ż������ý���"<<endl;
	cout << "2021-1-28 ���ʱ�5.4���� ��չ������"<<endl;
	cout << "2021-1-29 ���ʱ�5.5���� �޸�������bug"<<endl;
	cout << "2021-2-2 ���ʱ�5.6���� �޸�����Ŀ�ṹ"<<endl;
	cout << "2021-2-3 ���ʱ�5.7���� ������ȫ��"<<endl;
	cout << "2021-2-5 ���ʱ�5.8���� �޸����°����̨fc��bug"<<endl;
    cout << "2021-2-14 ���ʱ�5.9���� ����������ini"<<endl;
    cout << "2021-2-17 ���ʱ�6.0���� �޸��˶�������bug"<<endl;
}
void develop_mode()
{
    HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    int i,j;
    for(i=0;i<16;i++){
    for(j=0;j<=15;j++)
    {
       SetConsoleTextAttribute(hOut,i*16+j);
       printf(" %3d ",i*16+j);
    } 
    printf("\n");}
    SetConsoleTextAttribute(hOut,color);
    printf("\n�������֣��ɽ���ʾ�����Ϊѡ�����ʽ\n");
    scanf("%d",&color);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    save();
}  
void Recite::run() {
	print();
	int i;
	i=getch()-'0';
	while (i) {
		switch (i) {
			case 1:
				system("cls");
				insert_word();
				break;
			case 2:
				system("cls");
				query_all();
				break;
			case 3:
				system("cls");
				query_exact();
				break;
			case 4:
				system("cls");
				delete_word();
				break;
			case 5:
				system("cls");
				recite_word();
				break;
			case 6:
				system("cls");
				query_by_time();
				break;
			case 7:
				system("cls");
				update_log();
				break;
			case 8:
			    system("cls");
			    develop_mode();
			    break;
			case 9:
				system("cls");
				set();
				break;
			case 0:
				break;
			default:
				cout << "��Ӧ���ֵķ��񲻴��ڣ�����������" << endl;
				break;
		}
		system("pause");
		system("cls");
	    print();
		i=getch()-'0';
	}
}
int main()
{
	read();
	Recite r;
	mciSendString("open m.mp3 alias mymusic", NULL, 0, NULL);	// ������
	mciSendString("setaudio mymusic volume to 600",NULL,0,NULL);		//����������С
	mciSendString("play mymusic", NULL, 0, NULL);						//��ʼ����
	mciSendString("play mymusic repeat", NULL, 0, NULL);				//ѭ������
	setaudio();
	r.run();
    return 0;
}
