#pragma once

#include <afxext.h>
#include "resource.h" 

class CModifyDlg : public CFormView
{
	DECLARE_DYNCREATE(CModifyDlg)

protected:
	CModifyDlg();
public:
	virtual ~CModifyDlg();

	enum {
		IDD = IDD_DIALOG_MODIFY
	};//IDD_DISPLAYVIEW模态窗口的ID

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
private:
	CComboBox _combo;
public:
	afx_msg void OnCbnSelchangeCombo1();
private:
	CString _id;
	CString _name;
	CString _age;
	CString _grade;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};