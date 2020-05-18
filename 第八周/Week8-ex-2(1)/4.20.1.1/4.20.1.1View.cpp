
// 4.20.1.1View.cpp: CMy42011View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.20.1.1.h"
#endif

#include "4.20.1.1Doc.h"
#include "4.20.1.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy42011View

IMPLEMENT_DYNCREATE(CMy42011View, CView)

BEGIN_MESSAGE_MAP(CMy42011View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy42011View 构造/析构

CMy42011View::CMy42011View() noexcept
{
	// TODO: 在此处添加构造代码
	rect.top = 50;
	rect.bottom = 200;
	rect.left = 100;
	rect.right = 300;

}

CMy42011View::~CMy42011View()
{
}

BOOL CMy42011View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy42011View 绘图

void CMy42011View::OnDraw(CDC* pDC)
{
	CMy42011Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(rect);
}


// CMy42011View 诊断

#ifdef _DEBUG
void CMy42011View::AssertValid() const
{
	CView::AssertValid();
}

void CMy42011View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy42011Doc* CMy42011View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy42011Doc)));
	return (CMy42011Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy42011View 消息处理程序


void CMy42011View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}


void CMy42011View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
	if (nFlags)
	{
		rect.top = point.y - 75;
		rect.bottom = point.y + 75;
		rect.left = point.x - 100;
		rect.right = point.x + 100;
		Invalidate();
	}
}
