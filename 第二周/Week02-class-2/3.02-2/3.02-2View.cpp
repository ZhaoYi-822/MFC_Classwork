
// 3.02-2View.cpp: CMy3022View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.02-2.h"
#endif

#include "3.02-2Doc.h"
#include "3.02-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3022View

IMPLEMENT_DYNCREATE(CMy3022View, CView)

BEGIN_MESSAGE_MAP(CMy3022View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy3022View 构造/析构

CMy3022View::CMy3022View() noexcept
{
	// TODO: 在此处添加构造代码
	ca.SetSize(256);

}

CMy3022View::~CMy3022View()
{
}

BOOL CMy3022View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3022View 绘图

void CMy3022View::OnDraw(CDC* pDC)
{
	CMy3022Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < ca.GetSize(); i++)
	{
		pDC->Ellipse(ca[i]);
	}
}


// CMy3022View 诊断

#ifdef _DEBUG
void CMy3022View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3022View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3022Doc* CMy3022View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3022Doc)));
	return (CMy3022Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3022View 消息处理程序


void CMy3022View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	int r = rand() % 50 + 10;
	CClientDC dc(this);
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	ca.Add(cr);
	Invalidate();
}
