
// 3.23实验View.cpp: CMy323实验View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.23实验.h"
#endif

#include "3.23实验Doc.h"
#include "3.23实验View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy323实验View

IMPLEMENT_DYNCREATE(CMy323实验View, CView)

BEGIN_MESSAGE_MAP(CMy323实验View, CView)
	ON_COMMAND(ID_Circles, &CMy323实验View::OnCircles)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy323实验View 构造/析构

CMy323实验View::CMy323实验View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
}

CMy323实验View::~CMy323实验View()
{
}

BOOL CMy323实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy323实验View 绘图

void CMy323实验View::OnDraw(CDC* /*pDC*/)
{
	CMy323实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy323实验View 诊断

#ifdef _DEBUG
void CMy323实验View::AssertValid() const
{
	CView::AssertValid();
}

void CMy323实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy323实验Doc* CMy323实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy323实验Doc)));
	return (CMy323实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy323实验View 消息处理程序


void CMy323实验View::OnCircles()
{
	// TODO: 在此添加命令处理程序代码
	GetClientRect(&m_window);
	// TODO: 在此添加命令处理程序代码
	int x1 = (m_window.left + m_window.right) / 2;
	int x2 = (m_window.bottom + m_window.top) / 2;
	GetClientRect(&cr);
	CClientDC DC(this);
	cr.left = x1 - 50;
	cr.right = x1 + 50;
	cr.top = x2 - 50;
	cr.bottom = x2 + 50;

	if (set)
	{
		for (int i = 0; i < N; i++)
		{

			SetTimer(i, 200, NULL);
		}
		set = false;
	}

}


void CMy323实验View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnTimer(nIDEvent);
	CView::OnTimer(nIDEvent);
	CClientDC dc(this);
	int i = nIDEvent;
	cr.left -= 5;
	cr.right += 5;
	cr.top -= 5;
	cr.bottom += 5;

	dc.Ellipse(cr);
	CPen pen(PS_SOLID, 20, RGB(rand() % 150, rand() % 150, rand() % 150));
	CPen* color;
	color = dc.SelectObject(&pen);
	dc.Ellipse(cr);
	CView::OnTimer(nIDEvent);
}
