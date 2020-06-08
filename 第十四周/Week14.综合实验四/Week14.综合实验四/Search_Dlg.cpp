// Search_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Week14.综合实验四.h"
#include "Search_Dlg.h"
#include "afxdialogex.h"


// Search_Dlg 对话框

IMPLEMENT_DYNAMIC(Search_Dlg, CDialogEx)

Search_Dlg::Search_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Search_DlG, pParent)
	, search(_T(""))
{

}

Search_Dlg::~Search_Dlg()
{
}

void Search_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, search);
}


BEGIN_MESSAGE_MAP(Search_Dlg, CDialogEx)
END_MESSAGE_MAP()


// Search_Dlg 消息处理程序
