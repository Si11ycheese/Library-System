// CSelectView.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CSelectView.h"

#include"MainFrm.h"

// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	_tree=&GetTreeCtrl();
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON_SILLYCHEESE_1);
	_imageIist.Create(50, 50, ILC_COLOR24,1,1);
	_imageIist.Add(icon);
	_tree->SetImageList(&_imageIist, TVSIL_NORMAL);
	_tree->InsertItem(TEXT("个人信息"), 0, 0, NULL);
	_tree->InsertItem(TEXT("管理学生信息"), 0, 0, NULL);
	_tree->InsertItem(TEXT("查看所有学生"), 0, 0, NULL);
	_tree->InsertItem(TEXT("添加学生"), 0, 0, NULL);
	_tree->InsertItem(TEXT("查看所有书籍"), 0, 0, NULL);
	_tree->InsertItem(TEXT("管理所有书籍"), 0, 0, NULL);
	_tree->InsertItem(TEXT("添加书籍"), 0, 0, NULL);
	_tree->InsertItem(TEXT("借书"), 0, 0, NULL);
	_tree->InsertItem(TEXT("还书"), 0, 0, NULL);
}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	HTREEITEM item = _tree->GetSelectedItem();
	CString str = _tree->GetItemText(item);

	if (str == "个人信息")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_A, (LPARAM)NM_A, 0);
	}
	else if (str == "管理学生信息")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_B, (LPARAM)NM_B, 0);
	}
	else if (str == "查看所有学生")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_C, (LPARAM)(0x0400 + 102), 0);
	}
	else if (str == "添加学生")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_D, (LPARAM)NM_D, 0);
	}
	else if (str == "查看所有书籍")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_E, (LPARAM)NM_E, 0);
	}
	else if (str == "管理所有书籍")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_F, (LPARAM)NM_F, 0);
	}
	else if (str == "添加书籍")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_G, (LPARAM)NM_G, 0);
	}
	else if (str == "借书")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_H, (LPARAM)NM_H, 0);
	}
	else if (str == "还书")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_I, (LPARAM)NM_I, 0);
	}
}
