
// 3.10kewaiView.cpp: CMy310kewaiView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.10kewai.h"
#endif

#include "3.10kewaiDoc.h"
#include "3.10kewaiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy310kewaiView

IMPLEMENT_DYNCREATE(CMy310kewaiView, CView)

BEGIN_MESSAGE_MAP(CMy310kewaiView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy310kewaiView 构造/析构

CMy310kewaiView::CMy310kewaiView() noexcept
{
	// TODO: 在此处添加构造代码
	

}

CMy310kewaiView::~CMy310kewaiView()
{
}

BOOL CMy310kewaiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy310kewaiView 绘图

void CMy310kewaiView::OnDraw(CDC* pDC)
{
	CMy310kewaiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->ca);
	pDC->Rectangle(pDoc->cb);
	pDC->Rectangle(pDoc->cc);
	pDC->Rectangle(pDoc->cd);
}


// CMy310kewaiView 诊断

#ifdef _DEBUG
void CMy310kewaiView::AssertValid() const
{
	CView::AssertValid();
}

void CMy310kewaiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy310kewaiDoc* CMy310kewaiView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy310kewaiDoc)));
	return (CMy310kewaiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy310kewaiView 消息处理程序


void CMy310kewaiView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	x = rand() % 100 + 5;
	CView::OnLButtonDown(nFlags, point);
	CMy310kewaiDoc* pDoc = GetDocument();
	
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
		cout++;
		switch (cout%4)
		{
		case 1:
			s = "+";
			break;
		case 2:
			s = "-";			
			break;
		case 3:
			s = "×";		 
			break;
		case 0:
			s = "÷";		
			break;
		}
		dc.TextOutW(point.x, point.y, s);
	}
	else
	{
		s2 = "点击无效";
		dc.TextOutW(point.x, point.y, s2);
	}

}


void CMy310kewaiView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy310kewaiDoc* pDoc = GetDocument();
	CView::OnRButtonDown(nFlags, point);
	CClientDC dc(this);
	 if (point.x > 800 && point.x < 1200 && point.y>400 && point.y < 600)
	{
		 switch (cout % 4)
		 {
		 case 1:
			 s.Format(_T("%d"), pDoc->a + pDoc->b);
			 break;
		 case 2:
			 s.Format(_T("%d"), pDoc->a - pDoc->b);
			 break;
		 case 3:
			 s.Format(_T("%d"), pDoc->a* pDoc->b);
			 break;
		 case 0:
			 s.Format(_T("%d"), pDoc->a /pDoc->b);
			 break;
		 }
		 dc.TextOutW(point.x, point.y, s);

	
	
	}
}
