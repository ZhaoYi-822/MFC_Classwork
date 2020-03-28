
// MFC10View.cpp: CMFC10View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC10.h"
#endif

#include "MFC10Doc.h"
#include "MFC10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC10View

IMPLEMENT_DYNCREATE(CMFC10View, CView)

BEGIN_MESSAGE_MAP(CMFC10View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC10View 构造/析构

CMFC10View::CMFC10View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC10View::~CMFC10View()
{
}

BOOL CMFC10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC10View 绘图

void CMFC10View::OnDraw(CDC* pDC)
{
	CMFC10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(100, 30, _T("于鼠标左键按下，移动直到抬起的这个过程，在按下时记录下鼠标位置, 抬起画出一个矩形"));
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMFC10View 诊断

#ifdef _DEBUG
void CMFC10View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC10Doc* CMFC10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC10Doc)));
	return (CMFC10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC10View 消息处理程序


void CMFC10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC10Doc* pDoc = GetDocument();
	CView::OnLButtonDown(nFlags, point);
		pDoc->m_tagRec.left = point.x;
		pDoc->m_tagRec.top = point.y;
	InvalidateRect(NULL, TRUE);

}


void CMFC10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnLButtonUp(nFlags, point);

	CMFC10Doc* pDoc = GetDocument();	
		pDoc->m_tagRec.right = point.x;
		pDoc->m_tagRec.bottom = point.y;
	InvalidateRect(NULL, TRUE);
	
}
void CMFC10View::OnMouseMove(UINT nFlags, CPoint point)
{
	CString s;
	s.Format(_T("%d ,%d"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(10,30,s);
	CView::OnMouseMove(nFlags, point);
}
