
// MainFrm.cpp: CMainFrame 类的实现
//

#include "stdafx.h"
#include "StudentSystem.h"

#include "MainFrm.h"
#include "CInfoFile.h"

#include"CSelectView.h"
#include"CDisplayView.h"
#include"CUserDlg.h"
#include"CModifyDlg.h"
#include"CReport.h"
#include"CAddDlg.h"
#include"CRecord_bk.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"CModify_bk.h"
#include"CADD_BK.h"
#include"CBorrow.h"
#include"CReturn.h"
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()

	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)
	ON_MESSAGE(NM_F, OnMyChange)
	ON_MESSAGE(NM_G, OnMyChange)
	ON_MESSAGE(NM_H, OnMyChange)
	ON_MESSAGE(NM_I, OnMyChange)

	ON_COMMAND(ID_32775, &CMainFrame::On32775)
	ON_COMMAND(ID_32771, &CMainFrame::On32771)
	ON_COMMAND(ID_32772, &CMainFrame::On32772)
	ON_COMMAND(ID_32773, &CMainFrame::On32773)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//设置图标
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_SILLYCHEESE_2));
	//设置右侧标题
	SetTitle(TEXT("管理员模式-By Sillycheese ,Port Signal"));
	//设置窗口大小
	MoveWindow(0, 0, 800, 500);
	//设置居中
	CenterWindow();

	/*CInfoFile file;
	CString name, password;
	file.ReadLogin(name, password);
	MessageBox(name);
	MessageBox(password);
	*/

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//拆分成一行两列
	_splitter.CreateStatic(this, 1, 2);

	//分配空间
	_splitter.CreateView(0, 0,RUNTIME_CLASS (CSelectView), CSize(200, 500), pContext);
	_splitter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(600, 500), pContext);

	return true;//代表自己拆分
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

LRESULT CMainFrame::OnMyChange(WPARAM wparam, LPARAM lparam)
{
	CCreateContext _context;
	if (wparam == NM_A)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0,1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(600, 500), &_context);
		CUserDlg *pNewView = (CUserDlg *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_B)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CModifyDlg);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CModifyDlg), CSize(600, 500), &_context);
		CModifyDlg *pNewView = (CModifyDlg *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_C)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CReport);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CReport), CSize(600, 500), &_context);
		CReport *pNewView = (CReport *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_D)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CAddDlg);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CAddDlg), CSize(600, 500), &_context);
		CAddDlg *pNewView = (CAddDlg *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_E)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CRecord_bk);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView*)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CRecord_bk), CSize(600, 500), &_context);
		CRecord_bk* pNewView = (CRecord_bk*)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);

		//*_context.m_pNewViewClass = RUNTIME_CLASS(CINFO_BK);
			//_context.m_pCurrentFrame = this;
			//_context.m_pLastView = (CFormView*)_splitter.GetPane(0, 1);
			//_splitter.DeleteView(0, 1);
			//_splitter.CreateView(0, 1, RUNTIME_CLASS(CINFO_BK), CSize(600, 500), &_context);
			//CINFO_BK* pNewView = (CINFO_BK*)_splitter.GetPane(0, 1);
			//_splitter.RecalcLayout();
			//pNewView->OnInitialUpdate();
			//_splitter.SetActivePane(0, 1);
		

	}
	else if (wparam == NM_F)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CModify_bk);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView*)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CModify_bk), CSize(600, 500), &_context);
		CModify_bk* pNewView = (CModify_bk*)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_G)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CADD_BK);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView*)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CADD_BK), CSize(600, 500), &_context);
		CADD_BK* pNewView = (CADD_BK*)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_H)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CBorrow);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView*)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CBorrow), CSize(600, 500), &_context);
		CBorrow* pNewView = (CBorrow*)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_I)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CReturn);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView*)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CReturn), CSize(600, 500), &_context);
		CReturn* pNewView = (CReturn*)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	return 0;
}


void CMainFrame::On32775()
{
	// TODO: 在此添加命令处理程序代码
	exit(0);
}


void CMainFrame::On32771()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_A, (LPARAM)NM_A, 0);
}


void CMainFrame::On32772()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_B, (LPARAM)NM_B, 0);
}


void CMainFrame::On32773()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_C, (LPARAM)NM_C, 0);
}


void CMainFrame::On32774()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_D, (LPARAM)NM_D, 0);
}

void CMainFrame::On32776()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_E, (LPARAM)NM_E, 0);
}
void CMainFrame::On32777()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_F, (LPARAM)NM_F, 0);
}
void CMainFrame::On32778()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_G, (LPARAM)NM_G, 0);
}
void CMainFrame::On32779()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_H, (LPARAM)NM_H, 0);
}
