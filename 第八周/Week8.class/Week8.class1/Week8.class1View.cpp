
// Week8.class1View.cpp: CWeek8class1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week8.class1.h"
#endif

#include "Week8.class1Doc.h"
#include "Week8.class1View.h"
#include"MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek8class1View

IMPLEMENT_DYNCREATE(CWeek8class1View, CView)

BEGIN_MESSAGE_MAP(CWeek8class1View, CView)
	ON_COMMAND(ID_Show, &CWeek8class1View::OnShow)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CWeek8class1View 构造/析构

CWeek8class1View::CWeek8class1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CWeek8class1View::~CWeek8class1View()
{
}

BOOL CWeek8class1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek8class1View 绘图

void CWeek8class1View::OnDraw(CDC* /*pDC*/)
{
	CWeek8class1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek8class1View 诊断

#ifdef _DEBUG
void CWeek8class1View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek8class1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek8class1Doc* CWeek8class1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek8class1Doc)));
	return (CWeek8class1Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek8class1View 消息处理程序





void CWeek8class1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	CClientDC dc(this);
	if (cfd.DoModal() == IDOK)
	{
		filename = cfd.GetPathName();
		dc.TextOutW(20,20,filename);

	}

	CView::OnLButtonDblClk(nFlags, point);
}
void CWeek8class1View::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	CClientDC dc(this);
	dlg.x=filename;
	if (dlg.DoModal() == IDOK)
	{
		
	}

}