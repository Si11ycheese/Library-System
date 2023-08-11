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
	long int id; //学号
	string name; //姓名
	long int age; //电话号
	long int grade; //密码
};

struct bk
{
	
		long long int id;				//商品id
		string name;	//商品名
		string type;
		int price;			//商品价格
		string publisher; //出版社
		string date;      //出版日期
		string state;     //状态
	
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
//学生做排名
bool sortStuIdAsc(const stu& m1, const stu& m2);
bool sortStuIdDesc(const stu& m1, const stu& m2);
bool sortStuGradeAsc(const stu& m1, const stu& m2);
bool sortStuGradeDesc(const stu& m1, const stu& m2);
bool operator == (const stu &m1, const stu&m2);
//书籍做排名
bool sortBkIdAsc(const bk& m1, const bk& m2);
bool sortBkIdDesc(const bk& m1, const bk& m2);
bool operator ==(const bk& m1, const bk& m2);
class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//读取是否记住
	void ReadRemember(int &Rname, int &Rpwd);

	//写入是否记住
	void WriteRemember(int &Rname, int &Rpwd);

	//读取登录信息
	void ReadLogin(CString &name, CString &pwd);

	//修改密码
	void WritePwd(char* name, char* pwd);

	//读取学生数据
	void ReadDocline();

	//学生写入文件
	void WriteDocline();

	//添加新学生
	void Addline(int id, CString name, int _grade, int _age);

	list<stu> ls;	//存储学生容器
	int num;		//用来记录学生个数
	list<bk>lb;     //存储书籍容器
	int bk_num;     //记录书籍个数

	//读取书籍数据
	void ReadDocline_bk();

	//书籍写入文件
	void WriteDocline_bk();

	//添加新学生
	void Addline_bk(long long int _id, CString _name, CString _type, int _price, CString _publisher, CString _date, CString state);
};