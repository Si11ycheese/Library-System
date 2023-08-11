// CModify_bk.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CModify_bk.h"
#include"CInfoFile.h"


// CModify_bk

IMPLEMENT_DYNCREATE(CModify_bk, CFormView)

CModify_bk::CModify_bk()
	: CFormView(IDD_DIALOG_MODIFY_BK)
	, _id(_T(""))
	, _name(_T(""))
	, _type(_T(""))
	, _publisher(_T(""))
	, _date(_T(""))
	, _price(_T(""))
	, _state(_T(""))
{

}

CModify_bk::~CModify_bk()
{
}

void CModify_bk::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, _id);
	DDX_Text(pDX, IDC_EDIT2, _name);
	DDX_Text(pDX, IDC_EDIT3, _type);
	DDX_Text(pDX, IDC_EDIT7, _publisher);
	DDX_Text(pDX, IDC_EDIT8, _date);
	DDX_Text(pDX, IDC_EDIT9, _price);
	DDX_Text(pDX, IDC_EDIT10, _state);
	DDX_Control(pDX, IDC_COMBO1, _combo);
}

BEGIN_MESSAGE_MAP(CModify_bk, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CModify_bk::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CModify_bk::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CModify_bk::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CModify_bk::OnBnClickedButton3)
END_MESSAGE_MAP()


// CModify_bk 诊断

#ifdef _DEBUG
void CModify_bk::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CModify_bk::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CModify_bk 消息处理程序


void CModify_bk::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = _combo.GetCurSel();
	CString id;
	_combo.GetLBText(index, id);
	CInfoFile file;
	file.ReadDocline_bk();
	for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		_id = str;
		if (str == id)
		{
			_name = CString(it->name.c_str());
			_type = CString(it->type.c_str());
			_publisher = CString(it->publisher.c_str());
			_date = CString(it->date.c_str());
			CString str;
			str.Format(_T("%d"), it->price);
			_price = str;
			_state = CString(it->state.c_str());
			break;
		}
	}
	UpdateData(FALSE);
}


void CModify_bk::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	int index = _combo.GetCurSel();
	if (index == -1)
	{
		MessageBox(TEXT("修改失败，您未选中任何书籍"));
		return;
	}
	CString id;
	_combo.GetLBText(index, id);
	CInfoFile file;
	file.ReadDocline_bk();
	UpdateData(TRUE);
	for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		_id = str;
		if (str == id)
		{
			_name = CString(it->name.c_str());
			_type = CString(it->type.c_str());
			_publisher = CString(it->publisher.c_str());
			_date = CString(it->date.c_str());
			CString str;
			str.Format(_T("%d"), it->price);
			_price = str;
			_state = CString(it->state.c_str());
			break;
		}
	}
	UpdateData(FALSE);
	file.WriteDocline_bk();
	MessageBox(TEXT("修改成功"));
}


void CModify_bk::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	int index = _combo.GetCurSel();
	if (index == -1)
	{
		MessageBox(TEXT("请选中一本书"));
		return;
	}
	CString id;
	_combo.GetLBText(index, id);
	CInfoFile file;
	file.ReadDocline_bk();
	for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		_id = str;
		if (str == id)
		{
			_name = CString(it->name.c_str());
			_type = CString(it->type.c_str());
			_publisher = CString(it->publisher.c_str());
			_date = CString(it->date.c_str());
			CString str;
			str.Format(_T("%d"), it->price);
			_price = str;
			_state = CString(it->state.c_str());
			break;
		}
	}
	UpdateData(FALSE);
	MessageBox(TEXT("已取消修改"));
}


void CModify_bk::OnBnClickedButton3()
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
	file.ReadDocline_bk();
	UpdateData(TRUE);
	for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		if (str == id)
		{
			file.lb.remove(*it);
			_id = "";
			_name = "";
			_type = "";
			_publisher = "";
			_date = "";
			_price = "";
			_state = "";
			_combo.DeleteString(_combo.GetCurSel());
			_combo.SetCurSel(-1);
			break;
		}
	}
	UpdateData(FALSE);
	file.WriteDocline_bk();
	MessageBox(TEXT("删除成功"));

}


void CModify_bk::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	CInfoFile file;
	file.ReadDocline_bk();
	for (list<bk>::iterator it = file.lb.begin();it != file.lb.end();it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		_combo.AddString(str);
	}


}
