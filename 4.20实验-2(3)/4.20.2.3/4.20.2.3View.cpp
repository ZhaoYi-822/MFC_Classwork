
// 4.20.2.3View.cpp: CMy42023View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.20.2.3.h"
#endif

#include "4.20.2.3Doc.h"
#include "4.20.2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy42023View

IMPLEMENT_DYNCREATE(CMy42023View, CView)

BEGIN_MESSAGE_MAP(CMy42023View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy42023View 构造/析构

CMy42023View::CMy42023View() noexcept
{
	// TODO: 在此处添加构造代码
	rect.top = 100;
	rect.bottom = 300;
	rect.left = 200;
	rect.right = 500;
	
	x1 = rect.left;
	x2 = rect.right;
	y1 = rect.top;
	y2 = rect.bottom;
	

}

CMy42023View::~CMy42023View()
{
}

BOOL CMy42023View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy42023View 绘图

void CMy42023View::OnDraw(CDC* pDC)
{
	CMy42023Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	pDC->Ellipse(rect);

}


// CMy42023View 诊断

#ifdef _DEBUG
void CMy42023View::AssertValid() const
{
	CView::AssertValid();
}

void CMy42023View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy42023Doc* CMy42023View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy42023Doc)));
	return (CMy42023Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy42023View 消息处理程序


void CMy42023View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	
	CView::OnLButtonDown(nFlags, point);
	if (point.x > x1 && point.x<x2 && point.y>y1 && point.y < y2)
	{
		CPen newPen(PS_DASH,1,RGB(0,0,255));
		CPen* oldPen = dc.SelectObject(&newPen);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(rect);
	}
    
}
