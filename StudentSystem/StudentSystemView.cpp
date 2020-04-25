
// StudentSystemView.cpp: CStudentSystemView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudentSystem.h"
#endif

#include "StudentSystemDoc.h"
#include "StudentSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentSystemView

IMPLEMENT_DYNCREATE(CStudentSystemView, CView)

BEGIN_MESSAGE_MAP(CStudentSystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStudentSystemView 构造/析构

CStudentSystemView::CStudentSystemView() noexcept
{
	// TODO: 在此处添加构造代码

}

CStudentSystemView::~CStudentSystemView()
{
}

BOOL CStudentSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CStudentSystemView 绘图

void CStudentSystemView::OnDraw(CDC* /*pDC*/)
{
	CStudentSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CStudentSystemView 打印

BOOL CStudentSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudentSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CStudentSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CStudentSystemView 诊断

#ifdef _DEBUG
void CStudentSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentSystemDoc* CStudentSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentSystemDoc)));
	return (CStudentSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentSystemView 消息处理程序
