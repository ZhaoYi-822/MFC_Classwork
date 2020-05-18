
// 4.13-3View.cpp: CMy4133View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.13-3.h"
#endif

#include "4.13-3Doc.h"
#include "4.13-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4133View

IMPLEMENT_DYNCREATE(CMy4133View, CView)

BEGIN_MESSAGE_MAP(CMy4133View, CView)
	ON_COMMAND(ID_MoveCircle, &CMy4133View::OnMovecircle)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy4133View 构造/析构

CMy4133View::CMy4133View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	flag = 0;
	
}

CMy4133View::~CMy4133View()
{
}

BOOL CMy4133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4133View 绘图

void CMy4133View::OnDraw(CDC* pDC)
{
	CMy4133Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	CString s = _T("点击对话框中视图下栏中圆的移动");
	pDC->TextOutW(0, 0, s);
	if (set==true)
	{
		
			SetTimer(1,rand()%100+50,NULL);
			this->GetClientRect(&rect);
			set = false;
			
		
	}
	pDC->Ellipse(m_rect);
}


// CMy4133View 诊断

#ifdef _DEBUG
void CMy4133View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4133View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4133Doc* CMy4133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4133Doc)));
	return (CMy4133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4133View 消息处理程序


void CMy4133View::OnMovecircle()
{
	// TODO: 在此添加命令处理程序代码
	
	m_rect.top = (rect.bottom + rect.top) / 2 - 100;
	m_rect.bottom =(rect.bottom + rect.top) / 2 + 100;
	m_rect.left =(rect.left + rect.right) / 2 - 100;
    m_rect.right= (rect.left + rect.right) / 2 + 100;
	Invalidate();
}


void CMy4133View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	x = 1;
	Invalidate();
}


void CMy4133View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnTimer(nIDEvent);
	int i = nIDEvent;
	if (x == 1) 
	{
		
		if (m_rect.right > rect.right)
		{
			flag = 1;
		}
		if (m_rect.left < rect.left)
		{
			flag = 0;
		}
		if (flag==0)
		{
			m_rect.right += 20;
			m_rect.left += 20;
		}
		if (flag ==1)
		{
			m_rect.left -= 20;
			m_rect.right -= 20;
			
		}
	}
	Invalidate();
	
}


void CMy4133View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDblClk(nFlags, point);
	x = 0;
}
