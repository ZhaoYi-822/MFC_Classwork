
// UseLib0View.cpp : CUseLib0View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UseLib0.h"
#endif

#include "UseLib0Doc.h"
#include "UseLib0View.h"
#include"W32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUseLib0View

IMPLEMENT_DYNCREATE(CUseLib0View, CView)

BEGIN_MESSAGE_MAP(CUseLib0View, CView)
END_MESSAGE_MAP()

// CUseLib0View 构造/析构

CUseLib0View::CUseLib0View()
{
	// TODO:  在此处添加构造代码

}

CUseLib0View::~CUseLib0View()
{
}

BOOL CUseLib0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUseLib0View 绘制

void CUseLib0View::OnDraw(CDC* pDC)
{
	CUseLib0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	float deg = 30.0;
	FAC m_FAC;
	float value = m_FAC.convert(deg);
	CString s;
	s.Format(_T("%f的弧度值为%f"), deg, value);
	pDC->TextOutW(200,180,s);

}


// CUseLib0View 诊断

#ifdef _DEBUG
void CUseLib0View::AssertValid() const
{
	CView::AssertValid();
}

void CUseLib0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUseLib0Doc* CUseLib0View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseLib0Doc)));
	return (CUseLib0Doc*)m_pDocument;
}
#endif //_DEBUG


// CUseLib0View 消息处理程序
