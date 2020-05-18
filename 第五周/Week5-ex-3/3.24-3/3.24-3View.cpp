
// 3.24-3View.cpp: CMy3243View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.24-3.h"
#endif

#include "3.24-3Doc.h"
#include "3.24-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3243View

IMPLEMENT_DYNCREATE(CMy3243View, CView)

BEGIN_MESSAGE_MAP(CMy3243View, CView)
	ON_COMMAND(ID_Line, &CMy3243View::OnLine)
	ON_COMMAND(ID_Rectangle, &CMy3243View::OnRectangle)
	ON_COMMAND(ID_Ellipse, &CMy3243View::OnEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3243View 构造/析构

CMy3243View::CMy3243View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy3243View::~CMy3243View()
{
}

BOOL CMy3243View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3243View 绘图

void CMy3243View::OnDraw(CDC* pDC)
{
	CMy3243Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// CMy3243View 诊断

#ifdef _DEBUG
void CMy3243View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3243View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3243Doc* CMy3243View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3243Doc)));
	return (CMy3243Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3243View 消息处理程序


void CMy3243View::OnLine()
{
	
	CClientDC dc(this);
	// TODO: 在此添加命令处理程序代码
	set = 1;
	CPen pen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = dc.SelectObject(&pen);
}
	

void CMy3243View::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	set = 2;
	GetClientRect(&m_Crect);	
}

void CMy3243View::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	set = 3;	
}


void CMy3243View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	m_point.x = point.x;
	m_point.y = point.y;
}


void CMy3243View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CView::OnLButtonUp(nFlags, point);
	n_point.x = point.x;
	n_point.y = point.y;
	switch (set)
	{
	case 1:
		dc.MoveTo(n_point.x, n_point.y);
		dc.LineTo(m_point.x, m_point.y);
		break;
	case 2:
		m_Crect.left = m_point.x;
		m_Crect.top = m_point.y;
		m_Crect.right = n_point.x;
		m_Crect.bottom = n_point.y;
		dc.Rectangle(m_Crect);
		break;
	case 3:
		m_Crect.left = m_point.x;
		m_Crect.top = m_point.y;
		m_Crect.right = n_point.x;
		m_Crect.bottom = n_point.y;
		dc.Ellipse(m_Crect);
		break;
	default:
		break;
	}		
}
