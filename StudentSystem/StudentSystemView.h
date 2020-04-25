
// StudentSystemView.h: CStudentSystemView 类的接口
//

#pragma once


class CStudentSystemView : public CView
{
protected: // 仅从序列化创建
	CStudentSystemView() noexcept;
	DECLARE_DYNCREATE(CStudentSystemView)

// 特性
public:
	CStudentSystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CStudentSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // StudentSystemView.cpp 中的调试版本
inline CStudentSystemDoc* CStudentSystemView::GetDocument() const
   { return reinterpret_cast<CStudentSystemDoc*>(m_pDocument); }
#endif

