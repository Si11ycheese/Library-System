#pragma once

#include <afxext.h>
#include "resource.h" 

// CBorrow 窗体视图

class CBorrow : public CFormView
{
	DECLARE_DYNCREATE(CBorrow)

protected:
	CBorrow();           // 动态创建所使用的受保护的构造函数
	virtual ~CBorrow();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BORROW };
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
	CComboBox borrow_combo;
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
	CString _state;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString m_sellInfo;
	CStatic borrow_pic;
};


