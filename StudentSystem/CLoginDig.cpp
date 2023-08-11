// CLoginDig.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CLoginDig.h"
#include "afxdialogex.h"

#include"CInfoFile.h"

// CLoginDig 对话框

IMPLEMENT_DYNAMIC(CLoginDig, CDialogEx)

CLoginDig::CLoginDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, _userName(_T(""))
	, _passWord(_T(""))
{

}

CLoginDig::~CLoginDig()
{
}

void CLoginDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, _userName);
	DDX_Text(pDX, IDC_EDIT2, _passWord);
	DDX_Control(pDX, IDC_CHECK1, _remName);
	DDX_Control(pDX, IDC_CHECK2, _remPwd);
	DDX_Control(pDX, IDC_PIC, m_pic);
}


BEGIN_MESSAGE_MAP(CLoginDig, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDig::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDig::OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHECK2, &CLoginDig::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &CLoginDig::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CLoginDig 消息处理程序


void CLoginDig::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	if (_userName.IsEmpty() || _passWord.IsEmpty())
	{
		MessageBox(TEXT("输入的内容不能为空"));
		return;
	}

	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	if (name == _userName)
	{
		if (pwd == _passWord)
		{
			CDialog::OnCancel();
		}
		else
		{
			MessageBox(TEXT("密码错误"));
		}
	}
	else
	{
		MessageBox(TEXT("用户名错误"));
	}

}


BOOL CLoginDig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CInfoFile file;
	int Rname, Rpwd;
	file.ReadRemember(Rname, Rpwd);
	((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(Rname);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(Rpwd);
	
	CString name,pwd;
	file.ReadLogin(name, pwd);
	if (Rname == 1)
	{
		_userName = name;
		if (Rpwd == 1)
		{
			_passWord = pwd;
		}
	}	
	UpdateData(false);


	//设置静态控件窗口风格为位图居中显示
	m_pic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

//静态控件设置bitmap
	m_pic.SetBitmap(HBMP(TEXT("./1.bmp"), 300, 250));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE


	

}


void CLoginDig::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CLoginDig::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	UpdateData(TRUE);

	if (_userName.IsEmpty() || _passWord.IsEmpty())
	{
		MessageBox(TEXT("输入的内容不能为空"));
		return;
	}

	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	if (name == _userName)
	{
		if (pwd == _passWord)
		{
			CDialog::OnCancel();
		}
		else
		{
			MessageBox(TEXT("密码错误"));
		}
	}
	else
	{
		MessageBox(TEXT("用户名错误"));
	}

	//CDialogEx::OnOK();
}


void CLoginDig::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	exit(0);
	//CDialogEx::OnClose();
}


void CLoginDig::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	CInfoFile file;
	int state = 0;
	int state1 = ((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck();
	if (state1 == 1)
	{
		state = 1;
	}
	((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(state);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(state1);
	file.WriteRemember(state, state1);
}


void CLoginDig::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码

	CInfoFile file;
	int state = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	int state1 = 0;
	((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(state);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(state1);
	file.WriteRemember(state, state1);
}
