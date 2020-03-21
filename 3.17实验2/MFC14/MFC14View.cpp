
// MFC14View.cpp: CMFC14View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC14.h"
#endif

#include "MFC14Doc.h"
#include "MFC14View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC14View

IMPLEMENT_DYNCREATE(CMFC14View, CView)

BEGIN_MESSAGE_MAP(CMFC14View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC14View 构造/析构

CMFC14View::CMFC14View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC14View::~CMFC14View()
{
}

BOOL CMFC14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC14View 绘图

void CMFC14View::OnDraw(CDC* pDC)
{
	CMFC14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s =_T( "按R生成矩形");
	CString s1 = _T("按动键盘上下左右四键进行移动");
	CString s2 = _T("按动HOME键矩形朝左上角增大，按动END键矩形朝右下角缩小，点击鼠标左键矩形恢复原状");
	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(10, 60, s);
	pDC->TextOutW(10, 80, s1);
	pDC->TextOutW(10, 100, s2);
	pDC->Rectangle(pDoc->m_clientRec);
}


// CMFC14View 诊断

#ifdef _DEBUG
void CMFC14View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC14Doc* CMFC14View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC14Doc)));
	return (CMFC14Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC14View 消息处理程序


void CMFC14View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC14Doc* pDoc = GetDocument();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case 'R':
		pDoc->m_clientRec.left = (clientRec.left + clientRec.right) / 2 - 50;
		pDoc->m_clientRec.right = (clientRec.left + clientRec.right) / 2 + 50;
		pDoc->m_clientRec.top = (clientRec.top + clientRec.bottom) / 2 - 80;
		pDoc->m_clientRec.bottom = (clientRec.top + clientRec.bottom) / 2 + 80;
		break;
	case VK_LEFT:
		pDoc->m_clientRec.left -= 5;
		pDoc->m_clientRec.right -= 5;
		break;
	case VK_RIGHT:
		pDoc->m_clientRec.left += 5;
		pDoc->m_clientRec.right += 5;
		break;
	case VK_UP:
		pDoc->m_clientRec.top -= 5;
		pDoc->m_clientRec.bottom -= 5;
		break;
	case VK_DOWN:
		pDoc->m_clientRec.top += 5;
		pDoc->m_clientRec.bottom += 5;
		break;
	case VK_HOME:
		pDoc->m_clientRec.left -= 5;
		pDoc->m_clientRec.top -= 5;
		break;
	case VK_END:
		pDoc->m_clientRec.right -= 5;
		pDoc->m_clientRec.bottom -= 5;
		break;
	}
	InvalidateRect(NULL, TRUE);
}


void CMFC14View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC14Doc* pDoc = GetDocument();
	CView::OnLButtonDown(nFlags, point);
	CRect clientRec;
	GetClientRect(&clientRec);
	pDoc->m_clientRec.left = (clientRec.left + clientRec.right) / 2 - 50;
	pDoc->m_clientRec.right = (clientRec.left + clientRec.right) / 2 + 50;
	pDoc->m_clientRec.top = (clientRec.top + clientRec.bottom) / 2 - 80;
	pDoc->m_clientRec.bottom = (clientRec.top + clientRec.bottom) / 2 + 80;
	InvalidateRect(NULL, TRUE);
}
