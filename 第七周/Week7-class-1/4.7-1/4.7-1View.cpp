
// 4.7-1View.cpp: CMy471View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.7-1.h"
#endif
#include "MyDlg0.h"
#include "4.7-1Doc.h"
#include "4.7-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy471View

IMPLEMENT_DYNCREATE(CMy471View, CView)

BEGIN_MESSAGE_MAP(CMy471View, CView)
	ON_COMMAND(ID_POPOUT, &CMy471View::OnPopout)
END_MESSAGE_MAP()

// CMy471View 构造/析构

CMy471View::CMy471View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy471View::~CMy471View()
{
}

BOOL CMy471View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy471View 绘图

void CMy471View::OnDraw(CDC* /*pDC*/)
{
	CMy471Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy471View 诊断

#ifdef _DEBUG
void CMy471View::AssertValid() const
{
	CView::AssertValid();
}

void CMy471View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy471Doc* CMy471View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy471Doc)));
	return (CMy471Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy471View 消息处理程序


void CMy471View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	CString s=_T("你已退出对话框");
	CClientDC dc(this);
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t = IDOK)
	{
       dc.TextOutW(20, 30, s);
	}
	
}
