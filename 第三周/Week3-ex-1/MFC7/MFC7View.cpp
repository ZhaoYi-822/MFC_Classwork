
// MFC7View.cpp: CMFC7View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7.h"
#endif

#include "MFC7Doc.h"
#include "MFC7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC7View

IMPLEMENT_DYNCREATE(CMFC7View, CView)

BEGIN_MESSAGE_MAP(CMFC7View, CView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC7View 构造/析构

CMFC7View::CMFC7View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC7View::~CMFC7View()
{
}

BOOL CMFC7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC7View 绘图

void CMFC7View::OnDraw(CDC* pDC)
{
	CMFC7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(10, 20, _T("鼠标的按下与抬起："));
}


// CMFC7View 诊断

#ifdef _DEBUG
void CMFC7View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC7Doc* CMFC7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC7Doc)));
	return (CMFC7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC7View 消息处理程序


void CMFC7View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
	CString s = _T("左键正被抬起");
	CClientDC dc(this);
	dc.TextOutW(250,20,s);
}


void CMFC7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	CString s = _T("左键正被按下");
	CClientDC dc(this);
	dc.TextOutW(250, 20, s);
}
