
// Week6-ex1View.cpp: CWeek6ex1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week6-ex1.h"
#endif

#include "Week6-ex1Doc.h"
#include "Week6-ex1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek6ex1View

IMPLEMENT_DYNCREATE(CWeek6ex1View, CView)

BEGIN_MESSAGE_MAP(CWeek6ex1View, CView)
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CWeek6ex1View 构造/析构

CWeek6ex1View::CWeek6ex1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CWeek6ex1View::~CWeek6ex1View()
{
}

BOOL CWeek6ex1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek6ex1View 绘图

void CWeek6ex1View::OnDraw(CDC* pDC)
{
	CWeek6ex1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(190, 190, 510, 500);

}


// CWeek6ex1View 诊断

#ifdef _DEBUG
void CWeek6ex1View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek6ex1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek6ex1Doc* CWeek6ex1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek6ex1Doc)));
	return (CWeek6ex1Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek6ex1View 消息处理程序


int CWeek6ex1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码


	return 0;
}


void CWeek6ex1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnChar(nChar, nRepCnt, nFlags);
	CClientDC dc(this);
	CRect Rect(200, 200, 500, 500);

	str.Format(_T("%c"), nChar);

	if (x >= 200 && y >= 200) {
		pos = (x - 200) / 10 + (y - 200) / 20 * 30;

		s.Insert(pos, nChar);
	}
	else {
		s.Append(str);
	}

	dc.DrawText(s, Rect, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL);

}


void CWeek6ex1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	x = point.x;
	y = point.y;
}
