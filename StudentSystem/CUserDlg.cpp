#include "stdafx.h"
#include "CUserDlg.h"

#include"CInfoFile.h"

// CDisplayView
IMPLEMENT_DYNCREATE(CUserDlg, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CUserDlg::CUserDlg() : CFormView(IDD_DIALOG_USER)
, _name(_T(""))
, _user(_T(""))
, _newPwd(_T(""))
, _surePwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);
	DDX_Text(pDX, IDC_EDIT1, _name);
	DDX_Text(pDX, IDC_EDIT2, _user);
	DDX_Text(pDX, IDC_EDIT3, _newPwd);
	DDX_Text(pDX, IDC_EDIT4, _surePwd);
}

void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	_user = TEXT("管理员");
	CString pwd;
	CInfoFile file;
	file.ReadLogin(_name, pwd);
	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (_newPwd.IsEmpty())
	{
		MessageBox(TEXT("新密码为空"));
		return;
	}
	if (_surePwd.IsEmpty())
	{
		MessageBox(TEXT("确认密码为空"));
		return;
	}
	CString name, pwd;
	CInfoFile file;
	file.ReadLogin(name, pwd);
	if (_newPwd == pwd)
	{
		MessageBox(TEXT("新密码与原密码一致"));
		return;
	}
	if (_newPwd != _surePwd)
	{
		MessageBox(TEXT("新密码与确认密码不一致"));
		return;
	}
	file.WritePwd(((CStringA)name).GetBuffer(), ((CStringA)_newPwd).GetBuffer());
	MessageBox(TEXT("密码修改成功"));
	_newPwd.Empty();
	_surePwd.Empty();
	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	_newPwd.Empty();
	_surePwd.Empty();
	UpdateData(FALSE);
	MessageBox(TEXT("已将你输入的密码清空"));
}
