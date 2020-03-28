
// 3.17-3View.cpp: CMy3173View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.17-3.h"
#endif

#include "3.17-3Doc.h"
#include "3.17-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3173View

IMPLEMENT_DYNCREATE(CMy3173View, CView)

BEGIN_MESSAGE_MAP(CMy3173View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy3173View 构造/析构

CMy3173View::CMy3173View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect m_rect(t,0,t+20,20);
		ca.Add(m_rect);
	}


}

CMy3173View::~CMy3173View()
{
}

BOOL CMy3173View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3173View 绘图

void CMy3173View::OnDraw(CDC* pDC)
{
	CMy3173Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i,rand()%400+100,NULL);
			set = false;
		}
		
	}
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(ca[i]);
	}
}


// CMy3173View 诊断

#ifdef _DEBUG
void CMy3173View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3173Doc* CMy3173View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3173Doc)));
	return (CMy3173Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3173View 消息处理程序


void CMy3173View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	GetClientRect(&c);
	CView::OnTimer(nIDEvent);
	int i = nIDEvent;
	if (ca[i].bottom < c.bottom-10)
	{
		ca[i].top += 10;
		ca[i].bottom += 10;
	}
	else {
		ca[i].top -= c.bottom - 50;
		ca[i].bottom -= c.bottom -50;
	}
	Invalidate();
}
