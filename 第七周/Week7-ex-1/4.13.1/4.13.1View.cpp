
// 4.13.1View.cpp: CMy4131View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.13.1.h"
#endif

#include "4.13.1Doc.h"
#include "4.13.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4131View

IMPLEMENT_DYNCREATE(CMy4131View, CView)

BEGIN_MESSAGE_MAP(CMy4131View, CView)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy4131View 构造/析构

CMy4131View::CMy4131View() noexcept
{
	// TODO: 在此处添加构造代码
	rect.SetRect(200, 300, 500, 500);
	

}

CMy4131View::~CMy4131View()
{
}

BOOL CMy4131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4131View 绘图

void CMy4131View::OnDraw(CDC* pDC)
{
	CMy4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(rect);
}


// CMy4131View 诊断

#ifdef _DEBUG
void CMy4131View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4131Doc* CMy4131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4131Doc)));
	return (CMy4131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4131View 消息处理程序


void CMy4131View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
	if (nFlags)
	{
		rect.top = point.y-100;
		rect.bottom = point.y + 100;
		rect.left = point.x - 150;
		rect.right = point.x + 150;
		Invalidate();
	}
}
