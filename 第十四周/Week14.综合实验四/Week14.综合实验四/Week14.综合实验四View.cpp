
// Week14.综合实验四View.cpp : CWeek14综合实验四View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week14.综合实验四.h"
#endif

#include "Week14.综合实验四Set.h"
#include "Week14.综合实验四Doc.h"
#include "Week14.综合实验四View.h"
#include"Search_Dlg.h"
#include"Sort_Dlg.h"
#include"Traversal_Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek14综合实验四View

IMPLEMENT_DYNCREATE(CWeek14综合实验四View, CRecordView)

BEGIN_MESSAGE_MAP(CWeek14综合实验四View, CRecordView)
	ON_COMMAND(ID_Sort, &CWeek14综合实验四View::OnSort)
	ON_COMMAND(ID_Search, &CWeek14综合实验四View::OnSearch)
	ON_COMMAND(ID_Traversal, &CWeek14综合实验四View::OnTraversal)
END_MESSAGE_MAP()

// CWeek14综合实验四View 构造/析构

CWeek14综合实验四View::CWeek14综合实验四View()
	: CRecordView(IDD_WEEK14_FORM)
	, name(_T(""))
	, num(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birth(0)
	, tel(_T(""))
	, home(_T(""))
	, pic(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CWeek14综合实验四View::~CWeek14综合实验四View()
{
}

void CWeek14综合实验四View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1,m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column8);
}

BOOL CWeek14综合实验四View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CWeek14综合实验四View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Week14综合实验四Set;
	CRecordView::OnInitialUpdate();

}


// CWeek14综合实验四View 诊断

#ifdef _DEBUG
void CWeek14综合实验四View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CWeek14综合实验四View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CWeek14综合实验四Doc* CWeek14综合实验四View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek14综合实验四Doc)));
	return (CWeek14综合实验四Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek14综合实验四View 数据库支持
CRecordset* CWeek14综合实验四View::OnGetRecordset()
{
	return m_pSet;
}



// CWeek14综合实验四View 消息处理程序


void CWeek14综合实验四View::OnSort()
{
	// TODO: 在此添加命令处理程序代码
	Sort_Dlg sort_dlg;
	int t = sort_dlg.DoModal();
	if (t == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), sort_dlg.sort);
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CWeek14综合实验四View::OnSearch()
{
	// TODO: 在此添加命令处理程序代码
	Search_Dlg re_dlg;
	int t = re_dlg.DoModal();
	if (t == IDOK)
	{

		m_pSet->m_strFilter.Format(_T("%s"), re_dlg.search);
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CWeek14综合实验四View::OnTraversal()
{
	// TODO: 在此添加命令处理程序代码
	Traversal_Dlg dlg;
	int n,i;
	CString str,s;
	
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())

	{ 
		n=m_pSet->GetODBCFieldCount();
		
		
		 for (i = 1; i < n; i++)
		 {
			m_pSet->GetFieldValue((short)i, str);
			s += _T(" ")+str ;
		 }
		 s += _T("\r\n");
		 dlg.trav = s;
		 UpdateData(false);
		 m_pSet->MoveNext();
	}
	if (dlg.DoModal() == IDOK)
	{

	}
	
}
