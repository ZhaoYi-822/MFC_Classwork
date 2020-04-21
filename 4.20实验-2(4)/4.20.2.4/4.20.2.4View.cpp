
// 4.20.2.4View.cpp: CMy42024View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.20.2.4.h"
#endif

#include"MyDlg.h"
#include "4.20.2.4Doc.h"
#include "4.20.2.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy42024View

IMPLEMENT_DYNCREATE(CMy42024View, CView)

BEGIN_MESSAGE_MAP(CMy42024View, CView)
	ON_COMMAND(ID_Brush, &CMy42024View::OnBrush)
END_MESSAGE_MAP()

// CMy42024View 构造/析构

CMy42024View::CMy42024View() noexcept
{
	// TODO: 在此处添加构造代码
	rect.SetRect(50,100,200,300);
	flag = false;
}

CMy42024View::~CMy42024View()
{
}

BOOL CMy42024View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy42024View 绘图

void CMy42024View::OnDraw(CDC* pDC)
{
	CMy42024Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	MyDlg dlg;
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(rect);
        
	if (flag)
	{
		CBrush newBrush(RGB(R, G, B));
		CBrush* oldBrush = pDC->SelectObject(&newBrush);
		pDC->Ellipse(rect);
		pDC->SelectObject(oldBrush);
	}
}


// CMy42024View 诊断

#ifdef _DEBUG
void CMy42024View::AssertValid() const
{
	CView::AssertValid();
}

void CMy42024View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy42024Doc* CMy42024View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy42024Doc)));
	return (CMy42024Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy42024View 消息处理程序


void CMy42024View::OnBrush()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	CClientDC dc(this);
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		
		R = dlg.r;
		G = dlg.g;
		B = dlg.b;
		flag = true;
		Invalidate();
	}
}
