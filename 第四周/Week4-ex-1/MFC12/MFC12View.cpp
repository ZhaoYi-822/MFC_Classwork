
// MFC12View.cpp: CMFC12View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC12.h"
#endif

#include "MFC12Doc.h"
#include "MFC12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC12View

IMPLEMENT_DYNCREATE(CMFC12View, CView)

BEGIN_MESSAGE_MAP(CMFC12View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC12View 构造/析构

CMFC12View::CMFC12View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC12View::~CMFC12View()
{
}

BOOL CMFC12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

int cout = 0;
int num = 0;
CString s, s1;
CPoint m_point;
CPoint b_point;
// CMFC12View 绘图

void CMFC12View::OnDraw(CDC* pDC)
{
	CMFC12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(10, 50, _T("请点击鼠标左键，移动一段后释放鼠标左键"));
	
}


// CMFC12View 诊断

#ifdef _DEBUG
void CMFC12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC12Doc* CMFC12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC12Doc)));
	return (CMFC12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC12View 消息处理程序


void CMFC12View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
    CClientDC DC(this);
	
	if (nFlags)
	{
		s.Format(_T("鼠标移动次数：%d"), cout++);	
		DC.TextOutW(100, 100, s);
		
	}
	
}


void CMFC12View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
	CClientDC DC(this);
	cout = 0;
	
	m_point.x = point.x;
	
	if (m_point.x > b_point.x)
			num = m_point.x - b_point.x;
	if (m_point.x == b_point.x)
		num = 0;
	if (m_point.x < b_point.x)
		num = b_point.x - m_point.x;
		s1.Format(_T("移动的像素：%d"), num);
		DC.TextOutW(100, 130, s1);
}


void CMFC12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	
	b_point.x = point.x;
}
