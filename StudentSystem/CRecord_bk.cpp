// CRecord_bk.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CRecord_bk.h"
#include"CInfoFile.h"


// CRecord_bk

IMPLEMENT_DYNCREATE(CRecord_bk, CFormView)

CRecord_bk::CRecord_bk()
	: CFormView(IDD_REPORT_BK)
{

}

CRecord_bk::~CRecord_bk()
{
}

void CRecord_bk::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, _combo);
}

BEGIN_MESSAGE_MAP(CRecord_bk, CFormView)
//	ON_BN_CLICKED(IDC_BUTTON1, &CRecord_bk::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON12, &CRecord_bk::OnBnClickedButton12)
END_MESSAGE_MAP()


// CRecord_bk 诊断

#ifdef _DEBUG
void CRecord_bk::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CRecord_bk::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CRecord_bk 消息处理程序

void CRecord_bk::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | 0x00000020 | LVS_EX_GRIDLINES);
	CString str[] = { TEXT("书号"),TEXT("书名"),TEXT("类别"),TEXT("出版社"),TEXT("出版日期"),TEXT("价格"),TEXT("状态") };
	for (int i = 0; i < 7; i++)
	{
		m_list.InsertColumn(i, str[i], LVCFMT_LEFT, 100);
	}
	CInfoFile file;
	file.ReadDocline_bk();
	int i = 0;
	for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
	{
		CString str;
		str.Format(_T("%d"), it->id);
		m_list.InsertItem(i, str);
		int column = 1;
		m_list.SetItemText(i, column++, (CString)it->name.c_str());
		m_list.SetItemText(i, column++, (CString)it->type.c_str());
		m_list.SetItemText(i, column++, (CString)it->publisher.c_str());
		m_list.SetItemText(i, column++, (CString)it->date.c_str());
		str.Format(_T("%d"), it->price);
		m_list.SetItemText(i, column++, str);
		m_list.SetItemText(i, column++, (CString)it->state.c_str());
		i++;

		
	}
	_combo.AddString(TEXT("升序"));
	_combo.AddString(TEXT("降序"));
	_combo.SetCurSel(0);
}

	void CRecord_bk::OnBnClickedButton12()
	{
		m_list.DeleteAllItems();
		CInfoFile file;
		file.ReadDocline_bk();
		int select = _combo.GetCurSel();
		if (select == 1)
		{
			file.lb.sort(sortBkIdDesc);
		}
		else
		{
			file.lb.sort(sortBkIdAsc);
		}
		int i = 0;
		for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
		{
			CString str;
			str.Format(_T("%d"), it->id);
			m_list.InsertItem(i, str);
			m_list.SetItemText(i, 1, (CString)it->name.c_str());
			m_list.SetItemText(i, 2, (CString)it->type.c_str());
			m_list.SetItemText(i, 3, (CString)it->publisher.c_str());
			m_list.SetItemText(i, 4, (CString)it->date.c_str());
			str.Format(_T("%d"), it->price);
			m_list.SetItemText(i, 5, str);
			m_list.SetItemText(i, 6, (CString)it->state.c_str());
			i++;

		}
	}
