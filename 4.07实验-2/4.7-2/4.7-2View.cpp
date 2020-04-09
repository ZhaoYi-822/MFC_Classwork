
// 4.7-2View.cpp: CMy472View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.7-2.h"
#endif

#include"MyDlg2.h"
#include "4.7-2Doc.h"
#include "4.7-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy472View

IMPLEMENT_DYNCREATE(CMy472View, CView)

BEGIN_MESSAGE_MAP(CMy472View, CView)
	ON_COMMAND(ID_ExString, &CMy472View::OnExstring)
END_MESSAGE_MAP()

// CMy472View 构造/析构

CMy472View::CMy472View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy472View::~CMy472View()
{
}

BOOL CMy472View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy472View 绘图

void CMy472View::OnDraw(CDC* /*pDC*/)
{
	CMy472Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy472View 诊断

#ifdef _DEBUG
void CMy472View::AssertValid() const
{
	CView::AssertValid();
}

void CMy472View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy472Doc* CMy472View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy472Doc)));
	return (CMy472Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy472View 消息处理程序


void CMy472View::OnExstring()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
