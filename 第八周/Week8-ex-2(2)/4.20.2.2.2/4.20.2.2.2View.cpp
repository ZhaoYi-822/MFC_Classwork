
// 4.20.2.2.2View.cpp: CMy420222View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.20.2.2.2.h"
#endif

#include"MyDlg.h"
#include "4.20.2.2.2Doc.h"
#include "4.20.2.2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy420222View

IMPLEMENT_DYNCREATE(CMy420222View, CView)

BEGIN_MESSAGE_MAP(CMy420222View, CView)
	ON_COMMAND(ID_Ellipse, &CMy420222View::OnEllipse)
END_MESSAGE_MAP()

// CMy420222View 构造/析构

CMy420222View::CMy420222View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy420222View::~CMy420222View()
{
}

BOOL CMy420222View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy420222View 绘图

void CMy420222View::OnDraw(CDC* /*pDC*/)
{
	CMy420222Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy420222View 诊断

#ifdef _DEBUG
void CMy420222View::AssertValid() const
{
	CView::AssertValid();
}

void CMy420222View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy420222Doc* CMy420222View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy420222Doc)));
	return (CMy420222Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy420222View 消息处理程序


void CMy420222View::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int X, Y, R, R1;
		X = dlg.x;
		Y = dlg.y;
		R = dlg.r;
		R1 = dlg.r1;
		CRect rect(X-R,Y-R1,X+R,Y+R1);
		GetDC()->Ellipse(rect);

	}
}
