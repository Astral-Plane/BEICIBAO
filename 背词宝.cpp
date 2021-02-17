#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#pragma comment(lib, “winmm.lib”)
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
	file.open("生词本.txt");
	file.close();
	file.open("背词历史.log");
	file.close();
	file.open("历史记录.txt");
	file.close();
}
void full_screen()
{   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void windowed()
{   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
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
	    if(vol==0)mciSendString("setaudio mymusic volume to 0",NULL,0,NULL);		//设置音量大小
        if(vol==100)mciSendString("setaudio mymusic volume to 100",NULL,0,NULL);		//设置音量大小
        if(vol==200)mciSendString("setaudio mymusic volume to 200",NULL,0,NULL);		//设置音量大小
        if(vol==300)mciSendString("setaudio mymusic volume to 300",NULL,0,NULL);		//设置音量大小
        if(vol==400)mciSendString("setaudio mymusic volume to 400",NULL,0,NULL);		//设置音量大小
        if(vol==500)mciSendString("setaudio mymusic volume to 500",NULL,0,NULL);		//设置音量大小
        if(vol==600)mciSendString("setaudio mymusic volume to 600",NULL,0,NULL);		//设置音量大小
        if(vol==700)mciSendString("setaudio mymusic volume to 700",NULL,0,NULL);		//设置音量大小
        if(vol==800)mciSendString("setaudio mymusic volume to 800",NULL,0,NULL);		//设置音量大小
        if(vol==900)mciSendString("setaudio mymusic volume to 900",NULL,0,NULL);		//设置音量大小
        if(vol==1000)mciSendString("setaudio mymusic volume to 1000",NULL,0,NULL);		//设置音量大小
        if(vol==1100)mciSendString("setaudio mymusic volume to 1100",NULL,0,NULL);		//设置音量大小
        if(vol==1200)mciSendString("setaudio mymusic volume to 1200",NULL,0,NULL);		//设置音量大小
        if(vol==1300)mciSendString("setaudio mymusic volume to 1300",NULL,0,NULL);		//设置音量大小
        if(vol==1400)mciSendString("setaudio mymusic volume to 1400",NULL,0,NULL);		//设置音量大小
        if(vol==1500)mciSendString("setaudio mymusic volume to 1500",NULL,0,NULL);		//设置音量大小
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
	cout << "                             |     设置——用W,A,S,D操控    | " << endl;
	cout << "                             |         释义栏宽度           | " << endl;
	cout << "                             ";
	if(V==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	printf("|             %3d              | \n",wk);
	SetConsoleTextAttribute(h,color);
	cout << "                             |         单词栏宽度           | " << endl;
	cout << "                             ";
	if(V==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	printf("|             %3d              | \n",ck);
	SetConsoleTextAttribute(h,color);
	cout << "                             |       单次最大背词量         | " << endl;
	cout << "                             ";
	if(V==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	printf("|             %3d              | \n",M);
	SetConsoleTextAttribute(h,color);
	cout << "                             |            音乐              | " << endl;
	cout << "                             ";
	if(V==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	printf("|");
	for(int i=1;i<=15;i++){
		if(vol>=i*100) printf("█");
		else printf("  ");
	}
	printf("| \n");
	SetConsoleTextAttribute(h,color);
	cout << "                             |            显示模式          |" << endl;
	cout << "                             ";
	if(V==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color+128);
	if(fc==1) printf("|          Full screen         | \n");
	else printf("|           Windowed           | \n");
	SetConsoleTextAttribute(h,color);
	cout << "                             |        按0返回并保存设置     | " << endl;
	cout << "                             |      请输入需要服务的序号    | " << endl;
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
	file.open("生词本.txt", ios::out | ios::app);
	if (file.is_open() == 1) {
		startTime = clock();
		char word[wk+1], trans[ck+1];
		cout << "请输入要写入错题本的单词：";
		char c;
		cin>>word;
		cout << "请输入单词的解释：";
		cin >> trans;
		file << word << " " <<trans<<endl;
		file.close();
		endTime = clock();
		cout << "写入成功，总共用时" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}
	else {
		cout << "打开文件失败" << endl;
		system("pause");
	}
	
}
void Recite::query_all() {
	clock_t startTime, endTime;
	startTime = clock();
	char buffer[WK];
	int number = 0; 
	CE();
	cout << "|" << setw(wk) << "单词";
	cout << "|" << setw(ck) << "翻译";
	cout << "|" << endl;
	CE();
	file.open("生词本.txt", ios::in | ios::app);
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
	cout << "总共有" << number << "条记录，总共用时"<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
	file.close();
}
void Recite::query_by_time() {
	file.open("背词历史.log", ios::in | ios::out | ios::app);
	if (file.is_open()) {
		string time;
		cout << "请输入要查询的历史记录的年月日，格式为某年-某月-某日：";
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
		file.open("历史记录.txt", ios::in | ios::out | ios::trunc);
		for (int j = 0; j < i; j++)
			file << word[j] << " " <<trans[j] << endl;
		file.close();
		query_history();
	}
	else {
		cout << "文件打开失败" << endl;
		return;
	}
}
void Recite::query_history() {
	clock_t startTime, endTime;
	startTime = clock();
	char buffer[WK];
	int number = 0;
	CE();
	cout << "|" << setw(wk) << "单词";
	cout << "|" << setw(ck) << "翻译";
	cout << "|" << endl;
	CE();
	file.open("历史记录.txt", ios::in | ios::app);
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
	cout << "总共有" << number << "条记录，总共用时" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	file.close();
}
void Recite::query_exact() {
	clock_t startTime, endTime;
	char buffer[WK];
	int i,number=0;
	startTime = clock();
	string word;
	cout << "请输入要查的单词：";
	cin >> word;
	CE();
	cout << "|" << setw(wk) << "单词";
	cout << "|" << setw(ck) << "翻译";
	cout << "|" << endl;
	CE();
	file.open("生词本.txt", ios::in);
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
		cout << "查询成功，一共有" << number << "条记录，用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		file.close();
}
int Recite::get_num() {
	file1.open("生词本.txt", ios::in);
	char buffer[WK];
	int number = 0;
	while (!file.eof()) {
		file.getline(buffer, WK);
		istringstream is(buffer);
		string s1, s2, s3;
		is >> s1 >> s2 >> s3;
		if (s1 != " "&&s2 != " "&&s3 != " ")
			number++;
	}
	file1.close();
	return number;
}
void Recite::delete_word() {
	query_all();
	string str;
	clock_t startTime, endTime;
	cout << "请输入想要删除的单词：";
	cin >> str;
	startTime = clock();
	file.open("生词本.txt",ios::in);
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
	file.open("生词本.txt", ios::out|ios::trunc);
	for (int j = 0; j < i; j++) {
		file << str1[j] << " " << str2[j] << " " << str3[j] << " " << endl;
	}
	file.close();
	endTime = clock();
	cout << "删除成功，用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}
void Recite::recite_word() {
	file.open("生词本.txt", ios::in|ios::out);  
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
		cout << "生词表为空，先加入生词再背诵吧" << endl;
		return;}
		cout <<"本次需要复习的单词数量是："<<number;
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
			if(i<=num*25/M) cout<<"█";
			else cout<<"  ";
		}			
		cout<<"|"<<endl<<" --------------------------------------------------"<<endl;
				cout << "英文单词：" << word[j]<< endl;
				cout << "请选择意思："<<endl;
				srand((unsigned)time(NULL));
				int cr=rand()%4;
				int r1,r2,r3,r4;
				if(number<4)
				{ 
					word[number]="SJJ";trans[number]="n.时佳骏";
					word[number+1]="ZYT";trans[number+1]="n.翟烨廷";
					word[number+2]="CBS";trans[number+2]="n.曹博深";
					word[number+3]="Astral Plane";trans[number+3]="n.星体层"; 
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
						cout << "正确！";
						num_of_recite[j]--;
						system("pause");
						system("cls");
						num++;
						if (num == number)
							sucessful = 1;
					}
					else {
						if(cr==0) cr=4;
						printf("错误，正确答案是：%c\n",cr+64);
						num_of_recite[j]++;
						system("pause");
						system("cls");
					}
				}
			}
		}
		endTime=clock();
		cout<<" --------------------------------------------------"<<endl<<"|";
		for(int i=1; i<=25; i++) cout<<"█";
		cout<<"|"<<endl<<" --------------------------------------------------"<<endl;
		cout << "恭喜你背完啦~~，用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		file.close();
		file.open("背词历史.log", ios::out|ios::app);
		SYSTEMTIME st = { 0 };
		GetLocalTime(&st);
		file << st.wYear << "-" << st.wMonth << "-" << st.wDay << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
		for (int j = 0; j < i; j++) {
			file << word[j] <<" " << trans[j] << endl;
		}
		file.close();
		file.open("生词本.txt", ios::in|ios::out);
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
		file.open("生词本.txt", ios::out | ios::trunc);
		for (int j = M; j < i; j++) {
			file << word[j] <<" " << trans[j] << endl;
		}
		file.close();
	}
	else {
		cout << "生词表为空，先加入生词再背诵吧" << endl;
		return;
	}
}
void print()
{
	system("cls");printf("\n\n\n\n\n"); 
	cout << "                              ______________________________  " << endl;
	cout << "                             |                              | " << endl;
	cout << "                             |      欢迎使用背词宝6.0       | " << endl;
	cout << "                             |          1.添加生词          | " << endl;
	cout << "                             |        2.显示所有生词        | " << endl;
	cout << "                             |          3.精确查词          | " << endl;
	cout << "                             |       4.删除生词表中的词     | " << endl;
	cout << "                             |           5.背生词           | " << endl;
	cout << "                             |        6.查询背诵历史        | " << endl;
	cout << "                             |          7.更新日志          | " << endl;
	cout << "                             |         8.开发者模式         | " << endl;
	cout << "                             |            9.设置            | " << endl;
	cout << "                             |            0.退出            | " << endl;
	cout << "                             |      请输入需要服务的序号    | " << endl;
	cout << "                              ------------------------------  " << endl;
}
void Recite::update_log() {
	cout << "2018-9-4 背词宝1.0 诞生" << endl;
	cout << "2020-2-15 背词宝2.0 诞生 美化了界面 重构了代码" << endl;
	cout << "2021-1-19 背词宝3.0诞生 修复了重词bug 捆绑了图标"<<endl;
	cout << "2021-1-21 背词宝3.5诞生 修复了词库过小bug"<<endl;
	cout << "2021-1-22 背词宝4.0诞生 增加了开发者模式"<<endl;
	cout << "2021-1-23 背词宝4.5诞生 增加了设置"<<endl;
	cout << "2021-1-24 背词宝5.0诞生 增加了进度条"<<endl;
	cout << "2021-1-25 背词宝5.1诞生 修复了文件错误bug"<<endl;
	cout << "2021-1-26 背词宝5.2诞生 增加了BGM"<<endl;
	cout << "2021-1-27 背词宝5.3诞生 优化了设置界面"<<endl;
	cout << "2021-1-28 背词宝5.4诞生 扩展了音量"<<endl;
	cout << "2021-1-29 背词宝5.5诞生 修复了设置bug"<<endl;
	cout << "2021-2-2 背词宝5.6诞生 修改了项目结构"<<endl;
	cout << "2021-2-3 背词宝5.7诞生 增加了全屏"<<endl;
	cout << "2021-2-5 背词宝5.8诞生 修复了新版控制台fc的bug"<<endl;
    cout << "2021-2-14 背词宝5.9诞生 增加了设置ini"<<endl;
    cout << "2021-2-17 背词宝6.0诞生 修复了二次启动bug"<<endl;
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
    printf("\n输入数字，可将显示主题改为选择的样式\n");
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
				cout << "对应数字的服务不存在，请重新输入" << endl;
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
	color=188;M=100;
	read();
	if(fc==1) full_screen();
	if(fc==0) windowed();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
	Recite r;
	mciSendString("open m.mp3 alias mymusic", NULL, 0, NULL);	// 打开音乐
	mciSendString("setaudio mymusic volume to 600",NULL,0,NULL);		//设置音量大小
	mciSendString("play mymusic", NULL, 0, NULL);						//开始音乐
	mciSendString("play mymusic repeat", NULL, 0, NULL);				//循环播放
	r.run();
    return 0;
}
