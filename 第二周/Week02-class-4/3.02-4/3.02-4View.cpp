
// 3.02-4View.cpp: CMy3024View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.02-4.h"
#endif

#include "3.02-4Doc.h"
#include "3.02-4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3024View

IMPLEMENT_DYNCREATE(CMy3024View, CView)

BEGIN_MESSAGE_MAP(CMy3024View, CView)
END_MESSAGE_MAP()

// CMy3024View 构造/析构

CMy3024View::CMy3024View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy3024View::~CMy3024View()
{
}

BOOL CMy3024View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3024View 绘图

void CMy3024View::OnDraw(CDC* pDC)
{
	CMy3024Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	this->GetClientRect(&cr);
	
	int color = RGB(250, 0, 0);
	CBrush newBrush(color);
	CBrush* oldBrush = pDC->SelectObject(&newBrush);
	pDC->Ellipse(cr);
	pDC->SelectObject(oldBrush);

	
	
}


// CMy3024View 诊断

#ifdef _DEBUG
void CMy3024View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3024View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3024Doc* CMy3024View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3024Doc)));
	return (CMy3024Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3024View 消息处理程序
