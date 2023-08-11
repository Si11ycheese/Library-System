#pragma once

#include <afxext.h>
#include "resource.h" 

// CADD_BK 窗体视图

class CADD_BK : public CFormView
{
	DECLARE_DYNCREATE(CADD_BK)

protected:
	CADD_BK();           // 动态创建所使用的受保护的构造函数
	virtual ~CADD_BK();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_BK };
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
	CStatic bk_pic;
	CString _id;
	CString _name;
	CString _type;
	CString _publisher;
	CString _date;
	CString _price;
	CString _state;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


