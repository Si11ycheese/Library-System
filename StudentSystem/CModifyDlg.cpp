#include "stdafx.h"
#include "CModifyDlg.h"

#include"CInfoFile.h"

// CDisplayView
IMPLEMENT_DYNCREATE(CModifyDlg, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CModifyDlg::CModifyDlg() : CFormView(IDD_DIALOG_MODIFY)
, _id(_T(""))
, _name(_T(""))
, _age(_T(""))
, _grade(_T(""))
{

}

CModifyDlg::~CModifyDlg()
{
}

BEGIN_MESSAGE_MAP(CModifyDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CModifyDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CModifyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CModifyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CModifyDlg::OnBnClickedButton5)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CModifyDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CModifyDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);

	DDX_Control(pDX, IDC_COMBO1, _combo);
	DDX_Text(pDX, IDC_EDIT1, _id);
	DDX_Text(pDX, IDC_EDIT2, _name);
	DDX_Text(pDX, IDC_EDIT5, _age);
	DDX_Text(pDX, IDC_EDIT6, _grade);
}


void CModifyDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CInfoFile file;
	file.ReadDocline();
	for (list<stu>::iterator it=file.ls.begin();it!=file.ls.end();it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		_combo.AddString(str);
	}

	//_combo.SetCurSel(0);
	//OnCbnSelchangeCombo1();
}


void CModifyDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	int index = _combo.GetCurSel();
	CString id;
	_combo.GetLBText(index, id);
	CInfoFile file;
	file.ReadDocline();
	for (list<stu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		_id = str;
		if (str == id)
		{
			_name =CString(it->name.c_str());
			CString str;
			str.Format(_T("%d"), it->age);
			_age = str;
			str.Format(_T("%d"), it->grade);
			_grade = str;
			break;
		}
	}
	UpdateData(FALSE);
}


void CModifyDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = _combo.GetCurSel();
	if (index == -1)
	{
		MessageBox(TEXT("修改失败，您未选中任何人"));
		return;
	}
	CString id;
	_combo.GetLBText(index, id);
	CInfoFile file;
	file.ReadDocline();
	UpdateData(TRUE);
	for (list<stu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		_id = str;
		if (str == id)
		{
			CStringA s_name;
			s_name = _name;
			it->name = s_name.GetBuffer();
			it->age = _ttoi(_age);
			it->grade = _ttoi(_grade);
			break;
		}
	}
	UpdateData(FALSE);
	file.WriteDocline();
	MessageBox(TEXT("修改成功"));
}


void CModifyDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = _combo.GetCurSel();
	if (index == -1)
	{
		MessageBox(TEXT("请选中一个人"));
		return;
	}
	CString id;
	_combo.GetLBText(index, id);
	CInfoFile file;
	file.ReadDocline();
	for (list<stu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		_id = str;
		if (str == id)
		{
			_name = CString(it->name.c_str());
			CString str;
			str.Format(_T("%d"), it->age);
			_age = str;
			str.Format(_T("%d"), it->grade);
			_grade = str;
			break;
		}
	}
	UpdateData(FALSE);
	MessageBox(TEXT("已取消修改"));
}


void CModifyDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = _combo.GetCurSel();
	if (index == -1)
	{
		MessageBox(TEXT("删除失败，您未选中任何人"));
		return;
	}
	CString id;
	_combo.GetLBText(index, id);
	CInfoFile file;
	file.ReadDocline();
	UpdateData(TRUE);	
	for (list<stu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);		
		if (str == id)
		{
			file.ls.remove(*it);
			_id = "";
			_name = "";
			_age = "";
			_grade = "";
			_combo.DeleteString(_combo.GetCurSel());
			_combo.SetCurSel(-1);
			break;
		}
	}
	UpdateData(FALSE);
	file.WriteDocline();
	MessageBox(TEXT("删除成功"));

}
