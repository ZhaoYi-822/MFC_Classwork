
// week11.1.1View.cpp : Cweek1111View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "week11.1.1.h"
#endif

#include "week11.1.1Set.h"
#include "week11.1.1Doc.h"
#include "week11.1.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cweek1111View

IMPLEMENT_DYNCREATE(Cweek1111View, CRecordView)

BEGIN_MESSAGE_MAP(Cweek1111View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &Cweek1111View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &Cweek1111View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &Cweek1111View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &Cweek1111View::OnRecordLast)
END_MESSAGE_MAP()

// Cweek1111View 构造/析构

Cweek1111View::Cweek1111View()
	: CRecordView(IDD_WEEK1111_FORM)
	, id(_T(""))
	, name(_T(""))
	, num(_T(""))
	, sex(_T(""))
	, jprg(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\Picture\\");
}

Cweek1111View::~Cweek1111View()
{
}

void Cweek1111View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
	Invalidate();
}

BOOL Cweek1111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Cweek1111View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_week1111Set;
	CRecordView::OnInitialUpdate();
	
}


// Cweek1111View 诊断

#ifdef _DEBUG
void Cweek1111View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cweek1111View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cweek1111Doc* Cweek1111View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cweek1111Doc)));
	return (Cweek1111Doc*)m_pDocument;
}
#endif //_DEBUG


// Cweek1111View 数据库支持
CRecordset* Cweek1111View::OnGetRecordset()
{
	return m_pSet;
}



// Cweek1111View 消息处理程序


void Cweek1111View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);

	/*CString s;
	GetDlgItemText(IDC_EDIT5, s);
	CString file;
	file = path + s;
	foo(file);*/
	
	
}


void Cweek1111View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	
	UpdateData(false);
	

	
}


void Cweek1111View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	
	
}


void Cweek1111View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	/*CString s;
	GetDlgItemText(IDC_EDIT5, s);
	CString file;
	file = path + s;
	foo(file);*/
	
}

/*void  Cweek1111View::foo(CString filename)
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
	img.Draw(pDC->m_hDC,sx,sy,w,h);
	ReleaseDC(pDC);
	
}*/

void Cweek1111View::drawPicture(CImage&img, int&sx, int&sy, int&w, int&h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sy = (rect.Height() - h) / 2;
		sx = 0;
	}
}



void Cweek1111View::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	CImage img;
	img.Load(path+m_pSet->m_4);
	pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	int sx, sy, w, h;
	drawPicture(img, sx, sy, w, h);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
