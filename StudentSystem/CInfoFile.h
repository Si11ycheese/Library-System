#pragma once
#pragma warning(disable : 4996)

#include <list>
#include <fstream>
#include <iostream>
#include <string>

#define _F_LOGIN "./login.ini"
#define _F_STOCK "./stock.txt"
#define _F_STOCK_BK "./stock_bk.txt"
#define _F_REM "./remeber.txt"

using namespace std;

struct stu
{
	long int id; //ѧ��
	string name; //����
	long int age; //�绰��
	long int grade; //����
};

struct bk
{
	
		long long int id;				//��Ʒid
		string name;	//��Ʒ��
		string type;
		int price;			//��Ʒ�۸�
		string publisher; //������
		string date;      //��������
		string state;     //״̬
	
};

struct rc
{
	string user_ID;
	string user_name;
	string book_ID;
	string book_name;
	string type;
	string borrow_time;
	string borrow_date;
	string gap_money;
};
//ѧ��������
bool sortStuIdAsc(const stu& m1, const stu& m2);
bool sortStuIdDesc(const stu& m1, const stu& m2);
bool sortStuGradeAsc(const stu& m1, const stu& m2);
bool sortStuGradeDesc(const stu& m1, const stu& m2);
bool operator == (const stu &m1, const stu&m2);
//�鼮������
bool sortBkIdAsc(const bk& m1, const bk& m2);
bool sortBkIdDesc(const bk& m1, const bk& m2);
bool operator ==(const bk& m1, const bk& m2);
class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//��ȡ�Ƿ��ס
	void ReadRemember(int &Rname, int &Rpwd);

	//д���Ƿ��ס
	void WriteRemember(int &Rname, int &Rpwd);

	//��ȡ��¼��Ϣ
	void ReadLogin(CString &name, CString &pwd);

	//�޸�����
	void WritePwd(char* name, char* pwd);

	//��ȡѧ������
	void ReadDocline();

	//ѧ��д���ļ�
	void WriteDocline();

	//�����ѧ��
	void Addline(int id, CString name, int _grade, int _age);

	list<stu> ls;	//�洢ѧ������
	int num;		//������¼ѧ������
	list<bk>lb;     //�洢�鼮����
	int bk_num;     //��¼�鼮����

	//��ȡ�鼮����
	void ReadDocline_bk();

	//�鼮д���ļ�
	void WriteDocline_bk();

	//�����ѧ��
	void Addline_bk(long long int _id, CString _name, CString _type, int _price, CString _publisher, CString _date, CString state);
};