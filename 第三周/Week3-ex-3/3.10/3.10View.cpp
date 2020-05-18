
// 3.10View.cpp: CMy310View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.10.h"
#endif

#include "3.10Doc.h"
#include "3.10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy310View

IMPLEMENT_DYNCREATE(CMy310View, CView)

BEGIN_MESSAGE_MAP(CMy310View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy310View 构造/析构

CMy310View::CMy310View() noexcept
{
	// TODO: 在此处添加构造代码
	
	
}

CMy310View::~CMy310View()
{
}

BOOL CMy310View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy310View 绘图

void CMy310View::OnDraw(CDC* pDC)
{
	CMy310Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->ca);
	pDC->Rectangle(pDoc->cb);
	pDC->Rectangle(pDoc->cc);

}


// CMy310View 诊断

#ifdef _DEBUG
void CMy310View::AssertValid() const
{
	CView::AssertValid();
}

void CMy310View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy310Doc* CMy310View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy310Doc)));
	return (CMy310Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy310View 消息处理程序


void CMy310View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CString s, s1, s2;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy310Doc* pDoc = GetDocument();
	int x = rand() % 100 + 5;


	CClientDC dc(this);
	if (point.x > 40 && point.x < 200 && point.y>40 && point.y < 200)
	{
		pDoc->a = x;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (point.x > 220 && point.x < 400 && point.y>220 && point.y < 400)
	{
		pDoc->b = x;
		s1.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s1);

	}
	else if (point.x > 500 && point.x < 720 && point.y>400 && point.y < 600)
	{
		
		s2.Format(_T("%d"), pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s2);
	}
	else
	{
	   s2= "点击无效";
		dc.TextOutW(point.x,point.y,s2);
	}
}
