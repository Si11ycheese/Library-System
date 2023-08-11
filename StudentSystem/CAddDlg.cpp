#include "stdafx.h"
#include "CAddDlg.h"

#include"CInfoFile.h"

// CAddDlg
IMPLEMENT_DYNCREATE(CAddDlg, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CAddDlg::CAddDlg() : CFormView(IDD_DIALOG_ADD), _id(_T(""))
, _name(_T(""))
, _age(_T(""))
, _grade(_T(""))
{

}

CAddDlg::~CAddDlg()
{
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddDlg::OnBnClickedButton4)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);
	DDX_Text(pDX, IDC_EDIT1, _id);
	DDX_Text(pDX, IDC_EDIT2, _name);
	DDX_Text(pDX, IDC_EDIT5, _age);
	DDX_Text(pDX, IDC_EDIT6, _grade);
	DDX_Control(pDX, IDC_PIC_ADD, add_pic);
}


void CAddDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (_id.IsEmpty() || _name.IsEmpty() || _age.IsEmpty() || _grade.IsEmpty())
	{
		MessageBox(TEXT("学生信息不能为空"));
		return;
	}
	CInfoFile file;
	file.ReadDocline();
	for (list<stu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		if (str == _id)
		{
			CString str;
			str.Format(TEXT("学号%d已存在"), i);
			MessageBox(str);
			return;
		}
	}

	int id, age, grade;
	id = _ttoi(_id);
	age = _ttoi(_age);
	grade = _ttoi(_grade);
	file.Addline(id,_name, grade, age);
	file.WriteDocline();
	MessageBox(TEXT("添加成功"));
}


void CAddDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	_id = "";
	_name = "";
	_age = "";
	_grade = "";
	UpdateData(FALSE);
}


void CAddDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
//设置静态控件窗口风格为位图居中显示
	add_pic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

//静态控件设置bitmap
	add_pic.SetBitmap(HBMP(TEXT("./1.bmp"), 300, 250));

}
