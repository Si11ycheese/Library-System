#pragma once
#include <afxext.h>
#include "resource.h" 

// CReturn 窗体视图

class CReturn : public CFormView
{
	DECLARE_DYNCREATE(CReturn)

protected:
	CReturn();           // 动态创建所使用的受保护的构造函数
	virtual ~CReturn();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RETURN };
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
	CComboBox return_combo;
	CString _state;
	CString ReturnInfo;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCombo1();
	virtual void OnInitialUpdate();
	CStatic return_pic;
};


