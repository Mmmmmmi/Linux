#include<stdio.h>
#include<conio.h>                                 //ֱ�ӽ��������ַ��ĺ���ͷ�ļ�  
#include<time.h>                                   //����������ĺ���ͷ�ļ�  
//#include<windows.h>                                 //��������ͷ�ļ� 
#define random(x) (rand()%x)                          //�궨��һ������������ĺ��� 
#include<iostream>
#include<fstream>
using namespace std;
int sum = 0, MAX = 0, Max = 0, c[4][4] = { 1 };
int main() {                                                                    //������ 
	void choose(int b[4][4]);
	void print(int b[4][4]);
	void add_w(int b[4][4]);
	void add_s(int b[4][4]);
	void add_a(int b[4][4]);
	void add_d(int b[4][4]);
	int game_end(int b[4][4]);
	void max_number(int b[4][4]);
	void random_produce_number(int b[4][4]);                             //���λ�ò���������� 
	int save_score(int n);
	void print_array();
	int a[4][4] = { 0 };
	save_score(sum);
	choose(a);
	return 0;
}
void choose(int b[4][4]) {                                             //����ѡ��˵� 
	int save_score(int n);
	void print(int b[4][4]);
	void print_array();
	void random_produce_number(int b[4][4]);
	char i;
	int j = 1;
	random_produce_number(b);                                             //���ֲ���һ������� 
	c[0][0] = 1;
	random_produce_number(b);
	while (j == 1) {
		cout << "\t\t    ��ѡ���ܣ�" << "\n\n\t\t    1.��ʼ��Ϸ\n\n\t\t    2.���а�\n\n\t\t    3.�˳�����\n" << endl;
		i = _getch();
		switch (i)
		{
		case '1':system("cls"); print(b); break;
		case '2':system("cls"); print_array(); break;
		case '3':system("cls"); j = 0; cout << "\n\n\n\n\n\n\t\t\t�������������Ϸ������\n\n\n\n\n\n\n"; break;
		default:system("cls"); break;
		}
	}

}
void print(int b[4][4]) {                                       //������� 
	void add_w(int b[4][4]);
	void add_s(int b[4][4]);
	void add_a(int b[4][4]);
	void add_d(int b[4][4]);
	int game_end(int b[4][4]);
	void max_number(int b[4][4]);
	void random_produce_number(int b[4][4]);                             //���λ�ò���������� 
	int save_score(int n);
	int i, j;
	char in, a;                      //����   �������Ҳ���   w s a d;
	while (game_end(b)) {
		cout << "\n\n\t����������" << " 'w'  :  ��     's'  :  ��\n\n\t           'a'  �� ��     'd'  :  ��\n\n" << endl;
		cout << "\t�ܳɼ�Ϊ��" << sum << "\t  ��߳ɼ�Ϊ��" << Max << endl;
		cout << "\t---------------------------------" << endl;
		for (i = 0; i < 4; i++) {                                    //�����ά���� 
			for (j = 0; j < 4; j++) {
				if (b[i][j] == 0) cout << "\t|  ";
				else cout << "\t|  " << b[i][j];
			}
			cout << "\t|" << endl;
			cout << "\t|\t|\t|\t|\t|" << endl;
			cout << "\t|\t|\t|\t|\t|" << endl;
			cout << "\t---------------------------------" << endl;
		}
		in = _getch();                                 //�����ƶ�ָ��
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
	a = 'a';                                         //����ֵ�ý��治�жϣ���Ȼ����һ��ͣ��; 
	while (a != 32) {
		system("cls");
		cout << "\n\t�ܳɼ�Ϊ��" << sum << "\t  ��߳ɼ�Ϊ��" << Max << endl;
		cout << "\t---------------------------------" << endl;
		for (i = 0; i < 4; i++) {                                    //�����ά���� 
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
		cout << "\n\t-------�밴�ո����ѡ��˵�-------\n";
		a = _getch();
	}
	save_score(sum);
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			b[i][j] = 0;
		}
	}
	sum = 0;
	random_produce_number(b);                                             //���ֲ���һ������� 
	c[0][0] = 1;
	random_produce_number(b);
}
void add_w(int b[4][4]) {                                       //��������ָ�������� 
	int i, j, k;
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 4; i++) {                                          //�����ƶ� 
			for (j = 3; j > 0; j--) {
				//cout<<"ok"<<endl;                                   //���Ժ����Ƿ񱻵��óɹ� 
				if (b[j - 1][i] == 0) {
					//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
					b[j - 1][i] = b[j][i];
					b[j][i] = 0;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {                                     //������� 
		for (j = 1; j < 4; j++) {
			//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
			if (b[j - 1][i] == b[j][i]) {
				b[j - 1][i] = b[j - 1][i] + b[j][i];
				sum = b[j - 1][i] + sum;                         //�Ʒ� 
				b[j][i] = 0;
			}
		}
	}
	for (i = 0; i < 4; i++) {                                          //�����ƶ� 
		for (j = 3; j > 0; j--) {
			//cout<<"ok"<<endl;                                   //���Ժ����Ƿ񱻵��óɹ� 
			if (b[j - 1][i] == 0) {
				//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
				b[j - 1][i] = b[j][i];
				b[j][i] = 0;
			}
		}
	}
	/* for(i = 0;i < 4;i++){                                               //���������
	for(j = 0;j < 4;j++){
	cout<<"\t"<<b[i][j];
	}
	cout<<"\n";
	}*/
}
void add_s(int b[4][4]) {                                             //��������ָ��������  
	int i, j, k;
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 4; i++) {                                   //�����ƶ� 
			for (j = 0; j < 3; j++) {
				//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
				if (b[j + 1][i] == 0) {
					//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
					b[j + 1][i] = b[j][i];
					b[j][i] = 0;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {                                  //������� 
		for (j = 3; j > 0; j--) {
			//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
			if (b[j - 1][i] == b[j][i]) {
				b[j][i] = b[j - 1][i] + b[j][i];
				sum = b[j][i] + sum;                          //�Ʒ� 
				b[j - 1][i] = 0;
			}
		}
	}
	for (i = 0; i < 4; i++) {                                   //�����ƶ� 
		for (j = 0; j < 3; j++) {
			//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
			if (b[j + 1][i] == 0) {
				//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
				b[j + 1][i] = b[j][i];
				b[j][i] = 0;
			}
		}
	}
}
void add_a(int b[4][4]) {                                             //��������ָ��������  
	int i, j, k;
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 4; i++) {                                   //�����ƶ� 
			for (j = 3; j > 0; j--) {
				//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
				if (b[i][j - 1] == 0) {
					//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
					b[i][j - 1] = b[i][j];
					b[i][j] = 0;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {                                  //������� 
		for (j = 1; j <4; j++) {
			//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
			if (b[i][j - 1] == b[i][j]) {
				b[i][j - 1] = b[i][j - 1] + b[i][j];
				sum = b[i][j - 1] + sum;                           //�Ʒ� 
				b[i][j] = 0;
			}
		}
	}
	for (i = 0; i < 4; i++) {                                   //�����ƶ� 
		for (j = 3; j > 0; j--) {
			//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
			if (b[i][j - 1] == 0) {
				//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
				b[i][j - 1] = b[i][j];
				b[i][j] = 0;
			}
		}
	}
}
void add_d(int b[4][4]) {                                             //��������ָ�������� 
	int i, j, k;
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 4; i++) {                                   //�����ƶ� 
			for (j = 0; j < 3; j++) {
				//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
				if (b[i][j + 1] == 0) {
					//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
					b[i][j + 1] = b[i][j];
					b[i][j] = 0;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {                                  //������� 
		for (j = 3; j > 0; j--) {
			//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
			if (b[i][j] == b[i][j - 1]) {
				b[i][j] = b[i][j - 1] + b[i][j];
				sum = b[i][j] + sum;                        //�Ʒ� 
				b[i][j - 1] = 0;
			}
		}
	}
	for (i = 0; i < 4; i++) {                                   //�����ƶ� 
		for (j = 0; j < 3; j++) {
			//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
			if (b[i][j + 1] == 0) {
				//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
				b[i][j + 1] = b[i][j];
				b[i][j] = 0;
			}
		}
	}
}
void random_produce_number(int b[4][4]) {                             //������������� 
	int m = 0, i, j, k;
	srand((int)time(0));
	//cout<<"ok"<<endl;                                   //���Ժ����Ƿ񱻵��óɹ�
	/*for(i = 0;i < 4;i++){                                               //���������
	for(j = 0;j < 4;j++){
	cout<<"\t"<<b[i][j];
	}
	cout<<"\n";
	}*/
	for (i = 0; i < 4; i++) {
		//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
		for (j = 0; j < 4; j++) {
			//cout<<"ok"<<endl;                               //���Ժ����Ƿ񱻵��óɹ� 
			//cout<<c[i][j];
			if (b[i][j] != c[i][j]) {
				//cout<<"ok"<<endl;                             //���Ժ����Ƿ񱻵��óɹ�
				m = 1; break;
				//cout<<"m";    
			}
		}
	}
	//cout<<"m = "<<m<<endl;	 
	if (m == 1) {
		while (1) {
			i = random(4);                                                      //��������� 
			j = random(4);
			//cout<<i<<j;                                           //�жϲ�����������Ƕ��� 
			if (b[i][j] == 0) {
				//cout<<"ok"<<endl;                                   //���Ժ����Ƿ񱻵��óɹ� 
				if (MAX <= 1024) {
					k = random(3);                                     //������������ 
					if (k == 0 || k == 1)
						b[i][j] = 2;
					else b[i][j] = 4;
				}
				if (MAX > 1024) {
					k = random(3);                                     //������������ 
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
				/*for(i = 0;i < 4;i++){                                               //���������
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
int game_end(int b[4][4]) {                                         //�ж���Ϸ���� 
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
void max_number(int b[4][4]) {                                      //�ϳɵ������ 
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
	cout << "\n\n\n\t-------------���а�---------------\n\n";
	ifstream fin("array.txt", ios::in);
	for (i = 0; i < 10; i++) {
		fin >> s[i];
		cout << "\t\t      " << s[i] << endl;
	}
	cout << "\n\t----------------------------------\n\n";
	fin.close();
}