#pragma once
#include <afxext.h>
#include "resource.h" 


// CRecord_bk 窗体视图

class CRecord_bk : public CFormView
{
	DECLARE_DYNCREATE(CRecord_bk)

protected:
	CRecord_bk();           // 动态创建所使用的受保护的构造函数
	virtual ~CRecord_bk();

public:
	enum { IDD = IDD_REPORT_BK };
#ifdef AFX_DESIGN_TIME
	
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	CListCtrl m_list;
	CComboBox _combo;
	afx_msg void OnBnClickedButton12();
};


