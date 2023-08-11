#pragma once
#include <afxext.h>
#include "resource.h" 

class CAddDlg : public CFormView
{
	DECLARE_DYNCREATE(CAddDlg)

protected:
	CAddDlg();
public:
	virtual ~CAddDlg();

	enum { IDD = IDD_DIALOG_ADD };//IDD_DISPLAYVIEW模态窗口的ID

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
private:
	CString _id;
	CString _name;
	CString _age;
	CString _grade;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CStatic add_pic;
	virtual void OnInitialUpdate();
};
