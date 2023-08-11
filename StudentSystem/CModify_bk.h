#pragma once
#include <afxext.h>
#include "resource.h" 
// CModify_bk 窗体视图

class CModify_bk : public CFormView
{
	DECLARE_DYNCREATE(CModify_bk)

protected:
	CModify_bk();           // 动态创建所使用的受保护的构造函数
	virtual ~CModify_bk();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MODIFY_BK };
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
	
	
	CString _id;
	CString _name;
	CString _type;
	CString _publisher;
	CString _date;
	CString _price;
	CString _state;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	virtual void OnInitialUpdate();
	CComboBox _combo;
};


