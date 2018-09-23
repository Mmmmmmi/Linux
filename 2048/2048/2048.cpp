#include<stdio.h>
#include<conio.h>                                 //直接接收输入字符的函数头文件  
#include<time.h>                                   //产生随机数的函数头文件  
//#include<windows.h>                                 //清屏函数头文件 
#define random(x) (rand()%x)                          //宏定义一个产生随机数的函数 
#include<iostream>
#include<fstream>
using namespace std;
int sum = 0, MAX = 0, Max = 0, c[4][4] = { 1 };
int main() {                                                                    //主函数 
	void choose(int b[4][4]);
	void print(int b[4][4]);
	void add_w(int b[4][4]);
	void add_s(int b[4][4]);
	void add_a(int b[4][4]);
	void add_d(int b[4][4]);
	int game_end(int b[4][4]);
	void max_number(int b[4][4]);
	void random_produce_number(int b[4][4]);                             //随机位置产生随机数字 
	int save_score(int n);
	void print_array();
	int a[4][4] = { 0 };
	save_score(sum);
	choose(a);
	return 0;
}
void choose(int b[4][4]) {                                             //功能选择菜单 
	int save_score(int n);
	void print(int b[4][4]);
	void print_array();
	void random_produce_number(int b[4][4]);
	char i;
	int j = 1;
	random_produce_number(b);                                             //开局产生一个随机数 
	c[0][0] = 1;
	random_produce_number(b);
	while (j == 1) {
		cout << "\t\t    请选择功能：" << "\n\n\t\t    1.开始游戏\n\n\t\t    2.排行榜\n\n\t\t    3.退出程序\n" << endl;
		i = _getch();
		switch (i)
		{
		case '1':system("cls"); print(b); break;
		case '2':system("cls"); print_array(); break;
		case '3':system("cls"); j = 0; cout << "\n\n\n\n\n\n\t\t\t按任意键结束游戏！！！\n\n\n\n\n\n\n"; break;
		default:system("cls"); break;
		}
	}

}
void print(int b[4][4]) {                                       //输出界面 
	void add_w(int b[4][4]);
	void add_s(int b[4][4]);
	void add_a(int b[4][4]);
	void add_d(int b[4][4]);
	int game_end(int b[4][4]);
	void max_number(int b[4][4]);
	void random_produce_number(int b[4][4]);                             //随机位置产生随机数字 
	int save_score(int n);
	int i, j;
	char in, a;                      //接收   上下左右操作   w s a d;
	while (game_end(b)) {
		cout << "\n\n\t操作方法：" << " 'w'  :  ↑     's'  :  ↓\n\n\t           'a'  ： ←     'd'  :  →\n\n" << endl;
		cout << "\t总成绩为：" << sum << "\t  最高成绩为：" << Max << endl;
		cout << "\t---------------------------------" << endl;
		for (i = 0; i < 4; i++) {                                    //输出二维数组 
			for (j = 0; j < 4; j++) {
				if (b[i][j] == 0) cout << "\t|  ";
				else cout << "\t|  " << b[i][j];
			}
			cout << "\t|" << endl;
			cout << "\t|\t|\t|\t|\t|" << endl;
			cout << "\t|\t|\t|\t|\t|" << endl;
			cout << "\t---------------------------------" << endl;
		}
		in = _getch();                                 //接收移动指令
		if (in == 'w') { system("cls"); add_w(b); max_number(b); random_produce_number(b); }
		else {
			if (in == 's') { system("cls"); add_s(b); max_number(b); random_produce_number(b); }
			else {
				if (in == 'a') { system("cls"); add_a(b); max_number(b); random_produce_number(b); }
				else {
					if (in == 'd') { system("cls"); add_d(b); max_number(b); random_produce_number(b); }
					else { system("cls"); }
				}
			}
		}
	}
	//system("cls");
	a = 'a';                                         //赋初值让界面不中断，不然会有一下停顿; 
	while (a != 32) {
		system("cls");
		cout << "\n\t总成绩为：" << sum << "\t  最高成绩为：" << Max << endl;
		cout << "\t---------------------------------" << endl;
		for (i = 0; i < 4; i++) {                                    //输出二维数组 
			for (j = 0; j < 4; j++) {
				if (b[i][j] == 0) cout << "\t|  ";
				else cout << "\t|  " << b[i][j];
			}
			cout << "\t|" << endl;
			cout << "\t|\t|\t|\t|\t|" << endl;
			cout << "\t|\t|\t|\t|\t|" << endl;
			cout << "\t---------------------------------" << endl;
		}
		cout << "\n\t------------GAME OVER-------------\n";
		cout << "\n\t-------请按空格进入选择菜单-------\n";
		a = _getch();
	}
	save_score(sum);
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			b[i][j] = 0;
		}
	}
	sum = 0;
	random_produce_number(b);                                             //开局产生一个随机数 
	c[0][0] = 1;
	random_produce_number(b);
}
void add_w(int b[4][4]) {                                       //接收向上指令操作相加 
	int i, j, k;
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 4; i++) {                                          //数字移动 
			for (j = 3; j > 0; j--) {
				//cout<<"ok"<<endl;                                   //测试函数是否被调用成功 
				if (b[j - 1][i] == 0) {
					//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
					b[j - 1][i] = b[j][i];
					b[j][i] = 0;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {                                     //数字相加 
		for (j = 1; j < 4; j++) {
			//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
			if (b[j - 1][i] == b[j][i]) {
				b[j - 1][i] = b[j - 1][i] + b[j][i];
				sum = b[j - 1][i] + sum;                         //计分 
				b[j][i] = 0;
			}
		}
	}
	for (i = 0; i < 4; i++) {                                          //数字移动 
		for (j = 3; j > 0; j--) {
			//cout<<"ok"<<endl;                                   //测试函数是否被调用成功 
			if (b[j - 1][i] == 0) {
				//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
				b[j - 1][i] = b[j][i];
				b[j][i] = 0;
			}
		}
	}
	/* for(i = 0;i < 4;i++){                                               //对数组输出
	for(j = 0;j < 4;j++){
	cout<<"\t"<<b[i][j];
	}
	cout<<"\n";
	}*/
}
void add_s(int b[4][4]) {                                             //接收向下指令操作相加  
	int i, j, k;
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 4; i++) {                                   //数字移动 
			for (j = 0; j < 3; j++) {
				//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
				if (b[j + 1][i] == 0) {
					//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
					b[j + 1][i] = b[j][i];
					b[j][i] = 0;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {                                  //数字相加 
		for (j = 3; j > 0; j--) {
			//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
			if (b[j - 1][i] == b[j][i]) {
				b[j][i] = b[j - 1][i] + b[j][i];
				sum = b[j][i] + sum;                          //计分 
				b[j - 1][i] = 0;
			}
		}
	}
	for (i = 0; i < 4; i++) {                                   //数字移动 
		for (j = 0; j < 3; j++) {
			//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
			if (b[j + 1][i] == 0) {
				//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
				b[j + 1][i] = b[j][i];
				b[j][i] = 0;
			}
		}
	}
}
void add_a(int b[4][4]) {                                             //接收向左指令操作相加  
	int i, j, k;
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 4; i++) {                                   //数字移动 
			for (j = 3; j > 0; j--) {
				//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
				if (b[i][j - 1] == 0) {
					//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
					b[i][j - 1] = b[i][j];
					b[i][j] = 0;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {                                  //数字相加 
		for (j = 1; j <4; j++) {
			//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
			if (b[i][j - 1] == b[i][j]) {
				b[i][j - 1] = b[i][j - 1] + b[i][j];
				sum = b[i][j - 1] + sum;                           //计分 
				b[i][j] = 0;
			}
		}
	}
	for (i = 0; i < 4; i++) {                                   //数字移动 
		for (j = 3; j > 0; j--) {
			//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
			if (b[i][j - 1] == 0) {
				//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
				b[i][j - 1] = b[i][j];
				b[i][j] = 0;
			}
		}
	}
}
void add_d(int b[4][4]) {                                             //接收向右指令操作相加 
	int i, j, k;
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 4; i++) {                                   //数字移动 
			for (j = 0; j < 3; j++) {
				//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
				if (b[i][j + 1] == 0) {
					//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
					b[i][j + 1] = b[i][j];
					b[i][j] = 0;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {                                  //数字相加 
		for (j = 3; j > 0; j--) {
			//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
			if (b[i][j] == b[i][j - 1]) {
				b[i][j] = b[i][j - 1] + b[i][j];
				sum = b[i][j] + sum;                        //计分 
				b[i][j - 1] = 0;
			}
		}
	}
	for (i = 0; i < 4; i++) {                                   //数字移动 
		for (j = 0; j < 3; j++) {
			//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
			if (b[i][j + 1] == 0) {
				//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
				b[i][j + 1] = b[i][j];
				b[i][j] = 0;
			}
		}
	}
}
void random_produce_number(int b[4][4]) {                             //产生随机的数字 
	int m = 0, i, j, k;
	srand((int)time(0));
	//cout<<"ok"<<endl;                                   //测试函数是否被调用成功
	/*for(i = 0;i < 4;i++){                                               //对数组输出
	for(j = 0;j < 4;j++){
	cout<<"\t"<<b[i][j];
	}
	cout<<"\n";
	}*/
	for (i = 0; i < 4; i++) {
		//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
		for (j = 0; j < 4; j++) {
			//cout<<"ok"<<endl;                               //测试函数是否被调用成功 
			//cout<<c[i][j];
			if (b[i][j] != c[i][j]) {
				//cout<<"ok"<<endl;                             //测试函数是否被调用成功
				m = 1; break;
				//cout<<"m";    
			}
		}
	}
	//cout<<"m = "<<m<<endl;	 
	if (m == 1) {
		while (1) {
			i = random(4);                                                      //产生随机数 
			j = random(4);
			//cout<<i<<j;                                           //判断产生的随机数是多少 
			if (b[i][j] == 0) {
				//cout<<"ok"<<endl;                                   //测试函数是否被调用成功 
				if (MAX <= 1024) {
					k = random(3);                                     //随机输出的数字 
					if (k == 0 || k == 1)
						b[i][j] = 2;
					else b[i][j] = 4;
				}
				if (MAX > 1024) {
					k = random(3);                                     //随机输出的数字 
					if (k == 0 || k == 1)
						b[i][j] = 4;
					else b[i][j] = 2;
				}
				//cout<<b[i][j];
				for (i = 0; i < 4; i++) {
					for (j = 0; j < 4; j++) {
						c[i][j] = b[i][j];
					}
				}
				/*for(i = 0;i < 4;i++){                                               //对数组输出
				for(j = 0;j < 4;j++){
				cout<<"\t"<<c[i][j];
				}
				cout<<"\n";
				}*/
				return;
			}
		}
	}
}
int game_end(int b[4][4]) {                                         //判断游戏结束 
	void add_w(int b[4][4]);
	void add_s(int b[4][4]);
	void add_a(int b[4][4]);
	void add_d(int b[4][4]);
	int i, j, k, e[4][4];
	k = sum;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			e[i][j] = b[i][j];
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (b[i][j] == 0) { return 1; }
		}
	}
	add_w(e);
	add_s(e);
	add_a(e);
	add_d(e);
	sum = k;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (e[i][j] != b[i][j]) {
				return 1;
			}
		}
	}
	return 0;
}
void max_number(int b[4][4]) {                                      //合成的最大数 
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			if (b[i][j] > MAX)
				MAX = b[i][j];
		}
}
int save_score(int n) {
	int i, j, k, s[11] = { 0 };
	s[10] = n;
	ifstream fin("array.txt", ios::in);
	if (!fin) {
		cout << "Cannot open input file.\n";
		//return 1;
	}
	for (i = 0; i < 10; i++) {
		fin >> s[i];
		//cout<<"\t\t"<<s[i]<<endl;
	}
	fin.close();
	for (i = 0; i < 10; i++) {                                                         //   6   5  4   2  
		for (j = 0; j < 10 - i; j++) {
			if (s[j + 1] > s[j]) {
				{k = s[j]; s[j] = s[j + 1]; s[j + 1] = k; }
			}
		}
	}
	Max = s[0];
	ofstream fout("array.txt", ios::out);
	if (!fout) {
		cout << "Cannot open output file.\n";
		return 1;
	}
	for (i = 0; i < 10; i++) {
		fout << s[i] << endl;
		//cout<<"\t\t"<<s[i]<<endl;
	}
	fout.close();
	for (i = 0; i < 10; i++) {
		fin >> s[i];
		//cout<<"\t\t"<<s[i]<<endl;
	}
	fin.close();
	return 0;
}
void print_array() {
	int i, j, s[10] = { 0 };
	cout << "\n\n\n\t-------------排行榜---------------\n\n";
	ifstream fin("array.txt", ios::in);
	for (i = 0; i < 10; i++) {
		fin >> s[i];
		cout << "\t\t      " << s[i] << endl;
	}
	cout << "\n\t----------------------------------\n\n";
	fin.close();
}