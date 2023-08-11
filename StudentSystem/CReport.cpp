#include "stdafx.h"
#include "CReport.h"

#include"CInfoFile.h"

// CReport
IMPLEMENT_DYNCREATE(CReport, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CReport::CReport() : CFormView(IDD_REPORT) {

}

CReport::~CReport()
{
}

BEGIN_MESSAGE_MAP(CReport, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CReport::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CReport::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CReport::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CReport::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CReport::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CReport::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);
	DDX_Control(pDX, IDC_LIST3, _list);
	DDX_Control(pDX, IDC_COMBO1, _combox);
}


void CReport::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	_list.SetExtendedStyle(_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CString str[] = { TEXT("学号"),TEXT("姓名"),TEXT("手机号"),TEXT("密码") };
	for (int i = 0; i < 4; i++)
	{
		_list.InsertColumn(i, str[i], LVCFMT_LEFT, 100);
	}
	CInfoFile file;
	file.ReadDocline();
	int i = 0;
	for (list<stu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{		
		CString str;
		str.Format(L"%d", (it->id));
		_list.InsertItem(i,str);
		str= CString(it->name.c_str());
		_list.SetItemText(i, 1, str);
		str.Format(_T("%d"), it->age);
		_list.SetItemText(i, 2, str);
		str.Format(_T("%d"), it->grade);
		_list.SetItemText(i, 3, str);
		i++;
	}
	
	_combox.AddString(TEXT("升序"));
	_combox.AddString(TEXT("降序"));
	_combox.SetCurSel(0);
}


void CReport::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	_list.DeleteAllItems();
	CInfoFile file;
	file.ReadDocline();
	int select = _combox.GetCurSel();
	if (select == 1)
	{
		file.ls.sort(sortStuIdDesc);
	}
	else
	{
		file.ls.sort(sortStuIdAsc);
	}
	int i = 0;
	for (list<stu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		CString str;
		str.Format(_T("%d"), (it->id));
		_list.InsertItem(i, str);
		str = CString(it->name.c_str());
		_list.SetItemText(i, 1, str);
		str.Format(_T("%d"), it->age);
		_list.SetItemText(i, 2, str);
		str.Format(_T("%d"), it->grade);
		_list.SetItemText(i, 3, str);
		i++;
	}

}


void CReport::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	_list.DeleteAllItems();
	CInfoFile file;
	file.ReadDocline();
	int select=_combox.GetCurSel();
	if (select == 1)
	{
		file.ls.sort(sortStuGradeDesc);
	}
	else
	{
		file.ls.sort(sortStuGradeAsc);
	}
	int i = 0;
	for (list<stu>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		CString str;
		str.Format(_T("%d"), (it->id));
		_list.InsertItem(i, str);
		str = CString(it->name.c_str());
		_list.SetItemText(i, 1, str);
		str.Format(_T("%d"), it->age);
		_list.SetItemText(i, 2, str);
		str.Format(_T("%d"), it->grade);
		_list.SetItemText(i, 3, str);
		i++;
	}
}


void CReport::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

}
