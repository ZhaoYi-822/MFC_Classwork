
// 4.13-4View.cpp: CMy4134View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.13-4.h"
#endif

#include "4.13-4Doc.h"
#include "4.13-4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4134View

IMPLEMENT_DYNCREATE(CMy4134View, CView)

BEGIN_MESSAGE_MAP(CMy4134View, CView)
END_MESSAGE_MAP()

// CMy4134View 构造/析构

CMy4134View::CMy4134View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy4134View::~CMy4134View()
{
}

BOOL CMy4134View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4134View 绘图

void CMy4134View::OnDraw(CDC* /*pDC*/)
{
	CMy4134Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy4134View 诊断

#ifdef _DEBUG
void CMy4134View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4134View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4134Doc* CMy4134View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4134Doc)));
	return (CMy4134Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4134View 消息处理程序
