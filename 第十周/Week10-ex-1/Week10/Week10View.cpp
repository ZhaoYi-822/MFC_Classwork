
// Week10View.cpp : CWeek10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week10.h"
#endif

#include "Week10Doc.h"
#include "Week10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"fac.h"

// CWeek10View

IMPLEMENT_DYNCREATE(CWeek10View, CView)

BEGIN_MESSAGE_MAP(CWeek10View, CView)
END_MESSAGE_MAP()

// CWeek10View 构造/析构

CWeek10View::CWeek10View()
{
	// TODO:  在此处添加构造代码

}

CWeek10View::~CWeek10View()
{
}

BOOL CWeek10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek10View 绘制

void CWeek10View::OnDraw(CDC* pDC)
{
	CWeek10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CString s;
	int n = 5;
	int a = Factorial(5);
	if (a == 0)
	{
		pDC->TextOutW(200, 180, _T("n的值必须大于0"));
	}
	if (a == -1)
	{
		pDC->TextOutW(200, 180, _T("n的阶乘结果溢出"));
	}
	if (a!=0 && a!=-1)
	{
		s.Format(_T("%d的阶乘为%d"), n, a);
		pDC->TextOutW(200, 100, s);
	}
}


// CWeek10View 诊断

#ifdef _DEBUG
void CWeek10View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek10Doc* CWeek10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek10Doc)));
	return (CWeek10Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek10View 消息处理程序
