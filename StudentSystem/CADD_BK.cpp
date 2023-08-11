// CADD_BK.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CADD_BK.h"
#include"CInfoFile.h"


// CADD_BK

IMPLEMENT_DYNCREATE(CADD_BK, CFormView)

CADD_BK::CADD_BK()
	: CFormView(IDD_DIALOG_ADD_BK)
	, _id(_T(""))
	, _name(_T(""))
	, _type(_T(""))
	, _publisher(_T(""))
	, _date(_T(""))
	, _price(_T(""))
	, _state(_T(""))
{

}

CADD_BK::~CADD_BK()
{
}

void CADD_BK::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BK_PIC, bk_pic);
	DDX_Text(pDX, IDC_EDIT1, _id);
	DDX_Text(pDX, IDC_EDIT2, _name);
	DDX_Text(pDX, IDC_EDIT3, _type);
	DDX_Text(pDX, IDC_EDIT4, _publisher);
	DDX_Text(pDX, IDC_EDIT7, _date);
	DDX_Text(pDX, IDC_EDIT8, _price);
	DDX_Text(pDX, IDC_EDIT9, _state);
}

BEGIN_MESSAGE_MAP(CADD_BK, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CADD_BK::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CADD_BK::OnBnClickedButton2)
END_MESSAGE_MAP()


// CADD_BK 诊断

#ifdef _DEBUG
void CADD_BK::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CADD_BK::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CADD_BK 消息处理程序


void CADD_BK::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
//设置静态控件窗口风格为位图居中显示
	bk_pic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

//静态控件设置bitmap
	bk_pic.SetBitmap(HBMP(TEXT("./1.bmp"), 300, 250));

}


void CADD_BK::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (_id.IsEmpty() || _name.IsEmpty() || _type.IsEmpty() || _publisher.IsEmpty()||_date.IsEmpty()||_price.IsEmpty()||_state.IsEmpty())
	{
		MessageBox(TEXT("书籍信息不能为空"));
		return;
	}
	CInfoFile file;
	file.ReadDocline_bk();
	for (list<bk>::iterator it = file.lb.begin(); it != file.lb.end(); it++)
	{
		int i = it->id;
		CString str;
		str.Format(_T("%d"), i);
		if (str == _id)
		{
			CString str;
			str.Format(TEXT("书号%d已存在"), i);
			MessageBox(str);
			return;
		}
	}

	long int id, price;
	id = _ttoi(_id);
	price = _ttoi(_price);
	file.Addline_bk(id, _name, _type,price,_publisher,_date,_state);
	file.WriteDocline_bk();
	MessageBox(TEXT("添加成功"));
}


void CADD_BK::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	_id = "";
	_name = "";
	_type = "";
	_publisher = "";
	_date = "";
	_price = "";
	_state = "";
	UpdateData(FALSE);
}
