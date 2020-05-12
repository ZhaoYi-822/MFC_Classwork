
// Week11.classView.cpp : CWeek11classView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week11.class.h"
#endif

#include "Week11.classSet.h"
#include "Week11.classDoc.h"
#include "Week11.classView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek11classView

IMPLEMENT_DYNCREATE(CWeek11classView, CRecordView)

BEGIN_MESSAGE_MAP(CWeek11classView, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWeek11classView 构造/析构

CWeek11classView::CWeek11classView()
	: CRecordView(IDD_WEEK11CLASS_FORM)
	, ID(0)
	, name(_T(""))
	, num(_T(""))
	, age(_T(""))
	, tel(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CWeek11classView::~CWeek11classView()
{
}

void CWeek11classView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1,m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CWeek11classView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CWeek11classView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Week11classSet;
	CRecordView::OnInitialUpdate();

}


// CWeek11classView 打印

BOOL CWeek11classView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWeek11classView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CWeek11classView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CWeek11classView 诊断

#ifdef _DEBUG
void CWeek11classView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CWeek11classView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CWeek11classDoc* CWeek11classView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek11classDoc)));
	return (CWeek11classDoc*)m_pDocument;
}
#endif //_DEBUG


// CWeek11classView 数据库支持
CRecordset* CWeek11classView::OnGetRecordset()
{
	return m_pSet;
}



// CWeek11classView 消息处理程序
