// Sort_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Week14.综合实验四.h"
#include "Sort_Dlg.h"
#include "afxdialogex.h"


// Sort_Dlg 对话框

IMPLEMENT_DYNAMIC(Sort_Dlg, CDialogEx)

Sort_Dlg::Sort_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Sort_DLG, pParent)
	, sort(_T(""))
{

}

Sort_Dlg::~Sort_Dlg()
{
}

void Sort_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sort);
}


BEGIN_MESSAGE_MAP(Sort_Dlg, CDialogEx)
END_MESSAGE_MAP()


// Sort_Dlg 消息处理程序
