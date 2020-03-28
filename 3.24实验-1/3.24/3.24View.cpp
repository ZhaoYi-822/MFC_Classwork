
// 3.24View.cpp: CMy324View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.24.h"
#endif

#include "3.24Doc.h"
#include "3.24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy324View

IMPLEMENT_DYNCREATE(CMy324View, CView)

BEGIN_MESSAGE_MAP(CMy324View, CView)
	ON_COMMAND(ID_Name, &CMy324View::OnName)
END_MESSAGE_MAP()

// CMy324View 构造/析构

CMy324View::CMy324View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy324View::~CMy324View()
{
}

BOOL CMy324View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy324View 绘图

void CMy324View::OnDraw(CDC* /*pDC*/)
{
	CMy324Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy324View 诊断

#ifdef _DEBUG
void CMy324View::AssertValid() const
{
	CView::AssertValid();
}

void CMy324View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy324Doc* CMy324View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy324Doc)));
	return (CMy324Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy324View 消息处理程序


void CMy324View::OnName()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CString s=_T("赵毅");
	dc.TextOutW(600, 250, s);
}
