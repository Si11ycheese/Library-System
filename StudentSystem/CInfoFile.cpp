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
	ifstream ifs; //�����ļ��������
	ifs.open(_F_REM);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	Rname = _ttoi(CString(buf));	//��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	Rpwd = _ttoi(CString(buf));	//��char* ת��ΪCString

	ifs.close();	//�ر��ļ�
}

void CInfoFile::WriteRemember(int & Rname, int & Rpwd)
{
	ofstream ofs; //�����ļ��������
	ofs.open(_F_REM); //���ļ�

	ofs << Rname << endl;	//nameд���ļ�
	ofs << Rpwd << endl;	//pwdд���ļ�

	ofs.close();	//�ر��ļ�
}

//��ȡ��¼��Ϣ
void CInfoFile::ReadLogin(CString &name, CString &pwd)
{
	ifstream ifs; //�����ļ��������
	ifs.open(_F_LOGIN);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	name = CString(buf);	//��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	pwd = CString(buf);	//��char* ת��ΪCString

	ifs.close();	//�ر��ļ�
}
//�޸�����
void CInfoFile::WritePwd(char* name, char* pwd)
{
	ofstream ofs; //�����ļ��������
	ofs.open(_F_LOGIN); //���ļ�

	ofs << name << endl;	//nameд���ļ�
	ofs << pwd << endl;	//pwdд���ļ�

	ofs.close();	//�ر��ļ�
}
//��ȡ��Ʒ����Ϣ
void CInfoFile::ReadDocline()
{
	ifstream ifs(_F_STOCK); //���뷽ʽ���ļ�

	char buf[1024] = { 0 };
	num = 0;	//��ʼ��ѧ������Ϊ0
	ls.clear();
	//ȡ����ͷ
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof())	//û���ļ���β
	{
		stu tmp;

		ifs.getline(buf, sizeof(buf));	//��ȡһ��
		num++;	//ѧ��������һ

		//AfxMessageBox(CString(buf));
		char *sst = strtok(buf, "|");	//��"|"�ָ�
		if (sst != NULL)
		{
			tmp.id = atoi(sst);	//ѧ��
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

		ls.push_back(tmp);	//��������ĺ���
	}

	ifs.close();	//�ر��ļ�
}

void CInfoFile::ReadDocline_bk()
{
	ifstream ifs(_F_STOCK_BK); //���뷽ʽ���ļ�

	char buf[1024] = { 0 };
	num = 0;	//��ʼ��ѧ������Ϊ0
	lb.clear();
	//ȡ����ͷ
	ifs.getline(buf, sizeof(buf));

	while (!ifs.eof())	//û���ļ���β
	{
		bk tmp;

		ifs.getline(buf, sizeof(buf));	//��ȡһ��
		bk_num++;	//ѧ��������һ

		//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|");	//��"|"�ָ�
		if (sst != NULL)
		{
			tmp.id = atoi(sst);	//ѧ��
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


		lb.push_back(tmp);	//��������ĺ���
	}

	ifs.close();	//�ر��ļ�
}

//��Ʒд���ļ�
void CInfoFile::WriteDocline()
{
	ofstream ofs(_F_STOCK); //�����ʽ���ļ�
	string bt = "ѧ�� | ���� | �绰���� | ";

	if (ls.size() > 0)
	{
		ofs << bt << endl;	//д���ͷ

		//ͨ��������ȡ���������ݣ�д���ļ�����"|"�ָ��β�ӻ���
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
	ofstream ofs(_F_STOCK_BK); //�����ʽ���ļ�
	string bt = "�鼮ID|�鼮����|�������|������|��������|�۸�|״̬";

	if (lb.size() > 0)
	{
		ofs << bt << endl;	//д���ͷ

		//ͨ��������ȡ���������ݣ�д���ļ�����"|"�ָ��β�ӻ���
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
//�������Ʒ
void CInfoFile::Addline( int id,CString name, int _grade, int _age)
{
	stu tmp;

	if (ls.size() > 0)
	{
		//��Ʒ���ƣ���棬�۸���Ч
		if (!name.IsEmpty() && _grade > 0 && _age > 0)
		{
			tmp.id = id;	//id�Զ���1
			CStringA str;
			str = name;					//CString תCStringA
			tmp.name = str.GetBuffer();//CString תΪchar *, ��Ʒ����
			tmp.grade = _grade;			//���
			tmp.age = _age;		//�۸�

			ls.push_back(tmp);			//��������ĺ���
		}
	}
}

void CInfoFile::Addline_bk(long long int _id, CString _name, CString _type, int _price, CString _publisher, CString _date, CString _state)
{
	bk tmp;

	if (lb.size() > 0)
	{
		//��Ʒ���ƣ���棬�۸���Ч
		if (!_name.IsEmpty() &&!_type.IsEmpty()&&!_publisher.IsEmpty() &&!_state.IsEmpty() && _price > 0)
		{
			tmp.id = _id;	//id�Զ���1
			CStringA str1,str2,str3,str4,str5;
			str1 = _name;str2 = _type;str3 = _publisher;str4 = _date;str5 = _state;					//CString תCStringA
			tmp.name = str1.GetBuffer();//CString תΪchar *
			tmp.type = str2.GetBuffer();		//���
			tmp.price = _price;		//�۸�
			tmp.publisher = str3.GetBuffer();
			tmp.date = str4.GetBuffer();
			tmp.state = str5.GetBuffer();
			lb.push_back(tmp);			//��������ĺ���
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