// CReturn.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CReturn.h"
#include"CInfoFile.h"

// CReturn

IMPLEMENT_DYNCREATE(CReturn, CFormView)

CReturn::CReturn()
	: CFormView(IDD_DIALOG_RETURN)
	, _state(_T(""))
	, ReturnInfo(_T(""))
{

}

CReturn::~CReturn()
{
}

void CReturn::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, return_combo);
	DDX_Text(pDX, IDC_EDIT2, _state);
	DDX_Text(pDX, IDC_EDIT1, ReturnInfo);
	DDX_Control(pDX, IDC_RETURN_PIC, return_pic);
}

BEGIN_MESSAGE_MAP(CReturn, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CReturn::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CReturn::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CReturn::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CReturn 诊断

#ifdef _DEBUG
void CReturn::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CReturn::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CReturn 消息处理程序


void CReturn::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取控件上的内容，更新到对应关联的变量中
	UpdateData(TRUE);


	CString type;
	//获取当前选中项
	int index = return_combo.GetCurSel();
	//获取组合框当前内容
	return_combo.GetLBText(index, type);
	CString str;
	str.Format(_T("书名：%s \r\n：状态：%s \r\n"), type, _state);

	ReturnInfo = str; //销售信息
	UpdateData(FALSE);
	MessageBox(TEXT("还出成功！"));
	ReturnInfo.Empty();
	UpdateData(FALSE); //更新到对应的控件
}


void CReturn::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CReturn::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	//获取当前选中项
	int index = return_combo.GetCurSel();
	//获取当前内容
	return_combo.GetLBText(index, text);

	//需要包含#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline_bk(); //读取商品信息
	for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
	{
		if (text == it->name.c_str())
		{
			_state = CString(it->state.c_str());
			UpdateData(FALSE); //内容更新到对应的控件
		}
	}

	file.ls.clear(); //清空list的内容
}


void CReturn::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CInfoFile file;
	file.ReadDocline_bk(); //读取商品信息
	for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
	{
		return_combo.AddString((CString)it->name.c_str());
	}

	file.lb.clear(); //清空list的内容

	//将第一个商品名设为默认选中项
	return_combo.SetCurSel(0);

	//设置静态控件窗口风格为位图居中显示
	return_pic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

//静态控件设置bitmap
	return_pic.SetBitmap(HBMP(TEXT("./1.bmp"), 300, 250));
}
