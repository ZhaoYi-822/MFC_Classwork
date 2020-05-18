
// Week13.1View.cpp : CWeek131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week13.1.h"
#endif

#include "Week13.1Set.h"
#include "Week13.1Doc.h"
#include "Week13.1View.h"
#include"MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek131View

IMPLEMENT_DYNCREATE(CWeek131View, CRecordView)

BEGIN_MESSAGE_MAP(CWeek131View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CWeek131View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CWeek131View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CWeek131View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CWeek131View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CWeek131View::OnRecordLast)
END_MESSAGE_MAP()

// CWeek131View 构造/析构

CWeek131View::CWeek131View()
	: CRecordView(IDD_WEEK131_FORM)
	, id(0)
	, name(_T(""))
	, num(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, tel(_T(""))
	, home(_T(""))
	, jpeg(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\Picture\\");

}

CWeek131View::~CWeek131View()
{
}

void CWeek131View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->column8);
	Invalidate();
}

BOOL CWeek131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CWeek131View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Week131Set;
	CRecordView::OnInitialUpdate();

}


// CWeek131View 诊断

#ifdef _DEBUG
void CWeek131View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CWeek131View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CWeek131Doc* CWeek131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek131Doc)));
	return (CWeek131Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek131View 数据库支持
CRecordset* CWeek131View::OnGetRecordset()
{
	return m_pSet;
}



// CWeek131View 消息处理程序


void CWeek131View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg dlg;
	dlg.fil = path+m_pSet->column8;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		
	}
	
}


void CWeek131View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
}


void CWeek131View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CWeek131View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	
	
}


void CWeek131View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
}
void  CWeek131View::drawPicture(CString filename)
{
	CImage img;
	img.Load(filename);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_radio = 1.0 * rect.Width() / rect.Height();
	float image_radio = 1.0 * img.GetWidth() / img.GetHeight();

	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}

void CWeek131View::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	file = path + m_pSet->column8;
	drawPicture(file);
}
