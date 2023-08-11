#include "stdafx.h"
#include "CInfoFile.h"

CInfoFile::CInfoFile()
{
}

CInfoFile::~CInfoFile()
{
}

void CInfoFile::ReadRemember(int & Rname, int & Rpwd)
{
	ifstream ifs; //创建文件输入对象
	ifs.open(_F_REM);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	Rname = _ttoi(CString(buf));	//将char* 转换为CString

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	Rpwd = _ttoi(CString(buf));	//将char* 转换为CString

	ifs.close();	//关闭文件
}

void CInfoFile::WriteRemember(int & Rname, int & Rpwd)
{
	ofstream ofs; //创建文件输出对象
	ofs.open(_F_REM); //打开文件

	ofs << Rname << endl;	//name写入文件
	ofs << Rpwd << endl;	//pwd写入文件

	ofs.close();	//关闭文件
}

//读取登录信息
void CInfoFile::ReadLogin(CString &name, CString &pwd)
{
	ifstream ifs; //创建文件输入对象
	ifs.open(_F_LOGIN);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	name = CString(buf);	//将char* 转换为CString

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	pwd = CString(buf);	//将char* 转换为CString

	ifs.close();	//关闭文件
}
//修改密码
void CInfoFile::WritePwd(char* name, char* pwd)
{
	ofstream ofs; //创建文件输出对象
	ofs.open(_F_LOGIN); //打开文件

	ofs << name << endl;	//name写入文件
	ofs << pwd << endl;	//pwd写入文件

	ofs.close();	//关闭文件
}
//读取商品的信息
void CInfoFile::ReadDocline()
{
	ifstream ifs(_F_STOCK); //输入方式打开文件

	char buf[1024] = { 0 };
	num = 0;	//初始化学生数量为0
	ls.clear();
	//取出表头
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof())	//没到文件结尾
	{
		stu tmp;

		ifs.getline(buf, sizeof(buf));	//读取一行
		num++;	//学生数量加一

		//AfxMessageBox(CString(buf));
		char *sst = strtok(buf, "|");	//以"|"分隔
		if (sst != NULL)
		{
			tmp.id = atoi(sst);	//学号
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.name = sst;	

		sst = strtok(NULL, "|");
		tmp.age = atoi(sst);

		sst = strtok(NULL, "|");
		tmp.grade = atoi(sst);

		ls.push_back(tmp);	//放在链表的后面
	}

	ifs.close();	//关闭文件
}

void CInfoFile::ReadDocline_bk()
{
	ifstream ifs(_F_STOCK_BK); //输入方式打开文件

	char buf[1024] = { 0 };
	num = 0;	//初始化学生数量为0
	lb.clear();
	//取出表头
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof())	//没到文件结尾
	{
		bk tmp;

		ifs.getline(buf, sizeof(buf));	//读取一行
		bk_num++;	//学生数量加一

		//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|");	//以"|"分隔
		if (sst != NULL)
		{
			tmp.id = atoi(sst);	//学号
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.name = sst;

		sst = strtok(NULL, "|");
		tmp.type = sst;

		sst = strtok(NULL, "|");
		tmp.publisher = sst;

		sst = strtok(NULL, "|");
		tmp.date = sst;

		sst = strtok(NULL, "|");
		tmp.price = atoi(sst);

		sst = strtok(NULL, "|");
		tmp.state = sst;


		lb.push_back(tmp);	//放在链表的后面
	}

	ifs.close();	//关闭文件
}

//商品写入文件
void CInfoFile::WriteDocline()
{
	ofstream ofs(_F_STOCK); //输出方式打开文件
	string bt = "学号 | 姓名 | 电话号码 | ";

	if (ls.size() > 0)
	{
		ofs << bt << endl;	//写入表头

		//通过迭代器取出链表内容，写入文件，以"|"分割，结尾加换行
		for (list<stu>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			ofs << it->id << "|";
			ofs << it->name << "|";
			ofs << it->age << "|";
			ofs << it->grade << endl;
		}
	}
	ofs.close();
}

void CInfoFile::WriteDocline_bk()
{
	ofstream ofs(_F_STOCK_BK); //输出方式打开文件
	string bt = "书籍ID|书籍名称|书记种类|出版社|出版日期|价格|状态";

	if (lb.size() > 0)
	{
		ofs << bt << endl;	//写入表头

		//通过迭代器取出链表内容，写入文件，以"|"分割，结尾加换行
		for (list<bk>::iterator it = lb.begin(); it != lb.end(); it++)
		{
			ofs << it->id << "|";
			ofs << it->name << "|";
			ofs << it->type << "|";
			ofs << it->price << "|";
			ofs << it->publisher << "|";
			ofs << it->date << "|";
			ofs << it->state << endl;
		}
	}
	ofs.close();
}
//添加新商品
void CInfoFile::Addline( int id,CString name, int _grade, int _age)
{
	stu tmp;

	if (ls.size() > 0)
	{
		//商品名称，库存，价格有效
		if (!name.IsEmpty() && _grade > 0 && _age > 0)
		{
			tmp.id = id;	//id自动加1
			CStringA str;
			str = name;					//CString 转CStringA
			tmp.name = str.GetBuffer();//CString 转为char *, 商品名称
			tmp.grade = _grade;			//库存
			tmp.age = _age;		//价格

			ls.push_back(tmp);			//放在链表的后面
		}
	}
}

void CInfoFile::Addline_bk(long long int _id, CString _name, CString _type, int _price, CString _publisher, CString _date, CString _state)
{
	bk tmp;

	if (lb.size() > 0)
	{
		//商品名称，库存，价格有效
		if (!_name.IsEmpty() &&!_type.IsEmpty()&&!_publisher.IsEmpty() &&!_state.IsEmpty() && _price > 0)
		{
			tmp.id = _id;	//id自动加1
			CStringA str1,str2,str3,str4,str5;
			str1 = _name;str2 = _type;str3 = _publisher;str4 = _date;str5 = _state;					//CString 转CStringA
			tmp.name = str1.GetBuffer();//CString 转为char *
			tmp.type = str2.GetBuffer();		//库存
			tmp.price = _price;		//价格
			tmp.publisher = str3.GetBuffer();
			tmp.date = str4.GetBuffer();
			tmp.state = str5.GetBuffer();
			lb.push_back(tmp);			//放在链表的后面
		}
	}
}
bool sortStuIdAsc(const stu& m1, const stu& m2)
{
	return m1.id < m2.id;
}
bool sortStuIdDesc(const stu& m1, const stu& m2)
{
	return m1.id > m2.id;
}
bool sortStuGradeAsc(const stu& m1, const stu& m2)
{
	return m1.grade < m2.grade;
}
bool sortStuGradeDesc(const stu& m1, const stu& m2)
{
	return m1.grade > m2.grade;
}
bool operator == (const stu &m1, const stu&m2)
{
	if (m1.id == m2.id)
		return true;
	return false;
}
bool sortBkIdAsc(const bk& m1, const bk& m2)
{
	return m1.id < m2.id;
}
bool sortBkIdDesc(const bk& m1, const bk& m2)
{
	return m1.id > m2.id;
}
bool operator ==(const bk& m1, const bk& m2)
{
	if (m1.id == m2.id)
		return true;
	return false;
}